TEMPLATE=app

INCLUDEPATH += /usr/local/include/gnuradio
INCLUDEPATH += /usr/local/src/uhd/host/include
INCLUDEPATH += /opt/local/include/

LIBS += -L/usr/local/lib/ -luhd -lgnuradio-core -lgnuradio-usrp -lgnuradio-uhd

RESOURCES += \
     ../resources.qrc

OTHER_FILES += \
     ../res/main.css

QT += declarative
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

TARGET=../gsmdog
