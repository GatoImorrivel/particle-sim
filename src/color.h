#ifndef __COLOR_H__
#define __COLOR_H__

#include <SFML/System.h>

#define COLOR_CHANNELS 4

typedef struct color
{
    sfUint8 r, g, b, a;
} color;

static const color empty_color = {36, 36, 41, 255};
static const color sand_color = {235, 178, 47, 255};
static const color water_color = {43, 182, 224, 100};

#endif // __COLOR_H__
