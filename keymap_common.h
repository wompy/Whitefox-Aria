/*
Copyright 2016 November Taylor Dickson

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "action_util.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

 /*
  * Notes:
  * How to generate this file:
  * 1. Flash Keyboard with semi working tmk Build
  * 2. Launch  ./hid_listen
  * 3. Enter debug mode on keyboard (magic + d)
  * 4. Enter Matrix Debugging (magic + x)
  * 5. Press Every Single Key
  * Key code is a combo of Row and Colum from output, ex:
  *  r/c 01234567
  *  00: 00000000
  *  10: 00000000
  *  20: 00000000
  *  30: 00000000
  *  40: 00000000
  *  50: 00000001 <- This is K57, in our case right arrow
  *  60: 00000000
  *  70: 00000000
  *  80: 00000000
  *
  * Useful Links:
  * 1. How to Build Your Own Firmware, useful for understanding pin and KC_## section
  *   Link - https://deskthority.net/workshop-f7/how-to-build-your-very-own-keyboard-firmware-t7177.html#p141386
  * 2. TMK Wiki:
  *   Link - https://github.com/tmk/tmk_keyboard/wiki
  */

 /*Whitefox Aria
  * Note the following keys do not exist:
  * k74
  * k25
  * k47
  * k41
  *
  * ,-----------------------------------------------------.
  * |Esc| 1| 2| 3| 4| 5| 6| 7| 8| 9| 0| -| =| Backs  | `  |
  * |Tab  | q| w| e| r| t| y| u| i| o| [| ]|        \| Del|
  * | Caps | a| s| d| f| g| h| j| k| l| ;| '|  Return| Hme|
  * |  LShft| z| x| c| v| b| n| m| ,| .| /| RShft| Up| End|
  * |LCtrl|LGUI|LAlt|    [ ]       | F0|RCtrl||Rgt|Dwn|Lft|
  * `-----------------------------------------------------'
  */

 #define KEYMAP( \
   K00,K10, K20, K30, K40, K50, K60, K70, K80, K01, K11, K21, K31,     K51, K61, \
   K71  ,K81, K02, K12, K22, K32, K42, K52, K62, K72, K82, K03, K13,   K23, K33, \
   K43   ,K53, K63, K73, K83, K04, K14, K24, K34, K44, K54, K64,       K84, K05, \
   K15    , K35, K45, K55, K65, K75, K85, K06, K16, K26, K36,     K46, K56, K66, \
   K76 , K86, K07, K17                               ,K27, K37,   K57, K67, K77  \
 ) { \
   { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07 }, \
   { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
   { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24,    KC_NO, KC_##K26, KC_##K27 }, \
   { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37 }, \
   { KC_##K40, KC_NO, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46,    KC_NO }, \
   { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
   { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
   { KC_##K70, KC_##K71, KC_##K72, KC_##K73,    KC_NO, KC_##K75, KC_##K76, KC_##K77 }, \
   { KC_##K80, KC_##K81, KC_##K82, KC_##K83, KC_##K84, KC_##K85, KC_##K86,     KC_NO}  \
 }

 #endif
