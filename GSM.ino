#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11);

String number = "+919901553486"; // +91 is the country code

void setup() {
  Serial.begin(38400);
  Serial.println("Wait few seconds...");
  delay(5000);
  Serial.println("Sistem Started...");
  sim.begin(38400);
  delay(1000);
  Serial.println("Type c to make a call and s to send an SMS");
}

void loop() {
  if (Serial.available() > 0)
    switch (Serial.read())
    {
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
