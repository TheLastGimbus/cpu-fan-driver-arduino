#include <Arduino.h>

#define FAN_PIN 13
#define CYCLE_MS 1000

byte currentVal = 127;

void slowPWM(byte pin, byte value) {
    int on = float(CYCLE_MS) * (value / 255.0);
    int off = CYCLE_MS - on;
    digitalWrite(pin, 1);
    delay(on);
    digitalWrite(pin, 0);
    delay(off);
}

void setup() {
    Serial.begin(9600);
    pinMode(FAN_PIN, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        currentVal = Serial.readStringUntil('\n').toInt();
        if (currentVal > 0 && currentVal < 255) {
            Serial.println("OK");
        } else {
            Serial.println("KO");
        }
    }
    slowPWM(FAN_PIN, currentVal);
}