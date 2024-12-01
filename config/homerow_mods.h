#define MAKE_HRMS(name, hold_tap_flavor, ...) \
    ZMK_HOLD_TAP(hml_ ## name, \
        flavor = hold_tap_flavor; \
        bindings = <&kp>, <&kp>; \
        hold-trigger-key-positions = <RIGHT_HAND_KEYS THUMB_KEYS>; \
        __VA_ARGS__ \
    ) \
    ZMK_HOLD_TAP(hmr_ ## name, \
        flavor = hold_tap_flavor; \
        bindings = <&kp>, <&kp>; \
        hold-trigger-key-positions = <LEFT_HAND_KEYS THUMB_KEYS>; \
        __VA_ARGS__ \
    )

MAKE_HRMS(homes, "balanced",
    hold-trigger-on-release;  // wait for other home row mods
    tapping-term-ms = <270>;
    quick-tap-ms = <QUICK_TAP_MS>;
    require-prior-idle-ms = <170>;
)
MAKE_HRMS(shift, "tap-preferred",
    tapping-term-ms = <170>;
    quick-tap-ms = <QUICK_TAP_MS>;
    require-prior-idle-ms = <70>;
)

// Base Layer home row mods
#define A_LCTRL     &hml_homes LCTRL A
#define S_LALT      &hml_homes LALT S
#define D_LGUI      &hml_homes LGUI D
#define F_LSHFT     &hml_shift LSHFT F
#define J_RSHFT     &hmr_shift RSHFT J
#define K_RGUI      &hmr_homes RGUI K
#define L_RALT      &hmr_homes RALT L
#define SEMI_RCTRL  &hmr_homes RCTRL SEMI

// Symbol Layer home row mods
#define CARET_LCTRL     &hml_homes LCTRL A
#define EQUAL_LALT      &hml_homes LALT S
#define UNDER_LGUI      &hml_homes LGUI D
#define DLLR_LSHFT     &hml_shift LSHFT F
#define TAB_RSHFT     &hmr_shift RSHFT J
#define SPACE_RGUI      &hmr_homes RGUI K
#define ENTER_RALT      &hmr_homes RALT L
