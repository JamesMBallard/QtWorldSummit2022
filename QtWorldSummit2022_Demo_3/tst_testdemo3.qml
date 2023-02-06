import QtQuick
import QtTest
import Esri.ArcGISRuntime

TestCase {
    name: "testdemo3"
    property var create: ArcGISRuntimeEnvironment.createObject

    function test_data_driven_test_data() {
        return [
            {tag: "empty map", map: create("Map")},
            {tag: "map with basemap", map: create("Map",{basemap: create("Basemap")})},
            {tag: "map with url", map: create("Map",{initUrl: "https://arcgis.com/web_map_id"})},
            {tag: "map with background color", map: create("Map",{backgroundColor: "red"})}
        ]
    }

    function test_data_driven_test(data) {
        compare(data.map.maxScale, 0);
    }
}
