#include "globals.h"

int BASE_SIZE = 600;
int PADDING = 5;

bool SHOW_BOUNDS = true;
bool SHOW_TRAJECTORIES = false;

float SINES[359];
float COSINES[359];

float degSIN(int deg)
{
    if(deg < 0)
        return -SINES[deg % 360];

    return SINES[deg % 360];
}

float degCOS(int deg)
{
    return COSINES[deg%360];
}

