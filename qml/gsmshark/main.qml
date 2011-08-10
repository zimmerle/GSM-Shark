import Qt 4.7
import QtWebKit 1.0
import QtMobility.location 1.2
import QtQuick 1.0
import QtDesktop 0.1

import "main.js" as Core
//import "HostInfoModel.qml" as HostInfoModel
import "."

Rectangle {
    id: mainWindow

    /* Resize the qml windows according to the parent window */
    Connections {
        target: mainWindowContext
        onNewWindowSize: {
            mainWindow.width = width
            mainWindow.height = height
        }
    }

    /* Switch the application MainView between maps and list */
    Connections {
        target: viewSwitch
        onSwitchView: {
            Core.fadeMainView(view);
        }
    }

    /* background */
    Image {
        id: background_mainview
        width: parent.width
        height: parent.height

        source: "qrc:/res/application_background.png"
        MouseArea { anchors.fill: parent; }
        fillMode: Image.TileHorizontally
    }

    /* Maps view */
    MapsView {
        id: mapsView
        x: 0
        y: 0
        width: parent.width
        height: parent.height

        opacity: 1
    }

    /* List View*/
    ListView {
        id: listView
        x: 0
        y: 0
        width: parent.width
        height: parent.height

        opacity: 0
    }
}

/*
    ParallelAnimation {
        id: switchViews
        NumberAnimation {
            target: mapView;
            property: "latitude";
            to: latitude2go;
            duration: 1000
        }
        NumberAnimation {
            target: mapView;
            property: "longitude";
            to: longitude2go;
            duration: 1000
        }
        NumberAnimation {
            target: zoom;
            property: "value";
            to: 6;
            duration: 1000
        }
    }

*/
