/*
 * FDM - An application to list PCI and USB devices connected to a Windows computer.
 * Copyright (C) 2011 Axel Rasmussen
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "USBEntity.h"

#include <QStringList>

USBEntity::USBEntity(const QString &d)
	: good(false)
{
	setDescriptor(d);
}

USBEntity::USBEntity(const USBEntity &o)
{
	(*this) = o;
}

USBEntity::~USBEntity()
{
}

USBEntity &USBEntity::operator=(const USBEntity &o)
{
	good = o.good;
	vendor = o.vendor;
	device = o.device;
	
	return (*this);
}

bool USBEntity::operator==(const USBEntity &o) const
{
	return comparisonValue() == o.comparisonValue();
}

bool USBEntity::operator<(const USBEntity &o) const
{
	return comparisonValue() < o.comparisonValue();
}

bool USBEntity::operator<=(const USBEntity &o) const
{
	return comparisonValue() <= o.comparisonValue();
}

bool USBEntity::operator>(const USBEntity &o) const
{
	return comparisonValue() > o.comparisonValue();
}

bool USBEntity::operator>=(const USBEntity &o) const
{
	return comparisonValue() >= o.comparisonValue();
}

bool USBEntity::isGood() const
{
	return good;
}

bool USBEntity::setDescriptor(const QString &d)
{
	// Reset our data.
	
	vendor = QString();
	device = QString();
	
	// Do some initial processing of the string.
	
	int ds = d.indexOf("DeviceID=\"") + 10;
	if(ds < 10)
		return (good = false);
	
	int de = d.indexOf('"', ds);
	if(de <= ds)
		return (good = false);
	
	QString descriptor = d.mid(ds, de - ds);
	
	// Sanity Checks.
	
	QStringList type = descriptor.split("\\\\");
	
	if(type.length() < 2)
		return (good = false);
	
	type = type.at(1).split('&');
	
	if(type.length() < 2)
		return (good = false);
	
	if(type.at(0).left(3).toUpper() != "VID")
		return (good = false);
	
	if(type.at(1).left(3).toUpper() != "PID")
		return (good = false);
	
	// Process the string.
	
	vendor = type.at(0).right(4).toLower();
	device = type.at(1).right(4).toLower();
	
	return (good = true);
}

QString USBEntity::getVendor() const
{
	return vendor;
}

QString USBEntity::getDevice() const
{
	return device;
}

QString USBEntity::getSubID() const
{
	return QString();
}

uint32_t USBEntity::comparisonValue() const
{
	if(!good) return 0;
	
	bool ok;
	uint32_t buf;
	
	buf = static_cast<uint32_t>(vendor.toUInt(&ok, 16)) << 16;
	if(!ok) return 0;
	
	buf |= static_cast<uint32_t>(device.toUInt(&ok, 16));
	if(!ok) return 0;
	
	return buf;
}
