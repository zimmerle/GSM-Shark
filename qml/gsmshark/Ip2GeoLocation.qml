import QtQuick 1.0

Item {
    property bool ready: false
    property real latitude: 0
    property real longitude: 0

    XmlListModel {
        source: "http://freegeoip.net/xml/"
        query: "/Response"
        XmlRole { name: "Latitude"; query: "Latitude/number()" }
        XmlRole { name: "Longitude"; query: "Longitude/number()" }
        XmlRole { name: "CountryName"; query: "CountryName/string()" }
        XmlRole { name: "Ip"; query: "Ip/string()" }

        onStatusChanged: {
            if (status == XmlListModel.Ready)
            {
                latitude = get(0).Latitude;
                longitude = get(0).Longitude;
                console.debug("FreeGeoIpThing :: Found latitude and longitude of the user based on the ip address: " +
                              latitude + ", " + longitude);

                ready = true
            }

            if (status == XmlListModel.Loading)
            {
                console.debug("FreeGeoIpThing :: Loading XML form freegeoip.net with the user geolocation.")
            }

            if (status == XmlListModel.Error)
            {
                console.debug("FreeGeoIpThing :: Error trying to fetch the user's geolocation.")
            }
        }
    }
}
