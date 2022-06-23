#define SFML_STATIC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>

#include "simulation.h"

int main()
{
    srand(time(NULL));
    static const unsigned int windowWidth = 1260;
    static const unsigned int windowHeight = 848;
    static const unsigned int particleWidth = 2;
    static const unsigned int particleHeight = 2;

    sfColor clearColor = sfColor_fromRGBA(empty_color.r, empty_color.g, empty_color.b, empty_color.a);

    simulation simulation = simulation_create(windowWidth, windowHeight, particleWidth, particleHeight);
    simulation_randomize(&simulation);

    sfVideoMode mode = {windowWidth, windowHeight, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Particle Sim", sfClose, NULL);
    if (!window)
        return 1;

    sfEvent event;
    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed) {
                if(event.key.code == sfKeyR)
                    simulation_randomize(&simulation);
            }
            
        }
        sfRenderWindow_clear(window, clearColor);
        simulation_update(&simulation);
        simulation_draw(&simulation, window);
        sfRenderWindow_display(window);
    }

    simulation_free(&simulation);
    sfRenderWindow_destroy(window);
    return 0;
}
