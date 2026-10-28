#include "types.h"
#include "pso/object/TObjEnvSoundEx.h"
#include "pso/object/TObjEnvSoundGlobal.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjMotion.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_80190484___vt__18TObjEnvSoundGlobal {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_801902D8_lbl_804B7A70 { s32 value; u8 remaining[0x8C]; };

struct Obj_801903B4 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x90 - 0x44]; f32 param; s32 sound; s32 mode; };

struct Env_80190624 {
    u8 pad0[0x38];
    u8 pos[0x90 - 0x38];
    s32 f90;
    f32 vol;
    f32 step;
    s32 f9C;
    s32 mode;
    f32 range;
};

extern "C" {
s32 __ct__13TUnk_804B9870FP7TObject(void *, void *);
extern s32 __vt__18TObjEnvSoundGlobal[];
extern s32 TObjEnvSoundGlobal__class_name;
u8 *TObjEnvSoundGlobal__ct(u8 *arg0, s32 arg1, s32 arg2);
u8 *TObjEnvSoundEx__ct(u8 *arg0, s32 arg1, s32 arg2);
void copy_pair__18TObjEnvSoundGlobalFPvPv(void* p, void* q);
extern RecoveredGlobal_801902D8_lbl_804B7A70 environment_sound_tables_by_area;

s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
f32 xz_distance_squared(void *, void *);
extern u8 *camera_ctrl_instance;
void run_task__14TObjEnvSoundExFv(Env_80190624 *o);
void * TObjEnvSoundEx__create(void *arg0);
void *__dt__18TObjEnvSoundGlobalFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
int is_not_split_screen__13TRaderMapCoreFv(void *);

#pragma push
#pragma opt_common_subs off
s32 TObjEnvSoundGlobal::setup_sound() {
    s32 var_r31;
    u32 temp_r4;
    var_r31 = 1;
    temp_r4 = *(s32 *)((s8 *)&environment_sound_tables_by_area.value + (get_current_area() * 4));
    if (temp_r4 != 0U) {
        copy_pair__18TObjEnvSoundGlobalFPvPv((u8 *)&this->m_94, (void*)((int) (temp_r4 + (this->set_params[0] * 8))));
    } else {
        var_r31 = 0;
        this->m_94 = -1;
        this->m_98 = -1;
    }
    *(f32 *)&this->unk_90 = (f32) *(s32 *)&this->set_params[1];
    if (*(f32 *)&this->unk_90 < (-127.0f)) {
        *(f32 *)&this->unk_90 = (f32) (-127.0f);
    }
    if (*(f32 *)&this->unk_90 > (127.0f)) {
        *(f32 *)&this->unk_90 = (f32) (127.0f);
    }
    return var_r31;
}
#pragma pop

void copy_pair__18TObjEnvSoundGlobalFPvPv(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
void TObjEnvSoundGlobal::render() {  }

void TObjEnvSoundGlobal::run_task() {
    Obj_801903B4 *self = (Obj_801903B4 *)this;
    switch (self->mode) {
    case 0:
        break;
    case 1:
        play_persistent_sound((s32)self->sound, (s32)self, (u32)self->pos, 0, 0);
        break;
    case 2:
        play_persistent_sound((s32)self->sound, (s32)self, (u32)(0), (s32)self->param, 2);
        break;
    }
}

void *__dt__18TObjEnvSoundGlobalFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjEnvSoundGlobal;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

typedef char RecoveredGlobal_80190484___vt__18TObjEnvSoundGlobal_size[sizeof(RecoveredGlobal_80190484___vt__18TObjEnvSoundGlobal) == 0x34 ? 1 : -1];
u8 *TObjEnvSoundGlobal__ct(u8 *env_sound_global, s32 parent, s32 arg2) {
    __ct__13TUnk_804B9870FP7TObject((void *)env_sound_global, (void *)parent);
    *(s32 **)((s8 *)env_sound_global + 0x18) = &(*(RecoveredGlobal_80190484___vt__18TObjEnvSoundGlobal *)&__vt__18TObjEnvSoundGlobal).value;
    *(s32 *)((s8 *)env_sound_global + 0) = (s32) TObjEnvSoundGlobal__class_name;
    ((TObjEnvSoundGlobal *)(env_sound_global))->apply_object_set_data((void *)arg2);
    ((TObjEnvSoundGlobal *)env_sound_global)->setup_sound();
    return env_sound_global;
}

void * TObjEnvSoundEx__create(void *rader_map_core) {
    void *o;
    if (is_not_split_screen__13TRaderMapCoreFv(rader_map_core) == 1) {
        return NULL;
    }
    o = __nw__7TObjectFUl(0xA8);
    if (o != NULL) {
        o = TObjEnvSoundEx__ct((u8 *)o, (s32)tl_05, (s32)rader_map_core);
    }
    return o;
}

f32 fabs_float(f32);
void disallow_rendering__7TObjectFv(TObject *arg0);
extern s32 __vt__14TObjEnvSoundEx[];
extern s32 TObjEnvSoundEx__class_name;
void *__dt__14TObjEnvSoundExFv(void *arg0, s16 arg1);
struct RecoveredGlobal_8019080C___vt__14TObjEnvSoundEx {
    s32 value;
    u8 remaining[0x30];
};

s32 TObjEnvSoundEx::init_sound_params() {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;
    u32 temp_r4;
    var_r31 = 1;
    temp_r4 = *(s32 *)((s8 *)&environment_sound_tables_by_area.value + (get_current_area() * 4));
    if (temp_r4 != 0U) {
        ((s32 (*)(void *, int))copy_pair__18TObjEnvSoundGlobalFPvPv)(arg0 + 0x9C, (int) (temp_r4 + (this->set_params[0] * 8)));
    } else {
        var_r31 = 0;
        this->m_9c = -1;
        this->m_a0 = -1;
    }
    this->m_98 = fabs_float(this->scale.y);
    *(f32 *)&this->unk_A4 = (f32) this->scale.z;
    if (*(f32 *)&this->unk_A4 <= 0.0f) {
        *(f32 *)&this->unk_A4 = (f32) 2e+02f;
    }
    this->m_90 = (s32) this->set_params[1];
    if ((s32) this->m_90 < -0x7F) {
        this->m_90 = -0x7F;
    }
    if ((s32) this->m_90 > 0x7F) {
        this->m_90 = 0x7F;
    }
    return var_r31;
}

void TObjEnvSoundEx::render() {  }

#define F(o) (*(f32 *)(self + (o)))
#define S(o) (*(s32 *)(self + (o)))

#undef F
#undef S

void run_task__14TObjEnvSoundExFv(Env_80190624 *o) {
    if (xz_distance_squared(camera_ctrl_instance + 0x178, o->pos) < o->range * o->range) {
        o->vol += o->step;
        if (o->vol > (f32)o->f90) {
            o->vol = (f32)o->f90;
        }
        switch (o->mode) {
        case 0:
            break;
        case 1:
            play_persistent_sound((s32)o->f9C, (s32)o, (u32)((f32 *)o->pos), 0, 0);
            break;
        case 2:
            play_persistent_sound((s32)o->f9C, (s32)o, (u32)((f32 *)(0)), (s32)((s32)o->vol), 2);
            break;
        }
    } else {
        o->vol -= o->step;
        if (o->vol < -127.0f) {
            o->vol = -127.0f;
        }
        if (o->vol > (-127.0f)) {
            switch (o->mode) {
            case 0:
                break;
            case 1:
                play_persistent_sound((s32)o->f9C, (s32)o, (u32)((f32 *)o->pos), 0, 0);
                break;
            case 2:
                play_persistent_sound((s32)o->f9C, (s32)o, (u32)((f32 *)(0)), (s32)((s32)o->vol), 2);
                break;
            }
        }
    }
}

void *__dt__14TObjEnvSoundExFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjEnvSoundEx;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8019080C___vt__14TObjEnvSoundEx_size[sizeof(RecoveredGlobal_8019080C___vt__14TObjEnvSoundEx) == 0x34 ? 1 : -1];
u8 *TObjEnvSoundEx__ct(u8 *env_sound_ex, s32 arg1, s32 arg2) {
    ((s32 (*)(void *))__ct__13TUnk_804B9870FP7TObject)(env_sound_ex);
    *(s32 **)((s8 *)env_sound_ex + 0x18) = &(*(RecoveredGlobal_8019080C___vt__14TObjEnvSoundEx *)&__vt__14TObjEnvSoundEx).value;
    *(s32 *)((s8 *)env_sound_ex + 0) = (s32) TObjEnvSoundEx__class_name;
    ((TObjEnvSoundEx *)(env_sound_ex))->apply_object_set_data((void *)arg2);
    ((TObjEnvSoundEx *)env_sound_ex)->init_sound_params();
    *(f32 *)((s8 *)env_sound_ex + 0x94) = (f32) (-127.0f);
    disallow_rendering__7TObjectFv((TObject *)(env_sound_ex));
    return env_sound_ex;
}

}

#include "types.h"
#include "pso/unk/text_80190884.h"
#include "pso/object/TObjEnvSound.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TRaderMapCore.h"

extern "C" {
f32 xyz_distance_squared(void *, void *, void *);

s32 TObjEnvSound::is_sound_enabled(void *self, s32 cue) {
    if (TRaderMapCore::is_not_split_screen() == 1 && get_current_area() == 2) {
        switch (cue) {
        case 0x43704:
        case 0x4BC05:
            return 0;
        }
    }
    return 1;
}

s32 fn_801908F8(s32 arg0, f32 farg0) {
    return xyz_distance_squared((void *)(camera_ctrl_instance + 0x178), (void *)(arg0 + 0x38), (void *)arg0) < farg0;
}

}

#include "types.h"
#include "pso/unk/text_80190940.h"

struct Row_80190AA0 { u32 cue; s32 mode; };

struct Obj_80190AA0 {
    s32 unk0;
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

extern "C" {

void *TObjEnvSound__ct(Obj_80190AA0 *, void *, void *);
int is_not_split_screen__13TRaderMapCoreFv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void * TObjEnvSound__create(void *rader_map_core) {
    void *o;
    if (is_not_split_screen__13TRaderMapCoreFv(rader_map_core) == 1) {
        return NULL;
    }
    o = __nw__7TObjectFUl(0xA0);
    if (o != NULL) {
        o = TObjEnvSound__ct((Obj_80190AA0 *)o, tl_05, rader_map_core);
    }
    return o;
}

}

#include "types.h"
#include "pso/object/TObjEnvSound.h"
#include "pso/misc/TOKeyMachine01.h"

struct Pkt_80190BA0 { u32 header; s32 target; s32 event; };

extern "C" {

s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void byteswap_event_packet__6TLobbyFi(s32 arg0);
s32 get_current_floor(void);
}
s32 set_floor_event_flags(s32 arg0, s32 arg1, s32 arg2);
s32 activate_first_floor_event(s32 idx, s32 id);
extern "C" {
void handle_6x67_trigger_set_event(Pkt_80190BA0 *pkt);
void queue_destruction__7TObjectFv(void *);
void disallow_rendering__7TObjectFv(TObject *);
void copy_pair__18TObjEnvSoundGlobalFPvPv(void *p, void *q);

extern s32 __vt__12TObjEnvSound[];
extern s32 TObjEnvSound__class_name;

void *__dt__12TObjEnvSoundFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

void TObjEnvSound::render() {  }

void TObjEnvSound::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    temp_f0 = *(f32 *)&this->unk_90;
    if ((fn_801908F8((s32)this, (f32) (temp_f0 * temp_f0)) != 0) && (TObjEnvSound::is_sound_enabled(arg0, this->m_98) != 0)) {
        switch (this->m_9c) {
        case 0:
            break;
        case 1:
            play_persistent_sound((s32)this->m_98, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
            return;
        case 2:
            play_persistent_sound((s32)this->m_98, (s32)arg0, (u32)(arg0 + 0x38), (s32)this->m_94, 2);
            break;
        }
    }
}

void *__dt__12TObjEnvSoundFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjEnvSound;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TObjEnvSound__ct(Obj_80190AA0 *self, void *parent, void *arg2) {
    Row_80190AA0 *table;
    __ct__13TUnk_804B9870FP7TObject(self, parent);
    self->vtbl = __vt__12TObjEnvSound;
    self->unk0 = TObjEnvSound__class_name;
    ((TObjEnvSound *)self)->apply_object_set_data(arg2);
    table = ((Row_80190AA0 **)&environment_sound_tables_by_area)[get_current_area()];
    if (table != NULL) {
        copy_pair__18TObjEnvSoundGlobalFPvPv(&self->sound, &table[self->index]);
    } else {
        queue_destruction__7TObjectFv(self);
        return self;
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
    disallow_rendering__7TObjectFv((TObject *)self);
    return self;
}

void handle_6x67_trigger_set_event(Pkt_80190BA0 *pkt) {
    byteswap_event_packet__6TLobbyFi((s32)pkt);
    if (pkt->target != get_current_floor()) {
        set_floor_event_flags(pkt->target, pkt->event, 4);
    } else {
        activate_first_floor_event(pkt->target, pkt->event);
    }
}
}
