import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import "qrc:/qml"
import se.kj.CppInterface 1.0

ColumnLayout {
    property string side
    property bool edit
    property int tapWidth
    property int headerSize
    property int textSize
    
    property string name
    property string nameTag
    property string brewer
    property string brewerTag
    property string estVolume
    property string estVolumeTag
    property string abv
    property string abvTag
    property string ibu
    property string ibuTag
    property string brewDate
    property string brewDateTag
    property string tapDate
    property string tapDateTag
    property string finalGravity
    property string finalGravityTag
    property string clearButtonTag
    property bool buttonsVisible

    Layout.minimumWidth: tapWidth
    Layout.maximumWidth: tapWidth
    Layout.fillHeight: false
         
    Text {
        text: qsTr(side)
        font.pixelSize: headerSize
    }

    RowLayout {
        Text {
            text: qsTr(nameTag)
            font.pixelSize: textSize
        }
        TextInput {
            text: name
            font.pixelSize: textSize
            readOnly: !buttonsVisible
        }
    }
    Text {
        text: qsTr(estVolumeTag) + estVolume
        font.pixelSize: textSize
    }
    Text {
        text: qsTr(brewerTag) + brewer
        font.pixelSize: textSize
    }
    Text {
        text: qsTr(abvTag) + abv
        font.pixelSize: textSize
    }
    Text {
        text: qsTr(ibuTag) + ibu
        font.pixelSize: textSize
    }
    Text {
        text: qsTr(brewDateTag) + brewDate
        font.pixelSize: textSize
    }
    Text {
        text: qsTr(tapDateTag) + tapDate
        font.pixelSize: textSize
    }
    Text {
        text: qsTr(finalGravityTag) + finalGravity
        font.pixelSize: textSize
    }
    Button {
        text: qsTr(clearButtonTag)
        font.pixelSize: textSize

        onClicked: {
            buttonHandler.clearTap(side)
        }
        visible: buttonsVisible
    }

}
