import QtQuick 2.0

Rectangle {
    property int colorDelay: 3000
    property int rotationDur: 400
    property int movementDur: 10000
    width: 100
    height: 100
    color: "white"
    y: 100

    PropertyAnimation on rotation{
        running:true
        loops:Animation.Infinite
        from:0
        to:360
        duration:rotationDur
    }

    PropertyAnimation on x{
        running:true
        loops:Animation.Infinite
        from:-110
        to:2050
        duration:movementDur
    }

    SequentialAnimation on color {
        running: true;
        loops: Animation.Infinite;

        PropertyAnimation { from: "green"; to: "blue"; duration: colorDelay }
        PropertyAnimation { from: "blue"; to: "red"; duration: colorDelay }
        PropertyAnimation { from: "red"; to: "yellow"; duration: colorDelay }
        PropertyAnimation { from: "yellow"; to: "green"; duration: colorDelay }
    }
}
