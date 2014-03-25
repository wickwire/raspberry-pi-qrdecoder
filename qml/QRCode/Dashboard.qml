import QtQuick 2.0



Rectangle {

    property string src
    anchors.fill: parent
    color: "black"




    Waver{
        id: wave
    }

    Rectangle {
        width: 1000
        height: 300
        anchors.centerIn: parent
        color: "black"
        Text {
            text: "QRCode String"
            anchors.centerIn: parent
            color: "white"
        font.family: "Verdana"
        font.pixelSize: 200
        }
    }

    Rectangle {
        width: 1100
        height: 100
        color: "black"
        y: parent.height - 200
        x: parent.width/2 - width/2
        Text {
            id: message
            anchors.centerIn: parent
            color: "white"
            font.family: "Verdana"
            font.pixelSize: 40

            objectName: "TextBox"

            function updateTextBox(src)
            {
                message.text = src
                //console.log("In QML already: " + src)
            }//slot


        }
    }

    Satellite{
        id: sat
        movementDur: 7000
    }

    Satellite{
        id: sat2
        y: 250
        rotationDur: 1500
    }

    QRCodeImg{
        id: qrcodePic
        x: cameraUI.width-width*1.5
        y: cameraUI.height-height*1.8
    }
}
