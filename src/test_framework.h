#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int total_tests;
    int passed_tests;
    int failed_tests;
    double execution_time;
} TestResult;

typedef void (*TestFunction)();

#define ASSERT_EQ(expected, actual) do { \
    if ((expected) != (actual)) { \
        printf("\x1b[31mFAILED\x1b[0m [%s:%d]: Expected %d, got %d\n", __FILE__, __LINE__, (expected), (actual)); \
        exit(1); \
    } \
} while(0)

#define ASSERT_STR_EQ(expected, actual) do { \
    if (strcmp((expected), (actual)) != 0) { \
        printf("\x1b[31mFAILED\x1b[0m [%s:%d]: Expected %s, got %s\n", __FILE__, __LINE__, (expected), (actual)); \
        exit(1); \
    } \
} while(0)

#define ASSERT_TRUE(condition) do { \
    if (!(condition)) { \
        printf("\x1b[31mFAILED\x1b[0m [%s:%d]: Condition is false\n", __FILE__, __LINE__); \
        exit(1); \
    } \
} while(0)

#define RUN_TEST(test_func) do { \
    printf("Running test: %s\n", #test_func); \
    clock_t start = clock(); \
    test_func(); \
    clock_t end = clock(); \
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; \
    printf("\x1b[32mPASSED\x1b[0m [%.4f seconds]\n\n", time_spent); \
} while(0)

#define TEST_SUITE_BEGIN() TestResult test_result = {0, 0, 0, 0}; clock_t suite_start = clock();

#define TEST_SUITE_END() do { \
    clock_t suite_end = clock(); \
    test_result.execution_time = (double)(suite_end - suite_start) / CLOCKS_PER_SEC; \
    printf("\n=== Test Suite Summary ===\n"); \
    printf("Total Tests: %d\n", test_result.total_tests); \
    printf("Passed: \x1b[32m%d\x1b[0m\n", test_result.passed_tests); \
    printf("Failed: \x1b[31m%d\x1b[0m\n", test_result.failed_tests); \
    printf("Total Time: %.4f seconds\n", test_result.execution_time); \
} while(0)

#endif
