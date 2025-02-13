cmake_minimum_required(VERSION 3.14)

project(Figure VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} WIN32)

set(PROJECT_SOURCES
        main.cpp
	figure.cpp figure.h
	figurewindow.cpp figurewindow.h
	figurewindow.ui
	scene.h scene.cpp
	figurefabric.cpp figurefabric.h
	figuretypes.h
	ellipse.h ellipse.cpp
	triangle.h triangle.cpp
	randomgenerator.h
	circle.h circle.cpp
	mathhelper.h mathhelper.cpp
	convexunconvexpolygon.h convexunconvexpolygon.cpp
	parallelogramm.h parallelogramm.cpp
	rectangle.h rectangle.cpp
	square.h square.cpp
)


target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES} ${TS_FILES} ${PROJECT_HEADERS} ${RS})

target_link_libraries(Figure PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Figure PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

