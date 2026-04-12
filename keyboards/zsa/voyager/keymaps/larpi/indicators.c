#include QMK_KEYBOARD_H

// Home Row LED Indices
// Left:  A(13), S(14), D(15), F(16)
// Right: J(39), K(40), L(41), SCLN(42)
// Toggle: CW_TOGG(18)

bool rgb_matrix_indicators_user(void) {
    uint8_t mods = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();

    // Home Row Modifiers
    if ((mods | oneshot_mods) & MOD_BIT(MOD_LSFT)) {
        rgb_matrix_set_color(16, 255, 255, 255);
    }
    if ((mods | oneshot_mods) & MOD_BIT(MOD_RSFT)) {
        rgb_matrix_set_color(39, 255, 255, 255);
    }
    if ((mods | oneshot_mods) & MOD_BIT(MOD_LCTL)) {
        rgb_matrix_set_color(15, 255, 255, 255);
        rgb_matrix_set_color(40, 255, 255, 255);
    }
    if ((mods | oneshot_mods) & MOD_BIT(MOD_LALT)) {
        rgb_matrix_set_color(14, 255, 255, 255);
    }
    if ((mods | oneshot_mods) & MOD_BIT(MOD_RALT)) {
        rgb_matrix_set_color(41, 255, 255, 255);
    }
    if ((mods | oneshot_mods) & MOD_BIT(MOD_LGUI)) {
        rgb_matrix_set_color(13, 255, 255, 255);
    }
    if ((mods | oneshot_mods) & MOD_BIT(MOD_RGUI)) {
        rgb_matrix_set_color(42, 255, 255, 255);
    }

    // Caps Word indicator (Yellow)
    if (is_caps_word_on()) {
        rgb_matrix_set_color(18, 255, 255, 0);
    }

    // Caps Lock indicator (Red) - takes priority over Caps Word if both on
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(18, 255, 0, 0);
    }

    return true;
}
