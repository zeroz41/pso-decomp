#include "types.h"
#include "pso/misc/TParticleCtrl_800867E4.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#include "pso/misc/TTecReverser.h"
#include "pso/misc/TUnk_804CCBC0.h"
#include "pso/misc/TTecResta.h"
#include "pso/misc/TTecAnti.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80239C48___vt__9TTecResta {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802394B0_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

struct Vec_8023967C { f32 x, y, z; };

struct Row_8023967C { s32 delay; s32 duration; s32 entry; u32 flags; };

struct Resta_8023967C { u8 pad[0x18]; s32 *vt; void *emitters[3]; s32 owner; s32 x2c; };

struct Target_802399F8 { u16 id; u8 pad[6]; };

struct Resta_802399F8 {
    u8 pad0[0x1C];
    u32 source;
    u8 pad1[0xA4 - 0x20];
    s16 level;
    u8 pad2[0xA8 - 0xA6];
    u16 source_id;
    u8 pad3[0xE0 - 0xAA];
    s32 count;
    Target_802399F8 targets[11];
    s32 captured;
};

struct Resta_8023967C;
struct Vec_8023967C;
struct HitInfo_8023985C { s32 type; f32 power; };

struct VBase_8023985C { char pad[0x18]; };

struct VObj_8023985C : VBase_8023985C {
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
    virtual void m21(void *, HitInfo_8023985C *, s32, s32, s32);
};

struct VBase_18_9c98dd { char pad[0x18]; };

struct HitInfo_80239CF4 { s32 type; f32 power; };

struct VObj_18_9c98dd : VBase_18_9c98dd {
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
    virtual void m21(void *, HitInfo_80239CF4 *, s32, s32, s32);
};

struct Obj_80239CF4 { u8 pad[0x1C]; void *source; u8 pad20[0x88 - 0x20]; f32 power; };

extern "C" {
s32 get_entity_id(int);
s32 TTecPlayerInfluence__ct(void *, void *, void *, void *);
extern s32 __vt__9TTecResta[];
extern s32 lbl_805D3810;
extern const f32 TTecResta__data_805DC908;
u8 *TTecResta__sub_80239C48(TTecResta *arg0, s32 arg1, s32 arg2, s32 arg3);
f32 *calc_technique_parameters(s32, s32, s32);
s32 is_technique_ready__8TTecCtrlFv(int);
extern RecoveredGlobal_802394B0_lbl_804CC55C lbl_804CC55C;
extern s32 lbl_804CCBC0[];
extern Row_8023967C TTecResta__self_recovery_effect_table[];
void __ct__7TObjectFP7TObject(void *, void *);
void set_owner_id__13TParticleCtrlFUs(void *, s32);
Resta_8023967C *construct_self_recovery__9TTecRestaFPvPviPv(Resta_8023967C *self, Vec_8023967C *pos, s32 owner, void *parent);
s32 queue_destruction__7TObjectFv();
void *find_entity_by_id(u16 id);
void deliver_technique_to_party_targets(void *);
void run_task__9TTecRestaFv(Resta_802399F8 *self);
s32 is_split_screen(void);
s32 is_script_controlled__10TObjPlayerFv(void *);
void *__nw__7TObjectFUl(int);
}
u8 *construct_delayed_point_sound(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3, u8 *arg4);
extern s32 tl_07;
extern "C" {
s32 copy_technique_target_list(void *, void *);
void *TTecResta__ct(TTecResta *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
void *__dt__13TUnk_804CCBC0Fv(void *arg0, s16 arg1);
void *__dt__9TTecRestaFv(void *arg0, s16 arg1);
void create__9TTecRestaFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
void __dl__7TObjectFPv(void *);
void *__dt__19TTecPlayerInfluenceFv(void *arg0, s16 arg1);
void __dt__7TObjectFv(void *, int);
int spawn_support_tec_range_effect(void*);

int TTecResta::init_cast() { return spawn_support_tec_range_effect(this); }

typedef struct RecoveredGlobal_802394B0_lbl_804CC55C RecoveredGlobal_802394B0_lbl_804CC55C;
typedef char RecoveredGlobal_802394B0_lbl_804CC55C_size[((sizeof(RecoveredGlobal_802394B0_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
f32 TTecResta::calc_heal_amount(s32 arg0) {
  f32 *temp_r3;
  f32 var_f31;
  temp_r3 = (f32 *) calc_technique_parameters(0xF, arg0, 0xFFFF);
  var_f31 = *((f32 *) (((s8 *) temp_r3) + 0));
  var_f31 = var_f31 + ((f32) (arg0 * 5));
  if (is_technique_ready__8TTecCtrlFv((int) temp_r3) != 0)
  {
    var_f31 *= *((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x78));
  }
  return var_f31;
}

void TTecResta::init_parameters() {
    u8 *arg0 = (u8 *)this;
  int new_var;
  new_var = (int) calc_technique_parameters(0xF, this->m_a4, 0xFFFF);
  ((TTecAnti *)(arg0 + 0x74))->copy_params((u8 *)new_var);
  this->m_74 = (f32) ((this->m_74) + ((f32) ((this->m_98) * (this->m_a4))));
  if (((s32 (*)(void))is_technique_ready__8TTecCtrlFv)() != 0)
  {
    this->m_74 = (f32) ((this->m_74) * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x78))));
  }
}

void TUnk_804CCBC0::run_task() {
    s32 temp_r4;

    temp_r4 = this->m_2c;
    this->m_2c = (temp_r4 + 1);
    if (temp_r4 > 0xB4) {
        queue_destruction__7TObjectFv();
    }
}

void *__dt__13TUnk_804CCBC0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804CCBC0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_common_subs off
Resta_8023967C *construct_self_recovery__9TTecRestaFPvPviPv(Resta_8023967C *self, Vec_8023967C *pos, s32 owner, void *parent) {
    Vec_8023967C v;
    s32 i;
    Row_8023967C *row;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = ((s32 *)&lbl_804CCBC0);
    self->x2c = 0;
    for (i = 0; i < 3; i++) {
        self->emitters[i] = 0;
    }
    self->owner = owner;
    for (i = 0; i < 3; i++) {
        VecCopy((Vec *)&v, (const Vec *)pos);
        row = &TTecResta__self_recovery_effect_table[i];
        if (row->flags & 1) {
            v.y -= TTecResta__data_805DC908;
        }
        if (i == 2) {
            self->emitters[i] = create_timed_particle_emitter_with_flags(&v, row->entry, row->delay, row->duration, 0x30);
        } else {
            self->emitters[i] = create_timed_particle_emitter_with_flags(&v, row->entry, row->delay, row->duration, 0x10);
        }
        if (self->emitters[i] != 0) {
            set_owner_id__13TParticleCtrlFUs(self->emitters[i], get_entity_id(self->owner));
        }
    }
    return self;
}
#pragma pop

void create__9TTecRestaFPvPvPvPv(void *owner, void *pos, void *arg2, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x140);
    if (o != NULL) {
        TTecResta__ct((TTecResta *)o, owner, pos, arg2, level);
    }
}

void TTecResta::create(void *owner, void *pos, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x140);
    if (o != NULL) {
        TTecResta__sub_80239C48((TTecResta *)((u8 *)o), (s32)owner, (s32)pos, (s32)level);
    }
}

#pragma push
#pragma opt_common_subs off
void TTecResta::vfunc_7(void *arg1_arg) {
    TTecResta *arg0 = this;
    VObj_8023985C *player = (VObj_8023985C *)arg1_arg;
    HitInfo_8023985C h;
    if (is_script_controlled__10TObjPlayerFv(player) != 0) {
        return;
    }
    h.type = 6;
    h.power = arg0->m_74;
    if (is_split_screen() == 0) {
        TWindowCtrl::show_party_effect((void*)(get_entity_id(arg0->source)), (void*)(get_entity_id((int)player)), (void*)6);
    }
    HitInfo_8023985C c = h;
    player->m21((void *)arg0->source, &c, 0, 0xF, -1);
    if ((u16)get_entity_id(arg0->source) == (u16)get_entity_id((int)player)) {
        if (*(s32 *)&arg0->m_ac != 0) {
            void *o = __nw__7TObjectFUl(0x30);
            if (o != NULL) {
                construct_self_recovery__9TTecRestaFPvPviPv((Resta_8023967C *)o, (Vec_8023967C *)((u8 *)player + 0x2FC), arg0->source, (void *)tl_07);
            }
        }
    } else if (*(s32 *)&arg0->m_ac != 0) {
        void *e = spawn_particle_effect_with_flags((u8 *)player + 0x2FC, 0x1F6, 0x10);
        if (e != NULL) {
            set_owner_id__13TParticleCtrlFUs(e, get_entity_id((int)player));
        }
        e = spawn_particle_effect_with_flags((u8 *)player + 0x2FC, 0x1F7, 0x10);
        if (e != NULL) {
            set_owner_id__13TParticleCtrlFUs(e, get_entity_id((int)player));
        }
    }
    if (*(s32 *)&arg0->m_ac != 0) {
        void *o = __nw__7TObjectFUl(0x30);
        if (o != NULL) {
            construct_delayed_point_sound((u8 *)o, (u8 *)((u8 *)player + 0x2FC), (s16)(0x14), 0x4002A80F, (u8 *)tl_07);
        }
    }
}
#pragma pop

void TTecResta::render() {  }

void run_task__9TTecRestaFv(Resta_802399F8 *self) {
    u32 target;
    s32 i;
    self->source = (u32)find_entity_by_id(self->source_id);
    if (TTecLuker::is_parents_unqueued(self->source) == 0) {
        ((void (*)(void *))queue_destruction__7TObjectFv)(self);
        return;
    }
    if (self->captured != 0) {
        if (self->level <= 1) {
            ((TTecResta *)self)->vfunc_7((void *)self->source);
        } else {
            ((TTecResta *)self)->vfunc_7((void *)self->source);
            if (self->count != 0) {
                for (i = 0; i < self->count; i++) {
                    target = (u32)find_entity_by_id(self->targets[i].id);
                    if (TTecLuker::is_parents_unqueued(target) != 0) {
                        ((TTecResta *)self)->vfunc_7((void *)target);
                    }
                }
            }
        }
    } else if (self->level <= 1) {
        ((TTecResta *)self)->vfunc_7((void *)self->source);
    } else {
        deliver_technique_to_party_targets(self);
    }
    ((void (*)(void *))queue_destruction__7TObjectFv)(self);
}

void *__dt__9TTecRestaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TTecResta;
        __dt__19TTecPlayerInfluenceFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80239C48___vt__9TTecResta_size[sizeof(RecoveredGlobal_80239C48___vt__9TTecResta) == 0x20 ? 1 : -1];

#pragma push
#pragma opt_common_subs off
void *TTecResta__ct(TTecResta *arg0, void *owner, void *pos, void *arg3, void *level) {
    u32 src;
    u8 *p;
    TTecPlayerInfluence__ct(arg0, owner, pos, level);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TTecResta;
    ((TObjPlayer *)((u8 *)arg0 + 0xE0))->construct_target_cursor_records();
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D3810;
    *(s32 *)&arg0->m_13c = 1;
    copy_technique_target_list((u8 *)arg0 + 0xE0, arg3);
    arg0->init_parameters();
    p = *(u8 **)((s8 *)arg0 + 0xDC);
    if (p != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)p + 0xA4)) + 0xC) = TTecResta__data_805DC908 + arg0->m_7c;
    }
    src = arg0->source;
    if (src != 0) {
        *(s16 *)&arg0->m_a8 = get_entity_id(src);
    }
    if (*(s32 *)&arg0->m_ac != 0) {
        arg0->init_cast();
        arg0->play_launch_sound();
    }
    return arg0;
}
#pragma pop

u8 *TTecResta__sub_80239C48(TTecResta *arg0, s32 owner, s32 pos, s32 level) {
    u32 temp_r3_2;
    u8 *temp_r3;
    TTecPlayerInfluence__ct((void *)arg0, (void *)owner, (void *)pos, (void *)level);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80239C48___vt__9TTecResta *)&__vt__9TTecResta).value;
    ((TObjPlayer *)((u8 *)arg0 + 0xE0))->construct_target_cursor_records();
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3810;
    arg0->m_13c = 0;
    arg0->init_parameters();
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xDC));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = (f32) (TTecResta__data_805DC908 + arg0->m_7c);
    }
    temp_r3_2 = arg0->source;
    if (temp_r3_2 != 0U) {
        arg0->m_a8 = get_entity_id(temp_r3_2);
    }
    if ((s32) arg0->m_ac != 0) {
        arg0->init_cast();
        arg0->play_launch_sound();
    }
    return (u8 *)arg0;
}
void TTecReverser::vfunc_6(void *arg1_arg) {
    Obj_80239CF4 *arg0 = (Obj_80239CF4 *)this;
    VObj_18_9c98dd *arg1 = (VObj_18_9c98dd *)arg1_arg;
    HitInfo_80239CF4 h;
    h.type = 8;
    h.power = arg0->power;
    HitInfo_80239CF4 c = h;
    arg1->m21(arg0->source, &c, 0, -1, -1);
    void *o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        construct_delayed_point_sound((u8 *)o, (u8 *)((u8 *)arg1 + 0x38), (s16)(0x2D), 0x4002AD13, (u8 *)tl_07);
    }
}
}
