#ifndef __POSITION_H__
#define __POSITION_H__

#include <stdio.h>

typedef struct position
{
    unsigned int x;
    unsigned int y;
} position;

position create_pos(unsigned int x, unsigned int y);

#endif // __POSITION_H__
