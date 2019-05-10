#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
char name;
void setup()
{
  mySerial.begin(9600); // Setting the baud rate of Software Serial Library
  Serial.begin(9600);  //Setting the baud rate of Serial Monitor
} void loop()
{

  if (mySerial.available() > 0)
  { 
    Serial.write(mySerial.read());
  }

 
  if (mySerial == 27002223AE88) {
    name = "Shubam Anand";
    println(name); 
}
  


}
