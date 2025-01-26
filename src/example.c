#include "test_framework.h"

int add(int a, int b) {
    return a + b;
}

char* concatenate(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = malloc(len1 + len2 + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

void test_addition() {
    ASSERT_EQ(4, add(2, 2));
    ASSERT_EQ(0, add(0, 0));
    ASSERT_EQ(-2, add(-1, -1));
    ASSERT_EQ(1000, add(500, 500));
}

void test_string_operations() {
    char* result = concatenate("Hello, ", "World!");
    ASSERT_STR_EQ("Hello, World!", result);
    free(result);
    
    result = concatenate("", "Empty");
    ASSERT_STR_EQ("Empty", result);
    free(result);
}

int main() {
    TEST_SUITE_BEGIN();
    
    RUN_TEST(test_addition);
    RUN_TEST(test_string_operations);
    
    TEST_SUITE_END();
    return 0;
}
