#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "simulation.h"
#include "particles.h"
#include "behaviour.h"

simulation simulation_create(unsigned int windowWidth, unsigned int windowHeight, unsigned int particleWidth, unsigned particleHeight)
{
    simulation simulation;
    simulation.width = windowWidth / particleWidth;
    simulation.height = windowHeight / particleHeight;
    simulation.simSize = simulation.width * simulation.height;

    simulation.particles = (particle *)calloc(simulation.simSize, sizeof(particle));
    simulation.textureData = (sfUint8 *)calloc(simulation.simSize * COLOR_CHANNELS, sizeof(sfUint8));

    simulation.texture = sfTexture_create(simulation.width, simulation.height);
    if (!simulation.texture)
        printf("ERROR CREATING TEXTURE \n");

    simulation.sprite = sfSprite_create();
    if (!simulation.sprite)
        printf("ERROR CREATING SPRITE \n");

    sfVector2f scale = {particleWidth, particleHeight};
    sfSprite_setScale(simulation.sprite, scale);
    sfSprite_setTexture(simulation.sprite, simulation.texture, sfTrue);

    return simulation;
}

void simulation_draw(simulation *const simulation, sfRenderWindow *window)
{
    for (size_t i = 0; i < simulation->simSize; i++)
    {
        color c = simulation->particles[i].color;
        simulation_write_texture_pixel(simulation, i * COLOR_CHANNELS, c);
    }

    sfTexture_updateFromPixels(simulation->texture, simulation->textureData, simulation->width, simulation->height, 0, 0);
    sfRenderWindow_drawSprite(window, simulation->sprite, NULL);
}

void simulation_update(simulation *const simulation)
{
    position pos;
    for (size_t y = simulation->height - 1; y > 0; y--)
    {
        pos.y = y;
        for (size_t x = 0; x < simulation->width; x++)
        {
            pos.x = x;
            switch (simulation->particles[x].id)
            {
            case SAND_P:
                simulate_sand(simulation, pos);
                break;
            case WATER_P:
                simulate_water(simulation, pos);
                break;
            default:
                break;
            }
        }
    }
}

void simulation_write_texture_pixel(simulation *const simulation, size_t index, color color)
{
    simulation->textureData[index] = color.r;
    simulation->textureData[index + 1] = color.g;
    simulation->textureData[index + 2] = color.b;
    simulation->textureData[index + 3] = color.a;
}

void simulation_randomize(simulation *const simulation)
{
    int random;
    for (size_t i = 0; i < simulation->simSize; i++)
    {
        random = rand() % 2;
        simulation->particles[i] = random == 0 ? empty_particle() : sand_particle();
        simulation_write_texture_pixel(simulation, i * COLOR_CHANNELS, simulation->particles[i].color);
    }
}

void simulation_free(simulation *simulation)
{
    free(simulation->textureData);
    free(simulation->textureData);
    sfTexture_destroy(simulation->texture);
    sfSprite_destroy(simulation->sprite);
}

void simulation_swap_particles(simulation *const simulation, const position pos1, const position pos2)
{
    size_t i1 = simulation_get_index(simulation, pos1);
    size_t i2 = simulation_get_index(simulation, pos2);
    particle pTemp = simulation->particles[i1];
    simulation->particles[i1] = simulation->particles[i2];
    simulation->particles[i2] = pTemp;
}

size_t simulation_get_index(const simulation *const simulation, position pos)
{
    return pos.y * simulation->height + pos.x;
}

bool simulation_validate_pos(const simulation *const simulation, position pos)
{
    return pos.x < simulation->width && pos.x > 0 && pos.y < simulation->height && pos.y > 0;
}

particle *simulation_particle_at(const simulation *const simulation, position pos)
{
    const size_t index = simulation_get_index(simulation, pos);
    particle *p = &simulation->particles[index];
    return p;
}
