#include "pso/render/NinjaUtil.h"
#include "pso/system/SoundEffect.h"
#include "pso/network/FloorEventCommand.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
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

struct Row_80190AA0 { u32 cue; s32 mode; };



// Per-area {sound cue, mode} rows, indexed by the object's set parameter.
const Row_80190AA0 env_sound_table_pioneer2[] = {
    {0x4004B200, 1}, {0x4004C101, 1}, {0x4004CB02, 1},
};
const Row_80190AA0 env_sound_table_forest[] = {
    {0x4A801, 2}, {0x4B202, 2}, {0x4BC00, 2}, {0x43704, 2},
    {0x4BC05, 2}, {0x4AD06, 2},
};
const Row_80190AA0 env_sound_table_cave[] = {
    {0x46400, 2}, {0x42A01, 2}, {0x42F02, 2}, {0x43C03, 2},
    {0x43C04, 2}, {0x42D05, 2},
};
const Row_80190AA0 env_sound_table_mine[] = {
    {0x4004B715, 2}, {0x4004BC16, 2},
};
const Row_80190AA0 env_sound_table_ruins[] = {
    {0x4004B200, 2}, {0x4004CB01, 2}, {0x4004BC02, 2}, {0x4004BC03, 2},
    {0x4004C604, 2}, {0x4004AA05, 2}, {0x4004C606, 2},
};
const Row_80190AA0 env_sound_table_spaceship[] = {
    {0x4004B40C, 2}, {0x4004B40D, 2}, {0x4004C10E, 2}, {0x4004C10F, 2},
};
const Row_80190AA0 env_sound_table_palace[] = {
    {0x4CB0C, 2}, {0x4BC0D, 2}, {0x4BC0E, 2},
};
const Row_80190AA0 env_sound_table_vr_temple[] = {
    {0x4CB0C, 2}, {0x4BC0D, 2}, {0x4BC0E, 2},
};
const Row_80190AA0 env_sound_table_vr_spaceship[] = {
    {0x4004B40C, 2}, {0x4004B40D, 2}, {0x4C10E, 2}, {0x4C10F, 2},
};
const Row_80190AA0 env_sound_table_episode2_field[] = {
    {0x4CB05, 2}, {0x4D506, 2}, {0x4BC07, 2}, {0x4C60A, 2},
    {0x4CB0B, 2}, {0x4CB0C, 2}, {0x4CB0D, 2}, {0x4BC0E, 2},
};
const Row_80190AA0 env_sound_table_seabed[] = {
    {0x4004BC00, 2}, {0x4004BC01, 2}, {0x4004C603, 2}, {0x4004D504, 2},
    {0x4004B205, 2}, {0x4004B206, 2}, {0x4004AD07, 2}, {0x4004B208, 2},
    {0x4004AD09, 2}, {0x4004B20A, 2}, {0x4004B20B, 2},
};

const char *env_sound_class_name = "TObjEnvSound";
const char *env_sound_ex_class_name = "TObjEnvSoundEx";
const char *env_sound_global_class_name = "TObjEnvSoundGlobal";

extern "C" {
const Row_80190AA0 *environment_sound_tables_by_area[36] = {
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

#define F(o) (*(f32 *)(self + (o)))
#define S(o) (*(s32 *)(self + (o)))

#undef F
#undef S


}


#include "pso/unk/text_80190884.h"

#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/NinjaUtil.h"

#include "pso/unk/text_80190940.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby_80207DA8.h"




void copy_pair__18TObjEnvSoundGlobalFPvPv(void *p, void *q);

void handle_6x67_trigger_set_event(game_command_header *command) {
    G_FloorEvent_6x67 *pkt = reinterpret_cast<G_FloorEvent_6x67 *>(command);
    pkt->bswap();
    if (pkt->floor != get_current_floor()) {
        set_floor_event_flags(pkt->floor, pkt->event_id, 4);
    } else {
        activate_first_floor_event(pkt->floor, pkt->event_id);
    }
}

TObjEnvSound::TObjEnvSound(TObject *parent, void *set_data) : TObjBase(parent) {
    const Row_80190AA0 *table;
    m_name = env_sound_class_name;
    apply_object_set_data(set_data);
    table = environment_sound_tables_by_area[get_current_floor_area()];
    if (table != NULL) {
        copy_pair__18TObjEnvSoundGlobalFPvPv(&cue, (void *)&table[set_params[0]]);
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
    range = radius;
    if ((is_within_camera_distance_sq((saddr)this, (f32) (range * range)) != 0) && (is_sound_enabled(this->cue) != 0)) {
        switch (this->mode) {
        case 0:
            break;
        case 1:
            play_persistent_sound((s32)this->cue, this, &position, 0, 0);
            return;
        case 2:
            play_persistent_sound((s32)this->cue, this, &position, (s32)this->attenuation, 2);
            break;
        }
    }
}

void TObjEnvSound::render() {  }

void *TObjEnvSound::create(void *rader_map_core) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return NULL;
    }
    return new TObjEnvSound(tl_05, rader_map_core);
}

s32 is_within_camera_distance_sq(saddr object, f32 distance_sq) {
    return xyz_distance_squared(&camera_ctrl_instance->pos, &reinterpret_cast<const TObjBase *>(object)->position) < distance_sq;
}

s32 TObjEnvSound::is_sound_enabled(s32 cue) {
    if (TRaderMapCore::is_not_split_screen() == 1 && get_current_floor_area() == AREA_FOREST2) {
        switch (cue) {
        case 0x43704:
        case 0x4BC05:
            return 0;
        }
    }
    return 1;
}

TObjEnvSoundEx::TObjEnvSoundEx(TObject *parent, saddr set_data) : TObjBase(parent) {
    m_name = env_sound_ex_class_name;
    apply_object_set_data((void *)set_data);
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
        switch (mode) {
        case 0:
            break;
        case 1:
            play_persistent_sound(sound_id, this, &position, 0, 0);
            break;
        case 2:
            play_persistent_sound(sound_id, this, NULL, (s32)volume, 2);
            break;
        }
    } else {
        volume -= volume_step;
        if (volume < -127.0f) {
            volume = -127.0f;
        }
        if (volume > -127.0f) {
            switch (mode) {
            case 0:
                break;
            case 1:
                play_persistent_sound(sound_id, this, &position, 0, 0);
                break;
            case 2:
                play_persistent_sound(sound_id, this, NULL, (s32)volume, 2);
                break;
            }
        }
    }
}

void TObjEnvSoundEx::render() {  }

s32 TObjEnvSoundEx::init_sound_params() {
    s32 ok;
    uaddr table;
    ok = 1;
    table = (uaddr)environment_sound_tables_by_area[get_current_floor_area()];
    if (table != 0U) {
        ((s32 (*)(void *, int))copy_pair__18TObjEnvSoundGlobalFPvPv)(&sound_id, (int)(table + (set_params[0] * 8)));
    } else {
        ok = 0;
        sound_id = -1;
        mode = -1;
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

void *TObjEnvSoundEx::create(void *rader_map_core) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return NULL;
    }
    return new TObjEnvSoundEx(tl_05, (saddr)rader_map_core);
}

TObjEnvSoundGlobal::TObjEnvSoundGlobal(TObject *parent, saddr set_data) : TObjBase(parent) {
    m_name = env_sound_global_class_name;
    apply_object_set_data((void *)set_data);
    setup_sound();
}

TObjEnvSoundGlobal::~TObjEnvSoundGlobal() {

}

void TObjEnvSoundGlobal::run_task() {
    switch (mode) {
    case 0:
        break;
    case 1:
        play_persistent_sound((s32)cue, this, &position, 0, 0);
        break;
    case 2:
        play_persistent_sound((s32)cue, this, NULL, (s32)attenuation, 2);
        break;
    }
}

void TObjEnvSoundGlobal::render() {  }

void copy_pair__18TObjEnvSoundGlobalFPvPv(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

#pragma push
#pragma opt_common_subs off
s32 TObjEnvSoundGlobal::setup_sound() {
    s32 result;
    const Row_80190AA0 *table;
    result = 1;
    table = environment_sound_tables_by_area[get_current_floor_area()];
    if (table != NULL) {
        copy_pair__18TObjEnvSoundGlobalFPvPv(&this->cue, (void *)&table[this->set_params[0]]);
    } else {
        result = 0;
        this->cue = -1;
        this->mode = -1;
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
