#ifndef __PARTICLES_H__
#define __PARTICLES_H__

#include "color.h"

enum particles {
    EMPTY_P,
    SAND_P,
    WATER_P,
};

typedef struct particle
{
    color color;
    enum particles id;
} particle;

particle empty_particle();
particle sand_particle();
particle water_particle();

#endif // __PARTICLES_H__
