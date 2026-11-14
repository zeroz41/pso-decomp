#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/animation/MotionContext.h"
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResource.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/npc/TObjNpcEnemy_803D8090.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaMirage.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecSifta.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/AngleUnits.h"
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma defer_codegen on
extern "C" {
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 transform_relative_position__9TObjEneDDFPv(void *, void *);
s32 is_player_entity_id(u16);
s32 enemy_set_target_id(void *, u16);
void fn_800E762C(TObjEneMe3Shinowa *);
u16 TObjEneMe3ShinowaReal__sub_800E45CC(TObjEneMe3Shinowa *shinowa);
extern s32 model_render_flags;
TObjEneMe3ShinowaMirage *create__23TObjEneMe3ShinowaMirageFPvPv(void *, s32, s32, s32);
}

extern "C" {
u32 csnVecterUnder(void *, int);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
BmlResource * TObjEneMe3ShinowaMirage__data_805D5298;
s32 TObjEneMe3ShinowaMirage__render_node_index;
TUnk_8048FA00 * TObjEneMe3ShinowaMirage__data_805D52A0;
SampledMotionPoints * TObjEneMe3ShinowaMirage__data_805D52A4;
SampledMotionPoints * TObjEneMe3ShinowaMirage__data_805D52A8;
SampledMotionPoints * TObjEneMe3ShinowaMirage__data_805D52AC;
void TObjEneMe3ShinowaMirage__sub_800E5F64(TObjEneMe3Shinowa *, s32);
struct EnemyTargetCandidate { u16 id; u8 unk_2[6]; };
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
}

void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
extern "C" {
s32 collect_target_candidates__9TObjEneDDFlf(void *, f32);
s32 subtract_vector(void *, void *);
extern EnemyTargetCandidate enemy_target_candidate_table[];
void TObjEneMe3ShinowaReal__sub_800E5950(TObjEneMe3Shinowa *, s32);
s32 move_to_shot_position__9TObjEneDDFfff(void *, void *, f32, f32, f32);
void TObjEneMe3ShinowaMirage__sub_800E5CE4(TObjEneMe3Shinowa *, s32);
struct Tbl_800E7884 { u8 pad[0xC]; s32 t[3][2]; };
s32 get_main_phase();
}

void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
extern "C" {
s32 enemy_validate_retained_target(void *, int);
s32 is_main_phase_15__9TObjEneDDFv();
void get_camera_ctrl__9TObjEneDDFv(Vec *, Vec *);
void TObjEneDD__sub_800BA438(s32 arg0, u8 *arg1);
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
void TObjEneMe3ShinowaMirage__sub_800E4FE8(TObjEneMe3Shinowa *shinowa, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E50D8(TObjEneMe3Shinowa *shinowa, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E5220(TObjEneMe3Shinowa *shinowa, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E54E8(TObjEneMe3Shinowa *, s32);
void TObjEneMe3ShinowaMirage__sub_800E66FC(TObjEneMe3Shinowa *, s32);
void TObjEneMe3ShinowaMirage__sub_800E69F0(TObjEneMe3Shinowa *, s32);
void TObjEneMe3ShinowaMirage__sub_800E6F0C(TObjEneMe3Shinowa *shinowa);
void TObjEneMe3Shinowa__sub_800E7268(TObjEneMe3Shinowa *);
s32 check_in_range__23TObjEneMe3ShinowaMirageFPv(TObjEneMe3Shinowa *shinowa);
s32 get_room__8TObjBaseFv(TObjBase *);
s32 create__10TTecDebandFlll(void *, void *, s32);
void compose_motion_node_matrix(void *arg0);
s32 translate_matrix(int, f32, f32, f32);
extern u8 shinowa_mirage_breakup_params[];

// Per-variant parameter tables fetched from TLobby (TObjEneMe3Stelth names the same four
// base/attack/resistance/behavior_params_by_variant).
Vec TObjEneMe3ShinowaMirage__data_80500FC0;
__declspec(section ".data") s32 lbl_80500FCC[2];
__declspec(section ".data") s32 lbl_80500FD4[2];
__declspec(section ".data") s32 lbl_80500FDC[2];
__declspec(section ".data") TObjEneMe3ShinowaParams *TObjEneMe3ShinowaMirage__mirage_info_table[2];

// Copy of the model's texture list (the mirage swaps the first three texture addresses).
__declspec(section ".data") NJS_TEXLIST lbl_80500FEC;
Vec lbl_80500FF4;
s32 *lbl_80501000[4];
extern s32 saved_model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern s32 model_render_flags;
extern const char lbl_8043CE3C[];
extern const char lbl_8043CE4C[];
extern const char lbl_8043CE60[];
extern const char lbl_8043CE78[];
extern const char lbl_8043CE90[];
extern const char lbl_8043CEA4[];
extern const char lbl_8043CEBC[];
extern const char lbl_8043CED0[];
extern const char lbl_8043CEE8[];
extern const char lbl_8043CF00[];
extern const char lbl_8043CF14[];
extern const char lbl_8043CF28[];

TObjEneMe3ShinowaMoveParams TObjEneMe3ShinowaMirage__init_params = {
    225.0f, 0.0f, 0x600,
};

CollisionBody shinowa_mirage_model_init_data[1] = {
    {{0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

__declspec(section ".data") const char *bm_ene_me3_shinowa_model_names[2] = {
    lbl_8043CE3C, NULL,
};

const char *bm_ene_me3_shinowa_motion_names[11] = {
    lbl_8043CE4C, lbl_8043CE60, lbl_8043CE78, lbl_8043CE90,
    lbl_8043CEA4, lbl_8043CEBC, lbl_8043CED0, lbl_8043CEE8,
    lbl_8043CF00, lbl_8043CF14, NULL,
};

BmlResourceDescriptor shinowa_mirage_resource_descriptor = {
    lbl_8043CF28, bm_ene_me3_shinowa_model_names, bm_ene_me3_shinowa_motion_names, 1, 10,
};

TObjMotionAction shinowa_mirage_motion_param_table[11] = {
    {1, 0, 7, 0.5f, ACTION_NO_BLEND_IN},
    {3, 0, 0, 1.5f, ACTION_NO_BLEND_IN},
    {3, 0, 1, 0.8f, 0},
    {3, 0, 2, 0.6f, 0},
    {3, 0, 3, 0.6f, 0},
    {3, 0, 4, 0.7f, 0},
    {3, 0, 5, 1.0f, 0},
    {3, 0, 6, 0.7f, 0},
    {1, 0, 8, 0.5f, 0},
    {1, 0, 9, 0.5f, 0},
    {3, 0, 6, 0.7f, ACTION_NO_BLEND_IN},
};

const char *TObjEneMe3Shinowa__name = "TObjEneMe3Shinowa";
const char *TObjEneMe3ShinowaReal_class_name = "TObjEneMe3ShinowaReal";
// inferred: TObjEneMe3ShinowaMirage__class_name (was lbl_805D2AD0; the mirage ctor stores it to m_name)
const char *TObjEneMe3ShinowaMirage__class_name = "TObjEneMe3ShinowaMirage";
// inferred: motion binding load_shinowa_mirage_resources hands to TLobby::spawn_npc_enemy
const DelDepthAnimationBinding shinowa_mirage_spawn_binding = { NULL, shinowa_mirage_motion_param_table, 0x80009, 11, 0 };
// inferred: shadow scale handed to draw_ground_shadow by update_player_state_default
const Vec shinowa_shadow_scale = { 2.5f, 1.0f, 1.5f };

s32 free_bin_model_request(void *, s32);
void mem_free(void *p);
int create__21TObjEneMe3ShinowaRealFv(void*);
void *mem_alloc(u32 size);
extern s32 lbl_8043CE1C[];
extern s32 lbl_8043CE24[];
extern s32 lbl_8043CE2C[];
extern s32 lbl_8043CE34[];

// Floor resource callback (inferred: load_shared_resources, the TObjEneMe3SinowZoa::load_resources twin):
// loads the shared Shinowa BML, a texture-list copy for the mirage, the per-variant parameter tables,
// the breakup model and the sampled claw-trail points.
void load_shinowa_mirage_resources() {
    NJS_TEXLIST *src;
    s32 n;
    s32 i;
    TObjEneMe3ShinowaParams *info;
    u32 root;
    NJS_CNK_MODEL *cnk;
    AnimationMotion *motion;
    NJS_OBJECT *model;
    f32 step;
    NJS_MOTION *trail;

    TObjEneMe3ShinowaMirage__data_80500FC0.x = 0.0f;
    TObjEneMe3ShinowaMirage__data_80500FC0.y = 0.0f;
    TObjEneMe3ShinowaMirage__data_80500FC0.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        TObjEneMe3ShinowaMirage__data_805D5298 = (BmlResource *)load_enemy_bml_resource_named((s32)&shinowa_mirage_resource_descriptor, (s32)"bm_ene_me3_shinowa_a.bml");
    } else {
        TObjEneMe3ShinowaMirage__data_805D5298 = (BmlResource *)load_enemy_bml_resource((u8 *)&shinowa_mirage_resource_descriptor);
    }
    src = (NJS_TEXLIST *)TObjEneMe3ShinowaMirage__data_805D5298->models->m_c;
    n = src->nbTexture;
    lbl_80500FEC.nbTexture = n;
    lbl_80500FEC.textures = (NJS_TEXNAME *)mem_alloc(n * sizeof(NJS_TEXNAME));
    for (i = 0; i < n; i++) {
        ((TObjPlayer *)&lbl_80500FEC.textures[i])->copy_vec3(&src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        lbl_80500FEC.textures[i + 3].texaddr = lbl_80500FEC.textures[i].texaddr;
    }
    for (s32 j = 0; j < 2; j++) {
        lbl_80500FCC[j] = (s32)TLobby::register_boss(lbl_8043CE1C[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        lbl_80500FD4[j] = (s32)TLobby::dispatch_shared_handler_b(lbl_8043CE24[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        lbl_80500FDC[j] = (s32)TLobby::register_object(lbl_8043CE2C[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneMe3ShinowaMirage__mirage_info_table[j] = (TObjEneMe3ShinowaParams *)TLobby::dispatch_shared_handler_a(lbl_8043CE34[j]);
    }
    info = TObjEneMe3ShinowaMirage__mirage_info_table[0];
    TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(6, info->m_c);
    TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(3, info->m_10);
    TObjEneMe3ShinowaMirage__render_node_index = 0;
    lbl_80500FF4.x = 0.0f;
    lbl_80500FF4.y = 0.0f;
    lbl_80500FF4.z = 0.0f;
    root = TObjEneMe3ShinowaMirage__data_805D5298->models->model;
    cnk = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(root, 9))->model;
    if (cnk != NULL) {
        lbl_80501000[0] = (s32 *)(cnk->polygon_list + 2);
    } else {
        lbl_80501000[0] = NULL;
    }
    cnk = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(root, 13))->model;
    if (cnk != NULL) {
        lbl_80501000[1] = (s32 *)(cnk->polygon_list + 2);
    } else {
        lbl_80501000[1] = NULL;
    }
    cnk = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(root, 38))->model;
    if (cnk != NULL) {
        lbl_80501000[2] = (s32 *)(cnk->polygon_list + 2);
    } else {
        lbl_80501000[2] = NULL;
    }
    motion = TObjEneMe3ShinowaMirage__data_805D5298->motions[shinowa_mirage_motion_param_table[4].motion].motion;
    TUnk_8048FA00 *breakup = (TUnk_8048FA00 *)::operator new(0x10);
    if (breakup != NULL) {
        breakup = TBreakUpMdl::init(breakup, TObjEneMe3ShinowaMirage__data_805D5298->models->model, (s32)motion, motion->frameCount - 1);
    }
    TObjEneMe3ShinowaMirage__data_805D52A0 = breakup;
    {
        Vec first;
        Vec second;
        BmlResource *res = TObjEneMe3ShinowaMirage__data_805D5298;
        s32 idx = shinowa_mirage_motion_param_table[5].motion;
        model = (NJS_OBJECT *)res->models->model;
        first.x = 0.0f;
        first.y = 0.0f;
        first.z = 0.0f;
        second.x = -10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        trail = (NJS_MOTION *)res->motions[idx].motion;
        TObjEneMe3ShinowaMirage__data_805D52AC = new SampledMotionPoints(2, 16.0f, 26.0f, 0.7f);
        TObjEneMe3ShinowaMirage__data_805D52AC->sample_node_offsets(model, trail, 0x22, &first, &second);
        first.x = 0.0f;
        first.y = 0.0f;
        first.z = 0.0f;
        trail = (NJS_MOTION *)TObjEneMe3ShinowaMirage__data_805D5298->motions[shinowa_mirage_motion_param_table[6].motion].motion;
        step = TObjEneMe3ShinowaMirage__mirage_info_table[0]->m_c;
        if (step < 0.1f) {
            step = 0.1f;
        }
        second.x = -10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        TObjEneMe3ShinowaMirage__data_805D52A4 = new SampledMotionPoints(2, 6.0f, 14.0f, step);
        TObjEneMe3ShinowaMirage__data_805D52A4->sample_node_offsets(model, trail, 0x22, &first, &second);
        second.x = 10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        TObjEneMe3ShinowaMirage__data_805D52A8 = new SampledMotionPoints(2, 17.0f, 23.0f, step);
        TObjEneMe3ShinowaMirage__data_805D52A8->sample_node_offsets(model, trail, 0x15, &first, &second);
    }
    {
        DelDepthAnimationBinding binding = shinowa_mirage_spawn_binding;
        binding.motions = TObjEneMe3ShinowaMirage__data_805D5298->motions;
        TLobby::spawn_npc_enemy(0x26, TObjEneMe3ShinowaMirage__data_805D5298->models->model, (NJS_TEXLIST *)TObjEneMe3ShinowaMirage__data_805D5298->models->m_c, &binding, 8.0f, 0.0f);
        TLobby::spawn_npc_enemy(0x27, TObjEneMe3ShinowaMirage__data_805D5298->models->model, &lbl_80500FEC, &binding, 8.0f, 0.0f);
    }
}

int TObjEneMe3ShinowaMirage__sub_800E7B74(void* p) { return create__21TObjEneMe3ShinowaRealFv(p); }

void TObjEneMe3ShinowaMirage::free_shared_resources() {
    if (TObjEneMe3ShinowaMirage__data_805D52A8 != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52A8;
        TObjEneMe3ShinowaMirage__data_805D52A8 = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D52A4 != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52A4;
        TObjEneMe3ShinowaMirage__data_805D52A4 = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D52AC != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52AC;
        TObjEneMe3ShinowaMirage__data_805D52AC = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D52A0 != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52A0;
        TObjEneMe3ShinowaMirage__data_805D52A0 = 0;
    }
    if (lbl_80500FEC.textures != 0) {
        mem_free(lbl_80500FEC.textures);
        lbl_80500FEC.textures = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D5298 != 0) {
        free_bin_model_request(TObjEneMe3ShinowaMirage__data_805D5298, 1);
        TObjEneMe3ShinowaMirage__data_805D5298 = 0;
    }
}

void TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(s32 arg0, f32 farg0) {
    if (farg0 < 0.1f) {
        farg0 = 0.1f;
    }
    shinowa_mirage_motion_param_table[arg0].speed = farg0;
}

TObjEneMe3Shinowa::TObjEneMe3Shinowa(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe3Shinowa__name;
}
}

#pragma push
#pragma opt_propagation off
extern "C" {
void TObjEneMe3Shinowa::init_enemy() {
    Tbl_800E7884 *tbl = &(*(Tbl_800E7884 *)&TObjEneMe3ShinowaMirage__data_80500FC0);
    init_position_vectors();
    sub_800E6F64();
    model = (void *)TObjEneMe3ShinowaMirage__data_805D5298->models->model;
    init_model(shinowa_mirage_model_init_data, 1);
    motion_flags = 0;
    set_field_d8((s32)shinowa_mirage_motion_param_table);
    set_field_dc((s32)TObjEneMe3ShinowaMirage__data_805D5298->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    {
        s32 *a = tbl->t[0];
        s32 *b = tbl->t[1];
        s32 *c = tbl->t[2];
        s32 i = m_3c0;
        reset_hp((u8 *)a[i], (u8 *)b[i], (u8 *)c[i]);
    }
    check_state_flag_4();
    movementParameters = &TObjEneMe3ShinowaMirage__init_params;
    m_37c = 10.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    m_3c4 = 0;
    m_3c8 = position.y;
    m_3cc = 0.0f;
    m_3d0 = 0;
    m_3d8 = 0;
    m_3d4 = 0;
    m_3dc = m_2cc;
    m_3e0 = TUnk_80494968::create((u32)0xFF0000FF, (u32)0xA08000A0);
    m_3e4 = TUnk_80494968::create((u32)0xFF0000FF, (u32)0xA08000A0);
    m_3e8.reset_obstruction_fade();
    m_404 = 0;
    m_408 = 0;
    m_40c = 0;
    m_410 = 0.0f;
    m_414 = 0.0f;
    m_418.x = 0.0f;
    m_418.y = 0.0f;
    m_418.z = 0.0f;
    m_424 = NULL;
    m_428 = NULL;
}
}

#pragma pop
extern "C" {
TObjEneMe3Shinowa::~TObjEneMe3Shinowa() {
    m_3e4->queue_destruction();
    m_3e4 = NULL;
    m_3e0->queue_destruction();
    m_3e0 = NULL;
    if (m_424 != NULL) { m_424->queue_destruction(); m_424 = NULL; }
    if (m_428 != NULL) { m_428->queue_destruction(); m_428 = NULL; }
    free_collision_body_parts(this);
}

void TObjEneMe3Shinowa::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        update_mirage();
        return;
    }
    if (vfunc_83() != 4) {
        vfunc_85();
    }
    copy_position_vector();
    submit_default_cursor_candidate();
    vfunc_100();
}

void TObjEneMe3Shinowa::vfunc_28() {  }

void TObjEneMe3Shinowa::vfunc_63() { if (mode != 13) { transition_enemy_state(13); } }

void TObjEneMe3Shinowa::vfunc_62() {
    if (TObjEneDD::check_v2_mode() != 0) {
        clear_attack_receipts();
        return;
    }
    if (m_3c4 & 1) {
        clear_attack_receipts();
        return;
    }
    if ((s16) mode != 0xC) {
        transition_enemy_state(0xC);
    }
}

void TObjEneMe3Shinowa::vfunc_61() {  }

void TObjEneMe3Shinowa::copy_position_vector() { VecCopy(&center, (const Vec *)&m_2fc); }

void TObjEneMe3Shinowa::vfunc_88() {
    bodies->offset.y = m_3cc + (m_300 - position.y);
}

void fn_800E762C(TObjEneMe3Shinowa *) {  }

f32 TObjEneMe3Shinowa::get_node_world_y() {
    TObjEneMe3Shinowa *self = this;
    Vec v;
    NJS_OBJECT *node;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    bind_motion_context((NJS_MOTION *)self->current_motion, self->frame);
    node = (NJS_OBJECT *)self->model;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

s32 TObjEneMe3Shinowa::check_body_collision_at(s32 arg1, f32 farg0) {
    farg0 *= 0.5f;
    CollisionBody *body = bodies;
    s32 res;
    s32 a = rotation_y;
    s32 b = body->flags;
    body->offset.x = 0.0f;
    body->offset.z = farg0;
    body->radius = farg0;
    body->half_width = 8.0f;
    body->shape = 1;
    body->flags = 0x9D01;
    rotation_y = arg1;
    ((void (*)(void *, s32, f32, f32))check_enemy_body_collisions)(this, arg1, 0.0f, farg0);
    res = (body->flags & 0x380000) != 0;
    copy_collision_body(body, shinowa_mirage_model_init_data);
    body->flags = b;
    rotation_y = a;
    return res;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 check_in_range__23TObjEneMe3ShinowaMirageFPv(TObjEneMe3Shinowa *shinowa) {
    f32 f31;

    if (shinowa->m_3ac > 25.0f) {
        return 0;
    }
    f31 = shinowa->m_3a0.z * cos_table_lookup(shinowa->rotation_y);
    f31 += shinowa->m_3a0.x * sin_table_lookup(shinowa->rotation_y);
    return (s32)((u32)__cntlzw(f31 < cos_table_lookup(0x1E00)) >> 5);
}
}

#pragma pop
extern "C" {
void TObjEneMe3Shinowa::vfunc_105() {
    s32 temp_r31;
    temp_r31 = is_passing_frame(19.0f);
    if ((is_passing_frame(9.0f) != 0) || (temp_r31 != 0)) {
        if (enemy_check_target_valid() != 0) {
            if (m_390->select_melee_contact_body(this, 1.0f) != 0) {
                m_390->receive_physical_attack(this, 1.0f);
                m_390->apply_knockback_from_attacker((u8 *)this, 3.0f);
                if ((temp_r31 != 0) && (random_ratio() <= 0.1666f)) {
                    TObjEneDD__sub_800BA438((s32)this, (u8 *)m_390);
                }
            }
        }
        play_sound_effect(remap_sound_for_area(0x4003AD13), &position, 0, 0);
    }
}

void TObjEneMe3Shinowa::update_player_state_default() {
    if (!(m_3c4 & 0x80000)) {
        Vec stack = shinowa_shadow_scale;
        draw_ground_shadow(&stack, 0);
    }
}

s32 TObjEneMe3Shinowa::can_hit_same_target() {
    s16 mine;
    u8 ret;
    s16 theirs;
    ret = 0;
    if (!(m_3c4 & 0x10000)) {
        if (m_3ac > 100.0f && m_3ac < 150.0f) {
            mine = get_room__8TObjBaseFv(this);
            theirs = get_room__8TObjBaseFv(m_390);
            if (theirs == mine && check_body_collision_at(rotation_y, m_3ac - 20.0f) == 0) {
                ret = 1;
            }
        }
    }
    return ret;
}

void TObjEneMe3Shinowa::vfunc_107() {  }

void TObjEneMe3Shinowa__sub_800E7268(TObjEneMe3Shinowa *shinowa) {
    shinowa->m_3c4 |= 0x10;
    shinowa->m_2cc = (s16) ((s16) shinowa->m_3dc / 2);
}

void TObjEneMe3ShinowaReal::sub_800E7250() {
    m_3c4 &= 0xFFFFFFEF;
    m_2cc = (s16) m_3dc;
}

s32 TObjEneMe3Shinowa::update_effect() {
    s16 temp_r0;

    temp_r0 = mode;
    if ((temp_r0 == 1) || (temp_r0 == 9) || (m_3c4 & 0x80000)) {
        m_3e8.set_flags_and_apply_damage_color();
    }
    return 0;
}

void TObjEneMe3Shinowa::dispatch_if_active() {
    s16 temp_r0;

    temp_r0 = mode;
    if ((temp_r0 == 1) || (temp_r0 == 9) || (m_3c4 & 0x80000)) {
        m_3e8.clear_flag_and_notify();
    }
}

void TObjEneMe3Shinowa::vfunc_111() {  }

void TObjEneMe3Shinowa::apply_effect_pair() {
    s32 sp8[8];
    u32 entry;
    u32 temp_r3_3;

    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix((u8 *)&position);
    rotate_matrix_y(0, rotation_y);
    entry = (s32)TObjEneMe3ShinowaMirage__data_805D52A4->lookup(frame);
    if (entry != 0U) {
        mult_vec_array__10TObjPlayerFUll(0, entry, &sp8, 2);
        m_3e0->vfunc_6(&sp8, &sp8[3]);
    }
    temp_r3_3 = (s32)TObjEneMe3ShinowaMirage__data_805D52A8->lookup(frame);
    if (temp_r3_3 != 0U) {
        mult_vec_array__10TObjPlayerFUll(0, temp_r3_3, &sp8, 2);
        m_3e4->vfunc_6(&sp8, &sp8[3]);
    }
    pop_matrix();
}

void TObjEneMe3ShinowaMirage::update_by_distance() {
    f32 lim = 30.0f;
    if ((m_3c8 - position.y) > lim) {
        vfunc_97();
        return;
    }
    vfunc_98();
}

void TObjEneMe3Shinowa::vfunc_89() {
    vfunc_88();
    check_object_collisions();
    check_enemy_body_collisions(this);
}

s32 TObjEneMe3Shinowa::sub_800E701C() {
    return parameters[0] < 1.0f;
}

s32 TObjEneMe3Shinowa::vfunc_104(f32 range) { return select_and_apply_target(range); }

s32 TObjEneMe3Shinowa::sub_800E6FE0() {
    return parameters[1] >= 1.0f;
}

void TObjEneMe3Shinowa::sub_800E6F64() {
    if (sub_800E6FE0() != 0) {
        texlist = (s32)&lbl_80500FEC;
        initialize_enemy_state(0x1b);
        m_3c0 = 1;
        return;
    }
    texlist = (s32)TObjEneMe3ShinowaMirage__data_805D5298->models->m_c;
    initialize_enemy_state(0x1a);
    m_3c0 = 0;
}

void TObjEneMe3ShinowaMirage__sub_800E6F0C(TObjEneMe3Shinowa *shinowa) {
    s32 f = TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[shinowa->m_3c0]->m_18);
    TTecResta::create(shinowa, &shinowa->position, (void *)f);
}

void TObjEneMe3Shinowa::dispatch_action(u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        action(arg2);
        return;
    case 1:
        sub_800E6BB8(arg2);
        return;
    case 2:
        TObjEneMe3ShinowaMirage__sub_800E69F0(this, (s32)arg2);
        return;
    case 3:
        TObjEneMe3ShinowaMirage__sub_800E66FC(this, arg2);
        return;
    case 4:
        ((TObjEneMe3ShinowaMirage *)this)->state_chase_target(arg2);
        return;
    case 5:
        TObjEneMe3ShinowaMirage__sub_800E5F64(this, (s32)arg2);
        return;
    case 6:
        TObjEneMe3ShinowaMirage__sub_800E5CE4(this, (s32)arg2);
        return;
    case 7:
        TObjEneMe3ShinowaReal__sub_800E5950(this, (s32)arg2);
        return;
    case 8:
        TObjEneMe3ShinowaMirage__sub_800E54E8(this, arg2);
        return;
    case 11:
        TObjEneMe3ShinowaMirage__sub_800E5220(this, arg2);
        return;
    case 9:
        TObjEneMe3ShinowaMirage__sub_800E50D8(this, arg2);
        return;
    case 10:
        ((TObjEneMe3ShinowaMirage *)this)->state_cast_support(arg2);
        return;
    case 12:
        TObjEneMe3ShinowaMirage__sub_800E4FE8(this, arg2);
        return;
    case 13:
        ((TObjEneMe3ShinowaMirage *)this)->state_break_apart(arg2);
        return;
    case 14:
        vfunc_114(arg2);
        return;
    case 15:
        vfunc_115(arg2);
        return;
    case 16:
        vfunc_116(arg2);
    default:
        return;
    }
}

void TObjEneMe3Shinowa::action(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 1;
        set_field_378(1);
        vfunc_95();
        m_3c4 |= 2;
        m_3c4 &= 0xFFFFFFFE;
        if (TObjEneDD::check_v2_mode() != 0) {
            m_3c4 &= 0xFFFCFFFF;
        }
        m_404 = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy((Vec *)&m_2fc, &home_position);
        m_3c8 = position.y;
        if (!(m_3c4 & 0x1000)) {
            m_3d0 = 0;
        }
        m_3d8 = 0;
        return;
    case 3:
        if (m_404 > 5) {
            transition_enemy_state(1);
        }
    case 5:
        return;
    case 0:
        m_404 += 1;
        if (m_404 == 1) {
            m_3c8 = position.y;
            vfunc_102();
            m_3cc = m_3c8 - position.y;
        }
        break;
    }
}

void TObjEneMe3Shinowa::sub_800E6BB8(s32 arg1) {
    Vec pos;
    f32 y;
    switch (arg1) {
    case 4:
        requested_action = 1;
        set_field_378(0);
        vfunc_95();
        m_3c4 &= 0xFFFFFFFC;
        m_3e8.start_fade_in();
        VecCopy(&pos, &position);
        y = m_3c8;
        pos.y = y - 20.0f;
        TBoss3Volopt__sub_800D8D88(&pos, y);
        return;
    case 3:
        if (m_3e8.advance_toward_max() != 0) {
            transition_enemy_state(2);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E69F0(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    s32 temp_r3;
    s32 ene_dd_st;
    switch (arg1) {
    case 4:
        shinowa->requested_action = 0;
        shinowa->set_field_378(3);
        shinowa->vfunc_95();
        shinowa->m_3c4 &= 0xFFFFFFFC;
        shinowa->m_404 = 0;
        shinowa->m_408 = 0;
        return;
    case 3:
        if (shinowa->m_404 > 0x1E) {
            shinowa->transition_enemy_state(3);
        }
        return;
    case 0:
        shinowa->advance_animation();
        temp_r3 = shinowa->m_404;
        if (temp_r3 == 0) {
            if (shinowa->update_linked_position(200.0f) != 0) {
                static const u32 color_mask = 0xFFFF00FF;
                shinowa->m_404 = 1;
                if (!(shinowa->m_3c4 & 0x1000)) {
                    shinowa->m_3d0 = 0x1C00FFFF;
                }
                shinowa->m_3d0 &= color_mask;
                shinowa->m_408 = 0;
            }
        } else {
            shinowa->m_404 = (temp_r3 + 1);
            shinowa->m_408 += 0x10;
            if (shinowa->m_408 > 0xFF) {
                shinowa->m_408 = 0xFF;
            }
            ene_dd_st = shinowa->m_408;
            shinowa->m_3d0 = (ene_dd_st << 24) | (shinowa->m_3d0 & 0x00FFFFFF);
            if (enemy_validate_retained_target(shinowa, ene_dd_st) == 0) {
                shinowa->m_404 = 0;
                if (!(shinowa->m_3c4 & 0x1000)) {
                    shinowa->m_3d0 = 0;
                }
            }
        }
        shinowa->vfunc_102();
        ((TObjEneMe3ShinowaMirage *)shinowa)->update_by_distance();
        shinowa->vfunc_89();
        shinowa->m_3cc = shinowa->m_3c8 - shinowa->position.y;
        return;
    case 5:
        if (!(shinowa->m_3c4 & 0x1000)) {
            shinowa->m_3d0 = 0x1C00FFFF;
        }
        shinowa->m_3cc = 0.0f;
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E66FC(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f31;

    switch (arg1) {
    case 4:
        shinowa->requested_action = 1;
        shinowa->set_field_378(0xB);
        shinowa->vfunc_96();
        shinowa->m_3c4 &= 0xFFFFFFFD;
        shinowa->m_3c4 |= 1;
        shinowa->m_404 = 0;
        shinowa->m_410 = 0.0f;
        if (shinowa->enemy_has_live_target() != 0) {
            shinowa->enemy_copy_target_destination();
            shinowa->update_velocity();
            shinowa->m_40c = (s32) (RADIANS_TO_ANGLE * atan2_float(shinowa->m_3a0.x, shinowa->m_3a0.z));
            return;
        }
        shinowa->m_40c = (s32) shinowa->rotation_y;
        return;
    case 3:
        if (shinowa->m_404 == 3) {
            shinowa->transition_enemy_state(0xB);
        }
        return;
    case 0:
        switch (shinowa->m_404) {
        case 0:
            temp_f31 = shinowa->get_node_world_y();
            shinowa->advance_animation();
            shinowa->m_414 = shinowa->get_node_world_y();
            shinowa->m_3c8 = shinowa->m_3c8 + (temp_f31 - shinowa->m_414);
            shinowa->rotation_y += 0x8000;
            shinowa->m_404 = 1;
            shinowa->m_3cc = shinowa->m_3c8 - shinowa->position.y;
            break;
        case 1:
            shinowa->advance_animation();
            if (shinowa->frame > 29.0f) {
                shinowa->frame = 29.0f;
            }
            shinowa->rotation_y = approach_angle_limited(shinowa->rotation_y, shinowa->m_40c, 0x800);
            shinowa->m_410 = (f32) (shinowa->m_410 - 0.3f);
            if (shinowa->m_410 < -5.0f) {
                shinowa->m_410 = -5.0f;
            }
            shinowa->m_3c8 = shinowa->m_3c8 + shinowa->m_410;
            temp_f1 = shinowa->get_node_world_y();
            shinowa->m_3c8 = shinowa->m_3c8 - (temp_f1 - shinowa->m_414);
            shinowa->m_414 = temp_f1;
            if (shinowa->m_3c8 < shinowa->position.y) {
                shinowa->m_3c8 = shinowa->position.y;
                shinowa->m_404 = 2;
                play_sound_effect(shinowa->remap_sound_for_area(0x4003AD12), &shinowa->position, 0, 0);
                spawn_particle_effect(&shinowa->position, 0xF3);
            }
            break;
        case 2:
            if (shinowa->get_flag_b4() != 0) {
                shinowa->requested_action = 8;
                shinowa->m_404 = 3;
                shinowa->m_3c8 = shinowa->position.y;
                shinowa->m_3cc = 0.0f;
            }
            shinowa->advance_animation();
            break;
        }
        shinowa->vfunc_102();
        ((TObjEneMe3ShinowaMirage *)shinowa)->update_by_distance();
        shinowa->vfunc_89();
        shinowa->m_3cc = shinowa->m_3c8 - shinowa->position.y;
        return;
    case 5:
        shinowa->m_3c4 &= 0xFFFFFFFE;
        shinowa->m_3cc = 0.0f;
        break;
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneMe3ShinowaMirage::state_chase_target(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 9;
        set_field_378(4);
        vfunc_96();
        m_3c4 &= 0xFFFFFFFC;
        m_3ac = 300.0f;
        if (m_3c4 & 0x10) {
            m_410 = (f32) TObjEneMe3ShinowaMirage__mirage_info_table[m_3c0]->m_4;
        } else {
            m_410 = (f32) TObjEneMe3ShinowaMirage__mirage_info_table[m_3c0]->m_0;
        }
        m_414 = 0.0f;
        return;
    case 3:
        if ((u32) m_390 == 0U) {
            vfunc_111();
            transition_enemy_state(0xB);
        } else if (((s32 (*)(f32))check_in_range__23TObjEneMe3ShinowaMirageFPv)((f32) (m_414)) != 0) {
            transition_enemy_state(6);
        } else if (can_hit_same_target() != 0) {
            transition_enemy_state(5);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (update_linked_position(200.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
            m_414 = (f32) ((m_3a0.x * sin_table_lookup(rotation_y)) + (m_3a0.z * cos_table_lookup(rotation_y)));
            if (m_414 < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(0x500);
                vfunc_102();
            } else {
                enemy_turn_and_move_on_ground((u8 *)this, 0x500, (f32) (m_410));
            }
            vfunc_89();
        }
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E5F64(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    Vec sp20;
    Vec sp14;
    Vec v;
    f32 d;
    s32 angle;
    s32 entry;
    switch (arg1) {
    case 4:
        shinowa->requested_action = 5;
        shinowa->set_field_378(4);
        shinowa->vfunc_96();
        shinowa->m_3c4 &= ~3;
        shinowa->m_3c4 |= 0x10000;
        shinowa->m_404 = 0;
        shinowa->m_410 = 0.0f;
        shinowa->m_3e0->clear_segments();
        shinowa->set_active();
        break;
    case 3:
        if (shinowa->m_404 == 5 || ((int)shinowa->get_flag_b4()) != 0) {
            if (shinowa->vfunc_102() == 0U) {
                shinowa->transition_enemy_state(9);
            } else {
                shinowa->transition_enemy_state(4);
            }
        }
        break;
    case 0:
        switch (shinowa->m_404) {
        case 0:
            shinowa->advance_animation();
            if (shinowa->motion_flags & 8) {
                shinowa->m_404 = 1;
            }
            shinowa->vfunc_102();
            shinowa->vfunc_89();
            break;
        case 1:
            shinowa->advance_animation();
            if (((TObjEneEpsilon *)shinowa)->update_death_check() != 0) {
                shinowa->enemy_copy_target_destination();
                shinowa->update_velocity();
                angle = (s32)(10430.38043493439 * atan2_float(shinowa->m_3a0.x, shinowa->m_3a0.z));
            } else {
                angle = shinowa->rotation_y;
            }
            shinowa->rotation_y = approach_angle_limited(shinowa->rotation_y, angle, 0x1000);
            if (shinowa->is_passing_frame(10.0f) != 0) {
                shinowa->m_404 = 2;
            }
            shinowa->vfunc_102();
            shinowa->vfunc_89();
            break;
        case 2:
            shinowa->advance_animation();
            if (((TObjEneEpsilon *)shinowa)->update_death_check() != 0) {
                shinowa->enemy_copy_target_destination();
                shinowa->update_velocity();
            }
            if (shinowa->frame + shinowa->play_speed >= 14.0f) {
                if (shinowa->check_body_collision_at(shinowa->rotation_y, shinowa->m_3ac - 20.0f) != 0) {
                    shinowa->m_404 = 5;
                } else {
                    d = shinowa->m_3ac - 20.0f;
                    VecCopy(&v, &shinowa->position);
                    v.x += shinowa->m_3a0.x * d;
                    v.y += 20.0f;
                    v.z += shinowa->m_3a0.z * d;
                    if (csnVecterUnder(&v, 0x15) != 0U) {
                        shinowa->m_404 = 3;
                        shinowa->m_414 = (shinowa->m_3ac - 20.0f) / 12.857143f;
                        shinowa->vfunc_91();
                        play_sound_effect(shinowa->remap_sound_for_area(0x4003AD11), &shinowa->position, 0, 0);
                    } else {
                        shinowa->m_404 = 5;
                    }
                }
            }
            shinowa->vfunc_102();
            shinowa->vfunc_89();
            break;
        case 3:
            shinowa->advance_animation();
            if (shinowa->frame + shinowa->play_speed >= 23.0f) {
                shinowa->m_404 = 4;
                shinowa->vfunc_92();
                play_sound_effect(shinowa->remap_sound_for_area(0x4003AD12), &shinowa->position, 0, 0);
                spawn_particle_effect(&shinowa->position, 0xF3);
            }
            shinowa->move_with_wall_slide_commit(shinowa->m_3a0.x, shinowa->m_3a0.z, shinowa->m_414);
            shinowa->vfunc_88();
            break;
        case 4:
            shinowa->advance_animation();
            if (shinowa->is_passing_frame(25.0f) != 0) {
                if (shinowa->enemy_check_target_valid() != 0) {
                    if (shinowa->m_390->select_melee_contact_body(shinowa, 1.0f) != 0) {
                        shinowa->m_390->receive_physical_attack(shinowa, 1.0f);
                        shinowa->m_390->apply_knockback_from_attacker((u8 *)shinowa, 3.0f);
                    }
                }
                play_sound_effect(shinowa->remap_sound_for_area(0x4003AD13), &shinowa->position, 0, 0);
            }
            shinowa->m_414 *= 0.85f;
            shinowa->move_with_wall_slide_on_ground(shinowa->m_3a0.x, shinowa->m_3a0.z, shinowa->m_414);
            shinowa->vfunc_89();
            break;
        }
        if (shinowa->m_404 != 0) {
            entry = (s32)TObjEneMe3ShinowaMirage__data_805D52AC->lookup(shinowa->frame);
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&shinowa->position);
                rotate_matrix_y(0, shinowa->rotation_y);
                mult_vec_array__10TObjPlayerFUll(0, entry, &sp14, 2);
                pop_matrix();
                shinowa->m_3e0->vfunc_6(&sp14, &sp20);
            }
        }
        break;
    case 5:
        shinowa->m_3c8 = shinowa->position.y;
        shinowa->m_3cc = 0.0f;
        shinowa->vfunc_92();
        shinowa->clear_field_388();
        break;
    }
}
}

#pragma pop
extern "C" {
void TObjEneMe3ShinowaMirage__sub_800E5CE4(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    s32 angle;
    TObjEneMe3ShinowaParams *info;
    switch (arg1) {
    case 4:
        shinowa->requested_action = 6;
        shinowa->set_field_378(6);
        shinowa->vfunc_96();
        shinowa->m_3c4 &= ~3;
        shinowa->m_3c4 |= 0x10000;
        shinowa->m_404 = 0;
        shinowa->m_408 = 0;
        shinowa->m_3e0->clear_segments();
        shinowa->m_3e4->clear_segments();
        break;
    case 3:
        if (shinowa->get_flag_b4() != 0) {
            shinowa->vfunc_107();
        }
        break;
    case 5:
        break;
    case 0:
        shinowa->advance_animation();
        switch (shinowa->m_404) {
        case 0:
            shinowa->vfunc_105();
            if (shinowa->frame < 20.0f) {
                if (((TObjEneEpsilon *)shinowa)->update_death_check() != 0) {
                    shinowa->enemy_copy_target_destination();
                    shinowa->update_velocity();
                    angle = (s32)(10430.38043493439 * atan2_float(shinowa->m_3a0.x, shinowa->m_3a0.z));
                } else {
                    angle = shinowa->rotation_y;
                }
                shinowa->rotation_y = approach_angle_limited(shinowa->rotation_y, angle, 0x300);
                shinowa->m_3a0.x = sin_table_lookup(shinowa->rotation_y);
                shinowa->m_3a0.z = cos_table_lookup(shinowa->rotation_y);
            }
            shinowa->apply_effect_pair();
            if (shinowa->frame >= 0.0f && shinowa->frame <= 5.0f) {
                info = TObjEneMe3ShinowaMirage__mirage_info_table[shinowa->m_3c0];
                move_to_shot_position__9TObjEneDDFfff(shinowa, info, shinowa->m_3a0.x, shinowa->m_3a0.z, info->m_8);
            } else {
                shinowa->vfunc_102();
            }
            if (shinowa->frame >= 25.0f) {
                shinowa->frame = 25.0f;
                shinowa->m_404 = 1;
            }
            break;
        case 1:
            shinowa->m_408++;
            if (shinowa->m_408 <= TObjEneMe3ShinowaMirage__mirage_info_table[shinowa->m_3c0]->m_20) {
                shinowa->frame = 25.0f;
            }
            shinowa->vfunc_102();
            break;
        }
        shinowa->vfunc_89();
        break;
    }
}

void TObjEneMe3ShinowaReal__sub_800E5950(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    switch (arg1) {
    case 4:
        shinowa->requested_action = 2;
        shinowa->set_field_378(7);
        shinowa->vfunc_96();
        shinowa->m_3c4 &= ~3;
        shinowa->m_3d8 = 0;
        shinowa->m_404 = 3;
        if (shinowa->vfunc_104(200.0f) != 0) {
            shinowa->enemy_copy_target_destination();
            shinowa->update_velocity();
            shinowa->m_40c = (s32)(10430.38043493439 * atan2_float(shinowa->m_3a0.x, shinowa->m_3a0.z));
            if (shinowa->check_body_collision_at(shinowa->m_40c + 0x8000, 80.0f) == 0) {
                shinowa->m_3a0.x *= -1.0f;
                shinowa->m_3a0.z *= -1.0f;
                shinowa->m_404 = 0;
                shinowa->m_410 = 7.111111f;
            }
        }
        shinowa->set_active();
        return;
    case 3:
        if (shinowa->m_404 == 3) {
            if (shinowa->sub_800E6FE0() != 0) {
                shinowa->transition_enemy_state(0xA);
            } else if ((shinowa->m_3c4 & 0x20000) || (shinowa->sub_800E701C() == 0)) {
                shinowa->m_3c4 &= ~0x30000;
                if ((TObjEneDD::check_v2_mode() != 0) && (shinowa->sub_800E701C() == 0)) {
                    shinowa->transition_enemy_state(0x10);
                } else {
                    shinowa->transition_enemy_state(4);
                }
            } else {
                shinowa->m_3c4 |= 0x20000;
                shinowa->transition_enemy_state(0xE);
            }
        }
        break;
    case 0:
        shinowa->advance_animation();
        switch (shinowa->m_404) {
        case 0:
            shinowa->rotation_y = approach_angle_limited(shinowa->rotation_y, shinowa->m_40c, 0x31C7);
            if (shinowa->frame + shinowa->play_speed >= 15.0f) {
                shinowa->m_404 = 1;
                shinowa->vfunc_91();
                play_sound_effect(shinowa->remap_sound_for_area(0x4003AD11), &shinowa->position, 0, 0);
            }
            shinowa->vfunc_102();
            shinowa->vfunc_89();
            return;
        case 1:
            if (shinowa->frame + shinowa->play_speed >= 24.0f) {
                shinowa->m_404 = 2;
                shinowa->vfunc_92();
                play_sound_effect(shinowa->remap_sound_for_area(0x4003AD12), &shinowa->position, 0, 0);
                spawn_particle_effect(&shinowa->position, 0xF3);
            }
            shinowa->move_clamped_on_ground(shinowa->m_3a0.x, shinowa->m_3a0.z, shinowa->m_410);
            shinowa->vfunc_88();
            return;
        case 2:
            if (shinowa->get_flag_b4() != 0) {
                shinowa->m_404 = 3;
            }
            shinowa->vfunc_102();
            shinowa->vfunc_89();
            return;
        }
        break;
    case 5:
        shinowa->vfunc_92();
        shinowa->clear_field_388();
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E54E8(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    Vec save_pos;
    Vec save_center;
    Vec dest;
    s32 rot[3];
    f32 v;
    Vec *home = &shinowa->m_418;

    switch (arg1) {
    case 4: {
        shinowa->m_3c4 &= ~3;
        shinowa->vfunc_96();
        shinowa->vfunc_94();
        shinowa->m_404 = 0;
        shinowa->m_408 = 0;
        shinowa->m_410 = 1.0f;
        shinowa->m_37c = 30.0f;
        shinowa->m_40c = ((shinowa->m_3d4 - (s32)floor_to_float(2.5f)) * 0x3333) / 40;
        VecCopy(home, &shinowa->position);
        shinowa->m_424 = NULL;
        shinowa->m_428 = NULL;
        shinowa->set_active();
        break;
    }
    case 3: {
        if (shinowa->m_404 >= 40) {
            TObjEneMe3Shinowa__sub_800E7268(shinowa);
            s32 r = collect_target_candidates__9TObjEneDDFlf(shinowa, 40000.0f);
            if (r > 0) {
                enemy_set_target_id(shinowa, enemy_target_candidate_table[r - 1].id);
                shinowa->transition_enemy_state(4);
            } else {
                shinowa->transition_enemy_state(11);
            }
        }
        break;
    }
    case 0:
        shinowa->advance_animation();
        shinowa->m_404++;
        if (transform_relative_position__9TObjEneDDFPv(shinowa, shinowa->m_390) != 0) {
            if ((s16)get_room__8TObjBaseFv(shinowa) == (s16)get_room__8TObjBaseFv(shinowa->m_390)) {
                shinowa->enemy_copy_target_destination();
            }
        }
        shinowa->update_velocity();
        rotate_xz_pair_by_angle(&shinowa->m_3a0.x, &shinowa->m_3a0.z, shinowa->m_40c);
        v = shinowa->m_3ac;
        if (v > 80.0f) {
            v -= 3.0f;
            if (v < 80.0f) {
                v = 80.0f;
            }
        } else if (v < 80.0f) {
            v += 3.0f;
            if (v > 80.0f) {
                v = 80.0f;
            }
        }
        VecCopy(&save_pos, &shinowa->position);
        VecCopy(&save_center, (Vec *)&shinowa->m_2fc);
        VecCopy(&shinowa->position, &shinowa->m_394);
        VecCopy((Vec *)&shinowa->m_2fc, &shinowa->position);
        shinowa->m_300 += 20.0f;
        v *= shinowa->m_410;
        calc_wall_clamped_destination(shinowa, &dest, -shinowa->m_3a0.x, -shinowa->m_3a0.z, v);
        if (shinowa->vfunc_18((u8 *)&dest) == 0) {
            shinowa->m_410 *= 0.8f;
            VecCopy(&shinowa->position, &save_pos);
            VecCopy((Vec *)&shinowa->m_2fc, &save_center);
        } else {
            shinowa->m_410 = 1.0f;
            VecCopy(&shinowa->position, &save_pos);
            VecCopy((Vec *)&shinowa->m_2fc, &save_center);
            subtract_vector(&dest, &shinowa->position);
            f32 len = normalize_vector_xz(&dest);
            shinowa->move_clamped_on_ground(dest.x, dest.z, len);
        }
        shinowa->rotation_y = (s32)(10430.38043493439 * atan2_float(shinowa->m_3a0.x, shinowa->m_3a0.z));
        if (shinowa->m_40c != 0) {
            rot[0] = 0;
            if (shinowa->m_40c > 0) {
                rot[1] = shinowa->rotation_y;
            } else {
                rot[1] = shinowa->rotation_y - 0x8000;
            }
            rot[2] = -0x4000;
            if (shinowa->m_424 == NULL) {
                shinowa->m_424 = (TParticleCtrl *)create_particle_emitter(&shinowa->position, 0x115);
                if (shinowa->m_424 != NULL) {
                    shinowa->m_424->enable();
                    shinowa->m_424->set_flags(2);
                }
            } else {
                shinowa->m_424->set_direction(rot);
                shinowa->m_424->set_position(&shinowa->position);
            }
            if (shinowa->m_428 == NULL) {
                shinowa->m_428 = (TParticleCtrl *)create_particle_emitter(&shinowa->position, 0x116);
                if (shinowa->m_428 != NULL) {
                    shinowa->m_428->enable();
                    shinowa->m_428->set_flags(2);
                }
            } else {
                shinowa->m_428->set_direction(rot);
                shinowa->m_428->set_position(&shinowa->position);
            }
        }
        shinowa->vfunc_88();
        break;
    case 5:
        shinowa->vfunc_93();
        shinowa->m_37c = 10.0f;
        if (shinowa->m_424 != NULL) {
            shinowa->m_424->queue_destruction();
            shinowa->m_424 = NULL;
        }
        if (shinowa->m_428 != NULL) {
            shinowa->m_428->queue_destruction();
            shinowa->m_428 = NULL;
        }
        shinowa->clear_field_388();
        break;
    }
}

void TObjEneMe3ShinowaMirage::state_cast_support(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 7;
        set_field_378(0xA);
        vfunc_96();
        m_3c4 &= ~3;
        m_404 = 0;
        m_408 = 0;
        break;
    case 3:
        if (m_408 > TObjEneMe3ShinowaMirage__mirage_info_table[m_3c0]->m_1c) {
            transition_enemy_state(4);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        switch (m_404) {
        case 0:
            if (get_flag_b4() != 0) {
                TObjEneMe3ShinowaMirage__sub_800E6F0C(this);
                if (TObjEneDD::check_v2_mode() != 0) {
                    m_404 = 2;
                } else {
                    m_404 = 1;
                }
                m_408 = 0;
            }
            break;
        case 1:
            m_408++;
            break;
        case 2:
            m_408++;
            if (m_408 == 5) {
                TTecSifta::create(this, &position, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[m_3c0]->m_18)));
            } else if (m_408 == 0xA) {
                create__10TTecDebandFlll(this, &position, TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[m_3c0]->m_18));
                m_404 = 1;
                m_408 = 0;
            }
            break;
        }
        vfunc_102();
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E5220(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    switch (arg1) {
    case 4:
        shinowa->requested_action = 8;
        shinowa->set_field_378(0xB);
        shinowa->m_3c4 &= ~3;
        shinowa->vfunc_95();
        shinowa->m_3d8 = 0;
        shinowa->m_404 = 0;
        return;
    case 3:
        if (shinowa->update_linked_position(200.0f) != 0) {
            shinowa->transition_enemy_state(4);
        } else if (shinowa->m_404 >= 0x5A) {
            shinowa->transition_enemy_state(9);
        }
        return;
    case 0:
        shinowa->m_404++;
        shinowa->advance_animation();
        shinowa->vfunc_102();
        break;
    case 5:
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E50D8(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    u32 flags;
    switch (arg1) {
    case 4:
        shinowa->requested_action = 7;
        shinowa->set_field_378(4);
        shinowa->vfunc_95();
        shinowa->m_3c4 &= ~3;
        flags = shinowa->m_3c4;
        if (flags & 0x80000) {
            shinowa->m_3c4 = flags & ~0x80000;
            shinowa->m_404 = 2;
            return;
        }
        shinowa->m_3e8.reset_color();
        shinowa->m_404 = 1;
        return;
    case 3:
        if (shinowa->m_404 == 2) {
            shinowa->transition_enemy_state(0);
        }
    case 5:
        return;
    case 0:
        shinowa->advance_animation();
        switch (shinowa->m_404) {
        case 0:
            if (shinowa->get_flag_b4() != 0) {
                shinowa->m_404 = 1;
            }
            break;
        case 1:
            if (shinowa->m_3e8.decay_value_toward_floor() != 0) {
                shinowa->m_404 = 2;
            }
            break;
        }
        shinowa->vfunc_102();
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E4FE8(TObjEneMe3Shinowa *shinowa, s32 arg1) {
    Vec dir;
    f32 len;
    switch (arg1) {
    case 4:
        shinowa->requested_action = 3;
        shinowa->advance_animation();
        shinowa->set_active();
        break;
    case 3:
        if (shinowa->get_flag_b4() != 0) {
            shinowa->transition_enemy_state(shinowa->m_378);
        }
        break;
    case 0:
        shinowa->advance_animation();
        VecCopy(&dir, (Vec *)&shinowa->x_speed);
        len = normalize_vector_xz(&dir);
        shinowa->move_clamped_on_ground(dir.x, dir.z, len);
        shinowa->x_speed *= 0.8f;
        shinowa->m_310 *= 0.8f;
        shinowa->vfunc_89();
        break;
    case 5:
        shinowa->clear_attack_receipts();
        shinowa->clear_field_388();
        break;
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneMe3ShinowaMirage::state_break_apart(s32 arg1) {
    Vec effect_pos;
    Vec pos;
    switch (arg1) {
    case 4:
        requested_action = 4;
        refresh_and_send_entity_flags();
        vfunc_94();
        m_3c4 &= ~3;
        m_404 = 0;
        break;
    case 3:
    case 5:
        break;
    case 0:
        switch (m_404) {
        case 0:
            advance_animation();
            if (is_passing_frame(13.0f) != 0 || is_passing_frame(25.0f) != 0) {
                play_sound_effect(remap_sound_for_area(0x4003AD12), &position, 0, 0);
            }
            if (get_flag_b4() != 0) {
                m_404 = 1;
                m_408 = 0;
                effect_pos.x = 0.0f;
                effect_pos.y = 10.0f;
                effect_pos.z = 20.0f;
                ((TObjBoss2Tunnel *)&effect_pos)->init_zako(&position, rotation_y);
                TObjPlayer::spawn_effect_f8((s32)&effect_pos, 0x14);
            }
            break;
        case 1:
            m_408++;
            if (m_408 >= 0x14) {
                m_404 = 2;
                m_3c4 |= 2;
                TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe3ShinowaMirage__data_805D52A0, (s32)shinowa_mirage_breakup_params, texlist, (s32)&position, rotation_y);
                VecCopy(&pos, &position);
                pos.x += 20.0f * sin_table_lookup(rotation_y);
                pos.z += 20.0f * cos_table_lookup(rotation_y);
                ((TObjPlayer *)&pos)->trigger_dell_biter_events();
                play_sound_effect(remap_sound_for_area(0x4003AD16), &position, 0, 0);
            }
            vfunc_102();
            break;
        case 2:
            queue_destruction();
            break;
        }
        break;
    }
}
}

#pragma pop
extern "C" {
void TObjEneMe3Shinowa::vfunc_114(s32) {  }

void TObjEneMe3Shinowa::vfunc_115(s32) {  }

void TObjEneMe3Shinowa::vfunc_116(s32) {  }

void TObjEneMe3ShinowaMirage::advance_camera_ctrl_step() {
    if ((s32) TObjEneMe3ShinowaMirage__render_node_index == 1) {
        get_camera_ctrl__9TObjEneDDFv(&TObjEneMe3ShinowaMirage__data_80500FC0, &lbl_80500FF4);
    }
    TObjEneMe3ShinowaMirage__render_node_index += 1;
}

void TObjEneMe3Shinowa::render() {
    s32 detail;
    s32 draw;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_118();
        return;
    }
    sub_800E6FE0();
    if (m_3c4 & 2) {
        detail = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        detail = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail != 0) {
        update_player_state_default();
        TObjFish::set_global_param(texlist);
        update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        for (i = 0; i < 3; i++) {
            if (lbl_80501000[i] != NULL) {
                *lbl_80501000[i] = m_3d0;
            }
        }
        draw = 1;
        if ((update_effect() != 0) && (defer_render() != 0)) {
            draw = 0;
        }
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(&position);
            translate_matrix(0, 0.0f, m_3cc, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneMe3ShinowaMirage__render_node_index = 0;
            set_chunk_model_node_callback((s32)((void *)(TObjEneMe3ShinowaMirage::advance_camera_ctrl_step)));
            if (detail == 1) {
                TObjMotion::draw();
            } else {
                draw_motion_model();
            }
            set_chunk_model_node_callback(NULL);
            pop_matrix();
        }
        dispatch_if_active();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
        VecCopy((Vec *)&m_2fc, &lbl_80500FF4);
    } else if ((get_main_phase() == 0xF) || (is_split_screen() == 0)) {
        VecCopy((Vec *)&m_2fc, &position);
    }
    TParticleCtrl::end_effect_render();
}

void TObjEneMe3Shinowa::update_mirage() { if (get_target_info() != 0) { fn_800E762C(this); sub_800E6F64(); } }
}

#pragma push
#pragma pool_data off
extern "C" {
// Debug viewer: the mirage and gold-texture switches, then the model posed in
// action parameters[2] at frame parameters[3] (unposed when mode is not 0).
void TObjEneMe3Shinowa::vfunc_118() {
    s32 gold;
    NJS_TEXNAME *textures;
    u32 saved_texaddr[3];
    s32 i;
    if (get_target_info() != 0) {
        if (sub_800E701C() != 0) {
            debug_printf_at(pack_debug_text_position(0, 0), "MIRAGE:ENABLE");
        } else {
            debug_printf_at(pack_debug_text_position(0, 0), "MIRAGE:DISABLE");
        }
        if (sub_800E6FE0() != 0) {
            debug_printf_at(pack_debug_text_position(0, 1), "TEX:GOLD");
        } else {
            debug_printf_at(pack_debug_text_position(0, 1), "TEX:NORMAL");
        }
    }
    gold = sub_800E6FE0();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        TObjFish::set_global_param(texlist);
        TObjPlayer::toggle_particle_effect();
        if (gold != 0) {
            textures = ((NJS_TEXLIST *)texlist)->textures;
            for (i = 0; i < 3; i++) {
                saved_texaddr[i] = textures[i + 3].texaddr;
            }
            for (i = 0; i < 3; i++) {
                textures[i + 3].texaddr = textures[i].texaddr;
            }
        }
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, 1.0f, 1.0f,
                     1.0f);
        for (i = 0; i < 3; i++) {
            if (lbl_80501000[i] != NULL) {
                *lbl_80501000[i] = 0xB000FFB0;
            }
        }
        if (mode == 0) {
            s32 action = (s32)parameters[2];
            AnimationMotion *motion;
            f32 at_frame;
            if (action < 0) {
                action = 0;
            } else if (action >= 11) {
                action = 10;
            }
            motion = motion_list[action_table[action].motion].motion;
            at_frame = parameters[3];
            if (at_frame < 0.0f) {
                at_frame = 0.0f;
            } else if (at_frame > (f32)(motion->frameCount - 1)) {
                at_frame = (f32)(motion->frameCount - 1);
            }
            set_motion_packed_rotation();
            draw_model_motion(model, motion, at_frame);
            clear_motion_packed_rotation();
            current_motion = (NJS_MOTION *)motion;
            frame = at_frame;
            print_float_padded(pack_debug_text_position(0, 4), 5, get_node_world_y());
        } else {
            model_render_flags &= ~0x400;
            draw_chunk_object(model);
        }
        pop_matrix();
        if (gold != 0) {
            textures = ((NJS_TEXLIST *)texlist)->textures;
            for (i = 0; i < 3; i++) {
                textures[i + 3].texaddr = saved_texaddr[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}
}

#pragma pop
extern "C" {
TObjEneMe3ShinowaReal *TObjEneMe3ShinowaReal::create() {
    return new TObjEneMe3ShinowaReal(tl_04, this);
}

TObjEneMe3ShinowaReal::TObjEneMe3ShinowaReal(TObject *parent, void *set_data) : TObjEneMe3Shinowa(parent) {
    s32 i;
    m_name = TObjEneMe3ShinowaReal_class_name;
    invoke_initialization_hook(set_data);
    fn_800E762C(this);
    init_enemy();
    m_3d4 = 0;
    m_3c4 &= ~0x1000;
    for (i = 0; i < 4; i++) {
        m_42c[i] = 0xFFFF;
    }
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneMe3ShinowaReal::~TObjEneMe3ShinowaReal() {}

void TObjEneMe3ShinowaReal::vfunc_63() {
    try_spawn_mirages();
    TObjEneMe3Shinowa::vfunc_63();
}

void TObjEneMe3ShinowaReal::vfunc_62() {
    try_spawn_mirages();
    TObjEneMe3Shinowa::vfunc_62();
}

void TObjEneMe3ShinowaReal::try_spawn_mirages() {
    if (m_3c4 & 0x10) {
        sub_800E7250();
        spawn_mirages();
    }
}

u16 TObjEneMe3ShinowaReal__sub_800E45CC(TObjEneMe3Shinowa *shinowa) { return shinowa->m_38c; }

TObjEneMe3ShinowaMirage *TObjEneMe3ShinowaReal::get_or_create_mirage(s32 index) {
    TObjEneMe3ShinowaMirage *mirage;
    if (m_42c[index] == 0xFFFF) {
        u16 id = entity_id;
        s32 n = index + 1;
        mirage = create__23TObjEneMe3ShinowaMirageFPvPv(this, (u16)(id + n), set_index + n, id);
        if (mirage != NULL) {
            m_42c[index] = get_entity_id(mirage);
        }
    } else {
        mirage = (TObjEneMe3ShinowaMirage *)find_entity_by_id(m_42c[index]);
    }
    return mirage;
}

void TObjEneMe3ShinowaReal::vfunc_107() {
    m_3d8++;
    if (m_3d8 >= 2) {
        try_spawn_mirages();
        transition_enemy_state(7);
        return;
    }
    transition_enemy_state(4);
}

void TObjEneMe3ShinowaReal::vfunc_111() { try_spawn_mirages(); }

void TObjEneMe3ShinowaReal::spawn_mirages() {
    int i;
    for (i = 0; i < 4; i++) {
        get_or_create_mirage(i)->init_mirage();
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneMe3ShinowaReal::vfunc_114(s32 arg1) {
    s32 i;
    s32 n;
    Vec pos;
    switch (arg1) {
    case 4:
        requested_action = 7;
        set_field_378(0xE);
        vfunc_96();
        m_3c4 &= ~3;
        m_424 = NULL;
        break;
    case 3:
        if (get_flag_b4() != 0) {
            m_3b8 = m_3bc;
            i = 0;
            if (vfunc_99() != 0 || is_player_entity_id(m_38c) != 0) {
                if (transform_relative_position__9TObjEneDDFPv(this, m_390) != 0) {
                    i = 1;
                }
            } else {
                enemy_clear_target__12TObjEneDD_STFUs(this);
            }
            if (i == 1) {
                enemy_copy_target_destination();
                m_3d4 = (s32)(5.0f * random_ratio());
                i = 0;
                n = 0;
                for (; i < 5; i++) {
                    if (m_3d4 != i) {
                        get_or_create_mirage(n++)->activate_mirage(i);
                    }
                }
                transition_enemy_state(8);
                play_sound_effect(remap_sound_for_area(0x4003AD15), &position, 0, 0);
            } else {
                try_spawn_mirages();
                transition_enemy_state(4);
            }
        }
        break;
    case 0:
        advance_animation();
        if (frame >= 12.0f) {
            if (m_424 == NULL) {
                m_424 = create_particle_emitter(&position, 0x114);
                if (m_424 != NULL) {
                    m_424->enable();
                }
            } else {
                VecCopy(&pos, &position);
                pos.x = 15.0f * sin_table_lookup(rotation_y) + pos.x;
                pos.y += 17.0f;
                pos.z = 15.0f * cos_table_lookup(rotation_y) + pos.z;
                m_424->set_position(&pos);
            }
        }
        vfunc_102();
        vfunc_89();
        break;
    case 5:
        if (m_424 != NULL) {
            m_424->queue_destruction();
            m_424 = NULL;
        }
        break;
    }
}

void TObjEneMe3ShinowaReal::vfunc_116(s32 arg1) {
    Vec pos;
    u32 flags;
    TParticleCtrl *emitter;
    switch (arg1) {
    case 4:
        requested_action = 7;
        set_field_378(0x10);
        vfunc_96();
        m_3c4 &= ~2;
        m_3c4 |= 1;
        m_404 = 0;
        m_424 = NULL;
        return;
    case 3:
        if (m_404 == 3) {
            try_spawn_mirages();
            transition_enemy_state(4);
        }
        return;
    case 0:
        switch (m_404) {
        case 0:
            advance_animation();
            if (get_flag_b4() != 0) {
                flags = m_3c4;
                if (flags & 0x80000) {
                    m_3e8.reset_obstruction_fade();
                    m_404 = 1;
                } else {
                    m_3c4 = flags | 0x80000;
                    m_3e8.reset_color();
                    m_404 = 2;
                }
            }
            if (frame >= 12.0f) {
                if (m_424 == NULL) {
                    m_424 = create_particle_emitter(&position, 0x114);
                    emitter = m_424;
                    if (emitter != NULL) {
                        emitter->enable();
                    }
                } else {
                    VecCopy(&pos, &position);
                    pos.x += 15.0f * sin_table_lookup(rotation_y);
                    pos.y += 17.0f;
                    pos.z += 15.0f * cos_table_lookup(rotation_y);
                    m_424->set_position(&pos);
                }
            }
            break;
        case 1:
            if (m_3e8.advance_toward_max() != 0) {
                m_404 = 3;
                m_3c4 &= ~0x80000;
            }
            break;
        case 2:
            if (m_3e8.decay_value_toward_floor() != 0) {
                m_404 = 3;
            }
            break;
        }
        vfunc_102();
        vfunc_89();
        return;
    case 5:
        emitter = m_424;
        if (emitter != NULL) {
            emitter->queue_destruction();
            m_424 = NULL;
        }
        break;
    }
}
}

#pragma pop
extern "C" {
TObjEneMe3ShinowaMirage *TObjEneMe3ShinowaMirage::create(void *arg1, void *arg2) {
    return new TObjEneMe3ShinowaMirage(tl_04, (TObjEneMe3ShinowaReal *)this, (s32)arg1, (s32)arg2);
}

TObjEneMe3ShinowaMirage::TObjEneMe3ShinowaMirage(TObject *parent, TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index) : TObjEneMe3Shinowa(parent) {
    CollisionBody *body;

    m_name = TObjEneMe3ShinowaMirage__class_name;
    m_42c = get_entity_id(owner);
    init_common_from((u8 *)owner);
    parameters[1] = owner->parameters[1];
    fn_800E762C(this);
    this->entity_id = entity_id;
    this->set_index = set_index;
    init_enemy();
    m_3d4 = 0;
    m_3c4 |= 0x1000;
    set_flag_0x100();
    m_3d0 = 0xB000FFB0;
    position.y = -500.0f;
    prev_position.y = -500.0f;
    body = bodies;
    body->center.y = -500.0f;
    actorFlags |= 0x800;
    m_430.a = 0.0f;
    m_430.r = 0.0f;
    m_430.g = 0.0f;
    m_430.b = 0.0f;
    m_3e8.set_rate_from_divisor(0);
    m_3e8.reset_color();
    mode = 8;
    dispatch_action(mode, 4);
}

TObjEneMe3ShinowaMirage::~TObjEneMe3ShinowaMirage() {}

void TObjEneMe3ShinowaMirage::run_task() {
    TObjCollidable *owner;

    if ((owner = find_entity_by_id(m_42c)) == NULL || owner->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
        return;
    }
    if (!(m_3c4 & 0x100)) {
        TObjEneMe3Shinowa::run_task();
    }
}

void TObjEneMe3ShinowaMirage::vfunc_63() {
    if (mode != 15) {
        transition_enemy_state(15);
    }
}

void TObjEneMe3ShinowaMirage::vfunc_62() {
    if (mode != 15) {
        transition_enemy_state(15);
    }
    clear_attack_receipts();
}

void TObjEneMe3ShinowaMirage::vfunc_105() {  }

s32 TObjEneMe3ShinowaMirage::can_hit_same_target() { return 0; }

void TObjEneMe3ShinowaMirage::vfunc_107() { transition_enemy_state(4); }

void TObjEneMe3ShinowaMirage::update_player_state_default() {  }

void TObjEneMe3ShinowaMirage::activate_mirage(s32 index) {
    TObjCollidable *owner;

    owner = find_entity_by_id(m_42c);
    if (owner != NULL) {
        VecCopy(&position, &owner->position);
        VecCopy(&prev_position, &position);
        VecCopy(&bodies->center, &position);
        copy_xyz(&rotation_x, &owner->rotation_x);
        actorFlags &= ~0x800;
        actorFlags = 0x20000000;
        hp = hpmax;
        m_3d4 = index;
        enemy_set_target_id(this, TObjEneMe3ShinowaReal__sub_800E45CC((TObjEneMe3Shinowa *)owner));
        m_430.a = 0.0f;
        m_3c4 &= ~0x200;
        requested_action = 10;
        advance_animation();
        frame = (f32)(u32)(current_motion->nbFrame - 1);
        transition_enemy_state(8);
        clear_mirage();
    }
}

void TObjEneMe3ShinowaMirage::init_mirage() { transition_enemy_state(15); }

void TObjEneMe3ShinowaMirage::set_flag_0x100() {
    m_3c4 |= 0x100;
    vfunc_94();
}

void TObjEneMe3ShinowaMirage::clear_mirage() {
    m_3c4 &= ~0x100;
    vfunc_93();
}

s32 TObjEneMe3ShinowaMirage::update_effect() {
    model_render_flags |= 0x820;
    set_constant_material(&m_430);
    set_chunk_material_override_pair(0xFF00, 0x800);
    return 0;
}

void TObjEneMe3ShinowaMirage::dispatch_if_active() {
    MaterialColorFade *fade = &m_3e8;
    fade->clear_flag_and_notify();
}

void TObjEneMe3ShinowaMirage::apply_effect_pair() {  }

void TObjEneMe3ShinowaMirage::render() {
    if (!(m_3c4 & 0x100)) {
        TObjEneMe3Shinowa::render();
    }
}

void TObjEneMe3ShinowaMirage::vfunc_115(s32 arg1) {
    switch (arg1) {
    case 4:
        m_3c4 &= ~3;
        m_3c4 |= 0x200;
        vfunc_94();
        m_430.a = 0.0f;
        return;
    case 3:
        if (m_430.a <= -1.0f) {
            m_3c4 &= ~0x200;
            set_flag_0x100();
            position.y = -500.0f;
            prev_position.y = -500.0f;
            bodies->center.y = -500.0f;
            actorFlags |= 0x800;
        }
    case 5:
        return;
    case 0:
        m_430.a -= 0.1f;
        vfunc_102();
        break;
    }
}
}
