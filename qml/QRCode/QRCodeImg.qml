import QtQuick 2.0

Rectangle {
    width: 300
    height: 300
    color: "lightblue"
    Image{
        id: qrimg
        anchors.fill: parent


            objectName: "QRFrame"

            function updateQRFrame(src)
            {
                qrimg.source = src
                //console.log("In QML already: " + src)
            }//slot
    }
}
