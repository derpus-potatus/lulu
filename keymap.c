// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | GRV  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Play  |    |  CAPS |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LCTRL|LOWER | /Space  /       \Space \  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_GRV,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,  KC_CAPS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                          KC_LALT,    KC_LCTL, LOWER,KC_SPC,   KC_SPC,   RAISE,   KC_ENT,  KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |                    |      |      |  Up  |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------| trans |    | trans |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------| PGUP | PGDN |      |      |      | trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |trans |trans | trans| / trans /       \ trans\  |trans |trans | trans |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''-------------------'
 */
[_LOWER] = LAYOUT(
  _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,  KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,  KC_NO,   KC_UP,   KC_NO,   KC_NO,  KC_F12,
  _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,  KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,  KC_NO,
  _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,    _______, KC_PGUP,KC_PGDN, KC_NO,   KC_NO,   KC_NO,  _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | trans| trans| trans| trans| trans| trans|                    | trans| trans| trans| LBRC | RBRC | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |                    |      |      |  Up  |      | Pscr |  EQL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|      | Left | Down | Right|      | Pipe |
 * |------+------+------+------+------+------| trans |    | trans |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------| Home | End  |      |      |Insert| trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |trans |trans | trans| / trans /       \ trans\  |trans |trans | trans |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''-------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______,_______,_______, _______,                      _______, _______, _______,KC_LBRC, KC_RBRC,  KC_DEL,
  _______, KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_UP,  KC_NO,   KC_PSCR,  KC_EQL,
  _______, KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,                        KC_NO,   KC_LEFT, KC_DOWN,KC_RIGHT,KC_NO,    KC_BSLS,
  _______, KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,   _______,    _______, KC_HOME, KC_END,  KC_NO,  KC_NO,   KC_INS,   _______,
                          _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET| BOOT |PAUSE |SCROLL|NUMLCK| NKRO |                    | NKRO |NUMLCK|SCROLL|PAUSE | BOOT | RESET|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DEBUG|      |      |      |      |      |                    |      |      |      |      |      | DEBUG|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTOG|bri up|hue up|sat up|spd up|      |-------.    ,-------|      |spd up|sat up|hue up|bri up|RGBTOG|
 * |------+------+------+------+------+------| trans |    | trans |------+------+------+------+------+------|
 * |RGBMOD|bri dn|hue dn|sat dn|spd dn|      |-------|    |-------|      |spd dn|sat dn|hue dn|bri dn|RGBMOD|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |trans |trans | trans| / trans /       \ trans\  |trans |trans | trans |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''-------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_RBT,  QK_BOOT,KC_PAUS, KC_SCRL, KC_NUM,  NK_TOGG,                     NK_TOGG, KC_NUM,  KC_SCRL, KC_PAUS, QK_BOOT, QK_RBT,
  DB_TOGG, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DB_TOGG,
  RGB_TOG, RGB_VAI,RGB_HUI, RGB_SAI, RGB_SPI, KC_NO,                       KC_NO,   RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI, RGB_TOG,
  RGB_MOD, RGB_VAD,RGB_HUD, RGB_SAD, RGB_SPD, KC_NO,   _______,    _______,KC_NO,   RGB_SPD, RGB_SAD, RGB_HUD, RGB_VAD, RGB_MOD,
                            _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
