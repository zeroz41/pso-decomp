#include "types.h"
#include "pso/enemy/TObjEneMe1GiGueBarrier.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/object/TObjMotion.h"
#include "pso/map/FloorArea.h"

#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"


#pragma readonly_strings on

extern "C" {
const char *lbl_805D4198 = "TObjEneMe1GiGueBarrier";
s32 TObjEneMe1GiGueBarrier__barrier_resource_object;
TObjMotionAction TObjEneMe1GiGueBarrier__animation_definitions[3] = {
    { MOTION_MODE_ONCE, 0, 6, 1.0f, 0x1 },
    { MOTION_MODE_LOOP, 0, 7, 1.0f, 0x0 },
    { MOTION_MODE_ONCE, 0, 8, 1.0f, 0x1 },
};
}




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
s32 play_sound_effect(int, void *, int, int);
s32 is_active_state__22TObjEneMe1GiGueBarrierFv(int);
u16 get_entity_id(void *);
void TObjEneMe1GiGueBarrier__sub_802CABF4(void *p);
extern const char *lbl_805D4198;
extern s32 TObjEneMe1GiGueBarrier__barrier_resource_object;
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
void TObjEneMe1GiGueBarrier__sub_80325CC0(void);

#pragma push
#pragma opt_common_subs off
void TObjEneMe1GiGueBarrier::render() {
    u8 *arg0 = (u8 *)this;
    if ((u32) (*(u32 *)&TObjEneMe1GiGueBarrier__barrier_resource_object) == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if (get_current_floor_area() == AREA_TOWER) {
        if (((VObj_18_ca64a0 *)(arg0))->m9(600.0f, 600.0f, 20.0f) == 0) {
            return;
        }
        goto block_6;
    }
    if (((VObj_18_ca64a0 *)(arg0))->m9(150.0f, 400.0f, 20.0f) != 0) {
block_6:
        if (defer_render__7TObjectFv(arg0) == 0) {
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
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
    ((TObjMotion *)arg0)->advance_animation();
    this->m_108 = (this->m_108 - 1);
    switch (this->m_104) {
    case 0:
        if (this->motion_flags & 0x10) {
            this->m_104 = 1;
            this->requested_action = 1;
            if (get_current_floor_area() == AREA_TOWER) {
                play_sound_effect(0x4003A316, (u8 *)&this->position, 0, 0);
            } else {
                play_sound_effect(0x3A346, (u8 *)&this->position, 0, 0);
            }
        }
        break;
    case 2:
        if (this->motion_flags & 0x10) {
            queue_destruction__7TObjectFv((arg0));
        }
        break;
    default:
    case 1:
        if (((s32) this->m_108 <= 0) || (is_active_state__22TObjEneMe1GiGueBarrierFv(this->m_fc) != 0)) {
            this->m_104 = 2;
            this->requested_action = 2;
        }
        break;
    }
}

}
TObjEneMe1GiGueBarrier::~TObjEneMe1GiGueBarrier() {
    if (*(void **)((s8 *)this + 0xFC) != NULL) { ((TObjEneMe1GiGueBarrier *)(*(void **)((s8 *)this + 0xFC)))->clear_flag388_bit80000(); }
}


TObjEneMe1GiGueBarrier::TObjEneMe1GiGueBarrier(TObject *parent, void *owner) : TObjMotion(parent) {
    u8 *resource;
    m_name = lbl_805D4198;
    m_fc = (u32)owner;
    m_100 = get_entity_id((void *)m_fc);
    VecCopy(&position, (const Vec *)((TObjEneMe1GiGueBarrier *)m_fc)->update_and_get_pos());
    rotation_y = ((TObjEneMe1GiGueBarrier *)m_fc)->get_timer();
    m_108 = ((TObjEneMe1GiGueBarrier *)m_fc)->get_field_44c();
    TObjEneMe1GiGueBarrier__sub_802CABF4((void *)m_fc);
    m_104 = 0;
    model = *(void **)(*(u8 **)(TObjEneMe1GiGueBarrier__barrier_resource_object + 0x42C) + 0x28);
    resource = *(u8 **)(TObjEneMe1GiGueBarrier__barrier_resource_object + 0x42C);
    texlist = *(s32 *)(resource + 0x2C);
    set_field_d8((s32)TObjEneMe1GiGueBarrier__animation_definitions);
    set_field_dc(*(s32 *)(TObjEneMe1GiGueBarrier__barrier_resource_object + 0x430));
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
}

void TObjEneMe1GiGueBarrier__sub_80325CC0(void) {  }

void *TObjEneMe1GiGueBarrier::create(void *arg0, void *arg1) {
    return new TObjEneMe1GiGueBarrier((TObject *)arg0, arg1);
}

void TObjEneMe1GiGueBarrier::init_global() {
    TObjEneMe1GiGueBarrier__barrier_resource_object = TObjEneMe1GiGue::get_barrier_count();
}

