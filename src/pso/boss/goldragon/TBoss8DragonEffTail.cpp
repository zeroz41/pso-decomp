#include "pso/system/memory.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/boss/dragon/ObjBoss1CommonJResource.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/goldragon/TBoss8DragonEffTail.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/object/base/TObjChara.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/dragon/TBoss1DragonEffTail.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"

const char *TBoss8DragonEffTail__name = "TBoss8DragonEffTail";
// As TBoss1DragonEffTail's: what run_task hands its attack history.
extern const TailAttackParams boss8_dragon_tail_attack_params = { 3.0f, 1 };
// The 17 collision bodies the constructor sets up: the first a radius-10 sphere, the rest copies of it.
CollisionBody boss8_dragon_eff_tail_init_data[17] = { { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003 } };
BmlResource *boss8_eff_tail_bml_resource;
NJS_TEXLIST *dragon_tail_gvm_texture_handle;

void TBoss8DragonEffTail::load_resources() {  }
void TBoss8DragonEffTail::render() {  }

void TBoss8DragonEffTail::run_task() {
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
        TailAttackParams params = boss8_dragon_tail_attack_params;
        this->dragon->reset_tail_hp();
        call_vt16_with_default(&params, this->attack_history);
    }
    this->dragon->reload_boss_stats();
}

void TBoss8DragonEffTail::area_attack_apply_recoil(void *target, f32) {
    vec3_add_to(&((TObjChara *)target)->velocity, &sweep_vector);
}

void TBoss8DragonEffTail::apply_hit_if_active(void *target, f32 *) {
    ((TObjChara *)target)->receive_physical_attack((void *)this->owner, 1.0f);
}

void TBoss8DragonEffTail::enable() { this->sweep_side = 1; clear_attack_history(); }
void TBoss8DragonEffTail::disable() { this->sweep_side = 0; clear_attack_history(); }
void TBoss8DragonEffTail::clear_attack_history() { fill_value_array(attack_history); }

TBoss8DragonEffTail::~TBoss8DragonEffTail() {
    delete attack_history;
    attack_history = NULL;
}

TBoss8DragonEffTail::TBoss8DragonEffTail(TBoss8Dragon *dragon, Vec *nodes)
    : TUnk_804928CC(NULL, dragon, boss8_dragon_eff_tail_init_data, 0x11) {
    void *data;
    s32 i;
    data = boss8_dragon_eff_tail_init_data;
    m_name = TBoss8DragonEffTail__name;
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

void TBoss8DragonEffTail::free_statics() {
    if (dragon_tail_gvm_texture_handle != NULL) {
        release_texture_list(dragon_tail_gvm_texture_handle);
        safe_free(dragon_tail_gvm_texture_handle);
        dragon_tail_gvm_texture_handle = NULL;
    }
    delete boss8_eff_tail_bml_resource;
    boss8_eff_tail_bml_resource = 0;
}

void TBoss8DragonEffTail::load_statics() {
    boss8_eff_tail_bml_resource = load_enemy_bml_resource((BmlResourceDescriptor *)&bm_obj_boss1_common_j_resource_descriptor);
    dragon_tail_gvm_texture_handle = load_gvm_texture_file(obj_boss1_common_j_texture_filename);
}
