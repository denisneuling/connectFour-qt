#ifndef ANIMATION_H
#define ANIMATION_H

#include "coin.h"

#define ACCELERATION -9
#define TIME_STEP (1000/60) // 60FPS

/*!
 * \brief handles animation state
 * \details Struct that handles animation state
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
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
