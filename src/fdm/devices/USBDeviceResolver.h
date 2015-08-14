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

#ifndef INCLUDE_USB_DEVICE_RESOLVER_H
#define INCLUDE_USB_DEVICE_RESOLVER_H

#include "fdm/devices/DeviceResolver.h"

#include <QHash>
#include <QString>

class DeviceEntity;

class USBDeviceResolver : public DeviceResolver
{
	public:
		USBDeviceResolver();
		virtual ~USBDeviceResolver();
	
		virtual QString getVendorString(const DeviceEntity *e) const;
		virtual QString getDeviceString(const DeviceEntity *e) const;
		virtual QString getSubIDString(const DeviceEntity *e) const;
	
	private:
		QHash< QString, QString > vendorm;
		QHash< QString, QString > devicem;
		QHash< QString, QString > ifacem;
};

#endif
