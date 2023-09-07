#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial ss(8, 7); // RX, TX
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
}

void loop() {
  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();
      float speed = gps.speed.mps();
      float distance = gps.distanceBetween(latitude, longitude, targetLatitude, targetLongitude);

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
}
