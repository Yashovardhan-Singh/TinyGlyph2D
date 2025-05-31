#include "vector.h"
#include "constants.h"

#include <math.h>

Vec2 vec2GetZero() {
    return (Vec2) { 0.0f, 0.0f };
}

Vec2 vec2Add(Vec2 v1, Vec2 v2) {
    return (Vec2) {(v1.x + v2.x), (v1.y + v2.y) };
}

Vec2 vec2Sub(Vec2 v1, Vec2 v2) {
    return (Vec2) {v1.x - v2.x,v1.y - v2.y };
}

Vec2 vec2ScalarAdd(Vec2 v1, float scalar) {
    return (Vec2) {(v1.x + scalar),(v1.y + scalar) };
}

Vec2 vec2ScalarSub(Vec2 v1, float scalar) {
    return (Vec2) {(v1.x - scalar),(v1.y - scalar) };
}

Vec2 vec2Scale(Vec2 v1, float scalar) {
    return (Vec2) {(v1.x * scalar),(v1.y * scalar) };
}

float vec2Length(Vec2 v1) {
    return sqrtf(v1.x * v1.x + v1.y * v1.y);
}


float vec2LengthSquared(Vec2 v1) {
    return (v1.x * v1.x + v1.y * v1.y);
}

Vec2 vec2Normalize(Vec2 v1) {
    float len = vec2Length(v1);
    if (!(len == 0.0f))
        return (Vec2) {(v1.x / len), (v1.y / len) };
    return v1;
}

Vec2 vec2Clamp(Vec2 v1, float min, float max) {
    return (Vec2) {
        v1.x > min ? v1.x < max ? v1.x : max : min,
        v1.y > min ? v1.y < max ? v1.y : max : min,
      };
}

Vec2 vec2Lerp(Vec2 v1, Vec2 v2, float t) {
    return (Vec2) {
        .x = v1.x + (v2.x - v1.x) * t,
        .y = v1.y + (v2.y - v1.y) * t
    };
}

float vec2Dot(Vec2 v1, Vec2 v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

// Need to make sure n is normalized assert(fabsf(vec2Length(m) - 1.0f) < EPSILON);
Vec2 vec2Reflect(Vec2 v1, Vec2 n) {
    float factor = 2.0f*vec2Dot(v1, n);
    Vec2 subvec = {n.x * factor, n.y * factor};
    return vec2Sub(v1, subvec);
}

Vec2 vec2Projection(Vec2 v1, Vec2 v2) {
    float dot = vec2Dot(v1, v2);
    float lensq = vec2LengthSquared(v2);
    float scalar = dot / lensq;
    return (Vec2) { v2.x * scalar, v2.y * scalar };
}

Vec2 vec2Perpendicular(Vec2 v1) {
    return (Vec2) { -v1.y, v1.x };
}

float vec2Cross(Vec2 v1, Vec2 v2) {
    return (v1.x * v2.y) - (v1.y * v2.x);
}

float vec2DistanceFromPoint(Vec2 v1, Vec2 v2) {
    Vec2 pointer_vector = vec2Sub(v1, v2);
    return vec2Length(pointer_vector);
}

float vec2Angle(Vec2 v1) {
    float angle = atan2f(v1.y, v1.x);
    if (angle < 0.0f)
        angle += 2.0f * PI;
    return angle;  // range: [0, 2π)
}

void vec2Normalized(Vec2 *v1) {
    float len = vec2Length(*v1);
    if (!(len == 0.0f)) {
        v1->x /= len;
        v1->y /= len;
    }
}