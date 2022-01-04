#include <Keyboard.h>
#include <Mouse.h>

#include "EventDispatcher.h"
#include "MyLogger.h"
#include "ProfileConfiguration.h"
#include "StateManagement.h"
#include "TimerOne.h"
#include "WiringConfiguration.h"

// delay functions don't work in here.
void handleKnobSampling(void) {
    sampleKnob();
    // showFingersState();
    // showKnobState();
}

void setup() {
    // Serial.begin(4800);

    Mouse.begin();
    Keyboard.begin();

    configurePins();
    configureProfiles();
    setKnobSmoothedProps();

    // initialize timer1, and set a period of 20ms (in nanoseconds)
    Timer1.initialize(20000);
    Timer1.attachInterrupt(handleKnobSampling);
}

void loop() {
    setFingersState();
    handleFingers(defaultProfile);
    setPreviousFingersState();

    // Can't put this in the timer interrupt function because it relies on delay
    handleKnob(defaultProfile);
}