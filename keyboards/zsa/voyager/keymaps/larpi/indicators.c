#include QMK_KEYBOARD_H

// Voyager Home Row LED Indices
// Left:  A(13), S(14), D(15), F(16)
// Right: J(39), K(40), L(41), SCLN(42)
// Toggle: CW_TOGG(18)

// Number Row LED Indices
// Left:  1(1), 2(2), 3(3), 4(4), 5(5)
// Right: 6(26), 7(27), 8(28), 9(29), 0(30)

#define DEFAULT_ACTIVE_COLOR 0xFFFFFF
#define DEFAULT_INACTIVE_COLOR 0x000000
#define DEFAULT_ERROR_COLOR 0xFF0000
#define DEFAULT_WARNING_COLOR 0xFFFF00
#define LAYER_INDICATOR_COLOR 0xCE96F3

#define unpack_color(rgb) ((rgb >> 16) & 0xFF), ((rgb >> 8) & 0xFF), (rgb & 0xFF)
#define pack_color(r, g, b) ((r << 16) | (g << 8) | b)

static uint8_t g_previous_layer = 0;

static uint8_t get_num_key(uint8_t num) {
    static uint8_t s_row_leds[] = {1, 2, 3, 4, 5, 26, 27, 28, 29, 30};

    return s_row_leds[num];
}

static int is_led_off(void) {
    return !rgb_matrix_is_enabled() || rgb_matrix_get_val() == 0 || rgb_matrix_get_flags() == LED_FLAG_NONE;
}

static uint32_t get_inactive_color(void) {
    if (is_led_off()) {
        return DEFAULT_INACTIVE_COLOR;
    }

    hsv_t hsv = rgb_matrix_get_hsv();
    // If saturation is very low, it's effectively white/grayscale, 
    // but hue 0 would still return red in hsv_to_rgb.
    if (hsv.s < 5) {
        return pack_color(hsv.v, hsv.v, hsv.v);
    }

    rgb_t base_rgb = hsv_to_rgb(hsv);
    return pack_color(base_rgb.r, base_rgb.g, base_rgb.b);
}

/// Set the color of the home row indicators
static void set_hm_indicator(uint8_t index, bool active) {
    if (active) {
        rgb_matrix_set_color(index, unpack_color(DEFAULT_ACTIVE_COLOR));
    } else {
        // rgb_t base_rgb = hsv_to_rgb(rgb_matrix_config.hsv);
        // rgb_matrix_set_color(index, base_rgb.r, base_rgb.g, base_rgb.b);
        rgb_matrix_set_color(index, unpack_color(get_inactive_color()));
    }
}

static void set_layer_indicator(uint8_t layout_idx) {
    if (layout_idx == g_previous_layer) {
        return;
    }

    // Reset indicators for previous layer
    if (g_previous_layer >= 10) {
        rgb_matrix_set_color(get_num_key(g_previous_layer / 10), unpack_color(get_inactive_color()));
        rgb_matrix_set_color(get_num_key(g_previous_layer % 10), unpack_color(get_inactive_color()));
    } else {
        rgb_matrix_set_color(get_num_key(g_previous_layer), unpack_color(get_inactive_color()));
    }

    g_previous_layer = layout_idx;

    if (layout_idx >= 10) {
        rgb_matrix_set_color(get_num_key(layout_idx / 10), unpack_color(LAYER_INDICATOR_COLOR));
        rgb_matrix_set_color(get_num_key(layout_idx % 10), unpack_color(LAYER_INDICATOR_COLOR));
    } else if (layout_idx != 0) {
        rgb_matrix_set_color(get_num_key(layout_idx), unpack_color(LAYER_INDICATOR_COLOR));
    }
}


bool rgb_matrix_indicators_user(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();

    // Home Row Modifiers
    set_hm_indicator(13, mods & MOD_BIT(KC_LEFT_GUI));
    set_hm_indicator(14, mods & MOD_BIT(KC_LEFT_ALT));
    set_hm_indicator(15, mods & MOD_BIT(KC_LEFT_CTRL));
    set_hm_indicator(16, mods & MOD_BIT(KC_LEFT_SHIFT));

    set_hm_indicator(39, mods & MOD_BIT(KC_RIGHT_SHIFT));
    set_hm_indicator(40, mods & MOD_BIT(KC_LEFT_CTRL));
    set_hm_indicator(41, mods & MOD_BIT(KC_RIGHT_ALT));
    set_hm_indicator(42, mods & MOD_BIT(KC_RIGHT_GUI));

    set_layer_indicator(get_highest_layer(layer_state));

    // Caps Word / Lock
    if (is_caps_word_on()) {
        rgb_matrix_set_color(18, unpack_color(0xFFFF00)); // Yellow
    } else if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(18, unpack_color(0xFF0000)); // Red
    } else {
        rgb_matrix_set_color(18, unpack_color(get_inactive_color()));
    }

    return true;
}
