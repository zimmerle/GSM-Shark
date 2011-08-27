import Qt 4.7
import QtWebKit 1.0
import QtMobility.location 1.2
import QtQuick 1.0
import QtDesktop 0.1

Rectangle {
    property variant target: null;
    property real value: 0;

    color: "transparent"


    Flipable {
        id: flipable
        width: parent.width
        height: parent.height
        property bool flipped: false

        front: Rectangle {
            width: parent.width
            height: parent.height
            color: "transparent"
            Rectangle {
                color: "white"
                radius: 8
                opacity: 0.3
                width: parent.width
                height: parent.height
                id: background
            }


            Rectangle {
                anchors.centerIn: parent
                width: parent.width
                height: parent.height

                color: "transparent"
                Slider {
                    id: zoomSlider
                    x: 4
                    stepSize: 0.1
                    opacity: 1
                    width: parent.width-10-infoImage.width
                    height: parent.height-6
                    maximumValue: target.maximumZoomLevel
                    minimumValue: target.minimumZoomLevel+1.5

                    onValueChanged: {
                        target.zoomLevel = value;
                    }
                }

                Image {
                    id: infoImage
                    source: "qrc:/res/info.png"
                    smooth: true
                    height: parent.height-10
                    y: (parent.height-height)/2
                    x: parent.width-width-y+(parent.x/2)
                    fillMode: Image.PreserveAspectFit
                    opacity: 0.6
                }

                MouseArea {
                    anchors.fill: infoImage
                    hoverEnabled: true
                    onEntered: {
                        internalRect.state = "hover";
                    }
                    onExited: {
                        internalRect.state = "";
                    }

                    onClicked: flipable.flipped = !flipable.flipped
                }


                id: internalRect

                states: [
                    State {
                        name: "hover"
                        PropertyChanges { target: background; opacity: 0.8 }
                        PropertyChanges { target: infoImage; opacity: 1 }
                    }
                ]

                transitions: [
                    Transition {
                        from: ""; to: "hover"; reversible: true
                        NumberAnimation { properties: "opacity"; duration: 200; }
                    }
                ]

            }
        }
        back: Rectangle {

            width: parent.width
            height: parent.height

            color: "white"
	    radius: 8

            Text {
                text: "Not ready yet!"
                anchors.centerIn: parent
            }

            MouseArea {
                anchors.fill: parent
                onClicked: flipable.flipped = !flipable.flipped
            }
        }


        transform: Rotation {
            id: rotation
            origin.x: flipable.width/2
            origin.y: flipable.height/2
            axis.x: 1; axis.y: 0; axis.z: 0     // set axis.y to 1 to rotate around y-axis
            angle: 0    // the default angle
        }

        states: State {
            name: "back"
            PropertyChanges { target: rotation; angle: 180 }
            when: flipable.flipped
        }

        transitions: Transition {
            NumberAnimation { target: rotation; property: "angle"; duration: 300 }
        }
    }


    onValueChanged: {
        zoomSlider.value = value;
    }
    function fadeToValue (value)
    {
        log.console("Not implemented yet.")
        zoomSlider.value = value;
    }

}
