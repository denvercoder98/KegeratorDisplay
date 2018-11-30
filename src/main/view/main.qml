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
    title: qsTr("Kegerator Status")
    flags: Qt.FramelessWindowHint
    
    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
    
    ColumnLayout {
        anchors.centerIn: parent
    
        id: mainColumn
        property int titleSize: 40
        property int headerSize: 30
        property int textSize: 20
        spacing: 20      

        Text {
            text: qsTr("Kegerator Status");
            font.pixelSize: mainColumn.titleSize;
        }
    
        ColumnLayout {
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
        
            ColumnLayout {
                id: left
                property bool edit

                Text {
                    text: qsTr("Left tap");
                    font.pixelSize: mainColumn.headerSize;
                }
                TextInput {
                    text: qsTr("Name: ") + leftTap.name;
                    font.pixelSize: mainColumn.textSize;
                    readOnly: !left.edit
                }
                Text {
                    text: qsTr("Est. volum: ") + leftTap.estVolume;
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
                    Button {
                        text: qsTr("Edit");
                        font.pixelSize: mainColumn.textSize;
                        
                        onClicked: {
                            console.log("Edit left");
                            left.edit = true
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
                Text {
                    text: qsTr("Right tap");
                    font.pixelSize: mainColumn.headerSize;
                }
                Text {
                    text: qsTr("Name: ") + rightTap.name;
                    font.pixelSize: mainColumn.textSize;
                }
                Text {
                    text: qsTr("Est. volum: ") + rightTap.estVolume;
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
                    Button {
                        text: qsTr("Edit");
                        font.pixelSize: mainColumn.textSize;
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