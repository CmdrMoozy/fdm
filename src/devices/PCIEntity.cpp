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

#include "PCIEntity.h"

#include <QStringList>

#include "FDMUtil.h"

PCIEntity::PCIEntity(const QString &d)
	: good(false)
{
	setDescriptor(d);
}

PCIEntity::~PCIEntity()
{
}

bool PCIEntity::isGood() const
{
	return good;
}

bool PCIEntity::setDescriptor(const QString &d)
{
	// Reset our data.
	
	vendor = QString();
	device = QString();
	subsys = QString();
	
	// Sanity checks.
	
	if(d.length() < 5)
		return (good = false);
	
	QStringList type = d.split('\\');
	
	if(type.at(0).toUpper() != "PCI")
		return (good = false);
	
	// Process the string.
	
	QStringList desc = type.at(1).split('&');
	
	for(int i = 0; i < desc.count(); ++i)
	{
		if(desc[i].left(3).toUpper() == "VEN")
		{
			vendor = desc[i].right(4).toLower();
			
			if(!FDMUtil::isHexString(vendor))
				vendor = QString();
		}
		else if(desc[i].left(3).toUpper() == "DEV")
		{
			device = desc[i].right(4).toLower();
			
			if(!FDMUtil::isHexString(device))
				device = QString();
		}
		else if(desc[i].left(6).toUpper() == "SUBSYS")
		{
			subsys = desc[i].right(4).toLower() +
				desc[i].right(8).left(4).toLower();
			
			if(!FDMUtil::isHexString(subsys))
				subsys = QString();
		}
	}
	
	return (good = true);
}

QString PCIEntity::getVendor() const
{
	return vendor;
}

QString PCIEntity::getDevice() const
{
	return device;
}

QString PCIEntity::getSubID() const
{
	return subsys;
}
