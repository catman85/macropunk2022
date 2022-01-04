#include "MyLogger.h"

void showFingersState() {
    Serial.print("Pinky: ");
    Serial.print(getStateOfFinger(pinky));
    Serial.print(" Ring: ");
    Serial.print(getStateOfFinger(ring));
    Serial.print(" Middle: ");
    Serial.print(getStateOfFinger(middle));
    Serial.print(" Index: ");
    Serial.print(getStateOfFinger(index));
    Serial.print(" Thumb: ");
    Serial.println(getStateOfFinger(thumb));
};

void showKnobState() {
    Serial.print("Knob Value: ");
    Serial.print(getKnobValue());
    // Serial.print("Knob Previous Value: ");
    // Serial.print(getKnobPreviousValue());
    Serial.print(" Knob Acceleration: ");
    Serial.println(getKnobAcceleration());
}
