#ifndef VECTOR_H
#define VECTOR_H

#include "defines.h"

/**
 * @brief   Represents a 2-Dimensional Vector, with floating point components
 */
typedef struct Vec2 {
    float x;    /**< X Component */
    float y;    /**< Y Component */
} Vec2;


/**
 * @returns 2 Dimensional vector with both components set to zero
 */
TGAPI Vec2 vec2GetZero();

/**
 * @brief   Adds two vectors
 * @param   v1: Vec2, can be point or direction
 * @param   v2: Vec2, can be point or direction
 * @returns Vector sum of two 2D Vectors
 */
TGAPI Vec2 vec2Add(Vec2 v1, Vec2 v2);

/**
 * @brief   Subtract a vector from another
 * @param   v1: Vec2, can be point or direction
 * @param   v2: Vec2, can be point or direction
 * @returns Vector difference of two 2D Vectors
 */
TGAPI Vec2 vec2Sub(Vec2 v1, Vec2 v2);

/**
 * @brief   Add a scalar to the components of a vector
 * @param   v1: Vec2, can be point or direction
 * @param   scalar: float, value to add to components
 * @returns 2D Vector, with the scalar parameter added to the input vector's components
 */
TGAPI Vec2 vec2ScalarAdd(Vec2 v1, float scalar);

/**
 * @brief   Subtract a scalar from the components of a vector
 * @param   v1: Vec2, can be point or direction
 * @param   scalar: float, value to subtract from components
 * @returns 2D vector, with the scalar parameter subtracted from the input vector's components
 */
TGAPI Vec2 vec2ScalarSub(Vec2 v1, float scalar);

/**
 * @brief   Scale a vector by a scalar
 * @param   v1: Vec2, can be point or direction
 * @param   scalar: float, value to add to components
 * @returns 2D vector, with the scalar parameter subtracted from the input vector's components
 */
TGAPI Vec2 vec2Scale(Vec2 v1, float scalar);

/**
 * @brief   Dot/scalar multiplication operation on two vectors
 * @param   v1: Vec2, can be point or direction
 * @param   v2: Vec2, can be point or direction
 * @returns Scalar product of two 2D Vectors
 */
TGAPI float vec2Dot(Vec2 v1, Vec2 v2);

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
TGAPI float vec2Cross(Vec2 v1, Vec2 v2);

/**
 * @brief   get length of a vector
 * @param   v1: Vec2, can be point or direction
 * @returns Returns length of input 2D Vector
 */
TGAPI float vec2Length(Vec2 v1);

/**
 * @brief   get the squared length of a vector
 * @param   v1: Vec2, can be point or direction
 * @returns Returns the squared length of input 2D Vector
 */
TGAPI float vec2LengthSquared(Vec2 v1);

/**
 * @brief   normalize a vector
 * @param   v1: Vec2, can be point or direction
 * @returns Returns normalized input Vector
 */
TGAPI Vec2 vec2Normalize(Vec2 v1);

/**
 * @brief   clamps each component of a Vec2 between a minimum and maximum value
 * @param   v1: Vec2, input vector to be clamped
 * @param   min: float, minimum allowed value for each component
 * @param   max: float, maximum allowed value for each component
 * @returns Returns a Vec2 where each component is clamped to [min, max]
 */
TGAPI Vec2 vec2Clamp(Vec2 v1, float min, float max);

/**
 * @brief   linearly interpolates between two Vec2 vectors or points
 * @param   v1: Vec2, start vector
 * @param   v2: Vec2, end vector
 * @param   t: float, interpolation factor (between 0 and 1)
 * @returns Returns the interpolated Vec2 between a and b by t
 */
TGAPI Vec2 vec2Lerp(Vec2 v1, Vec2 v2, float t);

/**
 * @brief   reflects a vector v1 across a surface normal n
 * @param   v1: Vec2, input vector to reflect
 * @param   n: Vec2, normalized surface normal vector
 * @returns Returns the reflection of v1 w.r.t n
 * @note    The vector n must be normalized (unit length)
 */
TGAPI Vec2 vec2Reflect(Vec2 v1, Vec2 n);

/**
 * @brief   projects vector v1 onto vector v2
 * @param   v1: Vec2, vector to be projected
 * @param   v2: Vec2, vector to project onto
 * @returns Returns the projection of v1 onto v2
 * @note    Projection gives the component of v1 that lies in the direction of v2.
 *          The result is a vector parallel to v2.
 */
TGAPI Vec2 vec2Projection(Vec2 v1, Vec2 v2);

/**
 * @brief   calculates the distance between two Vec2 vectors or points
 * @param   v1: Vec2, first point
 * @param   v2: Vec2, second point
 * @returns Returns the Euclidean distance between v1 and v2
 * @note    Equivalent to the length of the vector from v2 to v1
 */
TGAPI float vec2DistanceFromPoint(Vec2 v1, Vec2 v2);

/**
 * @brief   computes the angle of a Vec2 from the positive X-axis
 * @param   v1: Vec2, input vector
 * @returns Returns the angle in radians in the range [0, 2π)
 * @note    Uses `atan2f` internally to handle all quadrants. Angle is measured counter-clockwise.
 */
TGAPI float vec2Angle(Vec2 v1);

/**
 * @brief   computes a vector perpendicular to the input Vec2
 * @param   v1: Vec2, input vector
 * @returns Returns a Vec2 that is perpendicular to v1
 * @note    The returned vector is v1 rotated +90° counterclockwise (x, y) → (−y, x)
 */
TGAPI Vec2 vec2Perpendicular(Vec2 v1);

/**
 * @brief   normalizes a Vec2 in place
 * @param   v1: Vec2* pointer, to the vector to normalize
 * @note    If the vector has zero length, it is left unchanged to avoid division by zero.
 */
TGAPI void vec2Normalized(Vec2 *v1);

#endif // VECTOR_H