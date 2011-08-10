import Qt 4.7
import QtWebKit 1.0
import QtMobility.location 1.2
import QtQuick 1.0
import QtDesktop 0.1

Rectangle {
    property variant target: null;

    Slider {
        stepSize: 0.1
        opacity: 1
        width: 200
        height: 20

        maximumValue: target.maximumZoomLevel
        minimumValue: target.minimumZoomLevel+1.5

        onValueChanged: {
            target.zoomLevel = value;
        }

        function setValue (value) {
            var diff = zoom.value - value;
            if (diff < 0)
                diff = diff * -1;

            diff = diff*200;

            if (diff < 200)
                diff = 200;

            zoom_duration = diff*2;
            zoom_internal = value;
            zoomFade.start();
        }
    }
}
