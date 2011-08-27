TEMPLATE=app

RESOURCES += ../resources.qrc

QT += declarative gui

CONFIG += link_pkgconfig
PKGCONFIG += gnuradio-uhd gnuradio-core gnuradio-usrp uhd

# FIXME: Hardcoded libs.
LIBS += -losmogsm -losmocodec -losmocore -losmovty
# Such libraries has no official packages or pkg-config info.
# Keeping this as it is. No need to ave a "configure" or "automake"
# right now, the thing is in very early development.
# For more info about those libraries take a look at: http://www.osmocom.org/

AIRPROBE_DIR = ../../airprobe

INCLUDEPATH += $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff

CONFIG(debug, debug|release):CONFIG += declarative_debug


message(Qt version: $$[QT_VERSION])
message(Qt is installed in $$[QT_INSTALL_PREFIX])
message(This project will use the airprobe installed in $$AIRPROBE_DIR)

OTHER_FILES += \
     ../res/main.css \
    ../qml/gsmshark/main.js \
    ../qml/gsmshark/MapsZoom.qml \
    ../qml/gsmshark/RadioAlert.qml \
    ../qml/gsmshark/MapsView.qml \
    ../qml/gsmshark/main.qml \
    ../qml/gsmshark/ListView.qml \
    ../qml/gsmshark/Ip2GeoLocation.qml

SOURCES += main.cpp \
    gnuradioworker.cpp \
    mainwin.cpp \
    fakesegmentedbutton.cpp \
    arfcn.cpp \
    combochannel.cpp \
    scanengine.cpp \
    radiostatus.cpp \
    radio.cpp \
    gr_tunner.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/viterbi_detector.cc \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/gsm_receiver_config.cc \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/gsm_receiver_cf.cc \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/sch.c \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/interleave.c \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/gsmstack.c \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/fire_crc.c \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/cch.c \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/Threads.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/Timeval.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/GSMTDMA.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/GSML1FEC.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/GSMCommon.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/GSM690Tables.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/GSM660Tables.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/GSM610Tables.cpp \
    $$AIRPROBE_DIR/gsm-receiver/src/lib/decoder/openbtsstuff/BitVector.cpp

HEADERS += \
    gnuradioworker.h \
    mainwin.h \
    fakesegmentedbutton.h \
    common.h \
    arfcn.h \
    combochannel.h \
    scanengine.h \
    radiostatus.h \
    radio.h \
    gr_tunner.h

TARGET=../gsmshark

















































