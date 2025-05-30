#ifndef TESTING_H
#define TESTING_H

#include <stdio.h>
#include <math.h>

#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

#define ASSERT_EQ(expected, actual) do { \
    if ((expected) != (actual)) { \
        printf(RED "[FAIL]" RESET " %s:%d: Expected %d, got %d\n", \
            __FILE__, __LINE__, (expected), (actual)); \
        return 1; \
    } \
} while (0)

#define FLOAT_EPSILON 1e-6

#define ASSERT_FLOAT_EQ(expected, actual) do { \
    double _diff = fabs((expected) - (actual)); \
    if (_diff > FLOAT_EPSILON) { \
        printf(RED "[FAIL]" RESET " %s:%d: Expected %.6f, got %.6f (diff %.6f)\n", \
            __FILE__, __LINE__, (double)(expected), (double)(actual), _diff); \
        return 1; \
    } \
} while (0)

typedef int (*TestFunc)();

static inline int runTest(const char* name, TestFunc func) {
    int result = func();
    if (result == 0)
        printf(GREEN "[PASS]" RESET " %s\n", name);
    return result;
}

#endif //TESTING_H
