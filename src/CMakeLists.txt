FIND_PACKAGE(Qt4 REQUIRED QtCore QtGui QtXml QtDeclarative)
FIND_PACKAGE(Boost REQUIRED)


set(GNU_RADIO_HEADERS "/usr/local/include/gnuradio/")
set(GNU_RADIO_LIBS "-L/usr/local/lib/ -lgnuradio-core -lgnuradio-uhd")

set(UHD_HEADERS "/usr/local/include/uhd")
set(UHD_LIBS "-L/usr/local/lib/ -luhd")


INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${GNU_RADIO_HEADERS} ${UHD_HEADERS})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIBS ${LIBS} ${QT_LIBRARIES} ${Boost_LIBRARY_DIRS})
set(LIBS ${LIBS} ${UHD_LIBS} ${GNU_RADIO_LIBS})

SET(gs_SOURCES main.cpp gnuradioworker.cpp mainwin.cpp fakesegmentedbutton.cpp arfcn.cpp combochannel.cpp scanengine.cpp radiostatus.cpp radio.cpp)

SET(gs_HEADERS gnuradioworker.h mainwin.h fakesegmentedbutton.h common.h arfcn.h combochannel.h scanengine.h radiostatus.h radio.h)

SET(gs_RESOURCES ../resources.qrc)

QT4_WRAP_CPP(gs_HEADERS_MOC ${gs_HEADERS})
QT4_ADD_RESOURCES(gs_RESOURCES_RCC ${gs_RESOURCES})

ADD_DEFINITIONS( -Wall )

add_executable(gsm-shark ${gs_SOURCES} ${gs_HEADERS_MOC} ${gs_RESOURCES_RCC})

target_link_libraries(gsm-shark ${LIBS})

