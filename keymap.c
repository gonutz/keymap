#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

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
#define _F_4_ LSFT_T(KC_F4)
#define _F_5_ LALT_T(KC_F5)
#define _F_6_ LGUI_T(KC_F6)
#define _F_7_ KC_F7
#define _F_8_ KC_F8
#define _F_9_ KC_F9
#define _F10_ KC_F10
#define _F11_ LCTL_T(KC_F11)
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
#define AltTb A(KC_TAB)
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
#define CS_F9 RCS(KC_F9)
#define R_G_B RGB_TOG

enum layers { _BASE, _SYMBOLS, _NAV, _NUM, _UMLAUTS, _GAMING };

enum custom_keycodes {
	SayGG = SAFE_RANGE,
	Smile,
	Grin_,
	Wink_,
	ToBas,
	ToSym,
	ToNav,
	ToNum,
};

int current_layer(void) {
	for(int i = _GAMING; i >= _BASE; i--)
		if(IS_LAYER_ON(i))
			return i;
	return _BASE;
}

bool is_layer_switch_key(uint16_t keycode) {
	return keycode == ToSym || keycode == ToNav || keycode == ToNum;
}

int layer_for_key(uint16_t keycode) {
	if(keycode == ToNav)
		return _NAV;
	if(keycode == ToNum)
		return _NUM;
	return _SYMBOLS;
}

struct key_event {
	uint16_t keycode;
	bool down;
};

struct key_event make_event(uint16_t keycode, keyrecord_t *record) {
	struct key_event e;
	e.keycode = keycode;
	e.down = record->event.pressed;
	return e;
}

#define event_history_size 4

bool were_tapped_together(struct key_event e[event_history_size], uint16_t key1, uint16_t key2) {
	bool down_then_up = e[3].down && e[2].down && !e[1].down && !e[0].down;
	bool key1_down = e[3].keycode == key1 || e[2].keycode == key1;
	bool key2_down = e[3].keycode == key2 || e[2].keycode == key2;
	bool key1_up   = e[1].keycode == key1 || e[0].keycode == key1;
	bool key2_up   = e[1].keycode == key2 || e[0].keycode == key2;
	return down_then_up && key1_down && key2_down && key1_up && key2_up;
}

bool was_tapped(struct key_event e[event_history_size], uint16_t key) {
	return e[1].down && e[1].keycode == key && !e[0].down && e[0].keycode == key;
}

bool alt_mod_down = false;
bool shift_mod_down = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static int last_permanent_layer = _BASE;
	static int layer_history[5] = {};
	static struct key_event event_history[event_history_size] = {};
	static bool bas_down = false;
	static bool sym_down = false;
	static bool nav_down = false;
	static bool num_down = false;

	if(IS_LAYER_ON(_GAMING)) {
		if(keycode == ToBas && !record->event.pressed) {
			last_permanent_layer = _BASE;
			bas_down = false;
			sym_down = false;
			nav_down = false;
			num_down = false;
			for(int i = 0; i < 5; i++)
				layer_history[i] = _BASE;
			for(int i = 0; i < event_history_size; i++)
				event_history[i].down = false;
			layer_move(_BASE);
			return false;
		}
		return true;
	}

	// Move this event into our history. The latest event is at index 0.
	for(int i = event_history_size - 1; i > 0; i--)
		event_history[i] = event_history[i - 1];
	event_history[0] = make_event(keycode, record);

	for(int i = 4; i > 0; i--)
		layer_history[i] = layer_history[i - 1];
	layer_history[0] = last_permanent_layer;

	if(event_history[0].keycode == ToBas)
		bas_down = event_history[0].down;

	if(event_history[0].keycode == ToSym)
		sym_down = event_history[0].down;

	if(event_history[0].keycode == ToNav)
		nav_down = event_history[0].down;

	if(event_history[0].keycode == ToNum)
		num_down = event_history[0].down;

	// While in base layer, the base layer key is a Shift key.
	if(event_history[0].keycode == ToBas && last_permanent_layer == _BASE) {
		shift_mod_down = event_history[0].down;
		if(shift_mod_down)
			add_mods(MOD_BIT(KC_LSFT));
		else
			del_mods(MOD_BIT(KC_LSFT));
	}

	bool SYM = sym_down;
	bool sym = !SYM;

	bool NAV = nav_down;
	bool nav = !NAV;

	bool BAS = bas_down;
	bool bas = !BAS;

	bool NUM = num_down;
	bool num = !NUM;

	int next_layer = last_permanent_layer;
	bool make_layer_permanent = false;

	// If layer keys are being held down, their layer is active.

	if(SYM && nav && bas && num)
		next_layer = _SYMBOLS;

	if(sym && NAV && bas && num)
		next_layer = _NAV;

	if(sym && nav && BAS && num)
		next_layer = _BASE;

	if(sym && nav && bas && NUM)
		next_layer = _NUM;

	if(sym && NAV && bas && NUM)
		next_layer = _UMLAUTS;

	if(SYM && nav && bas && NUM) {
		next_layer = _GAMING;
		alt_mod_down = false;
		shift_mod_down = false;
		del_mods(MOD_BIT(KC_LALT));
		del_mods(MOD_BIT(KC_LSFT));
	}

	// If no layer key is being held down, check for layer keys having been
	// tapped, which will activate a layer permanently.
	if(sym && nav && bas && num) {

		if(were_tapped_together(event_history, ToSym, ToNav)) {
			// Tapping Sym and Nav together toggles the Alt key state.
			alt_mod_down = !alt_mod_down;
			if(alt_mod_down)
				add_mods(MOD_BIT(KC_LALT));
			else
				del_mods(MOD_BIT(KC_LALT));
			next_layer = layer_history[0];
			make_layer_permanent = true;
			for(int i = 1; i < 5; i++)
				layer_history[i] = layer_history[0];
		} else if (were_tapped_together(event_history, ToNav, ToNum)) {
			// Nav and Num together are the rarely used umlaut layer.
			next_layer = _UMLAUTS;
			make_layer_permanent = true;
		} else if(was_tapped(event_history, ToBas)) {
			next_layer = _BASE;
			make_layer_permanent = true;
		} else if(was_tapped(event_history, ToSym)) {
			next_layer = _SYMBOLS;
			make_layer_permanent = true;
		} else if(was_tapped(event_history, ToNav)) {
			next_layer = _NAV;
			make_layer_permanent = true;
		} else if(was_tapped(event_history, ToNum)) {
			next_layer = _NUM;
			make_layer_permanent = true;
		}

	}

	layer_move(next_layer);
	if(make_layer_permanent)
		last_permanent_layer = next_layer;

	// The following are some macro keys.

	if(keycode == SayGG && record->event.pressed) {
		SEND_STRING("\ngg\n");
	}

	if(keycode == Smile && record->event.pressed) {
		SEND_STRING(":-)");
	}

	if(keycode == Grin_ && record->event.pressed) {
		SEND_STRING(":-D");
	}

	if(keycode == Wink_ && record->event.pressed) {
		SEND_STRING(";-)");
	}

    return true;
};

uint32_t layer_state_set_user(uint32_t state) {
	// We want auto shift in all layers but the gaming layer. There we want to
	// hold WASD down to move so they must produce down and up events.
	if(state & (1 << _GAMING))
		autoshift_disable();
	else
		autoshift_enable();

	return state;
}

void rgb_matrix_indicators_user(void) {
	// We color parts of the keyboard to indicate the current layer.
	const uint8_t x = 50; // Brightness.
	rgb_matrix_set_color_all(0, 0, 0);
	if(IS_LAYER_ON(_GAMING)) {
		rgb_matrix_set_color( 0, x, 0, 0);
		rgb_matrix_set_color( 5, x, 0, 0);
		rgb_matrix_set_color(24, x, 0, 0);
		rgb_matrix_set_color(29, x, 0, 0);
		rgb_matrix_set_color(36, x, 0, 0);
		rgb_matrix_set_color(37, x, 0, 0);
		rgb_matrix_set_color(38, x, 0, 0);
	} else if(IS_LAYER_ON(_UMLAUTS)) {
		rgb_matrix_set_color(29, 0, x, 0);
		rgb_matrix_set_color(30, 0, x, 0);
		rgb_matrix_set_color(36, 0, x, 0);
		rgb_matrix_set_color(37, 0, x, 0);
		rgb_matrix_set_color(38, 0, x, 0);
		rgb_matrix_set_color(44, 0, x, 0);
		rgb_matrix_set_color(45, 0, x, 0);
		rgb_matrix_set_color(46, 0, x, 0);
	} else if(IS_LAYER_ON(_NUM)) {
		rgb_matrix_set_color(30, x, x, 0);
		rgb_matrix_set_color(44, x, x, 0);
		rgb_matrix_set_color(45, x, x, 0);
		rgb_matrix_set_color(46, x, x, 0);
	} else if(IS_LAYER_ON(_NAV)) {
		rgb_matrix_set_color(29, x, 0, x);
		rgb_matrix_set_color(36, x, 0, x);
		rgb_matrix_set_color(37, x, 0, x);
		rgb_matrix_set_color(38, x, 0, x);
	} else if(IS_LAYER_ON(_SYMBOLS)) {
		rgb_matrix_set_color( 0, 0, x, x);
		rgb_matrix_set_color( 5, 0, x, x);
		rgb_matrix_set_color(24, 0, x, x);
	}

	// Indicate whether the Alt key is currently toggled.
	if(alt_mod_down) {
		rgb_matrix_set_color( 6, x, x, x);
		rgb_matrix_set_color(11, x, x, x);
	}
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_mit(
    Boot_ , __Q__ , __W__ , __F__ , __P__ , _____ , _____ , __L__ , __U__ , __Y__ , __J__ , _____ ,
    ToSym , __A__ , __R__ , __S__ , __T__ , __G__ , __M__ , __N__ , __E__ , __I__ , __O__ , Gui_E ,
    _____ , __Z__ , __X__ , __C__ , __D__ , _____ , _____ , __H__ , __K__ , __B__ , __V__ , _____ ,
    R_G_B , _____ , _____ , ToNav , C_Bck ,     ToBas     , Space , ToNum , _____ , _____ , _____
),
[_SYMBOLS] = LAYOUT_planck_mit(
    Boot_ , Tilde , _At__ , Hash_ , Equal , _____ , _____ , Quote , DblQu , Qstin , Minus , _____ ,
    ToSym , Dolar , Perct , Ampsn , BkTik , Bkslh , Bang_ , LParn , RParn , Comma , _Dot_ , Enter ,
    _____ , _Bar_ , Less_ , More_ , Under , _____ , _____ , LBrck , RBrck , LBrce , RBrce , _____ ,
    R_G_B , _____ , _____ , ToNav , C_Bck ,     ToBas     , Space , ToNum , _____ , _____ , _____
),
[_NAV] = LAYOUT_planck_mit(
    Boot_ , ReOpn , Wndws , _Esc_ , Prvat , _____ , _____ , PagUp , _Up__ , PgDwn , Quit_ , _____ ,
    ToSym , Ctrl_ , Shift , _Alt_ , _Tab_ , _Gui_ , Home_ , Left_ , Down_ , Right , _End_ , Enter ,
    _____ , _Del_ , _Cut_ , Copy_ , Paste , _____ , _____ , L_Tab , R_Tab , NwTab , ClTab , _____ ,
    R_G_B , _____ , _____ , ToNav , C_Bck ,     ToBas     , Space , ToNum , _____ , _____ , _____
),
[_NUM] = LAYOUT_planck_mit(
    Boot_ , _F12_ , _F_7_ , _F_8_ , _F_9_ , _____ , _____ , __7__ , __8__ , __9__ , Ctl_0 , _____ ,
    ToSym , _F11_ , _F_4_ , _F_5_ , _F_6_ , Mult_ , Slash , __4__ , __5__ , __6__ , Plus_ , Enter ,
    _____ , _F10_ , _F_1_ , _F_2_ , _F_3_ , _____ , _____ , __1__ , __2__ , __3__ , _Dot_ , _____ ,
    R_G_B , _____ , _____ , ToNav , C_Bck ,     ToBas     , Space , ToNum , _____ , _____ , _____
),
[_UMLAUTS] = LAYOUT_planck_mit(
    Boot_ , Cmflx , _____ , _Alt_ , Print , _____ , _____ , Play_ , _Ue__ , _____ , _____ , _____ ,
    ToSym , _Ae__ , _____ , _Ss__ , CS_F9 , _____ , _____ , VolDn , VolUp , Mute_ , _Oe__ , Enter ,
    _____ , Smile , Wink_ , Grin_ , _____ , _____ , _____ , Darkr , Brght , _____ , _____ , _____ ,
    R_G_B , _____ , _____ , ToNav , C_Bck ,     ToBas     , Space , ToNum , _____ , _____ , _____
),
[_GAMING] = LAYOUT_planck_mit(
    Boot_ , SayGG , __Q__ , __W__ , __E__ , _____ , _____ , AltTb , _Up__ , _____ , _____ , _____ ,
    _Esc_ , Shift , __A__ , __S__ , __D__ , Enter , _____ , Left_ , Down_ , Right , _____ , ToBas ,
    _____ , _Alt_ , __C__ , __C__ , __C__ , _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
    R_G_B , _____ , _____ , __Y__ , Space ,     Space     , _____ , _____ , _____ , _____ , _____
),

};
