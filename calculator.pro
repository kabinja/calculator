QT += qml quick

CONFIG += c++11

RESOURCES += resources/qml.qrc

PRECOMPILED_HEADER = src/includes.h

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(calculator.pri)
include(deployment.pri)
