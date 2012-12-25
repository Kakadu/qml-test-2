import QtQuick 2.0

Rectangle {
    width: 800
    height: 360

    ListView {
        model: mainModel
        spacing: 5
        anchors.fill: parent
        orientation: ListView.Vertical
        delegate: Text {
            text: "pizda"

            Component.onCompleted: {
                console.log(mainModel.roles() );
                console.log(model.homm);
                console.log(homm);
            }
        }

        /*
        delegate: ListView {
            model: homm
            height: 30

            orientation: ListView.Horizontal
            delegate: Text {
                //text: name + " " + sort
                text: "asfd"//model.name + " " + model.sort
                width: 50
                height: 30

                Component.onCompleted: console.log("Text created")
            }
            Component.onCompleted: {
                console.log("Inner ListView created");
                //console.log(homm);
                //console.log(homm.itemsCount());
            }
        }
        */
    }
}
