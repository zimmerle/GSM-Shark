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
        onRadioStatus: {
            if (status == 1)
            {
                radioAlert.missingRadio();
            }
            else
            {
                radioAlert.radioOk();
            }
        }

    }

    /* Switch the application MainView between maps and list */
    Connections {
        target: viewSwitch
        onSwitchView: {
            Core.switchMainView(view);
            radioAlert.changeView();

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

    Rectangle {
        id: views

        property real selectedView: 0;

        width: parent.width
        height: parent.height

        /* Maps view */
        MapsView {
            id: mapsView
            x: 0
            y: 0
            width: parent.width
            height: parent.height

            opacity: 1
        }

        /* List View */
        ListView {
            id: listView
            x: 0
            y: 0
            width: parent.width
            height: parent.height

            opacity: 0
        }

        /* Alert box */
        RadioAlert {
            z: 4
            id: radioAlert
            target: mainWindow
            view: parent.selectedView
            listView: listView
        }

    }


    ParallelAnimation {
        id: switchViews
        NumberAnimation {
            target: mapsView
            property: "opacity";
            to: 1-views.selectedView;
            duration: 200
        }

        NumberAnimation {
            target: listView
            property: "opacity";
            to: views.selectedView;
            duration: 200
        }
    }


}
