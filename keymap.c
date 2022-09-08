#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define ___ XXXXXXX
#define _A_ DE_A
#define _B_ DE_B
#define _C_ DE_C
#define _D_ DE_D
#define _E_ DE_E
#define _F_ DE_F
#define _G_ DE_G
#define _H_ DE_H
#define _I_ DE_I
#define _J_ DE_J
#define _K_ DE_K
#define _L_ DE_L
#define _M_ DE_M
#define _N_ DE_N
#define _O_ DE_O
#define _P_ DE_P
#define _Q_ DE_Q
#define _R_ DE_R
#define _S_ DE_S
#define _T_ DE_T
#define _U_ DE_U
#define _V_ DE_V
#define _W_ DE_W
#define _X_ DE_X
#define _Y_ DE_Y
#define _Z_ DE_Z
#define NAV TO(_NAV)
#define CBK LCTL_T(KC_BACKSPACE)
#define S1T OSM(MOD_LSFT)
#define G_E LGUI_T(KC_ENTER)
#define SYM TO(_SYMBOLS)
#define CSP LCTL_T(KC_SPACE)
#define SPC KC_SPACE
#define NUM TO(_NUM)
#define TLD DE_TILD
#define AT_ DE_AT
#define HSH DE_HASH
#define CFX DE_CIRC
#define LBC DE_LCBR
#define RBC DE_RCBR
#define PLS DE_PLUS
#define MNS DE_MINS
#define BNG DE_EXLM
#define DOL DE_DLR
#define PCN DE_PERC
#define AMP DE_AMPR
#define MUL DE_ASTR
#define BSL DE_BSLS
#define SLH DE_SLSH
#define LPA DE_LPRN
#define RPA DE_RPRN
#define LBR DE_LBRC
#define RBR DE_RBRC
#define EQL DE_EQL
#define BAR DE_PIPE
#define LES DE_LABK
#define MOR DE_RABK
#define UND DE_UNDS
#define SQT DE_QUOT
#define DQT DE_DQUO
#define COM DE_COMM
#define DOT DE_DOT
#define TAB KC_TAB
#define SEM DE_SCLN
#define COL DE_COLN
#define BAS TO(_BASE)
#define F_1 KC_F1
#define F_2 KC_F2
#define F_3 KC_F3
#define F_4 KC_F4
#define F_5 KC_F5
#define GF6 LGUI_T(KC_F6)
#define F_7 KC_F7
#define F_8 KC_F8
#define F_9 KC_F9
#define F10 KC_F10
#define F11 KC_F11
#define F12 KC_F12
#define CTL KC_LCTL
#define _1_ DE_1
#define _2_ DE_2
#define _3_ DE_3
#define _4_ DE_4
#define _5_ DE_5
#define _6_ DE_6
#define _7_ DE_7
#define _8_ DE_8
#define _9_ DE_9
#define _0_ DE_0
#define DEL KC_DELETE
#define BOT QK_BOOT
#define PUP KC_PAGE_UP
#define PDN KC_PAGE_DOWN
#define LFT KC_LEFT
#define RGT KC_RIGHT
#define UP_ KC_UP
#define DWN KC_DOWN
#define ESC KC_ESC
#define SFT KC_LSFT
#define ALT KC_LALT
#define GUI KC_LEFT_GUI
#define BT2 KC_MS_BTN2
#define HOM KC_HOME
#define END KC_END
#define ENT KC_ENTER
#define BAK KC_BACKSPACE
#define CUT C(DE_X)
#define CPY C(DE_C)
#define PST C(DE_V)
#define WND LCA(KC_TAB)
#define QIT A(KC_F4)
#define C_0 LCTL_T(DE_0)
#define TBR C(KC_TAB)
#define TBL RCS(KC_TAB)
#define BGT KC_BRIGHTNESS_UP
#define DRK KC_BRIGHTNESS_DOWN
#define NTB C(DE_T)
#define CTB C(DE_W)
#define REO RCS(DE_T)
#define QTN DE_QUES
#define UML TO(_UMLAUTS)
#define AE_ DE_ADIA
#define OE_ DE_ODIA
#define UE_ DE_UDIA
#define SS_ DE_SS
#define PRT KC_PRINT_SCREEN
#define VUP KC_AUDIO_VOL_UP
#define VDN KC_AUDIO_VOL_DOWN
#define MUT KC_AUDIO_MUTE
#define PLY KC_MEDIA_PLAY_PAUSE
#define BTK DE_GRV
#define QRZ TO(_QWERTZ)

enum custom_keycodes {
	GG_ = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GG_:
        if (record->event.pressed) {
            SEND_STRING("\ngg\n");
        }
        break;
    }
    return true;
};

enum layers { _BASE, _SYMBOLS, _NUM, _NAV, _UMLAUTS, _QWERTZ };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_mit(
    ___ , _Q_ , _W_ , _F_ , _P_ , ___ , ___ , _L_ , _U_ , _Y_ , _V_ , ___ ,
    S1T , _A_ , _R_ , _S_ , _T_ , _G_ , _M_ , _N_ , _E_ , _I_ , _O_ , G_E ,
    ___ , _Z_ , _X_ , _C_ , _D_ , ___ , ___ , _H_ , _K_ , _B_ , _J_ , ___ ,
    ___ , ___ , ___ , NAV , CBK ,    SYM    , CSP , NUM , ___ , ___ , QRZ
),

[_SYMBOLS] = LAYOUT_planck_mit(
    ___ , TLD , AT_ , HSH , EQL , ___ , ___ , LBR , RBR , QTN , SEM , ___ ,
    BNG , DOL , PCN , AMP , UML , BSL , COL , LPA , RPA , LBC , RBC , ENT ,
    ___ , BAR , LES , MOR , UND , ___ , ___ , SQT , DQT , COM , DOT , ___ ,
    ___ , ___ , ___ , NAV , CBK ,    BAS    , CSP , NUM , ___ , ___ , QRZ
),

[_NUM] = LAYOUT_planck_mit(
    ___ , F12 , F_7 , F_8 , F_9 , ___ , ___ , _7_ , _8_ , _9_ , MNS , ___ ,
    S1T , F11 , F_4 , F_5 , GF6 , MUL , SLH , _4_ , _5_ , _6_ , PLS , ENT ,
    ___ , F10 , F_1 , F_2 , F_3 , ___ , ___ , _1_ , _2_ , _3_ , DOT , ___ ,
    ___ , ___ , ___ , NAV , CBK ,    BAS    , CSP , C_0 , ___ , ___ , QRZ
),

[_NAV] = LAYOUT_planck_mit(
    BOT , REO , WND , DRK , BGT , ___ , ___ , PUP , UP_ , PDN , QIT , ___ ,
    ESC , CTL , SFT , ALT , TAB , GUI , HOM , LFT , DWN , RGT , END , ENT ,
    ___ , DEL , CUT , CPY , PST , ___ , ___ , TBL , TBR , NTB , CTB , ___ ,
    ___ , ___ , ___ , NAV , CBK ,    BAS    , CSP , NUM , ___ , ___ , QRZ
),

[_UMLAUTS] = LAYOUT_planck_mit(
    ___ , CFX , BTK , ALT , PRT , ___ , ___ , ___ , UE_ , ___ , ___ , ___ ,
    S1T , AE_ , ___ , SS_ , PLY , ___ , ___ , VDN , VUP , MUT , OE_ , ENT ,
    ___ , ___ , ___ , ___ , ___ , ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , NAV , CBK ,    BAS    , CSP , NUM , ___ , ___ , QRZ
),

[_QWERTZ] = LAYOUT_planck_mit(
    ___ , GG_ , _Q_ , _W_ , _E_ , ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
    ESC , SFT , _A_ , _S_ , _D_ , ENT , ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ALT , _C_ , _C_ , _C_ , ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , _Y_ , SPC ,    SPC    , ___ , ___ , ___ , ___ , BAS
),

};
