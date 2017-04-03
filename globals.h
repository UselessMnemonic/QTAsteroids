#ifndef GLOBALS
#define GLOBALS
#include <QDebug>

extern int SIZE;
extern int PADDING;
static bool SHOW_BOUNDS = false;
static bool SHOW_TRAJECTORIES = true;
extern float COSINES[359], SINES[359];

static float degSIN(int deg)
{
    if(deg < 0)
        return -SINES[deg % 360];

    return SINES[deg % 360];
}

static float degCOS(int deg)
{
    return COSINES[deg%360];
}

#endif // GLOBALS

