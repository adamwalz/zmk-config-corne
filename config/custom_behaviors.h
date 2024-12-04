//
// SELECT_WORD_DELAY defines how long the macro waits (milliseconds)
// after moving the cursor before it selects a word.  A larger delay
// may allow the macro to move to the next word upon each invocation.
//
#define SELECT_WORD_DELAY 1

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

//
// select current line
//
ZMK_MACRO(select_line_right,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp _HOME &kp LS(LG(RIGHT))>;
)
ZMK_MACRO(select_line_left,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp _END &kp LS(LG(LEFT))>;
)
ZMK_MOD_MORPH(select_line,
    bindings = <&select_line_right>, <&select_line_left>;
    mods = <(LSHIFT|RSHIFT)>;
)

//
// extend current selection by one line
//
ZMK_MACRO(extend_line_right,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LS(DOWN) &kp LS(LG(RIGHT))>;
)
ZMK_MACRO(extend_line_left,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LS(UP) &kp LS(LG(LEFT))>;
)
ZMK_MOD_MORPH(extend_line,
    bindings = <&extend_line_right>, <&extend_line_left>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

//
// select a word (jumps to next word upon each successive invocation)
//
ZMK_MACRO(select_word_right,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(RIGHT) &kp LA(LEFT) &kp LA(LS(RIGHT))>;
)
ZMK_MACRO(select_word_left,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(LEFT) &kp LA(RIGHT) &kp LA(LS(LEFT))>;
)
ZMK_MOD_MORPH(select_word,
    bindings = <&select_word_right>, <&select_word_left>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

//
// extend current selection by one word
//
ZMK_MACRO(extend_word_right,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(LS(RIGHT))>;
)
ZMK_MACRO(extend_word_left,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(LS(LEFT))>;
)
ZMK_MOD_MORPH(extend_word,
    bindings = <&extend_word_right>, <&extend_word_left>;
    mods = <(LSHIFT|RSHIFT)>;
)

ZMK_MACRO_ONE_PARAM(bt_sel,
    bindings = <&out OUT_BLE>, <&macro_param_1to2>, <&bt BT_SEL MACRO_PLACEHOLDER>;
)

// combos
ZMK_COMBO(copy_cut, &copy_cut,   LB2 LB3, ALL)  // copy on tap, cut on double-tap, active on all layers
ZMK_COMBO(paste,    &kp LS(INS), LB1 LB2, ALL)  // paste, active on all layers
