import Qt 4.7
import QtWebKit 1.0
import QtMobility.location 1.2
import QtQuick 1.0
import QtDesktop 0.1

Rectangle {

    property variant target: null
    property variant view: null
    property variant listView: null

    property string title: ''
    property string message: ''
    property string icon: ''

    /* 0 == none, 1 == missing radio */
    property int myState: 0

    onStateChanged: { this_thing.state = state }

    function missingRadio()
    {
        myState = 1
        icon.source = "qrc:/res/messagebox_warning.png";
        message.text = "Unable to perform a network scanner";
        title.text = "Radio not found!"
        changeView();
    }

    function radioOk()
    {
        if (myState == 0)
            return;

        if (myState == 1)
        {
            myState = 0;
            this_thing.state = ''
            icon.source = ''
            message.text = ''
            title.text = ''
        }
    }

    function changeView()
    {
        if (myState == 0)
            return;

        if (view == 0)
        {
            this_thing.state = 'map'
        }
        else
        {
            this_thing.state = 'list'
        }
    }

    Rectangle {
        width: 0
        height: 0
        x: 0
        y: 0
        opacity: 0.0

        id: this_thing
        color: "white"
        radius: 8

        Image {
            fillMode: Image.PreserveAspectFit
            height: parent.height-10
            x: 5
            y: 5
            id: icon
        }


        Text {
            x: icon.x*2 + icon.width
            y: icon.y
            id: title
            font.bold: true
        }
        Text {
            x: icon.x*2 + icon.width
            y: title.y + title.height + icon.x
            id: message
        }


        states: [
            State {
                name: "map"
                PropertyChanges { target: this_thing; height: 50; width: 300; opacity: 0.8; x: 10; y: 10; radius:8; color: "white" }
                PropertyChanges { target: listView; y: 0 }
            },
            State {
                name: "list"
                PropertyChanges { target: this_thing; height: 50; width: target.width; opacity: 1.0; x: 0; y: 0; radius:0; color: "lightgrey" }
                PropertyChanges { target: listView; y: 25 } /* dunno why 25. */
            }
        ]

        transitions: [
            Transition {
                from: ""; to: "map"; reversible: true
                ParallelAnimation {
                    NumberAnimation { properties: "opacity"; duration: 200;  }
                    ColorAnimation { duration: 300; }
                }
            },
            Transition {
                from: ""; to: "list"; reversible: true
                ParallelAnimation {
                    NumberAnimation { properties: "opacity,y,height"; duration: 200;  }
                    ColorAnimation { duration: 300; }
                }
            },
            Transition {
                from: "map"; to: "list"; reversible: true
                ParallelAnimation {
                    NumberAnimation { properties: "opacity,x,y,width,height"; duration: 200; }
                    ColorAnimation { duration: 300; }
                }
            }
        ]
    }

    /*
    // Use this for debug only.
    Rectangle {
        y: 100
        color: "red"
        width: 60
        height: 30
        Text {
            text: "Hide"
        }
        MouseArea { anchors.fill: parent; onClicked: this_thing.state = '' }
    }
    Rectangle {
        y: 100
        x: 65
        color: "blue"
        width: 60
        height: 30
        Text {
            text: "List"
        }
        MouseArea { anchors.fill: parent; onClicked: this_thing.state = 'list' }
    }
    Rectangle {
        y: 100
        x: 135
        color: "green"
        width: 60
        height: 30
        Text {
            text: "Map"
        }
        MouseArea { anchors.fill: parent; onClicked: this_thing.state = 'map' }
    }
    */
}
