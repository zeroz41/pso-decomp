#include "types.h"
#include "pso/enemy/TObjEneMe1GiGueBarrier.h"
#include "pso/misc/obj_band.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80143818.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/object/TObjMotion.h"

#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80325BCC_lbl_804ECD40 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80325BCC_lbl_804ECD40_size[sizeof(RecoveredGlobal_80325BCC_lbl_804ECD40) == 0x30 ? 1 : -1];

struct RecoveredGlobal_80325BCC___vt__22TObjEneMe1GiGueBarrier { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80325BCC___vt__22TObjEneMe1GiGueBarrier_size[sizeof(RecoveredGlobal_80325BCC___vt__22TObjEneMe1GiGueBarrier) == 0x38 ? 1 : -1];

struct VBase_18_ca64a0 { char pad[0x18]; };

struct VObj_18_ca64a0 : VBase_18_ca64a0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

extern "C" {
void *__nw__7TObjectFUl(int);
s32 advance_animation_playback(void *);
s32 play_sound_effect(int, void *, int, int);
s32 is_active_state__22TObjEneMe1GiGueBarrierFv(int);
u16 get_entity_id(void *);
s32 set_field_d8__10TObjMotionFl(void *, void *, int);
void TObjEneMe1GiGueBarrier__sub_802CABF4(void *p);
extern RecoveredGlobal_80325BCC_lbl_804ECD40 TObjEneMe1GiGueBarrier__animation_definitions;
extern s32 __vt__22TObjEneMe1GiGueBarrier[];
extern s32 lbl_805D4198;
extern s32 TObjEneMe1GiGueBarrier__barrier_resource_object;
u8 *TObjEneMe1GiGueBarrier__ct(TObjEneMe1GiGueBarrier *arg0, s32 arg1, u8 *arg2);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern const f32 lbl_805DF620;
extern const f32 lbl_805DF624;
extern const f32 lbl_805DF628;
extern const f32 lbl_805DF62C;
void TObjEneMe1GiGueBarrier__sub_80325CC0(void);

#pragma push
#pragma opt_common_subs off
void TObjEneMe1GiGueBarrier::render() {
    u8 *arg0 = (u8 *)this;
    if ((u32) (*(u32 *)&TObjEneMe1GiGueBarrier__barrier_resource_object) == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if (TOKeyMachine01::get_global_state() == 0x23) {
        if (((VObj_18_ca64a0 *)(arg0))->m9(lbl_805DF620, lbl_805DF620, lbl_805DF624) == 0) {
            return;
        }
        goto block_6;
    }
    if (((VObj_18_ca64a0 *)(arg0))->m9(lbl_805DF628, lbl_805DF62C, lbl_805DF624) != 0) {
block_6:
        if (defer_render__7TObjectFv(arg0) == 0) {
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texture_id);
            TParticleCtrl::end_effect_render();
            ((TObjMotion *)arg0)->draw();
            pop_matrix();
        }
    }
}
#pragma pop

void TObjEneMe1GiGueBarrier::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r0;
    temp_r0 = this->m_fc;
    if (temp_r0 == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(((TObjEneMe1GiGueBarrier *)temp_r0)->update_and_get_pos()));
    this->rotation_y = ((TObjEneMe1GiGueBarrier *)(this->m_fc))->get_timer();
    advance_animation_playback(arg0);
    this->m_108 = (this->m_108 - 1);
    switch (this->m_104) {
    case 0:
        if (this->animationFlags & 0x10) {
            this->m_104 = 1;
            this->m_b8 = 1;
            if (TOKeyMachine01::get_global_state() == 0x23) {
                play_sound_effect(0x4003A316, (u8 *)&this->position, 0, 0);
            } else {
                play_sound_effect(0x3A346, (u8 *)&this->position, 0, 0);
            }
        }
        break;
    case 2:
        if (this->animationFlags & 0x10) {
            queue_destruction__7TObjectFv((arg0));
        }
        break;
    default:
    case 1:
        if (((s32) this->m_108 <= 0) || (is_active_state__22TObjEneMe1GiGueBarrierFv(this->m_fc) != 0)) {
            this->m_104 = 2;
            this->m_b8 = 2;
        }
        break;
    }
}

}
TObjEneMe1GiGueBarrier::~TObjEneMe1GiGueBarrier() {
    if (*(void **)((s8 *)this + 0xFC) != NULL) { ((TObjEneMe1GiGueBarrier *)(*(void **)((s8 *)this + 0xFC)))->clear_flag388_bit80000(); }
}


u8 *TObjEneMe1GiGueBarrier__ct(TObjEneMe1GiGueBarrier *ene_me1_gi_gue_barrier, s32 arg1, u8 *arg2) {
    u8 *temp_r5;
    TObjMotion__ct((u8 *)ene_me1_gi_gue_barrier);
    *(s32 **)((s8 *)ene_me1_gi_gue_barrier + 0x18) = &(*(RecoveredGlobal_80325BCC___vt__22TObjEneMe1GiGueBarrier *)&__vt__22TObjEneMe1GiGueBarrier).value;
    *(s32 *)((s8 *)ene_me1_gi_gue_barrier + 0) = (s32) lbl_805D4198;
    *(u8 **)((s8 *)ene_me1_gi_gue_barrier + 0xFC) = arg2;
    ene_me1_gi_gue_barrier->m_100 = get_entity_id(*(u8 **)((s8 *)ene_me1_gi_gue_barrier + 0xFC));
    VecCopy((Vec *)((u8 *)ene_me1_gi_gue_barrier + 0x38), (const Vec *)((void *) (((TObjEneMe1GiGueBarrier *)((s32) *(u8 **)((s8 *)ene_me1_gi_gue_barrier + 0xFC)))->update_and_get_pos())));
    ene_me1_gi_gue_barrier->rotation_y = ((TObjEneMe1GiGueBarrier *)(*(u8 **)((s8 *)ene_me1_gi_gue_barrier + 0xFC)))->get_timer();
    ene_me1_gi_gue_barrier->m_108 = ((TObjEneMe1GiGueBarrier *)(*(u8 **)((s8 *)ene_me1_gi_gue_barrier + 0xFC)))->get_field_44c();
    TObjEneMe1GiGueBarrier__sub_802CABF4((*(u8 **)((s8 *)ene_me1_gi_gue_barrier + 0xFC)));
    ene_me1_gi_gue_barrier->m_104 = 0;
    *(s32 *)((s8 *)ene_me1_gi_gue_barrier + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjEneMe1GiGueBarrier__barrier_resource_object) + 0x42C)) + 0x28);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjEneMe1GiGueBarrier__barrier_resource_object) + 0x42C));
    ene_me1_gi_gue_barrier->texture_id = (s32) *(s32 *)((s8 *)temp_r5 + 0x2C);
    set_field_d8__10TObjMotionFl((void *)ene_me1_gi_gue_barrier, &TObjEneMe1GiGueBarrier__animation_definitions.value, (int)temp_r5);
    ((TObjMotion *)ene_me1_gi_gue_barrier)->set_field_dc((int) (*(s32 *)((s8 *)(*(u8 * *)&TObjEneMe1GiGueBarrier__barrier_resource_object) + 0x430)));
    ene_me1_gi_gue_barrier->m_b8 = 0;
    ((TObjMotion *)ene_me1_gi_gue_barrier)->set_animation((ene_me1_gi_gue_barrier->m_b8));
    ((TObjMotion *)ene_me1_gi_gue_barrier)->set_field_b8(ene_me1_gi_gue_barrier->m_b8);
    return (u8 *)ene_me1_gi_gue_barrier;
}

void TObjEneMe1GiGueBarrier__sub_80325CC0(void) {  }

void *TObjEneMe1GiGueBarrier::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x10C);
    if (o != NULL) {
        o = TObjEneMe1GiGueBarrier__ct((TObjEneMe1GiGueBarrier *)((u8 *)o), (s32)((s32)arg0), (u8 *)((u8 *)arg1));
    }
    return o;
}

void TObjEneMe1GiGueBarrier::init_global() {
    TObjEneMe1GiGueBarrier__barrier_resource_object = TObjEneMe1GiGue::get_barrier_count();
}

