#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecDeband.h"
#include "pso/technique/TTecLuker.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/technique/TTecAnti.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

#include "pso/system/task/TObject.h"
extern "C" void *__ct__16TargetCursorListFv(void *list);

#pragma readonly_strings on


const char *tec_deband_class_name_ptr = "TTecDeband";


struct Target_8022F73C {
    u16 id;
    u8 pad[6];
};

struct Deband_8022F73C {
    u8 pad0[0x1C];
    uaddr source;
    u8 pad1[0xA4 - 0x20];
    s16 level;
    u8 pad2[0xA8 - 0xA6];
    u16 source_id;
    u8 pad3[0xDC - 0xAA];
    u32 proxy;
    s32 count;
    Target_8022F73C targets[11];
    s32 captured;
};

struct VBase_18_b27ba1 { char pad[0x18]; };

struct HitInfo_8022F588 { s32 type; f32 power; };

struct VObj_18_b27ba1 : VBase_18_b27ba1 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, HitInfo_8022F588 *, void *, s32, s32);
};

struct Obj_8022F588 { u8 pad[0x1C]; u8 *source; u8 pad20[0x74 - 0x20]; f32 power; };

extern "C" {
saddr get_entity_id(int);
void *find_entity_by_id(u16 id);
s32 deliver_technique_to_party_targets(void *);
void run_task__10TTecDebandFv(Deband_8022F73C *self);
s32 is_split_screen();
void copy_technique_target_list(void *, void *, s32);
int spawn_support_tec_range_effect(void*);

int TTecDeband::init_params() { return spawn_support_tec_range_effect(this); }

void TTecDeband::update_effect_params() {
    u8 *arg0 = (u8 *)this;
    TechniqueParams *res;
    res = calc_technique_parameters(0xA, this->m_a4, 0xFFFF);
    ((TechniqueParams *)(arg0 + 0x74))->copy(res);
    this->m_74 = (f32) (this->m_98 * this->m_a4);
}

void TTecDeband::vfunc_7(void *arg1_arg) {
    Obj_8022F588 *arg0 = (Obj_8022F588 *)this;
    VObj_18_b27ba1 *player = (VObj_18_b27ba1 *)arg1_arg;
    HitInfo_8022F588 h;
    h.type = 0xA;
    h.power = arg0->power;
    if (((TObjPlayer *)player)->is_script_controlled() == 0) {
        HitInfo_8022F588 c = h;
        player->m21(arg0->source, &c, 0, 0xA, -1);
        if (is_split_screen() == 0) {
            TWindowCtrl::show_party_effect((void*)(get_entity_id((saddr)arg0->source)), (void*)(get_entity_id((saddr)player)), (void*)0xA);
        }
    }
}

void TTecDeband::create(saddr owner, saddr pos, saddr arg2, s32 level) {
    new TTecDeband((void *)owner, (void *)pos, (void *)arg2, level);
}
void TTecDeband::create(void *owner, void *pos, s32 level) {
    new TTecDeband(owner, pos, level);
}
void TTecDeband::render() {  }

}
TTecDeband::~TTecDeband() {

}

void run_task__10TTecDebandFv(Deband_8022F73C *self) {
    uaddr target;
    s32 i;
    if (self->proxy == 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    self->source = (uaddr)find_entity_by_id(self->source_id);
    if (self->source == 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (self->captured != 0) {
        if (self->level <= 1) {
            ((TTecDeband *)self)->vfunc_7((void *)self->source);
        } else {
            ((TTecDeband *)self)->vfunc_7((void *)self->source);
            if (self->count != 0) {
                for (i = 0; i < self->count; i++) {
                    target = (uaddr)find_entity_by_id(self->targets[i].id);
                    if ((TTecLuker::is_parents_unqueued(target) != 0) && (TObjPlayer::is_valid_and_active(target) != 0)) {
                        ((TTecDeband *)self)->vfunc_7((void *)target);
                    }
                }
            }
        }
    } else if (self->level <= 1) {
        ((TTecDeband *)self)->vfunc_7((void *)self->source);
    } else {
        deliver_technique_to_party_targets(self);
    }
    ((TObject *)self)->queue_destruction();
}

#pragma opt_common_subs off
TTecDeband::TTecDeband(void *owner, void *pos, void *arg3, saddr level) : TTecPlayerInfluence(owner, pos, level) {
#define arg0 ((u8 *)this)
    u32 temp_r3_2;
    u8 *temp_r3;
    __ct__16TargetCursorListFv((arg0 + 0xE0));
    s32 g = ((saddr)tec_deband_class_name_ptr);
    *(s32 *)((s8 *)arg0 + 0) = g;
    *(s32 *)&((TTecDeband *)arg0)->m_13c = 1;
    copy_technique_target_list(arg0 + 0xE0, (void *) arg3, g);
    ((TTecDeband *)arg0)->update_effect_params();
    temp_r3 = *(u8 **)((s8 *)arg0 + 0xDC);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = (f32) (5.0f + ((TTecDeband *)arg0)->m_7c);
    }
    temp_r3_2 = ((TTecDeband *)arg0)->source;
    if (temp_r3_2 != 0U) {
        *(s16 *)&((TTecDeband *)arg0)->m_a8 = get_entity_id(temp_r3_2);
    }
    if (*(s32 *)&((TTecDeband *)arg0)->m_ac != 0) {
        ((TTecDeband *)arg0)->init_params();
        ((TTecDeband *)arg0)->play_state_sound();
    }
#undef arg0
}
#pragma opt_common_subs reset

TTecDeband::TTecDeband(void *owner, void *pos, saddr level) : TTecPlayerInfluence(owner, pos, level) {
#define arg0 this
    u32 temp_r3_2;
    u8 *temp_r3;
    __ct__16TargetCursorListFv(((u8 *)arg0 + 0xE0));
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((saddr)tec_deband_class_name_ptr);
    arg0->m_13c = 0;
    arg0->update_effect_params();
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xDC));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = (f32) (5.0f + arg0->m_7c);
    }
    temp_r3_2 = arg0->source;
    if (temp_r3_2 != 0U) {
        arg0->m_a8 = get_entity_id(temp_r3_2);
    }
    arg0->init_params();
    arg0->play_state_sound();
#undef arg0
}

