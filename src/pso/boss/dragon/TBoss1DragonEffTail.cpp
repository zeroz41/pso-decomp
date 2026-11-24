#include "types.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/dragon/TBoss1DragonEffTail.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/unk/text_803D853C.h"

#pragma readonly_strings on

extern "C" {
const char *TBoss1DragonEffTail__name = "TBoss1DragonEffTail";
CollisionBody TBoss1DragonEffTail__collision_body_templates[17] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003 },
};

void TBoss1DragonEffTail::render() {  }

void TBoss1DragonEffTail::run_task() {
    CollisionBody *body;
    Vec *node;
    s32 i;
    VecCopy(&this->position, &this->nodes[3]);
    vec3_add_to(&this->position, &this->nodes[10]);
    this->position.x *= 0.5f;
    this->position.z *= 0.5f;
    this->position.y = this->dragon->position.y;
    this->rotation_y = this->dragon->rotation_y;
    node = this->nodes;
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(0, -this->rotation_y);
    translate_matrix(0, -this->position.x, -this->position.y, -this->position.z);
    for (i = 0; i < 0x11; i++) {
        body = &this->bodies[i];
        VecCopy(&body->center, node);
        matrix_mult_vec(NULL, node++, &body->offset);
        update_collider_contact_by_height(body, 30.0f);
    }
    pop_matrix();
    if (this->sweep_side == 1) {
        this->sweep_vector.x = 5.0f * cos_table_lookup(this->rotation_y);
        this->sweep_vector.y = 0.0f;
        this->sweep_vector.z = 5.0f * -sin_table_lookup(this->rotation_y);
    } else {
        this->sweep_vector.x = 5.0f * -cos_table_lookup(this->rotation_y);
        this->sweep_vector.y = 0.0f;
        this->sweep_vector.z = 5.0f * sin_table_lookup(this->rotation_y);
    }
    {
        TailAttackParams params = { 3.0f, 1 };
        this->dragon->reset_tail_hp();
        call_vt16_with_default(&params, this->attack_history);
    }
    this->dragon->reload_difficulty_stats();
}

// Pushes the hit object along this tail's sweep vector (its velocity, which the base
// TUnk_804928CC::area_attack_apply_recoil also moves).
void TBoss1DragonEffTail::area_attack_apply_recoil(void *target, f32) {
    vec3_add_to(&((TObjChara *)target)->velocity, &sweep_vector);
}

void TBoss1DragonEffTail::apply_hit_if_active(void *target, f32 *) {
    ((TObjChara *)target)->receive_physical_attack((void *)this->owner, 1.0f);
    if (TObjEneDD::check_v2_mode() != 0) {
        apply_dragon_hit_ailment((TObjChara *)target);
    }
}

void TBoss1DragonEffTail::enable() { this->sweep_side = 1; clear_attack_history(); }
void TBoss1DragonEffTail::disable() { this->sweep_side = 0; clear_attack_history(); }
void TBoss1DragonEffTail::clear_attack_history() { fill_value_array(attack_history); }

TBoss1DragonEffTail::~TBoss1DragonEffTail() {
    delete attack_history;
    attack_history = NULL;
}
TBoss1DragonEffTail::TBoss1DragonEffTail(TBoss1Dragon *dragon, Vec *nodes)
    : TUnk_804928CC(NULL, dragon, TBoss1DragonEffTail__collision_body_templates, 0x11) {
    void *data;
    s32 i;
    data = TBoss1DragonEffTail__collision_body_templates;
    m_name = TBoss1DragonEffTail__name;
    for (i = 1; i < 0x11; i++) {
        copy_collision_body(&bodies[i], (const CollisionBody *)data);
    }
    this->dragon = dragon;
    this->nodes = nodes;
    attack_history = new AreaAttackHistory(4);
    sweep_side = 0;
    sweep_vector.x = 0.0f;
    sweep_vector.y = 0.0f;
    sweep_vector.z = 0.0f;
}

}
