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

// balanced: treats quick-press and long-press actions equally; decides based solely on press duration
// tap-preferred: favors quick-press actions; makes typing letters easier but requires more deliberate long-presses
// hold-trigger-on-release: waits until you let go of key to decide if it was a modifier action, reducing accidental modifiers
// tapping-term-ms: maximum time in milliseconds to determine if you wanted a letter or a modifier function
// quick-tap-ms: time window where pressing the same key twice quickly always produces the letter, not the modifier
// require-prior-idle-ms: time your finger must be still before pressing to enable the modifier function

MAKE_HRMS(ctrl, "balanced",
    hold-trigger-on-release;
    tapping-term-ms = <270>;
    quick-tap-ms = <QUICK_TAP_MS>;
    require-prior-idle-ms = <170>;
)
MAKE_HRMS(alt, "balanced",
    hold-trigger-on-release;
    tapping-term-ms = <270>;
    quick-tap-ms = <QUICK_TAP_MS>;
    require-prior-idle-ms = <170>;
)
MAKE_HRMS(gui, "balanced",
    hold-trigger-on-release;
    tapping-term-ms = <300>;
    quick-tap-ms = <QUICK_TAP_MS>;
    require-prior-idle-ms = <190>;
)
MAKE_HRMS(shift, "balanced",
    tapping-term-ms = <170>;
    quick-tap-ms = <QUICK_TAP_MS>;
    require-prior-idle-ms = <70>;
)

// Base Layer home row mods
#define A_LCTRL     &hml_ctrl LCTRL A
#define S_LALT      &hml_alt LALT S
#define D_LGUI      &hml_gui LGUI D
#define F_LSHFT     &hml_shift LSHFT F
#define J_RSHFT     &hmr_shift RSHFT J
#define K_RGUI      &hmr_gui RGUI K
#define L_RALT      &hmr_alt RALT L
#define SEMI_RCTRL  &hmr_ctrl RCTRL SEMI

// Symbol Layer home row mods
#define CARET_LCTRL     &hml_ctrl LCTRL CARET
#define EQUAL_LALT      &hml_alt LALT EQUAL
#define AMPS_LALT       &hml_alt LALT AMPS
#define UNDER_LGUI      &hml_gui LGUI UNDER
#define DLLR_LSHFT      &hml_shift LSHFT DLLR
