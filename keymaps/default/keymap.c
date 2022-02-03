/* Copyright 2020 Neil Brian Ramirez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include QMK_KEYBOARD_H

/*
#define _BASE 0
#define _RAISE 1
#define _LOWER 2
*/

enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
};

// Tap Dance declarations
enum {
    TD_HIDE_SHOW,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for WIN+M, twice for WIN+SHIFT+M
    [TD_HIDE_SHOW] = ACTION_TAP_DANCE_DOUBLE(G(KC_M), RSG(KC_M)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		         MO(_RAISE),  KC_4,  KC_5,    KC_6,
			     MO(_LOWER),  KC_1,  KC_2,    KC_3
    ),
	[_RAISE] = LAYOUT(
		         _______,  KC_0,  KC_MINUS,KC_EQUAL,
			     _______,  KC_7,  KC_8,	   KC_9
    ),
	[_LOWER] = LAYOUT(
		         _______,  KC_Q,  KC_W,   KC_E,
			     _______,  KC_A,  KC_S,   KC_D
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code_delay(KC_VOLU, 10);
  } else {
    tap_code_delay(KC_VOLD, 10);
  }
	return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                tap_code16(KC_SPACE);
            } else {
            }
			break;
        }
	}
    return true;
}
