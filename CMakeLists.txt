cmake_minimum_required(VERSION 3.0.2)
project(FDM)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Allow for custom Qt prefixes.
if(CUSTOM_QT_DIR)
	set(CMAKE_PREFIX_PATH ${CUSTOM_QT_DIR} ${CMAKE_PREFIX_PATH})
	set(QT_ROOT_DIR ${CUSTOM_QT_DIR})
	set(QT_QMAKE_EXECUTABLE ${CUSTOM_QT_DIR}/bin/qmake)
endif()

# Define project dependencies.

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Set compile flags.

include(${PROJECT_SOURCE_DIR}/cmake/SetFlags.cmake)
fdmSetCompileFlags()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DFDM_DEBUG")

include_directories(src)

# Define the libraries to link against.

set(FDM_LIBRARIES
	${Qt5Widgets_LIBRARIES}
	${Qt5Gui_LIBRARIES}
	${Qt5Core_LIBRARIES}
	)

add_subdirectory(src/fdm)
