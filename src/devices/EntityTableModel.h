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

#ifndef INCLUDE_ENTITY_TABLE_MODEL_H
#define INCLUDE_ENTITY_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QModelIndex>

class DeviceEntity;
class DeviceResolver;

class EntityTableModel : public QAbstractTableModel
{
	public:
		EntityTableModel(const DeviceResolver *r, QObject *p = 0);
		virtual ~EntityTableModel();
		
		QString getSelectedText(const QModelIndexList &indexes) const;
		QString getAllText() const;
		
		virtual int rowCount(const QModelIndex &p = QModelIndex()) const;
		virtual int columnCount(const QModelIndex &p = QModelIndex()) const;
		virtual QVariant data(const QModelIndex &i, int r = Qt::DisplayRole) const;
		virtual QVariant headerData(int s, Qt::Orientation o, int r = Qt::DisplayRole) const;
	
		virtual void refresh() = 0;
		virtual int entityCount() const = 0;
		virtual DeviceEntity *entityAt(int i) const = 0;
		
	protected:
		const DeviceResolver *getDeviceResolver() const;
		void setDeviceResolver(const DeviceResolver *r);
	
		virtual void clearEntities() = 0;
	
	private:
		const DeviceResolver *resolver;
};

#endif
