import QtQuick 2.0

Rectangle {
    id: root
    width: 600
    height: 600
    color: "lightgrey"
    ListView {
        model: mainModel
        spacing: 5

        width: parent.width
        orientation: ListView.Horizontal

        delegate: Rectangle {
            //width: parent.desiredWidth / mainModel.dataLen()
            //width: root.width / mainModel.dataLen() - 10
            width: 200

            //Component.onCompleted: console.log(width)
            ListView {
                id: lv1/*
                ScrollBar {
                    flickable: lv1
                    vertical: true
                    hideScrollBarsWhenStopped: false
                    scrollbarWidth: 5
                }*/

                model: homm
                spacing: 5
                width: parent.width
                height: 150
                orientation: ListView.Vertical
                delegate:
                    Rectangle {
                        radius: 5
                        anchors.rightMargin: 5
                        anchors.leftMargin: 5
                        width: lv1.width
                        height: 20
                        color: "black"
                        Text { text: model.name //+ " " + model.sort
                            anchors.fill: parent
                            color: "white"
                        }
                }
            }
        }

    }
}
