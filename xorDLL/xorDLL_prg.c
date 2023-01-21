/**
 * @file xorDLL_prg.c
 * @author Mohamed Ashraf (wx@wx.com)
 * @brief The implementation file for the xorDLL library.
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
/*
 * ================================================================================================================================
 * -> Included Headers
 * ================================================================================================================================
 **/

#include "xorDLL_int.h"
#include "xorDLL_prv.h"

#if (CURRENT_PLATFORM == NATIVE_PLATFORM)

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#endif

/*
 * ================================================================================================================================
 * -> Private Datatypes (Localized global)
 * ================================================================================================================================
 **/

/*
 * ================================================================================================================================
 * -> Public Functions Implementation
 * ================================================================================================================================
 **/

/**
 * @brief Used for inital testing.
 *
 */
void portal_test(void) {

  _wxtrace_log("Working?");

  return;
}

/*
 * ================================================================================================================================
 * -> Private Functions Implementation
 * ================================================================================================================================
 **/