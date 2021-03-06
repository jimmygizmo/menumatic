#ifndef TIMINGSETTINGS_H
#define TIMINGSETTINGS_H

// ########    TIMING SETTINGS    ########

// All these values are in Milliseconds as indicated by the constant name
const int keyBlockDelayMillis = 20;
const int keyRepeatDelayMillis = 20;
const int alertMillis = 500;
const int bannerMillis = 1500;
const int guideMillis = 6000;
const int paintFreezeMillis = 20;  // This setting affects our flickering issue, but not related to the solution.
// paintFreezeMillis should stay around 10-20 ms. Make it too long and you can miss keypresses.

#endif


/**/
//
