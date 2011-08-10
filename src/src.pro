TEMPLATE=app

RESOURCES += ../resources.qrc

QT += declarative gui

INCLUDEPATH += /usr/local/include/gnuradio
INCLUDEPATH += /usr/local/src/uhd/host/include
INCLUDEPATH += /opt/local/include/

LIBS += -L/usr/local/lib/ -luhd -lgnuradio-core -lgnuradio-usrp -lgnuradio-uhd

OTHER_FILES += \
     ../res/main.css \
    ../qml/gsmshark/main.js \
    ../qml/gsmshark/MapsZoom.qml \
    ../qml/gsmshark/MapsView.qml \
    ../qml/gsmshark/main.qml \
    ../qml/gsmshark/ListView.qml \
    ../qml/gsmshark/Ip2GeoLocation.qml

CONFIG(debug, debug|release):CONFIG += declarative_debug


SOURCES += main.cpp \
    gnuradioworker.cpp \
    mainwin.cpp \
    fakesegmentedbutton.cpp \
    arfcn.cpp \
    combochannel.cpp \
    scanengine.cpp \
    radiostatus.cpp \
    radio.cpp

HEADERS += \
    gnuradioworker.h \
    mainwin.h \
    fakesegmentedbutton.h \
    common.h \
    arfcn.h \
    combochannel.h \
    scanengine.h \
    radiostatus.h \
    radio.h

TARGET=../gsmshark


