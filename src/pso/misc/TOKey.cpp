// TOKey: the switch keys and their 6x05 switch command.
//
// Deferred code generation (configure.py): the functions come out in reverse
// order, so this file is written from its last function back.
#include "types.h"
#include "pso/render/render_util.h"
#include "pso/misc/TOKey.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TSwitch.h"
#include "pso/network/client_id.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/protocol/protocol_types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/TProtocol.h"
#include "pso/unk/text_803D853C.h"

extern "C" {
s32 TWindowShortListCtrl__check_controller_button(ControllerInputContext *context, s32 button);
}

const char *TOKey__class_name = "TOKey";

void CursorAction::set_use() { kind = CURSOR_ACTION_USE; }

void init_6x04_packet(G_SwitchStateChanged_6x05 *cmd) {
    cmd->unused2 = 0;
    cmd->header.subcommand = 4;
    cmd->header.size = 2;
}

G_SwitchStateChanged_6x05 *G_SwitchStateChanged_6x05::init() {
    init_6x04_packet(this);
    header.subcommand = 5;
    header.size = 3;
    return this;
}

void G_SwitchStateChanged_6x05::send() {
    bswap();
    send_subcommand(this);
}

void G_SwitchStateChanged_6x05::bswap() {
    header.bswap();
    bswap_16(&switch_id);
}

void TOKey::vfunc_25() {}

void TOKey::update_switch_off() {}

void TOKey::update_switch_on() {}

TOKey::TOKey(TObject *parent) : TObjMapObject(parent) {
    m_name = TOKey__class_name;
    switch_id = -1;
    activate_range = 20.0f;
    mode = KEY_MODE_NONE;
    is_on = 0;
    press_pending = 0;
    press_delay = 28;
    press_timer = 28;
    cursor_action.set_use();
    in_view = 0;
}

TOKey::~TOKey() {}

void TOKey::init_key(void *set_entry) {
    apply_object_set_data(set_entry);
    init_switch_id();
    VecCopy(&center, &position);
    m_20 = 2;
}

void TOKey::init_switch_id() {
    s32 id = set_params[0];
    if (id < 0 || id > 0xFF) {
        switch_id = -1;
        mode = KEY_MODE_NONE;
        return;
    }
    switch_id = id;
    mode = KEY_MODE_ONCE;
}

void TOKey::run_task() {
    update_armed_switch();
    in_view = 0;
}

void TOKey::debug_draw_key_id() {
    set_params[0] = set_params[0] % 256;
    if (set_params[0] < 0 || set_params[0] > 0xFF) {
        switch_id = -1;
        mode = KEY_MODE_NONE;
    } else {
        switch_id = set_params[0];
        mode = KEY_MODE_ONCE;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "<- KEY ID : %d", switch_id);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    vfunc_25();
}

void TOKey::update_armed_switch() {
    update_lock_state();
    switch (is_on) {
    case 0:
        if (press_pending != 0) {
            if (--press_timer < 0) {
                send_switch_on();
                press_pending = 0;
            }
        }
        update_switch_off();
        return;
    case 1:
        update_switch_on();
        press_pending = 0;
        return;
    }
}

void TOKey::update_lock_state() {
    u8 set;

    if (mode != KEY_MODE_NONE) {
        set = is_current_floor_switch_set((u16)switch_id);
        if (set == 0) {
            is_on = 0;
        }
        if (set == 1) {
            is_on = 1;
        }
    }
}

void TOKey::trigger_activate_sound() {
    play_activate_sound();
}

void TOKey::play_activate_sound() {
    switch (get_current_floor_area()) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        switch (mode) {
        case KEY_MODE_ONCE:
            play_sound_effect(0x4C60A, &position, 0, 0);
            return;
        case KEY_MODE_TOGGLE:
            play_sound_effect(0x4AD0B, &position, 0, 0);
            return;
        }
        break;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        switch (mode) {
        case KEY_MODE_ONCE:
            play_sound_effect(0x44609, &position, 0, 0);
            return;
        case KEY_MODE_TOGGLE:
            play_sound_effect(0x42D0A, &position, 0, 0);
            return;
        }
        break;
    case AREA_MINE1:
    case AREA_MINE2:
        switch (mode) {
        case KEY_MODE_ONCE:
            play_sound_effect(0x4004C603, &position, 0, 0);
            return;
        case KEY_MODE_TOGGLE:
            play_sound_effect(0x4004AD04, &position, 0, 0);
            return;
        }
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        switch (mode) {
        case KEY_MODE_ONCE:
            play_sound_effect(0x4004C60A, &position, 0, 0);
            return;
        case KEY_MODE_TOGGLE:
            play_sound_effect(0x4004AD0B, &position, 0, 0);
            return;
        }
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if (enable_v2_features == 1) {
            switch (mode) {
            case KEY_MODE_ONCE:
                play_sound_effect(0x4004C601, &position, 0, 0);
                return;
            case KEY_MODE_TOGGLE:
                play_sound_effect(0x4004AD02, &position, 0, 0);
                return;
            }
        }
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4C601, &position, 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004C601, &position, 0, 0);
        return;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4C611, &position, 0, 0);
        return;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4004C611, &position, 0, 0);
        return;
    case AREA_TOWER:
        play_sound_effect(0x4004C611, &position, 0, 0);
        return;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004C611, &position, 0, 0);
        break;
    }
}

void TOKey::trigger_deactivate_sound() {
    play_deactivate_sound();
}

void TOKey::play_deactivate_sound() {
    switch (get_current_floor_area()) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_sound_effect(0x4AD0C, &position, 0, 0);
        break;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x42D0B, &position, 0, 0);
        break;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004AD05, &position, 0, 0);
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004AD0C, &position, 0, 0);
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if (enable_v2_features == 1) {
            play_sound_effect(0x4004AD03, &position, 0, 0);
            break;
        }
    default:
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4AD03, &position, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004AD03, &position, 0, 0);
        break;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4AD13, &position, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4004AD13, &position, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4004AD13, &position, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004AD13, &position, 0, 0);
        break;
    }
}

void TOKey::submit_cursor_target() {
    switch (mode) {
    case KEY_MODE_ONCE:
        switch (is_on) {
        case 0:
            if (in_view == 1) {
                submit_cursor_candidate(this, -1);
            }
            break;
        }
        break;
    case KEY_MODE_TOGGLE:
        if (in_view == 1) {
            submit_cursor_candidate(this, -1);
        }
        break;
    }
}

s32 TOKey::is_confirm_pressed() {
    s32 m = mode;

    if (m == KEY_MODE_NONE) {
        return 0;
    }
    if (m == KEY_MODE_ONCE && is_on == 1) {
        return 0;
    }
    if (is_local_player_in_range() != 0 &&
        TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 4) != 0) {
        return 1;
    }
    return 0;
}

s32 TOKey::is_local_player_in_range() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        if (player->get_floor() == get_current_floor()) {
            if (xyz_distance_squared(&player->position, &position) < activate_range * activate_range) {
                return 1;
            }
        }
    }
    return 0;
}

s32 TOKey::is_any_player_in_range() {
    TObjPlayer *player;
    s32 i;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player != NULL) {
            if (player->get_floor() == get_current_floor()) {
                if (xyz_distance_squared(&player->position, &position) < activate_range * activate_range) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TOKey::send_switch_on() {
    G_SwitchStateChanged_6x05 cmd;
    cmd.init();
    cmd.header.client_id = entity_id;
    cmd.unused1 = 0;
    cmd.switch_id = switch_id;
    cmd.floor = get_current_floor();
    cmd.flags = 1;
    cmd.send();
}

void TOKey::interact(s32 client) {
    s32 m = mode;
    TObjPlayer *player;

    if (m != KEY_MODE_NONE && (m != KEY_MODE_ONCE || is_on != 1)) {
        player = get_player_by_client_id((u16)client);
        if (player != NULL) {
            player->start_camera_pan(0xC, calc_angle_to(&player->position, &position));
            press_timer = press_delay;
            press_pending = 1;
        }
    }
}

void handle_6x05_write_switch_flag(void *data) {
    G_SwitchStateChanged_6x05 *cmd = (G_SwitchStateChanged_6x05 *)data;
    TObjCollidable *entity;

    cmd->bswap();
    entity = find_entity_by_id(cmd->header.client_id);
    if (entity != NULL) {
        ((TOKey *)entity)->handle_switch_trigger(cmd);
        return;
    }
    if ((cmd->flags & 2) && cmd->floor == get_current_floor()) {
        play_sound_effect(0x4005281F, NULL, 0, 0);
    }
    if (cmd->flags & 1) {
        set_floor_switch_flag(cmd->switch_id, cmd->floor);
        return;
    }
    clear_floor_switch_flag(cmd->switch_id, cmd->floor);
}

void TOKey::handle_switch_trigger(G_SwitchStateChanged_6x05 *cmd) {
    if ((cmd->flags & 2) && cmd->floor == get_current_floor()) {
        play_sound_effect(0x4005281F, NULL, 0, 0);
    }
    if (cmd->flags & 1) {
        set_current_floor_switch(cmd->switch_id);
    } else {
        clear_current_floor_switch(cmd->switch_id);
    }
    switch (is_on) {
    case 0:
        trigger_activate_sound();
        is_on = 1;
        return;
    case 1:
        trigger_deactivate_sound();
        is_on = 0;
        return;
    }
}

s32 TOKey::update_object_view_visibility(f32 near, f32 far) {
    if (TObjMapObject::update_object_view_visibility(near, far) == 1) {
        in_view = 1;
        return 1;
    }
    return 0;
}
