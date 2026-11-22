#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/GroundContactSound.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/technique/TTecZarua.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoaReal.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/reflection.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/animation/MotionContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/BmlResourceDescriptor.h"
#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecSifta.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/enemy/sinowzoa/SinowZoaData.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/unk/TLobby.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/math/AngleUnits.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/technique/TTecDeband.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/unk/text_803D853C.h"

// load_resources fills these per kind (0 and 1) from TLobby::register_boss,
// TLobby::dispatch_shared_handler_b, TLobby::register_object and
// TLobby::dispatch_shared_handler_a.
Vec lbl_80542FB0;
u8 *lbl_80542FBC[2];
u8 *lbl_80542FC4[2];
u8 *lbl_80542FCC[2];
TObjEneMe3SinowZoaParams *TObjEneMe3SinowZoa__kind_param_tbls[2];
// The model texture list with textures 0-2 swapped for 3-5 (load_resources); sub_8031A3D8
// installs it for the alternate form (named after the Stelth twin, load_shared_resources).
NJS_TEXLIST TObjEneMe3SinowZoa__alternate_texture_list;
Vec lbl_80542FE4;
u32 *TObjEneMe3SinowZoa__material_color_pointers[4];

BmlResource * TObjEneMe3SinowZoa__bml_resource;
s32 TObjEneMe3SinowZoa__render_node_index;
TUnk_8048FA00 * TObjEneMe3SinowZoa__breakup_model;

void print_float_padded(s32 arg0, s32 prec, f32 val);
void move_with_wall_slide(u8 *arg0);

extern "C" {
s32 scale_matrix(int, f32, f32, f32);
s32 post_translate_matrix(void *);
s32 select_enemy_destination(void *, Vec, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec);
}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
u16 get_entity_id(TObjBase *object);
f32 fabs_float(f32);
s32 TObjEneMe3SinowZoa__sub_800D72A4(TUnk_80494938 *fade);
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
f32 * TBoss3Volopt__sub_800F059C(void *);
void create__9TTecJelinFllll(void *, void *, void *, int);
}
void compose_motion_node_matrix(void *arg0);
extern "C" {
f64 atan2_float(f32, f32);
BOOL is_split_screen(void);
}

extern const f32 TObjEneMe3SinowZoa__data_805DF2FC;
extern const f32 lbl_805DF300;
extern const f32 TObjEneMe3SinowZoa__data_805DF2F0;
extern const f32 TObjEneMe3SinowZoa__data_805DF2F4;
extern const f32 lbl_805DF304;
extern s32 model_render_flags;
extern const f32 lbl_805DF318;
extern const f32 TObjEneMe3SinowZoa__data_805DF31C;
extern u8 identity_matrix[];
extern s32 game_difficulty_selection;
extern const f32 TObjEneMe3SinowZoa__data_805DF308;
extern const f32 TObjEneMe3SinowZoa__data_805DF30C;
extern const f32 TObjEneMe3SinowZoa__data_805DF310;
extern const f32 TObjEneMe3SinowZoa__data_805DF314;
extern const f32 lbl_805DF2F8;
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;

TObjEneMe3SinowZoaMoveParams TObjEneMe3SinowZoa_init_params = { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } };
CollisionBody sinow_zoa_collision_parts = { { 0.0f, 0.0f, 0.0f }, 12.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f };
const char *bm_ene_me3_shinowa_zoa_model_names[] = {
    sinow_zoa_model, NULL,
};
const char *bm_ene_me3_shinowa_zoa_motion_names[] = {
    sinow_zoa_t_wait_motion, sinow_zoa_apper_motion, sinow_zoa_backstep_motion, sinow_zoa_bareta_motion,
    sinow_zoa_damage_motion, sinow_zoa_death_motion, sinow_zoa_f_attack_motion, sinow_zoa_sword_motion,
    sinow_zoa_transform_motion, sinow_zoa_wait_motion, sinow_zoa_walk_motion, NULL,
};
BmlResourceDescriptor bm_ene_me3_shinowa_zoa_resource_descriptor = {
    sinow_zoa_bml, bm_ene_me3_shinowa_zoa_model_names, bm_ene_me3_shinowa_zoa_motion_names, 1, 11,
};
const char *bm_ene_me3_zoa_low_model_names[] = {
    sinow_zoa_low_model, NULL,
};
const char *bm_ene_me3_zoa_low_motion_names[] = {
    sinow_zoa_t_wait_motion, sinow_zoa_apper_motion, sinow_zoa_backstep_motion, sinow_zoa_bareta_motion,
    sinow_zoa_damage_motion, sinow_zoa_death_motion, sinow_zoa_f_attack_motion, sinow_zoa_sword_motion,
    sinow_zoa_transform_motion, sinow_zoa_wait_motion, sinow_zoa_walk_motion, NULL,
};
BmlResourceDescriptor bm_ene_me3_zoa_low_resource_descriptor = {
    sinow_zoa_low_bml, bm_ene_me3_zoa_low_model_names, bm_ene_me3_zoa_low_motion_names, 1, 11,
};
const char *TObjEneMe3SinowZoa__name = sinow_zoa_class_name;
const char *TObjEneMe3SinowZoaReal__name = sinow_zoa_real_class_name;
TObjMotionAction lbl_804E8880[13] = {
    { 1, 0, 0, 0.5f, 0x80000000 },
    { 3, 0, 1, 0.7f, 0x80000000 },
    { 1, 0, 9, 0.5f, 0x80000000 },
    { 3, 0, 2, 0.8f, 0x0 },
    { 3, 0, 4, 0.4f, 0x0 },
    { 3, 0, 5, 0.6f, 0x0 },
    { 3, 0, 6, 0.7f, 0x0 },
    { 3, 0, 7, 1.0f, 0x0 },
    { 3, 0, 8, 1.0f, 0x0 },
    { 1, 0, 9, 0.5f, 0x0 },
    { 1, 0, 10, 1.1f, 0x0 },
    { 3, 0, 3, 0.7f, 0x0 },
    { 3, 0, 8, 1.0f, 0x0 },
};

struct ChunkModel {
    void *vlist;
    u32 *plist;
};

struct ModelNode {
    u32 evalflags;
    ChunkModel *model;
};

// load_resources (inferred): floor_resource_callbacks pairs it with free_resources.
void TObjEneMe3SinowZoa::load_resources() {
    s32 i;
    NJS_TEXLIST *src;
    s32 count;
    u32 model;
    ModelNode *node;
    AnimationMotion *motion;
    TUnk_8048FA00 *breakup;
    TObjEneMe3SinowZoaParams *params;

    lbl_80542FB0.x = TObjEneMe3SinowZoa__data_805DF31C;
    lbl_80542FB0.y = TObjEneMe3SinowZoa__data_805DF31C;
    lbl_80542FB0.z = TObjEneMe3SinowZoa__data_805DF31C;
    if (is_split_screen()) {
        TObjEneMe3SinowZoa__bml_resource = load_enemy_bml_resource(&bm_ene_me3_zoa_low_resource_descriptor);
    } else {
        TObjEneMe3SinowZoa__bml_resource = load_enemy_bml_resource(&bm_ene_me3_shinowa_zoa_resource_descriptor);
    }
    src = (NJS_TEXLIST *)TObjEneMe3SinowZoa__bml_resource->models->m_c;
    count = src->nbTexture;
    TObjEneMe3SinowZoa__alternate_texture_list.nbTexture = count;
    TObjEneMe3SinowZoa__alternate_texture_list.textures = (NJS_TEXNAME *)mem_alloc(count * sizeof(NJS_TEXNAME));
    for (i = 0; i < count; i++) {
        ((TObjPlayer *)&TObjEneMe3SinowZoa__alternate_texture_list.textures[i])->copy_vec3(&src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        TObjEneMe3SinowZoa__alternate_texture_list.textures[i].texaddr = TObjEneMe3SinowZoa__alternate_texture_list.textures[i + 3].texaddr;
    }
    for (i = 0; i < 2; i++) {
        lbl_80542FBC[i] = (u8 *)TLobby::register_boss(lbl_80475E0C[i]);
    }
    for (i = 0; i < 2; i++) {
        lbl_80542FC4[i] = (u8 *)TLobby::dispatch_shared_handler_b(lbl_80475E14[i]);
    }
    for (i = 0; i < 2; i++) {
        lbl_80542FCC[i] = (u8 *)TLobby::register_object(lbl_80475E1C[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3SinowZoa__kind_param_tbls[i] = (TObjEneMe3SinowZoaParams *)TLobby::dispatch_shared_handler_a(lbl_80475E24[i]);
    }
    params = TObjEneMe3SinowZoa__kind_param_tbls[0];
    set_entry_value_clamped(7, params->m_c);
    set_entry_value_clamped(4, params->m_10);
    TObjEneMe3SinowZoa__render_node_index = 0;
    lbl_80542FE4.x = TObjEneMe3SinowZoa__data_805DF31C;
    lbl_80542FE4.y = TObjEneMe3SinowZoa__data_805DF31C;
    lbl_80542FE4.z = TObjEneMe3SinowZoa__data_805DF31C;
    model = (saddr)TObjEneMe3SinowZoa__bml_resource->models->model;
    node = (ModelNode *)find_model_node(model, 9);
    if (node->model != NULL) {
        TObjEneMe3SinowZoa__material_color_pointers[0] = node->model->plist + 1;
    } else {
        TObjEneMe3SinowZoa__material_color_pointers[0] = NULL;
    }
    node = (ModelNode *)find_model_node(model, 13);
    if (node->model != NULL) {
        TObjEneMe3SinowZoa__material_color_pointers[1] = node->model->plist + 1;
    } else {
        TObjEneMe3SinowZoa__material_color_pointers[1] = NULL;
    }
    node = (ModelNode *)find_model_node(model, 38);
    if (node->model != NULL) {
        TObjEneMe3SinowZoa__material_color_pointers[2] = node->model->plist + 1;
    } else {
        TObjEneMe3SinowZoa__material_color_pointers[2] = NULL;
    }
    motion = TObjEneMe3SinowZoa__bml_resource->motions[lbl_804E8880[5].motion].motion;
    breakup = new TUnk_8048FA00(TObjEneMe3SinowZoa__bml_resource->models->model, (NJS_MOTION *)motion, motion->frameCount - 1);
    TObjEneMe3SinowZoa__breakup_model = breakup;
    {
        NpcAnimationBinding info = lbl_80475FA8;
        info.motions = reinterpret_cast<BmlMotionEntry *>(TObjEneMe3SinowZoa__bml_resource->motions);
        NpcAnimationBinding info_b = lbl_80475FB8;
        info_b.motions = reinterpret_cast<BmlMotionEntry *>(TObjEneMe3SinowZoa__bml_resource->motions);
        NpcModelRegistry::register_animated_chunk(0x49, reinterpret_cast<void *>(TObjEneMe3SinowZoa__bml_resource->models->model), reinterpret_cast<void *>(TObjEneMe3SinowZoa__bml_resource->models->m_c), &info, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
        NpcModelRegistry::register_animated_chunk(0x4A, reinterpret_cast<void *>(TObjEneMe3SinowZoa__bml_resource->models->model), reinterpret_cast<void *>(&TObjEneMe3SinowZoa__alternate_texture_list), &info, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
        NpcModelRegistry::register_animated_chunk(0x4B, reinterpret_cast<void *>(TObjEneMe3SinowZoa__bml_resource->models->model), reinterpret_cast<void *>(TObjEneMe3SinowZoa__bml_resource->models->m_c), &info_b, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
        NpcModelRegistry::register_animated_chunk(0x4C, reinterpret_cast<void *>(TObjEneMe3SinowZoa__bml_resource->models->model), reinterpret_cast<void *>(&TObjEneMe3SinowZoa__alternate_texture_list), &info_b, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
    }
}

extern "C" {

int TObjEneMe3SinowZoaReal__create(void* p) { return (saddr)TObjEneMe3SinowZoaReal::create_instance(p); }

void TObjEneMe3SinowZoa::free_resources() {
    if (TObjEneMe3SinowZoa__breakup_model != NULL) {
        delete TObjEneMe3SinowZoa__breakup_model;
        TObjEneMe3SinowZoa__breakup_model = NULL;
    }
    if (TObjEneMe3SinowZoa__alternate_texture_list.textures != NULL) {
        mem_free(TObjEneMe3SinowZoa__alternate_texture_list.textures);
        TObjEneMe3SinowZoa__alternate_texture_list.textures = NULL;
    }
    if (TObjEneMe3SinowZoa__bml_resource != 0) {
        delete TObjEneMe3SinowZoa__bml_resource;
        TObjEneMe3SinowZoa__bml_resource = NULL;
    }
}

void TObjEneMe3SinowZoa::set_entry_value_clamped(s32 arg0, f32 farg0) {
    if (farg0 < 0.1f) {
        farg0 = 0.1f;
    }
    lbl_804E8880[arg0].speed = farg0;
}

}

TObjEneMe3SinowZoa::TObjEneMe3SinowZoa(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe3SinowZoa__name;
}

extern "C" {

void TObjEneMe3SinowZoaReal::init_enemy() {
    s32 kind;

    init_position_vectors();
    sub_8031A3D8();
    model = (void *)TObjEneMe3SinowZoa__bml_resource->models->model;
    init_model(&sinow_zoa_collision_parts, 1);
    motion_flags = 0;
    this->set_field_d8((saddr)lbl_804E8880);
    this->set_field_dc((saddr)TObjEneMe3SinowZoa__bml_resource->motions);
    set_animation((this->requested_action));
    kind = this->kind_index;
    reset_hp(lbl_80542FBC[kind], lbl_80542FC4[kind], lbl_80542FCC[kind]);
    this->set_state_flag_4();
    movementParameters = &TObjEneMe3SinowZoa_init_params;
    this->wall_reach = TObjEneMe3SinowZoa__data_805DF314;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    this->behavior_flags = 0;
    this->m_3d0 = 0;
    VecCopy(&m_3d4, &position);
    this->body_y = (this->position.y);
    this->body_offset_y = TObjEneMe3SinowZoa__data_805DF31C;
    material_color = 0;
    this->m_3fc = 0;
    this->m_404 = (s16) this->m_2cc;
    fade.reset_obstruction_fade();
    this->state_step = 0;
    this->state_timer = 0;
    this->m_43c = 0;
    this->m_440 = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_444 = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_448 = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_44c = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_450 = TObjEneMe3SinowZoa__data_805DF31C;
    unk_454 = NULL;
    unk_458 = NULL;
    if (this->stealthed == 1) {
        set_indexed_flags(0, 0x08000000);
    } else {
        this->clear_player_status_flag(0, 0x08000000);
    }
}

TObjEneMe3SinowZoa::~TObjEneMe3SinowZoa() {
    if (unk_454 != NULL) {
        unk_454->queue_destruction();
        unk_454 = NULL;
    }
    if (unk_458 != NULL) {
        unk_458->queue_destruction();
        unk_458 = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneMe3SinowZoa::run_task() {
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->action();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
    }
    sub_8031AC74();
    this->copy_pos_with_height_offset();
    this->update_body_colliders();
    temp_r3 = this->behavior_flags;
    if (temp_r3 & 0x40000) {
        this->behavior_flags = (s32) (temp_r3 & 0xFFFBFFFF);
    } else {
        submit_default_cursor_candidate();
    }
    if ((this->stealthed == 0) || (TObjEneMe3SinowZoa__sub_800D72A4(&fade) != 0)) {
        this->render_minimap_dot();
    }
    if (this->m_3d0 & 0x4000) {
        request_reflection_render();
    }
}

void TObjEneMe3SinowZoa::sub_8031AC74() {
    s32 temp_r3;
    s32 temp_r3_2;
    if (actorFlags & 0x24) {
        if ((this->stealthed != 0) || (temp_r3 = this->behavior_flags, (((temp_r3 & 0x100000) == 0) == 0)) || (temp_r3 & 4)) {
            this->behavior_flags |= 4;
            if (fade.advance_toward_max() != 0) {
                this->stealthed = 0;
                this->behavior_flags &= 0xFFEFFFFB;
                this->behavior_flags |= 0x40000;
                clear_player_status_flag(0, 0x08000000);
            }
        }
        if ((s16) this->mode == 0x11) {
            transition_enemy_state(0x12);
        }
    } else {
        temp_r3_2 = this->behavior_flags;
        if (!(temp_r3_2 & 0x100000) && !(temp_r3_2 & 4) && (TObjEneMe3SinowZoa__sub_800D72A4(&fade) != 0)) {
            if (this->stealthed != 0) {
                if (fade.decay_value_toward_floor() != 0) {
                    this->behavior_flags |= 0x40000;
                    set_indexed_flags(0, 0x08000000);
                }
            } else if (fade.advance_toward_max() != 0) {
                this->behavior_flags |= 0x40000;
                clear_player_status_flag(0, 0x08000000);
            }
        }
    }
}

void TObjEneMe3SinowZoa::refresh_target() {  }

void TObjEneMe3SinowZoa::run_death_reaction() { if (this->mode != 15) { transition_enemy_state(15); } }

void TObjEneMe3SinowZoa::run_hit_reaction() {
    if (this->behavior_flags & 1) {
        clear_attack_receipts();
        if ((this->stealthed == 1) && (random_ratio() <= this->stealth_off_chance)) {
            transition_enemy_state(0x12);
        }
    } else if ((s16) this->mode != 0xE) {
        transition_enemy_state(0xE);
    }
}

void TObjEneMe3SinowZoa::run_miss_reaction() {  }

void TObjEneMe3SinowZoa::copy_pos_with_height_offset() {
    VecCopy(&body_center, &position);
    this->body_center.y = this->body_center.y + (TObjEneMe3SinowZoa__data_805DF2FC + this->body_offset_y);
    VecCopy(&center, &position);
}

void TObjEneMe3SinowZoa::update_body_colliders() {
    bodies->offset.y = this->body_center.y - this->position.y;
}

void TObjEneMe3SinowZoa::set_intangible() { TObjEneDD::set_intangible(); sub_800F5874(38); }

void TObjEneMe3SinowZoa::clear_intangible() { TObjEneDD::clear_intangible(); sub_800F5864(38); }

void TObjEneMe3SinowZoa::setup_move_bounds() {
    if (sub_8031A4D0() != 0) {
        this->stealthed = 1;
    } else {
        this->stealthed = 0;
    }
    this->m_3c4 = is_outside_visible_range();
    if (this->m_3c4 == 1) {
        this->requested_action = 2;
    } else {
        this->requested_action = 0;
    }
    this->technique_chance = 0.4f + this->parameters[2];
    this->stealth_on_chance = 0.3f + this->parameters[1];
    this->stealth_off_chance = 0.1f + this->parameters[4];
    this->warp_chance = lbl_805DF304 + this->parameters[3];
    this->m_400 = (s32) this->variant;
}

f32 TObjEneMe3SinowZoa::get_node_height() {
    Vec v;
    NJS_OBJECT *node;
    v.x = TObjEneMe3SinowZoa__data_805DF31C;
    v.y = TObjEneMe3SinowZoa__data_805DF31C;
    v.z = TObjEneMe3SinowZoa__data_805DF31C;
    push_matrix_from(identity_matrix);
    bind_motion_context(current_motion, frame);
    node = (NJS_OBJECT *)model;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

s32 TObjEneMe3SinowZoa::check_body_collision_at(s32 arg1, f32 farg0) {
    f32 f2 = farg0 * lbl_805DF304;
    CollisionBody *body = bodies;
    u8 res;
    s32 rot = rotation_y;
    u32 flags = body->flags;
    body->offset.x = TObjEneMe3SinowZoa__data_805DF31C;
    body->offset.z = f2;
    body->radius = f2;
    body->half_width = TObjEneMe3SinowZoa__data_805DF2FC;
    body->shape = 1;
    body->flags = 0x9D01;
    rotation_y = arg1;
    ((void (*)(void *, s32, f32, f32))check_enemy_body_collisions)(this, arg1, TObjEneMe3SinowZoa__data_805DF31C, f2);
    res = (body->flags & 0x380000) != 0;
    copy_collision_body(body, &sinow_zoa_collision_parts);
    body->flags = flags;
    rotation_y = rot;
    return res;
}

#pragma push
#pragma fp_contract on

s32 TObjEneMe3SinowZoa::sub_8031A820(f32) {
    f32 facing;
    if (fabs_float(current_target->position.y - position.y) >= 20.0f) {
        if (random_ratio() <= warp_chance) {
            transition_enemy_state(0xC);
        } else {
            return 0;
        }
    }
    if (destination_distance > 25.0f) {
        return 0;
    }
    facing = (destination_direction.x * sin_table_lookup(rotation_y)) + (destination_direction.z * cos_table_lookup(rotation_y));
    if (facing < cos_table_lookup(0x1E00)) {
        return 0;
    }
    return 1;
}

#pragma pop

void TObjEneMe3SinowZoa::sub_8031A6A0() {
    f32 d;
    s32 near;
    TObjChara *pl;
    near = is_passing_frame(lbl_805DF2F8);
    if (is_passing_frame(TObjEneMe3SinowZoa__data_805DF2F0) != 0 || near != 0) {
        if (enemy_check_target_valid() != 0) {
            if (current_target->select_melee_contact_body(this, TObjEneMe3SinowZoa__data_805DF2F4) != 0) {
                d = current_target->receive_physical_attack(this, TObjEneMe3SinowZoa__data_805DF2F4);
                current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                if (d > TObjEneMe3SinowZoa__data_805DF31C) {
                    if (sub_8031A454() != 0) {
                        pl = current_target;
                        TItem *held;
                        if (TObjPlayer::is_locally_controlled(pl) != 0 && (held = (TItem *)TObjPlayer::get_item_field_6(pl)) != 0) {
                            TObjPlayer::send_6x26_unequip_item(pl, held->get_item_id());
                            ((TObjPlayer *)pl)->get_hand_joint_position((saddr)&unk_408);
                            spawn_particle_effect(&unk_408, 0x1D0);
                        }
                    } else if (near != 0 && this->random_ratio() <= 0.1666f) {
                        TObjEneDD__sub_800BA438(this, current_target);
                    }
                }
            }
        }
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003AA2B, &position, 0, 0);
    }
}

void TObjEneMe3SinowZoa::vfunc_108() {  }

s32 TObjEneMe3SinowZoa::is_target_in_range() {
    f32 temp_f1;
    u8 var_r31;

    var_r31 = 0;
    if (!(this->behavior_flags & 0x10000)) {
        temp_f1 = this->destination_distance;
        if ((temp_f1 > 50.0f) && (temp_f1 < 150.0f) && (this->check_body_collision_at(this->rotation_y, temp_f1 - 20.0f) == 0)) {
            var_r31 = 1;
        }
    }
    return var_r31;
}

void TObjEneMe3SinowZoa::select_next_attack_state() {  }

s32 TObjEneMe3SinowZoa::try_run_effect_m6() {
    if (this->behavior_flags & 4) {
        fade.set_flags_and_apply_damage_color();
        return 1;
    }
    return 0;
}

s32 TObjEneMe3SinowZoa::try_run_effect_m7() {
    if (this->behavior_flags & 4) {
        fade.clear_flag_and_notify();
        return 1;
    }
    return 0;
}

void TObjEneMe3SinowZoa::on_target_lost() {  }

void TObjEneMe3SinowZoa::vfunc_112() {  }

void TObjEneMe3SinowZoa::update_distance_state() {
    f32 thr = 30.0f;
    if ((this->body_y - this->position.y) > thr) {
        set_colliders_contact_high();
        return;
    }
    set_colliders_contact_low();
}

void TObjEneMe3SinowZoa::check_collisions() {
    update_body_colliders();
    check_object_collisions();
    check_enemy_body_collisions(this);
    update_enemy_collision_flags();
}

s32 TObjEneMe3SinowZoa::sub_8031A4D0() {
    return parameters[0] < 2.0f;
}

s32 TObjEneMe3SinowZoa::is_outside_visible_range() {
    u8 r = 0;
    if (parameters[0] < TObjEneMe3SinowZoa__data_805DF2F4 ||
        (parameters[0] >= 2.0f && parameters[0] < 3.0f)) r = 1;
    return r;
}

s32 TObjEneMe3SinowZoa::acquire_target(f32 range) { return select_and_apply_target(range); }

s32 TObjEneMe3SinowZoa::sub_8031A454() {
    u8 r = this->m_400 >= 1;
    return r;
}

void TObjEneMe3SinowZoa::sub_8031A3D8() {
    if (sub_8031A454() != 0) {
        texlist = (saddr)&TObjEneMe3SinowZoa__alternate_texture_list;
        initialize_enemy_state(0x46);
        this->kind_index = 1;
        return;
    }
    texlist = (saddr)TObjEneMe3SinowZoa__bml_resource->models->m_c;
    initialize_enemy_state(0x45);
    this->kind_index = 0;
}

void TObjEneMe3SinowZoa::cast_technique() {
    saddr lv;
    lv = TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->m_18);
    if (sub_8031A454() != 0) {
        if (game_difficulty_selection == 3) {
            TTecSifta::create(this, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->m_18));
            TTecDeband::create(this, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->m_18));
        } else {
            TTecZarua::create_instance((saddr)this, &position, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->m_18));
            create__9TTecJelinFllll(this, &position, &position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[kind_index]->m_18));
        }
    } else {
        TTecResta::create(this, &position, lv);
    }
}

void TObjEneMe3SinowZoa::dispatch_action(u32 state, s32 mode) {
    switch (state) {
    case 0:
        action(mode);
        return;
    case 1:
        sub_80319E74(mode);
        return;
    case 3:
        sub_80319B8C(mode);
        return;
    case 2:
        state_chase(mode);
        return;
    case 4:
        update_state_action(mode);
        return;
    case 5:
        sub_80319748(mode);
        return;
    case 6:
        state_chase_target(mode);
        return;
    case 7:
        sub_80318F7C(mode);
        return;
    case 8:
        sub_80318C0C(mode);
        return;
    case 9:
        sub_8031884C(mode);
        return;
    case 13:
        handle_state_substate(mode);
        return;
    case 10:
        sub_803182F8(mode);
        return;
    case 11:
        sub_80318564(mode);
        return;
    case 14:
        state_knockback(mode);
        return;
    case 15:
        sub_80317F90(mode);
        return;
    case 12:
        sub_80317B50(mode);
        return;
    case 16:
        sub_80316C3C(mode);
        return;
    case 17:
        sub_80317254(mode);
        return;
    case 18:
        sub_803170F0(mode);
    default:
        return;
    }
}

void TObjEneMe3SinowZoa::action(s32 mode) {
    s32 temp_r3;
    s32 temp_r4;

    switch (mode) {
    case 4:
        if (this->m_3c4 == 1) {
            this->requested_action = 2;
            set_field_378(1);
        } else {
            this->requested_action = 0;
            set_field_378(3);
        }
        set_intangible();
        temp_r4 = this->behavior_flags;
        this->behavior_flags = (s32) (temp_r4 | 2);
        temp_r3 = this->behavior_flags;
        this->behavior_flags = (s32) (temp_r3 & 0xFFEFFFFA);
        if (TObjEneDD::check_v2_mode() != 0) {
            this->behavior_flags &= 0xFFFEFFFF;
        }
        this->state_step = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy(&body_center, &home_position);
        this->body_y = this->position.y;
        this->material_color = 0;
        this->m_3fc = 0;
        return;
    case 3:
        if (this->state_step > 5) {
            if (this->m_3c4 == 1) {
                this->transition_enemy_state(1);
            } else {
                this->transition_enemy_state(3);
            }
        }
    case 5:
        return;
    case 0:
        this->state_step += 1;
        if (this->state_step == 1) {
            this->body_y = this->position.y;
            update_ground_contact();
            this->body_offset_y = this->body_y - this->position.y;
        }
        break;
    }
}

void TObjEneMe3SinowZoa::sub_80319E74(s32 mode) {
    Vec v;
    f32 t;
    switch (mode) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(0);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFFD;
        this->behavior_flags |= 5;
        this->fade.start_fade_in();
        VecCopy(&v, &this->position);
        t = this->body_y;
        v.y = t - 20.0f;
        if (this->stealthed == 0) {
            TBoss3Volopt__sub_800D8D88(&v, t);
        } else {
            create_timed_particle_emitter(&this->position, 0x79, 0, 0xF);
        }
        break;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            if (this->stealthed == 1) {
                this->transition_enemy_state(2);
            } else {
                this->transition_enemy_state(0xD);
            }
        }
        break;
    case 0:
        if (*TBoss3Volopt__sub_800F059C(&this->fade) >= -0.75f) {
            this->advance_animation();
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    case 5:
        this->behavior_flags &= ~4;
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::state_chase(s32 mode) {
    s32 temp_r0;
    s32 temp_r4;

    switch (mode) {
    case 4:
        this->requested_action = 9;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->state_step = 0;
        this->state_timer = 0;
        this->m_444 = TObjEneMe3SinowZoa__data_805DF31C;
        return;
    case 3:
        if (this->acquire_target(200.0f) != 0) {
            if (this->destination_distance <= 40.0f) {
                this->transition_enemy_state(0xD);
                return;
            }
            temp_r0 = this->state_timer - 1;
            this->state_timer = temp_r0;
            if ((temp_r0 <= 0) && (this->is_target_in_range() != 0)) {
                this->state_timer = 0x3C;
                if (this->random_ratio() <= 0.01f) {
                    this->transition_enemy_state(7);
                    return;
                }
            }
        } else if (this->state_step >= 0xE10) {
            this->transition_enemy_state(0xD);
            return;
        }
        break;
    case 5:
        break;
    case 0:
        (this->state_step)++;
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->m_444 = (this->destination_direction.x * sin_table_lookup(this->rotation_y)) + (this->destination_direction.z * cos_table_lookup(this->rotation_y));
            if (this->m_444 < cos_table_lookup(0x1000)) {
                this->turn_toward_target_direction(0x500);
                this->update_ground_contact();
            }
        }
        this->check_collisions();
        break;
    }
}

void TObjEneMe3SinowZoa::sub_80319B8C(s32 mode) {
    Vec v;
    f32 temp_f1;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(0);
        this->set_intangible();
        this->behavior_flags |= 7;
        this->fade.start_fade_in();
        VecCopy(&v, &this->position);
        temp_f1 = this->body_y;
        v.y = temp_f1 - TObjEneMe3SinowZoa__data_805DF314;
        TBoss3Volopt__sub_800D8D88(&v, temp_f1);
        break;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            this->transition_enemy_state(4);
            break;
        }
    case 0:
        break;
    case 5:
        this->behavior_flags &= 0xFFFFFFFB;
        break;
    }
}

#pragma pop

void TObjEneMe3SinowZoa::update_state_action(s32 mode) {
    // inferred: clears the green byte of the ARGB colour material_color
    static const u32 color_mask = 0xFFFF00FF;
    switch (mode) {
    case 4:
        this->requested_action = 0;
        set_field_378(5);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->state_step = 0;
        this->state_timer = 0;
        break;
    case 3:
        if (this->state_step > 0x1E) {
            this->transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        if (this->state_step == 0) {
            if (update_linked_position(200.0f) != 0) {
                this->state_step = 1;
                this->material_color = 0x1C00FFFF;
                this->material_color &= color_mask;
                this->state_timer = 0;
            }
        } else {
            (this->state_step)++;
            this->state_timer += 0x10;
            if (this->state_timer > 0xFF) {
                this->state_timer = 0xFF;
            }
            this->material_color = (this->state_timer << 24) | (this->material_color & 0xFFFFFF);
            if (enemy_validate_retained_target(this) == 0) {
                this->state_step = 0;
                this->material_color = 0;
            }
        }
        this->update_ground_contact();
        update_distance_state();
        this->check_collisions();
        this->body_offset_y = this->body_y - this->position.y;
        break;
    case 5:
        this->material_color = 0x1C00FFFF;
        this->body_offset_y = TObjEneMe3SinowZoa__data_805DF31C;
        break;
    }
}

void TObjEneMe3SinowZoa::sub_80319748(s32 mode) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 node_height;

    switch (mode) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(0xD);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF9;
        this->behavior_flags |= 1;
        this->state_step = 0;
        this->m_440 = TObjEneMe3SinowZoa__data_805DF31C;
        if (this->enemy_has_live_target() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        }
        break;
    case 3:
        if (this->state_step == 3) {
            this->transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (this->state_step) {
        case 0:
            node_height = this->get_node_height();
            this->advance_animation();
            this->m_444 = this->get_node_height();
            this->body_y = this->body_y + (node_height - this->m_444);
            this->state_step = 1;
            this->body_offset_y = this->body_y - this->position.y;
            break;
        case 1:
            this->advance_animation();
            if (this->frame > 29.0f) {
                this->frame = 29.0f;
            }
            this->m_440 -= 0.3f;
            if (this->m_440 < -5.0f) {
                this->m_440 = -5.0f;
            }
            this->body_y = this->body_y + this->m_440;
            temp_f1 = this->get_node_height();
            this->body_y = this->body_y - (temp_f1 - this->m_444);
            this->m_444 = temp_f1;
            if (this->body_y < this->position.y) {
                this->body_y = this->position.y;
                this->state_step = 2;
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
                this->check_and_notify();
            }
            break;
        case 2:
            if (this->get_flag_b4() != 0) {
                this->requested_action = 9;
                this->state_step = 3;
                this->body_y = this->position.y;
                this->body_offset_y = TObjEneMe3SinowZoa__data_805DF31C;
            }
            this->advance_animation();
            break;
        }
        this->update_ground_contact();
        this->update_distance_state();
        this->check_collisions();
        this->body_offset_y = this->body_y - this->position.y;
        break;
    case 5:
        this->behavior_flags &= 0xFFFFFFFE;
        this->body_offset_y = TObjEneMe3SinowZoa__data_805DF31C;
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::state_chase_target(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->destination_distance = (f32) 300.0f;
        this->m_440 = (f32) TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->m_0;
        this->m_444 = TObjEneMe3SinowZoa__data_805DF31C;
        return;
    case 3:
        if (this->current_target == NULL) {
            this->on_target_lost();
            this->transition_enemy_state(0xD);
            return;
        }
        if (sub_8031A820(m_444) != 0) {
            this->transition_enemy_state(8);
            return;
        }
        if (this->is_target_in_range() != 0) {
            this->transition_enemy_state(7);
        }
    case 5:
        return;
    case 0:
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            sub_80316840();
            this->m_444 = (this->destination_direction.x * sin_table_lookup(this->rotation_y)) + (this->destination_direction.z * cos_table_lookup(this->rotation_y));
            if (this->m_444 < cos_table_lookup(0x1000)) {
                this->turn_toward_target_direction(0x500);
                this->update_ground_contact();
            } else {
                enemy_turn_and_move_on_ground(this, 0x500, this->m_440);
            }
            this->check_collisions();
        }
        break;
    }
}

void TObjEneMe3SinowZoa::sub_80318F7C(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 6;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->behavior_flags |= 0x10000;
        this->state_step = 0;
        this->m_440 = TObjEneMe3SinowZoa__data_805DF31C;
        this->set_active();
        break;
    case 3:
        if (this->state_step == 7 || this->get_flag_b4() != 0) {
            if (this->update_ground_contact() == 0) {
                this->transition_enemy_state(10);
            } else {
                this->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        switch ((u32)this->state_step) {
        case 0:
            this->advance_animation();
            if (this->motion_flags & 8) {
                this->state_step = 1;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 1: {
            s32 target;
            this->advance_animation();
            if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                target = (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            } else {
                target = this->rotation_y;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, target, 0x1000);
            if (this->is_passing_frame(TObjEneMe3SinowZoa__data_805DF314) != 0) {
                this->state_step = 2;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        }
        case 2:
            this->advance_animation();
            if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
            }
            if (this->frame + this->play_speed >= 14.0f) {
                if (this->check_body_collision_at(this->rotation_y, this->destination_distance - 20.0f) != 0) {
                    this->state_step = 7;
                } else {
                    Vec v;
                    f32 d = this->destination_distance - 20.0f;
                    VecCopy(&v, &this->position);
                    v.x = this->destination_direction.x * d + v.x;
                    v.y += 20.0f;
                    v.z = this->destination_direction.z * d + v.z;
                    if (csnVecterUnder(&v, 0x15) != 0) {
                        if (this->room == ((TScene *)(&v))->find_section_at_position()) {
                            if (this->stealthed != 0) {
                                ((TObjEneMe3SinowZoa *)&this->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
                                this->fade.reset_obstruction_fade();
                                this->behavior_flags |= 0x100000;
                                this->behavior_flags |= 0x40000;
                                this->clear_player_status_flag(0, 0x08000000);
                                this->state_step = 3;
                            } else {
                                this->state_step = 4;
                            }
                            this->m_444 = (this->destination_distance - 20.0f) / 12.857143f;
                            this->set_invulnerable();
                            play_sound_effect(0x4003A82C, &this->position, 0, 0);
                        } else {
                            this->state_step = 7;
                        }
                    } else {
                        this->state_step = 7;
                    }
                }
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 3:
            if (((TObjEneMe3SinowZoa *)&this->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                this->state_step = 4;
            }
        case 4:
            this->advance_animation();
            if (this->frame + this->play_speed >= lbl_805DF2F8) {
                if (this->behavior_flags & 0x100000) {
                    this->state_step = 5;
                } else {
                    this->state_step = 6;
                }
                this->clear_invulnerable();
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
                this->check_and_notify();
            }
            this->move_with_wall_slide_commit(this->destination_direction.x, this->destination_direction.z, this->m_444);
            break;
        case 5:
            if (this->frame > TObjEneMe3SinowZoa__data_805DF2F0 && this->fade.decay_value_toward_floor() != 0) {
                this->behavior_flags &= ~0x100000;
                this->state_step = 6;
                this->behavior_flags |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
        case 6:
            this->advance_animation();
            if (this->is_passing_frame((f32)25.0f) != 0 && this->enemy_check_target_valid() != 0) {
                if (this->current_target->select_melee_contact_body(this, TObjEneMe3SinowZoa__data_805DF2F4) != 0) {
                    this->current_target->receive_physical_attack(this, TObjEneMe3SinowZoa__data_805DF2F4);
                    this->current_target->apply_knockback_from_attacker((u8 *)this, 3.0f);
                }
            }
            this->m_444 *= 0.85f;
            this->move_with_wall_slide_on_ground(this->destination_direction.x, this->destination_direction.z, this->m_444);
            this->check_collisions();
            break;
        }
        break;
    case 5:
        this->body_y = this->position.y;
        this->body_offset_y = TObjEneMe3SinowZoa__data_805DF31C;
        this->clear_invulnerable();
        this->clear_field_388();
        break;
    }
}

#pragma pop

void TObjEneMe3SinowZoa::sub_80318C0C(s32 mode) {
    s32 var_r4;
    f32 temp_f1;

    switch (mode) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(0xC);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->behavior_flags |= 0x10000;
        this->behavior_flags |= 0x40000;
        this->clear_player_status_flag(0, 0x08000000);
        if (this->stealthed != 0) {
            ((TObjEneMe3SinowZoa *)&this->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
            this->fade.reset_obstruction_fade();
            this->behavior_flags |= 0x100000;
            this->state_step = 0;
        } else {
            this->state_step = 1;
        }
        this->state_timer = 0;
        return;
    case 3:
        if (this->state_step == 4) {
            this->behavior_flags |= 0x80000;
            this->select_next_attack_state();
        }
        return;
    case 0:
        switch (this->state_step) {
        case 0:
            if (((TObjEneMe3SinowZoa *)&this->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                this->state_step = 1;
            }
        case 1:
            this->advance_animation();
            this->sub_8031A6A0();
            if (this->frame < 20.0f) {
                if (((TObjEneEpsilon *)this)->update_death_check() != 0) {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    var_r4 = (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
                } else {
                    var_r4 = this->rotation_y;
                }
                this->rotation_y = approach_angle_limited(this->rotation_y, var_r4, 0x300);
                this->destination_direction.x = sin_table_lookup(this->rotation_y);
                this->destination_direction.z = cos_table_lookup(this->rotation_y);
            }
            this->vfunc_112();
            sub_80316840();
            temp_f1 = this->frame;
            if (temp_f1 >= TObjEneMe3SinowZoa__data_805DF31C && temp_f1 <= TObjEneMe3SinowZoa__data_805DF308) {
                TObjEneMe3SinowZoaParams *rec = TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index];
                this->move_to_shot_position(this->destination_direction.x, this->destination_direction.z, rec->m_8);
            } else {
                this->update_ground_contact();
            }
            if (this->get_flag_b4() != 0) {
                this->state_step = 2;
            }
            break;
        case 2:
            this->state_timer += 1;
            if (this->state_timer >= TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->m_20) {
                if (this->behavior_flags & 0x100000) {
                    this->state_step = 3;
                } else {
                    this->state_step = 4;
                }
            }
            this->update_ground_contact();
            break;
        case 3:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->state_step = 4;
                this->behavior_flags |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        this->check_collisions();
        break;
    case 5:
        break;
    }
}


void TObjEneMe3SinowZoa::sub_8031884C(s32 mode) {
    s32 temp_r5;
    s32 zero;

    switch (mode) {
    case 4:
        this->requested_action = 3;
        this->set_field_378(6);
        this->clear_intangible();
        zero = 0;
        this->behavior_flags &= 0xFFEFFFF8;
        this->m_3fc = zero;
        this->state_step = 3;
        if (this->acquire_target(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->m_43c = (s32) (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
            if (this->check_body_collision_at(this->m_43c + 0x8000, 80.0f) == 0) {
                this->destination_direction.x *= -1.0f;
                this->destination_direction.z *= -1.0f;
                this->state_step = 0;
                this->m_440 = (f32) 7.111111f;
            }
        }
        this->set_active();
        return;
    case 3:
        if (this->state_step == 3) {
            if ((this->stealthed == 0) && (this->random_ratio() <= this->stealth_on_chance)) {
                this->transition_enemy_state(0x11);
            } else if (this->random_ratio() <= this->technique_chance) {
                if (this->sub_8031A454() != 0) {
                    if (this->random_ratio() > TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->m_14) {
                        this->transition_enemy_state(0x10);
                    } else {
                        this->transition_enemy_state(0xB);
                    }
                } else {
                    this->transition_enemy_state(0x10);
                }
            } else if (this->random_ratio() <= this->warp_chance) {
                this->transition_enemy_state(0xC);
            } else {
                this->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_43c, 0x31C7);
            if ((this->frame + this->play_speed) >= TObjEneMe3SinowZoa__data_805DF2F0) {
                this->state_step = 1;
                this->set_invulnerable();
                play_sound_effect(0x4003A829, &this->position, 0, 0);
            }
            this->update_ground_contact();
            this->check_collisions();
            return;
        case 1:
            if ((this->frame + this->play_speed) >= 24.0f) {
                this->state_step = 2;
                this->clear_invulnerable();
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
                this->check_and_notify();
            }
            this->move_clamped_on_ground(this->destination_direction.x, this->destination_direction.z, this->m_440);
            return;
        case 2:
            if (this->get_flag_b4() != 0) {
                this->state_step = 3;
            }
            this->update_ground_contact();
            this->check_collisions();
            return;
        }
        break;
    case 5:
        this->clear_invulnerable();
        this->clear_field_388();
        break;
    }
}


void TObjEneMe3SinowZoa::sub_80318564(s32 mode) {
    switch (mode) {
    case 4:
        (this->requested_action) = 8;
        this->set_field_378(0xB);
        this->clear_intangible();
        (this->behavior_flags) &= 0xFFEFFFF8;
        if ((this->stealthed) != 0) {
            ((TObjEneMe3SinowZoa *)&this->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
            this->fade.reset_obstruction_fade();
            (this->behavior_flags) |= 0x100000;
            (this->behavior_flags) |= 0x40000;
            this->clear_player_status_flag(0, 0x08000000);
            (this->state_step) = 0;
        } else {
            (this->state_step) = 1;
        }
        (this->state_timer) = 0;
        break;
    case 3:
        if ((this->state_timer) > TObjEneMe3SinowZoa__kind_param_tbls[(this->kind_index)]->m_1c) {
            this->transition_enemy_state(6);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch ((this->state_step)) {
        case 0:
            this->advance_animation();
            if (((TObjEneMe3SinowZoa *)&this->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                (this->state_step) = 1;
            }
        case 1:
            if (this->get_flag_b4() != 0) {
                cast_technique();
                if (TObjEneDD::check_v2_mode() != 0) {
                    (this->state_step) = 3;
                } else if ((this->behavior_flags) & 0x100000) {
                    (this->state_step) = 4;
                } else {
                    (this->state_step) = 2;
                }
                (this->state_timer) = 0;
            }
            break;
        case 2:
            (this->state_timer)++;
            break;
        case 3:
            (this->state_timer)++;
            if ((this->state_timer) == 5) {
                TTecSifta::create(this, &this->position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[(this->kind_index)]->m_18));
            } else if ((this->state_timer) == 0xA) {
                TTecDeband::create(this, &this->position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[(this->kind_index)]->m_18));
                if ((this->behavior_flags) & 0x100000) {
                    (this->state_step) = 4;
                } else {
                    (this->state_step) = 2;
                }
                (this->state_timer) = 0;
            }
            break;
        case 4:
            if (this->fade.decay_value_toward_floor() != 0) {
                (this->state_step) = 2;
                (this->behavior_flags) |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        this->update_ground_contact();
        break;
    }
}

void TObjEneMe3SinowZoa::handle_state_substate(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 9;
        set_field_378(0xD);
        this->behavior_flags &= 0xFFEFFFF8;
        this->set_intangible();
        this->m_3fc = 0;
        this->state_step = 0;
        break;
    case 3:
        if (update_linked_position(200.0f) != 0) {
            this->transition_enemy_state(6);
        } else if (this->state_step >= 0x5A) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        (this->state_step)++;
        advance_animation();
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

void TObjEneMe3SinowZoa::sub_803182F8(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(6);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFFC;
        this->behavior_flags |= 4;
        this->fade.set_rate_from_divisor(0x1E);
        this->fade.reset_color();
        this->state_step = 1;
        break;
    case 3:
        if (this->state_step == 2) {
            this->transition_enemy_state(0);
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->state_step) {
        case 0:
            if (this->get_flag_b4() != 0) {
                this->state_step = 1;
            }
            break;
        case 1:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->state_step = 2;
            }
            break;
        }
        this->update_ground_contact();
        break;
    case 5:
        this->behavior_flags &= 0xFFFFFFFB;
        break;
    }
}

void TObjEneMe3SinowZoa::state_knockback(s32 mode) {
    Vec v;
    f32 len;
    switch (mode) {
    case 4:
        this->requested_action = 4;
        this->advance_animation();
        this->set_active();
        play_sound_effect(0x4003A82D, &this->position, 0, 0);
        this->behavior_flags &= 0xFFEFFFF8;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            if (this->stealthed == 1 && this->random_ratio() <= this->stealth_off_chance) {
                this->transition_enemy_state(0x12);
            } else {
                this->transition_enemy_state(this->next_mode);
            }
        }
        break;
    case 0:
        this->advance_animation();
        VecCopy(&v, velocity());
        len = normalize_vector_xz((Vec *)(&v));
        this->move_clamped_on_ground(v.x, v.z, len);
        this->x_speed *= 0.8f;
        this->m_310 *= 0.8f;
        this->check_collisions();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::sub_80317F90(s32 mode) {
    Vec v;
    Vec p;
    this->stealthed = 0;
    switch (mode) {
    case 3:
    case 5:
        break;
    case 4:
        this->requested_action = 5;
        this->refresh_and_send_entity_flags();
        this->disable_body_collision();
        this->behavior_flags &= 0xFFEFFFF8;
        this->state_step = 0;
        break;
    case 0:
        switch (this->state_step) {
        case 0:
            this->advance_animation();
            if (this->is_passing_frame(18.0f) != 0 || this->is_passing_frame(lbl_805DF300) != 0) {
                play_sound_effect(0x4003A82A, &this->position, 0, 0);
            }
            if (this->get_flag_b4() != 0) {
                this->state_step = 1;
                this->state_timer = 0;
                v.x = TObjEneMe3SinowZoa__data_805DF31C;
                v.y = TObjEneMe3SinowZoa__data_805DF314;
                v.z = 20.0f;
                rotate_y_and_translate(&v, &this->position, this->rotation_y);
                TObjPlayer::spawn_effect_f8((saddr)&v, 0x14);
            }
            break;
        case 1:
            this->state_timer += 1;
            if (this->state_timer >= 0x14) {
                this->state_step = 2;
                this->behavior_flags |= 2;
                TBoss3Volopt::create_breakup_mdl((saddr)TObjEneMe3SinowZoa__breakup_model, (saddr)&sinow_zoa_breakup_params, (s32)this->texlist, (saddr)&this->position, this->rotation_y);
                VecCopy(&p, &this->position);
                p.x += 20.0f * sin_table_lookup(this->rotation_y);
                p.z += 20.0f * cos_table_lookup(this->rotation_y);
                ((TObjPlayer *)(&p))->trigger_dell_biter_events();
                play_sound_effect(0x4003AD2E, &this->position, 0, 0);
            }
            this->update_ground_contact();
            break;
        case 2:
            this->queue_destruction();
            break;
        }
        break;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::sub_80317B50(s32 mode) {
    Vec v;
    Vec pos;
    Vec tmp;
    s32 d[3];
    s32 i;

    switch (mode) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(0xC);
        this->set_intangible();
        this->behavior_flags &= 0xFFEFFFF9;
        this->behavior_flags |= 1;
        this->state_step = 0;
        break;
    case 3:
        if (this->state_step == 2) {
            this->stealthed = 1;
            this->behavior_flags |= 0x40000;
            this->set_indexed_flags(0, 0x08000000);
            if (this->random_ratio() <= this->technique_chance) {
                if (this->sub_8031A454() != 0) {
                    if (this->random_ratio() > TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->m_14) {
                        this->transition_enemy_state(0x10);
                    } else {
                        this->transition_enemy_state(0xB);
                    }
                } else {
                    this->transition_enemy_state(0x10);
                }
            } else {
                this->transition_enemy_state(1);
            }
        }
        break;
    case 0:
        switch (this->state_step) {
        case 0:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->behavior_flags |= 4;
                play_sound_effect(0x4003AD2F, &this->position, 0, 0);
                this->fade.set_rate_from_divisor(0x1E);
                VecCopy(&v, &this->position);
                v.y = this->body_y - 20.0f;
                this->state_step = 1;
            }
            this->update_ground_contact();
            this->check_collisions();
            break;
        case 1:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->behavior_flags |= 2;
                if (this->update_linked_position(200.0f) != 0) {
                    if (this->current_target == NULL) {
                        break;
                    }
                    d[0] = (s32)(3.0f * this->random_ratio()) - 1;
                    d[1] = (s32)(2.0f * this->random_ratio()) - 1;
                    if (d[1] <= d[0]) {
                        d[1]++;
                    }
                    d[2] = -(d[0] + d[1]);
                    for (i = 0; i < 3; i++) {
                        s32 ang;
                        VecCopy(&pos, &this->current_target->position);
                        ang = this->current_target->rotation_y + ((d[i] + 1) << 14);
                        pos.x += 20.0f * cos_table_lookup(ang);
                        pos.z -= 20.0f * sin_table_lookup(ang);
                        pos.y += TObjEneMe3SinowZoa__data_805DF308;
                        VecCopy(&tmp, &pos);
                        tmp.x += pos.x - this->current_target->position.x;
                        tmp.z += pos.z - this->current_target->position.z;
                        if (check_move_collision(&tmp) == 0 &&
                            csnVector(&this->current_target->position, &tmp, 0x88E0) == 0 &&
                            csnVectorUnder(&pos, (CsnGroup **)&this->m_120, 0x15) != 0 &&
                            this->room == ((TScene *)(&pos))->find_section_at_position()) {
                            VecCopy(&this->position, &pos);
                            this->rotation_y = ang + 0xC000;
                            break;
                        }
                    }
                }
                this->state_step = 2;
            }
            break;
        }
        break;
    case 5:
        this->behavior_flags &= ~4;
        break;
    }
}

#pragma pop

void TObjEneMe3SinowZoa::render() {
    s32 mode;
    s32 draw;
    s32 i;

    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    sub_8031A454();
    if (this->behavior_flags & 2) {
        mode = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        mode = this->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, TObjEneMe3SinowZoa__data_805DF2F0);
    } else if (this->update_object_view_visibility(lbl_805DF318, TObjEneMe3SinowZoa__data_805DF2F0) != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    if (mode != 0) {
        if (this->render_model_if_visible() != 0) {
            return;
        }
        this->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        if (!(this->m_3d0 & 0x4000)) {
            this->vfunc_108();
            TObjEneDD::clear_global_flag_400();
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(this->texlist);
        for (i = 0; i < 3; i++) {
            if (TObjEneMe3SinowZoa__material_color_pointers[i] != NULL) {
                *TObjEneMe3SinowZoa__material_color_pointers[i] = this->material_color;
            }
        }
        draw = 1;
        if (this->try_run_effect_m6() != 0) {
            if (defer_render() != 0) {
                draw = 0;
            } else if (this->stealthed != 0) {
                draw = 0;
            }
        } else if (TObjEneMe3SinowZoa__sub_800D72A4(&this->fade) != 0) {
            this->fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw = 0;
            }
        } else if (this->stealthed != 0) {
            draw = 0;
        }
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(&this->position);
            translate_matrix(0, TObjEneMe3SinowZoa__data_805DF31C, this->body_offset_y, TObjEneMe3SinowZoa__data_805DF31C);
            rotate_matrix_y(0, this->rotation_y);
            TObjEneMe3SinowZoa__render_node_index = 0;
            if (mode == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            pop_matrix();
        }
        if (this->try_run_effect_m7() == 0 && TObjEneMe3SinowZoa__sub_800D72A4(&this->fade) != 0) {
            this->fade.clear_flag_and_notify();
        }
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
        this->update_primary_light();
    }
    TParticleCtrl::end_effect_render();
}

}

void TObjEneMe3SinowZoa::action() { if (get_target_info() != 0) { setup_move_bounds(); sub_8031A3D8(); } }

extern "C" {

s32 TObjEneMe3SinowZoa::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix(&this->m_3d4) != 0) {
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            post_translate_matrix(&this->position);
            translate_matrix(0, TObjEneMe3SinowZoa__data_805DF31C, this->body_offset_y, TObjEneMe3SinowZoa__data_805DF31C);
            rotate_matrix_y(0, this->rotation_y);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

void TObjEneMe3SinowZoa::render_demo() {
    s32 save[3];
    s32 flag;
    AnimationMotion *motion;
    f32 frame;
    if (get_target_info() != 0) {
        if (sub_8031A4D0() != 0) {
            debug_printf_at(pack_debug_text_position(0, 2), sinow_zoa_debug_stelth_enable);
        } else {
            debug_printf_at(pack_debug_text_position(0, 2), sinow_zoa_debug_stelth_disable);
        }
        if (is_outside_visible_range() != 0) {
            debug_printf_at(pack_debug_text_position(0xF, 2), sinow_zoa_debug_appear_ground);
        } else {
            debug_printf_at(pack_debug_text_position(0xF, 2), sinow_zoa_debug_appear_roof);
        }
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 4), (char *)sinow_zoa_debug_tecniq_attack);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 3), (char *)sinow_zoa_debug_stelth_on);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 6), (char *)sinow_zoa_debug_stelth_off);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 5), (char *)sinow_zoa_debug_warp);
        if (sub_8031A454() != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), sinow_zoa_debug_tex_spigell);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), sinow_zoa_debug_tex_berill);
        }
    }
    flag = sub_8031A454();
    if (update_object_view_visibility(lbl_805DF318, TObjEneMe3SinowZoa__data_805DF2F0) != 0) {
        TObjFish::set_global_param(texlist);
        TObjPlayer::toggle_particle_effect();
        if (flag != 0) {
            NJS_TEXNAME *parts = ((NJS_TEXLIST *)texlist)->textures;
            s32 i;
            for (i = 0; i < 3; i++) {
                save[i] = parts[i].texaddr;
            }
            for (i = 0; i < 3; i++) {
                parts[i].texaddr = parts[i + 3].texaddr;
            }
        }
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, TObjEneMe3SinowZoa__data_805DF2F4, TObjEneMe3SinowZoa__data_805DF2F4, TObjEneMe3SinowZoa__data_805DF2F4);
        {
            s32 i;
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3SinowZoa__material_color_pointers[i] != NULL) {
                    *TObjEneMe3SinowZoa__material_color_pointers[i] = 0xB000FFB0;
                }
            }
        }
        if (mode == 0) {
            s32 idx = requested_action;
            if (idx < 0) {
                idx = 0;
            } else if (idx >= 0xD) {
                idx = 0xC;
            }
            motion = motion_list[action_table[idx].motion].motion;
            frame = parameters[3];
            if (frame < TObjEneMe3SinowZoa__data_805DF31C) {
                frame = TObjEneMe3SinowZoa__data_805DF31C;
            } else if (frame > (motion->frameCount - 1)) {
                frame = (motion->frameCount - 1);
            }
            set_motion_packed_rotation();
            draw_model_motion(model, motion, frame);
            clear_motion_packed_rotation();
            current_motion = (NJS_MOTION *)motion;
            this->frame = frame;
            frame = get_node_height();
            print_float_padded(pack_debug_text_position(0, 7), 5, frame);
        } else {
            model_render_flags &= ~0x400;
        }
        pop_matrix();
        if (flag != 0) {
            s32 i;
            NJS_TEXNAME *parts = ((NJS_TEXLIST *)texlist)->textures;
            for (i = 0; i < 3; i++) {
                parts[i].texaddr = save[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneMe3SinowZoa::sub_80317254(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xC;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFFD;
        this->behavior_flags |= 5;
        this->fade.set_rate_from_divisor(0x1E);
        play_sound_effect(0x4003AD2F, &this->position, 0, 0);
        this->state_step = 0;
        break;
    case 3:
        if ((this->state_step == 1) && (this->fade.decay_value_toward_floor() != 0)) {
            this->stealthed = 1;
            this->transition_enemy_state(6);
            this->behavior_flags &= ~5;
            this->behavior_flags |= 0x40000;
            this->set_indexed_flags(0, 0x08000000);
            break;
        }
    case 5:
        break;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->state_step = 1;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

void TObjEneMe3SinowZoa::sub_803170F0(s32 mode) {
    switch (mode) {
    case 4:
        this->requested_action = 0xB;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFFD;
        this->behavior_flags |= 5;
        this->fade.set_rate_from_divisor(0x1E);
        this->stealthed = 0;
        this->behavior_flags |= 0x40000;
        this->clear_player_status_flag(0, 0x08000000U);
        this->state_step = 0;
        break;
    case 3:
        if ((this->state_step == 1) && (this->fade.advance_toward_max() != 0)) {
            this->transition_enemy_state(6);
            this->behavior_flags &= ~5;
            break;
        }
    case 5:
        break;
    case 0:
        this->advance_animation();
        if (this->get_flag_b4() != 0) {
            this->state_step = 1;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

inline s32 approach_80316C3C(TObjEneMe3SinowZoa *self) {
    copy_position_if_valid__10TObjPlayerFii(self, self->body_center);
    self->body_center.y += TObjEneMe3SinowZoa__data_805DF308;
    return ((TObjEnemy *)self)->enemy_turn_toward_dest(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->turn);
}
inline s32 seek_80316C3C(TObjEneMe3SinowZoa *self, Vec *diff) {
    s32 angle;
    if (select_enemy_destination(self, self->destination, 1) != 0) {
        angle = approach_80316C3C(self);
        enemy_set_heading_velocity(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->speed, self, self->rotation_y);
        move_with_wall_slide((u8 *)self);
    } else {
        VecCopy(diff, &self->destination);
        subtract_vector(diff, &self->body_center);
        angle = self->turn_toward_direction(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->turn, diff);
    }
    return angle;
}

void TObjEneMe3SinowZoa::sub_80316C3C(s32 mode) {
    s32 angle;
    Vec diff;
    Vec out;
    switch (mode) {
    case 5:
        break;
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(6);
        this->clear_intangible();
        this->behavior_flags &= 0xFFEFFFF8;
        this->behavior_flags |= 0x10000;
        this->enemy_copy_target_destination();
        this->state_step = 0;
        break;
    case 3:
        if (this->state_step == 5) {
            this->transition_enemy_state(6);
        }
        break;
    case 0:
        switch (this->state_step) {
        case 0:
        default:
            if (this->current_target == NULL) {
                this->transition_enemy_state(6);
                break;
            }
            angle = seek_80316C3C(this, &diff);
            if (angle < 0x100) {
                if (this->stealthed != 0) {
                    ((TObjEneMe3SinowZoa *)&this->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
                    this->fade.reset_obstruction_fade();
                    this->behavior_flags |= 0x100000;
                    this->behavior_flags |= 0x40000;
                    this->clear_player_status_flag(0, 0x08000000);
                    this->state_step = 1;
                } else {
                    this->state_step = 2;
                }
                this->requested_action = 8;
            } else {
                this->requested_action = 0xA;
            }
            break;
        case 1:
            this->advance_animation();
            if (((TObjEneMe3SinowZoa *)&this->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                this->state_step = 2;
            }
        case 2:
            this->advance_animation();
            if (this->get_flag_b4() != 0) {
                this->state_timer = 0;
                this->state_step = 3;
            }
            if (this->is_passing_frame(TObjEneMe3SinowZoa__data_805DF314) != 0) {
                this->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix(&this->position);
                rotate_matrix_y(0, this->rotation_y);
                set_motion_packed_rotation();
                this->calc_joint_matrices(TObjEneMe3SinowZoa__data_805DF314);
                clear_motion_packed_rotation();
                pop_matrix();
                push_matrix_from(anim_model_matrix_array[3]);
                Vec offset = lbl_80475FC8;
                matrix_mult_vec(0, &offset, &out);
                pop_matrix();
                if (this->current_target != NULL) {
                    VecCopy(&diff, &this->destination);
                    subtract_vector(&diff, &this->body_center);
                    angle = this->turn_toward_direction(((TObjEneMe3SinowZoaMoveParams *)this->movementParameters)->turn, &diff);
                } else {
                    angle = ((AttackParams *)this->m_318)->attack_angle;
                }
                if (angle < ((AttackParams *)this->m_318)->attack_angle / 2 && this->current_target != NULL) {
                    if (game_difficulty_selection == 3) {
                        TTecRaBarta::create((void *)this, (void *)(&out), (void *)(&this->position), TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->m_24));
                    } else {
                        TTecGiBarta::create_ex(this, &out, this->rotation_y, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[this->kind_index]->m_24));
                    }
                } else if (this->behavior_flags & 0x100000) {
                    this->state_step = 4;
                } else {
                    this->state_step = 5;
                }
            }
            break;
        case 3:
            if (++this->state_timer >= 0x28) {
                if (this->behavior_flags & 0x100000) {
                    this->state_step = 4;
                } else {
                    this->state_step = 5;
                }
            }
            break;
        case 4:
            if (this->fade.decay_value_toward_floor() != 0) {
                this->state_step = 5;
                this->behavior_flags |= 0x40000;
                this->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        break;
    }
    ((TObjPlayer *)this)->update_collisions();
}

s32 TObjEneMe3SinowZoa::check_move_collision(const Vec *pos) {
    CollisionBody *body;
    u32 r;
    u32 saved;
    Vec sp8;
    body = this->bodies;
    saved = body->flags;
    body->flags = 0x9D01U;
    VecCopy(&sp8, &this->position);
    VecCopy(&this->position, pos);
    TObjPlayer::init_all_slots();
    this->check_collisions();
    this->update_enemy_collision_flags();
    if (body->flags & 0x80000) {
        if (get_valid_target_player(get_entity_id(this->current_target)) == 0) {
            VecCopy(&this->position, &sp8);
            TObjPlayer::init_all_slots();
            return 1;
        }
    }
    if ((body->flags & 0x100000) && get_valid_target_player(this->entity_id) == 0) {
        VecCopy(&this->position, &sp8);
        TObjPlayer::init_all_slots();
        return 1;
    }
    r = (body->flags & 0x200000) != 0;
    VecCopy(&this->position, &sp8);
    TObjPlayer::init_all_slots();
    copy_collision_body(body, &sinow_zoa_collision_parts);
    body->flags = saved;
    return r;
}

f32 TObjEneMe3SinowZoa::receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32) {
    f32 damage = TObjChara::receive_direct_attack(source, payload, collider, -1, -1);
    if (this->stealthed == 1 && random_ratio() <= this->stealth_off_chance) {
        transition_enemy_state(0x12);
    } else if (mode == 2) {
        transition_enemy_state(6);
    }
    return damage;
}

void *TObjEneMe3SinowZoaReal::create_instance(void *set_data) {
    return new TObjEneMe3SinowZoaReal(tl_04, set_data);
}

TObjEneMe3SinowZoaReal::TObjEneMe3SinowZoaReal(TObject *parent, void *set_data) : TObjEneMe3SinowZoa(parent) {
    m_name = TObjEneMe3SinowZoaReal__name;
    invoke_initialization_hook(set_data);
    setup_move_bounds();
    init_enemy();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneMe3SinowZoaReal::~TObjEneMe3SinowZoaReal() {
}

void TObjEneMe3SinowZoaReal::run_death_reaction() { TObjEneMe3SinowZoa::run_death_reaction(); }

void TObjEneMe3SinowZoaReal::run_hit_reaction() { TObjEneMe3SinowZoa::run_hit_reaction(); }

void TObjEneMe3SinowZoaReal::select_next_attack_state() {
    this->m_3fc = this->m_3fc + 1;
    if ((this->m_3fc >= 2) || (this->random_ratio() < lbl_805DF304)) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(6);
}

void TObjEneMe3SinowZoaReal::on_target_lost() {  }

void TObjEneMe3SinowZoa::sub_80316840() {
    if ((this->is_passing_frame(TObjEneMe3SinowZoa__data_805DF2FC) != 0) || (this->is_passing_frame(lbl_805DF300) != 0)) {
        this->check_floor_contact(&this->position);
    }
}

void TObjEneMe3SinowZoa::check_and_notify() {
    s32 x;
    x = check_floor_contact(&position);
    if (x == 0) {
        spawn_particle_effect(&position, 243);
    }
}

s32 TObjEneMe3SinowZoa::check_floor_contact(const Vec *origin) {
    Vec v;
    CsnHit *hit;
    void *p;
    VecCopy(&v, origin);
    v.y += TObjEneMe3SinowZoa__data_805DF2F0;
    hit = csnVectorUnder(&v, (CsnGroup **)&this->m_120, 0x4007);
    if (hit != NULL) {
        this->m_3d0 = hit->contact->flags;
        if (this->m_3d0 & 0x4000) {
            VecCopy(&this->m_3d4, &hit->contact->point);
        } else {
            VecCopy(&this->m_3d4, &this->position);
        }
        if (hit->hit_mask & 4) {
            TObjEneGibbles__sub_800D8988(&this->position);
            p = spawn_particle_effect(&hit->contact[2].point, 0x49);
            if (p != 0) {
                attach_particle_model((u8 *)p, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, TObjEneMe3SinowZoa__data_805DF2F4);
            }
            spawn_particle_effect(&hit->contact[2].point, 0xA4);
            return 1;
        }
        if (hit->hit_mask & 2) {
            TObjEneGibbles__sub_800D8988(&this->position);
            p = spawn_particle_effect(&hit->contact[3].point, 0x49);
            if (p != 0) {
                attach_particle_model((u8 *)p, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, TObjEneMe3SinowZoa__data_805DF2F4);
            }
            spawn_particle_effect(&hit->contact[3].point, 0xA4);
            return 1;
        }
    }
    return 0;
}

}

const f32 TObjEneMe3SinowZoa__data_805DF2F0 = 15.0f;
const f32 TObjEneMe3SinowZoa__data_805DF2F4 = 1.0f;
const f32 lbl_805DF2F8 = 23.0f;
const f32 TObjEneMe3SinowZoa__data_805DF2FC = 12.0f;
const f32 lbl_805DF300 = 28.0f;
const f32 lbl_805DF304 = 0.5f;
const f32 TObjEneMe3SinowZoa__data_805DF308 = 5.0f;
const f32 TObjEneMe3SinowZoa__data_805DF30C = 0.05f;
const f32 TObjEneMe3SinowZoa__data_805DF310 = 0.2f;
const f32 TObjEneMe3SinowZoa__data_805DF314 = 10.0f;
const f32 lbl_805DF318 = 400.0f;
const f32 TObjEneMe3SinowZoa__data_805DF31C = 0.0f;
