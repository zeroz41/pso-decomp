#include "types.h"
#include "pso/misc/TOHealGeneral.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/item/TItemProShield.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/network/client_id.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMapWarp_80141C68.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"

// TObjPlayer_80011014.h declares get_entity_id returning u16, but this
// unit's callers saw a 32-bit return (no zero extension before the
// (u16) test), so the helpers are still declared here.
extern "C" {
s32 add_actor_tp(u8 *arg0, s32 arg1);
s32 add_actor_hp(u8 *arg0, s16 arg1);
s16 get_actor_hp(void *object);
s16 get_actor_tp(void *object);
s16 obj_getS16_2BA(u8 *p);
s32 get_entity_id(void *object);
}

const char *bm_fe_obj_kaifuku_moto_model_names[2] = { "fe_obj_kaifuku_moto.nj", NULL };
const char *bm_fe_obj_kaifuku_moto_motion_names[1] = { NULL };
BmlResourceDescriptor bm_fe_obj_kaifuku_moto_resource_descriptor = {
    "bm_fe_obj_kaifuku_moto.bml", bm_fe_obj_kaifuku_moto_model_names, bm_fe_obj_kaifuku_moto_motion_names, 1, 0
};
// The Episode II ring.
const char *fe_obj_kaifuku_moto_2_model_names[2] = { "fe_obj_kaifuku_moto.gj", NULL };
const char *fe_obj_kaifuku_moto_2_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj_kaifuku_moto_2_resource_descriptor = {
    "fe_obj_kaifuku_moto_2.bml", fe_obj_kaifuku_moto_2_model_names, fe_obj_kaifuku_moto_2_motion_names, 1, 0
};
CollisionBody heal_general_collision_body_part = {
    { 0.0f, 20.0f, 0.0f }, 10.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f
};
const char *TOHealGeneral::class_name = "TOHealGeneral";
BmlResource *TOHealGeneral::model_resource;

// In a game without a split screen every player counts as local.
s32 TOHealGeneral::is_local_player(u16 client) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return 1;
    }
    return (u32)__cntlzw((u32)(local_client_id - client)) >> 5;
}

void TOHealGeneral::update_demo() {}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TOHealGeneral::update_closing() {
    s16 hp;
    TObjPlayer *player;
    apply_heal_to_target();
    rotor_angle = rotor_angle + 0x147;
    ring_drop = ring_drop - 0.37166664f;
    effect_pos[1].y = (22.3f + position.y) - ring_drop;
    if (ring_drop <= 0.0f) {
        ring_drop = 0.0f;
        object_state = 0;
        if (is_local_player(heal_target) != 0) {
            player = get_player_by_client_id(heal_target);
            if (player != NULL) {
                hp = get_actor_hp(player);
                if (hp > 0) {
                    send_6x2F_change_player_hp(0xFFFF, heal_target, hp);
                }
            }
        }
    }
}
#pragma pop

void TOHealGeneral::update_opening() {
    apply_heal_to_target();
    rotor_angle = rotor_angle + 0x147;
    ring_drop += 0.37166664f;
    effect_pos[1].y = (22.3f + position.y) - ring_drop;
    if (22.3f <= ring_drop) {
        ring_drop = 22.3f;
        object_state = 2;
    }
}

void TOHealGeneral::apply_heal_to_target() {
    TObjPlayer *player;
    u32 id = heal_target;
    if (id != 0xFFFF && id < 0x1000) {
        player = get_player_by_client_id(id);
        if (player != NULL && player->obj_testFlags30(0x800) == 0 &&
            horizontal_distance_squared(&player->position, &position) < 225.0f) {
            add_actor_hp((u8 *)player, 9);
            add_actor_tp((u8 *)player, 9);
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TOHealGeneral::find_heal_target() {
    TObjPlayer *player;
    s32 i;
    s32 id;
    f32 r;
    rotor_angle += 0x147;
    heal_target = 0xFFFF;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        id = get_entity_id(player);
        if (player == NULL) {
            continue;
        }
        if ((u16)id >= 0x1000) {
            continue;
        }
        r = 10.0f - get_collision_body_radius(player, 0);
        if (!(horizontal_distance_squared(&player->position, &position) < r * r)) {
            continue;
        }
        heal_target = id;
        if (get_actor_hp(player) < ((TItemProShield *)player)->get_field_2b8() ||
            get_actor_tp(player) < obj_getS16_2BA((u8 *)player) ||
            (u32)player->get_recovery_need_flags() != 0 ||
            (player->is_alive_and_ready() != 0 && player->are_traps_full() == 0)) {
            TParticleCtrl *effect;
            object_state = 1;
            if (is_local_player(heal_target) != 0) {
                send_6x2C_impose_hold(player, &position, 0x3C, 0, r);
                player->clear_harmful_statuses();
            }
            if (player->is_alive_and_ready() != 0) {
                player->refill_traps();
            }
            effect = (TParticleCtrl *)spawn_particle_effect_with_flags((u8 *)player + 0x2FC, 0x1F6, 0x10);
            if (effect != NULL) {
                effect->set_owner_id(heal_target);
            }
            effect = (TParticleCtrl *)spawn_particle_effect_with_flags((u8 *)player + 0x2FC, 0x1F7, 0x10);
            if (effect != NULL) {
                effect->set_owner_id(heal_target);
            }
            play_sound_effect(0x4002AB0E, &position, 0, 0);
            break;
        }
    }
}
#pragma pop

void TOHealGeneral::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        update_demo();
        return;
    }
    switch (object_state) {
    case 0:
        find_heal_target();
        return;
    case 1:
        update_opening();
        return;
    case 2:
        update_closing();
        return;
    }
}

// The base, the rotor turning under it and the ring turning the other way as
// it drops.
void TOHealGeneral::render() {
    NJS_OBJECT *base;
    NJS_OBJECT *rotor;
    NJS_OBJECT *ring;

    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        base = (NJS_OBJECT *)model;
        post_translate_matrix(base->pos);
        draw_ginja_model((s32)base->model);
        push_matrix();
        rotor = base->child;
        post_translate_matrix(rotor->pos);
        rotate_matrix_y(NULL, rotor_angle);
        draw_ginja_model((s32)rotor->model);
        pop_matrix();
        push_matrix();
        ring = rotor->sibling;
        translate_matrix(0, ring->pos[0], ring->pos[1] - ring_drop, ring->pos[2]);
        rotate_matrix_y(NULL, -rotor_angle);
        draw_ginja_model((s32)ring->model);
        pop_matrix();
        pop_matrix();
    }
}

void *TOHealGeneral::create(void *set_data) {
    return new TOHealGeneral(set_data);
}

void TOHealGeneral::unload_resources() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TOHealGeneral::load_resources() {
    BmlResource *resource;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &fe_obj_kaifuku_moto_2_resource_descriptor, 0, 0, 0);
        }
        model_resource = resource;
        return;
    }
    resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fe_obj_kaifuku_moto_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
}

TOHealGeneral::~TOHealGeneral() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (effects[i] != NULL) {
            TParticleCtrl::release(effects[i]);
        }
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOHealGeneral::TOHealGeneral(void *set_data) : TObjMapObject(tl_05) {
    s32 i;
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)model_resource->models->model;
    texlist = model_resource->models->m_c;
    model_radius = 40.0f;
    init_collision_body_parts(this, &heal_general_collision_body_part, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    clear_player_status_flag(0, 1);
    rotor_angle = 0;
    ring_drop = 0.0f;
    for (i = 0; i < 2; i++) {
        VecCopy(&effect_pos[i], &position);
    }
    effect_pos[0].y += 26.100002f;
    effect_pos[1].y += 22.3f;
    effects[0] = create_particle_emitter(&effect_pos[0], 0x63);
    if (effects[0] != NULL && effects[0]->all_parents_unqueued_for_destruction() == 0) {
        effects[0] = NULL;
    }
    effects[1] = spawn_continuous_particle_effect_with_flags(&effect_pos[1], 0x63, 0x10);
    if (effects[1] != NULL && effects[1]->all_parents_unqueued_for_destruction() != 0) {
        effects[1]->set_owner_id(entity_id);
    } else {
        effects[1] = NULL;
    }
    heal_target = 0xFFFF;
}

void *TOHealGeneral::get_center() { return &effect_pos[1]; }
