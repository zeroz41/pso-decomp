#include "pso/render/NinjaUtil.h"
#include "pso/system/SoundEffect.h"
#include "pso/network/FloorEventCommand.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/object/ambient/TObjEnvSound.h"
#include "pso/object/ambient/TObjEnvSoundEx.h"
#include "pso/object/ambient/TObjEnvSoundGlobal.h"


#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/SplitScreenQuery.h"

// Per-area {sound cue, mode} rows, indexed by the object's set parameter.
const EnvSoundRow env_sound_table_pioneer2[] = {
    {0x4004B200, 1}, {0x4004C101, 1}, {0x4004CB02, 1},
};
const EnvSoundRow env_sound_table_forest[] = {
    {0x4A801, 2}, {0x4B202, 2}, {0x4BC00, 2}, {0x43704, 2},
    {0x4BC05, 2}, {0x4AD06, 2},
};
const EnvSoundRow env_sound_table_cave[] = {
    {0x46400, 2}, {0x42A01, 2}, {0x42F02, 2}, {0x43C03, 2},
    {0x43C04, 2}, {0x42D05, 2},
};
const EnvSoundRow env_sound_table_mine[] = {
    {0x4004B715, 2}, {0x4004BC16, 2},
};
const EnvSoundRow env_sound_table_ruins[] = {
    {0x4004B200, 2}, {0x4004CB01, 2}, {0x4004BC02, 2}, {0x4004BC03, 2},
    {0x4004C604, 2}, {0x4004AA05, 2}, {0x4004C606, 2},
};
const EnvSoundRow env_sound_table_spaceship[] = {
    {0x4004B40C, 2}, {0x4004B40D, 2}, {0x4004C10E, 2}, {0x4004C10F, 2},
};
const EnvSoundRow env_sound_table_palace[] = {
    {0x4CB0C, 2}, {0x4BC0D, 2}, {0x4BC0E, 2},
};
const EnvSoundRow env_sound_table_vr_temple[] = {
    {0x4CB0C, 2}, {0x4BC0D, 2}, {0x4BC0E, 2},
};
const EnvSoundRow env_sound_table_vr_spaceship[] = {
    {0x4004B40C, 2}, {0x4004B40D, 2}, {0x4C10E, 2}, {0x4C10F, 2},
};
const EnvSoundRow env_sound_table_episode2_field[] = {
    {0x4CB05, 2}, {0x4D506, 2}, {0x4BC07, 2}, {0x4C60A, 2},
    {0x4CB0B, 2}, {0x4CB0C, 2}, {0x4CB0D, 2}, {0x4BC0E, 2},
};
const EnvSoundRow env_sound_table_seabed[] = {
    {0x4004BC00, 2}, {0x4004BC01, 2}, {0x4004C603, 2}, {0x4004D504, 2},
    {0x4004B205, 2}, {0x4004B206, 2}, {0x4004AD07, 2}, {0x4004B208, 2},
    {0x4004AD09, 2}, {0x4004B20A, 2}, {0x4004B20B, 2},
};

const char *env_sound_class_name = "TObjEnvSound";
const char *env_sound_ex_class_name = "TObjEnvSoundEx";
const char *env_sound_global_class_name = "TObjEnvSoundGlobal";

const EnvSoundRow *environment_sound_tables_by_area[36] = {
    env_sound_table_pioneer2, env_sound_table_forest, env_sound_table_forest, env_sound_table_cave,
    env_sound_table_cave, env_sound_table_cave, env_sound_table_mine, env_sound_table_mine,
    env_sound_table_ruins, env_sound_table_ruins, env_sound_table_ruins, NULL,
    NULL, NULL, NULL, NULL,
    env_sound_table_spaceship, env_sound_table_palace, env_sound_table_pioneer2, env_sound_table_vr_temple,
    env_sound_table_vr_temple, env_sound_table_vr_spaceship, env_sound_table_vr_spaceship, env_sound_table_episode2_field,
    env_sound_table_episode2_field, env_sound_table_episode2_field, env_sound_table_episode2_field, env_sound_table_episode2_field,
    env_sound_table_seabed, env_sound_table_seabed, NULL, env_sound_table_seabed,
    NULL, NULL, env_sound_table_episode2_field, env_sound_table_episode2_field,
};


#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/NinjaUtil.h"

#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/map/FloorWaveEvents.h"





void handle_6x67_trigger_set_event(game_command_header *command) {
    G_FloorEvent_6x67 *pkt = reinterpret_cast<G_FloorEvent_6x67 *>(command);
    pkt->bswap();
    if (pkt->floor != get_current_floor()) {
        set_floor_event_flags(pkt->floor, pkt->event_id, 4);
    } else {
        activate_first_floor_event(pkt->floor, pkt->event_id);
    }
}

TObjEnvSound::TObjEnvSound(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    const EnvSoundRow *table;
    m_name = env_sound_class_name;
    apply_object_set_data(set_data);
    table = environment_sound_tables_by_area[get_current_floor_area()];
    if (table != NULL) {
        TObjEnvSoundGlobal::copy_env_sound_row(&sound, const_cast<EnvSoundRow *>(&table[set_params[0]]));
    } else {
        queue_destruction();
        return;
    }
    radius = scale.z;
    if (radius <= 0.0f) {
        radius = 2e+02f;
    }
    attenuation = set_params[1];
    if (attenuation < -127) {
        attenuation = -127;
    }
    if (attenuation > 127) {
        attenuation = 127;
    }
    disallow_rendering();
}

TObjEnvSound::~TObjEnvSound() {

}

void TObjEnvSound::run_task() {
    f32 range;
    range = this->radius;
    if ((is_within_camera_distance_sq((f32) (range * range)) != 0) && (is_sound_enabled(this->sound.cue) != 0)) {
        switch (this->sound.mode) {
        case 0:
            break;
        case 1:
            play_persistent_sound(this->sound.cue, this, &position, 0, 0);
            return;
        case 2:
            play_persistent_sound(this->sound.cue, this, &position, (s32)this->attenuation, 2);
            break;
        }
    }
}

void TObjEnvSound::render() {  }

void *TObjEnvSound::create(ObjectSetData *set_data) {
    if (is_not_split_screen() == 1) {
        return NULL;
    }
    return new TObjEnvSound(tl_05, set_data);
}

s32 TObjEnvSound::is_within_camera_distance_sq(f32 distance_sq) {
    return xyz_distance_squared(&camera_ctrl_instance->pos, &position) < distance_sq;
}

s32 TObjEnvSound::is_sound_enabled(s32 cue) {
    if (is_not_split_screen() == 1 && get_current_floor_area() == AREA_FOREST2) {
        switch (cue) {
        case 0x43704:
        case 0x4BC05:
            return 0;
        }
    }
    return 1;
}

TObjEnvSoundEx::TObjEnvSoundEx(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = env_sound_ex_class_name;
    apply_object_set_data(set_data);
    init_sound_params();
    volume = -127.0f;
    disallow_rendering();
}

TObjEnvSoundEx::~TObjEnvSoundEx() {

}

void TObjEnvSoundEx::run_task() {
    if (xz_distance_squared(&camera_ctrl_instance->pos, &position) < range * range) {
        volume += volume_step;
        if (volume > (f32)max_volume) {
            volume = (f32)max_volume;
        }
        switch (sound.mode) {
        case 0:
            break;
        case 1:
            play_persistent_sound(sound.cue, this, &position, 0, 0);
            break;
        case 2:
            play_persistent_sound(sound.cue, this, NULL, (s32)volume, 2);
            break;
        }
    } else {
        volume -= volume_step;
        if (volume < -127.0f) {
            volume = -127.0f;
        }
        if (volume > -127.0f) {
            switch (sound.mode) {
            case 0:
                break;
            case 1:
                play_persistent_sound(sound.cue, this, &position, 0, 0);
                break;
            case 2:
                play_persistent_sound(sound.cue, this, NULL, (s32)volume, 2);
                break;
            }
        }
    }
}

void TObjEnvSoundEx::render() {  }

s32 TObjEnvSoundEx::init_sound_params() {
    s32 ok;
    const EnvSoundRow *table;
    ok = 1;
    table = environment_sound_tables_by_area[get_current_floor_area()];
    if (table != NULL) {
        TObjEnvSoundGlobal::copy_env_sound_row(&sound, const_cast<EnvSoundRow *>(&table[set_params[0]]));
    } else {
        ok = 0;
        sound.cue = -1;
        sound.mode = -1;
    }
    volume_step = fabs_float(scale.y);
    range = scale.z;
    if (range <= 0.0f) {
        range = 2e+02f;
    }
    max_volume = set_params[1];
    if (max_volume < -0x7F) {
        max_volume = -0x7F;
    }
    if (max_volume > 0x7F) {
        max_volume = 0x7F;
    }
    return ok;
}

void *TObjEnvSoundEx::create(ObjectSetData *set_data) {
    if (is_not_split_screen() == 1) {
        return NULL;
    }
    return new TObjEnvSoundEx(tl_05, set_data);
}

TObjEnvSoundGlobal::TObjEnvSoundGlobal(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = env_sound_global_class_name;
    apply_object_set_data(set_data);
    setup_sound();
}

TObjEnvSoundGlobal::~TObjEnvSoundGlobal() {

}

void TObjEnvSoundGlobal::run_task() {
    switch (sound.mode) {
    case 0:
        break;
    case 1:
        play_persistent_sound(sound.cue, this, &position, 0, 0);
        break;
    case 2:
        play_persistent_sound(sound.cue, this, NULL, (s32)attenuation, 2);
        break;
    }
}

void TObjEnvSoundGlobal::render() {  }

void TObjEnvSoundGlobal::copy_env_sound_row(EnvSoundRow *dst, EnvSoundRow *src) {
    dst->cue = src->cue;
    dst->mode = src->mode;
}

#pragma push
#pragma opt_common_subs off
s32 TObjEnvSoundGlobal::setup_sound() {
    s32 result;
    const EnvSoundRow *table;
    result = 1;
    table = environment_sound_tables_by_area[get_current_floor_area()];
    if (table != NULL) {
        copy_env_sound_row(&this->sound, const_cast<EnvSoundRow *>(&table[this->set_params[0]]));
    } else {
        result = 0;
        this->sound.cue = -1;
        this->sound.mode = -1;
    }
    attenuation = (f32) set_params[1];
    if (attenuation < (-127.0f)) {
        attenuation = -127.0f;
    }
    if (attenuation > (127.0f)) {
        attenuation = 127.0f;
    }
    return result;
}
#pragma pop
