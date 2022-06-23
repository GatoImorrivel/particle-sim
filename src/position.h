#ifndef __POSITION_H__
#define __POSITION_H__

#include <stdio.h>

typedef struct position
{
    int x;
    int y;
} position;

position create_pos(int x, int y);

#endif // __POSITION_H__
