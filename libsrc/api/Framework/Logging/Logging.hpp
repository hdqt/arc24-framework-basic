#pragma once

#include "Helper/Logger.hpp"

#if defined(APP_OS_ANDROID)
#include <android/log.h>
#endif

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL LOG_LEVEL_DEBUG

#if LOG_LEVEL > LOG_LEVEL_DEBUG
#define PLAT_LOG_D(...)
#else
#define PLAT_LOG_D(...) __PLAT_LOG(DEBUG, __VA_ARGS__)
#endif

#if LOG_LEVEL > LOG_LEVEL_INFO
#define PLAT_LOG_I(...)
#else
#define PLAT_LOG_I(...) __PLAT_LOG(INFO, __VA_ARGS__)
#endif

#if LOG_LEVEL > LOG_LEVEL_WARN
#define PLAT_LOG_W(...)
#else
#define PLAT_LOG_W(...) __PLAT_LOG(WARN, __VA_ARGS__)
#endif

#if LOG_LEVEL > LOG_LEVEL_ERROR
#define PLAT_LOG_E(...)
#else
#define PLAT_LOG_E(...) __PLAT_LOG(ERROR, __VA_ARGS__)
#endif

#define __PLAT_LOG(level, ...) Logger::getInstance()->printPlatLog(__FILE__, __LINE__, #level, __VA_ARGS__)

#define PLAT_ASSERT(expr, message)                                                                                     \
    do                                                                                                                 \
    {                                                                                                                  \
        assert((expr) && message);                                                                                     \
    } while (0)
