import Qt 4.7
import QtWebKit 1.0
import QtMobility.location 1.2
import QtQuick 1.0
import QtDesktop 0.1

Rectangle {

    MapsZoom {
        id: zoomContainer
        width: 200
        height: 20
        opacity: 1
        color: "transparent"

        z: 2
        x: mainWindow.width - 20 - width
        y: mainWindow.height - 10 - height

        target: mapsView
    }

    Map {
        id: mapsView
        z: 1

        signal changeZoom(int newLevel)

        plugin : Plugin {
            name : "nokia"
        }

        size.width: parent.width
        size.height: parent.height

        zoomLevel: 1.5
        center: Coordinate {
            latitude: 0
            longitude: 0
        }
        opacity: 1
        onOpacityChanged: {
            startupFade2.start()
        }

        mapType: Map.SatelliteMapDay

        MapMouseArea {
            property int lastX : -1
            property int lastY : -1

            onPressed : {
                lastX = mouse.x
                lastY = mouse.y
            }
            onReleased : {
                lastX = -1
                lastY = -1
            }
            onPositionChanged: {
                if (mouse.button == Qt.LeftButton) {
                    if ((lastX != -1) && (lastY != -1)) {
                        var dx = mouse.x - lastX
                        var dy = mouse.y - lastY
                        mapsView.pan(-dx, -dy)
                    }
                    lastX = mouse.x
                    lastY = mouse.y
                }
            }

        }

    }
}
/*



        PropertyAnimation {
            id: fadeA
            target: mapContainer;
            property: "opacity";
            to: mainViewOpacity;
        }

        MapCircle {
            id : circle
            center : Coordinate {
                latitude : 51.5
                longitude : -0.11
            }
            color : "#80FF0000"
            radius : 1000.0
            MapMouseArea {
                onPositionChanged: {
                    if (mouse.button == Qt.LeftButton)
                        circle.center = mouse.coordinate
                    if (mouse.button == Qt.RightButton)
                        circle.radius = circle.center.distanceTo(mouse.coordinate)
                }
            }
        }

            //onDoubleClicked: {
            //    mapView.center = mouse.coordinate
            //    mapView.zoomLevel += 1
            //    lastX = -1
            //    lastY = -1
            //}

Keys.onPressed: {
    if (event.key == Qt.Key_Plus) {
        mapView.zoomLevel += 1
    } else if (event.key == Qt.Key_Minus) {
        mapView.zoomLevel -= 1
    } else if (event.key == Qt.Key_T) {
        if (mapView.mapType == Map.StreetMap) {
            mapView.mapType = Map.SatelliteMapDay
        } else if (map.mapType == Map.SatelliteMapDay) {
            mapView.mapType = Map.StreetMap
        }
    }
}
*/

/*
WebView {
    id: mapView

    x: 0
    y: 0
    width: parent.width
    height: parent.height

    url: 'http://www.zimmerle.org/cgi-bin/x.pl'
    pressGrabTime: 0
    opacity: 0
    settings.javascriptEnabled: true

    PropertyAnimation {
        id: startupFade
        target: mapView;
        property: "opacity";
        to: 1;
        duration: 500;
    }
    PropertyAnimation {
        id: fadeA
        target: mapView;
        property: "opacity";
        to: mainViewOpacity;
    }
    onLoadFinished: {
        console.log("Loaded.");
        startupFade.running = true;
    }
}
*/
