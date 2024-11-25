cmake_minimum_required(VERSION 3.16)

project(InterfaceCRUD VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Spécifier le chemin d'installation de Qt (ajustez si nécessaire)
set(CMAKE_PREFIX_PATH "C:/Users/nour1/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Qt/6.6.3/mingw_64")

# Rechercher les composants nécessaires de Qt
#find_package(Qt6 REQUIRED COMPONENTS Widgets Network Sql Charts SerialPort)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Charts Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts Network)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Charts Network SerialPort)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts Network SerialPort)

# Déclaration des fichiers sources du projet
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    service.h
    service.cpp
    connection.cpp
    connection.h
)

# Création de l'exécutable
qt_add_executable(InterfaceCRUD
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# Lier les bibliothèques nécessaires
target_link_libraries(InterfaceCRUD
    PRIVATE
    Qt6::Widgets
    Qt6::Network
    Qt6::Sql
    Qt6::Charts
    Qt6::SerialPort # Ajout du module SerialPort
)

# Finalisation de l'exécutable pour Qt6
qt_finalize_executable(InterfaceCRUD)
