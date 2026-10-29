// Built -inline off,deferred: the functions are written from the last back.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TOSensor.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/network/client_id.h"
#include "pso/object/TObjMapWarp_80141C68.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/protocol/protocol_types.h"
#include "pso/system/vector.h"

const char *TOSensor__class_name = "TOSensor";

void TOSensor::render() {}

void TOSensor::update_switch_off() {}

void TOSensor::update_switch_on() {}

TOSensor::TOSensor(TObject *parent) : TOKey(parent) {
    VecCopy(&home_position, &position);
    m_name = TOSensor__class_name;
}

TOSensor::~TOSensor() {}

s32 TOSensor::is_confirm_pressed() {
    TObjPlayer *player;

    if (is_on != 1) {
        player = get_player_by_client_id(local_client_id);
        switch (mode) {
        case 1:
            if (player != NULL && player->obj_testFlags30(0x400000) != 0) {
                if (horizontal_distance_squared(&player->position, &position) < activate_range * activate_range) {
                    is_on = 1;
                }
            }
            break;
        case 2:
            if (local_client_id == TWindowCtrl::get_window_id() && player != NULL) {
                if (horizontal_distance_squared(&player->position, &position) < activate_range * activate_range) {
                    is_on = 1;
                }
            }
            break;
        }
    }
    return is_on;
}

void TOSensor::update_armed_switch() {
    update_lock_state();
    if (is_on != 1) {
        update_switch_off();
        play_off_loop_sound();
        if (is_confirm_pressed() == 1) {
            G_SwitchStateChanged_6x05 cmd;
            trigger_activate_sound();
            cmd.init();
            cmd.header.client_id = entity_id;
            cmd.unused1 = local_client_id;
            cmd.switch_id = switch_id;
            cmd.floor = get_current_floor();
            cmd.flags = 1;
            cmd.send();
        }
    } else {
        update_switch_on();
        play_on_loop_sound();
    }
    if (100.0f + home_position.y < position.y) {
        queue_destruction();
    }
}

void TOSensor::play_on_loop_sound() {
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_persistent_sound(0x4411D, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_MINE1:
    case AREA_MINE2:
        play_persistent_sound(0x4004C114, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_persistent_sound(0x4641A, (s32)this, (u32)&position, 0, 0);
    case AREA_PIONEER2_EP1:
        return;
    case AREA_FOREST1:
        return;
    case AREA_FOREST2:
        return;
    case AREA_DRAGON:
        return;
    case AREA_DE_ROL_LE:
        return;
    case AREA_VOL_OPT:
        return;
    case AREA_DARK_FALZ:
        return;
    case AREA_LOBBY:
        return;
    }
}

void TOSensor::play_off_loop_sound() {
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_persistent_sound(0x43C1C, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_MINE1:
    case AREA_MINE2:
        play_persistent_sound(0x4004BC13, (s32)this, (u32)&position, 0, 0);
        return;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_persistent_sound(0x46419, (s32)this, (u32)&position, 0, 0);
    case AREA_PIONEER2_EP1:
        return;
    case AREA_FOREST1:
        return;
    case AREA_FOREST2:
        return;
    case AREA_DRAGON:
        return;
    case AREA_DE_ROL_LE:
        return;
    case AREA_VOL_OPT:
        return;
    case AREA_DARK_FALZ:
        return;
    case AREA_LOBBY:
        return;
    }
}

void TOSensor::vfunc_25() {}
