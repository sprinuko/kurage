#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02, K03, K04, K05, K06, K07, \
	     K11, K12, K13, K14, K15, K16, K17, \
	K20, K21, K22, K23, K24, K25, K26,      \
	     K31, K32, K33, K34, K35, K36, K37, \
	K40, K41, K42, K43, K44, K45, K46,      \
	     K51, K52, K53, K54, K55, K56,      \
	K60,      K62, K63, K64,      K66, K67, \
	          K72, K73, K74,      K76  \
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07 }, \
	{ KC_NO, K11,   K12,   K13,   K14,   K15,   K16,   K17 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO }, \
	{ KC_NO, K31,   K32,   K33,   K34,   K35,   K36,   K37 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46,   KC_NO }, \
	{ KC_NO, K51,   K52,   K53,   K54,   K55,   K56,   KC_NO }, \
	{ K60,   KC_NO, K62,   K63,   K64,   KC_NO, K66,   K67 }, \
	{ KC_NO, KC_NO, K72,   K73,   K74,   KC_NO, K76,   KC_NO }  \
}

#endif