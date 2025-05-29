#ifndef VECTOR_H
#define VECTOR_H

#include "defines.h"

// X and Y components
typedef struct {
    float x, y;
} Vec2;

TGAPI INLINE Vec2 vec2GetZero();
TGAPI INLINE Vec2 vec2Add(Vec2 v1, Vec2 v2);
TGAPI INLINE Vec2 vec2Sub(Vec2 v1, Vec2 v2);
TGAPI INLINE Vec2 vec2ScalarAdd(Vec2 v1, float scalar);
TGAPI INLINE Vec2 vec2ScalarSub(Vec2 v1, float scalar);
TGAPI INLINE Vec2 vec2Scale(Vec2 v1, float scalar);
TGAPI INLINE float vec2Dot(Vec2 v1, Vec2 v2);
TGAPI INLINE float vec2Cross(Vec2 v1, Vec2 v2);
TGAPI INLINE float vec2Length(Vec2 v1);
TGAPI INLINE float vec2LengthSquared(Vec2 v1);
TGAPI INLINE Vec2 vec2Normalize(Vec2 v1);

#endif // VECTOR_H