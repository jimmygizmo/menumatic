#include <Arduino.h>
#include <LCDKeypad.h>
#include <CustomChars.h>
#include <TimingSettings.h>

// int pressResult = 0;  // Not used yet

LCDKeypad lcd;


// ########    FUNCTION DEFINITIONS   ########


void paintDash(String msg, int val1, int val2) {
    lcd.clear();  // Our slight flickering problem is happening here.
    // SOLUTION: We need to use a checksum on screen data to detect changes and only paint upon change.

    // TODO: Ideas for checksum: https://stackoverflow.com/questions/811195/fast-open-source-checksum-for-small-strings
    
    lcd.print("Power [");
    lcd.print(msg);
    lcd.print("] ");
    lcd.setCursor(0,1);
    lcd.print("Ticks [");
    lcd.print(val2);
    lcd.print("]");
    //lcd.print(msg);
    delay(paintFreezeMillis);
} // paintDash


void showMsg(String msg) {
    lcd.clear();
    lcd.print(msg);
    delay(alertMillis);
} // showMsg


void showGuide() {
    // Show menu instructions
    // LINE 1
    lcd.clear();
    lcd.print("Nav ");
    lcd.write(CHR_LEFT);
    lcd.write(CHR_UP);
    lcd.write(CHR_DOWN);
    lcd.write(CHR_RIGHT);
    lcd.print(" Edit ");
    lcd.write(CHR_UP);
    lcd.write(CHR_DOWN);
    // LINE 2
    lcd.setCursor(0,1);
    lcd.print("Select ");
    lcd.write(CHR_SELECT);
    lcd.print(" Reset ");
    lcd.write(CHR_RESET);
} // showGuide


void animatedBanner(){
    int i,k;
    int slideSteps = 3;
    lcd.clear();
    // Draw banner
    lcd.print("    NinthDevice ");
    lcd.setCursor(0,1);
    lcd.print("   ");
    lcd.write(CHR_LEFT);
    lcd.print(" MenuMatic ");
    lcd.write(CHR_RIGHT);
    delay(bannerMillis);

    // Slide left
    for (k=0;k<slideSteps;k++){
        lcd.scrollDisplayLeft();
        delay(50);
    }
    delay(bannerMillis);

    // Oscillate right-left a few times
    for (i=0;i<1;i++){
        for (k=0;k<slideSteps;k++) {
            lcd.scrollDisplayRight();
            delay(140);
        }
        delay(140);
        for (k=0;k<slideSteps;k++){
            lcd.scrollDisplayLeft();
            delay(140);
        }
        delay(140);
    }
    delay(bannerMillis);

    // Exit stage left
    for (k=0;k<16;k++){
        lcd.scrollDisplayLeft();
        delay(50);
    }
} // animatedBanner


// ########    END GLOBAL SCOPE INITIALIZATION    ########


// #######################################################
// ########    MAIN ARDUINO setup() AND loop()    ########
// #######################################################


// ARDUINO SETUP
void setup(){
    // IMPORTANT BUG FINALLY SOLVED - Character icons were getting corrupted and looked like corrupted memory.
    // SOLUTION:
    // You must always call lcd.begin() before any other lcd calls and you must never call it more than once.
    // Calling lcd.begin() a second time unnecessarily was the cause of corruption in the custom character memory.

    lcd.begin(16, 2);
    lcd.clear();

    lcd.createChar(CHR_SELECT,c_select);
    lcd.createChar(CHR_UP,c_up);
    lcd.createChar(CHR_DOWN,c_down);
    lcd.createChar(CHR_LEFT,c_left);
    lcd.createChar(CHR_RIGHT,c_right);
    lcd.createChar(CHR_RESET,c_reset);

    animatedBanner();
    showGuide();
    delay(guideMillis);
} // setup


// #### Global var initialization for use in main loop
String msg = "OFF";
int val1 = 0;
int val2 = 512;


// ARDUINO INFINITE LOOP
void loop() {
    paintDash(msg, val1, val2);

    //lcd.button();
    switch(lcd.buttonBlocking(keyBlockDelayMillis, keyRepeatDelayMillis)) {
        // NOTE: The Reset button is hardwired to Arduino system Reset/Reboot
        // and is not involved in keypad button operation, although it does
        // have a custom icon shown in the menu guide.
        case KEYPAD_SELECT:
            showMsg("     SELECT    ");
            paintDash(msg, val1, val2);
            break;
        case KEYPAD_LEFT:
            showMsg("      LEFT     ");
            val2 = val2 - 1;
            paintDash(msg, val1, val2);
            break;
        case KEYPAD_UP:
            showMsg("       UP      ");
            msg = "HIGH";
            paintDash(msg, val1, val2);
            break;
        case KEYPAD_DOWN:
            showMsg("      DOWN     ");
            msg = "LOW";
            paintDash(msg, val1, val2);
            break;
        case KEYPAD_RIGHT:
            showMsg("      RIGHT    ");
            val2 = val2 + 1;
            paintDash(msg, val1, val2);
            break;
    }

    delay(20);  // Tried a 20ms delay here to reduce flicker during main loop, but had no noticeable effect.
} // loop


/**/
//
