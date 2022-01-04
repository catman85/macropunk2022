#include "KnobBehaviour.h"

const double potNoiseShield = 0.02;

bool twistRightCondition(double potAcceleration) { return potAcceleration > 0; }
bool maxRightCondition(double potValue) { return potValue >= 9.8; }

bool twistLeftCondition(double potAcceleration) { return potAcceleration < 0; }
bool maxLeftCondition(double potValue) { return potValue <= 0.2; }

double logOfBase(int base, int x) {
    if (x <= 0) return 0;
    double a = log((double)x);
    double b = log((double)base);
    return a / b;
}

double normalizeAcceleration(double potValue, double previousPotValue) {
    double diff = potValue - previousPotValue;
    if (diff <= potNoiseShield && -potNoiseShield <= diff) return 0;
    if (diff > 0) {
        return pow(diff + 1, 13);  // even powers make everything positive
    }
    if (diff < 0) {
        return pow(diff - 1, 13);
    }
}

// Calibrated for shitty Harley Benton A500k pot at 5v
double getLinearFromLog(double potValue) {
    double inverse = logOfBase(5, potValue + 50);
    return 5.3 * (inverse - 2.43);
}

long calculateSrollInterval(long slowestScrollInteval, double acceleration) {
    long timeSubstractionFactor = abs(acceleration) * 20;
    if (timeSubstractionFactor >= slowestScrollInteval) return 0;
    return slowestScrollInteval - timeSubstractionFactor;
}