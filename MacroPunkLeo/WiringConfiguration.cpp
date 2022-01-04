#include "WiringConfiguration.h"

int PINKY_PIN = 4;
int RING_PIN = 3;
int MIDDLE_PIN = 2;
int INDEX_PIN = 0;
int THUMB_PIN = 1;
int POT_PIN = A3;

void configurePins() {
    pinMode(PINKY_PIN, INPUT);
    pinMode(RING_PIN, INPUT);
    pinMode(MIDDLE_PIN, INPUT);
    pinMode(INDEX_PIN, INPUT);
    pinMode(THUMB_PIN, INPUT);
    pinMode(POT_PIN, INPUT);
}