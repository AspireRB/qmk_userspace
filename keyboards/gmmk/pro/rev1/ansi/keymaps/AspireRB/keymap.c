/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layout
     *
     * ,-------------------------------------------------------------------------------------------------------------.
     * | Esc  ||  F1  |  F2  |  F3  |  F4  ||  F5  |  F6  |  F7  |  F8  ||  F9  | F10  | F11  | F12  || Del || Mute |
     * |=============================================================================================================|
     * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _ |  = + |  Backspc || Home  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |   Tab   |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | [ }  | ] }  |  \ |  || PgUp |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
     * |  Capslock  |  A   |  S   |  D   |  F  |  G   |  H   |  J   |  K   |  L   | ; :  | ' "  |    Enter   || PgDn |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * |    LShift    |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | , <  | . >  | / ?  | RShift ||  Up  || End  |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  Ctrl  |   Win  |  LAlt  |               Space                  | RAlt |  Fn  | Ctrl || Left | Down | Rght |
     * `------------------------------------------------------------------------------------------------------------'
     */

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        LT(2,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, LT(1,KC_APP),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* FN1 Layout
     *
     * ,-------------------------------------------------------------------------------------------------------------.
     * |EECLR  ||MyCmp |Calc | BriD | BriU ||MdPrv |MdNxt |MdPly |MdStp ||VolDn |VolUp |Mute |Insert ||PrScr ||Sleep |
     * |=============================================================================================================|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ________ || ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |  ______ |RGBSAD|RGBVAI|RGBSAI| NKRO | ____ |YAHOO | ____ | ____ |OUTLK | ____ | ____ | ____ |QK_BOOT|| ____ |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
     * |  Capslock  |RGBHUD|RGBVAD|RGBHUI| ____|GMAIL |HTMAIL| ____ | ____ | ____ | ____ | ____ | __________ || ____ |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * |  __________  |RGBNIT| ____ | ____ | ____ | ____ |NumLk | ____ | ____ |DOTCOM| ____ | ______ ||RGBMOD|| ____ |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  ____  | WinKyLk |  ____  |               _____                  | ____ | ____ | ____ ||RGBSPD|RGBRMD|RGBSPI|
     * `------------------------------------------------------------------------------------------------------------'
     */

    [1] = LAYOUT(
        EE_CLR,   KC_MYCM, KC_CALC, KC_BRID, KC_BRIU, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_VOLD, KC_VOLU, KC_MUTE, KC_INS, KC_PSCR,           KC_SLEP,
        _______,  _______, _______, _______, _______, _______ ,_______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,  RGB_SAD, RGB_VAI, RGB_SAI, NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        KC_CAPS,  RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, QK_BOOT, KC_NUM,  _______, _______, _______,  _______,          _______, RGB_MOD, _______,
        _______, GU_TOGG, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    /* _NUMPADMOUSE Layout
     *  Note: A symbol preceded by "P" is a Numpad-encoded version of the key -- any app that differentiates will recognize the char as coming from a physical numpad.
     * ,-------------------------------------------------------------------------------------------------------------.
     * | ____ || ____ | ____ | ____ | ____ || ____ | ____ | ____ | ____ || ____ | ____ | ____ | ____ || ____ || ____ |
     * |=============================================================================================================|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ________ || ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |  ______ | None | PGUP |  Up  | PGDN | None | None |  P7  |  P8  |  P9  |  P+  |  P/  |  P,  |  P=  ||  WhUp |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
     * |  ________  | None | Left | Down | Rght| None | None |  P4  |  P5  |  P6  |  P*  |  P-  |  P-Enter   || WhDn |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * |  __________  |NumLk | ____ | ____ | ____ | None | None |   P1  |  P2  |  P3  |  P.  |  MBt1  ||MS_UP ||MBt2 |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  ____  |  ____  |  ____  |               _____                  | ____ | ____ | MBt3 ||MS_LT |MS_DN |MS_RT |
     * `------------------------------------------------------------------------------------------------------------'
     */

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_NO,  KC_PGUP,  KC_UP,   KC_PGDN, KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PSLS, KC_PCMM, KC_PEQL,          KC_WH_U,
        _______, KC_NO,  KC_LEFT,  KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PMNS,          KC_PENT,          KC_WH_D,
        _______,          KC_NUM,   _______, _______, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_DOT,          KC_BTN1, KC_MS_U, KC_BTN2,
        _______, _______, _______,                            KC_PENT,                            _______, _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R
    ),

};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
