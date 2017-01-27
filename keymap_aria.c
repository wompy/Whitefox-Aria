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
#include "keymap_common.h"

#include "led_controller.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      /* Layer 0: Default Layer
      * ,-----------------------------------------------------.
      * |Esc| 1| 2| 3| 4| 5| 6| 7| 8| 9| 0| -| =| Backs  | `  |
      * |Tab  | q| w| e| r| t| y| u| i| o| [| ]|        \| Del|
      * | Caps | a| s| d| f| g| h| j| k| l| ;| '|  Return| Hme|
      * |  LShft| z| x| c| v| b| n| m| ,| .| /| RShft| Up| End|
      * |LCtrl|LGUI|LAlt|    [ ]       | F0|RCtrl||Rgt|Dwn|Lft|
      * `-----------------------------------------------------'
      */

      [0] = KEYMAP(\
        ESC, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSPC  , GRV, \
        TAB , Q, W, E, R, T, Y, U, I, O, P, LBRC,RBRC,BSLASH, DEL, \
        FN6 , A, S, D, F, G, H, J, K, L, SCLN,QUOT,    ENT, PGUP,\
        LSFT  , Z, X, C, V, B, N, M, COMM,DOT, SLSH,RSFT, UP,PGDN,\
        LCTL,LGUI,LALT,    SPC,           RALT,FN0,LEFT,DOWN,RIGHT \
      ),
      [1] = KEYMAP(\
        TRNS, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, TRNS  , INS, \
        TRNS , MPRV, MPLY, MNXT, TRNS, FN4, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,TRNS,TRNS, TRNS, \
        TRNS , MUTE, VOLD, VOLU, TRNS, FN3, TRNS, TRNS, TRNS, TRNS,TRNS,TRNS,TRNS, HOME,\
        TRNS  , FN1, FN2, TRNS, TRNS, FN5, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS, PGUP,END,\
        TRNS,TRNS,TRNS,    TRNS,      TRNS,TRNS,HOME,PGDN,END \
      ),
};

#define ACTION_LEDS_ALL 1
#define ACTION_LEDS_GAME 2



/* custom action function */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  switch(id) {
    case ACTION_LEDS_ALL:
        if(record->event.pressed) {
          // signal the LED controller thread
          chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
        }
      break;
    case ACTION_LEDS_GAME:
      if(record->event.pressed) {
        // signal the LED controller thread
        chMBPost(&led_mailbox, LED_MSG_GAME_TOGGLE, TIME_IMMEDIATE);
      }
      break;
  }
}

/* Macro definitions */ 
enum macro_id {
    STEVE,

}; 

 const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    //uint8_t tap_count = record->tap_count;

    switch (id) {
        case STEVE:
            return (event.pressed ?
                    MACRO( T(T), T(V), T(2), T(4), T(6), T(8), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
} 
const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_FUNCTION(ACTION_LEDS_ALL),
    [2] = ACTION_FUNCTION(ACTION_LEDS_GAME),
    [5] = ACTION_MACRO(STEVE), 
    [6] = ACTION_LAYER_TAP_KEY(1, KC_CAPS),

};

    
