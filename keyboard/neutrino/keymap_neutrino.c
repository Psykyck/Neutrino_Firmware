//Keymap for Neutrino with RGB underglow mod

#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(ESC,  1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,INS,    \
           TAB,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,DELETE, \
           CAPS, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,      HOME,   \
           LSFT, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,  UP,     END,    \
           LCTRL,LGUI,LALT,          SPC,                RALT,FN0, RCTL,LEFT,DOWN,RIGHT),
    /* 1: FN 1 */
    KEYMAP(MUTE,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  BSPC, VOLU, \
           GRV,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, BSLS, VOLD, \
           TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       PGUP, \
           TRNS,  FN1,  FN2,  FN3,  FN4,  FN5,  FN6,  FN7,  FN8,  TRNS, TRNS, TRNS, TRNS,       PGDN, \
           TRNS,  TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),
};

/* id for user defined function/macro */
enum function_id {
    SHIFT_ESC,
    RGBLED_TOGGLE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
    RGBLED_STEP_MODE,
};

enum macro_id {
    ALT_TAB,ALT_TAB2,
};


#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static uint8_t shift_esc_shift_mask;

    switch (id) {
        case SHIFT_ESC:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                    add_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    add_key(KC_ESC);
                    send_keyboard_report();
                }
            } else {
                if (shift_esc_shift_mask) {
                    del_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    del_key(KC_ESC);
                    send_keyboard_report();
                }
            }
            break;
      case RGBLED_TOGGLE:
        //led operations
        if (record->event.pressed) {
          rgblight_toggle();
        }

        break;
      case RGBLED_INCREASE_HUE:
        if (record->event.pressed) {
          rgblight_increase_hue();
        }
        break;
      case RGBLED_DECREASE_HUE:
        if (record->event.pressed) {
          rgblight_decrease_hue();
        }
        break;
      case RGBLED_INCREASE_SAT:
        if (record->event.pressed) {
          rgblight_increase_sat();
        }
        break;
      case RGBLED_DECREASE_SAT:
        if (record->event.pressed) {
          rgblight_decrease_sat();
        }
        break;
        case RGBLED_INCREASE_VAL:
          if (record->event.pressed) {
            rgblight_increase_val();
          }
          break;
        case RGBLED_DECREASE_VAL:
          if (record->event.pressed) {
            rgblight_decrease_val();
          }
          break;
        case RGBLED_STEP_MODE:
          if (record->event.pressed) {
            rgblight_step();
          }
          break;
  }
}


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case ALT_TAB:
            return (record->event.pressed ? MACRO( D(LSFT) ,T(H) , U(LSFT), T(E), T(L), T(L), T(O), END ) :MACRO( END ));
        case ALT_TAB2:
            return (record->event.pressed ? MACRO(D(LSFT),T(A),T(S),T(D),U(LSFT),T(F),T(G),T(H), END ) :MACRO( END ));

    }
    return MACRO_NONE;
}

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_FUNCTION(RGBLED_TOGGLE),
    [2] = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
    [3] = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
    [4]= ACTION_FUNCTION(RGBLED_INCREASE_SAT),
    [5] = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
    [6] = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
    [7] = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
    [8] = ACTION_FUNCTION(RGBLED_STEP_MODE),
};
