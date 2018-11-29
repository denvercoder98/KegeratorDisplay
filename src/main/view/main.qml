import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow
{
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
    
        id: stuff
        property int titleSize: 40
        property int headerSize: 30
        property int textSize: 20
        spacing: 20      

        Text {
            text: qsTr("Kegerator Status");
            font.pixelSize: stuff.titleSize;
        }
    
        ColumnLayout {
            Text {
                text: qsTr("Temperature: ") + temperature.temperature + " " + temperature.unit;
                font.pixelSize: stuff.textSize
            }
        
            Text {
                text: qsTr("Pressure: ") + pressure.pressure + " " + pressure.unit;
                font.pixelSize: stuff.textSize
            }
        }
        
        RowLayout {
        
            ColumnLayout {
                Text {
                    text: qsTr("Left tap");
                    font.pixelSize: stuff.headerSize;
                }
                Text {
                    text: qsTr("Name: ") + leftTap.name;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Brewer: ") + leftTap.brewer;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("ABV: ") + leftTap.abv;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("IBU: ") + leftTap.ibu;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Brew date: ") + leftTap.brewDate;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Tap date: ") + leftTap.tapDate;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Final gravity: ") + leftTap.finalGravity;
                    font.pixelSize: stuff.textSize;
                }
                RowLayout {
                    Button {
                        text: qsTr("Edit");
                        font.pixelSize: stuff.textSize;
                    }
                    Button {
                        text: qsTr("Clear");
                        font.pixelSize: stuff.textSize;
                    }
                }
            }
        
            ColumnLayout {
                Text {
                    text: qsTr("Right tap");
                    font.pixelSize: stuff.headerSize;
                }
                Text {
                    text: qsTr("Name: ") + rightTap.name;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Brewer: ") + rightTap.brewer;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("ABV: ") + rightTap.abv;
                    font.pixelSize: stuff.textSize;
                }                
                Text {
                    text: qsTr("IBU: ") + rightTap.ibu;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Brew date: ") + rightTap.brewDate;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Tap date: ") + rightTap.tapDate;
                    font.pixelSize: stuff.textSize;
                }
                Text {
                    text: qsTr("Final gravity: ") + leftTap.finalGravity;
                    font.pixelSize: stuff.textSize;
                }
                RowLayout {
                    Button {
                        text: qsTr("Edit");
                        font.pixelSize: stuff.textSize;
                    }
                    Button {
                        text: qsTr("Clear");
                        font.pixelSize: stuff.textSize;
                    }
                }         
            }
        }
    }
}