import QtQuick 1.0
import QtWebKit 1.0

Rectangle {
    WebView {
        url: 'http://www.google.com'
        settings.javascriptEnabled: true

        onLoadFinished: console.log("Loaded!");
        width: parent.width
        height: parent.height
        x: parent.x
        y: parent.y

    }
    x: 0
    y: 0
    z: 2
    width: parent.width
    height: parent.height
}
