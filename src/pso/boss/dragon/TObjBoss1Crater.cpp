#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/dragon/TObjBoss1Crater.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/system/vector.h"
#include "pso/enemy/AreaAttackContact.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/system/task/TObject.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/dragon/ObjBoss1CommonResource.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_8002C190.h"


BmlResource *dragon_ground_resource;
NJS_TEXLIST *dragon_common_texture_list;
s32 TObjBoss1Crater__instance_count;
void load_dragon_ground_assets(void) {
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        dragon_ground_resource = load_enemy_bml_resource(&dragon_ground_resource_descriptor);
        dragon_common_texture_list = load_gvm_texture_file(dragon_common_texture_filename);
        break;
    case 1:
        dragon_ground_resource = load_enemy_bml_resource_named(&dragon_ground_resource_descriptor, dragon_common_alternate_bml_filename);
        dragon_common_texture_list = load_gvm_texture_file(dragon_common_alternate_texture_filename);
        break;
    }
}

// The crater's hit: kind and power (run_task replaces both), the body radius the ctor gives it, and the
// recoil pair run_task passes to call_vt13_with_default.
struct CraterAttackParams {
    s32 kind;
    f32 power;
    f32 radius;
    AreaAttackContact contact;
};

extern const CraterAttackParams boss1_crater_attack_params = { 1, 50.0f, 20.0f, { 0.0f, 1 } };
const char *TObjBoss1Crater__name = "TObjBoss1Crater";

TObjBoss1Crater *TObjBoss1Crater__instance_list[20];

void TObjBoss1Crater::render() {
    push_matrix();
    TObjFish::set_global_param(dragon_common_texture_list);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    model_render_flags |= 0x01000000;
    draw_chunk_object(dragon_ground_resource->models[0].model);
    model_render_flags &= 0xFEFFFFFF;
    pop_matrix();
}

void TObjBoss1Crater::run_task() {
    s32 n;
    if (owner == 0) {
        return;
    }
    if (((TObject *)owner)->all_parents_unqueued_for_destruction() == 0) {
        owner = 0;
        return;
    }
    {
        CraterAttackParams params = boss1_crater_attack_params;
        params.power = ((TBoss1Dragon *)owner)->get_crater_attack_power();
        params.kind = attack_kind;
        n = attack_target_list_count(attack_history);
        if (call_vt13_with_default(const_cast<AreaAttackContact *>(&boss1_crater_attack_params.contact), &params, (saddr)attack_history) != 0) {
            s32 m = attack_target_list_count(attack_history);
            for (s32 j = n; j < m; j++) {
                hit_timers[j] = 0x3C;
            }
        }
    }
    {
        n = attack_target_list_count(attack_history);
        for (s32 i = 0; i < n; i++) {
            if (hit_timers[i] <= 0) {
                attack_target_list_remove(attack_history, i);
                hit_timers[i] = hit_timers[n - 1];
                hit_timers[n - 1] = 0;
                i--;
                n--;
            } else {
                hit_timers[i]--;
            }
        }
    }
}

void TObjBoss1Crater::area_attack_receive_direct(void *target, f32 *, void *attack) {
    TObjChara *chara = (TObjChara *)target;
    s32 off;
    s32 i;
    CollisionBody *body;
    off = 0;
    for (i = 0; i < chara->body_count; i++) {
        body = (CollisionBody *)((u8 *)chara->bodies + off);
        if (body->flags & 0x04000000) {
            DirectAttackPayload payload = *(DirectAttackPayload *)attack;
            chara->receive_direct_attack((void *)owner, payload, body, -1, -1);
            if (attack_kind == 0x13 && !(chara->actorFlags & 0x20)) {
                apply_dragon_hit_ailment(chara);
            }
            return;
        }
        off += 0x2C;
    }
}

TObjBoss1Crater::~TObjBoss1Crater() {
    if (this->attack_history != NULL) { delete this->attack_history; this->attack_history = 0; }
    if (emitter != NULL) { emitter->queue_destruction(); emitter = NULL; }
}


TObjBoss1Crater::TObjBoss1Crater(TObject *parent, TObjBase *owner, Vec *pos) : TUnk_804928CC(parent, owner) {
    f32 r;
    s32 i;
    r = boss1_crater_attack_params.radius;
    m_name = TObjBoss1Crater__name;
    bodies->radius = r;
    VecCopy(&position, pos);
    rotation_y = (s32)(65536.0f * ((1.0f / 32768.0f) * (f32)rand()));
    emitter = create_particle_emitter(&position, 0x40);
    attack_history = new AreaAttackHistory(4);
    for (i = 0; i < 4; i++) {
        hit_timers[i] = 0;
    }
    if (TObjBoss1Crater__instance_count < 0x14) {
        TObjBoss1Crater__instance_list[TObjBoss1Crater__instance_count++] = this;
    }
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        attack_kind = 1;
        break;
    case 1:
        attack_kind = 0x13;
        break;
    }
}

s32 TObjBoss1Crater::is_count_below_limit() {
    return TObjBoss1Crater__instance_count < 0x14;
}

TObjBoss1Crater *TObjBoss1Crater::create(TObject *parent, Vec *pos) {
    TObjBase *dragon;
    if (is_count_below_limit() == 0) {
        return NULL;
    }
    dragon = (TObjBase *)TBoss1Dragon::get_instance();
    if (dragon == NULL) {
        return NULL;
    }
    return new TObjBoss1Crater(parent, dragon, pos);
}

#pragma push
#pragma fp_contract on
f32 calc_nearest_crater_distance(Vec *position) {
    f32 best;
    s32 i;
    f32 x;
    f32 z;
    f32 d;
    f32 dx;
    f32 dz;
    best = 100000000.0f;
    if (TObjBoss1Crater__instance_count == 0) {
        return 0.0f;
    }
    x = position->x;
    z = position->z;
    for (i = 0; i < TObjBoss1Crater__instance_count; i++) {
        TObjBoss1Crater *crater = TObjBoss1Crater__instance_list[i];
        dx = crater->position.x - x;
        dz = crater->position.z - z;
        d = dx * dx + dz * dz;
        if (d < best) {
            best = d;
        }
    }
    return newton_sqrtf(best);
}
#pragma pop

void TObjBoss1Crater__sub_8002C7B4(void) {  }

void TObjBoss1Crater__sub_8002C7B8(void) {
    s32 i;
    TObjBoss1Crater__instance_count = 0;
    for (i = 0; i < 20; i++) {
        TObjBoss1Crater__instance_list[i] = 0;
    }
}

s32 attack_target_list_count(PointerBuffer *buffer) {
    return buffer->count;
}

void attack_target_list_remove(PointerBuffer *buffer, s32 index) {
    if (index >= 0 && index < buffer->count) {
        buffer->count--;
        buffer->entries[index] = buffer->entries[buffer->count];
        buffer->entries[buffer->count] = buffer->empty;
    }
}
