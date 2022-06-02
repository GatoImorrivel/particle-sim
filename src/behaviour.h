#ifndef __BEHAVIOUR_H__
#define __BEHAVIOUR_H__

#include "simulation.h"
#include "particles.h"
#include "position.h"

void simulate_sand(simulation *simulation, const position pos);
void simulate_water(simulation *simulation, const position pos);

#endif // __BEHAVIOUR_H__
