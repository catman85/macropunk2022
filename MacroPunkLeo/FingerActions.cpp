#include "FingerActions.h"

bool riseCondition(int previousValue, int currentValue) {
    return (previousValue == HIGH && currentValue == LOW);
};

bool holdCondition(int previousValue, int currentValue) {
    return (previousValue == LOW && currentValue == LOW);
};

bool fallCondition(int previousValue, int currentValue) {
    return (previousValue == LOW && currentValue == HIGH);
};
