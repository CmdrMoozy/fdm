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

#ifndef INCLUDE_FDM_MAIN_WINDOW_H
#define INCLUDE_FDM_MAIN_WINDOW_H

#include <QMainWindow>

class QMenu;
class QAction;
class QTabWidget;

class FDMAboutDialog;
class PCIDeviceResolver;
class PCIEntityTableModel;
class USBDeviceResolver;
class USBEntityTableModel;

class FDMMainWindow : public QMainWindow
{
	Q_OBJECT
	
	public:
		FDMMainWindow(QWidget *p = 0, Qt::WindowFlags f = 0);
		virtual ~FDMMainWindow();
		
	private:
		FDMAboutDialog *aboutDialog;
	
		QMenu *fileMenu;
		QMenu *editMenu;
		QMenu *helpMenu;
	
		QAction *exitAction;
		QAction *copySelectedAction;
		QAction *copyAllAction;
		QAction *aboutFDMAction;
		QAction *aboutQtAction;
		
		PCIDeviceResolver *pciResolver;
		PCIEntityTableModel *pciModel;
		USBDeviceResolver *usbResolver;
		USBEntityTableModel *usbModel;
	
		QTabWidget *deviceTabs;
	
		void createDialogs();
		void createActions();
		void createMenus();
	
	private slots:
		void doCopySelected();
		void doCopyAll();
		void doAboutFDM();
};

#endif
