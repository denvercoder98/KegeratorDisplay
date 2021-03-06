import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import se.kj.CppInterface 1.0

ApplicationWindow
{
    id: main
    visible: true
    
    width: 800
    height: 480
    maximumWidth: 800
    maximumHeight: 480
    minimumWidth: 800
    minimumHeight: 480
    
    property int tapWidth: 300
    property int topMargin: 10
    property bool debug: true
    property int titleSize: 30
    property int headerSize: 25
    property int textSize: 14
    
    title: qsTr(kegerator.heading)
    flags: Qt.FramelessWindowHint
    
    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2)
        setY(Screen.height / 2 - height / 2)
    }
    
    MouseArea {
        width: parent.width
        height: parent.height
        onClicked: {
            buttonHandler.screenTouched()
        }
    }
    
    ColumnLayout {
        anchors.top: parent.top
        anchors.topMargin: main.topMargin
        anchors.horizontalCenter: parent.horizontalCenter
    
        spacing: 20      

        Text {
            id: headline
            text: qsTr(kegerator.heading)
            font.pixelSize: main.titleSize
        }
    
        ColumnLayout {

            id: generalInformation            
            anchors.top: headline.bottom
            anchors.topMargin: main.topMargin
            
            Rectangle {
                width: parent.width
                height: parent.height
                border.color: "blue"
                border.width: 1
                visible: main.debug
            }
            
            Text {
                text: qsTr(temperature.tag + temperature.temperature + temperature.unit)
                font.pixelSize: main.textSize
            }
        
            Text {
                text: qsTr(pressure.tag + pressure.pressure + pressure.unit)
                font.pixelSize: main.textSize
            }
        }
        
        RowLayout {
            id: tapInformation
            anchors.top: generalInformation.bottom
            anchors.topMargin: main.topMargin
            
            Rectangle {
                width: parent.width
                height: parent.height
                border.color: "red"
                border.width: 1
                visible: main.debug
            }
            
            Tap {
                tap: leftTap
                headerSize: main.headerSize
                tapWidth: main.tapWidth
                textSize: main.textSize
            }
            
            Tap {
                tap: rightTap
                headerSize: main.headerSize
                tapWidth: main.tapWidth
                textSize: main.textSize                
            }
        }
    
    }

}
