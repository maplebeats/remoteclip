import QtQuick 2.5
import QtQuick.Layouts 1.2

Rectangle {
    id: rect_main

    width: 360
    height: 360

    Column {
        id: col_all
        x: 0
        y: 50
        width: 250
        height: 150

        TextEdit {
            id: edit_guid
            x: 25
            y: 20
            width: 200
            height: 20
            text: qsTr("Text Edit")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }


        Text {
            id: button_quit
            text: "退出"
            anchors.right: parent.right
            anchors.rightMargin: 10
            antialiasing: false
            transformOrigin: Item.Center
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
        }

        Text {
            id: button_register
            text: "注册"
            anchors.left: parent.left
            anchors.leftMargin: 10
        }

        MouseArea {
            id: area_quit
            width: 100
            height: 100
        }

        MouseArea {
            id: area_register
            width: 100
            height: 100
        }



    }

}

