// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Layer numbers:
#define LAYER_MAC 0
#define LAYER_FN 1
#define LAYER_WIN 2
#define LAYER_WIN_CAP 3
#define LAYER_MAC_CMD 4
#define LAYER_WIN_CTL 5
#define LAYER_CLEAN 6
#define LAYER_COUNT 7

// Macros for switching layers
#define TO_WIN  TO(LAYER_WIN)
#define TO_CLN  TO(LAYER_CLEAN)
#define TO_MAC  TO(LAYER_MAC)
#define MAC_CAP LM(LAYER_MAC_CMD, MOD_LGUI)
#define FN_GRV  LT(LAYER_FN, KC_GRV)
#define WIN_CAP MO(LAYER_WIN_CAP)

// Macros for modifier keys
#define AK(N) LALT(KC_##N)
#define CK(N) LCTL(KC_##N)

const uint16_t PROGMEM keymaps[LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {
    // RGB Blue
    [LAYER_MAC] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        MAC_CAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             TO_WIN,  FN_GRV,  KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // RGB Yellow. None of this is tested. No idea if the RGB stuff will work with this firmware.
    [LAYER_FN] = LAYOUT_65_ansi_blocker(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE,
        _______, RGB_TOG, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_APP,  KC_VOLU,
        _______, RGB_MOD, RGB_VAD, RGB_SPD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLD,
        _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,QK_BOOT, NK_TOGG, _______, _______, _______, _______, _______,          KC_PGUP, KC_MPLY,
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END
    ),
    // RGB Violet (c90fe6)
    [LAYER_WIN] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        WIN_CAP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        WIN_CTL, KC_LGUI, KC_LALT,                            _______,                            TO_CLN,  _______, _______, _______, _______
    ),
    // RGB Red
    [LAYER_WIN_CMD] = LAYOUT_65_ansi_blocker(
        AK(ESC), CK(1),   CK(2),   CK(3),   CK(4),   CK(5),   CK(6),   CK(7),   CK(8),   CK(9),   CK(0),   CK(MINS),CK(EQL), CK(BSPC),CK(HOME),
        AK(TAB), AK(F4),  CK(F4),  CK(E),   CK(R),   CK(T),   CK(Y)    CK(U),   CK(I),   CK(O),   CK(P),   CK(LBRC),CK(RBRC),CK(BSLS),CK(PGUP),
        _______, CK(A),   CK(S),   CK(D),   CK(F),   CK(G),   CK(H),   CK(J),   CK(K),   CK(L),   CK(SEMI),CK(QUOT),         CK(ENT), CK(PGDN),
        CK(LSFT),CK(Z),   CK(X),   CK(C),   CK(V),   CK(B),   CK(N),   CK(M),   KC(COMM),CK(DOT), CK(SLSH),KC_LGUI,          CK(UP),  CK(END),
        KC_LCTL, CK(LGUI),CK(LART),                           CK(SPC),                            _______, CK(GRV), CK(LEFT),CK(DOWN),CK(RGHT)
    ),
    // RGB Green
    [LAYER_MAC_CMD] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC,           _______, _______,
        _______, _______, _______,                            _______,                            QK_BOOT, _______, _______, _______, _______
    ),
    // RGB Teal/Salmon
    [LAYER_WIN_CTL] = LAYOUT_65_ansi_blocker(
        CK(ESC), CK(1),   CK(2),   CK(3),   CK(4),   CK(5),   CK(6),   CK(7),   CK(8),   CK(9),   CK(0),   CK(MINS),CK(EQL), CK(BSPC),CK(HOME),
        CK(TAB), CK(Q),   CK(W),   KC_END,  CK(R),   CK(T),   CK(Y)    CK(U),   CK(I),   CK(O),   CK(P),   CK(LBRC),CK(RBRC),CK(BSLS),CK(PGUP),
        KC_LCTL, KC_HOME, CK(S),   KC_DEL,  KC_RGHT, CK(G),   KC_BSPC, CK(J),   CK(K),   CK(L),   CK(SEMI),CK(QUOT),         CK(ENT), CK(PGDN),
        CK(LSFT),CK(Z),   CK(X),   CK(C),   CK(V),   KC_LEFT, CK(N),   CK(M),   KC(COMM),CK(DOT), CK(SLSH),CK(RSFT),         CK(UP),  CK(END),
        _______, CK(LGUI),CK(LART),                           CK(SPC),                            QK_BOOT, CK(GRV), CK(LEFT),CK(DOWN),CK(RGHT)
    ),
    // RGB Rainbow
    [LAYER_CLEAN] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT,          _______, _______,
        _______, KC_LGUI, KC_LALT,                            _______,                            TO_MAC,  _______, _______, _______, _______
    )
};
