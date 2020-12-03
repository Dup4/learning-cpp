
#ifndef __GTEST_H__
#define __GTEST_H__

#define COLOR(color, msg) "\033[0:1;" #color "m" msg "\033[0m"
#define RED(msg)    COLOR(31, msg)
#define GREEN(msg)  COLOR(32, msg)
#define YELLOW(msg) COLOR(33, msg)
#define BLUE(msg)   COLOR(34, msg)

int GTEST_CNT = 0;
int GTEST_TOT = 0;

#define EXPECT(a, comp, b) { \
    __typeof(a) __a = (a), __b = (b); \
    ++GTEST_TOT; \
    printf(BLUE("[Test %d]"), GTEST_TOT); \
    if (!((__a) comp (__b))) { \
        printf(RED(" [ FAILED ]\n")); \
        ++GTEST_CNT; \
        printf(YELLOW("%s:%d: Failure\n"), __FILE__, __LINE__); \
        printf(YELLOW("Expected: (%s) %s (%s), actual: %d vs %d\n"), #a, #comp, #b, __a, __b); \
    } else { \
        printf(GREEN(" [ PASSED ]\n")); \
    } \
}

#define EXPECT_EQ(a, b) EXPECT(a, ==, b)
#define EXPECT_NE(a, b) EXPECT(a, !=, b)
#define EXPECT_LT(a, b) EXPECT(a, <, b)
#define EXPECT_LE(a, b) EXPECT(a, <=, b)
#define EXPECT_GT(a, b) EXPECT(a, >, b)
#define EXPECT_GE(a, b) EXPECT(a, >=, b)

#define TEST(a, b) \
void gtest_##a##_##b(); \
__attribute__((constructor)) \
void reg_##a##_##b() { \
    add_test_func(gtest_##a##_##b, #a "." #b); \
} \
void gtest_##a##_##b()

struct {
    void (*func)();
    const char *func_name;
} func_arr[110];
int func_cnt = 0;

void add_test_func(void (*func)(), const char *func_name) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].func_name = func_name;
    func_cnt++;
    return ;
}

int RUN_ALL_TESTS() {
    // run each test case
    for (int i = 0; i < func_cnt; ++i) {
        GTEST_CNT = 0;
        GTEST_TOT = 0;
        printf(BLUE("[ RUN ]") " %s\n", func_arr[i].func_name);
        func_arr[i].func();
        if (GTEST_CNT == 0) {
            printf(GREEN("[PASSED ALL %d TESTS ]\n"), GTEST_TOT);
        } else {
            printf(RED("[TOTAL %d TESTS, %d PASSED, %d FAILED]\n"), GTEST_TOT, GTEST_TOT - GTEST_CNT, GTEST_CNT);
        }
    }
    return 0;
}

#endif