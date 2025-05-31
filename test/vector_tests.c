#include "testing_framework.h"
#include "../src/vector.h"

int test_zero() {
    Vec2 z = vec2GetZero();
    ASSERT_EQ(z.x, 0);
    ASSERT_EQ(z.y, 0);
    return 0;
}

int test_addition() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    Vec2 b = (Vec2) { 2.0f, 2.0f };
    Vec2 sum = vec2Add(a, b);
    ASSERT_EQ(sum.x, 3);
    ASSERT_EQ(sum.y, 3);
    return 0;
}

int test_subtraction() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    Vec2 b = (Vec2) { 2.0f, 2.0f };
    Vec2 sub = vec2Sub(a, b);
    ASSERT_EQ(sub.x, -1);
    ASSERT_EQ(sub.y, -1);
    return 0;
}

int test_scalarAdd() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    float f = 4.0f;
    Vec2 final = vec2ScalarAdd(a, f);
    ASSERT_EQ(final.x, 5);
    ASSERT_EQ(final.y, 5);
    return 0;
}

int test_scalarSub() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    float f = 4.0f;
    Vec2 final = vec2ScalarSub(a, f);
    ASSERT_EQ(final.x, -3);
    ASSERT_EQ(final.y, -3);
    return 0;
}

int test_scale() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    float f = 4.0f;
    Vec2 final = vec2Scale(a, f);
    ASSERT_EQ(final.x, 4);
    ASSERT_EQ(final.y, 4);
    return 0;
}

int test_dot() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    Vec2 b = (Vec2) { 2.0f, 2.0f };
    float dot = vec2Dot(a, b);
    ASSERT_EQ(dot, 4);
    return 0;
}

int test_cross() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    Vec2 b = (Vec2) { 2.0f, 2.0f };
    float cross = vec2Cross(a, b);
    ASSERT_EQ(cross, 0);
    return 0;
}

int test_length() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    float len = vec2Length(a);
    ASSERT_FLOAT_EQ(len, 1.414213562);
    return 0;
}

int test_lengthSquared() {
    Vec2 a = (Vec2) { 1.0f, 1.0f };
    float len = vec2LengthSquared(a);
    ASSERT_EQ(len, 2);
    return 0;
}

int test_normalize() {
    Vec2 a = (Vec2) { 2343215.0f, 5465754.0f };
    Vec2 normal = vec2Normalize(a);
    ASSERT_FLOAT_EQ(normal.x, 0.394025701008114);
    ASSERT_FLOAT_EQ(normal.y, 0.919099421686829);
    return 0;
}

int test_distanceFromPoint() {
    Vec2 a = (Vec2){ 0.0f, 0.0f };
    Vec2 b = (Vec2){ 3.0f, 4.0f };
    float dist = vec2DistanceFromPoint(a, b);
    ASSERT_FLOAT_EQ(dist, 5.0);

    Vec2 c = (Vec2){ -2.5f, 7.1f };
    float dist2 = vec2DistanceFromPoint(c, c);
    ASSERT_FLOAT_EQ(dist2, 0.0);

    return 0;
}

int test_clamp() {
    Vec2 a = (Vec2){ 2.0f, -1.0f };
    Vec2 clamped = vec2Clamp(a, 0.0f, 1.0f);
    ASSERT_FLOAT_EQ(clamped.x, 1.0);
    ASSERT_FLOAT_EQ(clamped.y, 0.0);

    Vec2 b = (Vec2){ 0.5f, 0.8f };
    Vec2 clamped2 = vec2Clamp(b, 0.0f, 1.0f);
    ASSERT_FLOAT_EQ(clamped2.x, 0.5);
    ASSERT_FLOAT_EQ(clamped2.y, 0.8);

    return 0;
}

int test_lerp() {
    Vec2 a = (Vec2){ 0.0f, 0.0f };
    Vec2 b = (Vec2){ 2.0f, 2.0f };
    Vec2 mid = vec2Lerp(a, b, 0.5f);
    ASSERT_FLOAT_EQ(mid.x, 1.0);
    ASSERT_FLOAT_EQ(mid.y, 1.0);

    Vec2 zero = vec2Lerp(a, b, 0.0f);
    ASSERT_FLOAT_EQ(zero.x, 0.0);
    ASSERT_FLOAT_EQ(zero.y, 0.0);

    Vec2 one = vec2Lerp(a, b, 1.0f);
    ASSERT_FLOAT_EQ(one.x, 2.0);
    ASSERT_FLOAT_EQ(one.y, 2.0);

    return 0;
}

int test_reflect() {
    Vec2 incoming = (Vec2){ 1.0f, -1.0f };
    Vec2 normal = (Vec2){ 0.0f, 1.0f }; // already normalized
    Vec2 refl = vec2Reflect(incoming, normal);
    ASSERT_FLOAT_EQ(refl.x, 1.0);
    ASSERT_FLOAT_EQ(refl.y, 1.0);

    Vec2 n2 = (Vec2){ 0.70710678f, 0.70710678f };
    Vec2 inc2 = (Vec2){ 1.0f, 0.0f };
    Vec2 refl2 = vec2Reflect(inc2, n2);
    ASSERT_FLOAT_EQ(refl2.x, 0.0);
    ASSERT_FLOAT_EQ(refl2.y, 1.0);

    return 0;
}

int test_projection() {
    Vec2 v1 = (Vec2){ 2.0f, 0.0f };
    Vec2 v2 = (Vec2){ 1.0f, 0.0f };
    Vec2 proj = vec2Projection(v1, v2);
    ASSERT_FLOAT_EQ(proj.x, 2.0);
    ASSERT_FLOAT_EQ(proj.y, 0.0);

    Vec2 v3 = (Vec2){ 1.0f, 1.0f };
    Vec2 v4 = (Vec2){ 0.0f, 2.0f };
    Vec2 proj2 = vec2Projection(v3, v4);
    ASSERT_FLOAT_EQ(proj2.x, 0.0);
    ASSERT_FLOAT_EQ(proj2.y, 1.0);

    return 0;
}

int test_perpendicular() {
    Vec2 v1 = (Vec2){ 1.0f, 0.0f };
    Vec2 p1 = vec2Perpendicular(v1);
    ASSERT_FLOAT_EQ(p1.x, 0.0);
    ASSERT_FLOAT_EQ(p1.y, 1.0);

    Vec2 v2 = (Vec2){ 0.0f, 1.0f };
    Vec2 p2 = vec2Perpendicular(v2);
    ASSERT_FLOAT_EQ(p2.x, -1.0);
    ASSERT_FLOAT_EQ(p2.y, 0.0);

    return 0;
}

int test_angle() {
    Vec2 v1 = (Vec2){ 1.0f, 0.0f };
    float a1 = vec2Angle(v1);
    ASSERT_FLOAT_EQ(a1, 0.0);

    Vec2 v2 = (Vec2){ 0.0f, 1.0f };
    float a2 = vec2Angle(v2);
    ASSERT_FLOAT_EQ(a2, (PI / 2.0));

    Vec2 v3 = (Vec2){ -1.0f, 0.0f };
    float a3 = vec2Angle(v3);
    ASSERT_FLOAT_EQ(a3, (double)PI);

    Vec2 v4 = (Vec2){ 0.0f, -1.0f };
    float a4 = vec2Angle(v4);
    ASSERT_FLOAT_EQ(a4, (3.0 * PI / 2.0));

    return 0;
}

int test_normalize_in_place() {
    Vec2 v = (Vec2){ 3.0f, 4.0f };
    vec2Normalized(&v);
    ASSERT_FLOAT_EQ(v.x, 0.6);
    ASSERT_FLOAT_EQ(v.y, 0.8);

    // Vec2 zero = (Vec2){ 0.0f, 0.0f };
    // vec2Normalized(&zero);
    // ASSERT_FLOAT_EQ(zero.x, 0.0);
    // ASSERT_FLOAT_EQ(zero.y, 0.0);

    return 0;
}

int main() {
    int failed = 0;
    failed += runTest("test_zero", test_zero);
    failed += runTest("test_addition", test_addition);
    failed += runTest("test_subtraction", test_subtraction);
    failed += runTest("test_scalarAdd", test_scalarAdd);
    failed += runTest("test_scalarSub", test_scalarSub);
    failed += runTest("test_scale", test_scale);
    failed += runTest("test_dot", test_dot);
    failed += runTest("test_cross", test_cross);
    failed += runTest("test_length", test_length);
    failed += runTest("test_lengthSquared", test_lengthSquared);
    failed += runTest("test_normalize", test_normalize);
    failed += runTest("test_clamp", test_clamp);
    failed += runTest("test_lerp", test_lerp);
    failed += runTest("test_reflect", test_reflect);
    failed += runTest("test_projection", test_projection);
    failed += runTest("test_perpendicular", test_perpendicular);
    failed += runTest("test_angle", test_angle);
    failed += runTest("test_normalize_in_place", test_normalize_in_place);
    failed += runTest("test_distanceFromPoint", test_distanceFromPoint);

    printf("\n");
    if (failed == 0)
        printf(GREEN "All Tests Passed!\n" RESET);
    else
        printf(RED "%d Test(s) Failed.\n" RESET, failed);

    return failed;
}