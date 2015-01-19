- QR Code Qt5 App
	- requirements:
	- usb webcam
	- IR sensor

- How does it work:
	- the app checks the IR sensor state every second
	- if the sensor state changes, the app performs the following actions:
	- a snapshot is taken with the webcam
	- the snapshot is analyzed for any QR Code
	- if a QR Code is found and successfully decoded:
	- the decoded string is passed on to the QML presentation layer and the text box is updated
	- the snapshot image is passed on to the QML presentation layer and the image frame is updated

- TO DO:

- incorporate a white LED to simulate the camera flash effect
- drop the "streamer" dependency - use GSTreamer with usb webcam support and Qt5 integration
- incorporate an NFC shield
- port the solution to other embedded devices > cubieboard family


#EOF#
