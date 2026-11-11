#include "types.h"
#include "pso/enemy/gee/TObjEneMe1Gee_NEEDLE.h"
#include "pso/enemy/TNeedleShoot_802A4754.h"
#include "pso/enemy/gee/TObjEneMe1Gee_NEEDLE_802A4A44.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/enemy/TNeedleShoot.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/gee/TObjEneMe1Gee_NEEDLE_802A4BB8.h"
#include "pso/enemy/TNeedleShoot_802A4668.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801542CC.h"

struct VBase_18_174c10 { char pad[0x18]; };

struct VObj_18_174c10 : VBase_18_174c10 {
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
    virtual s32 m21(s32, void *, s32, s32, s32);
};

struct Pair_802A4AEC { s32 a; f32 b; };

extern "C" {

void*TNeedleShoot::get_shoot_data() { return (char*)this + 0x28; }


extern "C" {

int TObjEneMe1Gee_NEEDLE::queue_destruction() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = this->m_c0 - 1;
    this->m_c0 = temp_r0;
    if (temp_r0 <= 0) {
        queue_destruction__7TObjectFv(arg0);
    }
}

int TObjEneMe1Gee_NEEDLE::vfunc_6() {
    if (get_current_floor_area() == AREA_SEASIDE_NIGHT) {
        play_sound_effect(0x4003B20E, (u8 *)&this->m_6c, 0, 0);
    } else {
        play_sound_effect(0x3A847, (u8 *)&this->m_6c, 0, 0);
    }
    this->m_b8 = 0;
}

}


void TObjEneMe1Gee_NEEDLE::vfunc_9(void *arg1_arg) {
    u8 *arg0 = (u8 *)this;
    VObj_18_174c10 *arg1 = (VObj_18_174c10 *)arg1_arg;
    Pair_802A4AEC t;
    t.a = 0;
    t.b = *(f32 *)(arg0 + 0xBC);
    Pair_802A4AEC u = t;
    arg1->m21(*(s32 *)(arg0 + 0x1C), &u, *(s32 *)(arg0 + 0x38), -1, -1);
    queue_destruction__7TObjectFv((arg0));
}

}
TObjEneMe1Gee_NEEDLE::~TObjEneMe1Gee_NEEDLE() {

}

#pragma readonly_strings on

extern "C" {
const char *TObjEneMe1Gee_NEEDLE__name = "TObjEneMe1Gee_NEEDLE";
u32 me1gee_cached_model_handle;
}


struct RecoveredGlobal_802A4CC4_lbl_804DCFF8 {
    s32 value;
    u8 remaining[0x24];
};

extern "C" {
s32 TObjPlayer__sub_802A445C(void *, s32);
s32 update_lifetime__22TObjEneMe1GiGueMissileFv(void *);
u16 get_entity_id(void *);
u8 * TNeedleShoot__ct(void *, s32, void *, void *);
extern RecoveredGlobal_802A4CC4_lbl_804DCFF8 __vt__20TObjEneMe1Gee_NEEDLE;
extern const char *TObjEneMe1Gee_NEEDLE__name;
int TObjEneMe1Gee__sub_800CC2BC(void);
extern u32 me1gee_cached_model_handle;
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 rotate_matrix_x(int, int);
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 set_global_param__8TObjFishFl();
s32 rotate_matrix_y(int, int);
s32 push_matrix();

void TObjEneMe1Gee_NEEDLE::render() {
    u8 *arg0 = (u8 *)this;
    if ((u32) me1gee_cached_model_handle == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    push_matrix();
    TParticleCtrl::begin_effect_render();
    post_translate_matrix((u8 *)&this->m_6c);
    rotate_matrix_y(0, this->m_a4);
    rotate_matrix_x(0, this->m_a0);
    TObjFish__sub_8001EDB0((void *)me1gee_cached_model_handle, 1);
    set_global_param__8TObjFishFl();
    get_bml_model((void *)me1gee_cached_model_handle, 1);
    draw_ginja_object();
    TParticleCtrl::end_effect_render();
    pop_matrix();
}
void TObjEneMe1Gee_NEEDLE::run_task() {
    this->m_1c = (u32)find_entity_by_id(this->m_34);
    if ((u32) this->m_1c == 0U) {
        queue_destruction__7TObjectFv((this));
        return;
    }
    if ((s32) this->m_b8 == 1) {
        update_position();
        update_lifetime__22TObjEneMe1GiGueMissileFv(this);
        TObjPlayer__sub_802A445C(this, 1);
        return;
    }
    TNeedleShoot__sub_802A4668(this);
}
u8 *TObjEneMe1Gee_NEEDLE__ct(TObjEneMe1Gee_NEEDLE *arg0, s32 arg1, u8 *from, u8 *to, f32 farg0, f32 farg1) {
    u8 *temp_r3;
    TNeedleShoot__ct(arg0, arg1, from, to);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__20TObjEneMe1Gee_NEEDLE.value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) ((s32)TObjEneMe1Gee_NEEDLE__name);
    *(f32 *)((s8 *)arg0 + 0xBC) = farg1;
    *(f32 *)((s8 *)arg0 + 0xAC) = farg0;
    arg0->m_c0 = 0x96;
    arg0->m_b0 = 1;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x1C));
    if (temp_r3 != NULL) {
        arg0->m_34 = get_entity_id(temp_r3);
    }
    return (u8 *)arg0;
}
void TObjEneMe1Gee__sub_802A4D4C(void) {  }
void TObjEneMe1Gee::cache_result_805D6660() { (*(int *)&me1gee_cached_model_handle) = TObjEneMe1Gee__sub_800CC2BC(); }

typedef char RecoveredGlobal_802A4CC4_lbl_804DCFF8_size[sizeof(RecoveredGlobal_802A4CC4_lbl_804DCFF8) == 0x28 ? 1 : -1];

}
