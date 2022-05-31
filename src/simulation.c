#include <stdio.h>
#include <malloc.h>
#include "simulation.h"
#include "particles.h"

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

void simulation_draw(simulation *simulation, sfRenderWindow *window)
{
    for (size_t i = 0; i < simulation->simSize; i++)
    {
        color c = simulation->particles[i].color;
        simulation_write_texture_pixel(simulation, i * COLOR_CHANNELS, c);
    }
    
    sfTexture_updateFromPixels(simulation->texture, simulation->textureData, simulation->width, simulation->height, 0, 0);
    sfRenderWindow_drawSprite(window, simulation->sprite, NULL);
}

void simulation_update(simulation *simulation)
{
    for (size_t i = 0; i < simulation->simSize; i++)
    {
        switch (simulation->particles[i].id)
        {
        case SAND_P:

            break;
        case WATER_P:

            break;
        
        default:
            break;
        }
    }
    
}

void simulation_write_texture_pixel(simulation *simulation, size_t index, color color)
{
    simulation->textureData[index] = color.r;
    simulation->textureData[index + 1] = color.g;
    simulation->textureData[index + 2] = color.b;
    simulation->textureData[index + 3] = color.a;
}

void simulation_initialize(simulation *simulation)
{
    for (size_t i = 0; i < simulation->simSize; i++)
    {
        simulation->particles[i] = i % 2 ? water_particle() : empty_particle();
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
