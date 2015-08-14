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

#include "USBDeviceResolver.h"

#include <QFile>
#include <QTextStream>
#include <QList>

#include "FDMUtil.h"
#include "devices/USBEntity.h"

USBDeviceResolver::USBDeviceResolver()
{
	QFile ids(":/data/usb.ids");
	if(ids.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream(&ids);
		QString line, vendor, device;
		
		while(!stream.atEnd())
		{
			line = stream.readLine();
			
			if(FDMUtil::isWhitespace(line))
			{ // Skip blank lines.
				
				continue;
				
			}
			else if(line[0] == '#')
			{ // Skip comment lines.
				
				continue;
				
			}
			else if(line[0] == '\t')
			{ // Line starts with a tab - either device or subsys.
				
				if(line[1] == '\t')
				{ // Another tab - ignore.
					
					continue;
					
				}
				else
				{ // An ID - must be a device.
					
					device = line.mid(1, 4).toLower();
					devicem.insert(vendor + device, line.mid(7));
					
				}
				
			}
			else
			{ // Line starts with an ID - this is a vendor.
				
				vendor = line.mid(0, 4).toLower();
				vendorm.insert(vendor, line.mid(6));
				
			}
		}
	}
}

USBDeviceResolver::~USBDeviceResolver()
{
}

QString USBDeviceResolver::getVendorString(const DeviceEntity *e) const
{
	if(e == NULL) return QString();
	return vendorm.value(e->getVendor(), QString());
}

QString USBDeviceResolver::getDeviceString(const DeviceEntity *e) const
{
	if(e == NULL) return QString();
	return devicem.value(e->getVendor() + e->getDevice(), QString());
}

QString USBDeviceResolver::getSubIDString(const DeviceEntity *e) const
{
	return QString();
}
