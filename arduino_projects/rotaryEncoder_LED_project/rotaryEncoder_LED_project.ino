const int clkPin = 2;      // Rotary encoder CLK
const int dtPin = 3;       // Rotary encoder DT
const int ledPin = 10;      // LED connected to PWM pin

int brightness = 0;        // LED brightness (0-255)
int lastClkState;

void setup() {
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  lastClkState = digitalRead(clkPin);
}

void loop() {
  int currentClkState = digitalRead(clkPin);

  // Only act when the state changes
  if (currentClkState != lastClkState) {
    if (digitalRead(dtPin) != currentClkState) {
      brightness += 5;  // Clockwise
    } else {
      brightness -= 5;  // Counter-clockwise
    }

    brightness = constrain(brightness, 0, 255);  // Keep brightness safe
    analogWrite(ledPin, brightness);

    Serial.print("Brightness: ");
    Serial.println(brightness);
  }

  lastClkState = currentClkState;
}