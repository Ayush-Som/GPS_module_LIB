#include <NMEAGPS.h>
#include <GPSport.h>

NMEAGPS gps;
gps_fix fix;

void setup() {
  Serial.begin(9600);
  gpsPort.begin(9600);
}

void loop() {
  while (gps.available(gpsPort)) {
    fix = gps.read();

    if (fix.valid.location) {
      float latitude = fix.latitude();
      float longitude = fix.longitude();
      float speed = fix.speed_mph();
      float distance = fix.distanceBetween(targetLatitude, targetLongitude);

      Serial.print("Latitude: ");
      Serial.println(latitude, 6);
      Serial.print("Longitude: ");
      Serial.println(longitude, 6);
      Serial.print("Speed (mph): ");
      Serial.println(speed);
      Serial.print("Distance (m): ");
      Serial.println(distance);
    }
  }
}
