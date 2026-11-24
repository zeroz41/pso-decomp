#include "pso/render/NinjaUtil.h"
#include "pso/system/SoundEffect.h"
#include "pso/network/FloorEventCommand.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjEnvSound.h"
#include "pso/object/ambient/TObjEnvSoundEx.h"
#include "pso/object/ambient/TObjEnvSoundGlobal.h"


#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"

struct Row_80190AA0 { u32 cue; s32 mode; };

struct Obj_801903B4 { u8 pad0[0x38]; Vec pos; u8 pad44[0x90 - 0x44]; f32 param; s32 sound; s32 mode; };


// Per-area {sound cue, mode} rows, indexed by the object's set parameter.
const Row_80190AA0 lbl_804456F0[] = {
    {0x4004B200, 1}, {0x4004C101, 1}, {0x4004CB02, 1},
};
const Row_80190AA0 lbl_80445708[] = {
    {0x4A801, 2}, {0x4B202, 2}, {0x4BC00, 2}, {0x43704, 2},
    {0x4BC05, 2}, {0x4AD06, 2},
};
const Row_80190AA0 lbl_80445738[] = {
    {0x46400, 2}, {0x42A01, 2}, {0x42F02, 2}, {0x43C03, 2},
    {0x43C04, 2}, {0x42D05, 2},
};
const Row_80190AA0 lbl_80445768[] = {
    {0x4004B715, 2}, {0x4004BC16, 2},
};
const Row_80190AA0 lbl_80445778[] = {
    {0x4004B200, 2}, {0x4004CB01, 2}, {0x4004BC02, 2}, {0x4004BC03, 2},
    {0x4004C604, 2}, {0x4004AA05, 2}, {0x4004C606, 2},
};
const Row_80190AA0 lbl_804457B0[] = {
    {0x4004B40C, 2}, {0x4004B40D, 2}, {0x4004C10E, 2}, {0x4004C10F, 2},
};
const Row_80190AA0 lbl_804457D0[] = {
    {0x4CB0C, 2}, {0x4BC0D, 2}, {0x4BC0E, 2},
};
const Row_80190AA0 lbl_804457E8[] = {
    {0x4CB0C, 2}, {0x4BC0D, 2}, {0x4BC0E, 2},
};
const Row_80190AA0 lbl_80445800[] = {
    {0x4004B40C, 2}, {0x4004B40D, 2}, {0x4C10E, 2}, {0x4C10F, 2},
};
const Row_80190AA0 lbl_80445820[] = {
    {0x4CB05, 2}, {0x4D506, 2}, {0x4BC07, 2}, {0x4C60A, 2},
    {0x4CB0B, 2}, {0x4CB0C, 2}, {0x4CB0D, 2}, {0x4BC0E, 2},
};
const Row_80190AA0 lbl_80445860[] = {
    {0x4004BC00, 2}, {0x4004BC01, 2}, {0x4004C603, 2}, {0x4004D504, 2},
    {0x4004B205, 2}, {0x4004B206, 2}, {0x4004AD07, 2}, {0x4004B208, 2},
    {0x4004AD09, 2}, {0x4004B20A, 2}, {0x4004B20B, 2},
};

const char *TObjEnvSound__class_name = "TObjEnvSound";
const char *TObjEnvSoundEx__class_name = "TObjEnvSoundEx";
const char *TObjEnvSoundGlobal__class_name = "TObjEnvSoundGlobal";

extern "C" {
const Row_80190AA0 *environment_sound_tables_by_area[36] = {
    lbl_804456F0, lbl_80445708, lbl_80445708, lbl_80445738,
    lbl_80445738, lbl_80445738, lbl_80445768, lbl_80445768,
    lbl_80445778, lbl_80445778, lbl_80445778, NULL,
    NULL, NULL, NULL, NULL,
    lbl_804457B0, lbl_804457D0, lbl_804456F0, lbl_804457E8,
    lbl_804457E8, lbl_80445800, lbl_80445800, lbl_80445820,
    lbl_80445820, lbl_80445820, lbl_80445820, lbl_80445820,
    lbl_80445860, lbl_80445860, NULL, lbl_80445860,
    NULL, NULL, lbl_80445820, lbl_80445820,
};



#define F(o) (*(f32 *)(self + (o)))
#define S(o) (*(s32 *)(self + (o)))

#undef F
#undef S


}


#include "pso/unk/text_80190884.h"

#include "pso/ui/hud/TRaderMapCore.h"

extern "C" {


}


#include "pso/unk/text_80190940.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby_80207DA8.h"


struct Obj_80190AA0 {
    const char *unk0;
    u8 pad4[0x18 - 0x4];
    void *vtbl;
    u8 pad1C[0x70 - 0x1C];
    f32 authoredRadius;
    u8 pad74[0x84 - 0x74];
    s32 index;
    s32 authoredAttenuation;
    s32 unk8C;
    f32 radius;
    s32 attenuation;
    Row_80190AA0 sound;
};


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

#define self ((Obj_80190AA0 *)this)
TObjEnvSound::TObjEnvSound(TObject *parent, void *arg2) : TObjBase(parent) {
    const Row_80190AA0 *table;
    self->unk0 = TObjEnvSound__class_name;
    ((TObjEnvSound *)self)->apply_object_set_data(arg2);
    table = environment_sound_tables_by_area[get_current_floor_area()];
    if (table != NULL) {
        copy_pair__18TObjEnvSoundGlobalFPvPv(&self->sound, (void *)&table[self->index]);
    } else {
        ((TObject *)self)->queue_destruction();
        return;
    }
    self->radius = self->authoredRadius;
    if (self->radius <= 0.0f) {
        self->radius = 2e+02f;
    }
    self->attenuation = self->authoredAttenuation;
    if (self->attenuation < -127) {
        self->attenuation = -127;
    }
    if (self->attenuation > 127) {
        self->attenuation = 127;
    }
    ((TObject *)self)->disallow_rendering();
}
#undef self

TObjEnvSound::~TObjEnvSound() {

}

void TObjEnvSound::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    temp_f0 = *(f32 *)&this->unk_90;
    if ((fn_801908F8((saddr)this, (f32) (temp_f0 * temp_f0)) != 0) && (TObjEnvSound::is_sound_enabled(arg0, this->m_98) != 0)) {
        switch (this->m_9c) {
        case 0:
            break;
        case 1:
            play_persistent_sound((s32)this->m_98, this, &position, 0, 0);
            return;
        case 2:
            play_persistent_sound((s32)this->m_98, this, &position, (s32)this->m_94, 2);
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

s32 fn_801908F8(saddr arg0, f32 farg0) {
    return xyz_distance_squared(&camera_ctrl_instance->pos, &reinterpret_cast<const TObjBase *>(arg0)->position) < farg0;
}

s32 TObjEnvSound::is_sound_enabled(void *self, s32 cue) {
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
    m_name = TObjEnvSoundEx__class_name;
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

#define env_sound_global this
TObjEnvSoundGlobal::TObjEnvSoundGlobal(TObject *parent, saddr arg2) : TObjBase(parent) {
    ((TObjEnvSoundGlobal *)env_sound_global)->m_name = TObjEnvSoundGlobal__class_name;
    ((TObjEnvSoundGlobal *)(env_sound_global))->apply_object_set_data((void *)arg2);
    ((TObjEnvSoundGlobal *)env_sound_global)->setup_sound();
}
#undef env_sound_global

TObjEnvSoundGlobal::~TObjEnvSoundGlobal() {

}

void TObjEnvSoundGlobal::run_task() {
    Obj_801903B4 *self = (Obj_801903B4 *)this;
    switch (self->mode) {
    case 0:
        break;
    case 1:
        play_persistent_sound((s32)self->sound, self, &self->pos, 0, 0);
        break;
    case 2:
        play_persistent_sound((s32)self->sound, self, NULL, (s32)self->param, 2);
        break;
    }
}

void TObjEnvSoundGlobal::render() {  }

void copy_pair__18TObjEnvSoundGlobalFPvPv(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

#pragma push
#pragma opt_common_subs off
s32 TObjEnvSoundGlobal::setup_sound() {
    s32 var_r31;
    const Row_80190AA0 *table;
    var_r31 = 1;
    table = environment_sound_tables_by_area[get_current_floor_area()];
    if (table != NULL) {
        copy_pair__18TObjEnvSoundGlobalFPvPv(&this->m_94, (void *)&table[this->set_params[0]]);
    } else {
        var_r31 = 0;
        this->m_94 = -1;
        this->m_98 = -1;
    }
    *(f32 *)&this->unk_90 = (f32) *(s32 *)&this->set_params[1];
    if (*(f32 *)&this->unk_90 < (-127.0f)) {
        *(f32 *)&this->unk_90 = -127.0f;
    }
    if (*(f32 *)&this->unk_90 > (127.0f)) {
        *(f32 *)&this->unk_90 = 127.0f;
    }
    return var_r31;
}
#pragma pop
