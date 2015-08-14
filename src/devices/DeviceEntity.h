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

#ifndef INCLUDE_DEVICE_ENTITY_H
#define INCLUDE_DEVICE_ENTITY_H

#include <QString>

class DeviceEntity
{
	public:
		virtual bool isGood() const = 0;
		virtual bool setDescriptor(const QString &d) = 0;
		
		virtual QString getVendor() const = 0;
		virtual QString getDevice() const = 0;
		virtual QString getSubID() const = 0;
};

#endif
