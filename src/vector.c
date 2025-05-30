#include "vector.h"
#include <math.h>

TGAPI Vec2 vec2GetZero() {
    return (Vec2) { 0.0f, 0.0f };
}

TGAPI Vec2 vec2Add(Vec2 v1, Vec2 v2) {
    return (Vec2) {(v1.x + v2.x), (v1.y + v2.y) };
}

TGAPI Vec2 vec2Sub(Vec2 v1, Vec2 v2) {
    return (Vec2) {v1.x - v2.x,v1.y - v2.y };
}

TGAPI Vec2 vec2ScalarAdd(Vec2 v1, float scalar) {
    return (Vec2) {(v1.x + scalar),(v1.y + scalar) };
}

TGAPI Vec2 vec2ScalarSub(Vec2 v1, float scalar) {
    return (Vec2) {(v1.x - scalar),(v1.y - scalar) };
}

TGAPI Vec2 vec2Scale(Vec2 v1, float scalar) {
    return (Vec2) {(v1.x * scalar),(v1.y * scalar) };
}

TGAPI float vec2Dot(Vec2 v1, Vec2 v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

TGAPI float vec2Cross(Vec2 v1, Vec2 v2) {
    return (v1.x * v2.y) - (v1.y * v2.x);
}

TGAPI float vec2Length(Vec2 v1) {
    return sqrtf(v1.x * v1.x + v1.y * v1.y);
}

TGAPI float vec2LengthSquared(Vec2 v1) {
    return (v1.x * v1.x + v1.y * v1.y);
}

TGAPI Vec2 vec2Normalize(Vec2 v1) {
    float len = vec2Length(v1);
    return (Vec2) {(v1.x / len), (v1.y / len) };
}

TGAPI float vec2DistanceFromPoint(Vec2 v1, Vec2 v2) {
    Vec2 pointer_vector = vec2Sub(v1, v2);
    return vec2Length(pointer_vector);
}

TGAPI Vec2 vec2Clamp(Vec2 v1, float min, float max) {
    return (Vec2) {
        v1.x > min ? v1.x < max ? v1.x : max : min,
        v1.y > min ? v1.y < max ? v1.y : max : min,
      };
}

