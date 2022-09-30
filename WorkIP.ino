#include <SPI.h>
#include <SD.h>
File myFile;
void setup() {
Serial.begin(9600);

pinMode(10, OUTPUT); 
digitalWrite(10, HIGH); 

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  myFile = SD.open("airdata.txt", FILE_WRITE); 

if (myFile) {
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
  } 
}

void loop() {
  if (myFile) {
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  myFile = SD.open("airdata.txt", FILE_WRITE); 
  delay(5000);
}
