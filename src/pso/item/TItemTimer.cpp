#include "pso/TItemTimer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/item/TUnk_804A0668.h"
#include "pso/player/TUnk_804A0648.h"
#include "pso/player/TUnk_804A0628.h"
#include "pso/item/TUnk_804A0608.h"
#include "pso/item/TUnk_804A05E8.h"
#include "pso/item/TUnk_804A05C8.h"
#include "pso/item/TUnk_804A05A8.h"
#include "pso/item/TUnk_804A0588.h"
#include "pso/item/TUnk_804A0568.h"

extern "C" {
void queue_destruction__7TObjectFv(void*);
}

void TItemTimer::run_task() {
    m_1C--;
    if (((TObject *)m_20)->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction__7TObjectFv(this);
    } else if (m_1C == 0) {
        ((TItemTimer *)(&m_20))->invoke_callback();
        queue_destruction__7TObjectFv(this);
    }
}

TItemTimer::~TItemTimer() {}

#include "types.h"
#include "pso/TObject.h"
#include "pso/boss/TBoss3Volopt.h"

struct VBase18_8011d87c_8011D414 { char pad[0x18]; };
struct VObj18_8011d87c_8011D414 : VBase18_8011d87c_8011D414 {
    virtual void vpad0();
    virtual void vpad1();
    virtual void vpad2();
    virtual void vpad3();
    virtual void vpad4();
    virtual void vpad5();
    virtual void vpad6();
    virtual void vpad7();
    virtual void vpad8();
    virtual void vpad9();
    virtual void vpad10();
    virtual void vpad11();
    virtual void vpad12();
    virtual void vpad13();
    virtual void vpad14();
    virtual void vpad15();
    virtual void vpad16();
    virtual void vpad17();
    virtual void vpad18();
    virtual void vpad19();
    virtual void vpad20();
    virtual void vpad21();
    virtual void vpad22();
    virtual void vpad23();
    virtual void vpad24();
    virtual void vpad25();
    virtual void vpad26();
    virtual void vpad27();
    virtual void vpad28();
    virtual void vpad29();
    virtual void vpad30();
    virtual s32 vf84();
    virtual void vpad32();
    virtual void vpad33();
    virtual void vpad34();
    virtual void vpad35();
    virtual void vpad36();
    virtual void vpad37();
    virtual void vpad38();
    virtual void vpad39();
    virtual void vpad40();
    virtual void vpad41();
    virtual void vpad42();
    virtual void vpad43();
    virtual void vpad44();
    virtual void vpad45();
    virtual void vfC0(int);
    virtual void vpad47();
    virtual void vpad48();
    virtual void vpad49();
    virtual void vpad50();
    virtual void vpad51();
    virtual void vpad52();
    virtual void vpad53();
    virtual void vpad54();
    virtual void vpad55();
    virtual void vpad56();
    virtual void vpad57();
    virtual void vpad58();
    virtual void vpad59();
    virtual void vpad60();
    virtual void vpad61();
    virtual void vpad62();
    virtual void vpad63();
    virtual void vpad64();
    virtual void vpad65();
    virtual void vpad66();
    virtual void vpad67();
    virtual void vpad68();
    virtual void vpad69();
    virtual void vpad70();
    virtual void vpad71();
    virtual void vf128(int);
};
struct Base_8011D94C_8011D414 { char pad[0x18]; };
struct VObj_8011D94C_8011D414 : Base_8011D94C_8011D414 {
    virtual void m0();   virtual void m1();   virtual void m2();   virtual void m3();
    virtual void m4();   virtual void m5();   virtual void m6();   virtual void m7();
    virtual void m8();   virtual void m9();   virtual void m10();  virtual void m11();
    virtual void m12();  virtual void m13();  virtual void m14();  virtual void m15();
    virtual void m16();  virtual void m17();  virtual void m18();  virtual void m19();
    virtual void m20();  virtual void m21();  virtual void m22();  virtual void m23();
    virtual void m24();  virtual void m25();  virtual void m26();  virtual void m27();
    virtual void m28();  virtual void m29();  virtual void m30();  virtual void m31();
    virtual void m32();  virtual void m33();  virtual void m34();  virtual void m35();
    virtual void m36();  virtual void m37();  virtual void m38();  virtual void m39();
    virtual void m40();  virtual void m41();  virtual void m42();  virtual void m43();
    virtual void m44();  virtual void m45();  virtual void m46();  virtual void m47();
    virtual void m48();  virtual void m49();  virtual void m50();  virtual void m51();
    virtual void m52();  virtual void m53();  virtual void m54();  virtual void m55();
    virtual void m56();  virtual void m57();  virtual void m58();  virtual void m59();
    virtual void m60();  virtual void m61();  virtual void m62();  virtual void m63();
    virtual void m64();  virtual void m65();  virtual void m66();  virtual void m67();
    virtual void m68();  virtual void m69();  virtual void m70();  virtual void m71();
    virtual void m72();  virtual void m73(f32);
};

struct VBase_8011D5B4 { char pad[0x18]; };
struct VObj_8011D5B4 : VBase_8011D5B4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void m21(void *, void *, s32, s32, s32);
};
struct Rec_8011D5B4 { s32 k1; s32 v1; s32 k2; f32 v2; };
struct Timer_8011D5B4 { u8 pad[0x28]; VObj_8011D5B4 *obj; f32 f2c; };

extern "C" {
void TItemTimer__sub_8011D598(u8 *arg0, s32 arg1, s32 arg2);
u8 *TItemTimer__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 add_actor_hp(u8 *arg0, s16 arg1);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
s32 add_actor_tp(u8 *arg0, s32 arg1);
s32 set_owner_id__13TParticleCtrlFUs(s32, s32);
s32 is_item_area_enabled();
s32 __ct__7TObjectFP7TObject();
void disallow_rendering__7TObjectFv(TObject *arg0);
s32 is_flag_20000_set__10TObjPlayerFv(s32);
s32 get_entity_id(s32);
s32 obj_isState2_324__13TUnk_804806E8Fv(void *);
s32 obj_isState3_324__13TUnk_804806E8Fv(s32);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);
s32 rand();
s32 test_flag_2000000__10TObjPlayerFPv(s32);

extern s32 __vt__10TItemTimer[];
extern s32 lbl_805D2C88;

u8 *TItemTimer__ct(u8 *item_timer, s32 arg1, s32 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)item_timer + 0x18) = __vt__10TItemTimer;
    ((TItemTimer *)(item_timer + 0x20))->reset_fields();
    *(s32 *)((s8 *)item_timer + 0) = (s32) lbl_805D2C88;
    ((TItemTimer *)item_timer)->m_1C = (arg3 - 1);
    if ((s32) ((TItemTimer *)item_timer)->m_1C < 1) {
        ((TItemTimer *)item_timer)->m_1C = 1;
    }
    TItemTimer__sub_8011D598(item_timer + 0x20, arg1, arg2);
    disallow_rendering__7TObjectFv((TObject *)(item_timer));
    return item_timer;
}

void TItemTimer::invoke_callback() {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)this + 4);
    if (temp_r12 != NULL) {
        temp_r12(*(s32 *)&this->m_name);
    }
}

void TItemTimer__sub_8011D598(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0) = arg1;
    *(s32 *)((s8 *)arg0 + 4) = arg2;
}

void TItemTimer::reset_fields() { *(s32 *)&this->m_name = 0; *(s32 *)&this->m_flags = 0; }

extern const f32 lbl_805DAC78;
extern const f32 lbl_805DAC7C;
void TUnk_804A0568::vfunc_6() {
    Timer_8011D5B4 *arg0 = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
    ((TBoss3Volopt *)(arg0->obj))->get_field_3e0();
    if (is_item_area_enabled() == 1 && lbl_805DAC78 * (f32)rand() < arg0->f2c) {
        a.k1 = 0x10;
        a.v2 = lbl_805DAC7C;
        a.k2 = 0x10;
        a.v1 = *(s32 *)&a.v2;
        arg0->obj->m21(arg0->obj, &a, 0, -1, -1);
    }
}

void TUnk_804A0588::vfunc_6() {
    Timer_8011D5B4 *arg0 = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
    ((TBoss3Volopt *)(arg0->obj))->get_field_3e0();
    if (is_item_area_enabled() == 1 && lbl_805DAC78 * (f32)rand() < arg0->f2c) {
        a.k1 = 0x12;
        a.v2 = lbl_805DAC7C;
        a.k2 = 0x12;
        a.v1 = *(s32 *)&a.v2;
        arg0->obj->m21(arg0->obj, &a, 0, -1, -1);
    }
}

void TUnk_804A05A8::vfunc_6() {
    Timer_8011D5B4 *arg0 = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
    ((TBoss3Volopt *)(arg0->obj))->get_field_3e0();
    if (is_item_area_enabled() == 1 && lbl_805DAC78 * (f32)rand() < arg0->f2c) {
        a.k1 = 0x11;
        a.v2 = lbl_805DAC7C;
        a.k2 = 0x11;
        a.v1 = *(s32 *)&a.v2;
        arg0->obj->m21(arg0->obj, &a, 0, -1, -1);
    }
}

void TUnk_804A05C8::vfunc_6() {
    s32 particle_effect_with_flags;

    if ((test_flag_2000000__10TObjPlayerFPv(this->m_28) == 0) && (is_flag_20000_set__10TObjPlayerFv(this->m_28) == 0)) {
        ((TBoss3Volopt *)(this->m_28))->get_field_3e0();
        if ((is_item_area_enabled() == 1) && (obj_testFlags30__13TUnk_804AF8A0FUl((void *)this->m_28, 0x800) == 0)) {
            particle_effect_with_flags = (s32)spawn_particle_effect_with_flags((void *)(*(s32 *)&this->m_28 + 0x2FC), *(s32 *)&this->unk_2C, 0x10);
            if (particle_effect_with_flags != 0) {
                set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, get_entity_id(this->m_28));
            }
        }
    }
}

void TUnk_804A05E8::vfunc_6() {

    if (obj_isState2_324__13TUnk_804806E8Fv(*(void * *)&this->m_28) == 0) {
        if (((VObj18_8011d87c_8011D414 *) this->m_28)->vf84() == 0) {
            ((TBoss3Volopt *)(this->m_28))->get_field_3e0();
            if ((is_item_area_enabled() == 1) && ((lbl_805DAC78 * (f32) rand()) < *(f32 *)&this->unk_2C)) {
                ((VObj18_8011d87c_8011D414 *) this->m_28)->vfC0(0);
                ((VObj18_8011d87c_8011D414 *) this->m_28)->vf128(0);
            }
        }
    }
}

extern f32 lbl_805DAC80;

void TUnk_804A0608::vfunc_6() {
    struct VObj_8011D94C_8011D414 *o;

    if (obj_testFlags30__13TUnk_804AF8A0FUl((void *)this->m_28, 0x800) == 0) {
        o = (struct VObj_8011D94C_8011D414 *)this->m_28;
        o->m73(lbl_805DAC80);
    }
}

void TUnk_804A0628::vfunc_6() {
    if (obj_testFlags30__13TUnk_804AF8A0FUl((void *)this->m_28, 0x800) == 0) {
        add_actor_tp((u8 *)this->m_28, 1);
    }
}

void TUnk_804A0648::vfunc_6() {
    if (obj_testFlags30__13TUnk_804AF8A0FUl((void *)this->m_28, 0x800) == 0) {
        add_actor_hp((u8 *)this->m_28, 1);
    }
}

void TUnk_804A0668::vfunc_6() {
    ((TBoss3Volopt *)(this->m_28))->get_field_3e0();
    if ((is_item_area_enabled() == 1) && (obj_isState3_324__13TUnk_804806E8Fv(this->m_28) == 0) && (obj_testFlags30__13TUnk_804AF8A0FUl((void *)this->m_28, 0x800) == 0)) {
        ((TUnk_804806E8 *)(this->m_28))->subtract_actor_tp(1);
    }
}

}
