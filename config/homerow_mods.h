#define LEFT_HAND_KEYS   LN6 LN5 LN4 LN3 LN2 LN1 LN0 \
                         LT6 LT5 LT4 LT3 LT2 LT1 LT0 \
                         LM6 LM5 LM4 LM3 LM2 LM1 LM0 \
                         LB5 LB4 LB3 LB2 LB1 LB0 \
                         LF4 LF3 LF2 LF1 LF0

#define RIGHT_HAND_KEYS  RN0 RN1 RN2 RN3 RN4 RN5 RN6 \
                         RT0 RT1 RT2 RT3 RT4 RT5 RT6 \
                         RM0 RM1 RM2 RM3 RM4 RM5 RM6 \
                             RB0 RB1 RB2 RB3 RB4 RB5 \
                                 RF0 RF1 RM2 RF3 RF4

#define THUMB_KEYS           LH5 LH4     RH4 RH5 \
                                 LH3     RH3 \
                         LH2 LH1 LH0     RH0 RH1 RH2

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
