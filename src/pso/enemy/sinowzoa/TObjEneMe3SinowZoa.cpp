#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_80087278.h"
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
#include "pso/enemy/recon/TObjEneRecon_8029E89C.h"
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
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/math/AngleUnits.h"
#include "pso/player/PlayerAttackParams.h"

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
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);

extern "C" {
void TObjEneGibbles__sub_800D8988(void *);
void TObjEneMe3SinowZoa__sub_80316840(TObjEneMe3SinowZoa *self);
void debug_printf_at(s32 id, const char *fmt, ...);
s32 scale_matrix(int, f32, f32, f32);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 select_enemy_destination(void *, Vec, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec);
s32 enemy_turn_toward_dest(void *, s32);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
void create__11TTecRaBartaFPvPvPvPv(void *, void *, void *, s32);
s32 matrix_mult_vec(int, void *, void *);
void TObjEneMe3SinowZoa__sub_80316C3C(TObjEneMe3SinowZoa *self, s32 arg1);
u16 get_entity_id(int);
u32 get_valid_target_player__10TNpcPlayerFv(int);
s32 check_move_collision__18TObjEneMe3SinowZoaFPvPv(TObjEneMe3SinowZoa *self, const Vec *pos);
s32 get_mode__11TCameraCtrlFPv(void *);
u32 get_item_field_6__10TObjPlayerFPv(void *);
f32 fabs_float(f32);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
s32 get_item_id__5TItemFv();
s32 check_v2_mode__9TObjEneDDFv(s32, s32);
void TObjEneDD__sub_800BA438(void *, void *);
s32 TObjEneMe3SinowZoa__sub_800D72A4(TUnk_80494938 *fade);
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
f32 * TBoss3Volopt__sub_800F059C(void *);
void create__10TTecDebandFlll(void *, void *, int);
void create__9TTecJelinFllll(void *, void *, void *, int);
void create_instance__9TTecZaruaFllll(void *, void *, void *, int);
void TObjEneMe3SinowZoa__sub_803170F0(TObjEneMe3SinowZoa *self, s32 arg1);
void TObjEneMe3SinowZoa__sub_80317254(TObjEneMe3SinowZoa *self, s32 arg1);
void TObjEneMe3SinowZoa__sub_80317B50(TObjEneMe3SinowZoa *self, s32 arg1);
void TObjEneMe3SinowZoa__sub_80317F90(TObjEneMe3SinowZoa *self, s32 arg1);
void TObjEneMe3SinowZoa__sub_803182F8(TObjEneMe3SinowZoa *self, s32);
void TObjEneMe3SinowZoa__sub_80318564(TObjEneMe3SinowZoa *self, s32);
void TObjEneMe3SinowZoa__sub_8031884C(TObjEneMe3SinowZoa *self, s32);
void TObjEneMe3SinowZoa__sub_80318C0C(TObjEneMe3SinowZoa *self, s32);
void TObjEneMe3SinowZoa__sub_80318F7C(TObjEneMe3SinowZoa *self, s32);
void TObjEneMe3SinowZoa__sub_80319748(TObjEneMe3SinowZoa *self, s32 arg1);
void TObjEneMe3SinowZoa__sub_80319B8C(TObjEneMe3SinowZoa *self, s32 arg1);
void compose_motion_node_matrix(void *arg0);
s32 is_main_phase_15__9TObjEneDDFv();
f64 atan2_float(f32, f32);
s32 enemy_validate_retained_target(u8 *arg0);
s32 free_bin_model_request(u32, s32);
void mem_free(void *p);
void *mem_alloc(u32 size);
BOOL is_split_screen(void);

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
extern const f32 lbl_805DF374;
extern const f32 lbl_805DF378;
extern f32 lbl_805DF37C;
extern f32 lbl_805DF380;
extern const f32 lbl_805DF384;
extern const f32 lbl_805DF388;
extern const f32 lbl_805DF38C;
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const u32 lbl_805DF368;
extern const f32 lbl_805DF36C;
extern const f32 lbl_805DF370;

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

}

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
        TObjEneMe3SinowZoa__bml_resource = (BmlResource *)load_enemy_bml_resource((u8 *)&bm_ene_me3_zoa_low_resource_descriptor);
    } else {
        TObjEneMe3SinowZoa__bml_resource = (BmlResource *)load_enemy_bml_resource((u8 *)&bm_ene_me3_shinowa_zoa_resource_descriptor);
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
    model = TObjEneMe3SinowZoa__bml_resource->models->model;
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
    breakup = (TUnk_8048FA00 *)::operator new(0x10);
    if (breakup != NULL) {
        breakup = TBreakUpMdl::init(breakup, TObjEneMe3SinowZoa__bml_resource->models->model, (s32)motion, motion->frameCount - 1);
    }
    TObjEneMe3SinowZoa__breakup_model = breakup;
    {
        DelDepthAnimationBinding info = lbl_80475FA8;
        info.motions = TObjEneMe3SinowZoa__bml_resource->motions;
        DelDepthAnimationBinding info_b = lbl_80475FB8;
        info_b.motions = TObjEneMe3SinowZoa__bml_resource->motions;
        TLobby::spawn_npc_enemy(0x49, TObjEneMe3SinowZoa__bml_resource->models->model, (NJS_TEXLIST *)TObjEneMe3SinowZoa__bml_resource->models->m_c, &info, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
        TLobby::spawn_npc_enemy(0x4A, TObjEneMe3SinowZoa__bml_resource->models->model, &TObjEneMe3SinowZoa__alternate_texture_list, &info, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
        TLobby::spawn_npc_enemy(0x4B, TObjEneMe3SinowZoa__bml_resource->models->model, (NJS_TEXLIST *)TObjEneMe3SinowZoa__bml_resource->models->m_c, &info_b, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
        TLobby::spawn_npc_enemy(0x4C, TObjEneMe3SinowZoa__bml_resource->models->model, &TObjEneMe3SinowZoa__alternate_texture_list, &info_b, TObjEneMe3SinowZoa__data_805DF2FC, TObjEneMe3SinowZoa__data_805DF31C);
    }
}

extern "C" {

int TObjEneMe3SinowZoaReal__create(void* p) { return (int)TObjEneMe3SinowZoaReal::create_instance(p); }

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
        free_bin_model_request((u32)TObjEneMe3SinowZoa__bml_resource, 1);
        TObjEneMe3SinowZoa__bml_resource = NULL;
    }
}

void TObjEneMe3SinowZoa::set_entry_value_clamped(s32 arg0, f32 farg0) {
    if (farg0 < lbl_805DF38C) {
        farg0 = lbl_805DF38C;
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
    this->set_field_d8((s32)lbl_804E8880);
    this->set_field_dc((s32)TObjEneMe3SinowZoa__bml_resource->motions);
    set_animation((this->requested_action));
    kind = this->m_3c8;
    reset_hp(lbl_80542FBC[kind], lbl_80542FC4[kind], lbl_80542FCC[kind]);
    this->check_state_flag_4();
    movementParameters = &TObjEneMe3SinowZoa_init_params;
    this->m_37c = TObjEneMe3SinowZoa__data_805DF314;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    this->m_3cc = 0;
    this->m_3d0 = 0;
    VecCopy(&m_3d4, &position);
    this->m_3e0 = (this->position.y);
    this->m_3e4 = TObjEneMe3SinowZoa__data_805DF31C;
    m_3f8 = 0;
    this->m_3fc = 0;
    this->m_404 = (s16) this->m_2cc;
    fade.reset_obstruction_fade();
    this->m_434 = 0;
    this->m_438 = 0;
    this->m_43c = 0;
    this->m_440 = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_444 = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_448 = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_44c = TObjEneMe3SinowZoa__data_805DF31C;
    this->m_450 = TObjEneMe3SinowZoa__data_805DF31C;
    unk_454 = NULL;
    unk_458 = NULL;
    if (this->m_3c0 == 1) {
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
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    }
    sub_8031AC74();
    this->copy_pos_with_height_offset();
    this->vfunc_88();
    temp_r3 = this->m_3cc;
    if (temp_r3 & 0x40000) {
        this->m_3cc = (s32) (temp_r3 & 0xFFFBFFFF);
    } else {
        submit_default_cursor_candidate();
    }
    if ((this->m_3c0 == 0) || (TObjEneMe3SinowZoa__sub_800D72A4(&fade) != 0)) {
        this->vfunc_100();
    }
    if (this->m_3d0 & 0x4000) {
        TObjEneRecon::set_active();
    }
}

void TObjEneMe3SinowZoa::sub_8031AC74() {
    s32 temp_r3;
    s32 temp_r3_2;
    if (actorFlags & 0x24) {
        if ((this->m_3c0 != 0) || (temp_r3 = this->m_3cc, (((temp_r3 & 0x100000) == 0) == 0)) || (temp_r3 & 4)) {
            this->m_3cc |= 4;
            if (fade.advance_toward_max() != 0) {
                this->m_3c0 = 0;
                this->m_3cc &= 0xFFEFFFFB;
                this->m_3cc |= 0x40000;
                clear_player_status_flag(0, 0x08000000);
            }
        }
        if ((s16) this->mode == 0x11) {
            transition_enemy_state(0x12);
        }
    } else {
        temp_r3_2 = this->m_3cc;
        if (!(temp_r3_2 & 0x100000) && !(temp_r3_2 & 4) && (TObjEneMe3SinowZoa__sub_800D72A4(&fade) != 0)) {
            if (this->m_3c0 != 0) {
                if (fade.decay_value_toward_floor() != 0) {
                    this->m_3cc |= 0x40000;
                    set_indexed_flags(0, 0x08000000);
                }
            } else if (fade.advance_toward_max() != 0) {
                this->m_3cc |= 0x40000;
                clear_player_status_flag(0, 0x08000000);
            }
        }
    }
}

void TObjEneMe3SinowZoa::vfunc_28() {  }

void TObjEneMe3SinowZoa::vfunc_63() { if (this->mode != 15) { transition_enemy_state(15); } }

void TObjEneMe3SinowZoa::vfunc_62() {
    if (this->m_3cc & 1) {
        clear_attack_receipts();
        if ((this->m_3c0 == 1) && (random_ratio() <= this->stealth_off_chance)) {
            transition_enemy_state(0x12);
        }
    } else if ((s16) this->mode != 0xE) {
        transition_enemy_state(0xE);
    }
}

void TObjEneMe3SinowZoa::vfunc_61() {  }

void TObjEneMe3SinowZoa::copy_pos_with_height_offset() {
    VecCopy(body_center(), &position);
    this->m_300 = this->m_300 + (TObjEneMe3SinowZoa__data_805DF2FC + this->m_3e4);
    VecCopy(&center, &position);
}

void TObjEneMe3SinowZoa::vfunc_88() {
    bodies->offset.y = this->m_300 - this->position.y;
}

void TObjEneMe3SinowZoa::vfunc_95() { TObjEneDD::vfunc_95(); sub_800F5874(38); }

void TObjEneMe3SinowZoa::vfunc_96() { TObjEneDD::vfunc_96(); sub_800F5864(38); }

void TObjEneMe3SinowZoa::setup_move_bounds() {
    if (sub_8031A4D0() != 0) {
        this->m_3c0 = 1;
    } else {
        this->m_3c0 = 0;
    }
    this->m_3c4 = is_outside_visible_range();
    if (this->m_3c4 == 1) {
        this->requested_action = 2;
    } else {
        this->requested_action = 0;
    }
    this->technique_chance = lbl_805DF388 + this->parameters[2];
    this->stealth_on_chance = 0.3f + this->parameters[1];
    this->stealth_off_chance = lbl_805DF38C + this->parameters[4];
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

bool TObjEneMe3SinowZoa__sub_8031A820(TObjEneMe3SinowZoa *self) {
    f32 temp_f31;
    if (fabs_float(self->m_390->position.y - self->position.y) >= 20.0f) {
        if (self->random_ratio() <= self->warp_chance) {
            self->transition_enemy_state(0xC);
            goto block_4;
        }
        return 0;
    }
block_4:
    if (self->m_3ac > 25.0f) {
        return 0;
    }
    temp_f31 = (self->m_3a0.x * sin_table_lookup(self->rotation_y)) + (self->m_3a0.z * cos_table_lookup(self->rotation_y));
    return (temp_f31 < cos_table_lookup(0x1E00)) == 0;
}

#pragma pop

void TObjEneMe3SinowZoa::sub_8031A6A0() {
    f32 d;
    s32 near;
    TObjChara *pl;
    near = is_passing_frame(lbl_805DF2F8);
    if (is_passing_frame(TObjEneMe3SinowZoa__data_805DF2F0) != 0 || near != 0) {
        if (enemy_check_target_valid() != 0) {
            if (m_390->select_melee_contact_body(this, TObjEneMe3SinowZoa__data_805DF2F4) != 0) {
                d = m_390->receive_physical_attack(this, TObjEneMe3SinowZoa__data_805DF2F4);
                m_390->apply_knockback_from_attacker((u8 *)this, 3.0f);
                if (d > TObjEneMe3SinowZoa__data_805DF31C) {
                    if (sub_8031A454() != 0) {
                        pl = m_390;
                        if (TObjPlayer::is_locally_controlled(pl) != 0 && get_item_field_6__10TObjPlayerFPv(pl) != 0) {
                            TObjPlayer::send_6x26_unequip_item(pl, (void *)get_item_id__5TItemFv());
                            ((TObjPlayer *)pl)->get_hand_joint_position((s32)&unk_408);
                            spawn_particle_effect(&unk_408, 0x1D0);
                        }
                    } else if (near != 0 && this->random_ratio() <= lbl_805DF384) {
                        TObjEneDD__sub_800BA438(this, m_390);
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
    if (!(this->m_3cc & 0x10000)) {
        temp_f1 = this->m_3ac;
        if ((temp_f1 > lbl_805DF37C) && (temp_f1 < lbl_805DF380) && (this->check_body_collision_at(this->rotation_y, temp_f1 - 20.0f) == 0)) {
            var_r31 = 1;
        }
    }
    return var_r31;
}

void TObjEneMe3SinowZoa::vfunc_107() {  }

s32 TObjEneMe3SinowZoa::try_run_effect_m6() {
    if (this->m_3cc & 4) {
        fade.set_flags_and_apply_damage_color();
        return 1;
    }
    return 0;
}

s32 TObjEneMe3SinowZoa::try_run_effect_m7() {
    if (this->m_3cc & 4) {
        fade.clear_flag_and_notify();
        return 1;
    }
    return 0;
}

void TObjEneMe3SinowZoa::vfunc_111() {  }

void TObjEneMe3SinowZoa::vfunc_112() {  }

void TObjEneMe3SinowZoa::update_distance_state() {
    f32 thr = lbl_805DF378;
    if ((this->m_3e0 - this->position.y) > thr) {
        vfunc_97();
        return;
    }
    vfunc_98();
}

void TObjEneMe3SinowZoa::vfunc_89() {
    vfunc_88();
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

s32 TObjEneMe3SinowZoa::vfunc_104(f32 arg1) { return select_and_apply_target(arg1); }

s32 TObjEneMe3SinowZoa::sub_8031A454() {
    u8 r = this->m_400 >= 1;
    return r;
}

void TObjEneMe3SinowZoa::sub_8031A3D8() {
    if (sub_8031A454() != 0) {
        texlist = (s32)&TObjEneMe3SinowZoa__alternate_texture_list;
        initialize_enemy_state(0x46);
        this->m_3c8 = 1;
        return;
    }
    texlist = TObjEneMe3SinowZoa__bml_resource->models->m_c;
    initialize_enemy_state(0x45);
    this->m_3c8 = 0;
}

void cast_technique__18TObjEneMe3SinowZoaFPv(u8 *arg0) {
    s32 lv;
    lv = TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[((TObjEneMe3SinowZoa *)arg0)->m_3c8]->m_18);
    if (((TObjEneMe3SinowZoa *)arg0)->sub_8031A454() != 0) {
        if (game_difficulty_selection == 3) {
            TTecSifta::create((void *)arg0, arg0 + 0x38, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[((TObjEneMe3SinowZoa *)arg0)->m_3c8]->m_18)));
            create__10TTecDebandFlll(arg0, &((TObjEneMe3SinowZoa *)arg0)->position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[((TObjEneMe3SinowZoa *)arg0)->m_3c8]->m_18));
        } else {
            create_instance__9TTecZaruaFllll(arg0, arg0 + 0x38, arg0 + 0x38, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[((TObjEneMe3SinowZoa *)arg0)->m_3c8]->m_18));
            create__9TTecJelinFllll(arg0, arg0 + 0x38, arg0 + 0x38, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[((TObjEneMe3SinowZoa *)arg0)->m_3c8]->m_18));
        }
    } else {
        TTecResta::create(arg0, &((TObjEneMe3SinowZoa *)arg0)->position, (void *)lv);
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
        TObjEneMe3SinowZoa__sub_80319B8C(this, mode);
        return;
    case 2:
        state_chase(mode);
        return;
    case 4:
        update_state_action(mode);
        return;
    case 5:
        TObjEneMe3SinowZoa__sub_80319748(this, mode);
        return;
    case 6:
        state_chase_target(mode);
        return;
    case 7:
        TObjEneMe3SinowZoa__sub_80318F7C(this, mode);
        return;
    case 8:
        TObjEneMe3SinowZoa__sub_80318C0C(this, mode);
        return;
    case 9:
        TObjEneMe3SinowZoa__sub_8031884C(this, mode);
        return;
    case 13:
        handle_state_substate(mode);
        return;
    case 10:
        TObjEneMe3SinowZoa__sub_803182F8(this, mode);
        return;
    case 11:
        TObjEneMe3SinowZoa__sub_80318564(this, mode);
        return;
    case 14:
        state_knockback(mode);
        return;
    case 15:
        TObjEneMe3SinowZoa__sub_80317F90(this, mode);
        return;
    case 12:
        TObjEneMe3SinowZoa__sub_80317B50(this, mode);
        return;
    case 16:
        TObjEneMe3SinowZoa__sub_80316C3C(this, mode);
        return;
    case 17:
        TObjEneMe3SinowZoa__sub_80317254(this, mode);
        return;
    case 18:
        TObjEneMe3SinowZoa__sub_803170F0(this, mode);
    default:
        return;
    }
}

void TObjEneMe3SinowZoa::action(s32 arg1) {
    s32 temp_r3;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        if (this->m_3c4 == 1) {
            this->requested_action = 2;
            set_field_378(1);
        } else {
            this->requested_action = 0;
            set_field_378(3);
        }
        vfunc_95();
        temp_r4 = this->m_3cc;
        this->m_3cc = (s32) (temp_r4 | 2);
        temp_r3 = this->m_3cc;
        this->m_3cc = (s32) (temp_r3 & 0xFFEFFFFA);
        if (check_v2_mode__9TObjEneDDFv(temp_r3, temp_r4) != 0) {
            this->m_3cc &= 0xFFFEFFFF;
        }
        this->m_434 = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy(body_center(), &home_position);
        this->m_3e0 = this->position.y;
        this->m_3f8 = 0;
        this->m_3fc = 0;
        return;
    case 3:
        if (this->m_434 > 5) {
            if (this->m_3c4 == 1) {
                this->transition_enemy_state(1);
            } else {
                this->transition_enemy_state(3);
            }
        }
    case 5:
        return;
    case 0:
        this->m_434 += 1;
        if (this->m_434 == 1) {
            this->m_3e0 = this->position.y;
            vfunc_102();
            this->m_3e4 = this->m_3e0 - this->position.y;
        }
        break;
    }
}

void TObjEneMe3SinowZoa::sub_80319E74(s32 arg1) {
    Vec v;
    f32 t;
    switch (arg1) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(0);
        this->vfunc_95();
        this->m_3cc &= 0xFFEFFFFD;
        this->m_3cc |= 5;
        this->fade.start_fade_in();
        VecCopy(&v, &this->position);
        t = this->m_3e0;
        v.y = t - 20.0f;
        if (this->m_3c0 == 0) {
            TBoss3Volopt__sub_800D8D88(&v, t);
        } else {
            create_timed_particle_emitter(&this->position, 0x79, 0, 0xF);
        }
        break;
    case 3:
        if (this->fade.advance_toward_max() != 0) {
            if (this->m_3c0 == 1) {
                this->transition_enemy_state(2);
            } else {
                this->transition_enemy_state(0xD);
            }
        }
        break;
    case 0:
        if (*TBoss3Volopt__sub_800F059C(&this->fade) >= lbl_805DF374) {
            this->advance_animation();
        }
        this->vfunc_102();
        this->vfunc_89();
        break;
    case 5:
        this->m_3cc &= ~4;
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::state_chase(s32 arg1) {
    s32 temp_r0;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        this->requested_action = 9;
        this->set_field_378(0xD);
        this->vfunc_96();
        this->m_3cc &= 0xFFEFFFF8;
        this->m_434 = 0;
        this->m_438 = 0;
        this->m_444 = TObjEneMe3SinowZoa__data_805DF31C;
        return;
    case 3:
        if (this->vfunc_104(200.0f) != 0) {
            if (this->m_3ac <= lbl_805DF36C) {
                this->transition_enemy_state(0xD);
                return;
            }
            temp_r0 = this->m_438 - 1;
            this->m_438 = temp_r0;
            if ((temp_r0 <= 0) && (this->is_target_in_range() != 0)) {
                this->m_438 = 0x3C;
                if (this->random_ratio() <= lbl_805DF370) {
                    this->transition_enemy_state(7);
                    return;
                }
            }
        } else if (this->m_434 >= 0xE10) {
            this->transition_enemy_state(0xD);
            return;
        }
        break;
    case 5:
        break;
    case 0:
        (this->m_434)++;
        this->advance_animation();
        if (this->update_linked_position(200.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            this->m_444 = (this->m_3a0.x * sin_table_lookup(this->rotation_y)) + (this->m_3a0.z * cos_table_lookup(this->rotation_y));
            if (this->m_444 < cos_table_lookup(0x1000)) {
                this->turn_toward_target_direction(0x500);
                this->vfunc_102();
            }
        }
        this->vfunc_89();
        break;
    }
}

void TObjEneMe3SinowZoa__sub_80319B8C(TObjEneMe3SinowZoa *self, s32 arg1) {
    Vec v;
    f32 temp_f1;
    switch (arg1) {
    case 4:
        self->requested_action = 0;
        self->set_field_378(0);
        self->vfunc_95();
        self->m_3cc |= 7;
        self->fade.start_fade_in();
        VecCopy(&v, &self->position);
        temp_f1 = self->m_3e0;
        v.y = temp_f1 - TObjEneMe3SinowZoa__data_805DF314;
        TBoss3Volopt__sub_800D8D88(&v, temp_f1);
        break;
    case 3:
        if (self->fade.advance_toward_max() != 0) {
            self->transition_enemy_state(4);
            break;
        }
    case 0:
        break;
    case 5:
        self->m_3cc &= 0xFFFFFFFB;
        break;
    }
}

#pragma pop

void TObjEneMe3SinowZoa::update_state_action(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        set_field_378(5);
        this->vfunc_95();
        this->m_3cc &= 0xFFEFFFF8;
        this->m_434 = 0;
        this->m_438 = 0;
        break;
    case 3:
        if (this->m_434 > 0x1E) {
            this->transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        if (this->m_434 == 0) {
            if (update_linked_position(200.0f) != 0) {
                this->m_434 = 1;
                this->m_3f8 = 0x1C00FFFF;
                this->m_3f8 &= lbl_805DF368;
                this->m_438 = 0;
            }
        } else {
            (this->m_434)++;
            this->m_438 += 0x10;
            if (this->m_438 > 0xFF) {
                this->m_438 = 0xFF;
            }
            this->m_3f8 = (this->m_438 << 24) | (this->m_3f8 & 0xFFFFFF);
            if (enemy_validate_retained_target((u8 *)this) == 0) {
                this->m_434 = 0;
                this->m_3f8 = 0;
            }
        }
        this->vfunc_102();
        update_distance_state();
        this->vfunc_89();
        this->m_3e4 = this->m_3e0 - this->position.y;
        break;
    case 5:
        this->m_3f8 = 0x1C00FFFF;
        this->m_3e4 = TObjEneMe3SinowZoa__data_805DF31C;
        break;
    }
}

void TObjEneMe3SinowZoa__sub_80319748(TObjEneMe3SinowZoa *self, s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f31;

    switch (arg1) {
    case 4:
        self->requested_action = 1;
        self->set_field_378(0xD);
        self->vfunc_96();
        self->m_3cc &= 0xFFEFFFF9;
        self->m_3cc |= 1;
        self->m_434 = 0;
        self->m_440 = TObjEneMe3SinowZoa__data_805DF31C;
        if (self->enemy_has_live_target() != 0) {
            self->enemy_copy_target_destination();
            self->update_velocity();
        }
        break;
    case 3:
        if (self->m_434 == 3) {
            self->transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (self->m_434) {
        case 0:
            temp_f31 = self->get_node_height();
            self->advance_animation();
            self->m_444 = self->get_node_height();
            self->m_3e0 = self->m_3e0 + (temp_f31 - self->m_444);
            self->m_434 = 1;
            self->m_3e4 = self->m_3e0 - self->position.y;
            break;
        case 1:
            self->advance_animation();
            if (self->frame > 29.0f) {
                self->frame = 29.0f;
            }
            self->m_440 -= 0.3f;
            if (self->m_440 < -5.0f) {
                self->m_440 = -5.0f;
            }
            self->m_3e0 = self->m_3e0 + self->m_440;
            temp_f1 = self->get_node_height();
            self->m_3e0 = self->m_3e0 - (temp_f1 - self->m_444);
            self->m_444 = temp_f1;
            if (self->m_3e0 < self->position.y) {
                self->m_3e0 = self->position.y;
                self->m_434 = 2;
                play_sound_effect(0x4003A82A, &self->position, 0, 0);
                self->check_and_notify();
            }
            break;
        case 2:
            if (self->get_flag_b4() != 0) {
                self->requested_action = 9;
                self->m_434 = 3;
                self->m_3e0 = self->position.y;
                self->m_3e4 = TObjEneMe3SinowZoa__data_805DF31C;
            }
            self->advance_animation();
            break;
        }
        self->vfunc_102();
        self->update_distance_state();
        self->vfunc_89();
        self->m_3e4 = self->m_3e0 - self->position.y;
        break;
    case 5:
        self->m_3cc &= 0xFFFFFFFE;
        self->m_3e4 = TObjEneMe3SinowZoa__data_805DF31C;
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa::state_chase_target(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 0xA;
        this->set_field_378(6);
        this->vfunc_96();
        this->m_3cc &= 0xFFEFFFF8;
        this->m_3ac = (f32) 300.0f;
        this->m_440 = (f32) TObjEneMe3SinowZoa__kind_param_tbls[this->m_3c8]->m_0;
        this->m_444 = TObjEneMe3SinowZoa__data_805DF31C;
        return;
    case 3:
        if (this->m_390 == NULL) {
            this->vfunc_111();
            this->transition_enemy_state(0xD);
            return;
        }
        if (((s32 (*)(f32))TObjEneMe3SinowZoa__sub_8031A820)(this->m_444) != 0) {
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
            TObjEneMe3SinowZoa__sub_80316840(this);
            this->m_444 = (this->m_3a0.x * sin_table_lookup(this->rotation_y)) + (this->m_3a0.z * cos_table_lookup(this->rotation_y));
            if (this->m_444 < cos_table_lookup(0x1000)) {
                this->turn_toward_target_direction(0x500);
                this->vfunc_102();
            } else {
                enemy_turn_and_move_on_ground((u8 *)this, 0x500, this->m_440);
            }
            this->vfunc_89();
        }
        break;
    }
}

void TObjEneMe3SinowZoa__sub_80318F7C(TObjEneMe3SinowZoa *self, s32 arg1) {
    switch (arg1) {
    case 4:
        self->requested_action = 6;
        self->set_field_378(6);
        self->vfunc_96();
        self->m_3cc &= 0xFFEFFFF8;
        self->m_3cc |= 0x10000;
        self->m_434 = 0;
        self->m_440 = TObjEneMe3SinowZoa__data_805DF31C;
        self->set_active();
        break;
    case 3:
        if (self->m_434 == 7 || self->get_flag_b4() != 0) {
            if (self->vfunc_102() == 0) {
                self->transition_enemy_state(10);
            } else {
                self->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        switch ((u32)self->m_434) {
        case 0:
            self->advance_animation();
            if (self->motion_flags & 8) {
                self->m_434 = 1;
            }
            self->vfunc_102();
            self->vfunc_89();
            break;
        case 1: {
            s32 target;
            self->advance_animation();
            if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
                self->enemy_copy_target_destination();
                self->update_velocity();
                target = (s32)(RADIANS_TO_ANGLE * atan2_float(self->m_3a0.x, self->m_3a0.z));
            } else {
                target = self->rotation_y;
            }
            self->rotation_y = approach_angle_limited(self->rotation_y, target, 0x1000);
            if (self->is_passing_frame(TObjEneMe3SinowZoa__data_805DF314) != 0) {
                self->m_434 = 2;
            }
            self->vfunc_102();
            self->vfunc_89();
            break;
        }
        case 2:
            self->advance_animation();
            if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
                self->enemy_copy_target_destination();
                self->update_velocity();
            }
            if (self->frame + self->play_speed >= 14.0f) {
                if (self->check_body_collision_at(self->rotation_y, self->m_3ac - 20.0f) != 0) {
                    self->m_434 = 7;
                } else {
                    Vec v;
                    f32 d = self->m_3ac - 20.0f;
                    VecCopy(&v, &self->position);
                    v.x = self->m_3a0.x * d + v.x;
                    v.y += 20.0f;
                    v.z = self->m_3a0.z * d + v.z;
                    if (csnVecterUnder((s32)&v, 0x15) != 0) {
                        if (self->room == ((TScene *)(&v))->find_section_at_position()) {
                            if (self->m_3c0 != 0) {
                                ((TObjEneMe3SinowZoa *)&self->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
                                self->fade.reset_obstruction_fade();
                                self->m_3cc |= 0x100000;
                                self->m_3cc |= 0x40000;
                                self->clear_player_status_flag(0, 0x08000000);
                                self->m_434 = 3;
                            } else {
                                self->m_434 = 4;
                            }
                            self->m_444 = (self->m_3ac - 20.0f) / 12.857143f;
                            self->vfunc_91();
                            play_sound_effect(0x4003A82C, &self->position, 0, 0);
                        } else {
                            self->m_434 = 7;
                        }
                    } else {
                        self->m_434 = 7;
                    }
                }
            }
            self->vfunc_102();
            self->vfunc_89();
            break;
        case 3:
            if (((TObjEneMe3SinowZoa *)&self->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                self->m_434 = 4;
            }
        case 4:
            self->advance_animation();
            if (self->frame + self->play_speed >= lbl_805DF2F8) {
                if (self->m_3cc & 0x100000) {
                    self->m_434 = 5;
                } else {
                    self->m_434 = 6;
                }
                self->vfunc_92();
                play_sound_effect(0x4003A82A, &self->position, 0, 0);
                self->check_and_notify();
            }
            self->move_with_wall_slide_commit(self->m_3a0.x, self->m_3a0.z, self->m_444);
            break;
        case 5:
            if (self->frame > TObjEneMe3SinowZoa__data_805DF2F0 && self->fade.decay_value_toward_floor() != 0) {
                self->m_3cc &= ~0x100000;
                self->m_434 = 6;
                self->m_3cc |= 0x40000;
                self->set_indexed_flags(0, 0x08000000);
            }
        case 6:
            self->advance_animation();
            if (self->is_passing_frame((f32)25.0f) != 0 && self->enemy_check_target_valid() != 0) {
                if (self->m_390->select_melee_contact_body(self, TObjEneMe3SinowZoa__data_805DF2F4) != 0) {
                    self->m_390->receive_physical_attack(self, TObjEneMe3SinowZoa__data_805DF2F4);
                    self->m_390->apply_knockback_from_attacker((u8 *)self, 3.0f);
                }
            }
            self->m_444 *= 0.85f;
            self->move_with_wall_slide_on_ground(self->m_3a0.x, self->m_3a0.z, self->m_444);
            self->vfunc_89();
            break;
        }
        break;
    case 5:
        self->m_3e0 = self->position.y;
        self->m_3e4 = TObjEneMe3SinowZoa__data_805DF31C;
        self->vfunc_92();
        self->clear_field_388();
        break;
    }
}

#pragma pop

void TObjEneMe3SinowZoa__sub_80318C0C(TObjEneMe3SinowZoa *self, s32 arg1) {
    s32 var_r4;
    f32 temp_f1;

    switch (arg1) {
    case 4:
        self->requested_action = 7;
        self->set_field_378(0xC);
        self->vfunc_96();
        self->m_3cc &= 0xFFEFFFF8;
        self->m_3cc |= 0x10000;
        self->m_3cc |= 0x40000;
        self->clear_player_status_flag(0, 0x08000000);
        if (self->m_3c0 != 0) {
            ((TObjEneMe3SinowZoa *)&self->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
            self->fade.reset_obstruction_fade();
            self->m_3cc |= 0x100000;
            self->m_434 = 0;
        } else {
            self->m_434 = 1;
        }
        self->m_438 = 0;
        return;
    case 3:
        if (self->m_434 == 4) {
            self->m_3cc |= 0x80000;
            self->vfunc_107();
        }
        return;
    case 0:
        switch (self->m_434) {
        case 0:
            if (((TObjEneMe3SinowZoa *)&self->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                self->m_434 = 1;
            }
        case 1:
            self->advance_animation();
            self->sub_8031A6A0();
            if (self->frame < 20.0f) {
                if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
                    self->enemy_copy_target_destination();
                    self->update_velocity();
                    var_r4 = (s32) (RADIANS_TO_ANGLE * atan2_float(self->m_3a0.x, self->m_3a0.z));
                } else {
                    var_r4 = self->rotation_y;
                }
                self->rotation_y = approach_angle_limited(self->rotation_y, var_r4, 0x300);
                self->m_3a0.x = sin_table_lookup(self->rotation_y);
                self->m_3a0.z = cos_table_lookup(self->rotation_y);
            }
            self->vfunc_112();
            TObjEneMe3SinowZoa__sub_80316840(self);
            temp_f1 = self->frame;
            if (temp_f1 >= TObjEneMe3SinowZoa__data_805DF31C && temp_f1 <= TObjEneMe3SinowZoa__data_805DF308) {
                TObjEneMe3SinowZoaParams *rec = TObjEneMe3SinowZoa__kind_param_tbls[self->m_3c8];
                self->move_to_shot_position(self->m_3a0.x, self->m_3a0.z, rec->m_8);
            } else {
                self->vfunc_102();
            }
            if (self->get_flag_b4() != 0) {
                self->m_434 = 2;
            }
            break;
        case 2:
            self->m_438 += 1;
            if (self->m_438 >= TObjEneMe3SinowZoa__kind_param_tbls[self->m_3c8]->m_20) {
                if (self->m_3cc & 0x100000) {
                    self->m_434 = 3;
                } else {
                    self->m_434 = 4;
                }
            }
            self->vfunc_102();
            break;
        case 3:
            if (self->fade.decay_value_toward_floor() != 0) {
                self->m_434 = 4;
                self->m_3cc |= 0x40000;
                self->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        self->vfunc_89();
        break;
    case 5:
        break;
    }
}


void TObjEneMe3SinowZoa__sub_8031884C(TObjEneMe3SinowZoa *self, s32 arg1) {
    s32 temp_r5;
    s32 zero;

    switch (arg1) {
    case 4:
        self->requested_action = 3;
        self->set_field_378(6);
        self->vfunc_96();
        zero = 0;
        self->m_3cc &= 0xFFEFFFF8;
        self->m_3fc = zero;
        self->m_434 = 3;
        if (self->vfunc_104(200.0f) != 0) {
            self->enemy_copy_target_destination();
            self->update_velocity();
            self->m_43c = (s32) (RADIANS_TO_ANGLE * atan2_float(self->m_3a0.x, self->m_3a0.z));
            if (self->check_body_collision_at((int) (self->m_43c + 0x8000), 80.0f) == 0) {
                self->m_3a0.x *= -1.0f;
                self->m_3a0.z *= -1.0f;
                self->m_434 = 0;
                self->m_440 = (f32) 7.111111f;
            }
        }
        self->set_active();
        return;
    case 3:
        if (self->m_434 == 3) {
            if ((self->m_3c0 == 0) && (self->random_ratio() <= self->stealth_on_chance)) {
                self->transition_enemy_state(0x11);
            } else if (self->random_ratio() <= self->technique_chance) {
                if (self->sub_8031A454() != 0) {
                    if (self->random_ratio() > TObjEneMe3SinowZoa__kind_param_tbls[self->m_3c8]->m_14) {
                        self->transition_enemy_state(0x10);
                    } else {
                        self->transition_enemy_state(0xB);
                    }
                } else {
                    self->transition_enemy_state(0x10);
                }
            } else if (self->random_ratio() <= self->warp_chance) {
                self->transition_enemy_state(0xC);
            } else {
                self->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        self->advance_animation();
        switch (self->m_434) {
        case 0:
            self->rotation_y = approach_angle_limited(self->rotation_y, self->m_43c, 0x31C7);
            if ((self->frame + self->play_speed) >= TObjEneMe3SinowZoa__data_805DF2F0) {
                self->m_434 = 1;
                self->vfunc_91();
                play_sound_effect(0x4003A829, &self->position, 0, 0);
            }
            self->vfunc_102();
            self->vfunc_89();
            return;
        case 1:
            if ((self->frame + self->play_speed) >= 24.0f) {
                self->m_434 = 2;
                self->vfunc_92();
                play_sound_effect(0x4003A82A, &self->position, 0, 0);
                self->check_and_notify();
            }
            self->move_clamped_on_ground(self->m_3a0.x, self->m_3a0.z, self->m_440);
            return;
        case 2:
            if (self->get_flag_b4() != 0) {
                self->m_434 = 3;
            }
            self->vfunc_102();
            self->vfunc_89();
            return;
        }
        break;
    case 5:
        self->vfunc_92();
        self->clear_field_388();
        break;
    }
}


void TObjEneMe3SinowZoa__sub_80318564(TObjEneMe3SinowZoa *self, s32 arg1) {
    switch (arg1) {
    case 4:
        (self->requested_action) = 8;
        self->set_field_378(0xB);
        self->vfunc_96();
        (self->m_3cc) &= 0xFFEFFFF8;
        if ((self->m_3c0) != 0) {
            ((TObjEneMe3SinowZoa *)&self->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
            self->fade.reset_obstruction_fade();
            (self->m_3cc) |= 0x100000;
            (self->m_3cc) |= 0x40000;
            self->clear_player_status_flag(0, 0x08000000);
            (self->m_434) = 0;
        } else {
            (self->m_434) = 1;
        }
        (self->m_438) = 0;
        break;
    case 3:
        if ((self->m_438) > TObjEneMe3SinowZoa__kind_param_tbls[(self->m_3c8)]->m_1c) {
            self->transition_enemy_state(6);
        }
        break;
    case 5:
        break;
    case 0:
        self->advance_animation();
        switch ((self->m_434)) {
        case 0:
            self->advance_animation();
            if (((TObjEneMe3SinowZoa *)&self->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                (self->m_434) = 1;
            }
        case 1:
            if (self->get_flag_b4() != 0) {
                cast_technique__18TObjEneMe3SinowZoaFPv((u8 *)self);
                if (((s32 (*)(void))check_v2_mode__9TObjEneDDFv)() != 0) {
                    (self->m_434) = 3;
                } else if ((self->m_3cc) & 0x100000) {
                    (self->m_434) = 4;
                } else {
                    (self->m_434) = 2;
                }
                (self->m_438) = 0;
            }
            break;
        case 2:
            (self->m_438)++;
            break;
        case 3:
            (self->m_438)++;
            if ((self->m_438) == 5) {
                TTecSifta::create(self, &self->position, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[(self->m_3c8)]->m_18)));
            } else if ((self->m_438) == 0xA) {
                create__10TTecDebandFlll(self, &self->position, TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[(self->m_3c8)]->m_18));
                if ((self->m_3cc) & 0x100000) {
                    (self->m_434) = 4;
                } else {
                    (self->m_434) = 2;
                }
                (self->m_438) = 0;
            }
            break;
        case 4:
            if (self->fade.decay_value_toward_floor() != 0) {
                (self->m_434) = 2;
                (self->m_3cc) |= 0x40000;
                self->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        self->vfunc_102();
        break;
    }
}

void TObjEneMe3SinowZoa::handle_state_substate(s32 arg1) {
    switch (arg1) {
    case 4:
        this->requested_action = 9;
        set_field_378(0xD);
        this->m_3cc &= 0xFFEFFFF8;
        this->vfunc_95();
        this->m_3fc = 0;
        this->m_434 = 0;
        break;
    case 3:
        if (update_linked_position(200.0f) != 0) {
            this->transition_enemy_state(6);
        } else if (this->m_434 >= 0x5A) {
            this->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        (this->m_434)++;
        advance_animation();
        this->vfunc_102();
        this->vfunc_89();
        break;
    }
}

void TObjEneMe3SinowZoa__sub_803182F8(TObjEneMe3SinowZoa *self, s32 arg1) {
    switch (arg1) {
    case 4:
        self->requested_action = 8;
        self->set_field_378(6);
        self->vfunc_95();
        self->m_3cc &= 0xFFEFFFFC;
        self->m_3cc |= 4;
        self->fade.set_rate_from_divisor(0x1E);
        self->fade.reset_color();
        self->m_434 = 1;
        break;
    case 3:
        if (self->m_434 == 2) {
            self->transition_enemy_state(0);
        }
        break;
    case 0:
        self->advance_animation();
        switch (self->m_434) {
        case 0:
            if (self->get_flag_b4() != 0) {
                self->m_434 = 1;
            }
            break;
        case 1:
            if (self->fade.decay_value_toward_floor() != 0) {
                self->m_434 = 2;
            }
            break;
        }
        self->vfunc_102();
        break;
    case 5:
        self->m_3cc &= 0xFFFFFFFB;
        break;
    }
}

void TObjEneMe3SinowZoa::state_knockback(s32 arg1) {
    Vec v;
    f32 len;
    switch (arg1) {
    case 4:
        this->requested_action = 4;
        this->advance_animation();
        this->set_active();
        play_sound_effect(0x4003A82D, &this->position, 0, 0);
        this->m_3cc &= 0xFFEFFFF8;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            if (this->m_3c0 == 1 && this->random_ratio() <= this->stealth_off_chance) {
                this->transition_enemy_state(0x12);
            } else {
                this->transition_enemy_state(this->m_378);
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
        this->vfunc_89();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa__sub_80317F90(TObjEneMe3SinowZoa *self, s32 arg1) {
    Vec v;
    Vec p;
    self->m_3c0 = 0;
    switch (arg1) {
    case 3:
    case 5:
        break;
    case 4:
        self->requested_action = 5;
        self->refresh_and_send_entity_flags();
        self->vfunc_94();
        self->m_3cc &= 0xFFEFFFF8;
        self->m_434 = 0;
        break;
    case 0:
        switch (self->m_434) {
        case 0:
            self->advance_animation();
            if (self->is_passing_frame(18.0f) != 0 || self->is_passing_frame(lbl_805DF300) != 0) {
                play_sound_effect(0x4003A82A, &self->position, 0, 0);
            }
            if (self->get_flag_b4() != 0) {
                self->m_434 = 1;
                self->m_438 = 0;
                v.x = TObjEneMe3SinowZoa__data_805DF31C;
                v.y = TObjEneMe3SinowZoa__data_805DF314;
                v.z = 20.0f;
                ((TObjBoss2Tunnel *)(&v))->init_zako(&self->position, self->rotation_y);
                TObjPlayer::spawn_effect_f8((s32)&v, 0x14);
            }
            break;
        case 1:
            self->m_438 += 1;
            if (self->m_438 >= 0x14) {
                self->m_434 = 2;
                self->m_3cc |= 2;
                TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe3SinowZoa__breakup_model, (s32)&sinow_zoa_breakup_params, (s32)(self->texlist), (s32)(&self->position), self->rotation_y);
                VecCopy(&p, &self->position);
                p.x += 20.0f * sin_table_lookup(self->rotation_y);
                p.z += 20.0f * cos_table_lookup(self->rotation_y);
                ((TObjPlayer *)(&p))->trigger_dell_biter_events();
                play_sound_effect(0x4003AD2E, &self->position, 0, 0);
            }
            self->vfunc_102();
            break;
        case 2:
            self->queue_destruction();
            break;
        }
        break;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on

void TObjEneMe3SinowZoa__sub_80317B50(TObjEneMe3SinowZoa *self, s32 arg1) {
    Vec v;
    Vec pos;
    Vec tmp;
    s32 d[3];
    s32 i;

    switch (arg1) {
    case 4:
        self->requested_action = 0xC;
        self->set_field_378(0xC);
        self->vfunc_95();
        self->m_3cc &= 0xFFEFFFF9;
        self->m_3cc |= 1;
        self->m_434 = 0;
        break;
    case 3:
        if (self->m_434 == 2) {
            self->m_3c0 = 1;
            self->m_3cc |= 0x40000;
            self->set_indexed_flags(0, 0x08000000);
            if (self->random_ratio() <= self->technique_chance) {
                if (self->sub_8031A454() != 0) {
                    if (self->random_ratio() > TObjEneMe3SinowZoa__kind_param_tbls[self->m_3c8]->m_14) {
                        self->transition_enemy_state(0x10);
                    } else {
                        self->transition_enemy_state(0xB);
                    }
                } else {
                    self->transition_enemy_state(0x10);
                }
            } else {
                self->transition_enemy_state(1);
            }
        }
        break;
    case 0:
        switch (self->m_434) {
        case 0:
            self->advance_animation();
            if (self->get_flag_b4() != 0) {
                self->m_3cc |= 4;
                play_sound_effect(0x4003AD2F, &self->position, 0, 0);
                self->fade.set_rate_from_divisor(0x1E);
                VecCopy(&v, &self->position);
                v.y = self->m_3e0 - 20.0f;
                self->m_434 = 1;
            }
            self->vfunc_102();
            self->vfunc_89();
            break;
        case 1:
            if (self->fade.decay_value_toward_floor() != 0) {
                self->m_3cc |= 2;
                if (self->update_linked_position(200.0f) != 0) {
                    if (self->m_390 == NULL) {
                        break;
                    }
                    d[0] = (s32)(3.0f * self->random_ratio()) - 1;
                    d[1] = (s32)(2.0f * self->random_ratio()) - 1;
                    if (d[1] <= d[0]) {
                        d[1]++;
                    }
                    d[2] = -(d[0] + d[1]);
                    for (i = 0; i < 3; i++) {
                        s32 ang;
                        VecCopy(&pos, &self->m_390->position);
                        ang = self->m_390->rotation_y + ((d[i] + 1) << 14);
                        pos.x += 20.0f * cos_table_lookup(ang);
                        pos.z -= 20.0f * sin_table_lookup(ang);
                        pos.y += TObjEneMe3SinowZoa__data_805DF308;
                        VecCopy(&tmp, &pos);
                        tmp.x += pos.x - self->m_390->position.x;
                        tmp.z += pos.z - self->m_390->position.z;
                        if (check_move_collision__18TObjEneMe3SinowZoaFPvPv(self, &tmp) == 0 &&
                            csnVector(&self->m_390->position, &tmp, 0x88E0) == 0 &&
                            csnVectorUnder(&pos, (u32 *)&self->m_120, 0x15) != 0 &&
                            self->room == ((TScene *)(&pos))->find_section_at_position()) {
                            VecCopy(&self->position, &pos);
                            self->rotation_y = ang + 0xC000;
                            break;
                        }
                    }
                }
                self->m_434 = 2;
            }
            break;
        }
        break;
    case 5:
        self->m_3cc &= ~4;
        break;
    }
}

#pragma pop

void TObjEneMe3SinowZoa::render() {
    s32 mode;
    s32 draw;
    s32 i;

    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_115();
        return;
    }
    sub_8031A454();
    if (this->m_3cc & 2) {
        mode = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
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
                *TObjEneMe3SinowZoa__material_color_pointers[i] = this->m_3f8;
            }
        }
        draw = 1;
        if (this->try_run_effect_m6() != 0) {
            if (defer_render() != 0) {
                draw = 0;
            } else if (this->m_3c0 != 0) {
                draw = 0;
            }
        } else if (TObjEneMe3SinowZoa__sub_800D72A4(&this->fade) != 0) {
            this->fade.set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                draw = 0;
            }
        } else if (this->m_3c0 != 0) {
            draw = 0;
        }
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(&this->position);
            translate_matrix(0, TObjEneMe3SinowZoa__data_805DF31C, this->m_3e4, TObjEneMe3SinowZoa__data_805DF31C);
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
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        if (push_reflection_matrix(&this->m_3d4) != 0) {
            TObjFish::set_global_param((int) (this->texlist));
            push_matrix();
            post_translate_matrix((void *) (&this->position));
            translate_matrix(0, TObjEneMe3SinowZoa__data_805DF31C, this->m_3e4, TObjEneMe3SinowZoa__data_805DF31C);
            rotate_matrix_y(0, this->rotation_y);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

void TObjEneMe3SinowZoa::vfunc_115() {
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

void TObjEneMe3SinowZoa__sub_80317254(TObjEneMe3SinowZoa *self, s32 arg1) {
    switch (arg1) {
    case 4:
        self->requested_action = 0xC;
        self->set_field_378(6);
        self->vfunc_96();
        self->m_3cc &= 0xFFEFFFFD;
        self->m_3cc |= 5;
        self->fade.set_rate_from_divisor(0x1E);
        play_sound_effect(0x4003AD2F, &self->position, 0, 0);
        self->m_434 = 0;
        break;
    case 3:
        if ((self->m_434 == 1) && (self->fade.decay_value_toward_floor() != 0)) {
            self->m_3c0 = 1;
            self->transition_enemy_state(6);
            self->m_3cc &= ~5;
            self->m_3cc |= 0x40000;
            self->set_indexed_flags(0, 0x08000000);
            break;
        }
    case 5:
        break;
    case 0:
        self->advance_animation();
        if (self->get_flag_b4() != 0) {
            self->m_434 = 1;
        }
        self->vfunc_102();
        self->vfunc_89();
        break;
    }
}

void TObjEneMe3SinowZoa__sub_803170F0(TObjEneMe3SinowZoa *self, s32 arg1) {
    switch (arg1) {
    case 4:
        self->requested_action = 0xB;
        self->set_field_378(6);
        self->vfunc_96();
        self->m_3cc &= 0xFFEFFFFD;
        self->m_3cc |= 5;
        self->fade.set_rate_from_divisor(0x1E);
        self->m_3c0 = 0;
        self->m_3cc |= 0x40000;
        self->clear_player_status_flag(0, 0x08000000U);
        self->m_434 = 0;
        break;
    case 3:
        if ((self->m_434 == 1) && (self->fade.advance_toward_max() != 0)) {
            self->transition_enemy_state(6);
            self->m_3cc &= ~5;
            break;
        }
    case 5:
        break;
    case 0:
        self->advance_animation();
        if (self->get_flag_b4() != 0) {
            self->m_434 = 1;
        }
        self->vfunc_102();
        self->vfunc_89();
        break;
    }
}

inline s32 approach_80316C3C(TObjEneMe3SinowZoa *self) {
    copy_position_if_valid__10TObjPlayerFii(self, *self->body_center());
    self->m_300 += TObjEneMe3SinowZoa__data_805DF308;
    return enemy_turn_toward_dest(self, ((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->turn);
}
inline s32 seek_80316C3C(TObjEneMe3SinowZoa *self, Vec *diff) {
    s32 angle;
    if (select_enemy_destination(self, self->m_394, 1) != 0) {
        angle = approach_80316C3C(self);
        enemy_set_heading_velocity(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->speed, self, self->rotation_y);
        move_with_wall_slide((u8 *)self);
    } else {
        VecCopy(diff, &self->m_394);
        subtract_vector(diff, self->body_center());
        angle = self->turn_toward_direction(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->turn, diff);
    }
    return angle;
}

void TObjEneMe3SinowZoa__sub_80316C3C(TObjEneMe3SinowZoa *self, s32 arg1) {
    s32 angle;
    Vec diff;
    Vec out;
    switch (arg1) {
    case 5:
        break;
    case 4:
        self->requested_action = 0xA;
        self->set_field_378(6);
        self->vfunc_96();
        self->m_3cc &= 0xFFEFFFF8;
        self->m_3cc |= 0x10000;
        self->enemy_copy_target_destination();
        self->m_434 = 0;
        break;
    case 3:
        if (self->m_434 == 5) {
            self->transition_enemy_state(6);
        }
        break;
    case 0:
        switch (self->m_434) {
        case 0:
        default:
            if (self->m_390 == NULL) {
                self->transition_enemy_state(6);
                break;
            }
            angle = seek_80316C3C(self, &diff);
            if (angle < 0x100) {
                if (self->m_3c0 != 0) {
                    ((TObjEneMe3SinowZoa *)&self->fade)->set_field_10(TObjEneMe3SinowZoa__data_805DF30C);
                    self->fade.reset_obstruction_fade();
                    self->m_3cc |= 0x100000;
                    self->m_3cc |= 0x40000;
                    self->clear_player_status_flag(0, 0x08000000);
                    self->m_434 = 1;
                } else {
                    self->m_434 = 2;
                }
                self->requested_action = 8;
            } else {
                self->requested_action = 0xA;
            }
            break;
        case 1:
            self->advance_animation();
            if (((TObjEneMe3SinowZoa *)&self->fade)->advance_timer(TObjEneMe3SinowZoa__data_805DF310) != 0) {
                self->m_434 = 2;
            }
        case 2:
            self->advance_animation();
            if (self->get_flag_b4() != 0) {
                self->m_438 = 0;
                self->m_434 = 3;
            }
            if (self->is_passing_frame(TObjEneMe3SinowZoa__data_805DF314) != 0) {
                self->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix(&self->position);
                rotate_matrix_y(0, self->rotation_y);
                set_motion_packed_rotation();
                self->calc_joint_matrices(TObjEneMe3SinowZoa__data_805DF314);
                clear_motion_packed_rotation();
                pop_matrix();
                push_matrix_from(anim_model_matrix_array[3]);
                Vec offset = lbl_80475FC8;
                matrix_mult_vec(0, &offset, &out);
                pop_matrix();
                if (self->m_390 != NULL) {
                    VecCopy(&diff, &self->m_394);
                    subtract_vector(&diff, self->body_center());
                    angle = self->turn_toward_direction(((TObjEneMe3SinowZoaMoveParams *)self->movementParameters)->turn, &diff);
                } else {
                    angle = ((AttackParams *)self->m_318)->attack_angle;
                }
                if (angle < ((AttackParams *)self->m_318)->attack_angle / 2 && self->m_390 != NULL) {
                    if (game_difficulty_selection == 3) {
                        create__11TTecRaBartaFPvPvPvPv(self, &out, &self->position,
                            TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[self->m_3c8]->m_24));
                    } else {
                        ((TTecGiBarta *)self)->create_ex(&out, (void *)self->rotation_y, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3SinowZoa__kind_param_tbls[self->m_3c8]->m_24)));
                    }
                } else if (self->m_3cc & 0x100000) {
                    self->m_434 = 4;
                } else {
                    self->m_434 = 5;
                }
            }
            break;
        case 3:
            if (++self->m_438 >= 0x28) {
                if (self->m_3cc & 0x100000) {
                    self->m_434 = 4;
                } else {
                    self->m_434 = 5;
                }
            }
            break;
        case 4:
            if (self->fade.decay_value_toward_floor() != 0) {
                self->m_434 = 5;
                self->m_3cc |= 0x40000;
                self->set_indexed_flags(0, 0x08000000);
            }
            break;
        }
        break;
    }
    ((TObjPlayer *)self)->update_collisions();
}

s32 check_move_collision__18TObjEneMe3SinowZoaFPvPv(TObjEneMe3SinowZoa *self, const Vec *pos) {
    CollisionBody *body;
    u32 r;
    u32 saved;
    Vec sp8;
    body = self->bodies;
    saved = body->flags;
    body->flags = 0x9D01U;
    VecCopy(&sp8, &self->position);
    VecCopy(&self->position, pos);
    TObjPlayer::init_all_slots();
    self->vfunc_89();
    self->update_enemy_collision_flags();
    if (body->flags & 0x80000) {
        if (get_valid_target_player__10TNpcPlayerFv(get_entity_id((int)self->m_390)) == 0) {
            VecCopy(&self->position, &sp8);
            TObjPlayer::init_all_slots();
            return 1;
        }
    }
    if ((body->flags & 0x100000) && get_valid_target_player__10TNpcPlayerFv(self->entity_id) == 0) {
        VecCopy(&self->position, &sp8);
        TObjPlayer::init_all_slots();
        return 1;
    }
    r = (body->flags & 0x200000) != 0;
    VecCopy(&self->position, &sp8);
    TObjPlayer::init_all_slots();
    copy_collision_body(body, &sinow_zoa_collision_parts);
    body->flags = saved;
    return r;
}

f32 TObjEneMe3SinowZoa::receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32) {
    f32 damage = TObjChara::receive_direct_attack(source, payload, collider, -1, -1);
    if (this->m_3c0 == 1 && random_ratio() <= this->stealth_off_chance) {
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

void TObjEneMe3SinowZoaReal::vfunc_63() { TObjEneMe3SinowZoa::vfunc_63(); }

void TObjEneMe3SinowZoaReal::vfunc_62() { TObjEneMe3SinowZoa::vfunc_62(); }

void TObjEneMe3SinowZoaReal::vfunc_107() {
    this->m_3fc = this->m_3fc + 1;
    if ((this->m_3fc >= 2) || (this->random_ratio() < lbl_805DF304)) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(6);
}

void TObjEneMe3SinowZoaReal::vfunc_111() {  }

void TObjEneMe3SinowZoa__sub_80316840(TObjEneMe3SinowZoa *self) {
    if ((self->is_passing_frame(TObjEneMe3SinowZoa__data_805DF2FC) != 0) || (self->is_passing_frame(lbl_805DF300) != 0)) {
        self->check_floor_contact(&self->position);
    }
}

void TObjEneMe3SinowZoa::check_and_notify() {
    s32 x;
    x = check_floor_contact(&position);
    if (x == 0) {
        spawn_particle_effect(&position, 243);
    }
}

s32 TObjEneMe3SinowZoa::check_floor_contact(void *arg1) {
    Vec v;
    CsnHit *hit;
    void *p;
    VecCopy(&v, (const Vec *)arg1);
    v.y += TObjEneMe3SinowZoa__data_805DF2F0;
    hit = (CsnHit *)csnVectorUnder(&v, (u32 *)&this->m_120, 0x4007);
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
                attach_particle_model((u8 *)p, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, TObjEneMe3SinowZoa__data_805DF2F4);
            }
            spawn_particle_effect(&hit->contact[2].point, 0xA4);
            return 1;
        }
        if (hit->hit_mask & 2) {
            TObjEneGibbles__sub_800D8988(&this->position);
            p = spawn_particle_effect(&hit->contact[3].point, 0x49);
            if (p != 0) {
                attach_particle_model((u8 *)p, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, TObjEneMe3SinowZoa__data_805DF2F4);
            }
            spawn_particle_effect(&hit->contact[3].point, 0xA4);
            return 1;
        }
    }
    return 0;
}

}
