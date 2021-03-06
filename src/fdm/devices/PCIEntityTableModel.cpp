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

#include "PCIEntityTableModel.h"

#include <wbemidl.h>
#include <comdef.h>
#include <Windows.h>

#include "fdm/devices/PCIEntity.h"

PCIEntityTableModel::PCIEntityTableModel(const DeviceResolver *r, QObject *p)
	: EntityTableModel(r, p)
{
	refresh();
}

PCIEntityTableModel::~PCIEntityTableModel()
{
	clearEntities();
}

// TODO - Emit a signal so table will have the correct info?
void PCIEntityTableModel::refresh()
{
	HRESULT hr;
	IWbemLocator *loc;
	IWbemServices *svc;
	IEnumWbemClassObject *it;
	IWbemClassObject *item;
	ULONG ureturn;
	
	// Clear existing device list.
	
	clearEntities();
	
	// Initialize COM library.
	
	hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if(FAILED(hr))
		return;

	// Set COM security level.

	hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT,
		RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
	if(FAILED(hr) && (hr != RPC_E_TOO_LATE)) // If CoInitializeSecurity has already been called, try to proceed anyway.
	{
		CoUninitialize();
		return;
	}

	// Initialize locator interface.

	hr = CoCreateInstance(CLSID_WbemLocator, NULL, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *) &loc);
	if(FAILED(hr))
	{
		CoUninitialize();
		return;
	}

	// Connect to WMI namespace.

	hr = loc->ConnectServer(BSTR(L"ROOT\\cimv2"), NULL, NULL, NULL, 0, NULL, NULL, &svc);
	if(FAILED(hr))
	{
		loc->Release();
		CoUninitialize();
		return;
	}

	// Set WMI connection security.

	hr = CoSetProxyBlanket(svc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL,
		RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);
	if(FAILED(hr))
	{
		svc->Release();
		loc->Release();
		CoUninitialize();
		return;
	}

	// Get PCI Bus information.

	hr = svc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_PnPEntity"), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
		NULL, &it);
	if(FAILED(hr))
	{
		svc->Release();
		loc->Release();
		CoUninitialize();
		return;
	}
	
	// Process the data we retrieved.
	
	while(it)
	{
		VARIANT prop;

		// Get the next item in the list.

		hr = it->Next(WBEM_INFINITE, 1, &item, &ureturn);

		if(ureturn == 0)
			break;
		
		// Retrieve Device ID.
		
		hr = item->Get(L"DeviceID", 0, &prop, NULL, NULL);
		PCIEntity *e = new PCIEntity(QString::fromStdWString(prop.bstrVal));
		
		if(e->isGood())
			devices.push_back(e);
		else
			delete e;
		
		// Clean up.
		
		VariantClear(&prop);
		item->Release();
	}
	
	it->Release();
	svc->Release();
	loc->Release();
	CoUninitialize();
}

int PCIEntityTableModel::entityCount() const
{
	return devices.count();
}

DeviceEntity *PCIEntityTableModel::entityAt(int i) const
{
	return devices.at(i);
}

void PCIEntityTableModel::clearEntities()
{
	while(!devices.isEmpty())
		delete devices.takeFirst();
}
