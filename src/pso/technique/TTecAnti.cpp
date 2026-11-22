#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecLuker.h"
#include "pso/unk/TUnk_804CC0E8.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"


#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
extern "C" void *__ct__16TargetCursorListFv(void *list);

#pragma readonly_strings on


const char *TTecAnti_name_ref = "TTecAnti";


struct Obj_8022ACB4 { u8 pad[0xA6]; s16 state; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Sub_8022B3E8 { s32 w[22]; };

struct S_8022B3E8 { s32 f0; Sub_8022B3E8 sub; };

struct AntiRow_8022AE10 { s32 a; s32 b; s32 c; s32 flags; };

struct Obj_8022AE10 {
    u8 pad0[0x18];
    void *vtbl;
    u8 pad1C[0x30 - 0x1C];
    Vec body;
    Vec ground;
};

struct Target_8022B150 { u16 id; u8 pad[6]; };

struct Anti_8022B150 {
    u8 pad0[0x1C];
    uaddr source;
    u8 pad1[0xA4 - 0x20];
    s16 level;
    u8 pad2[0xA8 - 0xA6];
    u16 source_id;
    u8 pad3[0xE0 - 0xAA];
    s32 count;
    Target_8022B150 targets[11];
    s32 captured;
};

struct Obj_8022AE10;
struct Hit_8022AEF8 {
    s32 type;
    f32 power;
};

struct PBase_8022AEF8 { char pad[0x18]; };

struct Player_8022AEF8 : PBase_8022AEF8 {
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
    virtual void m21(void *, Hit_8022AEF8, s32, s32, s16);
    u8 pad1C[0x38 - 0x1C];
    u8 pos[0x2FC - 0x38];
    u8 x2FC[4];
};

struct Anti_8022AEF8 {
    u8 pad0[0x1C];
    void *caster;
    u8 pad20[0x74 - 0x20];
    f32 power;
    u8 pad78[0xA4 - 0x78];
    s16 level;
    u8 padA6[0xAC - 0xA6];
    s32 xAC;
};

extern "C" {
saddr get_entity_id(int);
int TTecAnti__sub_8022AD74(void* p);
void TTecAnti__sub_8022AD94(void *);
S_8022B3E8 *copy_technique_target_list(S_8022B3E8 *d, S_8022B3E8 *s);
void set_owner_id__13TParticleCtrlFUs(void *, s32);
void __ct__7TObjectFP7TObject(void *, void *);
AntiRow_8022AE10 TTecAnti__self_effect_rows[4] = {
    {0xF, 1, 0x30, 0},
    {0xF, 1, 0x32, 0},
    {0, 0xF, 0x31, 1},
    {0xA, 1, 0x1EC, 1},
};
extern s32 __vt__13TUnk_804CC0E8[];
Obj_8022AE10 *construct_self_effect__8TTecAntiFPvPvPviPv(Obj_8022AE10 *self, const Vec *body, const Vec *ground, s32 actor, void *parent);
void deliver_technique_to_party_targets(void *);
void run_task__8TTecAntiFv(Anti_8022B150 *self);
s32 is_split_screen();
int spawn_support_tec_range_effect(void*);
}
u8 *construct_delayed_point_sound(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3, u8 *arg4);
void TTecAnti::render() {  }

S_8022B3E8 *copy_technique_target_list(S_8022B3E8 *d, S_8022B3E8 *s) {
    d->f0 = s->f0;
    d->sub = s->sub;
    return d;
}

void TechniqueParams::copy(TechniqueParams *src) {
    pad_00 = src->pad_00;
    pad_04 = src->pad_04;
    pad_08 = src->pad_08;
    pad_0C = src->pad_0C;
    tp_cost = src->tp_cost;
    pad_12 = src->pad_12;
    pad_14 = src->pad_14;
    pad_16 = src->pad_16;
    pad_18 = src->pad_18;
    pad_1C = src->pad_1C;
    pad_20 = src->pad_20;
    pad_22 = src->pad_22;
    tp_cost_percent = src->tp_cost_percent;
    pad_24 = src->pad_24;
    pad_26 = src->pad_26;
    pad_28 = src->pad_28;
    pad_2A = src->pad_2A;
}

#define arg0 ((u8 *)this)
TTecAnti::TTecAnti(void *owner, void *pos, void *targets, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    u32 temp_r3_2;
    u8 *temp_r3;
    __ct__16TargetCursorListFv((arg0 + 0xE0));
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((saddr)TTecAnti_name_ref);
    ((TTecAnti *)arg0)->m_13c = 1;
    copy_technique_target_list((S_8022B3E8 *)(arg0 + 0xE0), (S_8022B3E8 *)(targets));
    ((TechniqueParams *)(arg0 + 0x74))->copy(&technique_param_table[16]);
    TTecAnti__sub_8022AD94(arg0);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xDC));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = (f32) (5.0f + ((TTecAnti *)arg0)->m_7c);
    }
    temp_r3_2 = ((TTecAnti *)arg0)->source;
    if (temp_r3_2 != 0U) {
        ((TTecAnti *)arg0)->m_a8 = get_entity_id(temp_r3_2);
    }
    if ((s32) ((TTecAnti *)arg0)->m_ac != 0) {
        ((TTecAnti *)arg0)->play_anti_cast_sound();
        TTecAnti__sub_8022AD74(arg0);
    }
}
#undef arg0

void run_task__8TTecAntiFv(Anti_8022B150 *self) {
    uaddr target;
    s32 i;
    self->source = (uaddr)find_entity_by_id(self->source_id);
    if (self->source == 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (self->captured != 0) {
        if (self->level == 0) {
            ((TTecAnti *)self)->vfunc_7((void *)self->source);
        } else {
            ((TTecAnti *)self)->vfunc_7((void *)self->source);
            if (self->count != 0) {
                for (i = 0; i < self->count; i++) {
                    target = (uaddr)find_entity_by_id(self->targets[i].id);
                    if ((TTecLuker::is_parents_unqueued(target) != 0) && (TObjPlayer::is_valid_and_active(target) != 0)) {
                        ((TTecAnti *)self)->vfunc_7((void *)target);
                    }
                }
            }
        }
    } else if (self->level == 0) {
        ((TTecAnti *)self)->vfunc_7((void *)self->source);
    } else {
        deliver_technique_to_party_targets(self);
    }
    ((TObject *)self)->queue_destruction();
}

TTecAnti::~TTecAnti() {

}

void TTecAnti::create(void *source, void *origin, void *targets, s32 level) {
    new TTecAnti(source, origin, targets, level);
}

void TTecAnti::vfunc_7(void *pl_arg) {
    Anti_8022AEF8 *self = (Anti_8022AEF8 *)this;
    Player_8022AEF8 *pl = (Player_8022AEF8 *)pl_arg;
    Hit_8022AEF8 hit;
    void *o;
    hit.type = 7;
    hit.power = self->power;
    if (((TObjPlayer *)pl)->is_script_controlled() != 0) {
        return;
    }
    pl->m21(self->caster, hit, 0, 0x10, self->level);
    if (is_split_screen() == 0) {
        TWindowCtrl::show_party_effect((void*)(get_entity_id((saddr)self->caster)), (void*)(get_entity_id((saddr)pl)), (void*)7);
    }
    if ((u16)get_entity_id((saddr)self->caster) == (u16)get_entity_id((saddr)pl)) {
        if (self->xAC != 0) {
            o = TObject::operator new(0x48);
            if (o != NULL) {
                construct_self_effect__8TTecAntiFPvPvPviPv((Obj_8022AE10 *)o, (const Vec *)pl->x2FC, (const Vec *)pl->pos, get_entity_id((saddr)pl), tl_07);
            }
        }
    } else if (self->xAC != 0) {
        o = spawn_particle_effect_with_flags((const Vec *)pl->x2FC, 0x1F8, 0x10);
        if (o != NULL) {
            set_owner_id__13TParticleCtrlFUs(o, get_entity_id((saddr)pl));
        }
        o = spawn_particle_effect_with_flags((const Vec *)pl->x2FC, 0x1FF, 0x10);
        if (o != NULL) {
            set_owner_id__13TParticleCtrlFUs(o, get_entity_id((saddr)pl));
        }
    }
    if (self->xAC != 0) {
        o = TObject::operator new(0x30);
        if (o != NULL) {
            construct_delayed_point_sound((u8 *)o, (u8 *)pl->x2FC, (s16)(0xF), 0x4002AD11, (u8 *)tl_07);
        }
    }
}

Obj_8022AE10 *construct_self_effect__8TTecAntiFPvPvPviPv(Obj_8022AE10 *self, const Vec *body, const Vec *ground, s32 actor, void *parent) {
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    self->vtbl = __vt__13TUnk_804CC0E8;
    VecCopy((Vec *)&self->body, (const Vec *)body);
    VecCopy((Vec *)&self->ground, (const Vec *)ground);
    for (i = 0; i < 4; i++) {
        AntiRow_8022AE10 *row = &TTecAnti__self_effect_rows[i];
        void *p;
        if (row->flags & 1) {
            p = create_timed_particle_emitter_with_flags(&self->ground, row->c, row->a, row->b, 0x10);
            if (p != NULL) {
                set_owner_id__13TParticleCtrlFUs(p, actor);
            }
        } else {
            p = create_timed_particle_emitter_with_flags(&self->body, row->c, row->a, row->b, 0x10);
            if (p != NULL) {
                set_owner_id__13TParticleCtrlFUs(p, actor);
            }
        }
    }
    return self;
}

TUnk_804CC0E8::~TUnk_804CC0E8() {

}

void TUnk_804CC0E8::run_task() { queue_destruction(); }

void TTecAnti__sub_8022AD94(void * _w0) {  }

int TTecAnti__sub_8022AD74(void* p) { return spawn_support_tec_range_effect(p); }

void TTecAnti::play_anti_cast_sound() {
    Obj_8022ACB4 *arg0 = (Obj_8022ACB4 *)this;
    s32 r;
    switch (*(s16 *)&this->m_a6) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AB10, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AB10, (u8 *)arg0 + 0x20, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AB10, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
}
