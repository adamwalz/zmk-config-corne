ZMK_HOLD_TAP(thumb,
    flavor = "balanced";
    bindings = <&mo>, <&kp>;
    tapping-term-ms = <200>;
    quick-tap-ms = <300>;
    // no typing streak
)

ZMK_HOLD_TAP(space,
    flavor = "balanced";
    bindings = <&mo>, <&kp>;
    tapping-term-ms = <170>;
    quick-tap-ms = <200>;
    // no typing streak
    retro-tap; // allow slow (hold-like) taps
)

// tap: copy
// double-tap: cut
ZMK_TAP_DANCE(copy_cut,
    tapping-term-ms = <200>;
    bindings = <&kp LC(INS)>, <&kp LC(X)>;
)

ZMK_TAP_DANCE(kp_dot_comma,
    tapping-term-ms = <200>;
    bindings = <&kp KP_DOT>, <&kp COMMA>;
)

ZMK_TAP_DANCE(kp_plus_kp_multiply,
    tapping-term-ms = <200>;
    bindings = <&kp KP_PLUS>, <&kp KP_MULTIPLY>;
)

ZMK_TAP_DANCE(kp_minus_kp_slash,
    tapping-term-ms = <200>;
    bindings = <&kp KP_MINUS>, <&kp KP_SLASH>;
)

// tap: sticky-shift 
// shift + tap/ double-tap: caps-word
// hold: shift
ZMK_MOD_MORPH(smart_shft,
    bindings = <&sk LSHFT>, <&caps_word>;
    mods = <(MOD_LSFT)>;
)

ZMK_MACRO_ONE_PARAM(bt_sel,
    bindings = <&out OUT_BLE>, <&macro_param_1to2>, <&bt BT_SEL MACRO_PLACEHOLDER>;
)

// combos
ZMK_COMBO(copy_cut, &copy_cut,   LB2 LB3, ALL)  // copy on tap, cut on double-tap, active on all layers
ZMK_COMBO(paste,    &kp LS(INS), LB1 LB2, ALL)  // paste, active on all layers
