#ifndef GLOBALS
#define GLOBALS

static int WIDTH = 500;
static int HEIGHT = 500;
static bool SHOW_BOUNDS = true;
static bool SHOW_TRAJECTORIES = true;
static double COSINES[359], SINES[359];

static double degSIN(int deg)
{
    if(deg < 0)
        return -SINES[(-deg) % 360];
    return SINES[deg % 360];
}

static double degCOS(int deg)
{
    if(deg < 0)
        deg = -deg;

    return COSINES[deg%360];
}

#endif // GLOBALS

