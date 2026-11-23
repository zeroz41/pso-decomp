#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecResta.h"
#include "pso/unk/TUnk_804CCBC0.h"
#include "pso/unk/TUnk_804CCA90.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecReverser.h"


#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"

#pragma readonly_strings on


const char *TTecResta__name = "TTecResta";


struct Row_8023967C { s32 delay; s32 duration; s32 entry; u32 flags; };


struct Target_802399F8 { u16 id; u8 pad[6]; };

struct Resta_802399F8 {
    u8 pad0[0x1C];
    uaddr source;
    u8 pad1[0xA4 - 0x20];
    s16 level;
    u8 pad2[0xA8 - 0xA6];
    u16 source_id;
    u8 pad3[0xE0 - 0xAA];
    s32 count;
    Target_802399F8 targets[11];
    s32 captured;
};

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
saddr get_entity_id(int);
Row_8023967C TTecResta__self_recovery_effect_table[3] = {
    {0x14, 1, 0x2C, 0},
    {0, 1, 0x2D, 1},
    {0x14, 1, 0x2E, 0},
};
void set_owner_id__13TParticleCtrlFUs(void *, s32);
void deliver_technique_to_party_targets(void *);
void run_task__9TTecRestaFv(Resta_802399F8 *self);
s32 is_split_screen(void);
s32 copy_technique_target_list(void *, void *);
int spawn_support_tec_range_effect(void*);


}
void TTecReverser::vfunc_6(void *arg1_arg) {
    Obj_80239CF4 *arg0 = (Obj_80239CF4 *)this;
    VObj_18_9c98dd *arg1 = (VObj_18_9c98dd *)arg1_arg;
    HitInfo_80239CF4 h;
    h.type = 8;
    h.power = arg0->power;
    HitInfo_80239CF4 c = h;
    arg1->m21(arg0->source, &c, 0, -1, -1);
    new TUnk_804CCA90((Vec *)((u8 *)arg1 + 0x38), 0x2D, 0x4002AD13, tl_07);
}

TTecResta::TTecResta(void *owner, void *pos, s32 level) : TTecPlayerInfluence(owner, pos, level) {
#define arg0 this
    u32 temp_r3_2;
    u8 *temp_r3;
    __ct__16TargetCursorListFv(((u8 *)arg0 + 0xE0));
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((saddr)TTecResta__name);
    arg0->m_13c = 0;
    arg0->init_parameters();
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xDC));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = (f32) (5.0f + arg0->m_7c);
    }
    temp_r3_2 = arg0->source;
    if (temp_r3_2 != 0U) {
        arg0->m_a8 = get_entity_id(temp_r3_2);
    }
    if ((s32) arg0->m_ac != 0) {
        arg0->init_cast();
        arg0->play_launch_sound();
    }
#undef arg0
}

#pragma push
#pragma opt_common_subs off
TTecResta::TTecResta(void *owner, void *pos, void *targets, s32 level) : TTecPlayerInfluence(owner, pos, level) {
#define arg0 this
    u32 src;
    u8 *p;
    __ct__16TargetCursorListFv(((u8 *)arg0 + 0xE0));
    *(s32 *)((s8 *)arg0 + 0) = ((saddr)TTecResta__name);
    *(s32 *)&arg0->m_13c = 1;
    copy_technique_target_list((u8 *)arg0 + 0xE0, targets);
    arg0->init_parameters();
    p = *(u8 **)((s8 *)arg0 + 0xDC);
    if (p != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)p + 0xA4)) + 0xC) = 5.0f + arg0->m_7c;
    }
    src = arg0->source;
    if (src != 0) {
        *(s16 *)&arg0->m_a8 = get_entity_id(src);
    }
    if (*(s32 *)&arg0->m_ac != 0) {
        arg0->init_cast();
        arg0->play_launch_sound();
    }
#undef arg0
}
#pragma pop

TTecResta::~TTecResta() {

}

void run_task__9TTecRestaFv(Resta_802399F8 *self) {
    uaddr target;
    s32 i;
    self->source = (uaddr)find_entity_by_id(self->source_id);
    if (TTecLuker::is_parents_unqueued(self->source) == 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (self->captured != 0) {
        if (self->level <= 1) {
            ((TTecResta *)self)->vfunc_7((void *)self->source);
        } else {
            ((TTecResta *)self)->vfunc_7((void *)self->source);
            if (self->count != 0) {
                for (i = 0; i < self->count; i++) {
                    target = (uaddr)find_entity_by_id(self->targets[i].id);
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
    ((TObject *)self)->queue_destruction();
}

void TTecResta::render() {  }

#pragma push
#pragma opt_common_subs off
void TTecResta::vfunc_7(void *arg1_arg) {
    TTecResta *arg0 = this;
    VObj_8023985C *player = (VObj_8023985C *)arg1_arg;
    HitInfo_8023985C h;
    if (((TObjPlayer *)player)->is_script_controlled() != 0) {
        return;
    }
    h.type = 6;
    h.power = arg0->m_74;
    if (is_split_screen() == 0) {
        TWindowCtrl::show_party_effect((void*)(get_entity_id(arg0->source)), (void*)(get_entity_id((saddr)player)), (void*)6);
    }
    HitInfo_8023985C c = h;
    player->m21((void *)arg0->source, &c, 0, 0xF, -1);
    if ((u16)get_entity_id(arg0->source) == (u16)get_entity_id((saddr)player)) {
        if (*(s32 *)&arg0->m_ac != 0) {
            new TUnk_804CCBC0((Vec *)((u8 *)player + 0x2FC), arg0->source, tl_07);
        }
    } else if (*(s32 *)&arg0->m_ac != 0) {
        void *e = spawn_particle_effect_with_flags((const Vec *)((u8 *)player + 0x2FC), 0x1F6, 0x10);
        if (e != NULL) {
            set_owner_id__13TParticleCtrlFUs(e, get_entity_id((saddr)player));
        }
        e = spawn_particle_effect_with_flags((const Vec *)((u8 *)player + 0x2FC), 0x1F7, 0x10);
        if (e != NULL) {
            set_owner_id__13TParticleCtrlFUs(e, get_entity_id((saddr)player));
        }
    }
    if (*(s32 *)&arg0->m_ac != 0) {
        new TUnk_804CCA90((Vec *)((u8 *)player + 0x2FC), 0x14, 0x4002A80F, tl_07);
    }
}
#pragma pop

void TTecResta::create(void *owner, void *pos, s32 level) {
    new TTecResta(owner, pos, level);
}

void TTecResta::create(void *source, void *origin, void *targets, s32 level) {
    new TTecResta(source, origin, targets, level);
}

#pragma push
#pragma opt_common_subs off
TUnk_804CCBC0::TUnk_804CCBC0(Vec *pos, s32 owner, TObject *parent) : TObject(parent) {
    Vec v;
    s32 i;
    Row_8023967C *row;
    m_timer = 0;
    for (i = 0; i < 3; i++) {
        m_emitters[i] = 0;
    }
    m_owner = owner;
    for (i = 0; i < 3; i++) {
        VecCopy(&v, pos);
        row = &TTecResta__self_recovery_effect_table[i];
        if (row->flags & 1) {
            v.y -= 5.0f;
        }
        if (i == 2) {
            m_emitters[i] = create_timed_particle_emitter_with_flags(&v, row->entry, row->delay, row->duration, 0x30);
        } else {
            m_emitters[i] = create_timed_particle_emitter_with_flags(&v, row->entry, row->delay, row->duration, 0x10);
        }
        if (m_emitters[i] != 0) {
            set_owner_id__13TParticleCtrlFUs(m_emitters[i], get_entity_id(m_owner));
        }
    }
}
#pragma pop

TUnk_804CCBC0::~TUnk_804CCBC0() {

}

void TUnk_804CCBC0::run_task() {
    if (m_timer++ > 180) {
        queue_destruction();
    }
}

void TTecResta::init_parameters() {
    u8 *arg0 = (u8 *)this;
  saddr new_var;
  new_var = (saddr) calc_technique_parameters(0xF, this->m_a4, 0xFFFF);
  ((TechniqueParams *)(arg0 + 0x74))->copy((TechniqueParams *)new_var);
  this->m_74 = (f32) ((this->m_74) + ((f32) ((this->m_98) * (this->m_a4))));
  if (TTecCtrl::is_technique_ready() != 0)
  {
    this->m_74 = (f32) ((this->m_74) * lbl_804CC55C[15].pad_00);
  }
}

f32 TTecResta::calc_heal_amount(s32 level) {
  f32 *temp_r3;
  f32 var_f31;
  temp_r3 = (f32 *) calc_technique_parameters(0xF, level, 0xFFFF);
  var_f31 = *((f32 *) (((s8 *) temp_r3) + 0));
  var_f31 = var_f31 + ((f32) (level * 5));
  if (TTecCtrl::is_technique_ready() != 0)
  {
    var_f31 *= lbl_804CC55C[15].pad_00;
  }
  return var_f31;
}

int TTecResta::init_cast() { return spawn_support_tec_range_effect(this); }
