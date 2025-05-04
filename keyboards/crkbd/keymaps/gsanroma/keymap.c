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
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
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
      KC_CAPS, XXXXXXX, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   MO(3),  KC_ENT,     KC_ENT, _______, KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, MS_ACL1, MS_ACL2, MS_WHLD, XXXXXXX, XXXXXXX,                      MS_WHLU, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
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
static void perform_tmux_action(uint16_t keycode, bool press_shift, bool press_alt) {
    unregister_mods(MOD_MASK_ALT); // Unregister Alt
    register_code(KC_LCTL);
    tap_code(KC_B);
    wait_ms(10);  // wait a small delay
    unregister_code(KC_LCTL);

    if (press_shift) {
        register_code(KC_LSFT);   // Press and hold Shift if needed
    }
    if (press_alt) {
        register_code(KC_LALT);   // Press and hold Alt if needed
    }

    tap_code(keycode);  // Tap the specified keycode

    if (press_shift) {
        unregister_code(KC_LSFT); // Release Shift if it was pressed
    }
    if (press_alt) {
        unregister_code(KC_LALT); // Release Alt if it was pressed
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Check for Alt combinations
        if (get_mods() & MOD_MASK_ALT) {
            switch (keycode) {
                // detach  // Alt-d
                case KC_D:    return perform_tmux_action(KC_D, false, false), false;
                // move along windows
                // Alt-[
                case KC_LBRC: return perform_tmux_action(KC_LBRC, false, false), false;
                // Alt-]
                case KC_RBRC: return perform_tmux_action(KC_RBRC, false, false), false;
                // move along panes
                // Alt-k
                case KC_K:    return perform_tmux_action(KC_UP, false, false), false;
                // Alt-j
                case KC_J:    return perform_tmux_action(KC_DOWN, false, false), false;
                // Alt-h
                case KC_H:    return perform_tmux_action(KC_LEFT, false, false), false;
                // Alt-l
                case KC_L:    return perform_tmux_action(KC_RGHT, false, false), false;
                // maximize/minimize pane
                //
                // Alt-z
                case KC_Z:    return perform_tmux_action(KC_Z, false, false), false;
                // navigation panel
                //
                // Alt-w
                case KC_W:    return perform_tmux_action(KC_W, false, false), false;
                // Alt-s
                case KC_S:    return perform_tmux_action(KC_S, false, false), false;
                // rename session (assumes bind $ in .tmux.conf)
                //
                // Alt-$
                case KC_DLR:  return perform_tmux_action(KC_4, true, false), false;
                // rename window
                //
                // Alt-,
                case KC_COMM: return perform_tmux_action(KC_COMM, false, false), false;
                // new window
                //
                // Alt-N
                case KC_N:    return perform_tmux_action(KC_C, false, false), false;
                // mark window
                //
                // Alt-M
                case KC_M:    return perform_tmux_action(KC_M, false, false), false;
                // join panel (assumes bind @ in .tmux.conf)
                //
                // Alt-@
                case KC_AT:   return perform_tmux_action(KC_2, true, false), false;
                // del pane
                //
                // Alt-x
                case KC_X:    return perform_tmux_action(KC_X, false, false), false;
                // vim mode
                //
                // Alt-esc
                case KC_ESC:  return perform_tmux_action(KC_ESC, false, false), false;
                // new panes (hor and vert)
                //
                // Alt--
                case KC_MINS: return perform_tmux_action(KC_QUOT, true, false), false;
                // Alt-|
                case KC_PIPE: return perform_tmux_action(KC_5, true, false), false;
                // resize panes
                //
                // Alt-Up Arrow
                case KC_UP:   return perform_tmux_action(KC_UP, false, true), false;
                // Alt-Down Arrow
                case KC_DOWN: return perform_tmux_action(KC_DOWN, false, true), false;
                // Alt-Left Arrow
                case KC_LEFT: return perform_tmux_action(KC_LEFT, false, true), false;
                // Alt-Right Arrow
                case KC_RGHT: return perform_tmux_action(KC_RGHT, false, true), false;
                // tmux plugins
                // Alt-f (tmux-fingers)
                case KC_F:    return perform_tmux_action(KC_F, false, false), false;
            }
        }
    }
    return true;
}
