#include "behaviour.h"

void simulate_sand(simulation *const simulation, const position pos)
{
    const position neighbours[] = {
        {pos.x, pos.y + 1},     // Down
        {pos.x - 1, pos.y + 1}, // Left-Down
        {pos.x + 1, pos.y + 1}, // Right-Down
    };
    const unsigned int numOfNeighbours = 3;

    particle *neighbour;
    particle *self;
    for (size_t i = 0; i < numOfNeighbours; i++)
    {
        neighbour = simulation_particle_at(simulation, neighbours[i]);
        if (simulation_validate_pos(simulation, neighbours[i]) && neighbour->id == EMPTY_P)
        {
            self = simulation_particle_at(simulation, pos);
            simulation_swap_particles(simulation, pos, neighbours[i]);
            simulation_write_texture_pixel(simulation, simulation_get_index(simulation, pos) * COLOR_CHANNELS, self->color);
            break;
        }
    }
}

void simulate_water(simulation *const simulation, const position pos)
{
}
