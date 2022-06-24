/* Copyright 202 Kevin Frei <kevinfrei@hotmail.com>
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

#define LY_MED  0
#define SEL_DBG 1
#define SEL_MSP 2
#define SEL_BT  3
#define LY_VS   4
#define LY_IJ   5
#define LY_PAT  6
#define LY_SPD  7
#define LY_BR   8
#define LY_VSO  9
#define LY_IJO  10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LY_MED] =  LAYOUT(LT(SEL_DBG, KC_MUTE), LT(SEL_MSP, KC_MPLY), LT(SEL_BT, KC_MNXT)),
[SEL_DBG] = LAYOUT(KC_TRNS,              TG(LY_VS),            TG(LY_IJ)),
[SEL_MSP] = LAYOUT(TG(LY_PAT),           KC_TRNS,              TG(LY_SPD)),
[SEL_BT] =  LAYOUT(TG(LY_BR),            RGB_TOG,              KC_TRNS),
[LY_VS] =   LAYOUT(LSFT(KC_F11),         LT(LY_VSO, KC_F10),   KC_F11),
[LY_IJ] =   LAYOUT(LSFT(KC_F8),          LT(LY_IJO, KC_F8),    KC_F7),
[LY_PAT] =  LAYOUT(RGB_RMOD,             TG(LY_PAT),           RGB_MOD),
[LY_SPD] =  LAYOUT(RGB_SPD,              TG(LY_SPD),           RGB_SPI),
[LY_BR] =   LAYOUT(RGB_VAD,              TG(LY_BR),            RGB_VAI),
[LY_VSO] =  LAYOUT(TG(LY_VS),            KC_TRNS,              TG(LY_VS)),
[LY_IJO] =  LAYOUT(TG(LY_IJ),            KC_TRNS,              TG(LY_IJ)),
};
