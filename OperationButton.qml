import QtQuick 2.3



Rectangle {
	 property alias operation: label.text
	 property bool toggable: false
	 property bool toggled: false

	id: button
	width: 40
	height: 30
	color: "black"

	 MouseArea {
		 anchors.fill: parent
		 onClicked: button.parent.buttonClicked(button.operation)
	 }

	 Text { id: label; anchors.centerIn: parent; color: "white" }
}
