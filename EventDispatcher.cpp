#include "EventDispatcher.h"

void handleFinger(FingerAction* fingerActions, Finger finger) {
    int previousValue = getPreviousStateOfFinger(finger);
    int currentValue = getStateOfFinger(finger);
    if (riseCondition(previousValue, currentValue)) {
        fingerActions->rise();
        delay(fingerActions->getMinimumInterval());
    };
    if (holdCondition(previousValue, currentValue)) {
        fingerActions->hold();
        delay(fingerActions->getMinimumInterval());
    };
    if (fallCondition(previousValue, currentValue)) {
        fingerActions->fall();
        delay(fingerActions->getMinimumInterval());
    };
};

void handleFingers(Profile profile) {
    handleFinger(profile.fingerActions[pinky], pinky);
    handleFinger(profile.fingerActions[ring], ring);
    handleFinger(profile.fingerActions[middle], middle);
    handleFinger(profile.fingerActions[index], index);
    handleFinger(profile.fingerActions[thumb], thumb);
};

void handleKnob(Profile profile) {
    double potValue = getKnobValue();
    double acceleration = getKnobAcceleration();
    long scrollInterval = profile.knobBehaviour->getSlowestScrollTick();
    long sensitivity = profile.knobBehaviour->getSensitivity();

    if (maxLeftCondition(potValue)) {
        profile.knobBehaviour->maxLeft();
    }
    if (maxRightCondition(potValue)) {
        profile.knobBehaviour->maxRight();
    }
    if (maxLeftCondition(potValue) || maxRightCondition(potValue)) {
        delay(profile.knobBehaviour->getSlowestScrollTick());
        return;
    }

    if (twistLeftCondition(acceleration)) {
        profile.knobBehaviour->twistLeft(acceleration);
    }
    if (twistRightCondition(acceleration)) {
        profile.knobBehaviour->twistRight(acceleration);
    }
    if (twistLeftCondition(acceleration) || twistRightCondition(acceleration)) {
        delay(calculateSrollInterval(
            profile.knobBehaviour->getSlowestScrollTick(), acceleration));
        return;
    }
}
