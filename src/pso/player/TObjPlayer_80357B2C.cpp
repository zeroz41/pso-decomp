#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecZonde.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TUnk_804F166C.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"

struct Base_8035836C_80357734 { char pad[0x18]; };
struct VObj_8035836C_80357734 : Base_8035836C_80357734 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, void *);
};
struct Base_803583B4_80357734 { char pad[0x18]; };
struct VObj_803583B4_80357734 : Base_803583B4_80357734 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, void *);
};
struct Base_803584FC_80357734 { char pad[0x18]; };
struct VObj_803584FC_80357734 : Base_803584FC_80357734 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, s32 *);
};
struct Base_80358824_80357734 { char pad[0x18]; };
struct VObj_80358824_80357734 : Base_80358824_80357734 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, void *);
};

struct RecoveredGlobal_803589F8_lbl_804F15C8 { s32 value; u8 remaining[0xA0]; };
typedef char RecoveredGlobal_803589F8_lbl_804F15C8_size[sizeof(RecoveredGlobal_803589F8_lbl_804F15C8) == 0xA4 ? 1 : -1];

#include <stddef.h>
#include "pso/ui/hud/TNowLoading.h"
#include "pso/item/TItem.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct RecoveredGlobal_80358048_lbl_804F166C {
    s32 value;
    u8 remaining[0x18];
};

struct Base_8035862C { u8 pad[0x18]; };

struct VObj_8035862C : Base_8035862C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, void *);
};

struct Vec_8035862C { f32 x, y, z; };

struct InwardOrbitDir { s32 x, y, z; };

static const Vec_8035862C lbl_804793D8 = {0.0f, -1.0f, 0.0f};
static const InwardOrbitDir lbl_804793E4 = {0, 0, 0x4000};


struct Vec_80357B2C { f32 x, y, z; };

struct Strike_80357B2C {
    Vec_80357B2C pos;
    Vec_80357B2C dir;
    f32 len;
};


extern "C" {
extern s32 tl_05;
u16 get_entity_id(void *);
int get_item_field_6__10TObjPlayerFPv(void *p);
u8 get_item_type__5TItemFv();
extern RecoveredGlobal_803589F8_lbl_804F15C8 weapon_special_effect_callbacks;
void dispatch_weapon_special_effect(s32 arg0, u32 arg1, s32 arg2, s32 arg3);
void *spawn_continuous_particle_with_direction(void *pos, void *dir, s32 id);
s32 __ct__7TObjectFP7TObject(void *, void *);
f32 sin_table_lookup(void *);
f32 cos_table_lookup(void *);
void *spawn_particle_effect(void *pos, s32 id);
u32 __nw__7TObjectFUl(s32);
u32 create_fire_explosion_effect(u32, s32, s32, s32, f32);
int rand(void);
f32 vector_length(void *);
s32 normalize_vector(void *);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
s32 get_bml_motion(s32, s32);
s32 get_bml_model(s32, s32);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 update_battle_control_if_unlocked__10TObjPlayerFv();

}
extern s32 inward_orbit_effect_vtable[];
u8 *create_inward_orbit_effect(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
extern s32 tl_07;
void weapon_special_lightning_bolt_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 tl_particle;
void weapon_fire_explosion_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void spawn_scattered_lightning_strikes(u8 *arg0, s32 arg1);
void weapon_fractional_hp_effect(void *arg0, void *arg1, s32 arg2, s32 arg3);
void prepare_shock_special_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void prepare_freeze_special_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void weapon_dim_shadow_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void weapon_hell_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void weapon_dark_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 a, s32 b, s32 c);
#pragma push
#pragma fp_contract on
void spawn_scattered_lightning_strikes(u8 *arg0, s32 arg1) {
    Vec_80357B2C *p = (Vec_80357B2C *)arg0;
    Strike_80357B2C strikes[14];
    Strike_80357B2C *s;
    Vec_80357B2C *d;
    s32 i;
    u32 obj;
    f32 scale;
    s32 j;
    s32 k;
    s32 m;
    for (i = 0; i < 14; i++) {
        s = &strikes[i];
        s->pos.y = 100.0f + p->y;
        if (arg1 == 5 && i == 0) {
            s->pos.y = 500.0f + p->y;
        }
        s->pos.x = 13.0f * ((f32) i * (3.0517578e-05f * (f32) rand())) + p->x;
        s->pos.z = 13.0f * ((f32) i * (3.0517578e-05f * (f32) rand())) + p->z;
        d = &s->dir;
        s->dir.x = p->x - s->pos.x;
        s->dir.y = p->y - s->pos.y;
        s->dir.z = p->z - s->pos.z;
        s->len = vector_length(d);
        if (0.0f != s->len) {
            normalize_vector(d);
        }
    }
    scale = 0.5f;
    switch (arg1) {
    case 0:
        obj = __nw__7TObjectFUl(0x260);
        if (obj != 0) {
            ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&strikes[0].pos, (u8 *)&strikes[0].dir, 0x14000000, 0x14, strikes[0].len, 0.5f);
        }
        break;
    case 1:
        scale *= 1.2f;
        obj = __nw__7TObjectFUl(0x260);
        if (obj != 0) {
            ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&strikes[0].pos, (u8 *)&strikes[0].dir, 0x14000000, 0x14, strikes[0].len, (f32)scale);
        }
        break;
    case 2:
        scale *= 1.4f;
        obj = __nw__7TObjectFUl(0x260);
        if (obj != 0) {
            ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&strikes[0].pos, (u8 *)&strikes[0].dir, 0x14000000, 0x14, strikes[0].len, (f32)scale);
        }
        break;
    case 3:
        for (j = 0; j < 3; j++) {
            obj = __nw__7TObjectFUl(0x260);
            if (obj != 0) {
                ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&strikes[j].pos, (u8 *)&strikes[j].dir, 0x14000000, 0x14, strikes[j].len, 0.5f);
            }
        }
        break;
    case 4:
        scale *= 1.4f;
        for (k = 0; k < 3; k++) {
            obj = __nw__7TObjectFUl(0x260);
            if (obj != 0) {
                ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&strikes[k].pos, (u8 *)&strikes[k].dir, 0x14000000, 0x14, strikes[k].len, (f32)scale);
            }
        }
        break;
    case 5:
        for (m = 0; m < 14; m++) {
            if (m == 0) {
                obj = __nw__7TObjectFUl(0x260);
                if (obj != 0) {
                    ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&strikes[m].pos, (u8 *)&strikes[m].dir, 0x14000000, 0x14, strikes[m].len, 5.0f);
                }
            } else {
                obj = __nw__7TObjectFUl(0x260);
                if (obj != 0) {
                    ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&strikes[m].pos, (u8 *)&strikes[m].dir, 0x14000000, 0x14, strikes[m].len, 0.5f);
                }
            }
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on

void TUnk_804F166C::update_inward_orbit_point() {
    u8 *arg0 = (u8 *)this;
    this->m_34 = (f32) ((this->m_40 * sin_table_lookup((void *)(*(s32 *)&this->unk_44))) + *(f32 *)((s8 *)arg0 + 0x1C));
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) this->m_20;
    this->m_3c = (f32) ((this->m_40 * cos_table_lookup((void *)(*(s32 *)&this->unk_44))) + *(f32 *)((s8 *)arg0 + 0x24));
}
#pragma pop

void TUnk_804F166C::render() {  }

void TUnk_804F166C::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3_2;
    u8 *now_loading;
    *(s32 *)&this->unk_44 = (s32) (*(s32 *)&this->unk_44 - 0x1999);
    this->m_40 = (f32) (this->m_40 - 4.0f);
    ((TUnk_804F166C *)arg0)->update_inward_orbit_point();
    now_loading = (u8 *)(*(u8 * *)&this->unk_4C);
    if (now_loading != NULL) {
        ((TParticleCtrl *)now_loading)->set_position((u8 *)&this->m_34);
    }
    temp_r3_2 = this->m_48;
    if (temp_r3_2 > 0) {
        this->m_48 = (temp_r3_2 - 1);
        return;
    }
    ((TObject *)arg0)->queue_destruction();
}

void *TUnk_804F166C::dt_with_child_queue(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = inward_orbit_effect_vtable;
        if (*(void * *)&this->unk_4C != NULL) { ((TObject *)(*(void * *)&this->unk_4C))->queue_destruction(); }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_80358048_lbl_804F166C_size[sizeof(RecoveredGlobal_80358048_lbl_804F166C) == 0x1C ? 1 : -1];
u8 *create_inward_orbit_effect(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80358048_lbl_804F166C *)&inward_orbit_effect_vtable).value;
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(arg2));
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) ((5.0f * sin_table_lookup((void *)arg3)) + *(f32 *)((s8 *)arg2 + 0));
    ((TUnk_804F166C *)arg0)->m_20 = (f32) *(f32 *)((s8 *)arg2 + 4);
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) ((5.0f * cos_table_lookup((void *)arg3)) + *(f32 *)((s8 *)arg2 + 8));
    ((TUnk_804F166C *)arg0)->m_40 = 40.0f;
    *(s32 *)((s8 *)arg0 + 0x44) = (arg3 - 0x4000);
    ((TUnk_804F166C *)arg0)->m_48 = 0xA;
    ((TUnk_804F166C *)arg0)->update_inward_orbit_point();
    InwardOrbitDir dir = lbl_804793E4;
    *(s32 *)((s8 *)arg0 + 0x4C) = (s32)spawn_continuous_particle_with_direction((arg0 + 0x34), &dir, 0xA);
    return arg0;
}
#pragma pop

void TObjPlayer::update_battle_control_on_unlock(void *arg0, void *arg1, void *arg2, s32 arg3) {
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
}

void TObjPlayer::handle_exp_steal_effect(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
    if (arg3 == 1) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xA8);
    }
}


void TObjPlayer::handle_action(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
    if (arg3 == 1) {
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xA8);
        if (particle != NULL) {
            particle->set_scale(0.2f, 0.3f);
        }
    }
}

void TObjPlayer::dispatch_effect_by_type(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
    if (arg3 == 1) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0x10A);
    }
}

void weapon_fractional_hp_effect(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
    if (arg3 == 1) {
        spawn_particle_effect((s32 *)arg2, 0x1AC);
    }
}

void TObjPlayer::handle_symbol_chat_action(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
    if (arg3 == 1) {
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0x67);
        if (particle != NULL) {
            particle->set_scale(0.2f, 0.3f);
        }
    }
}

void TObjPlayer::handle_action_by_type(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
    if (arg3 == 1) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0x67);
    }
}

void TObjPlayer::handle_stage_event(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        update_battle_control_if_unlocked__10TObjPlayerFv();
    }
    if (arg3 == 1) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0x66);
    }
}

void TObjPlayer::trigger_biter_effect(s32 arg1, s32 arg2, s32 arg3) {
    u8 sp8[0x18];

    if (arg3 == 0) {
        struct VObj_8035836C_80357734 *o = (struct VObj_8035836C_80357734 *)this;
        o->m63(0x30, &sp8);
        spawn_particle_effect((s32 *)((s32 *) &sp8), 0x1AB);
    }
}

void prepare_shock_special_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp8[0x18];

    if (arg3 == 0) {
        struct VObj_803583B4_80357734 *o = (struct VObj_803583B4_80357734 *)arg0;
        o->m63(0x30, &sp8);
        spawn_particle_effect((s32 *)((s32 *) &sp8), 0x1AA);
    }
}


void weapon_hell_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xC6);
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xC9);
    }
    if (arg3 == 1) {
        {
            TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect((s32 *)arg2, 0x1C5);
            if (particle != NULL) {
                particle->set_scale(2.0f, 2.0f);
            }
        }
        {
            TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect((s32 *)arg2, 0x1C8);
            if (particle != NULL) {
                particle->set_scale(2.0f, 2.0f);
            }
        }
    }
}

void weapon_dark_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xC6);
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xC9);
    }
    if (arg3 == 1) {
        spawn_particle_effect((s32 *)arg2, 0x1C5);
        spawn_particle_effect((s32 *)arg2, 0x1C8);
    }
}

void weapon_dim_shadow_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8;

    if (arg3 == 0) {
        ((VObj_803584FC_80357734 *)arg0)->m63(0x30, &sp8);
        spawn_particle_effect(&sp8, 0x1A8);
        spawn_particle_effect(&sp8, 0x1A9);
    }
    if (arg3 == 1) {
        spawn_particle_effect_with_flags((void *)arg2, 0xC8, 0x40);
        create_timed_particle_emitter_with_flags((void *)arg2, 0x101, 0, 0x1E, 0x40);
    }
}

void TObjPlayer::dispatch_attack_event(void *arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xA0);
    }
    if (arg3 == 1) {
        spawn_scattered_lightning_strikes((u8 *)arg2, 4);
    }
}

void TObjPlayer::dispatch_by_type(void *arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xA0);
    }
    if (arg3 == 1) {
        spawn_scattered_lightning_strikes((u8 *)arg2, 4);
    }
}

extern s32 technique_effect_bml;
extern s32 lbl_805D63B0;

void weapon_special_lightning_bolt_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp20[0x18];
    Vec_8035862C v;
    u32 obj;
    if (arg3 == 0) {
        ((VObj_8035862C *)arg0)->m63(0x30, &sp20);
        spawn_particle_effect((s32 *)&sp20, 0xBE);
    }
    if (arg3 == 1) {
        VecCopy((Vec *)&v, (const Vec *)arg2);
        v.y += 100.0f;
        {
            Vec_8035862C t = lbl_804793D8;
            obj = __nw__7TObjectFUl(0x260);
            if (obj != 0U) {
                ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&v, (u8 *)&t, 0x14000000, 0x14, 100.0f, 1.8f);
            }
        }
    }
}

void TObjPlayer::spawn_effect_by_type(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    s32 temp_a;

    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xBD);
    }
    if (arg3 == 1) {
        temp_a = (s32)create_timed_particle_emitter((void *)arg2, 0xBF, 0, 0xF);
        if (temp_a != 0) {
            attach_particle_model((u8 *)temp_a, get_bml_model(technique_effect_bml, 0), lbl_805D63B0, get_bml_motion(technique_effect_bml, 0), 0, 1.0f);
        }
    }
}

void TObjPlayer::spawn_hit_effect(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    s32 timed_particle_emitter;

    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0xBD);
    }
    if (arg3 == 1) {
        timed_particle_emitter = (s32)create_timed_particle_emitter((void *)arg2, 0x9A, 0, 0xF);
        if (timed_particle_emitter != 0) {
            attach_particle_model((u8 *)timed_particle_emitter, get_bml_model(technique_effect_bml, 0), lbl_805D63B0, get_bml_motion(technique_effect_bml, 0), 0, 1.0f);
        }
    }
}

void prepare_freeze_special_effect(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp8[0x18];

    if (arg3 == 0) {
        struct VObj_80358824_80357734 *o = (struct VObj_80358824_80357734 *)arg0;
        o->m63(0x30, &sp8);
        spawn_particle_effect((s32 *)((s32 *) &sp8), 0x6A);
    }
}

void weapon_fire_explosion_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 obj;
    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0x69);
    }
    if (arg3 == 1) {
        obj = __nw__7TObjectFUl(0x64);
        if (obj != 0U) {
            obj = ((u32 (*)(f32, u32, s32, s32, s32))create_fire_explosion_effect)(10.0f, obj, arg2, 0, tl_particle);
        }
        if (obj != 0U) {
            *(f32 *)((s8 *)obj + 0x34) = 0.6f;
            *(f32 *)((s8 *)obj + 0x38) = 0.6f;
            *(f32 *)((s8 *)obj + 0x3C) = 0.6f;
            *(f32 *)((s8 *)obj + 0x40) = 0.8f;
        }
    }
}

void TObjPlayer::spawn_mirror_pair(void *arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    u32 obj;
    if (arg3 == 0) {
        spawn_particle_effect((s32 *)(arg0 + 0x2FC), 0x69);
    }
    if (arg3 == 1) {
        obj = __nw__7TObjectFUl(0x50);
        if (obj != 0U) {
            create_inward_orbit_effect((u8 *)obj, (s32)tl_05, (u8 *)arg2, (s32)(*(s32 *)((s8 *)arg1 + 0x60)));
        }
        obj = __nw__7TObjectFUl(0x50);
        if (obj != 0U) {
            create_inward_orbit_effect((u8 *)obj, (s32)tl_05, (u8 *)arg2, (s32)(*(s32 *)((s8 *)arg1 + 0x60) - 0x8000));
        }
    }
}

void TObjPlayer::handle_hit_effect(s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8;

    if (arg3 == 0) {
        this->get_anim_node_position(0x30, (Vec *)&sp8);
        spawn_particle_effect(&sp8, 0x68);
    }
    if (arg3 == 1) {
        create_timed_particle_emitter_with_flags((void *)arg2, 0x18, 0, 5, 0x40);
    }
}
void dispatch_weapon_special_effect(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 (*temp_r12)(s32, u32, s32, s32);
    s32 temp_r3;
    u8 temp_r3_2;
    if (((arg0 != 0) || (arg1 != 0U)) && ((s32) get_entity_id((void *)arg0) < 0xC) && (is_current_area_item_enabled() != 0) && (temp_r3 = get_item_field_6__10TObjPlayerFPv((void *)arg0), ((temp_r3 == 0) == 0)) && (get_item_type__5TItemFv() == 0)) {
        if (((TItemWeapon *)temp_r3)->test_weapon_flags(0x400020) != 0U) {
            TObjPlayer::update_battle_control_on_unlock((void *)arg0, (void *)arg1, (void *)arg2, (s32)arg3);
            return;
        }
        temp_r3_2 = ((TItemWeapon *)temp_r3)->get_special_selector();
        if (temp_r3_2 < 0x29U) {
            temp_r12 = *(s32 (**)(s32, u32, s32, s32))((s8 *)((u8 *)&weapon_special_effect_callbacks.value + ((temp_r3_2 * 4) & 0x3FC)) + 0);
            if (temp_r12 != NULL) {
                temp_r12(arg0, arg1, arg2, arg3);
            }
        }
    }
}
