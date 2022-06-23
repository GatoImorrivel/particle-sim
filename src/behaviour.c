#include "behaviour.h"

void simulate_sand(simulation *const simulation, const position pos)
{
    const position neighbours[] = {
        {pos.x, pos.y + 1},     // Down
        {pos.x - 1, pos.y + 1}, // Left-Down
        {pos.x + 1, pos.y + 1}, // Right-Down
    };

    if (simulation_validate_pos(simulation, neighbours[0]))
    {
        if(simulation_particle_at(simulation, neighbours[0])->id == EMPTY_P)
            simulation_swap_particles(simulation, neighbours[0], pos);
        else if(simulation_particle_at(simulation, neighbours[1])->id == EMPTY_P)
            simulation_swap_particles(simulation, neighbours[1], pos);
        else if(simulation_particle_at(simulation, neighbours[2])->id == EMPTY_P)
            simulation_swap_particles(simulation, neighbours[2], pos);
    }
}

void simulate_water(simulation *const simulation, const position pos)
{
}
