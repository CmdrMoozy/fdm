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

#include "EntityTableModel.h"

#include <set>

#include <QModelIndexList>

#include "devices/DeviceEntity.h"
#include "devices/DeviceResolver.h"

EntityTableModel::EntityTableModel(const DeviceResolver *r, QObject *p)
	: QAbstractTableModel(p), resolver(r)
{
}

EntityTableModel::~EntityTableModel()
{
}

QString EntityTableModel::getSelectedText(const QModelIndexList &indexes) const
{
	std::set<int> rows;
	
	for(int i = 0; i < indexes.count(); ++i)
		rows.insert(indexes.at(i).row());
	
	QString text = "";
	
	for(std::set<int>::iterator it = rows.begin(); it != rows.end(); ++it)
	{
		for(int j = 0; j < 6; ++j)
		{
			text += data(createIndex( (*it), j )).toString();
			
			if(j < 5)
				text += "\t";
		}
		
		text += "\n";
	}
	
	text.chop(1);
	return text;
}

QString EntityTableModel::getAllText() const
{
	QString text = "";
	
	for(int i = 0; i < rowCount(); ++i)
	{
		for(int j = 0; j < 6; ++j)
		{
			text += data(createIndex(i, j)).toString();
			
			if(j < 5)
				text += "\t";
		}
		
		if(i < (rowCount() - 1))
			text += "\n";
	}
	
	return text;
}

int EntityTableModel::rowCount(const QModelIndex &p) const
{
	return entityCount();
}

int EntityTableModel::columnCount(const QModelIndex &p) const
{
	return 6;
}

QVariant EntityTableModel::data(const QModelIndex &i, int r) const
{
	switch(r)
	{
		case Qt::DisplayRole:
		{
			int row = i.row();
			if( (row < 0) || (row >= entityCount()) )
				return QVariant(QVariant::Invalid);
			
			DeviceEntity *e = entityAt(row);
			if(e == NULL)
				return QVariant(QVariant::Invalid);
			
			switch(i.column())
			{
				case 0:
					return QVariant(e->getVendor());
				
				case 1:
					return QVariant(e->getDevice());
				
				case 2:
					return QVariant(e->getSubID());
				
				case 3:
					return QVariant(resolver->getVendorString(e));
				
				case 4:
					return QVariant(resolver->getDeviceString(e));
				
				case 5:
					return QVariant(resolver->getSubIDString(e));
				
				default:
					return QVariant(QVariant(QVariant::Invalid));
			};
		}
		
		case Qt::AccessibleDescriptionRole:
			return headerData(i.column(), Qt::Horizontal, Qt::DisplayRole);
		
		default:
			return QVariant(QVariant::Invalid);
	};
}

QVariant EntityTableModel::headerData(int s, Qt::Orientation o, int r) const
{
	if(o != Qt::Horizontal)
		return QVariant(QVariant::Invalid);
	
	switch(r)
	{
		case Qt::DisplayRole:
			{
				switch(s)
				{
					case 0:
						return QVariant("Ven ID");
					
					case 1:
						return QVariant("Dev ID");
					
					case 2:
						return QVariant("Sub ID");
					
					case 3:
						return QVariant("Vendor");
					
					case 4:
						return QVariant("Device");
					
					case 5:
						return QVariant("Subvendor / Subdevice");
					
					default:
						return QVariant(QVariant::Invalid);
				};
			}
			break;
			
		default:
			return QVariant(QVariant::Invalid);
	};
}

const DeviceResolver *EntityTableModel::getDeviceResolver() const
{
	return resolver;
}

void EntityTableModel::setDeviceResolver(const DeviceResolver *r)
{
	resolver = r;
}
