import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

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
    
    title: qsTr("Kegerator Status")
    flags: Qt.FramelessWindowHint
    
    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
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
    
        id: mainColumn
        property int titleSize: 40
        property int headerSize: 30
        property int textSize: 20
        spacing: 20      

        Text {
            id: headline
            text: qsTr("Kegerator Status");
            font.pixelSize: mainColumn.titleSize;
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
                text: qsTr("Temperature: ") + temperature.temperature + " " + temperature.unit;
                font.pixelSize: mainColumn.textSize
            }
        
            Text {
                text: qsTr("Pressure: ") + pressure.pressure + " " + pressure.unit;
                font.pixelSize: mainColumn.textSize
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
        
            ColumnLayout {
                id: left
                property bool edit
                
                Layout.minimumWidth: main.tapWidth
                Layout.maximumWidth: main.tapWidth
                Layout.fillHeight: false

                Text {
                    text: qsTr("Left tap");
                    font.pixelSize: mainColumn.headerSize;
                }
                TextInput {
                    text: qsTr("Name: ") + leftTap.name;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Est. volume: ") + leftTap.estVolume;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Brewer: ") + leftTap.brewer;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("ABV: ") + leftTap.abv;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("IBU: ") + leftTap.ibu;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Brew date: ") + leftTap.brewDate;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Tap date: ") + leftTap.tapDate;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Final gravity: ") + leftTap.finalGravity;
                    font.pixelSize: mainColumn.textSize;
                }
                RowLayout {
                    visible: leftTap.buttonsVisible
                    Button {
                        text: qsTr("Edit");
                        font.pixelSize: mainColumn.textSize;
                        
                        onClicked: {
                            buttonHandler.editTap("left")
                        }
                    }
                    Button {
                        text: qsTr("Clear");
                        font.pixelSize: mainColumn.textSize;
                        
                        onClicked: {
                            buttonHandler.clearTap("left")
                        }
                    }
                }
            }
        
            ColumnLayout {
                            
                Layout.minimumWidth: main.tapWidth
                Layout.maximumWidth: main.tapWidth
                
                Text {
                    text: qsTr("Right tap");
                    font.pixelSize: mainColumn.headerSize;
                }
                Text {
                    text: qsTr("Name: ") + rightTap.name;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Est. volume: ") + rightTap.estVolume;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Brewer: ") + rightTap.brewer;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("ABV: ") + rightTap.abv;
                    font.pixelSize: mainColumn.textSize;
                }                
                Text {
                    text: qsTr("IBU: ") + rightTap.ibu;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Brew date: ") + rightTap.brewDate;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Tap date: ") + rightTap.tapDate;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Final gravity: ") + rightTap.finalGravity;
                    font.pixelSize: mainColumn.textSize;
                }
                RowLayout {
                    visible: rightTap.buttonsVisible
                    Button {
                        text: qsTr("Edit");
                        font.pixelSize: mainColumn.textSize;
                        onClicked: {
                            buttonHandler.editTap("right")
                        }
                    }
                    Button {
                        text: qsTr("Clear");
                        font.pixelSize: mainColumn.textSize;
                        onClicked: {
                            buttonHandler.clearTap("right")
                        }
                    }
                }         
            }
        }
    }
}