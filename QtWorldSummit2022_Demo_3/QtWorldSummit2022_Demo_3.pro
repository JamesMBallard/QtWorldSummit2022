CONFIG += warn_on qmltestcase

CONFIG += c++17
QMAKE_CXXFLAGS += -Zc:__cplusplus -std:c++17

ARCGIS_RUNTIME_VERSION = 200.0.0
include($$PWD/arcgisruntime.pri)

TEMPLATE = app

DISTFILES += \
    tst_testdemo3.qml

SOURCES += \
    main.cpp
