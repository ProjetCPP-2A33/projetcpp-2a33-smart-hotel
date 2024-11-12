cmake_minimum_required(VERSION 3.16)

project(InterfaceCRUD VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Users/nour1/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Qt/6.6.3/mingw_64")

# Find required Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts)

# Set project sources
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    connection.h
    connection.cpp
    service.h
    service.cpp
)

# Add executable and link libraries
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(InterfaceCRUD
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(InterfaceCRUD
        ${PROJECT_SOURCES}
    )
endif()

# Link the necessary Qt libraries
target_link_libraries(InterfaceCRUD PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Sql Qt6::Charts)

# Set properties for macOS bundle or Windows executable
set_target_properties(InterfaceCRUD PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS InterfaceCRUD
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize the executable if using Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(InterfaceCRUD)
endif()

