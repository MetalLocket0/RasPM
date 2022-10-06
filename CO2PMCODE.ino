#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "SparkFun_SCD4x_Arduino_Library.h"
SCD4x mySensor;
File myFile;

void setup() {
Serial.begin(9600);
Wire.begin();

    if (mySensor.begin() == false)
  {
    Serial.println(F("Sensor not detected. Please check wiring. Freezing..."));
    while (1)
      ;
  }
Serial.print("Initializing SD card...");
if (!SD.begin(10)) {
Serial.println("initialization failed!");
while (1);
}
Serial.println("initialization done.");

}

void loop() {
  myFile = SD.open("air.txt", FILE_WRITE);

  if (myFile) {
  Serial.print("Writing to air.txt...");
  }
    if (mySensor.readMeasurement()){
  myFile.println(F("CO2(ppm):"));
  myFile.println(mySensor.getCO2());

  myFile.println(F("\tTemperature(C):"));
  myFile.println(mySensor.getTemperature(), 1);

  myFile.println(F("\tHumidity(%RH):"));
  myFile.println(mySensor.getHumidity(), 1);
  }
  else 
  myFile.print(F("."));
  myFile.close();
  Serial.println("done.");
    delay(900000);
  }
