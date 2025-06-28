#include "TinyGPS++.h"
#include "SoftwareSerial.h"

// GPS and SIM800L
SoftwareSerial gpsSerial(10, 11); // GPS TX, RX
SoftwareSerial sim800l(8, 9);     // SIM800L TX, RX
TinyGPSPlus gps;                  // GPS object

const int buttonPin = 13;         // Button pin
int buttonState = HIGH;           // Current button state
int lastButtonState = HIGH;       // Last button state

// Phone number to send SMS
const char phoneNumber[] = "+1234567890"; // Replace with recipient's number

void setup()
{
  Serial.begin(9600);             // Monitor serial
  gpsSerial.begin(9600);          // GPS serial
  sim800l.begin(9600);            // SIM800L serial
  pinMode(buttonPin, INPUT_PULLUP); // Button setup with internal pull-up

  // Initialize SIM800L
  Serial.println("Initializing SIM800L...");
  sendCommand("AT");
  sendCommand("AT+CMGF=1");        // Set SMS mode to text
  Serial.println("SIM800L Initialized.");
}

void loop()
{
  // Continuously process GPS data
  while (gpsSerial.available())
  {
    gps.encode(gpsSerial.read());
  }

  // Read button state
  buttonState = digitalRead(buttonPin);

  // Check for button press (HIGH to LOW transition)
  if (buttonState == LOW && lastButtonState == HIGH)
  {
    sendLocation();               // Send GPS location via SMS
  }

  // Update last button state
  lastButtonState = buttonState;
}

void sendLocation()
{
  if (gps.location.isValid())
  {
    String message = "Location:\n";
    message += "Lat: ";
    message += String(gps.location.lat(), 6);
    message += "\nLng: ";
    message += String(gps.location.lng(), 6);
    message += "\nAlt: ";
    message += String(gps.altitude.feet()) + " ft";

    Serial.println("Sending SMS...");
    sendCommand("AT+CMGS=\"" + String(phoneNumber) + "\""); // Start SMS
    sim800l.println(message);                              // Send SMS body
    sim800l.write(26);                                     // End SMS (CTRL+Z)
    delay(3000);
    Serial.println("SMS Sent!");
  }
  else
  {
    Serial.println("GPS location is not valid. Waiting for signal...");
  }
}

void sendCommand(String cmd)
{
  sim800l.println(cmd);
  delay(1000);                  // Wait for the command to process
  while (sim800l.available())
  {
    Serial.write(sim800l.read());
  }
}
