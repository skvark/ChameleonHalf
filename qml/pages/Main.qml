
import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
    id: mainPage
    SilicaFlickable
    {
        anchors.fill: parent
        contentHeight: column.height

        Column
        {
            id: column

            width: mainPage.width
            spacing: Theme.paddingLarge
            PageHeader
            {
                title: "Chameleon Half"
            }

            Button {
               anchors.horizontalCenter: parent.horizontalCenter
               text: "Start Chameleon"
               onClicked: {
                   controller.setChameleonMode(true)
               }
            }

            Button {
               anchors.horizontalCenter: parent.horizontalCenter
               text: "Stop Chameleon"
               onClicked: {
                   controller.setChameleonMode(false)
               }
            }

            Rectangle {
                id: bg
                width: parent.width
                height: 80
                Label {
                    id: colorlabel
                    height: 40
                    text: "TESTCOLOR"
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Label {
                width: parent.width
                text: "Choose color"
                horizontalAlignment: Text.AlignHCenter
            }

            ColorPicker {

                width: 540
                colors: [
                    "#0000FF","#FF0000","#F0F8FF","#FAEBD7","#00FFFF","#7FFFD4","#F0FFFF","#F5F5DC","#FFE4C4","#000000",
                    "#FFEBCD","#8A2BE2","#A52A2A","#DEB887","#5F9EA0","#7FFF00","#D2691E","#FF7F50","#6495ED","#FFF8DC",
                    "#DC143C","#00FFFF","#00008B","#008B8B","#B8860B","#A9A9A9","#006400","#BDB76B","#8B008B","#556B2F",
                    "#FF8C00","#9932CC","#8B0000","#E9967A","#8FBC8F","#483D8B","#2F4F4F","#00CED1","#9400D3","#FF1493",
                    "#00BFFF","#696969","#1E90FF","#B22222","#FFFAF0","#228B22","#FF00FF","#DCDCDC","#E0E0E0","#FFD700",
                    "#DAA520","#808080","#008000","#ADFF2F","#CC5500","#FF69B4","#CD5C5C","#4B0082","#FFFFF0","#F0E68C",
                    "#E6E6FA","#FFF0F5","#7CFC00","#FFFACD","#ADD8E6","#F08080","#E0FFFF","#FAFAD2","#D3D3D3","#90EE90",
                    "#FFB6C1","#FFA07A","#20B2AA","#87CEFA","#778899","#B0C4DE","#FFFFE0","#00FF00","#32CD32","#FAF0E6",
                    "#FF00FF","#800000","#66CDAA","#0000CD","#BA55D3","#9370D8","#3CB371","#7B68EE","#00FA9A","#48D1CC",
                    "#C71585","#191970","#F5FFFA","#FFE4E1","#FFE4B5","#FFDEAD","#000080","#FDF5E6","#808000","#6B8E23",
                    "#FFA500","#FF4500","#DA70D6","#EEE8AA","#98FB98","#AFEEEE","#D87093","#FFEFD5","#FFDAB9","#CD853F",
                    "#FFC0CB","#DDA0DD","#B0E0E6","#800080","#BC8F8F","#4169E1","#8B4513","#FA8072","#F4A460","#2E8B57",
                    "#FFF5EE","#A0522D","#C0C0C0","#87CEEB","#6A5ACD","#708090","#FFFAFA","#00FF7F","#4682B4","#D2B48C",
                    "#008080","#D8BFD8","#FF6347","#40E0D0","#EE82EE","#F5DEB3","#A86363","#F5F5F5","#FFFF00","#9ACD32",
                    ]
                onColorChanged: {
                    controller.setColor(color)
                }
            }

        }
    }
    Connections {
        target: controller
        onColorDetected: {
            bg.color = newcolor;
        }
    }
}


