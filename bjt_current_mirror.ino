// Pins
const int pwmPin = 9;         // Filtered PWM output to sweep Vce
const int vceSensePin = A0;   // Measures Vce (collector voltage)
const int vSensePin = A1;     // Measures voltage across sense resistor
const float R_sense = 100.0;  // Sense resistor value in ohms

void setup() {
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // Sweep PWM from 0 to 255
  for (int pwmVal = 0; pwmVal <= 255; pwmVal += 5) {
    analogWrite(pwmPin, pwmVal);
    delay(50); // Allow RC filter to settle

    // Read analog voltages
    float Vce = analogRead(vceSensePin) * (5.0 / 1023.0);
    float V_sense = analogRead(vSensePin) * (5.0 / 1023.0);

    // Calculate collector current in mA
    float Ic_mA = (V_sense / R_sense) * 1000.0;

    // Print clean CSV format: Vce, Ic
    Serial.print(Vce, 2);
    Serial.print(", ");
    Serial.println(Ic_mA, 2);
  }

  // Stop after one full sweep
  while (true) {
    delay(1000);
  }
}
