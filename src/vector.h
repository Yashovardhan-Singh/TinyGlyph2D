#ifndef VECTOR_H
#define VECTOR_H

#include "defines.h"

// X and Y components
typedef struct {
    float x, y;
} Vec2;

API INLINE Vec2 vec2GetZero();

#endif //VECTOR_H
