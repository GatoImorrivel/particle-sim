#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "position.h"
#include "particles.h"

typedef struct simulation
{
    unsigned int width;
    unsigned int height;
    unsigned int simSize;
    unsigned int textureDataSize;
    sfUint8* textureData;
    sfTexture* texture;
    sfSprite* sprite;
    particle* particles;
} simulation;

simulation simulation_create(unsigned int windowWidth, unsigned int windowHeight, unsigned int particleWidth, unsigned particleHeight);
void simulation_draw(simulation *const simulation, sfRenderWindow *window);
void simulation_update(simulation *const simulation);
void simulation_write_texture_pixel(simulation *const simulation, size_t index, color color);
void simulation_randomize(simulation *const simulation);
void simulation_free(simulation *const simulation);

bool simulation_validate_pos(const simulation *const simulation, position pos);
void simulation_swap_particles(simulation *const simulation, const position pos1, const position pos2);
size_t simulation_get_index(const simulation *const simulation, position pos);
particle *simulation_particle_at(const simulation *const simulation, position pos);

#endif // __SIMULATION_H__
