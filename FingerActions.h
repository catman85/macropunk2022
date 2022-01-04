#ifndef FINGER_ACTIONS_H
#define FINGER_ACTIONS_H
#include <Arduino.h>
#include <Keyboard.h>
#include <Mouse.h>

bool riseCondition(int previousValue, int currentValue);
bool holdCondition(int previousValue, int currentValue);
bool fallCondition(int previousValue, int currentValue);

const unsigned long DEFAULT_INTERVAL = 300;  // In ms
// use this options for OSX:
const char ctrlKey = KEY_LEFT_GUI;
const char altKey = KEY_LEFT_GUI;
// use this option for Windows and Linux:
// const char ctrlKey = KEY_LEFT_CTRL;
// const char altKey = KEY_LEFT_ALT;

class FingerAction {
   protected:
    unsigned long minimumInterval;

   public:
    FingerAction(unsigned long interval = DEFAULT_INTERVAL) {
        this->minimumInterval = interval;
    };
    virtual void rise() = 0;
    virtual void hold() = 0;
    virtual void fall() = 0;
    long getMinimumInterval() { return this->minimumInterval; }
};

class OpenTabFingerAction : public FingerAction {
   public:
    using FingerAction::FingerAction;
    void rise() {
        Keyboard.press(ctrlKey);
        Keyboard.press('t');
        Keyboard.release('t');
    }
    void hold() {
        Keyboard.press('t');
        Keyboard.release('t');
    }
    void fall() { Keyboard.releaseAll(); }
};

class ClickFingerAction : public FingerAction {
   public:
    using FingerAction::FingerAction;
    void rise() { Mouse.press(); }
    void hold() {}
    void fall() { Mouse.release(); }
};

class PreviousTabFingerAction : public FingerAction {
   public:
    using FingerAction::FingerAction;
    void rise() {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_PAGE_UP);
        Keyboard.release(KEY_PAGE_UP);
    }
    void hold() {
        Keyboard.press(KEY_PAGE_UP);
        Keyboard.release(KEY_PAGE_UP);
    }
    void fall() { Keyboard.releaseAll(); }
};

class NextTabFingerAction : public FingerAction {
   public:
    using FingerAction::FingerAction;
    void rise() {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_PAGE_DOWN);
        Keyboard.release(KEY_PAGE_DOWN);
    }
    void hold() {
        Keyboard.press(KEY_PAGE_DOWN);
        Keyboard.release(KEY_PAGE_DOWN);
    }
    void fall() { Keyboard.releaseAll(); }
};

class SwitchAppFingerAction : public FingerAction {
   public:
    using FingerAction::FingerAction;
    void rise() {
        Keyboard.press(altKey);
        Keyboard.press(KEY_TAB);
        Keyboard.release(KEY_TAB);
    }
    void hold() {
        Keyboard.press(KEY_TAB);
        Keyboard.release(KEY_TAB);
    }
    void fall() { Keyboard.releaseAll(); }
};

#endif