#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include <SFML/Graphics.h>
#include "particles.h"

typedef struct simulation
{
    unsigned int width;
    unsigned int height;
    particle* particles;
    sfUint8* textureData;
    sfTexture* texture;
    sfSprite* sprite;
    unsigned int simSize;
    unsigned int textureDataSize;
} simulation;

simulation simulation_create(unsigned int windowWidth, unsigned int windowHeight, unsigned int particleWidth, unsigned particleHeight);
void simulation_draw(simulation *simulation, sfRenderWindow *window);
void simulation_update(simulation *simulation);
void simulation_write_texture_pixel(simulation *simulation, size_t index, color color);
void simulation_initialize(simulation *simulation);
void simulation_free(simulation *simulation);
void simulation_particle_at(simulation *simulation, unsigned int x, unsigned int y);
void simulation_particles_in_bounds(simulation *simulation, unsigned int x, unsigned int y);
void simulation_compute_index(simulation *simulation, unsigned int x, unsigned int y);

#endif // __SIMULATION_H__
