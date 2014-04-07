import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"

ApplicationWindow
{
    initialPage: Component { Main { id: mainPage } }
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
}


