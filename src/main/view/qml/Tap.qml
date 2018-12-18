import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import se.kj.CppInterface 1.0

ColumnLayout {
    spacing: 1
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
    
    TapDataRow {
        tag: nameTag
        value: name
        textSize: textSize
        edit: buttonsVisible
    }

    Text {
        text: qsTr(estVolumeTag) + estVolume
        font.pixelSize: textSize
    }
    
    TapDataRow {
        tag: brewerTag
        value: brewer
        textSize: parent.textSize
        edit: buttonsVisible
    }
    
    TapDataRow {
        tag: brewDateTag
        value: brewDate
        textSize: parent.textSize
        edit: buttonsVisible
    }
    
    TapDataRow {
        tag: tapDateTag
        value: tapDate
        textSize: parent.textSize
        edit: buttonsVisible
    }
    
    TapDataRow {
        tag: abvTag
        value: abv
        textSize: parent.textSize
        edit: buttonsVisible
    }
    
    TapDataRow {
        tag: ibuTag
        value: ibu
        textSize: parent.textSize
        edit: buttonsVisible
    }
    
    TapDataRow {
        tag: finalGravityTag
        value: finalGravity
        textSize: parent.textSize
        edit: buttonsVisible
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
