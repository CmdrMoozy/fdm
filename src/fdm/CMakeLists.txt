set(FDM_RESOURCES
	data.qrc
	)

set(root_SOURCES
	FDM.cpp
	FDMMainWindow.cpp
	FDMMainWindow.h
	FDMUtil.cpp
	FDMUtil.h
	)
source_group(FDM FILES ${root_SOURCES})
list(APPEND FDM_SOURCES ${root_SOURCES})

set(devices_SOURCES
	devices/DeviceEntity.h
	devices/DeviceResolver.h
	devices/EntityTableModel.cpp
	devices/EntityTableModel.h
	devices/FDMDeviceTab.cpp
	devices/FDMDeviceTab.h
	devices/PCIDeviceResolver.cpp
	devices/PCIDeviceResolver.h
	devices/PCIEntity.cpp
	devices/PCIEntity.h
	devices/PCIEntityTableModel.cpp
	devices/PCIEntityTableModel.h
	devices/USBDeviceResolver.cpp
	devices/USBDeviceResolver.h
	devices/USBEntity.cpp
	devices/USBEntity.h
	devices/USBEntityTableModel.cpp
	devices/USBEntityTableModel.h
	)
source_group(FDM\\devices FILES ${devices_SOURCES})
list(APPEND FDM_SOURCES ${devices_SOURCES})

set(dialogs_SOURCES
	dialogs/FDMAboutDialog.cpp
	dialogs/FDMAboutDialog.h
	)
source_group(FDM\\dialogs FILES ${dialogs_SOURCES})
list(APPEND FDM_SOURCES ${dialogs_SOURCES})

set(util_SOURCES
	util/MSVCWarnings.h
	)
source_group(FDM\\util FILES ${util_SOURCES})
list(APPEND FDM_SOURCES ${util_SOURCES})

qt5_add_resources(FDM_RESOURCES_RCC ${FDM_RESOURCES})

add_executable(FDM
	${FDM_SOURCES}
	${FDM_RESOURCES_RCC}
	)
target_link_libraries(FDM ${FDM_LIBRARIES})
