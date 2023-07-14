/* * This file receives a Serial value of "1" or "0" and changes the light based on * that value.  */
// Define the port for the LED
#define lightPin D0
int distance = 0;

String receivedString = "";

void setup() {
  // Initialize the light pin
  pinMode(lightPin, OUTPUT);
  // Initialize the Serial
  Serial.begin(9600);
}

void distanceCalculate() {


  distance = 60;
  Serial.println(distance);

  delay(1000);



}

void loop() {
  // CHeck to see if Serial data is being received
  if (Serial.available() > 0)
  {
    // Create a new string variable to receive Serial data
    receivedString = "";
    // Loop through received data and append to the receivedString variable
    while (Serial.available() > 0)
    {
      receivedString += char(Serial.read ());

    }

    // Print received Serial data
    Serial.println(receivedString);

    // Change LED status based on received data
    if (receivedString == "1") {
      //      digitalWrite(lightPin, HIGH);

      distanceCalculate();

      //        Serial.println(distance);

    }

    if (receivedString == "0")
    {
      //      digitalWrite(lightPin, LOW);
      distance = 0;
      Serial.println(distance);

    }

  }
}
