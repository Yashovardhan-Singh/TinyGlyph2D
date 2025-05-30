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

int test_Scale() {
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

int main() {
    int failed = 0;
    failed += runTest("test_zero", test_zero);
    failed += runTest("test_addition", test_addition);
    failed += runTest("test_subtraction", test_subtraction);
    failed += runTest("test_scalarAdd", test_scalarAdd);
    failed += runTest("test_scalarSub", test_scalarSub);
    failed += runTest("test_dot", test_dot);
    failed += runTest("test_cross", test_cross);
    failed += runTest("test_length", test_length);
    failed += runTest("test_lengthSquared", test_lengthSquared);
    failed += runTest("test_normalize", test_normalize);

    printf("\n");
    if (failed == 0)
        printf(GREEN "All Tests Passed!\n" RESET);
    else
        printf(RED "%d Test(s) Failed.\n" RESET, failed);

    return failed;
}
