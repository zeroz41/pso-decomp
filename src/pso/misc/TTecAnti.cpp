#include "types.h"
#include "pso/misc/TParticleCtrl_800867E4.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804CC0E8.h"
#include "pso/misc/TTecAnti.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

struct Obj_8022ACB4 { u8 pad[0xA6]; s16 state; };
extern "C" {
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(int, void *, int, int);
void TTecAnti::play_anti_cast_sound() {
    Obj_8022ACB4 *arg0 = (Obj_8022ACB4 *)this;
    s32 r;
    switch (*(s16 *)&this->m_a6) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AB10, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, 0x100, 0);
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
            update_technique_slot__10TTecRaFoieFl(r, -0x100, 0);
        }
        break;
    }
}

}

struct RecoveredGlobal_8022B288___vt__8TTecAnti { s32 value; u8 remaining[0x1C]; };
typedef char RecoveredGlobal_8022B288___vt__8TTecAnti_size[sizeof(RecoveredGlobal_8022B288___vt__8TTecAnti) == 0x20 ? 1 : -1];

struct RecoveredGlobal_8022B288_lbl_804CC1CC { s32 value; u8 remaining[0x340]; };
typedef char RecoveredGlobal_8022B288_lbl_804CC1CC_size[sizeof(RecoveredGlobal_8022B288_lbl_804CC1CC) == 0x344 ? 1 : -1];

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Sub_8022B3E8 { s32 w[22]; };

struct S_8022B3E8 { s32 f0; Sub_8022B3E8 sub; };

struct Vec_8022AE10 { f32 x, y, z; };

struct AntiRow_8022AE10 { s32 a; s32 b; s32 c; s32 flags; };

struct Obj_8022AE10 {
    u8 pad0[0x18];
    void *vtbl;
    u8 pad1C[0x30 - 0x1C];
    Vec_8022AE10 body;
    Vec_8022AE10 ground;
};

struct Target_8022B150 { u16 id; u8 pad[6]; };

struct Anti_8022B150 {
    u8 pad0[0x1C];
    u32 source;
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
struct Vec_8022AE10;
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
s32 get_entity_id(int);
int TTecAnti__sub_8022AD74(void* p);
void TTecAnti__sub_8022AD94(void *);
s32 TTecPlayerInfluence__ct(void *, void *, void *, void *);
extern s32 __vt__8TTecAnti[];
extern RecoveredGlobal_8022B288_lbl_804CC1CC technique_param_table;
extern s32 TTecAnti_name_ref;
extern const f32 lbl_805DC798;
u8 *TTecAnti__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
S_8022B3E8 *copy_technique_target_list(S_8022B3E8 *d, S_8022B3E8 *s);
void set_owner_id__13TParticleCtrlFUs(void *, s32);
void __ct__7TObjectFP7TObject(void *, void *);
extern AntiRow_8022AE10 TTecAnti__self_effect_rows[];
extern s32 lbl_804CC0E8[];
Obj_8022AE10 *construct_self_effect__8TTecAntiFPvPvPviPv(Obj_8022AE10 *self, const Vec_8022AE10 *body, const Vec_8022AE10 *ground, s32 actor, void *parent);
void *find_entity_by_id(u16 id);
s32 is_parents_unqueued__9TTecLukerFUl();
void deliver_technique_to_party_targets(void *);
void run_task__8TTecAntiFv(Anti_8022B150 *self);
s32 is_split_screen();
void *spawn_particle_effect_with_flags(void *, int, int);
s32 is_script_controlled__10TObjPlayerFv(void *);
void *__nw__7TObjectFUl(int);
}
u8 *construct_delayed_point_sound(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3, u8 *arg4);
extern void *tl_07;
extern "C" {
void *__dt__13TUnk_804CC0E8Fv(void *arg0, s16 arg1);
void *__dt__8TTecAntiFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__19TTecPlayerInfluenceFv(void *arg0, s16 arg1);
void __dt__7TObjectFv(void *, int);
int spawn_support_tec_range_effect(void*);

int TTecAnti__sub_8022AD74(void* p) { return spawn_support_tec_range_effect(p); }
void TTecAnti__sub_8022AD94(void * _w0) {  }
void TUnk_804CC0E8::run_task() { queue_destruction__7TObjectFv(this); }

void *__dt__13TUnk_804CC0E8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804CC0E8;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Obj_8022AE10 *construct_self_effect__8TTecAntiFPvPvPviPv(Obj_8022AE10 *self, const Vec_8022AE10 *body, const Vec_8022AE10 *ground, s32 actor, void *parent) {
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    self->vtbl = lbl_804CC0E8;
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

void TTecAnti::vfunc_7(void *pl_arg) {
    Anti_8022AEF8 *self = (Anti_8022AEF8 *)this;
    Player_8022AEF8 *pl = (Player_8022AEF8 *)pl_arg;
    Hit_8022AEF8 hit;
    void *o;
    hit.type = 7;
    hit.power = self->power;
    if (is_script_controlled__10TObjPlayerFv(pl) != 0) {
        return;
    }
    pl->m21(self->caster, hit, 0, 0x10, self->level);
    if (is_split_screen() == 0) {
        TWindowCtrl::show_party_effect((void*)(get_entity_id((int)self->caster)), (void*)(get_entity_id((int)pl)), (void*)7);
    }
    if ((u16)get_entity_id((int)self->caster) == (u16)get_entity_id((int)pl)) {
        if (self->xAC != 0) {
            o = __nw__7TObjectFUl(0x48);
            if (o != NULL) {
                construct_self_effect__8TTecAntiFPvPvPviPv((Obj_8022AE10 *)o, (const Vec_8022AE10 *)pl->x2FC, (const Vec_8022AE10 *)pl->pos, get_entity_id((int)pl), tl_07);
            }
        }
    } else if (self->xAC != 0) {
        o = spawn_particle_effect_with_flags(pl->x2FC, 0x1F8, 0x10);
        if (o != NULL) {
            set_owner_id__13TParticleCtrlFUs(o, get_entity_id((int)pl));
        }
        o = spawn_particle_effect_with_flags(pl->x2FC, 0x1FF, 0x10);
        if (o != NULL) {
            set_owner_id__13TParticleCtrlFUs(o, get_entity_id((int)pl));
        }
    }
    if (self->xAC != 0) {
        o = __nw__7TObjectFUl(0x30);
        if (o != NULL) {
            construct_delayed_point_sound((u8 *)o, (u8 *)pl->x2FC, (s16)(0xF), 0x4002AD11, (u8 *)tl_07);
        }
    }
}

void TTecAnti::create(void *owner, void *pos, void *arg2, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x140);
    if (o != NULL) {
        TTecAnti__ct((u8 *)o, (s32)owner, (s32)pos, (s32)arg2, (s32)level);
    }
}

void *__dt__8TTecAntiFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__8TTecAnti;
        __dt__19TTecPlayerInfluenceFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void run_task__8TTecAntiFv(Anti_8022B150 *self) {
    u32 target;
    s32 i;
    self->source = (u32)find_entity_by_id(self->source_id);
    if (self->source == 0) {
        queue_destruction__7TObjectFv((self));
        return;
    }
    if (self->captured != 0) {
        if (self->level == 0) {
            ((TTecAnti *)self)->vfunc_7((void *)self->source);
        } else {
            ((TTecAnti *)self)->vfunc_7((void *)self->source);
            if (self->count != 0) {
                for (i = 0; i < self->count; i++) {
                    target = (u32)find_entity_by_id(self->targets[i].id);
                    if ((is_parents_unqueued__9TTecLukerFUl() != 0) && (TObjPlayer::is_valid_and_active(target) != 0)) {
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
    queue_destruction__7TObjectFv((self));
}

u8 *TTecAnti__ct(u8 *arg0, s32 owner, s32 pos, s32 arg3, s32 level) {
    u32 temp_r3_2;
    u8 *temp_r3;
    TTecPlayerInfluence__ct((void *)arg0, (void *)owner, (void *)pos, (void *)level);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8022B288___vt__8TTecAnti *)&__vt__8TTecAnti).value;
    ((TObjPlayer *)(arg0 + 0xE0))->construct_target_cursor_records();
    *(s32 *)((s8 *)arg0 + 0) = (s32) TTecAnti_name_ref;
    ((TTecAnti *)arg0)->m_13c = 1;
    copy_technique_target_list((S_8022B3E8 *)(arg0 + 0xE0), (S_8022B3E8 *)(arg3));
    ((TTecAnti *)(arg0 + 0x74))->copy_params((u8 *)((void *) ((u8 *)&technique_param_table.value + 0x2C0)));
    TTecAnti__sub_8022AD94(arg0);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xDC));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = (f32) (lbl_805DC798 + ((TTecAnti *)arg0)->m_7c);
    }
    temp_r3_2 = ((TTecAnti *)arg0)->source;
    if (temp_r3_2 != 0U) {
        ((TTecAnti *)arg0)->m_a8 = get_entity_id(temp_r3_2);
    }
    if ((s32) ((TTecAnti *)arg0)->m_ac != 0) {
        ((TTecAnti *)arg0)->play_anti_cast_sound();
        TTecAnti__sub_8022AD74(arg0);
    }
    return arg0;
}

void TTecAnti::copy_params(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)&this->m_name = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)&this->m_flags = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)&this->m_prev = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(f32 *)&this->m_next = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    *(s16 *)&this->m_up = (s16) *(s16 *)((s8 *)arg1 + 0x10);
    *(s16 *)((s8 *)arg0 + 0x12) = (s16) *(s16 *)((s8 *)arg1 + 0x12);
    *(s16 *)&this->m_down = (s16) *(s16 *)((s8 *)arg1 + 0x14);
    *(s16 *)((s8 *)arg0 + 0x16) = (s16) *(s16 *)((s8 *)arg1 + 0x16);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    *(s32 *)&this->source = (s32) *(s32 *)((s8 *)arg1 + 0x1C);
    *(s16 *)((s8 *)arg0 + 0x20) = (s16) *(s16 *)((s8 *)arg1 + 0x20);
    *(u8 *)((s8 *)arg0 + 0x22) = (u8) *(u8 *)((s8 *)arg1 + 0x22);
    *(u8 *)((s8 *)arg0 + 0x23) = (u8) *(u8 *)((s8 *)arg1 + 0x23);
    *(s16 *)((s8 *)arg0 + 0x24) = (s16) *(s16 *)((s8 *)arg1 + 0x24);
    *(s16 *)((s8 *)arg0 + 0x26) = (s16) *(s16 *)((s8 *)arg1 + 0x26);
    *(s16 *)((s8 *)arg0 + 0x28) = (s16) *(s16 *)((s8 *)arg1 + 0x28);
    *(s16 *)((s8 *)arg0 + 0x2A) = (s16) *(s16 *)((s8 *)arg1 + 0x2A);
}

S_8022B3E8 *copy_technique_target_list(S_8022B3E8 *d, S_8022B3E8 *s) {
    d->f0 = s->f0;
    d->sub = s->sub;
    return d;
}

void TTecAnti::render() {  }
}
