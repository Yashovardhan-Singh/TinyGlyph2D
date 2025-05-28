#ifndef VECTOR_H
#define VECTOR_H

#include "defines.h"

// X and Y components
typedef struct {
    float x, y;
} Vec2;

TGAPI INLINE Vec2 vec2GetZero();

#endif //VECTOR_H
