#include "types.h"

// Boot-time memory-card window seed (.ctors entry).
// File-scope statics with runtime-init members: MWCC emits the constant
// image as a template in .data and synthesizes __sinit_text_8033C69C_cpp
// that computes the float geometry and copies the state-action table.

extern "C" {
extern const f32 lbl_80477DB4[2];
extern const f32 lbl_80477DBC[2];
}

class TWindowSubComCard {
public:
    void poll_card_status();
    void handle_menu_selection();
    void update_display_state();
    void close_and_update_display();
    void sub_8033C178();
    void sub_8033C198();
    void sub_8033C19C();
    void init_from_keyboard_state();
};

typedef void (TWindowSubComCard::*TWindowSubComCardAction)();

struct TWindowSubComCardStateActions {
    TWindowSubComCardAction enter;
    TWindowSubComCardAction update;
};

#pragma push
#pragma opt_propagation off

__declspec(section ".data") static f32 menu_geom_804EF8D8[2] = {
    20.0f + lbl_80477DB4[0],
    10.0f + (lbl_80477DB4[1] + lbl_80477DBC[1]),
};

static f32 menu_layout_height_805D6D98 = lbl_80477DBC[0] - 40.0f;

static TWindowSubComCardStateActions menu_state_actions_804EF940[4] = {
    {&TWindowSubComCard::close_and_update_display, &TWindowSubComCard::update_display_state},
    {&TWindowSubComCard::sub_8033C19C, &TWindowSubComCard::sub_8033C198},
    {&TWindowSubComCard::sub_8033C178, &TWindowSubComCard::poll_card_status},
    {&TWindowSubComCard::init_from_keyboard_state, &TWindowSubComCard::handle_menu_selection},
};

#pragma pop
