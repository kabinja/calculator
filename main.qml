import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3
import QtQuick.Window 2.0
import "qrc:/"

Window {
	id: main
	width: 300
	height: 480
	color: palette.window
	visible: true

	signal operatorClicked(string operation)

	property alias equation: expressionString.text

	Rectangle{
		id: expression
		width: parent.width
		height: 20
		color: "white"
	}

	Text { id: expressionString; anchors.centerIn: expression; color: "black" }

	SystemPalette { id: palette }

	Row {
		anchors.top: expression.bottom
		anchors.topMargin: 5
		spacing: 20

		Grid {
			id: numpad
			columns: 3
			columnSpacing: 5
			rowSpacing: 5

			signal buttonClicked(string operation)

			OperationButton { operation: "7" }
			OperationButton { operation: "8" }
			OperationButton { operation: "9" }
			OperationButton { operation: "4" }
			OperationButton { operation: "5" }
			OperationButton { operation: "6" }
			OperationButton { operation: "1" }
			OperationButton { operation: "2" }
			OperationButton { operation: "3" }
			OperationButton { operation: "0" }
			OperationButton { operation: "." }
			OperationButton { operation: "=" }
		}

		Grid {
			id: operators
			columns: 3
			columnSpacing: 5
			rowSpacing: 5

			signal buttonClicked(string operation)

			OperationButton { operation: "%" }
			OperationButton { operation: "-" }
			OperationButton { operation: "+" }
			OperationButton { operation: "root" }
			OperationButton { operation: "power" }
			OperationButton { operation: "/" }
			OperationButton { operation: "*" }
			OperationButton { operation: "(" }
			OperationButton { operation: ")" }
			OperationButton { operation: "," }
			OperationButton { operation: "AC" }
			OperationButton { operation: "C" }
		}

		Component.onCompleted: {
				numpad.buttonClicked.connect(operatorClicked)
				operators.buttonClicked.connect(operatorClicked)
		}
	}
}
