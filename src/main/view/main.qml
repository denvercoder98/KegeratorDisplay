import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Window 2.0

ApplicationWindow
{
    visible: true
    width: 800
    height: 480
    maximumWidth: 800
    maximumHeight: 480
    minimumWidth: 800
    minimumHeight: 480
    title: qsTr("Kegerator Display")
    flags: Qt.FramelessWindowHint
    
    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
}