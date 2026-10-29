#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TOKeyCol.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/protocol/protocol_types.h"

const char *TOKeyCol__name = "TOKeyCol";

void TOKeyCol::vfunc_25() {}

// Pressed while a player stands on it (in once mode, latched once on).
s32 TOKeyCol::is_confirm_pressed() {
    s32 pressed = 0;
    s32 in_range;

    switch (mode) {
    case KEY_MODE_ONCE:
        if (is_split_screen() == 1) {
            in_range = is_any_player_in_range();
        } else {
            in_range = is_local_player_in_range();
        }
        if (is_on == 1 || in_range == 1) {
            pressed = 1;
        }
        break;
    case KEY_MODE_TOGGLE:
        pressed = is_any_player_in_range();
        break;
    }
    return pressed;
}

void TOKeyCol::send_switch_changed(s32 flags) {
    G_SwitchStateChanged_6x05 cmd;
    cmd.init();
    cmd.header.client_id = entity_id;
    cmd.unused1 = local_client_id;
    cmd.switch_id = switch_id;
    cmd.floor = get_current_floor();
    cmd.flags = flags;
    cmd.send();
}

void TOKeyCol::trigger_deactivate_sound() {}

void TOKeyCol::trigger_activate_sound() {}

void TOKeyCol::update_switch_off() {}

void TOKeyCol::update_switch_on() {}

void TOKeyCol::run_task() {
    update_lock_state();
    if (is_on != 1) {
        update_switch_off();
        if (is_confirm_pressed() == 1) {
            send_switch_changed(1);
            trigger_activate_sound();
            is_on = 1;
        }
    } else {
        update_switch_on();
        if (is_confirm_pressed() != 1) {
            send_switch_changed(0);
            trigger_deactivate_sound();
            is_on = 0;
        }
    }
}

void TOKeyCol::render() {}

void *TOKeyCol::create(void *set_data) {
    return new TOKeyCol(tl_05, set_data);
}

TOKeyCol::~TOKeyCol() {}

TOKeyCol::TOKeyCol(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = TOKeyCol__name;
    apply_object_set_data(set_data);
    init_switch_id();
    m_c0 = 400.0f;
    model_radius = 50.0f;
    activate_range = 10.0f + scale.x;
    if (mode != KEY_MODE_NONE && set_params[1] < 0) {
        mode = KEY_MODE_TOGGLE;
    } else {
        mode = KEY_MODE_ONCE;
    }
}
