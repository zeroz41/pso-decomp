#include "types.h"
#include "pso/enemy/TObjEneMorfosArm.h"
#include "pso/enemy/TObjEneMorfosArm_80335218.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"

#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"


#pragma readonly_strings on

extern "C" {
const char *TObjEneMorfosArm__name = "TObjEneMorfosArm";
TObjMotionAction morfos_arm_motion_params[1] = {
    { MOTION_MODE_ONCE, 0, 0, 0.7f, 0x4 },
};
}




extern "C" {
void *TObjEneMorfosArm__sub_803326B4(void *p);
s32 TObjEneMorfosArm__sub_803326BC(void *);
u16 get_entity_id(void *);
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

TObjEneMorfosArm::TObjEneMorfosArm(TObject *parent, void *owner) : TObjMotion(parent) {
    u8 *resource;
    m_name = TObjEneMorfosArm__name;
    m_fc = (u32)owner;
    m_100 = get_entity_id((void *)m_fc);
    VecCopy(&position, (const Vec *)TObjEneMorfosArm__sub_803326B4((void *)m_fc));
    rotation_y = TObjEneMorfosArm__sub_803326BC((void *)m_fc);
    model = *(void **)(*(u8 **)(TObjEneMorfosArm__parent_morfos_instance + 0x42C) + 8);
    resource = *(u8 **)(TObjEneMorfosArm__parent_morfos_instance + 0x42C);
    texlist = *(s32 *)(resource + 0xC);
    set_field_d8((s32)morfos_arm_motion_params);
    set_field_dc(*(s32 *)(TObjEneMorfosArm__parent_morfos_instance + 0x430));
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
}

