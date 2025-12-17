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
#include "rgb_matrix_map.h"
#include "midi.h"

#define KC_DICT LCTL(LALT(LGUI(KC_D)))
#define KC_PRNT LGUI(LSFT(KC_4))
#define KC_DND LCTL(LALT(LGUI(KC_N)))

enum layers { _BASE = 0, _FN = 1, _NUMPAD = 2, _MIDI = 3 };

enum custom_keycodes {
    MIDI_CC_CUTOFF = SAFE_RANGE,
    MIDI_CC_RESO,
    MIDI_CC_ATTACK,
    MIDI_CC_RELEASE,

    // Drums
    MIDI_KICK,
    MIDI_SNARE,
    MIDI_CLAP,
    MIDI_HH_C,
    MIDI_HH_O,
    MIDI_TOM,
    MIDI_CRASH
};

extern MidiDevice midi_device;
int8_t            midi_octave = 0;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layout
     *
     * ,-------------------------------------------------------------------------------------------------------------.
     * | Esc  ||  F1  |  F2  |  F3  |  F4  ||  F5  |  F6  |  F7  |  F8  ||  F9  | F10  | F11  | F12  || Del || Mute  |
     * |=============================================================================================================|
     * |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _ |  = + |  Backspc || Home |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |   Tab   |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | [ }  | ] }  |  \ |  || End  |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
     * |  Capslock  |  A   |  S   |  D   |  F  |  G   |  H   |  J   |  K   |  L   | ; :  | ' "  |    Enter   || PgUp |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * |    LShift    |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | , <  | . >  | / ?  | RShift ||  Up  || PgDn |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  Ctrl  |   LAlt  |  LGui  |               Space                  | RGui |  RAlt  | Fn || Left | Down | Rght |
     * `------------------------------------------------------------------------------------------------------------'
     */

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        LT(2,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, KC_ROPT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* FN1 Layout
     *
     * ,-------------------------------------------------------------------------------------------------------------.
     * |EECLR  || BriD | Briu | MCTL | MLPAD || DICT | DND | MRWD | MPLY || MFFD | MUTE | VOLD | VOLU ||PrScr ||Sleep|
     * |=============================================================================================================|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ________ || ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
     * |  ______ |RGBSAD|RGBVAI|RGBSAI| NKRO | ____ |YAHOO | ____ | ____ |OUTLK | ____ | ____ | ____ |QK_BOOT|| ____ |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
     * |  ______  |RGBHUD|RGBVAD|RGBHUI| ____ | GMAIL |HTMAIL| ____ | ____ | ____ | ____ | ____ | __________ || ____ |
     * |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
     * |  ________  |RGBNIT| ____ | ____ | ____ | QK_BOOT | ____ | ____ | ____ |DOTCOM| ____ | ______ ||RGBMOD||____ |
     * |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
     * |  ____  | WinKyLk |  ____  |               _____                  | ____ | ____ | ____ ||RGBSPD|RGBRMD|RGBSPI|
     * `------------------------------------------------------------------------------------------------------------'
     */

    [1] = LAYOUT(
        EE_CLR,   KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_DICT, KC_DND,  KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, KC_PRNT,          KC_SLEP,
        _______,  _______, _______, _______, _______, _______ ,_______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,  RM_SATD, RM_VALU, RM_SATU, NK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______,  RM_HUED, RM_VALD, RM_HUEU, RM_TOGG, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,           _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______,          _______, RM_NEXT, _______,
        _______,  GU_TOGG, _______,                            _______,                            MO(3),   MI_TOGG, _______, RM_SPDD, RM_PREV, RM_SPDU
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
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_NO,  KC_PGUP,  KC_UP,   KC_PGDN, KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PSLS, KC_PCMM, KC_PEQL,          MS_WHLU,
        _______, KC_NO,  KC_LEFT,  KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PMNS,          KC_PENT,          MS_WHLD,
        _______,         _______,  _______, _______, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT,          MS_BTN1, MS_UP,   MS_BTN2,
        _______, _______, _______,                            KC_PENT,                            MS_WHLL, MS_WHLR, MS_BTN3, MS_LEFT, MS_DOWN, MS_RGHT
    ),

    [3] = LAYOUT(
        _______, MI_OCTD, MI_OCTU, _______,    MIDI_CC_CUTOFF, MIDI_CC_RESO, MIDI_CC_ATTACK, MIDI_CC_RELEASE, _______,    _______, _______, _______, _______, _______,          _______,
        _______, MI_C,    MI_Cs,   MI_D,       MI_Ds,         MI_E,         MI_F,           MI_Fs,           MI_G,       MI_Gs,   MI_A,    MI_As,   MI_B,    MI_C1,           _______,
        _______, _______, _______, _______,    _______,        _______,      _______,        _______,         _______,    _______, _______, _______, _______, _______,          _______,
        _______, MI_C,    MI_D,    MI_E,       MI_F,           MI_G,         MI_A,           MI_B,            MI_C1,      _______, _______, _______,          _______,          _______,
        _______, MIDI_KICK, MIDI_SNARE, MIDI_CLAP, MIDI_HH_C, MIDI_HH_O, MIDI_TOM, MIDI_CRASH, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                                               _______,                                              _______, _______, _______, _______, _______, _______
    ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_NO, KC_NO) },      // FN layer
    [2] = { ENCODER_CCW_CW(KC_MRWD, KC_MFFD) },
    [3] = { ENCODER_CCW_CW(KC_NO, KC_NO) }       // MIDI layer
};
#endif

/*#if defined(ENCODER_ENABLE) && !defined(ENCODER_DEFAULTACTIONS_ENABLE) // Encoder Functionality when not using userspace defaults
void encoder_action_rgbhue(bool clockwise) {
    if (clockwise)
        rgblight_increase_hue_noeeprom();
    else
        rgblight_decrease_hue_noeeprom();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();
    if (mods_state & MOD_BIT(KC_LSFT)) { // If you are holding L shift, encoder changes layers
        encoder_action_layerchange(clockwise);
    } else if (mods_state & MOD_BIT(KC_RSFT)) { // If you are holding R shift, Page up/dn
        unregister_mods(MOD_BIT(KC_RSFT));
        encoder_action_navpage(clockwise);
        register_mods(MOD_BIT(KC_RSFT));
    } else if (mods_state & MOD_BIT(KC_LCTL)) { // if holding Left Ctrl, navigate next/prev word
        encoder_action_navword(clockwise);
    } else if (mods_state & MOD_BIT(KC_RCTL)) { // if holding Right Ctrl, change rgb hue/colour
        encoder_action_rgbhue(clockwise);
    } else if (mods_state & MOD_BIT(KC_LALT)) { // if holding Left Alt, change media next/prev track
        encoder_action_mediatrack(clockwise);
    } else {
        switch (get_highest_layer(layer_state)) {
        case 1:
            #ifdef IDLE_TIMEOUT_ENABLE
            timeout_update_threshold(clockwise);
            #endif
            break;              
        default:
            encoder_action_volume(clockwise); // Otherwise it just changes volume
            break;
        }
    }
    //return true; //set to return false to counteract enabled encoder in pro.c
    return false;
}
#endif // ENCODER_ENABLE && !ENCODER_DEFAULTACTIONS_ENABLE*/

// Capslock, Scroll lock and Numlock indicator on Left side lights.
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //if (get_rgb_nightmode()) rgb_matrix_set_color_all(RGB_OFF);

    led_t led_state = host_keyboard_led_state();

    // Scroll Lock RGB setup
    // if (led_state.scroll_lock) {
    //     rgb_matrix_set_color(LED_L3, RGB_RED);
    //     rgb_matrix_set_color(LED_L4, RGB_RED);
    //     rgb_matrix_set_color(LED_TAB, RGB_RED);
    //     rgb_matrix_set_color(LED_F12, RGB_RED);
    // }

/*
    // System NumLock warning indicator RGB setup
    #ifdef INVERT_NUMLOCK_INDICATOR
    if (!led_state.num_lock) { // on if NUM lock is OFF to bring attention to overlay numpad not functional when enabled
        rgb_matrix_set_color(LED_GRV, RGB_ORANGE2);
        rgb_matrix_set_color(LED_L1, RGB_ORANGE2);
        rgb_matrix_set_color(LED_L2, RGB_ORANGE2);
        rgb_matrix_set_color(LED_N, RGB_ORANGE2);
        rgb_matrix_set_color(LED_FN, RGB_ORANGE2);
    }
    #else
    if (led_state.num_lock) { // Normal, on if NUM lock is ON
        rgb_matrix_set_color(LED_GRV, RGB_ORANGE2);
        rgb_matrix_set_color(LED_L1, RGB_ORANGE2);
        rgb_matrix_set_color(LED_L2, RGB_ORANGE2);
        rgb_matrix_set_color(LED_N, RGB_ORANGE2);
        rgb_matrix_set_color(LED_FN, RGB_ORANGE2);
    }
    #endif // INVERT_NUMLOCK_INDICATOR
*/

    // CapsLock RGB setup
    if (led_state.caps_lock) {        
        for (uint8_t i = 0; i < ARRAY_SIZE(LED_LIST_LETTERS); i++) {
            rgb_matrix_set_color(LED_LIST_LETTERS[i], RGB_CHARTREUSE);
        }
        rgb_matrix_set_color(LED_L5, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_L6, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_L7, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_L8, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_CAPS, RGB_CHARTREUSE);
    }

    // Winkey disabled (gaming) mode RGB setup
    /*if (keymap_config.no_gui) {
        rgb_matrix_set_color(LED_LWIN, RGB_RED); //light up Winkey red when disabled
        rgb_matrix_set_color(LED_W, RGB_CHARTREUSE); //light up gaming keys with WSAD higlighted
        rgb_matrix_set_color(LED_S, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_A, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_D, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_Q, RGB_ORANGE2);
        rgb_matrix_set_color(LED_E, RGB_ORANGE2);
        rgb_matrix_set_color(LED_R, RGB_ORANGE2);
        rgb_matrix_set_color(LED_TAB, RGB_ORANGE2);
        rgb_matrix_set_color(LED_F, RGB_ORANGE2);
        rgb_matrix_set_color(LED_Z, RGB_ORANGE2);
        rgb_matrix_set_color(LED_X, RGB_ORANGE2);
        rgb_matrix_set_color(LED_C, RGB_ORANGE2);
        rgb_matrix_set_color(LED_V, RGB_ORANGE2);
        rgb_matrix_set_color(LED_SPC, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LCTL, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LSFT, RGB_ORANGE2);
    }*/

    // Fn selector mode RGB setup
    switch (get_highest_layer(layer_state)) { // special handling per layer
    case 1: // on Fn layer select what the encoder does when pressed
        // rgb_matrix_set_color(LED_FN, RGB_RED); //FN key

        //NEW RGB LIGHTING TO RING KEYBOARD ON FN LAYER ACTIVATION:
        for (uint8_t j = 0; j < ARRAY_SIZE(LED_LIST_FUNCROW); j++) {
            rgb_matrix_set_color(LED_LIST_FUNCROW[j], RGB_RED);
        }
        //rgb_matrix_set_color(LED_LCTL, RGB_RED);
        //rgb_matrix_set_color(LED_LALT, RGB_RED);
        //rgb_matrix_set_color(LED_SPC, RGB_RED);
        //rgb_matrix_set_color(LED_LWIN, RGB_RED);
        //rgb_matrix_set_color(LED_RALT, RGB_RED);
        //rgb_matrix_set_color(LED_FN, RGB_OFFBLUE);
        //rgb_matrix_set_color(LED_RCTL, RGB_RED);
        //rgb_matrix_set_color(LED_BSLS, RGB_RED);
        rgb_matrix_set_color(LED_L1, RGB_RED);
        rgb_matrix_set_color(LED_L2, RGB_RED);
        rgb_matrix_set_color(LED_L3, RGB_RED);
        rgb_matrix_set_color(LED_L4, RGB_RED);
        rgb_matrix_set_color(LED_L5, RGB_RED);
        rgb_matrix_set_color(LED_L6, RGB_RED);
        rgb_matrix_set_color(LED_L7, RGB_RED);
        rgb_matrix_set_color(LED_L8, RGB_RED);
        //rgb_matrix_set_color(LED_DOWN, RGB_RED);
        //rgb_matrix_set_color(LED_LEFT, RGB_RED);
        //rgb_matrix_set_color(LED_RIGHT, RGB_RED);
        rgb_matrix_set_color(LED_R1, RGB_RED);
        rgb_matrix_set_color(LED_R2, RGB_RED);
        rgb_matrix_set_color(LED_R3, RGB_RED);
        rgb_matrix_set_color(LED_R4, RGB_RED);
        rgb_matrix_set_color(LED_R5, RGB_RED);
        rgb_matrix_set_color(LED_R6, RGB_RED);
        rgb_matrix_set_color(LED_R7, RGB_RED);
        rgb_matrix_set_color(LED_R8, RGB_RED);

        // System NumLock warning indicator RGB setup
        // #ifdef INVERT_NUMLOCK_INDICATOR
        // if (!led_state.num_lock) { // on if NUM lock is OFF to bring attention to overlay numpad not functional when enabled
        //     rgb_matrix_set_color(LED_SPC, RGB_ORANGE2);
        // }
        // #else
        if (led_state.num_lock) { // Normal, on if NUM lock is ON
            rgb_matrix_set_color(LED_SPC, RGB_ORANGE2);
        }
        // #endif // INVERT_NUMLOCK_INDICATOR

        // Add RGB Timeout Indicator -- shows 0 to 139 using F row and num row; larger numbers using 16bit code
        /*uint16_t timeout_threshold = get_timeout_threshold();
        if (timeout_threshold <= 10) rgb_matrix_set_color(LED_LIST_FUNCROW[timeout_threshold], RGB_BLUE);
        else if (timeout_threshold < 140) {
            rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold / 10)], RGB_CYAN);
            rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold % 10)], RGB_BLUE);
        } else { // >= 140 minutes, just show these 3 lights
            rgb_matrix_set_color(LED_LIST_FUNCROW[10], RGB_CYAN);
            rgb_matrix_set_color(LED_LIST_FUNCROW[11], RGB_CYAN);
            rgb_matrix_set_color(LED_LIST_FUNCROW[12], RGB_CYAN);
        }*/
        break;

        // Numpad & Mouse Keys overlay RGB
    case 2:
        // #ifdef INVERT_NUMLOCK_INDICATOR
        // if (!led_state.num_lock) { // on if NUM lock is OFF to bring attention to overlay numpad not functional when enabled
        //     rgb_matrix_set_color(LED_CAPS, RGB_ORANGE2);
        // }
        // #else
        if (led_state.num_lock) { // Normal, on if NUM lock is ON
            rgb_matrix_set_color(LED_CAPS, RGB_ORANGE2);
        }
        // #endif // INVERT_NUMLOCK_INDICATOR
        for (uint8_t i = 0; i < ARRAY_SIZE(LED_LIST_NUMPAD); i++) {
            rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_OFFBLUE);
        }
        rgb_matrix_set_color(LED_L5, RGB_OFFBLUE);
        rgb_matrix_set_color(LED_L6, RGB_OFFBLUE);
        rgb_matrix_set_color(LED_CAPS, RGB_OFFBLUE);
        rgb_matrix_set_color(LED_UP, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_DOWN, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_LEFT, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_RIGHT, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_RCTL, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_RSFT, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_END, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_PGUP, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_PGDN, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_FN, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_RALT, RGB_CHARTREUSE);
        break;
    }
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state) == 2) {
        uint8_t value = clockwise ? 127 : 0;
        midi_send_cc(&midi_device, 0, 74, value);
        return false; // bloquea encoder_map en capa MIDI
    }
    return true; // deja encoder_map en capas normales
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* ---------- NOTE OFF (soltar tecla) ---------- */
    if (!record->event.pressed) {
        switch (keycode) {
            case MIDI_KICK:   midi_send_noteoff(&midi_device, 9, 36, 0); return false;
            case MIDI_SNARE:  midi_send_noteoff(&midi_device, 9, 38, 0); return false;
            case MIDI_CLAP:   midi_send_noteoff(&midi_device, 9, 39, 0); return false;
            case MIDI_HH_C:   midi_send_noteoff(&midi_device, 9, 42, 0); return false;
            case MIDI_HH_O:   midi_send_noteoff(&midi_device, 9, 46, 0); return false;
            case MIDI_TOM:    midi_send_noteoff(&midi_device, 9, 45, 0); return false;
            case MIDI_CRASH:  midi_send_noteoff(&midi_device, 9, 49, 0); return false;
        }
        return true;
    }

    /* ---------- NOTE ON / CC ---------- */
    switch (keycode) {

        /* OCTAVAS */
        case MI_OCTU:
            if (midi_octave < 3) midi_octave++;
            return false;

        case MI_OCTD:
            if (midi_octave > -3) midi_octave--;
            return false;

        /* CC */
        case MIDI_CC_CUTOFF:
            midi_send_cc(&midi_device, midi_config.channel, 74, 100);
            return false;

        case MIDI_CC_RESO:
            midi_send_cc(&midi_device, midi_config.channel, 71, 100);
            return false;

        case MIDI_CC_ATTACK:
            midi_send_cc(&midi_device, midi_config.channel, 73, 80);
            return false;

        case MIDI_CC_RELEASE:
            midi_send_cc(&midi_device, midi_config.channel, 72, 80);
            return false;

        /* DRUMS */
        case MIDI_KICK:   midi_send_noteon(&midi_device, 9, 36, 127); return false;
        case MIDI_SNARE:  midi_send_noteon(&midi_device, 9, 38, 127); return false;
        case MIDI_CLAP:   midi_send_noteon(&midi_device, 9, 39, 127); return false;
        case MIDI_HH_C:   midi_send_noteon(&midi_device, 9, 42, 110); return false;
        case MIDI_HH_O:   midi_send_noteon(&midi_device, 9, 46, 110); return false;
        case MIDI_TOM:    midi_send_noteon(&midi_device, 9, 45, 120); return false;
        case MIDI_CRASH:  midi_send_noteon(&midi_device, 9, 49, 127); return false;
    }

    return true;
}