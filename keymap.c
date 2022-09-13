#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _____ XXXXXXX
#define __A__ DE_A
#define __B__ DE_B
#define __C__ DE_C
#define __D__ DE_D
#define __E__ DE_E
#define __F__ DE_F
#define __G__ DE_G
#define __H__ DE_H
#define __I__ DE_I
#define __J__ DE_J
#define __K__ DE_K
#define __L__ DE_L
#define __M__ DE_M
#define __N__ DE_N
#define __O__ DE_O
#define __P__ DE_P
#define __Q__ DE_Q
#define __R__ DE_R
#define __S__ DE_S
#define __T__ DE_T
#define __U__ DE_U
#define __V__ DE_V
#define __W__ DE_W
#define __X__ DE_X
#define __Y__ DE_Y
#define __Z__ DE_Z
#define C_Bck LCTL_T(KC_BACKSPACE)
#define Shft1 OSM(MOD_LSFT)
#define Gui_E LGUI_T(KC_ENTER)
#define C_Spc LCTL_T(KC_SPACE)
#define Space KC_SPACE
#define Tilde DE_TILD
#define _At__ DE_AT
#define Hash_ DE_HASH
#define Cmflx DE_CIRC
#define LBrce DE_LCBR
#define RBrce DE_RCBR
#define Plus_ LSFT_T(DE_PLUS)
#define Minus DE_MINS
#define Bang_ DE_EXLM
#define Dolar DE_DLR
#define Perct DE_PERC
#define Ampsn DE_AMPR
#define Mult_ DE_ASTR
#define Bkslh DE_BSLS
#define Slash DE_SLSH
#define LParn DE_LPRN
#define RParn DE_RPRN
#define LBrck DE_LBRC
#define RBrck DE_RBRC
#define Equal DE_EQL
#define _Bar_ DE_PIPE
#define Less_ DE_LABK
#define More_ DE_RABK
#define Under DE_UNDS
#define Quote DE_QUOT
#define DblQu DE_DQUO
#define Comma DE_COMM
#define _Dot_ DE_DOT
#define _Tab_ KC_TAB
#define _F_1_ KC_F1
#define _F_2_ KC_F2
#define _F_3_ KC_F3
#define _F_4_ KC_F4
#define _F_5_ KC_F5
#define GuiF6 LGUI_T(KC_F6)
#define _F_7_ KC_F7
#define _F_8_ KC_F8
#define _F_9_ KC_F9
#define _F10_ KC_F10
#define _F11_ KC_F11
#define _F12_ KC_F12
#define Ctrl_ KC_LCTL
#define __1__ DE_1
#define __2__ DE_2
#define __3__ DE_3
#define __4__ DE_4
#define __5__ DE_5
#define __6__ DE_6
#define __7__ DE_7
#define __8__ DE_8
#define __9__ DE_9
#define __0__ DE_0
#define _Del_ KC_DELETE
#define Boot_ QK_BOOT
#define PagUp KC_PAGE_UP
#define PgDwn KC_PAGE_DOWN
#define Left_ KC_LEFT
#define Right KC_RIGHT
#define _Up__ KC_UP
#define Down_ KC_DOWN
#define _Esc_ KC_ESC
#define Shift KC_LSFT
#define _Alt_ KC_LALT
#define _Gui_ KC_LEFT_GUI
#define Home_ KC_HOME
#define _End_ KC_END
#define Enter KC_ENTER
#define _BAK_ KC_BACKSPACE
#define _Cut_ C(DE_X)
#define Copy_ C(DE_C)
#define Paste C(DE_V)
#define Wndws LCA(KC_TAB)
#define Quit_ A(KC_F4)
#define Ctl_0 LCTL_T(DE_0)
#define R_Tab C(KC_TAB)
#define L_Tab RCS(KC_TAB)
#define Brght KC_BRIGHTNESS_UP
#define Darkr KC_BRIGHTNESS_DOWN
#define NwTab C(DE_T)
#define ClTab C(KC_F4)
#define ReOpn RCS(DE_T)
#define Qstin DE_QUES
#define _Ae__ DE_ADIA
#define _Oe__ DE_ODIA
#define _Ue__ DE_UDIA
#define _Ss__ DE_SS
#define Print KC_PRINT_SCREEN
#define VolUp KC_AUDIO_VOL_UP
#define VolDn KC_AUDIO_VOL_DOWN
#define Mute_ KC_AUDIO_MUTE
#define Play_ KC_MEDIA_PLAY_PAUSE
#define BkTik DE_GRV
#define Prvat RCS(DE_N)
#define ToBas TO(_BASE)
#define ToNav TT(_NAV)
#define ToNum TT(_NUM)
// TODO Bring back umlauts.
#define ToUml KC_NO // TO(_UMLAUTS)
#define ToQrz TO(_QWERTZ)

enum layers { _BASE, _SYMBOLS, _NUM, _NAV, _UMLAUTS, _QWERTZ };

enum custom_keycodes {
	SayGG = SAFE_RANGE,
	ToSym,
	//ToNav,
	//ToNum,
};

int current_layer(void) {
	for(int i = _QWERTZ; i >= _BASE; i--)
		if(IS_LAYER_ON(i))
			return i;
	return _BASE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static int last_layer = 0;
	static bool stay_in_symbols = false;
	static bool non_symbol_key_pressed = false;

	int layer = current_layer();

	if(keycode == ToSym) {
		if(record->event.pressed) {
			// Symbol key down.
			if(layer != _SYMBOLS) {
				last_layer = layer;
				layer_move(_SYMBOLS);
				stay_in_symbols = false;
				non_symbol_key_pressed = false;
			}
		} else {
			// Symbol key up.
			if(non_symbol_key_pressed && !stay_in_symbols)
				layer_move(last_layer);
			else
				stay_in_symbols = true;
		}
		return false;
	} else
		non_symbol_key_pressed = true;

	if(keycode == SayGG && record->event.pressed) {
		SEND_STRING("\ngg\n");
	}

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_mit(
    Boot_ , __Q__ , __W__ , __F__ , __P__ , _____ , _____ , __L__ , __U__ , __Y__ , __V__ , _____ ,
    ToSym , __A__ , __R__ , __S__ , __T__ , __G__ , __M__ , __N__ , __E__ , __I__ , __O__ , Gui_E ,
    _____ , __Z__ , __X__ , __C__ , __D__ , _____ , _____ , __H__ , __K__ , __B__ , __J__ , _____ ,
    _____ , _____ , _____ , ToNav , C_Bck ,     Shift     , C_Spc , ToNum , _____ , _____ , ToQrz
),
[_SYMBOLS] = LAYOUT_planck_mit(
    Boot_ , Tilde , _At__ , Hash_ , Equal , _____ , _____ , Quote , DblQu , Qstin , Minus , _____ ,
    ToSym , Dolar , Perct , Ampsn , ToUml , Bkslh , Bang_ , LParn , RParn , Comma , _Dot_ , Enter ,
    _____ , _Bar_ , Less_ , More_ , Under , _____ , _____ , LBrck , RBrck , LBrce , RBrce , _____ ,
    _____ , _____ , _____ , ToNav , C_Bck ,     ToBas     , C_Spc , ToNum , _____ , _____ , ToQrz
),
[_NUM] = LAYOUT_planck_mit(
    Boot_ , _F12_ , _F_7_ , _F_8_ , _F_9_ , _____ , _____ , __7__ , __8__ , __9__ , Ctl_0 , _____ ,
    ToSym , _F11_ , _F_4_ , _F_5_ , GuiF6 , Mult_ , Slash , __4__ , __5__ , __6__ , Plus_ , Enter ,
    _____ , _F10_ , _F_1_ , _F_2_ , _F_3_ , _____ , _____ , __1__ , __2__ , __3__ , _Dot_ , _____ ,
    _____ , _____ , _____ , ToNav , C_Bck ,     ToBas     , C_Spc , ToNum , _____ , _____ , ToQrz
),
[_NAV] = LAYOUT_planck_mit(
    Boot_ , ReOpn , Wndws , _Esc_ , Prvat , _____ , _____ , PagUp , _Up__ , PgDwn , Quit_ , _____ ,
    ToSym , Ctrl_ , Shift , _Alt_ , _Tab_ , _Gui_ , Home_ , Left_ , Down_ , Right , _End_ , Enter ,
    _____ , _Del_ , _Cut_ , Copy_ , Paste , _____ , _____ , L_Tab , R_Tab , NwTab , ClTab , _____ ,
    _____ , _____ , _____ , ToNav , C_Bck ,     ToBas     , C_Spc , ToNum , _____ , _____ , ToQrz
),
[_UMLAUTS] = LAYOUT_planck_mit(
    Boot_ , Cmflx , BkTik , _Alt_ , Print , _____ , _____ , Play_ , _Ue__ , _____ , _____ , _____ ,
    ToSym , _Ae__ , _____ , _Ss__ , ToUml , _____ , _____ , VolDn , VolUp , Mute_ , _Oe__ , Enter ,
    _____ , _____ , _____ , _____ , _____ , _____ , _____ , Darkr , Brght , _____ , _____ , _____ ,
    _____ , _____ , _____ , ToNav , C_Bck ,     ToBas     , C_Spc , ToNum , _____ , _____ , ToQrz
),
[_QWERTZ] = LAYOUT_planck_mit(
    Boot_ , SayGG , __Q__ , __W__ , __E__ , _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
    _Esc_ , Shift , __A__ , __S__ , __D__ , Enter , _____ , _____ , _____ , _____ , _____ , _____ ,
    _____ , _Alt_ , __C__ , __C__ , __C__ , _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
    _____ , _____ , _____ , __Y__ , Space ,     Space     , _____ , _____ , _____ , _____ , ToBas
),

};
