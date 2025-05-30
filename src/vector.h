#ifndef VECTOR_H
#define VECTOR_H

#include "defines.h"

/**
 * @brief   Represents a 2-Dimensional Vector, with floating point components
 */
typedef struct Vector2 {
    float x;    /**< X Component */
    float y;    /**< Y Component */
} Vec2;


/**
 * @returns 2 Dimensional vector with both components set to zero
 */
TGAPI INLINE Vec2 vec2GetZero();

/**
 * @brief   Adds two vectors
 * @param   v1: Vec2, can be point or direction
 * @param   v2: Vec2, can be point or direction
 * @returns Vector sum of two 2D Vectors
 */
TGAPI INLINE Vec2 vec2Add(Vec2 v1, Vec2 v2);

/**
 * @brief   Subtract a vector from another
 * @param   v1: Vec2, can be point or direction
 * @param   v2: Vec2, can be point or direction
 * @returns Vector difference of two 2D Vectors
 */
TGAPI INLINE Vec2 vec2Sub(Vec2 v1, Vec2 v2);

/**
 * @brief   Add a scalar to the components of a vector
 * @param   v1: Vec2, can be point or direction
 * @param   scalar: float, value to add to components
 * @returns 2D Vector, with the scalar parameter added to the input vector's components
 */
TGAPI INLINE Vec2 vec2ScalarAdd(Vec2 v1, float scalar);

/**
 * @brief   Subtract a scalar from the components of a vector
 * @param   v1: Vec2, can be point or direction
 * @param   scalar: float, value to add to components
 * @returns 2D vector, with the scalar parameter subtracted from the input vector's components
 */
TGAPI INLINE Vec2 vec2ScalarSub(Vec2 v1, float scalar);

/**
 * @brief   Scale a vector by a scalar
 * @param   v1: Vec2, can be point or direction
 * @param   scalar: float, value to add to components
 * @returns 2D vector, with the scalar parameter subtracted from the input vector's components
 */
TGAPI INLINE Vec2 vec2Scale(Vec2 v1, float scalar);

/**
 * @brief   Dot/scalar multiplication operation on two vectors
 * @param   v1: Vec2, can be point or direction
 * @param   v2: Vec2, can be point or direction
 * @returns Scalar product of two 2D Vectors
 */
TGAPI INLINE float vec2Dot(Vec2 v1, Vec2 v2);

/**
 * @brief   Cross/vector multiplication operation on two vectors
 * @param   v2: Vec2, can be point or direction
 * @param   v1: Vec2, can be point or direction
 * @returns Vector product of two 2D Vectors
 * @note since the inputs are 2D vectors, the result will be a signed float
 * +ve result indicating resultant vector is out of the plane and -ve result indicating
 * resultant vector is into the plane. The value represents the area of the parallelogram
 * formed by the two vectors
 */
TGAPI INLINE float vec2Cross(Vec2 v1, Vec2 v2);

/**
 * @brief   get length of a vector
 * @param   v1: Vec2, can be point or direction
 * @returns Returns length of input 2D Vector
 */
TGAPI INLINE float vec2Length(Vec2 v1);

/**
 * @brief   get the squared length of a vector
 * @param   v1: Vec2, can be point or direction
 * @returns Returns the squared length of input 2D Vector
 */
TGAPI INLINE float vec2LengthSquared(Vec2 v1);

/**
 * @brief   normalize a vector
 * @param   v1: Vec2, can be point or direction
 * @returns Returns normalized input Vector
 */
TGAPI INLINE Vec2 vec2Normalize(Vec2 v1);

#endif // VECTOR_H