#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#    define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
    RGB_SLD = ZSA_SAFE_RANGE,
    HSV_0_255_255,
    HSV_74_255_255,
    HSV_169_255_255,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬────────────┐                         ┌─────────────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬───────┐
//    │    =    │        1        │        2        │        3        │        4        │     5      │                         │      6      │        7        │        8        │        9        │        0        │   -   │
//    ├─────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼────────────┤                         ├─────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼───────┤
//    │    `    │        q        │        w        │        e        │        r        │     t      │                         │      y      │        u        │        i        │        o        │        p        │   \   │
//    ├─────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼────────────┤                         ├─────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼───────┤
//    │   esc   │ MT(MOD_LGUI, a) │ MT(MOD_LALT, s) │ MT(MOD_LCTL, d) │ MT(MOD_LSFT, f) │     g      │                         │      h      │ MT(MOD_RSFT, j) │ MT(MOD_LCTL, k) │ MT(MOD_RALT, l) │ MT(MOD_RGUI, ;) │   '   │
//    ├─────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼────────────┤                         ├─────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼───────┤
//    │ CW_TOGG │        z        │        x        │    LT(6, c)     │        v        │     b      │                         │      n      │        m        │        ,        │        .        │        /        │ TG(1) │
//    └─────────┴─────────────────┴─────────────────┴─────────────────┴─────────────────┼────────────┼────────────┬────────────┼─────────────┼─────────────────┴─────────────────┴─────────────────┴─────────────────┴───────┘
//                                                                                      │ LT(2, spc) │ LT(4, tab) │ LT(7, ent) │ LT(3, bspc) │
//                                                                                      └────────────┴────────────┴────────────┴─────────────┘
[0] = LAYOUT_voyager(
  KC_EQUAL  , KC_1               , KC_2               , KC_3               , KC_4               , KC_5            ,                                   KC_6           , KC_7               , KC_8               , KC_9               , KC_0                  , KC_MINUS,
  KC_GRAVE  , KC_Q               , KC_W               , KC_E               , KC_R               , KC_T            ,                                   KC_Y           , KC_U               , KC_I               , KC_O               , KC_P                  , KC_BSLS ,
  KC_ESCAPE , MT(MOD_LGUI, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LCTL, KC_D) , MT(MOD_LSFT, KC_F) , KC_G            ,                                   KC_H           , MT(MOD_RSFT, KC_J) , MT(MOD_LCTL, KC_K) , MT(MOD_RALT, KC_L) , MT(MOD_RGUI, KC_SCLN) , KC_QUOTE,
  CW_TOGG   , KC_Z               , KC_X               , LT(6, KC_C)        , KC_V               , KC_B            ,                                   KC_N           , KC_M               , KC_COMMA           , KC_DOT             , KC_SLASH              , TG(1)   ,
                                                                                                  LT(2, KC_SPACE) , LT(4, KC_TAB) , LT(7, KC_ENTER) , LT(3, KC_BSPC)
),

//    ┌───────┬───────┬───────┬───────┬───────┬───────┐               ┌───────┬───────┬───────┬───────┬───────┬───────┐
//    │ trans │ trans │ trans │ trans │ trans │ trans │               │ trans │ trans │ trans │ trans │ trans │ trans │
//    ├───────┼───────┼───────┼───────┼───────┼───────┤               ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │ trans │ trans │ trans │ trans │ trans │ trans │               │ trans │ trans │ trans │ trans │ trans │ trans │
//    ├───────┼───────┼───────┼───────┼───────┼───────┤               ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │ trans │   a   │   s   │   d   │   f   │ trans │               │ trans │   j   │   k   │   l   │   ;   │ trans │
//    ├───────┼───────┼───────┼───────┼───────┼───────┤               ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │ trans │ trans │ trans │ trans │ trans │ trans │               │ trans │ trans │ trans │ trans │ trans │ trans │
//    └───────┴───────┴───────┴───────┴───────┼───────┼───────┬───────┼───────┼───────┴───────┴───────┴───────┴───────┘
//                                            │ trans │ trans │ trans │ trans │
//                                            └───────┴───────┴───────┴───────┘
[1] = LAYOUT_voyager(
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
  KC_TRANSPARENT , KC_A           , KC_S           , KC_D           , KC_F           , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_J           , KC_K           , KC_L           , KC_SCLN        , KC_TRANSPARENT,
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                                                       KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT
),

//    ┌─────┬────┬────┬────┬────┬───────┐               ┌────┬────┬────┬────┬─────┬─────┐
//    │ esc │ f1 │ f2 │ f3 │ f4 │  f5   │               │ f6 │ f7 │ f8 │ f9 │ f10 │ f11 │
//    ├─────┼────┼────┼────┼────┼───────┤               ├────┼────┼────┼────┼─────┼─────┤
//    │  `  │ <  │ >  │ (  │ )  │   *   │               │ \  │ 7  │ 8  │ 9  │  /  │ f12 │
//    ├─────┼────┼────┼────┼────┼───────┤               ├────┼────┼────┼────┼─────┼─────┤
//    │  ~  │ [  │ ]  │ {  │ }  │   =   │               │ +  │ 6  │ 5  │ 4  │  *  │ del │
//    ├─────┼────┼────┼────┼────┼───────┤               ├────┼────┼────┼────┼─────┼─────┤
//    │  &  │ ?  │ .  │ ,  │ !  │   $   │               │ -  │ 1  │ 2  │ 3  │  =  │ ins │
//    └─────┴────┴────┴────┴────┼───────┼───────┬───────┼────┼────┴────┴────┴─────┴─────┘
//                              │ trans │ trans │ trans │ 0  │
//                              └───────┴───────┴───────┴────┘
[2] = LAYOUT_voyager(
  KC_ESCAPE , KC_F1   , KC_F2   , KC_F3    , KC_F4   , KC_F5          ,                                   KC_F6    , KC_F7 , KC_F8 , KC_F9 , KC_F10   , KC_F11   ,
  KC_GRAVE  , KC_LABK , KC_RABK , KC_LPRN  , KC_RPRN , KC_ASTR        ,                                   KC_BSLS  , KC_7  , KC_8  , KC_9  , KC_SLASH , KC_F12   ,
  KC_TILD   , KC_LBRC , KC_RBRC , KC_LCBR  , KC_RCBR , KC_EQUAL       ,                                   KC_PLUS  , KC_6  , KC_5  , KC_4  , KC_ASTR  , KC_DELETE,
  KC_AMPR   , KC_QUES , KC_DOT  , KC_COMMA , KC_EXLM , KC_DLR         ,                                   KC_MINUS , KC_1  , KC_2  , KC_3  , KC_EQUAL , KC_INSERT,
                                                       KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_0
),

//    ┌─────────┬────────────────────┬──────────────────┬───────────────┬────────────────┬─────────────────┐               ┌─────────────────┬─────────┬───────┬───────┬───────────┬─────────┐
//    │ RGB_TOG │ TOGGLE_LAYER_COLOR │ RGB_MODE_FORWARD │    RGB_SLD    │    RGB_VAD     │     RGB_VAI     │               │      trans      │  trans  │ trans │ trans │   trans   │ QK_BOOT │
//    ├─────────┼────────────────────┼──────────────────┼───────────────┼────────────────┼─────────────────┤               ├─────────────────┼─────────┼───────┼───────┼───────────┼─────────┤
//    │  mprv   │       trans        │       vold       │     volu      │      mute      │      trans      │               │ LCTL(LSFT(tab)) │  home   │  up   │  end  │   trans   │  trans  │
//    ├─────────┼────────────────────┼──────────────────┼───────────────┼────────────────┼─────────────────┤               ├─────────────────┼─────────┼───────┼───────┼───────────┼─────────┤
//    │  trans  │      left_GUI      │     left_ALT     │   left_CTRL   │   left_SHIFT   │      trans      │               │    LCTL(tab)    │  left   │ down  │ rght  │ rght_CTRL │  trans  │
//    ├─────────┼────────────────────┼──────────────────┼───────────────┼────────────────┼─────────────────┤               ├─────────────────┼─────────┼───────┼───────┼───────────┼─────────┤
//    │  trans  │     left_CTRL      │    left_SHIFT    │ HSV_0_255_255 │ HSV_74_255_255 │ HSV_169_255_255 │               │      trans      │ pAGE_UP │ pgdn  │ trans │   trans   │  trans  │
//    └─────────┴────────────────────┴──────────────────┴───────────────┴────────────────┼─────────────────┼───────┬───────┼─────────────────┼─────────┴───────┴───────┴───────────┴─────────┘
//                                                                                       │      trans      │ trans │ trans │      trans      │
//                                                                                       └─────────────────┴───────┴───────┴─────────────────┘
[3] = LAYOUT_voyager(
  RGB_TOG             , TOGGLE_LAYER_COLOR , RGB_MODE_FORWARD  , RGB_SLD         , RGB_VAD        , RGB_VAI         ,                                   KC_TRANSPARENT     , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , QK_BOOT       ,
  KC_MEDIA_PREV_TRACK , KC_TRANSPARENT     , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , KC_AUDIO_MUTE  , KC_TRANSPARENT  ,                                   LCTL(LSFT(KC_TAB)) , KC_HOME        , KC_UP          , KC_END         , KC_TRANSPARENT , KC_TRANSPARENT,
  KC_TRANSPARENT      , KC_LEFT_GUI        , KC_LEFT_ALT       , KC_LEFT_CTRL    , KC_LEFT_SHIFT  , KC_TRANSPARENT  ,                                   LCTL(KC_TAB)       , KC_LEFT        , KC_DOWN        , KC_RIGHT       , KC_RIGHT_CTRL  , KC_TRANSPARENT,
  KC_TRANSPARENT      , KC_LEFT_CTRL       , KC_LEFT_SHIFT     , HSV_0_255_255   , HSV_74_255_255 , HSV_169_255_255 ,                                   KC_TRANSPARENT     , KC_PAGE_UP     , KC_PGDN        , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT
),

//    ┌───────────────────┬───────────────────┬───────┬───────┬───────┬───────────────┐               ┌───────────────┬─────────────────┬──────────┬──────────┬───────────────────┬───────┐
//    │ NAVIGATOR_DEC_CPI │ NAVIGATOR_INC_CPI │ trans │ trans │ trans │    QK_LLCK    │               │     trans     │      trans      │  trans   │  trans   │       trans       │ trans │
//    ├───────────────────┼───────────────────┼───────┼───────┼───────┼───────────────┤               ├───────────────┼─────────────────┼──────────┼──────────┼───────────────────┼───────┤
//    │       trans       │       trans       │ trans │ trans │ trans │ TOGGLE_SCROLL │               │     trans     │      trans      │  trans   │  trans   │ mS_JIGGLER_TOGGLE │ trans │
//    ├───────────────────┼───────────────────┼───────┼───────┼───────┼───────────────┤               ├───────────────┼─────────────────┼──────────┼──────────┼───────────────────┼───────┤
//    │       trans       │       trans       │ btn3  │ btn2  │ btn1  │  DRAG_SCROLL  │               │  left_SHIFT   │    left_CTRL    │ left_ALT │ left_GUI │       trans       │ trans │
//    ├───────────────────┼───────────────────┼───────┼───────┼───────┼───────────────┤               ├───────────────┼─────────────────┼──────────┼──────────┼───────────────────┼───────┤
//    │       trans       │       ms_l        │ ms_d  │ ms_u  │ ms_r  │     trans     │               │ NAVIGATOR_AIM │ NAVIGATOR_TURBO │  trans   │  trans   │       trans       │ trans │
//    └───────────────────┴───────────────────┴───────┴───────┴───────┼───────────────┼───────┬───────┼───────────────┼─────────────────┴──────────┴──────────┴───────────────────┴───────┘
//                                                                    │     trans     │ trans │ trans │     trans     │
//                                                                    └───────────────┴───────┴───────┴───────────────┘
[4] = LAYOUT_voyager(
  NAVIGATOR_DEC_CPI , NAVIGATOR_INC_CPI , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , QK_LLCK        ,                                   KC_TRANSPARENT , KC_TRANSPARENT  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT       , KC_TRANSPARENT,
  KC_TRANSPARENT    , KC_TRANSPARENT    , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , TOGGLE_SCROLL  ,                                   KC_TRANSPARENT , KC_TRANSPARENT  , KC_TRANSPARENT , KC_TRANSPARENT , KC_MS_JIGGLER_TOGGLE , KC_TRANSPARENT,
  KC_TRANSPARENT    , KC_TRANSPARENT    , KC_MS_BTN3     , KC_MS_BTN2     , KC_MS_BTN1     , DRAG_SCROLL    ,                                   KC_LEFT_SHIFT  , KC_LEFT_CTRL    , KC_LEFT_ALT    , KC_LEFT_GUI    , KC_TRANSPARENT       , KC_TRANSPARENT,
  KC_TRANSPARENT    , KC_MS_LEFT        , KC_MS_DOWN     , KC_MS_UP       , KC_MS_RIGHT    , KC_TRANSPARENT ,                                   NAVIGATOR_AIM  , NAVIGATOR_TURBO , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT       , KC_TRANSPARENT,
                                                                                             KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT
),

//    ┌────────────┬───────┬───────┬───────┬───────┬───────┐           ┌───────┬───────┬───────┬───────┬───────┬───────┐
//    │   trans    │ trans │ trans │ trans │ trans │ trans │           │ trans │ trans │ trans │ trans │ trans │ trans │
//    ├────────────┼───────┼───────┼───────┼───────┼───────┤           ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │    esc     │ trans │ trans │ trans │ trans │ trans │           │ trans │ trans │  up   │ trans │ trans │ trans │
//    ├────────────┼───────┼───────┼───────┼───────┼───────┤           ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │ left_SHIFT │   a   │   s   │   d   │   f   │ trans │           │ trans │ left  │ down  │ rght  │   ;   │ trans │
//    ├────────────┼───────┼───────┼───────┼───────┼───────┤           ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │   TO(0)    │ trans │ trans │ trans │ trans │ trans │           │ trans │ trans │ trans │ trans │ btn1  │ btn2  │
//    └────────────┴───────┴───────┴───────┴───────┼───────┼─────┬─────┼───────┼───────┴───────┴───────┴───────┴───────┘
//                                                 │  spc  │ tab │ ent │ bspc  │
//                                                 └───────┴─────┴─────┴───────┘
[5] = LAYOUT_voyager(
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
  KC_ESCAPE      , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                     KC_TRANSPARENT , KC_TRANSPARENT , KC_UP          , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
  KC_LEFT_SHIFT  , KC_A           , KC_S           , KC_D           , KC_F           , KC_TRANSPARENT ,                     KC_TRANSPARENT , KC_LEFT        , KC_DOWN        , KC_RIGHT       , KC_SCLN        , KC_TRANSPARENT,
  TO(0)          , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_MS_BTN1     , KC_MS_BTN2    ,
                                                                                       KC_SPACE       , KC_TAB , KC_ENTER , KC_BSPC
),

//    ┌─────────┬───────┬───────┬───────┬───────┬───────┐               ┌───────┬───────┬───────┬───────┬───────┬───────┐
//    │  trans  │ trans │ trans │ trans │ trans │ trans │               │ trans │ trans │ trans │ trans │ trans │ trans │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┤               ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │ QK_LLCK │ trans │ trans │  up   │ trans │ trans │               │ trans │ trans │ trans │ trans │ trans │ trans │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┤               ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │  trans  │ trans │ left  │ down  │ rght  │ trans │               │ trans │ trans │ trans │ trans │ trans │ trans │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┤               ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │  trans  │ trans │ trans │ trans │ trans │ trans │               │ trans │ trans │ trans │ trans │ trans │ trans │
//    └─────────┴───────┴───────┴───────┴───────┼───────┼───────┬───────┼───────┼───────┴───────┴───────┴───────┴───────┘
//                                              │ trans │ trans │ trans │ trans │
//                                              └───────┴───────┴───────┴───────┘
[6] = LAYOUT_voyager(
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
  QK_LLCK        , KC_TRANSPARENT , KC_TRANSPARENT , KC_UP          , KC_TRANSPARENT , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
  KC_TRANSPARENT , KC_TRANSPARENT , KC_LEFT        , KC_DOWN        , KC_RIGHT       , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                                   KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                                                       KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT
),

//    ┌───────┬───────────────┬───────────────┬───────────────┬───────────────┬──────────┐              ┌───────┬───────┬───────┬───────┬──────────────┬───────┐
//    │ trans │     trans     │     trans     │     trans     │     trans     │  trans   │              │ trans │ trans │ trans │ trans │    trans     │ trans │
//    ├───────┼───────────────┼───────────────┼───────────────┼───────────────┼──────────┤              ├───────┼───────┼───────┼───────┼──────────────┼───────┤
//    │ trans │     trans     │     trans     │     trans     │     trans     │ LALT(f4) │              │ trans │ trans │ trans │ trans │ system_power │ trans │
//    ├───────┼───────────────┼───────────────┼───────────────┼───────────────┼──────────┤              ├───────┼───────┼───────┼───────┼──────────────┼───────┤
//    │ trans │ OSM(MOD_LGUI) │ OSM(MOD_LALT) │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │  TO(5)   │              │ trans │ trans │ trans │ trans │    trans     │ trans │
//    ├───────┼───────────────┼───────────────┼───────────────┼───────────────┼──────────┤              ├───────┼───────┼───────┼───────┼──────────────┼───────┤
//    │ trans │     trans     │     trans     │     trans     │     trans     │  trans   │              │ trans │ trans │ trans │ trans │    trans     │ trans │
//    └───────┴───────────────┴───────────────┴───────────────┴───────────────┼──────────┼──────┬───────┼───────┼───────┴───────┴───────┴──────────────┴───────┘
//                                                                            │ CW_TOGG  │ caps │ trans │ trans │
//                                                                            └──────────┴──────┴───────┴───────┘
[7] = LAYOUT_voyager(
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                            KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  , KC_TRANSPARENT,
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , LALT(KC_F4)    ,                            KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_SYSTEM_POWER , KC_TRANSPARENT,
  KC_TRANSPARENT , OSM(MOD_LGUI)  , OSM(MOD_LALT)  , OSM(MOD_LCTL)  , OSM(MOD_LSFT)  , TO(5)          ,                            KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  , KC_TRANSPARENT,
  KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,                            KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  , KC_TRANSPARENT,
                                                                                       CW_TOGG        , KC_CAPS , KC_TRANSPARENT , KC_TRANSPARENT
)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT('L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', '*', '*', '*', '*');

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MODS ... QK_MODS_MAX:
            // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
            // this makes sure that modifiers are always applied to the key that was pressed.
            if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
                if (record->event.pressed) {
                    add_mods(QK_MODS_GET_MODS(keycode));
                    send_keyboard_report();
                    wait_ms(2);
                    register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
                    return false;
                } else {
                    wait_ms(2);
                    del_mods(QK_MODS_GET_MODS(keycode));
                }
            }
            break;

        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case HSV_0_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0, 255, 255);
            }
            return false;
        case HSV_74_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(74, 255, 255);
            }
            return false;
        case HSV_169_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(169, 255, 255);
            }
            return false;
    }
    return true;
}
