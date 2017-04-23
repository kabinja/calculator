QT += qml quick

CONFIG += c++11

RESOURCES += qml.qrc

PRECOMPILED_HEADER = includes.h

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(calculator.pri)
include(deployment.pri)
