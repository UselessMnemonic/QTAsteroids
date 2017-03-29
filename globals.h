#ifndef GLOBALS
#define GLOBALS

static int WIDTH = 500;
static int HEIGHT = 500;
static bool SHOW_BOUNDS = true;
static bool SHOW_TRAJECTORIES = true;
static double COSINES[359], SINES[359];

static double degSIN(int deg)
{
    return SINES[deg%360];
}

static double degCOS(int deg)
{
    return COSINES[deg%360];
}

#endif // GLOBALS

