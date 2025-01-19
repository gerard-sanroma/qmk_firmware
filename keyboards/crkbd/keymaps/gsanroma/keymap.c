/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   MO(1),  KC_SPC,     KC_SPC,   MO(2), KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX, KC_PGDN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______,  KC_ENT,     KC_ENT,   MO(3), KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   MO(3),  KC_ENT,     KC_ENT, _______, KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MS_ACL0, MS_ACL1, MS_ACL2, MS_WHLD, XXXXXXX, XXXXXXX,                      MS_WHLU, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, MS_WHLL, MS_BTN2, MS_BTN1, MS_WHLR,                      MS_LEFT, MS_DOWN,  MS_UP,  MS_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______,  KC_SPC,     KC_ENT, _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  )
};


// tmux actions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Check for Alt combinations
        if (get_mods() & MOD_MASK_ALT) {
            switch (keycode) {

                // detach
                case KC_D: // Alt-d
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_D);
                    return false;

                // move along windows
                case KC_LBRC: // Alt-[
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_LBRC);
                    return false;

                case KC_RBRC: // Alt-]
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_RBRC);
                    return false;

                // move along panes
                //
                case KC_K: // Alt-k
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_UP);
                    return false;

                case KC_J: // Alt-j
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_DOWN);
                    return false;

                case KC_H: // Alt-h
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_LEFT);
                    return false;

                case KC_L: // Alt-l
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_RGHT);
                    return false;

                // maximize/minimize pane
                //
                case KC_Z: // Alt-z
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_Z);
                    return false;

                // navigation panel
                //
                case KC_W: // Alt-w
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_W);
                    return false;

                // rename session (assumes bind $ in .tmux.conf)
                //
                case KC_DLR: // Alt-$
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LSFT);    // Press and hold the Shift key
                    tap_code(KC_4);
                    unregister_code(KC_LSFT);  // Release the Shift key
                    return false;

                // rename window
                //
                case KC_COMM: // Alt-,
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_COMM);
                    return false;

                // new window
                //
                case KC_N: // Alt-N
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_C);
                    return false;

                // mark window
                //
                case KC_M: // Alt-M
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_M);
                    return false;

                // join panel (assumes bind @ in .tmux.conf)
                //
                case KC_AT: // Alt-@
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LSFT);    // Press and hold the Shift key
                    tap_code(KC_2);
                    unregister_code(KC_LSFT);  // Release the Shift key
                    return false;

                // del pane
                //
                case KC_X: // Alt-x
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_X);
                    return false;

                // vim mode
                //
                case KC_ESC: // Alt-esc
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    tap_code(KC_ESC);
                    return false;

                // new panes (hor and vert)
                //
                case KC_MINS: // Alt--
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LSFT);    // Press and hold the Shift key
                    tap_code(KC_QUOT);
                    unregister_code(KC_LSFT);  // Release the Shift key
                    return false;

                case KC_PIPE: // Alt-|
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LSFT);    // Press and hold the Shift key
                    tap_code(KC_5);
                    unregister_code(KC_LSFT);  // Release the Shift key
                    return false;

                // resize panes
                //
                case KC_UP: // Alt-Up Arrow
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LALT);
                    tap_code(KC_UP);
                    unregister_code(KC_LALT);
                    return false;

                case KC_DOWN: // Alt-Down Arrow
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LALT);
                    tap_code(KC_DOWN);
                    unregister_code(KC_LALT);
                    return false;

                case KC_LEFT: // Alt-Left Arrow
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LALT);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LALT);
                    return false;

                case KC_RGHT: // Alt-Right Arrow
                    unregister_mods(MOD_MASK_ALT); // Unregister Alt
                    register_code(KC_LCTL);
                    tap_code(KC_B);
                    wait_ms(10);  // wait a small delay
                    unregister_code(KC_LCTL);
                    register_code(KC_LALT);
                    tap_code(KC_RGHT);
                    unregister_code(KC_LALT);
                    return false;
            }
        }

    }
    return true;
}

