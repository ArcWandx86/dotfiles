/* Copyright 2017 Wunder
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

enum layer_names {
	_QW,
	_GT,
	_MV,
	_NP,
	_AP,
	_MD,
	_KB,
	_PL
};

enum custom_keycodes {
	LAYER = SAFE_RANGE,
	PLOVER,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LAYER:
			if (record->event.pressed) {
				layer_move(_GT);
			} else {
				if (layer_state_is(_GT)) {
					layer_clear();
				}
			}
			break;
		case PLOVER:
			if (record->event.pressed) {
			} else {
			}
			break;
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | HOME   | DEL    | END    | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | `      | PG UP  | \      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTRL  | A      | S      | D      | F      | G      | [      | PG DN  | ]      | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | -      | UP     | =      | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LGUI   | LCTRL  | LGUI   | LALT   | LAYER  | SPACE  | LEFT   | DOWN   | RIGHT  | BACKSP | LAYER  | DEL    | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME, KC_DEL,  KC_END,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_GRV,  KC_PGUP, KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, 
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC, KC_PGDN, KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS, KC_UP,   KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
		KC_LGUI, KC_LCTL, KC_LGUI, KC_LALT, LAYER,   KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, LAYER,   KC_DEL,  KC_RALT, KC_RGUI, KC_RCTL  
	 ),

    /* GOTO
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | F1     | F2     | F3     | F4     | F5     | 6      |        | F7     | F8     | F9     | F10    | F11    | F12    |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        |        |TO(_PL) |TO(_KB) |TO(_MD) |        |        |        |        |        |TO(_MD) |TO(_KB) |TO(_PL) |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        |        |TO(_AP) |TO(_NP) |TO(_MV) |        |        |        |        |        |TO(_MV) |TO(_NP) |TO(_AP) |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        | LAYER  |        |        |        |        |        | LAYER  |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
	[_GT] = LAYOUT_ortho_5x15( /* GOTO */
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, 
		_______, _______, TO(_PL), TO(_KB), TO(_MD), _______, _______, _______, _______, _______, TO(_MD), TO(_KB), TO(_PL), _______, _______, 
		_______, _______, TO(_AP), TO(_NP), TO(_MV), _______, _______, _______, _______, _______, TO(_MV), TO(_NP), TO(_AP), _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, LAYER,   _______, _______, _______, _______, _______, LAYER,   _______, _______, _______, _______  
	),

   /* MOVEMENT
	* .--------------------------------------------------------------------------------------------------------------------------------------.
	* | ESC    | F1     | F2     | F3     | F4     | F5     | 6      |        | F7     | F8     | F9     | F10    | F11    | F12    | BACKSP |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	* |        |        |        |        |        |        |        | PG UP  |        | HOME   | PG DN  | PG UP  | END    |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	* |        |        |        |        |        |        |        | PG DN  |        | LEFT   | DOWN   | UP     | RIGHT  |        | ENTER  |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------|
	* |        |        |        |        |        |        |        | UP     |        |        | LEFT   | DOWN   | RIGHT  |        |        |
	* |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	* |        |        |        |        | MO(1)  |        | LEFT   | DOWN   | RIGHT  |        | MO(1)  |        |        |        |        |
	* '--------------------------------------------------------------------------------------------------------------------------------------'
	*/
   [_MV] = LAYOUT( /* MOVEMENT */
	   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, 
	   _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, 
	   _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_ENT,  
	   _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, 
	   _______, _______, _______, _______, LAYER,   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, LAYER,   _______, _______, _______, _______  
   ),

   /* NUMPAD
	* .--------------------------------------------------------------------------------------------------------------------------------------.
	* |        |        |        |        |        |        | NUM LK | /      | *      | -      |        |        |        |        | BACKSP |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	* |        |        |        |        |        |        | 7      | 8      | 9      | +      |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	* |        |        |        |        |        |        | 4      | 5      | 6      | =      | ENTER  |        |        |        | ENTER  |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	* |        |        |        |        |        |        | 1      | 2      | 3      | DEL    |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	* |        |        |        |        | MO(1)  | SPACE  | 0      | 0      | .      | BACKSP | MO(1)  |        |        |        |        |
	* '--------------------------------------------------------------------------------------------------------------------------------------'
	*/
   [_NP] = LAYOUT( /* NUMPAD */
	   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, 
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
	   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  
	   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
	   _______, _______, _______, _______, LAYER,   KC_SPC,  KC_P0,   KC_P0,   KC_PDOT, KC_BSPC, LAYER,   _______, _______, _______, _______  
   ),

   /* APPKEYS
	* .-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
	* | ESC         | SHFT + ESC  | ALT + LEFT  | ALT + RIGHT |             |             |             |             |             |             |             |             |             |             |             |
	* |-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+---------------------------|
	* | TAB         | ALT + UP    | ALT SHFT UP | C-A-S-UP    | SHFT + PGUP |             |             |             |             |             |             |             |             |             |             |
	* |-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+---------------------------+-------------|
	* |             | ALT + DOWN  | ALT SHFT DN | C-A-S-DOWN  | SHFT + PGDN |             |             |             |             |             |             |             |             |             |             |
	* |-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-----------------------------------------+-------------|
	* |             | CTRL + I    | CTRL SHFT E | CTRL + K    |             |             |             |             |             |             |             |             |             |             |             |
	* |-------------+-------------+-------------+-------------+-------------+---------------------------+-------------+-------------+-------------+-------------+---------------------------+-------------+-------------|
	* |             |             |             |             | MO(1)       |             |             |             |             |             | MO(1)       |             |             |             |             |
	* '-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
	*/
   [_AP] = LAYOUT( /* APPKEYS */
	   KC_ESC,       LSFT(KC_ESC), LALT(KC_LEFT),LALT(KC_RGHT),XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
	   KC_TAB,       LALT(KC_UP),  LSA(KC_UP),   MEH(KC_UP),   LSFT(KC_PGUP),XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
	   _______,      LALT(KC_DOWN),LSA(KC_DOWN), MEH(KC_UP),   LSFT(KC_PGDN),XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,      XXXXXXX,      XXXXXXX,      
	   _______,      LCTL(KC_I),   RCS(KC_E),    LCTL(KC_K),   LCTL(KC_PGUP),LCTL(KC_PGDN),XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
	   _______,      _______,      _______,      _______,      LAYER,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      LAYER,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX       
   ),

   /* MEDIA
	* .--------------------------------------------------------------------------------------------------------------------------------------.
	* | ESC    |        |        |        |        |        | SLEEP  | POWER  | BOOT   |        |MS WH L |MS CLK M|MS WH R |        | CALC   |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	* |        | VOL DN | MUTE   | VOL UP |        |        | CAP LK | NUM LK | SCR LK |MS WH U |MS CLK L| MS UP  |MS CLK R|        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	* |        | PREV   | PLAY   | NEXT   | PR SCR |        |        |        | PAUSE  |MS WH D |MS LEFT |MS DOWN |MS RIGHT|        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	* |        |        | BRI DN | BRI UP |        |        |        |        |        |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	* |        |        |        |        | MO(1)  |        |        |        |        |        | MO(1)  |        |        |        |        |
	* '--------------------------------------------------------------------------------------------------------------------------------------'
	*/
   [_MD] = LAYOUT( /* MEDIA */
	   KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, KC_PWR,  QK_BOOT, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, KC_CALC, 
	   _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, XXXXXXX, KC_CAPS, KC_NUM,  KC_SCRL, KC_WH_U, _______, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, 
	   _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______, 
	   _______, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
	   _______, _______, _______, _______, TO(_GT), _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, TO(_GT), _______, _______, _______, _______  
   ),

   /* KEYBOARD RGB
	* .--------------------------------------------------------------------------------------------------------------------------------------.
	* | ESC    | PLAIN  | BREATH |RAINBOW | SWIRL  | SNAKE  | KNIGHT | XMAS   | GRAD   | TEST   |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	* |        |        |        |        |        |        | TOGGLE | MODE - | MODE + |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	* |        |        |        |        |        | HUE +  | SAT +  | VALU + | SPD +  |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	* |        |        |        |        |        | HUE -  | SAT -  | VALU - | SPD -  |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	* |        |        |        |        | MO(1)  |        |        |        |        |        | MO(1)  |        |        |        |        |
	* '--------------------------------------------------------------------------------------------------------------------------------------'
	*/
   [_KB] = LAYOUT( /* KEYBOARD RGB */
	   KC_ESC,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_RMOD,RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYER,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYER,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  
   ),

   /* PLOVER
	* .--------------------------------------------------------------------------------------------------------------------------------------.
	* | ESC    | 1      | 2      | 3      | 4      | 5      | `      | PG UP  | \      | 6      | 7      | 8      | 9      | 0      | BACKSP |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	* | TAB    | Q      | W      | E      | R      | T      | [      | PG DN  | ]      | Y      | U      | I      | O      | P      | [      |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	* |        | A      | S      | D      | F      | G      | HOME   | UP     | END    | H      | J      | K      | L      | ;      | '      |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	* |        | Z      | X      | C      | V      | B      | LEFT   | DOWN   | RIGHT  | N      | M      | ,      | .      | /      |        |
	* |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	* |        |        |        |        | C      | V      | SPACE  | MO(1)  | BACKSP | N      | M      | ENTER  |        |        |        |
	* '--------------------------------------------------------------------------------------------------------------------------------------'
	*/
   [_PL] = LAYOUT( /* PLOVER */
	   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_PGUP, KC_BSLS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
	   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_PGDN, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, 
	   _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_UP,   KC_END,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
	   _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, KC_DOWN, KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, 
	   _______, _______, _______, _______, KC_C,    KC_V,    KC_SPC,  LAYER,   KC_BSPC, KC_N,    KC_M,    KC_ENT,  _______, _______, _______  
   )
};

