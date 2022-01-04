#include "StateManagement.h"

FingersState fingersState;
FingersState previousFingersState;
int getStateOfFinger(Finger finger) { return fingersState.finger[finger]; };
int getPreviousStateOfFinger(Finger finger) {
    return previousFingersState.finger[finger];
};

KnobState knobState;
void setKnobSmoothedProps() {
    knobState.potValue.begin(SMOOTHED_AVERAGE, 12);
    knobState.previousPotValue.begin(SMOOTHED_AVERAGE,13);
    knobState.potAcceleration.begin(SMOOTHED_AVERAGE, 13);
}
void sampleKnob() {
    double potValue = analogRead(POT_PIN);
    double linearPotValue = getLinearFromLog(potValue);
    knobState.potValue.add(linearPotValue);
    knobState.previousPotValue.add(knobState.potValue.getLast());
    double normalizedAcceleration = normalizeAcceleration(
        knobState.potValue.get(), knobState.previousPotValue.get());

    knobState.potAcceleration.add(normalizedAcceleration);
}
double getKnobValue() { return knobState.potValue.get(); }
double getKnobPreviousValue() { return knobState.previousPotValue.get(); }
double getKnobAcceleration() { return knobState.potAcceleration.get(); }

void setFingersState() {
    // We cant use attach Interrputs in this case because we need to recognize
    // the HOLD state.
    fingersState.finger[pinky] = digitalRead(PINKY_PIN);
    fingersState.finger[ring] = digitalRead(RING_PIN);
    fingersState.finger[middle] = digitalRead(MIDDLE_PIN);
    fingersState.finger[index] = digitalRead(INDEX_PIN);
    fingersState.finger[thumb] = digitalRead(THUMB_PIN);
};
void setPreviousFingersState() { previousFingersState = fingersState; };