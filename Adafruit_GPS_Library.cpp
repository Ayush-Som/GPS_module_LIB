#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 7); // RX, TX

Adafruit_GPS GPS(&mySerial);

void setup() {
  Serial.begin(9600);
  GPS.begin(9600);

  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand(PGCMD_ANTENNA);

  delay(1000);
}

void loop() {
  GPS.read();

  if (GPS.newNMEAreceived()) {
    if (!GPS.parse(GPS.lastNMEA())) {
      return;
    }
  }

  if (GPS.fix) {
    float latitude = GPS.latitudeDegrees;
    float longitude = GPS.longitudeDegrees;
    float speed = GPS.speed;
    float distance = GPS.distanceBetween(latitude, longitude, targetLatitude, targetLongitude);

    Serial.print("Latitude: ");
    Serial.println(latitude, 6);
    Serial.print("Longitude: ");
    Serial.println(longitude, 6);
    Serial.print("Speed (m/s): ");
    Serial.println(speed);
    Serial.print("Distance (m): ");
    Serial.println(distance);
  }
}
