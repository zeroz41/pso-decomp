#include "types.h"
#include "pso/enemy/TObjEneMorfosArm.h"
#include "pso/enemy/TObjEneMorfosArm_80335218.h"
#include "pso/misc/obj_band.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"

#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

// The hand-written constructors below call the base one by its symbol.
extern "C" u8 *__ct__10TObjMotionFP7TObject(u8 *self);

#pragma readonly_strings on

extern "C" {
const char *TObjEneMorfosArm__name = "TObjEneMorfosArm";
}


struct RecoveredGlobal_80335354_lbl_804EE3B0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80335354_lbl_804EE3B0_size[sizeof(RecoveredGlobal_80335354_lbl_804EE3B0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80335354___vt__16TObjEneMorfosArm { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80335354___vt__16TObjEneMorfosArm_size[sizeof(RecoveredGlobal_80335354___vt__16TObjEneMorfosArm) == 0x38 ? 1 : -1];

extern "C" {
void *TObjEneMorfosArm__sub_803326B4(void *p);
s32 TObjEneMorfosArm__sub_803326BC(void *);
u16 get_entity_id(void *);
s32 set_field_d8__10TObjMotionFl(void *, void *, int);
extern RecoveredGlobal_80335354_lbl_804EE3B0 morfos_arm_motion_params;
extern s32 __vt__16TObjEneMorfosArm[];
extern const char *TObjEneMorfosArm__name;
extern u32 TObjEneMorfosArm__parent_morfos_instance;
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();

void TObjEneMorfosArm::render() {
    u8 *arg0 = (u8 *)this;
    if ((u32) TObjEneMorfosArm__parent_morfos_instance == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    TObjFish::set_global_param(this->texlist);
    TObjPlayer::toggle_particle_effect();
    ((TObjMotion *)arg0)->draw();
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjEneMorfosArm::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    advance_animation();
    temp_r3 = (u8 *)this->m_fc;
    if (temp_r3 == NULL) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(TObjEneMorfosArm__sub_803326B4(temp_r3)));
    this->rotation_y = TObjEneMorfosArm__sub_803326BC(*(u8 * *)&this->m_fc);
    if (this->motion_flags & 0x10) {
        queue_destruction__7TObjectFv((arg0));
    }
}

}
TObjEneMorfosArm::~TObjEneMorfosArm() {

}

u8 *TObjEneMorfosArm__ct(TObjEneMorfosArm *ene_morfos_arm, s32 arg1, u8 *arg2) {
    u8 *temp_r5;
    __ct__10TObjMotionFP7TObject((u8 *)ene_morfos_arm);
    *(s32 **)((s8 *)ene_morfos_arm + 0x18) = &(*(RecoveredGlobal_80335354___vt__16TObjEneMorfosArm *)&__vt__16TObjEneMorfosArm).value;
    *(s32 *)((s8 *)ene_morfos_arm + 0) = (s32) ((s32)TObjEneMorfosArm__name);
    *(u8 **)((s8 *)ene_morfos_arm + 0xFC) = arg2;
    ene_morfos_arm->m_100 = get_entity_id(*(u8 **)((s8 *)ene_morfos_arm + 0xFC));
    VecCopy((Vec *)((u8 *)ene_morfos_arm + 0x38), (const Vec *)((void *) (((s32)TObjEneMorfosArm__sub_803326B4((void *)((s32) *(u8 **)((s8 *)ene_morfos_arm + 0xFC)))))));
    ene_morfos_arm->rotation_y = TObjEneMorfosArm__sub_803326BC(*(u8 **)((s8 *)ene_morfos_arm + 0xFC));
    *(s32 *)((s8 *)ene_morfos_arm + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjEneMorfosArm__parent_morfos_instance) + 0x42C)) + 8);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjEneMorfosArm__parent_morfos_instance) + 0x42C));
    ene_morfos_arm->texlist = (s32) *(s32 *)((s8 *)temp_r5 + 0xC);
    set_field_d8__10TObjMotionFl((void *)ene_morfos_arm, &morfos_arm_motion_params.value, (int)temp_r5);
    ((TObjMotion *)ene_morfos_arm)->set_field_dc((int) (*(s32 *)((s8 *)(*(u8 * *)&TObjEneMorfosArm__parent_morfos_instance) + 0x430)));
    ene_morfos_arm->requested_action = 0;
    ((TObjMotion *)ene_morfos_arm)->set_animation((ene_morfos_arm->requested_action));
    ((TObjMotion *)ene_morfos_arm)->set_field_b8(ene_morfos_arm->requested_action);
    return (u8 *)ene_morfos_arm;
}

