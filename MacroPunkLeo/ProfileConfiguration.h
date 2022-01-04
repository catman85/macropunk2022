#ifndef PROFILE_CONFIGURATION_H
#define PROFILE_CONFIGURATION_H
#include "FingerActions.h"
#include "WiringConfiguration.h"
#include "StateManagement.h"
#include "KnobBehaviour.h"

struct Profile {
    FingerAction* fingerActions[5];
    KnobBehaviour* knobBehaviour;
};

extern Profile defaultProfile;

void configureProfiles();

#endif