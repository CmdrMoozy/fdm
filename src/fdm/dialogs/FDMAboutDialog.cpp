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

#include "FDMAboutDialog.h"

#include <QGridLayout>
#include <QTabWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QFont>
#include <QIcon>

FDMAboutDialog::FDMAboutDialog(QWidget *p, Qt::WindowFlags f)
	: QDialog(p, f)
{
	// Setup GUI.
	
	layout = new QGridLayout(this);
	
	aboutTabs = new QTabWidget(this);
	
	// FDM Tab
	
	fdmTab = new QWidget(aboutTabs);
	fdmTabLayout = new QGridLayout(fdmTab);
	
	logoLabel = new QLabel(tr("Logo"), fdmTab);
	
	headerLabel = new QLabel(tr("FDM 1.0.0"), fdmTab);
	headerLabel->setFont(QFont(headerLabel->font().family(), 18));
	headerLabel->setMargin(5);
	
	aboutText = new QTextEdit(fdmTab);
	aboutText->setLineWrapMode(QTextEdit::NoWrap);
	aboutText->setReadOnly(true);
	
	fdmTabLayout->addWidget( logoLabel,   0, 0, 1, 1 );
	fdmTabLayout->addWidget( headerLabel, 0, 1, 1, 1 );
	fdmTabLayout->addWidget( aboutText,   1, 0, 1, 2 );
	fdmTabLayout->setColumnStretch(1, 1);
	fdmTabLayout->setRowStretch(1, 1);
	fdmTab->setLayout(fdmTabLayout);
	
	// License Tab
	
	licenseTab = new QWidget(aboutTabs);
	licenseTabLayout = new QGridLayout(licenseTab);
	
	licenseText = new QTextEdit(licenseTab);
	licenseText->setLineWrapMode(QTextEdit::NoWrap);
	licenseText->setReadOnly(true);
	
	licenseTabLayout->addWidget( licenseText, 0, 0, 1, 1 );
	licenseTab->setLayout(licenseTabLayout);
	
	// Add everything to the dialog.
	
	closeButton = new QPushButton(tr("Clos&e"), this);
	
	aboutTabs->addTab(fdmTab, tr("FDM"));
	aboutTabs->addTab(licenseTab, tr("License"));
	
	layout->addWidget( aboutTabs,   0, 0, 1, 1 );
	layout->addWidget( closeButton, 1, 0, 1, 1 );
	layout->setRowStretch(0, 1);
	setLayout(layout);
	
	QObject::connect( closeButton, SIGNAL( clicked() ), this, SLOT( close() ) );
	
	// Load text.
	
	loadAboutText();
	loadLicenseText();
}

FDMAboutDialog::~FDMAboutDialog()
{
}

void FDMAboutDialog::loadAboutText()
{
	aboutText->setText("");
	QFile file(":/data/about.txt");
	
	if(file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream(&file);
		
		while(!stream.atEnd())
			aboutText->append(stream.readLine());
		
		file.close();
		aboutText->moveCursor(QTextCursor::Start);
	}
}

void FDMAboutDialog::loadLicenseText()
{
	licenseText->setText("");
	QFile file(":/data/license.txt");
	
	if(file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream(&file);
		
		while(!stream.atEnd())
			licenseText->append(stream.readLine());
		
		file.close();
		licenseText->moveCursor(QTextCursor::Start);
	}
}
