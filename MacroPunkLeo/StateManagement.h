#ifndef STATE_MANAGEMENT_H
#define STATE_MANAGEMENT_H
#include <Arduino.h>
#include <Smoothed.h>

#include "KnobBehaviour.h"
#include "WiringConfiguration.h"

enum Finger { pinky, ring, middle, index, thumb };
struct FingersState {
    int finger[5] = {1};
};
int getStateOfFinger(Finger finger);
int getPreviousStateOfFinger(Finger finger);

struct KnobState {
    Smoothed<double> potValue;
    Smoothed<double> previousPotValue;
    Smoothed<double> potAcceleration;
};
void setKnobSmoothedProps();
double getKnobValue();
double getKnobPreviousValue();
double getKnobAcceleration();

void setFingersState();
void sampleKnob();
void setPreviousFingersState();

#endif