import QtQuick 2.0

Rectangle {
    anchors.fill: parent
    color: "black"

    property int colorDelay: 3000

    Rectangle {
        id:topleft
        width: parent.width/2.2
        height: parent.height/2.2
        x: 0
        y: 0

        SequentialAnimation on color {
            running: true;
            loops: Animation.Infinite;
            PropertyAnimation { from: "red"; to: "yellow"; duration: colorDelay }
            PropertyAnimation { from: "yellow"; to: "green"; duration: colorDelay }
            PropertyAnimation { from: "green"; to: "blue"; duration: colorDelay }
            PropertyAnimation { from: "blue"; to: "red"; duration: colorDelay }
        }

    }

    Rectangle {
        id:topright
        width: parent.width/2.2
        height: parent.height/2.2
        x: parent.width/2
        y: 0

        SequentialAnimation on color {
            running: true;
            loops: Animation.Infinite;

            PropertyAnimation { from: "blue"; to: "red"; duration: colorDelay }
            PropertyAnimation { from: "red"; to: "yellow"; duration: colorDelay }
            PropertyAnimation { from: "yellow"; to: "green"; duration: colorDelay }
            PropertyAnimation { from: "green"; to: "blue"; duration: colorDelay }
        }
    }

    Rectangle {
        id:bottomleft
        width: parent.width/2.2
        height: parent.height/2.2
        x: 0
        y: parent.height/2
        color: "green"

        SequentialAnimation on color {
            running: true;
            loops: Animation.Infinite;

            PropertyAnimation { from: "green"; to: "blue"; duration: colorDelay }
            PropertyAnimation { from: "blue"; to: "red"; duration: colorDelay }
            PropertyAnimation { from: "red"; to: "yellow"; duration: colorDelay }
            PropertyAnimation { from: "yellow"; to: "green"; duration: colorDelay }
        }
    }

    Rectangle {
        id:bottomright
        width: parent.width/2.2
        height: parent.height/2.2
        x: parent.width/2
        y: parent.height/2
        color: "blue"

        SequentialAnimation on color {
            running: true;
            loops: Animation.Infinite;

            PropertyAnimation { from: "yellow"; to: "green"; duration: colorDelay }
            PropertyAnimation { from: "green"; to: "blue"; duration: colorDelay }
            PropertyAnimation { from: "blue"; to: "red"; duration: colorDelay }
            PropertyAnimation { from: "red"; to: "yellow"; duration: colorDelay }
        }
    }

}
