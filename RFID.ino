#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11);
SoftwareSerial mySerial(9, 10); //declaring pins for rfid
String number = "+880XXXXXXXXXX"; // +880 is the country code
char tag[3][12]={};

void setup() {
   mySerial.begin(9600); // Setting the baud rate of Software Serial Library
  Serial.begin(9600);  //Setting the baud rate of Serial Monitor
  //above two lines are for rfid data display
  Serial.println("Wait few seconds...");
  delay(5000);
  Serial.println("System Started...");
  sim.begin(9600);
  delay(1000);
  Serial.println("Type c to make a call and s to send an SMS");
}

void loop() {
 if (mySerial.available() > 0)
  {
    Serial.write(mySerial.read());
    val=mySerial.read();
  }
  //above two lines are for rfid card detection
  
  if (Serial.available() > 0)
    switch (Serial.read())
    {
      case 'c':
        callNumber();
        break;
      case 's':
        SendMessage();
        break;
    }
  if (sim.available() > 0)
    Serial.write(sim.read());
}

void SendMessage()
{
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + number + "\"\r");
  delay(1000);
  String SMS = "Your ward is present today";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);
  delay(1000);
}
