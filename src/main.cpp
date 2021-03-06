#include <Arduino.h>

#define FAN_PIN 13
#define CYCLE_MS 1000

byte currentVal = 127;

void slowPWM(byte pin, byte value) {
    int on = float(CYCLE_MS) * (value / 255.0);
    int off = CYCLE_MS - on;
    if (on > 0) {
        digitalWrite(pin, 1);
        delay(on);
    }
    if (off > 0) {
        digitalWrite(pin, 0);
        delay(off);
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(FAN_PIN, OUTPUT);
}

void loop() {
    while (Serial.available()) {
        int newVal = Serial.read();
        if (newVal >= 0 && newVal < 256) {
            Serial.print(1);
            currentVal = newVal;
        } else {
            Serial.print(0);
        }
        Serial.flush();
    }
    slowPWM(FAN_PIN, currentVal);
}