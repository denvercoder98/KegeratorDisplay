import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import se.kj.CppInterface 1.0

ColumnLayout {
    spacing: 1
    property string side
    property int tapWidth
    property int headerSize
    property int textSize
    
    property QTap tap: QTap {}
    property bool editing : tap.buttonsVisible

    Layout.minimumWidth: tapWidth
    Layout.maximumWidth: tapWidth
    Layout.fillHeight: false

    Text {
        text: qsTr(tap.sideName)
        font.pixelSize: headerSize
    }
    
    RowLayout {
        Text {
            text: qsTr(tapTags.nameTag)
            font.pixelSize: textSize
        }
    
        TextField {
            text: tap.name
            font.pixelSize: textSize
            Layout.fillWidth: true
            Layout.minimumHeight: 30
            Layout.maximumHeight: 30
            onEditingFinished: tap.name = text
            readOnly: !editing
        }
    }
    
    RowLayout {
        Text {
            text: qsTr(tapTags.brewerTag)
            font.pixelSize: textSize
        }
    
        TextField {
            text: tap.brewer
            font.pixelSize: textSize
            Layout.fillWidth: true
            Layout.minimumHeight: 30
            Layout.maximumHeight: 30
            onEditingFinished: tap.brewer = text
            readOnly: !editing
        }
    }
    
    Text {
        text: qsTr(tapTags.estVolumeTag) + tap.estVolume
        font.pixelSize: textSize
    }
    
    RowLayout {
        Text {
            text: qsTr(tapTags.abvTag)
            font.pixelSize: textSize
        }
    
        TextField {
            text: tap.abv
            font.pixelSize: textSize
            Layout.fillWidth: true
            Layout.minimumHeight: 30
            Layout.maximumHeight: 30
            onEditingFinished: tap.abv = text
            readOnly: !editing
        }
    }
    
    RowLayout {
        Text {
            text: qsTr(tapTags.ibuTag)
            font.pixelSize: textSize
        }
    
        TextField {
            text: tap.ibu
            font.pixelSize: textSize
            Layout.fillWidth: true
            Layout.minimumHeight: 30
            Layout.maximumHeight: 30
            onEditingFinished: tap.ibu = text
            readOnly: !editing
        }
    }    
    
    RowLayout {
        Text {
            text: qsTr(tapTags.brewDateTag)
            font.pixelSize: textSize
        }
    
        TextField {
            text: tap.brewDate
            font.pixelSize: textSize
            Layout.fillWidth: true
            Layout.minimumHeight: 30
            Layout.maximumHeight: 30
            onEditingFinished: tap.brewDate = text
            readOnly: !editing
        }
    }
    
    RowLayout {
        Text {
            text: qsTr(tapTags.tapDateTag)
            font.pixelSize: textSize
        }
    
        TextField {
            text: tap.tapDate
            font.pixelSize: textSize
            Layout.fillWidth: true
            Layout.minimumHeight: 30
            Layout.maximumHeight: 30
            onEditingFinished: tap.tapDate = text
            readOnly: !editing
        }
    }
    
    RowLayout {
        Text {
            text: qsTr(tapTags.finalGravityTag)
            font.pixelSize: textSize
        }
    
        TextField {
            text: tap.finalGravity
            font.pixelSize: textSize
            Layout.fillWidth: true
            Layout.minimumHeight: 30
            Layout.maximumHeight: 30
            onEditingFinished: tap.finalGravity = text
            readOnly: !editing
        }
    }    
    
    RowLayout {
        Button {
            text: qsTr(tapTags.saveButtonTag)
            font.pixelSize: textSize

            onClicked: {
                buttonHandler.saveTap(tap.side)
            }
            visible: tap.buttonsVisible
        }
        
        Button {
            text: qsTr(tapTags.clearButtonTag)
            font.pixelSize: textSize

            onClicked: {
                buttonHandler.clearTap(tap.side)
            }
            visible: tap.buttonsVisible
        }
    }

}
