#include "kb.h"
#include <stdio.h>

enum custom_keycodes {
    ALTSHIFT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC,  KC_Q,   KC_E,     KC_T,    KC_U,    KC_O,    KC_LBRC, KC_BSPC,
				 KC_W,   KC_R,     KC_Y,    KC_I,    KC_P,    KC_RBRC, ALTSHIFT,
		KC_LCTL, KC_A,   KC_D,     KC_G,    KC_J,    KC_L,    KC_QUOT, 
				 KC_S,   KC_F,     KC_H,    KC_K,    KC_SCLN, KC_ENT,  KC_GRV,
		KC_LSFT, KC_Z,   KC_C,     KC_B,    KC_M,    KC_DOT,  KC_RSFT, 
				 KC_X,   KC_V,     KC_N,    KC_COMM, KC_SLSH, KC_UP, 
		MO(1),           KC_LGUI,  KC_LALT, MO(2),            KC_LEFT, KC_RGHT,
		                 KC_SPC,   KC_SPC,  KC_NO,            KC_DOWN),

	KEYMAP(
		KC_TAB,  KC_TRNS, KC_7,    KC_9,    KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, 
		         KC_TRNS, KC_8,    KC_PLUS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_4,    KC_6,    KC_SLSH, KC_TRNS, KC_TRNS, 
		         KC_TRNS, KC_5,    KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_1,    KC_3,    KC_RPRN, KC_TRNS, KC_TRNS, 
		         KC_0,    KC_2,    KC_LPRN, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS,          KC_TRNS, KC_TRNS, MO(3),            KC_TRNS, KC_TRNS, 
		                  KC_LCTL, KC_TRNS, KC_TAB,          KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F2,   KC_F4,   KC_TRNS, KC_DEL, 
		         KC_TRNS, KC_TRNS, KC_F1,   KC_F3,   KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,   KC_F8,   KC_TRNS, 
		         KC_TRNS, KC_TRNS, KC_F5,   KC_F7,   KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F10,  KC_F12,  KC_TRNS, 
		         KC_TRNS, KC_TRNS, KC_F9,   KC_F11,  KC_TRNS, KC_TRNS, 
		MO(3),            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, 
		                  KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, 
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, 
		                  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS)
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    	case ALTSHIFT:
    	    if (record->event.pressed) {
    	        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LSHIFT) SS_UP(X_LALT));
    	    }
			break;
    }

    return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
		case 3:
			oled_write_P(PSTR("ADJUST\n"), false);
			break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

void oled_task_user(void) {
	render_status();
}
#endif