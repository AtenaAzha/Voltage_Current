const int LED_voltage_pin   = A0;
const int current_sense_pin = A1;
const float R_sense         = 39.0;

const int MAX_SAMPLES = 6000;
int sample_count       = 0; 


void setup() {
  Serial.begin(9600);

}

void loop() {
  if (sample_count < MAX_SAMPLES) {
    int LED_voltage = analogRead(LED_voltage_pin);
    int current_sense_voltage = analogRead(current_sense_pin);

    float voltage_LED = LED_voltage * (5.0/1023.0);
    float voltage_R_sense = current_sense_voltage * (5.0/1023.0);

    float current_LED = 0.0;
    if (R_sense > 0.001) {
      current_LED = voltage_R_sense/R_sense;
    }

    if (current_LED < 0) {
    current_LED = 0;
    }

    Serial.print(",");
    Serial.print(millis());
    Serial.print(",");
    Serial.print(voltage_LED , 4);
    Serial.print(",");
    Serial.println(current_LED , 4);

    sample_count++;

    if (sample_count == MAX_SAMPLES) {
      Serial.println(",");
    }
    delay(100);
  } else {
    delay(5000);
  }
}
