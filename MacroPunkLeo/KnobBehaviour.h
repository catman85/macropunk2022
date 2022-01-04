#ifndef KNOB_BEHAVIOUR_H
#define KNOB_BEHAVIOUR_H
#include <Arduino.h>
#include <Mouse.h>
#include <math.h>

#include "StateManagement.h"

bool twistRightCondition(double potAcceleration);
bool maxRightCondition(double potValue);

bool twistLeftCondition(double potAcceleration);
bool maxLeftCondition(double potValue);

double getLinearFromLog(double potValue);
double normalizeAcceleration(double potValue, double previousPotValue);
long calculateSrollInterval(long slowestScrollInteval, double acceleration);

// Shortest Interval between scroll events (ms)
const unsigned long DEFAULT_SCROLL_INTERVAL = 90;
const unsigned int DEFAULT_SENSITIVIYT = 0;

class KnobBehaviour {
   protected:
    unsigned long scrollInterval;
    unsigned long sensitivity;

   public:
    KnobBehaviour(unsigned long autoInterval = DEFAULT_SCROLL_INTERVAL,
                  unsigned int sensitivity = DEFAULT_SENSITIVIYT) {
        this->scrollInterval = autoInterval;
        this->sensitivity = sensitivity;
    };

    virtual void twistRight(signed char potAcceleration) = 0;
    virtual void maxRight() = 0;

    virtual void twistLeft(signed char potAcceleration) = 0;
    virtual void maxLeft() = 0;

    long getSlowestScrollTick() { return this->scrollInterval; }
    long getSensitivity() { return this->sensitivity; }
};

class MouseScrollBehaviour : public KnobBehaviour {
   public:
    using KnobBehaviour::KnobBehaviour;

    void twistRight(signed char potAcceleration) { Mouse.move(0, 0, -1); };
    void maxRight() { Mouse.move(0, 0, -4); };

    void twistLeft(signed char potAcceleration) { Mouse.move(0, 0, 1); };
    void maxLeft() { Mouse.move(0, 0, 4); };
};

#endif