#include "ProfileConfiguration.h"

Profile defaultProfile;

void configureProfiles() {
    defaultProfile.fingerActions[pinky] = new OpenTabFingerAction();
    defaultProfile.fingerActions[ring] = new ClickFingerAction(8);
    defaultProfile.fingerActions[middle] = new PreviousTabFingerAction();
    defaultProfile.fingerActions[index] = new NextTabFingerAction();
    defaultProfile.fingerActions[thumb] = new SwitchAppFingerAction(500);
    defaultProfile.knobBehaviour = new MouseScrollBehaviour();
}