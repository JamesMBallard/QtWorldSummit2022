QT += testlib
QT -= gui

CONFIG += c++17
QMAKE_CXXFLAGS += -Zc:__cplusplus -std:c++17

# additional modules are pulled in via arcgisruntime.pri

ARCGIS_RUNTIME_VERSION = 200.0.0
include($$PWD/arcgisruntime.pri)

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testdemo2.cpp
