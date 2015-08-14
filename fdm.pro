TEMPLATE = app
TARGET = FDM
CONFIG += release console
DEPENDPATH += src/
INCLUDEPATH += src/

HEADERS += src/FDMUtil.h \
	src/FDMMainWindow.h \
	src/devices/DeviceEntity.h \
	src/devices/DeviceResolver.h \
	src/devices/EntityTableModel.h \
	src/devices/PCIEntity.h \
	src/devices/PCIDeviceResolver.h \
	src/devices/PCIEntityTableModel.h \
	src/devices/USBEntity.h \
	src/devices/USBDeviceResolver.h \
	src/devices/USBEntityTableModel.h \
	src/devices/FDMDeviceTab.h \
	src/dialogs/FDMAboutDialog.h

SOURCES += src/FDM.cpp \
	src/FDMUtil.cpp \
	src/FDMMainWindow.cpp \
	src/devices/EntityTableModel.cpp \
	src/devices/PCIEntity.cpp \
	src/devices/PCIDeviceResolver.cpp \
	src/devices/PCIEntityTableModel.cpp \
	src/devices/USBEntity.cpp \
	src/devices/USBDeviceResolver.cpp \
	src/devices/USBEntityTableModel.cpp \
	src/devices/FDMDeviceTab.cpp \
	src/dialogs/FDMAboutDialog.cpp

RESOURCES += data.qrc

QMAKE_CXXFLAGS += /O2
