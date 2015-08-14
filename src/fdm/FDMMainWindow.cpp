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

#include "FDMMainWindow.h"

#include <QMenu>
#include <QAction>
#include <QTabWidget>
#include <QMenuBar>
#include <QApplication>

#include "dialogs/FDMAboutDialog.h"
#include "devices/FDMDeviceTab.h"
#include "devices/PCIDeviceResolver.h"
#include "devices/PCIEntityTableModel.h"
#include "devices/USBDeviceResolver.h"
#include "devices/USBEntityTableModel.h"

FDMMainWindow::FDMMainWindow(QWidget *p, Qt::WindowFlags f)
	: QMainWindow(p, f)
{
	// Setup our window.
	
	setWindowTitle(tr("FDM"));
	
	// Create some stuff.
	
	createDialogs();
	createActions();
	createMenus();
	
	// Create our device models.
	
	pciResolver = new PCIDeviceResolver();
	pciModel = new PCIEntityTableModel(pciResolver);
	
	usbResolver = new USBDeviceResolver();
	usbModel = new USBEntityTableModel(usbResolver);
	
	// Make our tab widget, and create a couple of tabs.
	
	deviceTabs = new QTabWidget(this);
	
	deviceTabs->addTab(new FDMDeviceTab(pciModel, deviceTabs), tr("PCI Devices"));
	deviceTabs->addTab(new FDMDeviceTab(usbModel, deviceTabs), tr("USB Devices"));
	
	setCentralWidget(deviceTabs);
	resize(700, 400);
}

FDMMainWindow::~FDMMainWindow()
{
	delete pciModel;
	delete pciResolver;
}

void FDMMainWindow::createDialogs()
{
	aboutDialog = new FDMAboutDialog(this);
}

void FDMMainWindow::createActions()
{
	exitAction         = new QAction(tr("E&xit"),                  this);
	copySelectedAction = new QAction(tr("Copy &Selected Devices"), this);
	copyAllAction      = new QAction(tr("Copy &All Devices"),      this);
	aboutFDMAction     = new QAction(tr("About FDM..."),           this);
	aboutQtAction      = new QAction(tr("About &Qt..."),           this);
	
	QObject::connect( exitAction,         SIGNAL( triggered() ), this, SLOT( close()          ) );
	QObject::connect( copySelectedAction, SIGNAL( triggered() ), this, SLOT( doCopySelected() ) );
	QObject::connect( copyAllAction,      SIGNAL( triggered() ), this, SLOT( doCopyAll()      ) );
	QObject::connect( aboutFDMAction,     SIGNAL( triggered() ), this, SLOT( doAboutFDM()     ) );
	QObject::connect( aboutQtAction,      SIGNAL( triggered() ), qApp, SLOT( aboutQt()        ) );
}

void FDMMainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(exitAction);
	
	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(copySelectedAction);
	editMenu->addAction(copyAllAction);
	
	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutFDMAction);
	helpMenu->addAction(aboutQtAction);
}

void FDMMainWindow::doCopySelected()
{ /* SLOT */
	
	FDMDeviceTab *tab = dynamic_cast<FDMDeviceTab *>(deviceTabs->currentWidget());
	if(tab == NULL)
		return;
	
	tab->selectedToClipboard();
	
}

void FDMMainWindow::doCopyAll()
{ /* SLOT */
	
	FDMDeviceTab *tab = dynamic_cast<FDMDeviceTab *>(deviceTabs->currentWidget());
	if(tab == NULL)
		return;
	
	tab->allToClipboard();
	
}

void FDMMainWindow::doAboutFDM()
{ /* SLOT */
	aboutDialog->show();
}
