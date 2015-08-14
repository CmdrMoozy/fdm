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

#include "FDMUtil.h"

bool FDMUtil::isHexChar(const QChar &c)
{
	switch(c.toLatin1())
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
			return true;
		
		default:
			return false;
	};
}

bool FDMUtil::isHexString(const QString &s)
{
	for(int i = 0; i < s.length(); ++i)
	{
		if(!isHexChar(s[i]))
			return false;
	}
	
	return true;
}

bool FDMUtil::isWhitespace(const QString &s)
{
	for(int i = 0; i < s.length(); ++i)
	{
		if(!s[i].isSpace())
			return false;
	}
	
	return true;
}
