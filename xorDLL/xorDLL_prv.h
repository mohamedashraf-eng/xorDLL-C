/**
 * @file xorDLL_prv.h
 * @author Mohamed Wx (wx@wx.com)
 * @brief The private header for the xorDLL library
 * @version 0.1
 * @date 2023-01-21
 *
 * @copyright Copyright (c) Mohamed Ashraf Wx, 2023
 *
 * @attention
 * Copyright [2023] [Mohamed Ashraf Wx]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
/** @defgroup Header guards */
#ifndef __XORDLL_PRV_H__
#define __XORDLL_PRV_H__
/** @def C++ Guards */
#ifdef __cplusplus
extern "C" {
#endif

/*
 * ================================================================================================================================
 * -> Private Macros
 * ================================================================================================================================
 **/

/**
 * @defgroup Logging/Debugging Macros
 *
 * @brief Simple debugging/logging function like macro to trace the code.
 */
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_INACTIVE)
/** @brief Function like macro used for debug messages
 * 	@attention
 * 		This function like macro is compatible starts from GCC-89/90
 */
#define _wxtrace_log(format, ...)                                              \
  ({                                                                           \
    fprintf(stderr,                                                            \
            "\n=> File: %s, Function: %s, Line: %d\n DBG_MSG: " format "\n",   \
            __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);                  \
  })
#endif

#if (FULL_ASSERTION_FLAG == FULL_ASSERTION_ACTIVE)

/** @brief Function like macro used for terminating the program on assertion
 * failure
 * 	@attention
 * 		This function like macro is compatible starts from GCC-89/90
 */
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_INACTIVE)
#define exit_on_failure(_EXIT_CODE)                                            \
  ({                                                                           \
    _wxtrace_log("ASSERTION_FAILURE - EXIT_CODE=%d", (_EXIT_CODE));            \
    exit((_EXIT_CODE));                                                        \
  })
#else
#define exit_on_failure(_EXIT_CODE) ({ exit((_EXIT_CODE)); })
#endif
#define DEFAULT_EXIT_CODE (-1)
/** @brief Function like macro used for assertion statically
 * 	@attention
 * 		This function like macro is compatible starts from GCC-89/90
 */
#define STATIC_ASSERT(EXPRESSION, _EXIT_CODE)                                  \
  ({ (EXPRESSION) ? (NULL) : (exit_on_failure(_EXIT_CODE)); })
#endif
/**
 * @def Debugging/Logging Configuration Parameters
 */
#define WXTRACE_LOG_STATE_INACTIVE (0)
#define WXTRACE_LOG_STATE_ACTIVE (1)

/**
 * @def Configuration Parameters
 *    @arg WXTRACE_LOG_STATE_ACTIVE
 *    @arg WXTRACE_LOG_STATE_INACTIVE
 */
#define WXTRACE_LOG_STATE (WXTRACE_LOG_STATE_INACTIVE)
/**
 * @def Debugging/Logging Configuration Parameters
 */
#define NATIVE_PLATFORM (0)
#define CROSS_PLATFORM (1)
/**
 * @def Configuration Parameters
 *    @arg CROSS_PLATFORM_NO
 *    @arg CROSS_PLATFORM_YES
 */
#define CURRENT_PLATFORM (NATIVE_PLATFORM)

/**
 * @defgroup Private compiler specifications macro
 *
 */
#define _FORCE_INLINE __attribute__((always_inline))
#define _FORCE_CONST __attribute__((const))
#define _INLINE inline
#define _LOCAL static
#define _LOCAL_INLINE _LOCAL _INLINE
#define _CONST const

/*
 * ================================================================================================================================
 * -> Private Datatypes
 * ================================================================================================================================
 **/

/**
 * @defgroup Platform specific datatypes
 *
 * @brief This type defined is used to be easly changable
 *        reusable (not dependent) on any platform.
 */
/** @brief Using user defined types */
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;
typedef long double float128;

/*
 * ================================================================================================================================
 * -> Private Enums
 * ================================================================================================================================
 **/

/*
 * ================================================================================================================================
 * -> Private Structs
 * ================================================================================================================================
 **/

/*
 * ================================================================================================================================
 * -> Private Functions Declaration
 * ================================================================================================================================
 **/

/** @def C++ Guards */
#ifdef __cplusplus
}
#endif

#endif /* __XORDLL_PRV_H__ */
