#ifndef ANIMATION_H
#define ANIMATION_H

#include "coin.h"

#define ACCELERATION -9
#define TIME_STEP (1000/60) // 60FPS

//! Struct that handles animation state
typedef struct Animation
{
    bool active;

    int currentY;
    int endY;
    int positionX;
    int startY;

    float time;

    Coin player;


} Animation;

#endif // ANIMATION_H
