#pragma once

#define FISHTTP_RESET   "\x1b[0m"
#define FISHTTP_RED     "\x1b[31m"
#define FISHTTP_MAGENTA "\x1b[35m"
#define FISHTTP_BLUE    "\x1b[34m"
#define FISHTTP_CYAN    "\x1b[36m"
#define FISHTTP_BRIGHT_RED   "\x1b[91m"
#define FISHTTP_BRIGHT_GREEN "\x1b[92m"

// Returns the filename only
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Environment
#define FISHTTP_ENV_IS_DEV  1
#define FISHTTP_ENV_IS_PROD 0

#if FISHTTP_ENV_IS_DEV
#   define FISHTTP_LOG(x, ...) \
        printf( \
            FISHTTP_CYAN "%s:" FISHTTP_BLUE "%d(" FISHTTP_CYAN "%s" FISHTTP_BLUE "): " FISHTTP_RESET x, \
            __FILENAME__, \
            __LINE__, \
            __func__, \
            ##__VA_ARGS__ \
        );
#else
#   define FISHTTP_LOG(x, ...) ((void)0)
#endif

#define FISHTTP_ASSERT(x, y) \
    if (!(x)) { \
        printf( \
            FISHTTP_RED "%s:%d(" FISHTTP_BRIGHT_RED "%s" FISHTTP_RED "): assertion failed: " FISHTTP_RESET y, \
            __FILENAME__, \
            __LINE__, \
            __func__ \
        ); \
        exit(1); \
    }
