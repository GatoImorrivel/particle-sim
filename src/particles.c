#include "particles.h"
#include "simulation.h"

particle empty_particle()
{
    particle p;
    p.color = empty_color;
    p.id = EMPTY_P;
    return p;
}

particle sand_particle()
{
    particle p;
    p.color = sand_color;
    p.id = SAND_P;
    return p;
}

particle water_particle()
{
    particle p;
    p.color = water_color;
    p.id = WATER_P;
    return p;
}
