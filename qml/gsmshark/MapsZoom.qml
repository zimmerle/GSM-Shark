import Qt 4.7
import QtWebKit 1.0
import QtMobility.location 1.2
import QtQuick 1.0
import QtDesktop 0.1

Rectangle {
    property variant target: null;
    property real value: 0;

    Slider {
	id: zoomSlider
        stepSize: 0.1
        opacity: 1
        width: parent.width
        height: parent.height

        maximumValue: target.maximumZoomLevel
        minimumValue: target.minimumZoomLevel+1.5

        onValueChanged: {
            target.zoomLevel = value;
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

