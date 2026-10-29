#include "types.h"
#include "pso/misc/TODoorBase.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TSwitch.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include "pso/TProtocol.h"

// This unit is compiled with deferred code generation (its vtable comes ahead
// of its switch tables), which emits the functions in reverse: the file is
// written from the last function back to the first.

s32 switch_doors_force_closed;

void TODoorBase::update_demo() {}

TODoorBase::TODoorBase(TObject *parent) : TObjMapObject(parent) {
    switch_id = -1;
    lock_mode = LOCK_LOCKED;
    door_flags = 0;
    object_state = DOOR_CLOSED;
    animation_step = 1.0f;
}

TODoorBase::~TODoorBase() {}

void TODoorBase::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        update_demo();
        return;
    }
    if (switch_doors_force_closed != 0) {
        object_state = DOOR_CLOSED;
        door_flags &= ~DOOR_FLAG_UNLOCKED;
        clear_player_status_flag(0, 8);
    } else {
        update_door_switch_state();
    }
    switch (object_state) {
    case DOOR_CLOSED:
        update_closed();
        break;
    case DOOR_OPENING:
        update_opening();
        break;
    case DOOR_OPEN:
        update_open();
        break;
    case DOOR_CLOSING:
        update_closing();
        break;
    }
    if (door_flags & DOOR_FLAG_UNLOCKED) {
        minimap_render_gate(&position, 0xFF00FF00, rotation_y, 0, 0);
    } else {
        minimap_render_gate(&position, 0xFFFF0000, rotation_y, 0, 0);
    }
}

void TODoorBase::update_door_switch_state() {
    switch (lock_mode) {
    case LOCK_UNLOCKED:
        play_door_sound();
        door_flags |= DOOR_FLAG_UNLOCKED;
        return;
    case LOCK_SWITCH:
        if (is_current_floor_switch_set((u16)switch_id) == 1) {
            play_door_sound();
            door_flags |= DOOR_FLAG_UNLOCKED;
            return;
        }
        door_flags &= ~DOOR_FLAG_UNLOCKED;
        return;
    case LOCK_SWITCH_LATCH:
        if (is_current_floor_switch_set((u16)switch_id) == 1) {
            play_door_sound();
            door_flags |= DOOR_FLAG_UNLOCKED;
        }
        break;
    default:
        door_flags &= ~DOOR_FLAG_UNLOCKED;
        break;
    }
}

void TODoorBase::update_closed() {
    if ((door_flags & DOOR_FLAG_UNLOCKED) && is_any_player_within_radius_xz(4900.0f) == 1) {
        object_state = DOOR_OPENING;
        set_indexed_flags(0, 8);
        switch (get_current_floor_area()) {
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_sound_effect(0x42807, &position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_sound_effect(0x4004BC01, &position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_sound_effect(0x4004B708, &position, 0, 0);
            break;
        case AREA_BATTLE1:
        case AREA_BATTLE2:
            if (enable_v2_features == 1) {
                play_sound_effect(0x4004AA0B, &position, 0, 0);
            }
            break;
        case AREA_VR_TEMPLE_ALPHA:
        case AREA_VR_TEMPLE_BETA:
            play_sound_effect(0x4BF0B, &position, 0, 0);
            break;
        case AREA_VR_SPACESHIP_ALPHA:
        case AREA_VR_SPACESHIP_BETA:
            play_sound_effect(0x4004AA0B, &position, 0, 0);
            break;
        case AREA_PIONEER2_EP2:
            play_sound_effect(0x42A04, &position, 0, 0);
            break;
        case AREA_SEABED_UPPER:
        case AREA_SEABED_LOWER:
            play_sound_effect(0x4004A80C, &position, 0, 0);
            break;
        case AREA_PIONEER2_EP1:
            break;
        }
    }
}

void TODoorBase::update_opening() {
    animation_frame += animation_step;
    if (animation_end_frame < animation_frame) {
        animation_frame = animation_end_frame;
        object_state = DOOR_OPEN;
    }
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        break;
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_persistent_sound(0x49E08, (s32)this, (u32)&position, 0, 0);
        break;
    case AREA_DARK_FALZ:
        return;
    case AREA_LOBBY:
        break;
    }
}

void TODoorBase::update_open() {
    if ((door_flags & DOOR_FLAG_UNLOCKED) && is_any_player_within_radius_xz(10000.0f) != 0) {
        return;
    }
    object_state = DOOR_CLOSING;
    clear_player_status_flag(0, 8);
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        break;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x42807, &position, 0, 0);
        break;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004BC01, &position, 0, 0);
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004B708, &position, 0, 0);
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if (enable_v2_features == 1) {
            play_sound_effect(0x4004AA0B, &position, 0, 0);
        }
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004A80C, &position, 0, 0);
        break;
    case AREA_PIONEER2_EP2:
        play_sound_effect(0x42A05, &position, 0, 0);
        break;
    }
}

void TODoorBase::update_closing() {
    animation_frame -= animation_step;
    if (animation_frame < 0.0f) {
        animation_frame = 0.0f;
        object_state = DOOR_CLOSED;
    }
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        break;
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_persistent_sound(0x49E08, (s32)this, (u32)&position, 0, 0);
        break;
    case AREA_DARK_FALZ:
        return;
    case AREA_LOBBY:
        break;
    }
}

s32 TODoorBase::init_door_switch_binding() {
    switch_id = set_params[0];
    if (switch_id > 0x100) {
        lock_mode = LOCK_LOCKED;
    } else if (switch_id < 0) {
        lock_mode = LOCK_UNLOCKED;
    } else {
        lock_mode = LOCK_SWITCH;
    }
    return switch_id;
}

void TODoorBase::play_door_sound() {
    if (!(door_flags & DOOR_FLAG_UNLOCKED)) {
        switch (get_current_floor_area()) {
        case AREA_PIONEER2_EP1:
        case AREA_PIONEER2_EP2:
            play_sound_effect(0x42A04, &position, 0, 0);
            break;
        case AREA_FOREST1:
        case AREA_FOREST2:
            play_sound_effect(0x4BC07, &position, 0, 0);
            break;
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_sound_effect(0x42807, &position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_sound_effect(0x4004BC00, &position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_sound_effect(0x4004BC07, &position, 0, 0);
            break;
        case AREA_BATTLE1:
        case AREA_BATTLE2:
            play_sound_effect(0x4004BC00, &position, 0, 0);
            break;
        }
    }
}
