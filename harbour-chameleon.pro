# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = harbour-chameleon
CONFIG += sailfishapp
CONFIG += debug
CONFIG += console
INCLUDEPATH += src

SOURCES += src/harbour-chameleon.cpp \
    src/BlinkMDriver.cpp \
    src/TCS34725Driver.cpp \
    src/controller.cpp \
    src/driverBase.cpp \
    src/colorPoller.cpp
	
HEADERS += \
    src/BlinkMDriver.h \
    src/TCS34725Driver.h \
    src/controller.h \
    src/driverBase.h \
    src/colorPoller.h

OTHER_FILES += qml/harbour-chameleon.qml \
    qml/cover/CoverPage.qml \
    rpm/harbour-chameleon.spec \
    rpm/harbour-chameleon.yaml \
    harbour-chameleon.desktop \
    harbour-chameleon.png \
    qml/pages/Main.qml

