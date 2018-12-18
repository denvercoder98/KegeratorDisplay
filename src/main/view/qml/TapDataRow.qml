import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import se.kj.CppInterface 1.0

RowLayout {
    property string tag
    property int textSize
    property string value
    property bool edit
           
    Text {
        text: qsTr(tag)
        font.pixelSize: textSize
    }
    
    TextField {
        text: value
        font.pixelSize: textSize
        readOnly: !edit
        Layout.fillWidth: true
        Layout.minimumHeight: 30
        Layout.maximumHeight: 30
    }
}