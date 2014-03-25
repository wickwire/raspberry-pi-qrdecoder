import QtQuick 2.0
import QZXing 1.2

Item {

    anchors.fill: parent

    property string qrcodePath_poc: "resources/qrfree.kaywa.com.jpg"
    property string qrcodePath: "resources/moved.jpeg"
    property string qrcoderesult
    property bool zxingRes

    QZXing{

            id: decoder
            onDecodingStarted: console.log("Decoding of image started...")
            onTagFound: console.log("Barcode data: " + tag)
            onDecodingFinished: { zxingRes = succeeded ; console.log("Decoding finished " + (succeeded==true ? "successfully" : "unsuccessfully") ) }
    }

}
