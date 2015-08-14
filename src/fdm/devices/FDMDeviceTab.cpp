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

#include "FDMDeviceTab.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableView>
#include <QClipboard>
#include <QApplication>

#include "devices/EntityTableModel.h"

FDMDeviceTab::FDMDeviceTab(EntityTableModel *m, QWidget *p, Qt::WindowFlags f)
	: QWidget(p, f)
{
	layout = new QGridLayout(this);
	
	headerWidget = new QWidget(this);
	headerLayout = new QGridLayout(headerWidget);
	
	refreshButton = new QPushButton(tr("&Refresh"), headerWidget);
	
	headerLayout->addWidget(refreshButton, 0, 1, 1, 1);
	headerLayout->setColumnStretch(0, 1);
	headerWidget->setLayout(headerLayout);
	
	deviceView = new QTableView(this);
	deviceView->setSelectionBehavior(QAbstractItemView::SelectRows);
	deviceView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	
	layout->addWidget(headerWidget, 0, 0, 1, 1);
	layout->addWidget(deviceView, 1, 0, 1, 1);
	layout->setRowStretch(1, 1);
	setLayout(layout);
	
	QObject::connect( refreshButton, SIGNAL( clicked() ), this, SLOT( doRefresh() ) );
	
	setModel(m);
	deviceView->resizeColumnsToContents();
}

FDMDeviceTab::~FDMDeviceTab()
{
}

EntityTableModel *FDMDeviceTab::getModel() const
{
	return dynamic_cast< EntityTableModel * >(deviceView->model());
}

void FDMDeviceTab::setModel(EntityTableModel *m)
{
	deviceView->setModel(m);
}

void FDMDeviceTab::selectedToClipboard() const
{
	QClipboard *clipboard = QApplication::clipboard();
	EntityTableModel *m = getModel();
	QString text = "";
	
	if(m != NULL)
		text = m->getSelectedText(deviceView->selectionModel()->selectedRows());
	
	clipboard->setText(text);
}

void FDMDeviceTab::allToClipboard() const
{
	QClipboard *clipboard = QApplication::clipboard();
	EntityTableModel *m = getModel();
	QString text = "";
	
	if(m != NULL)
		text = m->getAllText();
	
	clipboard->setText(text);
}

void FDMDeviceTab::doRefresh()
{ /* SLOT */
	
	EntityTableModel *m = getModel();
	
	if(m != NULL)
		m->refresh();
	
}
