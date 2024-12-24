#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_AHTX0.h>


Adafruit_BMP280 bmp;
Adafruit_AHTX0 aht;
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.println(result);
  Serial.begin(115200);
  Serial.println(F("AHT20+BMP280 test"));

  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }


  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */


  if (! aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 or AHT20 found");

}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.print("Pressure: " );
   Serial.print(bmp.readPressure());
  Serial.print("    Temp: " );
   Serial.println(bmp.readTemperature());


  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  Serial.print("Temperature: "); Serial.print(temp.temperature); 
  Serial.print("  Humidity: "); Serial.println(humidity.relative_humidity);

    delay(2000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}