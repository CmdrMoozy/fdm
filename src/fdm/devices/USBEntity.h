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

#ifndef INCLUDE_USB_ENTITY_H
#define INCLUDE_USB_ENTITY_H

#include "devices/DeviceEntity.h"

#include <cstdint>

class USBEntity : public DeviceEntity
{
	public:
		USBEntity(const QString &d = QString());
		USBEntity(const USBEntity &o);
		virtual ~USBEntity();
		
		USBEntity &operator=(const USBEntity &o);
	
		bool operator==(const USBEntity &o) const;
		bool operator<(const USBEntity &o) const;
		bool operator<=(const USBEntity &o) const;
		bool operator>(const USBEntity &o) const;
		bool operator>=(const USBEntity &o) const;
		
		virtual bool isGood() const;
		virtual bool setDescriptor(const QString &d);
		
		virtual QString getVendor() const;
		virtual QString getDevice() const;
		virtual QString getSubID() const;
	
	private:
		bool good;
		QString vendor;
		QString device;
	
		uint32_t comparisonValue() const;
};

#endif
