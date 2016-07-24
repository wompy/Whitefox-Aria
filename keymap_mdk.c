/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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
#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |GRV|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| |Backs|Ins|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|Del|
     * |---------------------------------------------------------------|
     * | ESC |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
     * |---------------------------------------------------------------|
     * |Shif|   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Alt |Gui |Ctrl |         Space         |Ctrl |FN0|  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
   [0] = KEYMAP( \
       GRV, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, NO,BSPC,  INS, \
       TAB,  Q, W, E, R, T, Y, U, I, O, P, LBRC,RBRC,   BSLS,  DEL, \
       FN0,  A, S, D, F, G, H, J, K, L, SCLN,QUOT,  NO,ENT,   PGUP, \
       FN2,NO,Z, X, C, V, B, N, M, COMM,DOT,SLSH,   FN3, UP,PGDN,\
       LALT, LGUI,LCTL,      SPC,        RCTL,FN1,NO, LEFT,DOWN,RGHT \
   ),
    /* Layer 1:
     * ,---------------------------------------------------------------.
     * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |    |  |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |      |  |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |         |  |
     * |---------------------------------------------------------------|
     * |    |   |   |   |   |   |   |   |   |   |   |   |      |    |  |
     * |---------------------------------------------------------------|
     * |    |    |    |                  |    |    |    |  |   |    |  |
     * `---------------------------------------------------------------'
     */
   [1] = KEYMAP( \
       TRNS, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, TRNS, TRNS, TRNS,\
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS, \
       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME, \
       TRNS,TRNS,TRNS ,TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,TRNS,END, \
       TRNS,TRNS,TRNS,               TRNS,       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS \
   ),
};

/* id for user defined functions */
enum function_id {
    LSHIFT_LPAREN,
    RSHIFT_RPAREN,
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_ESC),
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),
    [3] = ACTION_FUNCTION_TAP(RSHIFT_RPAREN),
};

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case LSHIFT_LPAREN:
            // Shift parentheses example: LShft + tap '('
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        register_mods(MOD_BIT(KC_LSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_9);
                    unregister_code(KC_9);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                }
            }
            break;
        case RSHIFT_RPAREN:
            // Shift parentheses example: RShft + tap ')'
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        register_mods(MOD_BIT(KC_RSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_RSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    register_code(KC_0);
                    unregister_code(KC_0);
                    del_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_RSHIFT));
                }
            }
            break;
    }
}
