#define TOBJECT_OUT_OF_LINE_HELPERS
#include <stddef.h>
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/enemy/stelth/StelthData.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/stelth/TObjEneMe3StelthReal.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/player/TObjPlayer.h"
#include "pso/animation/MotionContext.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/BmlResource.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/unk/TLobby.h"
#include "pso/object/trap/TOTrapAncient02.h"
#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecSifta.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/npc/TObjNpcEnemy_803D8090.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth_803DC82C.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"
#include "pso/enemy/dd/TObjEneDD_800B9A34.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa_800D72A4.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma readonly_strings on

extern "C" {
void TObjEneGibbles__sub_800D8988(Vec *pos);
extern const f32 TObjEneMe3Stelth__data_805DA808;
extern const f32 TObjEneMe3Stelth__data_805DA80C;
extern const f32 lbl_805DA814;
extern const f32 lbl_805DA818;
}

// Class names the two constructors store in m_name (.sdata).
const char *TObjEneMe3Stelth__class_name = stelth_class_name;
const char *TObjEneMe3StelthReal__class_name = stelth_real_class_name;

extern "C" {

extern const f32 lbl_805DA81C;

}

extern "C" {
s32 is_split_screen();
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
s32 select_enemy_destination(void *, Vec *, int);
s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 enemy_turn_toward_dest(void *, s32);
extern StelthBehaviorParams *TObjEneMe3Stelth__behavior_params_by_variant[];
extern s32 game_difficulty_selection;
extern const f32 TObjEneMe3Stelth__data_805DA820;
extern const f32 TObjEneMe3Stelth__data_805DA824;
u16 get_entity_id(void *);
u32 get_valid_target_player__10TNpcPlayerFv(int);
extern CollisionBody TObjEneMe3Stelth__collision_body_template;
}
void move_with_wall_slide(u8 *arg0);


extern "C" {
BmlResource *TObjEneMe3Stelth__bml_resource;
s32 TObjEneMe3Stelth__render_node_index;
TUnk_8048FA00 *TObjEneMe3Stelth__breakup_model;
SampledMotionPoints *TObjEneMe3Stelth__trail_buffer;
s32 stelth_projection_texture_handle;
}

extern "C" {
f32 lbl_805010E0[3];
__declspec(section ".data") s32 TObjEneMe3Stelth__base_params_by_variant[2];
__declspec(section ".data") s32 TObjEneMe3Stelth__attack_params_by_variant[2];
__declspec(section ".data") s32 TObjEneMe3Stelth__resistance_params_by_variant[2];
__declspec(section ".data") StelthBehaviorParams *TObjEneMe3Stelth__behavior_params_by_variant[2];
__declspec(section ".data") NJS_TEXLIST TObjEneMe3Stelth__alternate_texture_list;
f32 lbl_80501114[3];
u32 *TObjEneMe3Stelth__material_color_pointers[4];


}

extern "C" {
s32 set_global_param__8TObjFishFl(s32);
}

extern "C" {
s32 is_main_phase_15__9TObjEneDDFv();
s32 dispatch_input_to_instance__18TAdEnterPasswordGCFi(void *);
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
}

extern "C" {
void TObjEneMe3Stelth__sub_800F290C(TObjEneMe3Stelth *stelth, s32 arg1);
void TObjEneMe3Stelth__sub_800F2270(TObjEneMe3Stelth *stelth, s32 arg1);



void action__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1);

}


extern const f32 lbl_805DA888;
extern const f32 lbl_805DA88C;
extern "C" {
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
void TObjEneMe3Stelth__sub_800F3FE4(TObjEneMe3Stelth *stelth, s32 arg1);
f32 *TBoss3Volopt__sub_800F059C(void *);
extern const f32 lbl_805DA890;
f64 atan2_float(f32, f32);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
extern const f32 lbl_805DA810;
void TObjEneMe3Stelth__sub_800F348C(TObjEneMe3Stelth *stelth, s32 arg1);
s32 move_to_shot_position__9TObjEneDDFfff(void *, int, f32, f32, f32);
void TObjEneMe3Stelth__sub_800F3214(TObjEneMe3Stelth *stelth, s32 arg1);
s32 create__10TTecDebandFlll(void *, void *, s32);
void run_walk_state__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1);





s32 is_locally_controlled__10TObjPlayerFPv(void *);
u32 get_item_field_6__10TObjPlayerFPv(void *);
f32 fabs_float(f32);
s32 get_item_id__5TItemFv(void);
int select_and_apply_target__12TObjEneDD_STFf(void*);
void TObjEneDD__sub_800BA438(void *, void *);
void handle_message__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1);
s32 update_enemy_collision_flags__14TObjCollidableFv(void *);
s32 check_object_collisions__14TObjCollidableFv(void *);
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *, s32);

extern const f32 lbl_805DA894;
extern f32 lbl_805DA898;
extern f32 lbl_805DA89C;
extern const f32 lbl_805DA8A0;
extern const f32 lbl_805DA8A4;
extern const f32 lbl_805DA8A8;
extern const f32 lbl_805DA8AC;

extern void *lbl_80497710[2];
extern void *lbl_80497718[12];
extern void *stelth_bml_resource_desc[4];
extern void *lbl_80497758[2];
extern void *lbl_80497760[12];
extern void *me3_stelth_bml_resource_desc[4];
void *TObjEneMe3Stelth__shared_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
CollisionBody TObjEneMe3Stelth__collision_body_template = {
    {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f,
};
__declspec(section ".data") void *lbl_80497710[2] = {
    (void *)stelth_model, (void *)0x0,
};
void *lbl_80497718[12] = {
    (void *)stelth_t_wait_motion, (void *)stelth_apper_motion, (void *)stelth_backstep_motion, (void *)stelth_bareta_motion,
    (void *)stelth_damage_motion, (void *)stelth_death_motion, (void *)stelth_f_attack_motion, (void *)stelth_sword_motion,
    (void *)stelth_transform_motion, (void *)stelth_wait_motion, (void *)stelth_walk_motion, (void *)0x0,
};
void *stelth_bml_resource_desc[4] = {
    (void *)stelth_bml, (void *)&lbl_80497710, (void *)&lbl_80497718, (void *)0x1000b,
};
__declspec(section ".data") void *lbl_80497758[2] = {
    (void *)stelth_low_model, (void *)0x0,
};
void *lbl_80497760[12] = {
    (void *)stelth_t_wait_motion, (void *)stelth_apper_motion, (void *)stelth_backstep_motion, (void *)stelth_bareta_motion,
    (void *)stelth_damage_motion, (void *)stelth_death_motion, (void *)stelth_f_attack_motion, (void *)stelth_sword_motion,
    (void *)stelth_transform_motion, (void *)stelth_wait_motion, (void *)stelth_walk_motion, (void *)0x0,
};
void *me3_stelth_bml_resource_desc[4] = {
    (void *)stelth_low_bml, (void *)&lbl_80497758, (void *)&lbl_80497760, (void *)0x1000b,
};
TObjMotionAction TObjEneMe3Stelth__animation_descriptors[13] = {
    {MOTION_MODE_LOOP, 0, 0, 0.5f, ACTION_NO_BLEND_IN},
    {MOTION_MODE_ONCE, 0, 1, 0.7f, ACTION_NO_BLEND_IN},
    {MOTION_MODE_LOOP, 0, 9, 0.5f, ACTION_NO_BLEND_IN},
    {MOTION_MODE_ONCE, 0, 2, 0.8f, 0},
    {MOTION_MODE_ONCE, 0, 4, 0.4f, 0},
    {MOTION_MODE_ONCE, 0, 5, 0.6f, 0},
    {MOTION_MODE_ONCE, 0, 6, 0.7f, 0},
    {MOTION_MODE_ONCE, 0, 7, 1.0f, 0},
    {MOTION_MODE_ONCE, 0, 8, 1.0f, 0},
    {MOTION_MODE_LOOP, 0, 9, 0.5f, 0},
    {MOTION_MODE_LOOP, 0, 10, 1.1f, 0},
    {MOTION_MODE_ONCE, 0, 3, 0.7f, 0},
    {MOTION_MODE_ONCE, 0, 8, 1.0f, 0},
};


}

extern "C" {
s32 free_bin_model_request(BmlResource *, s32);
void mem_free(void *p);

int create__20TObjEneMe3StelthRealFPv(void*);


s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
void *mem_alloc(u32 size);
extern const f32 lbl_805DA8B0;
extern const f32 lbl_805DA8B4;
extern const f32 lbl_805DA8B8;
extern const f32 lbl_805DA8BC;

}


extern "C" {
void draw_model__16TObjEneMe3StelthFPv(TObjEneMe3Stelth *stelth) {
    stelth->draw_ginja_motion_model();
}
}

extern "C" {
void TObjEneDD_ST::sub_800F5874(s32 arg1) {
    this->m_11c = (s16) (this->m_11c | arg1);
}
}

extern "C" {
void TObjEneDD_ST::sub_800F5864(s32 arg1) {
    this->m_11c = (s16) (this->m_11c & ~arg1);
}
}

extern "C" {
void TObjEneMe3Stelth::load_shared_resources() {
    s32 i;
    NJS_TEXLIST *src;
    s32 n;
    StelthBehaviorParams *d;
    u32 m;
    s32 *q;
    AnimationMotion *motion;
    void *p;

    lbl_805010E0[0] = 0.0f;
    lbl_805010E0[1] = 0.0f;
    lbl_805010E0[2] = 0.0f;
    if (is_split_screen() != 0) {
        TObjEneMe3Stelth__bml_resource = (BmlResource *)load_enemy_bml_resource((u8 *)me3_stelth_bml_resource_desc);
    } else {
        TObjEneMe3Stelth__bml_resource = (BmlResource *)load_enemy_bml_resource((u8 *)stelth_bml_resource_desc);
    }
    src = (NJS_TEXLIST *)TObjEneMe3Stelth__bml_resource->models->m_c;
    n = src->nbTexture;
    TObjEneMe3Stelth__alternate_texture_list.nbTexture = n;
    TObjEneMe3Stelth__alternate_texture_list.textures = (NJS_TEXNAME *)mem_alloc(n * sizeof(NJS_TEXNAME));
    for (i = 0; i < n; i++) {
        ((TObjPlayer *)&TObjEneMe3Stelth__alternate_texture_list.textures[i])->copy_vec3(&src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        TObjEneMe3Stelth__alternate_texture_list.textures[i].texaddr = TObjEneMe3Stelth__alternate_texture_list.textures[i + 3].texaddr;
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__base_params_by_variant[i] = register_boss__6TLobbyFl(lbl_8043D47C[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__attack_params_by_variant[i] = dispatch_shared_handler_b__6TLobbyFl(lbl_8043D484[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__resistance_params_by_variant[i] = register_object__6TLobbyFl(lbl_8043D48C[i]);
    }
    for (i = 0; i < 2; i++) {
        TObjEneMe3Stelth__behavior_params_by_variant[i] = (StelthBehaviorParams *)TLobby::dispatch_shared_handler_a(lbl_8043D494[i]);
    }
    d = TObjEneMe3Stelth__behavior_params_by_variant[0];
    TObjEneMe3Stelth::set_slot_min_clamped_value(7, d->m_0c);
    TObjEneMe3Stelth::set_slot_min_clamped_value(4, d->m_10);
    TObjEneMe3Stelth__render_node_index = 0;
    lbl_80501114[0] = 0.0f;
    lbl_80501114[1] = 0.0f;
    lbl_80501114[2] = 0.0f;
    m = TObjEneMe3Stelth__bml_resource->models->model;
    q = (s32 *)((NJS_OBJECT *)find_model_node(m, 9))->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[0] = (u32 *)(q[1] + 4);
    } else {
        TObjEneMe3Stelth__material_color_pointers[0] = 0;
    }
    q = (s32 *)((NJS_OBJECT *)find_model_node(m, 0xD))->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[1] = (u32 *)(q[1] + 4);
    } else {
        TObjEneMe3Stelth__material_color_pointers[1] = 0;
    }
    q = (s32 *)((NJS_OBJECT *)find_model_node(m, 0x26))->model;
    if (q != NULL) {
        TObjEneMe3Stelth__material_color_pointers[2] = (u32 *)(q[1] + 4);
    } else {
        TObjEneMe3Stelth__material_color_pointers[2] = 0;
    }
    motion = TObjEneMe3Stelth__bml_resource->motions[TObjEneMe3Stelth__animation_descriptors[5].motion].motion;
    if (is_split_screen() != 0) {
        p = ::operator new(0x10);
        if (p != NULL) {
            p = TBreakUpMdl::init(p, TObjEneMe3Stelth__bml_resource->models->model, (s32)motion, (f32)(((NJS_MOTION *)motion)->nbFrame - 1));
        }
        TObjEneMe3Stelth__breakup_model = (TUnk_8048FA00 *)p;
    } else {
        p = ::operator new(0x10);
        if (p != NULL) {
            p = ((TBreakUpMdl *)p)->setup_pieces(TObjEneMe3Stelth__bml_resource->models->model, (s32)motion, (f32)(((NJS_MOTION *)motion)->nbFrame - 1));
        }
        TObjEneMe3Stelth__breakup_model = (TUnk_8048FA00 *)p;
    }
    {
        Vec va;
        Vec vb;
        s32 mdl;
        AnimationMotion *trail_motion;
        BmlResource *r = TObjEneMe3Stelth__bml_resource;
        s32 idx = TObjEneMe3Stelth__animation_descriptors[6].motion;
        mdl = r->models->model;
        va.x = 0.0f;
        va.y = 0.0f;
        va.z = 0.0f;
        vb.x = lbl_805DA8B0;
        vb.y = 0.0f;
        vb.z = 0.0f;
        trail_motion = r->motions[idx].motion;
        TObjEneMe3Stelth__trail_buffer = new SampledMotionPoints(2, lbl_805DA8B4, lbl_805DA8B8, lbl_805DA8BC);
        TObjEneMe3Stelth__trail_buffer->sample_node_offsets((NJS_OBJECT *)mdl, (NJS_MOTION *)trail_motion, 0x22, &va, &vb);
    }
    {
        DelDepthAnimationBinding a = stelth_attack_binding_desc_a;
        a.motions = TObjEneMe3Stelth__bml_resource->motions;
        DelDepthAnimationBinding b = stelth_attack_binding_desc_b;
        b.motions = TObjEneMe3Stelth__bml_resource->motions;
        TObjEneMe3Stelth::spawn_attack(0x2B, TObjEneMe3Stelth__bml_resource->models->model, TObjEneMe3Stelth__bml_resource->models->m_c, (s32)&a, lbl_805DA8A4, 0.0f);
        TObjEneMe3Stelth::spawn_attack(0x2D, TObjEneMe3Stelth__bml_resource->models->model, TObjEneMe3Stelth__bml_resource->models->m_c, (s32)&b, lbl_805DA8A4, 0.0f);
    }
}
}

extern "C" {
int TObjEneMe3Stelth::create_real() { return create__20TObjEneMe3StelthRealFPv(this); }
}

extern "C" {
void TObjEneMe3Stelth::free_shared_resources() {
    if (TObjEneMe3Stelth__trail_buffer != NULL) {
        delete TObjEneMe3Stelth__trail_buffer;
        TObjEneMe3Stelth__trail_buffer = NULL;
    }
    if (TObjEneMe3Stelth__breakup_model != NULL) {
        delete TObjEneMe3Stelth__breakup_model;
        TObjEneMe3Stelth__breakup_model = NULL;
    }
    if (TObjEneMe3Stelth__alternate_texture_list.textures != NULL) {
        mem_free(TObjEneMe3Stelth__alternate_texture_list.textures);
        TObjEneMe3Stelth__alternate_texture_list.textures = NULL;
    }
    if (TObjEneMe3Stelth__bml_resource != NULL) {
        free_bin_model_request(TObjEneMe3Stelth__bml_resource, 1);
        TObjEneMe3Stelth__bml_resource = NULL;
    }
}
}

extern "C" {
void TObjEneMe3Stelth::set_slot_min_clamped_value(s32 arg0, f32 farg0) {
    f32 speed = farg0;
    if (speed < lbl_805DA8AC) {
        speed = lbl_805DA8AC;
    }
    TObjEneMe3Stelth__animation_descriptors[arg0].speed = speed;
}
}

extern "C" {
TObjEneMe3Stelth::TObjEneMe3Stelth(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneMe3Stelth__class_name;
}
}

extern "C" {
#pragma push
#pragma opt_propagation off
void TObjEneMe3StelthReal::init_common() {
    BmlModelEntry *entry;
    f32 y;
    s32 v;

    init_position_vectors();
    sub_800F4758();
    entry = TObjEneMe3Stelth__bml_resource->models;
    model = (void *)entry->model;
    init_model(&TObjEneMe3Stelth__collision_body_template, 1);
    motion_flags = 0;
    set_field_d8((s32)TObjEneMe3Stelth__animation_descriptors);
    set_field_dc((s32)TObjEneMe3Stelth__bml_resource->motions);
    set_animation(requested_action);
    v = m_3c8;
    reset_hp((u8 *)TObjEneMe3Stelth__base_params_by_variant[v], (u8 *)TObjEneMe3Stelth__attack_params_by_variant[v], (u8 *)TObjEneMe3Stelth__resistance_params_by_variant[v]);
    check_state_flag_4();
    movementParameters = TObjEneMe3Stelth__shared_params;
    m_37c = TObjEneMe3Stelth__data_805DA824;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    m_3cc = 0;
    y = position.y;
    m_3d0 = y;
    m_3d4 = 0.0f;
    m_3e8 = 0;
    m_3ec = 0;
    m_3f4 = m_2cc;
    m_404.reset_obstruction_fade();
    m_424 = 0;
    m_428 = 0;
    m_42c = 0;
    m_430 = 0.0f;
    m_434 = 0.0f;
    m_438 = 0.0f;
    m_43c = 0.0f;
    m_440 = 0.0f;
    m_444 = NULL;
    m_448 = NULL;
    m_420 = 0;
    if (m_3c0 == 1) {
        set_indexed_flags(0, 0x08000000);
        return;
    }
    clear_player_status_flag(0, 0x08000000);
}
#pragma pop
}

extern "C" {
TObjEneMe3Stelth::~TObjEneMe3Stelth() {
    if (m_444 != NULL) {
        m_444->queue_destruction();
        m_444 = NULL;
    }
    if (m_448 != NULL) {
        m_448->queue_destruction();
        m_448 = NULL;
    }
    free_collision_body_parts(this);
}
}

extern "C" {
void TObjEneMe3Stelth::run_task() {
    s32 flags;
    if (TObjPlayer::check_demo_mode() != 0) {
        setup_move();
        return;
    }
    if (vfunc_83() != 4) {
        vfunc_85();
    }
    copy_pos_with_height_offset();
    vfunc_88();
    flags = m_3cc;
    if (flags & 0x40000) {
        m_3cc = flags & ~0x40000;
        return;
    }
    submit_default_cursor_candidate();
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_28() {  }
}

extern "C" {
void TObjEneMe3Stelth::vfunc_63() {
    if (mode != 15) {
        transition_enemy_state(15);
    }
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_62() {
    if (m_3cc & 1) {
        clear_attack_receipts();
        if (m_3c0 == 1 && random_ratio() <= m_3e0) {
            transition_enemy_state(0x12);
        }
    } else if (mode != 0xE) {
        transition_enemy_state(0xE);
    }
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_61() {  }
}

extern "C" {
void TObjEneMe3Stelth::copy_pos_with_height_offset() {
    VecCopy((Vec *)&m_2fc, &position);
    m_300 += lbl_805DA814 + m_3d4;
    VecCopy(&center, (Vec *)&m_2fc);
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_88() {
    bodies->offset.y = m_300 - position.y;
}
}

extern "C" {
void TObjEneMe3Stelth::setup_move_bounds() {
    if (sub_800F4850() != 0) {
        m_3c0 = 1;
    } else {
        m_3c0 = 0;
    }
    m_3c4 = is_angle_in_range();
    if (m_3c4 == 1) {
        requested_action = 2;
    } else {
        requested_action = 0;
    }
    m_3d8 = lbl_805DA8A8 + parameters[2];
    m_3dc = 0.3f + parameters[1];
    m_3e0 = lbl_805DA8AC + parameters[4];
    m_3e4 = lbl_805DA81C + parameters[3];
    m_3f0 = variant;
}
}

extern "C" {
f32 TObjEneMe3Stelth::get_node_world_y() {
    Vec v;
    NJS_OBJECT *node;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    bind_motion_context(current_motion, frame);
    node = (NJS_OBJECT *)model;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}
}

extern "C" {
s32 TObjEneMe3Stelth::test_body_collision(s32 arg1, f32 farg0) {
    f32 f2 = farg0 * lbl_805DA81C;
    CollisionBody *s = bodies;
    u8 res;
    s32 a = rotation_y;
    s32 b = s->flags;
    s->offset.x = 0.0f;
    s->offset.z = f2;
    s->radius = f2;
    s->half_width = lbl_805DA8A4;
    s->shape = 1;
    s->flags = 0x9D01;
    rotation_y = arg1;
    ((void (*)(void *, s32, f32, f32))check_enemy_body_collisions)(this, arg1, 0.0f, f2);
    res = (s->flags & 0x380000) != 0;
    copy_collision_body(s, &TObjEneMe3Stelth__collision_body_template);
    s->flags = b;
    rotation_y = a;
    return res;
}
}

extern "C" {
#pragma push
#pragma fp_contract on
bool TObjEneMe3Stelth__sub_800F4C10(TObjEneMe3Stelth *stelth, f32) {
    f32 temp_f31;
    if (fabs_float(stelth->target->position.y - stelth->position.y) >= 20.0f) {
        return 0;
    }
    if (stelth->m_3ac > 25.0f) {
        return 0;
    }
    temp_f31 = (stelth->m_3a0 * sin_table_lookup(stelth->rotation_y)) + (stelth->m_3a8 * cos_table_lookup(stelth->rotation_y));
    return (temp_f31 < cos_table_lookup(0x1E00)) == 0;
}
#pragma pop
}

extern "C" {
void TObjEneMe3Stelth::attack_and_unequip() {
    s32 near = is_passing_frame(lbl_805DA810);
    if (is_passing_frame(TObjEneMe3Stelth__data_805DA808) == 0 && near == 0) {
        return;
    }
    if (enemy_check_target_valid() != 0 && target->select_melee_contact_body(this, TObjEneMe3Stelth__data_805DA80C) != 0) {
        f32 d = target->receive_physical_attack(this, TObjEneMe3Stelth__data_805DA80C);
        target->apply_knockback_from_attacker((u8 *)this, 3.0f);
        if (d > 0.0f) {
            if (sub_800F47D4() != 0) {
                TObjChara *t = target;
                if (is_locally_controlled__10TObjPlayerFPv(t) != 0 && get_item_field_6__10TObjPlayerFPv(t) != 0) {
                    send_6x26_unequip_item__10TObjPlayerFPvPv(t, get_item_id__5TItemFv());
                    ((TObjPlayer *)t)->get_hand_joint_position((s32)&m_3f8);
                    spawn_particle_effect(&m_3f8, 0x1D0);
                }
            } else if (near != 0 && random_ratio() <= lbl_805DA8A0) {
                TObjEneDD__sub_800BA438(this, target);
            }
        }
    }
    play_sound_effect(0x3AA37, (u8 *)&position, 0, 0);
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_108() {  }
}

extern "C" {
s32 TObjEneMe3Stelth::check_target_in_range() {
    f32 temp_f1;
    s32 var_r31;

    var_r31 = 0;
    if (!(m_3cc & 0x10000)) {
        temp_f1 = m_3ac;
        if ((temp_f1 > lbl_805DA898) && (temp_f1 < lbl_805DA89C) && (test_body_collision(rotation_y, temp_f1 - 20.0f) == 0)) {
            var_r31 = 1;
        }
    }
    return (u8)var_r31;
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_107() {  }
}

extern "C" {
s32 TObjEneMe3Stelth::check_active_flag() {
    if (m_3cc & 4) {
        m_404.set_flags_and_apply_damage_color();
        return 1;
    }
    return 0;
}
}

extern "C" {
s32 TObjEneMe3Stelth::check_flag() {
    if (m_3cc & 4) {
        m_404.clear_flag_and_notify();
        return 1;
    }
    return 0;
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_111() {  }
}

extern "C" {
void TObjEneMe3Stelth::vfunc_95() { TObjEneDD::vfunc_95(); sub_800F5874(38); }
}

extern "C" {
void TObjEneMe3Stelth::vfunc_96() { TObjEneDD::vfunc_96(); sub_800F5864(38); }
}

extern "C" {
void TObjEneMe3Stelth::vfunc_112() {  }
}

extern "C" {
void TObjEneMe3Stelth::update_distance_state() {
    if (m_3d0 - position.y > lbl_805DA894) {
        vfunc_97();
        return;
    }
    vfunc_98();
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_89() {
    vfunc_88();
    check_object_collisions__14TObjCollidableFv(this);
    check_enemy_body_collisions(this);
    update_enemy_collision_flags__14TObjCollidableFv(this);
}
}

extern "C" {
s32 TObjEneMe3Stelth::sub_800F4850() {
    return parameters[0] < 2.0f;
}
}

extern "C" {
s32 TObjEneMe3Stelth::is_angle_in_range() {
    return parameters[0] < TObjEneMe3Stelth__data_805DA80C ||
           (parameters[0] >= 2.0f && parameters[0] < 3.0f);
}
}

extern "C" {
s32 TObjEneMe3Stelth::vfunc_104(f32) { return select_and_apply_target__12TObjEneDD_STFf(this); }
}

extern "C" {
s32 TObjEneMe3Stelth::sub_800F47D4() {
    return m_3f0 >= 1;
}
}

extern "C" {
void TObjEneMe3Stelth::sub_800F4758() {
    if (sub_800F47D4() != 0) {
        texlist = (s32)&TObjEneMe3Stelth__alternate_texture_list;
        initialize_enemy_state(0x3F);
        m_3c8 = 1;
        return;
    }
    texlist = TObjEneMe3Stelth__bml_resource->models->m_c;
    initialize_enemy_state(0x3E);
    m_3c8 = 0;
}
}

extern "C" {
void create_resta_effect__16TObjEneMe3StelthFPv(TObjEneMe3Stelth *stelth) {
    s32 f = TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8]->support_tech_level);
    TTecResta::create((void *)stelth, (u8 *)&stelth->position, (void *)f);
}
}

extern "C" {
void TObjEneMe3Stelth::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        vfunc_113(reason);
        break;
    case 1:
        sub_800F42B8(reason);
        break;
    case 3:
        TObjEneMe3Stelth__sub_800F3FE4(this, reason);
        break;
    case 2:
        state_chase(reason);
        break;
    case 4:
        update_state_fade_in(reason);
        break;
    case 5:
        update_state_drop(reason);
        break;
    case 6:
        state_chase_target(reason);
        break;
    case 7:
        TObjEneMe3Stelth__sub_800F348C(this, reason);
        break;
    case 8:
        TObjEneMe3Stelth__sub_800F3214(this, reason);
        break;
    case 9:
        run_walk_state__16TObjEneMe3StelthFPvi(this, reason);
        break;
    case 13:
        handle_message__16TObjEneMe3StelthFPvi(this, reason);
        break;
    case 10:
        action__16TObjEneMe3StelthFPvi(this, reason);
        break;
    case 11:
        update_state_resta_cast(reason);
        break;
    case 14:
        TObjEneMe3Stelth__sub_800F290C(this, reason);
        break;
    case 15:
        handle_breakup_state(reason);
        break;
    case 12:
        TObjEneMe3Stelth__sub_800F2270(this, reason);
        break;
    case 16:
        TObjEneMe3Stelth__sub_800F1098(this, reason);
        break;
    case 17:
        exec__16TObjEneMe3StelthFPvi(this, reason);
        break;
    case 18:
        TObjEneMe3Stelth__sub_800F1440(this, reason);
        break;
    }
    if (m_3c0 != 1 || ((s32)state != 1 && (s32)state != 2)) {
        vfunc_100();
    }
}
}

extern "C" {
void TObjEneMe3Stelth::vfunc_113(s32 arg1) {
    switch (arg1) {
    case 4:
        if (m_3c4 == 1) {
            requested_action = 2;
            set_field_378(1);
        } else {
            requested_action = 0;
            set_field_378(3);
        }
        vfunc_95();
        m_3cc |= 2;
        m_3cc &= ~1;
        if (TObjEneDD::check_v2_mode() != 0) {
            m_3cc &= ~0x10000;
        }
        m_424 = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &home_position);
        VecCopy((Vec *)&m_2fc, &home_position);
        m_3d0 = position.y;
        m_3e8 = 0;
        m_3ec = 0;
        return;
    case 3:
        if (m_424 > 5) {
            if (m_3c4 == 1) {
                transition_enemy_state(1);
            } else {
                transition_enemy_state(3);
            }
        }
    case 5:
        return;
    case 0:
        m_424++;
        if (m_424 == 1) {
            m_3d0 = position.y;
            vfunc_102();
            m_3d4 = m_3d0 - position.y;
        }
        break;
    }
}
}

extern "C" {
void TObjEneMe3Stelth::sub_800F42B8(s32 arg1) {
    Vec v;
    f32 t;
    switch (arg1) {
    case 4:
        requested_action = 2;
        set_field_378(0);
        vfunc_95();
        m_3cc &= ~2;
        m_3cc |= 5;
        m_404.start_fade_in();
        VecCopy(&v, &position);
        t = m_3d0;
        v.y = t - 20.0f;
        if (m_3c0 == 0) {
            TBoss3Volopt__sub_800D8D88(&v, t);
        } else {
            create_timed_particle_emitter((u8 *)&position, 0x79, 0, 0xF);
        }
        break;
    case 3:
        if (m_404.advance_toward_max() != 0) {
            if (m_3c0 == 1) {
                transition_enemy_state(2);
            } else {
                transition_enemy_state(0xD);
            }
        }
        break;
    case 0:
        if (*TBoss3Volopt__sub_800F059C(&m_404) >= lbl_805DA890) {
            advance_animation();
        }
        vfunc_102();
        break;
    case 5:
        m_3cc &= ~4;
        break;
    }
}
}

extern "C" {
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_chase(s32 arg1) {
    s32 temp_r0;
    switch (arg1) {
    case 4:
        requested_action = 9;
        set_field_378(0xD);
        vfunc_96();
        m_3cc &= ~7;
        m_424 = 0;
        m_428 = 0;
        m_434 = 0.0f;
        break;
    case 3:
        if (update_linked_position(200.0f) != 0) {
            if (m_3ac <= lbl_805DA888) {
                transition_enemy_state(0xD);
                break;
            }
            temp_r0 = m_428 - 1;
            m_428 = temp_r0;
            if ((temp_r0 <= 0) && (check_target_in_range() != 0)) {
                m_428 = 0x3C;
                if (random_ratio() <= lbl_805DA88C) {
                    transition_enemy_state(7);
                    break;
                }
            }
        } else {
            if (m_424 >= 0xE10) {
                transition_enemy_state(0xD);
                break;
            }
        case 5:
            break;
        }
        break;
    case 0:
        m_424++;
        advance_animation();
        if (update_linked_position(200.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
            m_434 = (m_3a0 * sin_table_lookup(rotation_y)) + (m_3a8 * cos_table_lookup(rotation_y));
            if (m_434 < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(0x500);
                vfunc_102();
            }
        }
        vfunc_89();
        break;
    }
}
#pragma pop
}

extern "C" {
void TObjEneMe3Stelth__sub_800F3FE4(TObjEneMe3Stelth *stelth, s32 arg1) {
    Vec pos;
    f32 temp_f1;
    switch (arg1) {
    case 4:
        stelth->requested_action = 0;
        stelth->set_field_378(0);
        stelth->vfunc_95();
        stelth->m_3cc |= 7;
        stelth->m_404.start_fade_in();
        VecCopy(&pos, &stelth->position);
        temp_f1 = stelth->m_3d0;
        pos.y = temp_f1 - TObjEneMe3Stelth__data_805DA824;
        TBoss3Volopt__sub_800D8D88(&pos, temp_f1);
        break;
    case 3:
        if (stelth->m_404.advance_toward_max() != 0) {
            stelth->transition_enemy_state(4);
            break;
        }
    case 0:
        break;
    case 5:
        stelth->m_3cc &= ~4;
        break;
    }
}
}

extern "C" {
void TObjEneMe3Stelth::update_state_fade_in(s32 arg1) {
    s32 enemy_validate_retained_target(void *, s32);
    extern const s32 lbl_805DA884;
    s32 t;
    switch (arg1) {
    case 4:
        requested_action = 0;
        set_field_378(5);
        vfunc_95();
        m_3cc &= ~7;
        m_424 = 0;
        m_428 = 0;
        break;
    case 3:
        if (m_424 > 0x1E) {
            transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        if (m_424 == 0) {
            if (update_linked_position(200.0f) != 0) {
                m_424 = 1;
                m_3e8 = 0x1C00FFFF;
                m_3e8 &= lbl_805DA884;
                m_428 = 0;
            }
        } else {
            m_424 += 1;
            m_428 += 0x10;
            if (m_428 > 0xFF) {
                m_428 = 0xFF;
            }
            t = m_428;
            m_3e8 = (t << 24) | (m_3e8 & 0x00FFFFFF);
            if (enemy_validate_retained_target(this, t) == 0) {
                m_424 = 0;
                m_3e8 = 0;
            }
        }
        vfunc_102();
        update_distance_state();
        vfunc_89();
        m_3d4 = m_3d0 - position.y;
        break;
    case 5:
        m_3e8 = 0x1C00FFFF;
        m_3d4 = 0.0f;
        break;
    }
}
}

extern "C" {
void TObjEneMe3Stelth::update_state_drop(s32 arg1) {
    f32 temp_f1;
    f32 temp_f31;

    switch (arg1) {
    case 4:
        requested_action = 1;
        set_field_378(0xD);
        vfunc_96();
        m_3cc &= ~6;
        m_3cc |= 1;
        m_424 = 0;
        m_430 = 0.0f;
        if (enemy_has_live_target() != 0) {
            enemy_copy_target_destination();
            update_velocity();
        }
        break;
    case 3:
        if (m_424 == 3) {
            transition_enemy_state(0xD);
        }
        break;
    case 0:
        switch (m_424) {
        case 0:
            temp_f31 = get_node_world_y();
            advance_animation();
            m_434 = get_node_world_y();
            m_3d0 = m_3d0 + (temp_f31 - m_434);
            m_424 = 1;
            m_3d4 = m_3d0 - position.y;
            break;
        case 1:
            advance_animation();
            if (frame > 29.0f) {
                frame = 29.0f;
            }
            m_430 -= 0.3f;
            if (m_430 < -5.0f) {
                m_430 = -5.0f;
            }
            m_3d0 = m_3d0 + m_430;
            temp_f1 = get_node_world_y();
            m_3d0 = m_3d0 - (temp_f1 - m_434);
            m_434 = temp_f1;
            if (m_3d0 < position.y) {
                m_3d0 = position.y;
                m_424 = 2;
                play_hit_effect();
            }
            break;
        case 2:
            if (get_flag_b4() != 0) {
                requested_action = 9;
                m_424 = 3;
                m_3d0 = position.y;
                m_3d4 = 0.0f;
            }
            advance_animation();
            break;
        }
        vfunc_102();
        update_distance_state();
        vfunc_89();
        m_3d4 = m_3d0 - position.y;
        break;
    case 5:
        m_3cc &= ~1;
        m_3d4 = 0.0f;
        break;
    }
}
}

extern "C" {
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::state_chase_target(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0xA;
        set_field_378(6);
        vfunc_96();
        m_3cc &= ~7;
        m_3ac = 300.0f;
        m_430 = TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->m_00;
        m_434 = 0.0f;
        return;
    case 3:
        if (target == NULL) {
            vfunc_111();
            transition_enemy_state(0xD);
            return;
        }
        if (((s32 (*)(TObjEneMe3Stelth *, f32))TObjEneMe3Stelth__sub_800F4C10)(this, m_434) != 0) {
            transition_enemy_state(8);
            return;
        }
        if (check_target_in_range() != 0) {
            transition_enemy_state(7);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (update_linked_position(200.0f) != 0) {
            enemy_copy_target_destination();
            update_velocity();
            TObjEneMe3Stelth__sub_800F0C90(this);
            m_434 = (m_3a0 * sin_table_lookup(rotation_y)) + (m_3a8 * cos_table_lookup(rotation_y));
            if (m_434 < cos_table_lookup(0x1000)) {
                turn_toward_target_direction(0x500);
                vfunc_102();
            } else {
                enemy_turn_and_move_on_ground((u8 *)this, 0x500, m_430);
            }
            vfunc_89();
        }
        break;
    }
}
#pragma pop
}

extern "C" {
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth__sub_800F348C(TObjEneMe3Stelth *stelth, s32 arg1) {
    Vec v;
    Vec points[2];
    f32 t;
    s32 ang;
    s32 entry;
    switch (arg1) {
    case 4:
        stelth->requested_action = 6;
        stelth->set_field_378(6);
        stelth->vfunc_96();
        stelth->m_3cc &= ~7;
        stelth->m_3cc |= 0x10000;
        stelth->m_424 = 0;
        stelth->m_430 = 0.0f;
        stelth->set_active();
        break;
    case 3:
        if (stelth->m_424 == 5 || stelth->get_flag_b4() != 0) {
            if (stelth->vfunc_102() == 0) {
                stelth->transition_enemy_state(0xA);
            } else {
                stelth->transition_enemy_state(6);
            }
        }
        break;
    case 0:
        switch (stelth->m_424) {
        case 0:
            stelth->advance_animation();
            if (stelth->motion_flags & 8) {
                stelth->m_424 = 1;
            }
            stelth->vfunc_102();
            stelth->vfunc_89();
            break;
        case 1:
            stelth->advance_animation();
            if (((TObjEneEpsilon *)stelth)->update_death_check() != 0) {
                stelth->enemy_copy_target_destination();
                stelth->update_velocity();
                ang = (s32)(10430.38043493439 * atan2_float(stelth->m_3a0, stelth->m_3a8));
            } else {
                ang = stelth->rotation_y;
            }
            stelth->rotation_y = approach_angle_limited(stelth->rotation_y, ang, 0x1000);
            if (stelth->is_passing_frame(TObjEneMe3Stelth__data_805DA824) != 0) {
                stelth->m_424 = 2;
            }
            stelth->vfunc_102();
            stelth->vfunc_89();
            break;
        case 2:
            stelth->advance_animation();
            if (((TObjEneEpsilon *)stelth)->update_death_check() != 0) {
                stelth->enemy_copy_target_destination();
                stelth->update_velocity();
            }
            if (stelth->frame + stelth->play_speed >= 14.0f) {
                if (stelth->test_body_collision(stelth->rotation_y, stelth->m_3ac - 20.0f) != 0) {
                    stelth->m_424 = 5;
                } else {
                    t = stelth->m_3ac - 20.0f;
                    VecCopy(&v, &stelth->position);
                    v.x += stelth->m_3a0 * t;
                    v.y += 20.0f;
                    v.z += stelth->m_3a8 * t;
                    if (csnVecterUnder((s32)&v, 0x15) != 0) {
                        if (stelth->room == ((TScene *)(&v))->find_section_at_position()) {
                            stelth->m_424 = 3;
                            stelth->m_434 = (stelth->m_3ac - 20.0f) / 12.857143f;
                            stelth->vfunc_91();
                            play_sound_effect(0x3A835, (u8 *)&stelth->position, 0, 0);
                        } else {
                            stelth->m_424 = 5;
                        }
                    } else {
                        stelth->m_424 = 5;
                    }
                }
            }
            stelth->vfunc_102();
            stelth->vfunc_89();
            break;
        case 3:
            stelth->advance_animation();
            if (stelth->frame + stelth->play_speed >= lbl_805DA810) {
                stelth->m_424 = 4;
                stelth->vfunc_92();
                stelth->play_hit_effect();
            }
            stelth->move_with_wall_slide_commit(stelth->m_3a0, stelth->m_3a8, stelth->m_434);
            stelth->vfunc_89();
            break;
        case 4:
            stelth->advance_animation();
            if (stelth->is_passing_frame(25.0f) != 0) {
                if (stelth->enemy_check_target_valid() != 0) {
                    if (stelth->target->select_melee_contact_body(stelth, TObjEneMe3Stelth__data_805DA80C) != 0) {
                        stelth->target->receive_physical_attack(stelth, TObjEneMe3Stelth__data_805DA80C);
                        stelth->target->apply_knockback_from_attacker((u8 *)stelth, 3.0f);
                    }
                }
                play_sound_effect(0x3A838, (u8 *)&stelth->position, 0, 0);
            }
            stelth->m_434 *= 0.85f;
            stelth->move_with_wall_slide_on_ground(stelth->m_3a0, stelth->m_3a8, stelth->m_434);
            stelth->vfunc_89();
            break;
        }
        if (stelth->m_424 != 0) {
            entry = (s32)TObjEneMe3Stelth__trail_buffer->lookup(stelth->frame);
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix((f32 *)&stelth->position);
                rotate_matrix_y(0, stelth->rotation_y);
                mult_vec_array__10TObjPlayerFUll(0, entry, points, 2);
                pop_matrix();
            }
        }
        break;
    case 5:
        stelth->m_3d0 = stelth->position.y;
        stelth->m_3d4 = 0.0f;
        stelth->vfunc_92();
        stelth->clear_field_388();
        break;
    }
}
#pragma pop
}

extern "C" {
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth__sub_800F3214(TObjEneMe3Stelth *stelth, s32 arg1) {
    f32 temp_f1;
    s32 var_r4;
    switch (arg1) {
    case 4:
        stelth->requested_action = 7;
        stelth->set_field_378(0xC);
        stelth->vfunc_96();
        stelth->m_3cc &= ~7;
        stelth->m_3cc |= 0x10000;
        stelth->m_424 = 0;
        stelth->m_428 = 0;
        return;
    case 3:
        if (stelth->get_flag_b4() != 0) {
            stelth->vfunc_107();
        }
    case 5:
        return;
    case 0:
        stelth->advance_animation();
        switch (stelth->m_424) {
        case 0:
            stelth->attack_and_unequip();
            if (stelth->frame < 20.0f) {
                if (((TObjEneEpsilon *)stelth)->update_death_check() != 0) {
                    stelth->enemy_copy_target_destination();
                    stelth->update_velocity();
                    var_r4 = (s32) (10430.38043493439 * atan2_float(stelth->m_3a0, stelth->m_3a8));
                } else {
                    var_r4 = stelth->rotation_y;
                }
                stelth->rotation_y = approach_angle_limited(stelth->rotation_y, var_r4, 0x300);
                stelth->m_3a0 = sin_table_lookup(stelth->rotation_y);
                stelth->m_3a8 = cos_table_lookup(stelth->rotation_y);
            }
            stelth->vfunc_112();
            TObjEneMe3Stelth__sub_800F0C90(stelth);
            temp_f1 = stelth->frame;
            if ((temp_f1 >= 0.0f) && (temp_f1 <= TObjEneMe3Stelth__data_805DA820)) {
                move_to_shot_position__9TObjEneDDFfff(stelth, (int) TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8], stelth->m_3a0, stelth->m_3a8, TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8]->m_08);
            } else {
                stelth->vfunc_102();
            }
            if (stelth->frame >= 25.0f) {
                stelth->frame = 25.0f;
                stelth->m_424 = 1;
            }
            break;
        case 1:
            stelth->m_428++;
            if (stelth->m_428 <= TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8]->m_20) {
                stelth->frame = 25.0f;
            }
            stelth->vfunc_102();
            break;
        }
        stelth->vfunc_89();
        break;
    }
}
#pragma pop
}

extern "C" {
#pragma push
#pragma fp_contract on
void run_walk_state__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1) {
    switch (arg1) {
    case 4:
        stelth->requested_action = 3;
        stelth->set_field_378(6);
        stelth->vfunc_96();
        stelth->m_3cc &= ~7;
        stelth->m_3ec = 0;
        stelth->m_424 = 3;
        if (stelth->vfunc_104(200.0f) != 0) {
            stelth->enemy_copy_target_destination();
            stelth->update_velocity();
            stelth->m_42c = (s32) (10430.38043493439 * atan2_float(stelth->m_3a0, stelth->m_3a8));
            if (stelth->test_body_collision(stelth->m_42c + 0x8000, 80.0f) == 0) {
                stelth->m_3a0 *= -1.0f;
                stelth->m_3a8 *= -1.0f;
                stelth->m_424 = 0;
                stelth->m_430 = 7.111111f;
            }
        }
        stelth->set_active();
        return;
    case 3:
        if (stelth->m_424 == 3) {
            if ((stelth->m_3c0 == 0) && (stelth->random_ratio() <= stelth->m_3dc)) {
                stelth->transition_enemy_state(0x11);
                return;
            }
            if (stelth->random_ratio() <= stelth->m_3d8) {
                if (stelth->sub_800F47D4() != 0) {
                    if (stelth->random_ratio() > TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8]->m_14) {
                        stelth->transition_enemy_state(0x10);
                        return;
                    }
                    stelth->transition_enemy_state(0xB);
                    return;
                }
                stelth->transition_enemy_state(0x10);
                return;
            }
            if (stelth->random_ratio() <= stelth->m_3e4) {
                stelth->transition_enemy_state(0xC);
                return;
            }
            stelth->transition_enemy_state(6);
        }
        return;
    case 0:
        stelth->advance_animation();
        switch (stelth->m_424) {
        case 0:
            stelth->rotation_y = approach_angle_limited(stelth->rotation_y, stelth->m_42c, 0x31C7);
            if ((stelth->frame + stelth->play_speed) >= TObjEneMe3Stelth__data_805DA808) {
                stelth->m_424 = 1;
                stelth->vfunc_91();
                play_sound_effect(0x3A835, (u8 *)&stelth->position, 0, 0);
            }
            stelth->vfunc_102();
            stelth->vfunc_89();
            return;
        case 1:
            if ((stelth->frame + stelth->play_speed) >= 24.0f) {
                stelth->m_424 = 2;
                stelth->vfunc_92();
                stelth->play_hit_effect();
            }
            stelth->move_clamped_on_ground(stelth->m_3a0, stelth->m_3a8, stelth->m_430);
            return;
        case 2:
            if (stelth->get_flag_b4() != 0) {
                stelth->m_424 = 3;
            }
            stelth->vfunc_102();
            stelth->vfunc_89();
            return;
        }
        break;
    case 5:
        stelth->vfunc_92();
        stelth->clear_field_388();
        break;
    }
}
#pragma pop
}

extern "C" {
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::update_state_resta_cast(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 8;
        set_field_378(0xB);
        vfunc_96();
        m_3cc &= ~6;
        m_3cc |= 1;
        m_424 = 0;
        m_428 = 0;
        return;
    case 3:
        if (m_428 > TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->m_1c) {
            transition_enemy_state(6);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        switch (m_424) {
        case 0:
            if (get_flag_b4() != 0) {
                create_resta_effect__16TObjEneMe3StelthFPv(this);
                if (TObjEneDD::check_v2_mode() != 0) {
                    m_424 = 2;
                } else {
                    m_424 = 1;
                }
                m_428 = 0;
            }
            break;
        case 1:
            m_428++;
            break;
        case 2:
            m_428++;
            if (m_428 == 5) {
                TTecSifta::create((void *)this, (u8 *)&position, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->support_tech_level)));
            } else if (m_428 == 0xA) {
                create__10TTecDebandFlll(this, (u8 *)&position, TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[m_3c8]->support_tech_level));
                m_424 = 1;
                m_428 = 0;
            }
            break;
        }
        vfunc_102();
        break;
    }
}
#pragma pop
}

extern "C" void handle_message__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1) {
    switch (arg1) {
    case 4:
        stelth->requested_action = 9;
        stelth->set_field_378(0xD);
        stelth->m_3cc &= ~7;
        stelth->vfunc_95();
        stelth->m_3ec = 0;
        stelth->m_424 = 0;
        break;
    case 3:
        if (stelth->update_linked_position(200.0f) != 0) {
            stelth->transition_enemy_state(6);
        } else if (stelth->m_424 >= 0x5A) {
            stelth->transition_enemy_state(0xA);
        }
        break;
    case 5:
        break;
    case 0:
        stelth->m_424++;
        stelth->advance_animation();
        stelth->vfunc_102();
        stelth->vfunc_89();
        break;
    }

}

extern "C" {
void action__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1) {

    switch (arg1) {
    case 4:
        stelth->requested_action = 8;
        stelth->set_field_378(6);
        stelth->vfunc_95();
        stelth->m_3cc &= ~3;
        stelth->m_3cc |= 4;
        stelth->m_404.reset_color();
        stelth->m_424 = 1;
        return;
    case 3:
        if (stelth->m_424 == 2) {
            stelth->transition_enemy_state(0);
        }
        return;
    case 0:
        stelth->advance_animation();
        switch (stelth->m_424) {
        case 0:
            if (stelth->get_flag_b4() != 0) {
                stelth->m_424 = 1;
            }
            break;
        case 1:
            if (stelth->m_404.decay_value_toward_floor() != 0) {
                stelth->m_424 = 2;
            }
            break;
        }
        stelth->vfunc_102();
        return;
    case 5:
        stelth->m_3cc &= ~4;
        break;
    }
}
}

extern "C" {
void TObjEneMe3Stelth__sub_800F290C(TObjEneMe3Stelth *stelth, s32 arg1) {
    Vec v;
    f32 c;
    switch (arg1) {
    case 4:
        stelth->requested_action = 4;
        stelth->advance_animation();
        stelth->set_active();
        play_sound_effect(0x3A839, (u8 *)&stelth->position, 0, 0);
        break;
    case 3:
        if (stelth->get_flag_b4() != 0) {
            if (stelth->m_3c0 == 1 && stelth->random_ratio() <= stelth->m_3e0) {
                stelth->transition_enemy_state(0x12);
            } else {
                stelth->transition_enemy_state(stelth->m_378);
            }
        }
        break;
    case 0:
        stelth->advance_animation();
        VecCopy(&v, (Vec *)&stelth->x_speed);
        c = normalize_vector_xz(&v);
        stelth->move_clamped_on_ground(v.x, v.z, c);
        stelth->x_speed *= 0.8f;
        stelth->m_310 *= 0.8f;
        stelth->vfunc_89();
        break;
    case 5:
        stelth->clear_attack_receipts();
        stelth->clear_field_388();
        break;
    }
}
}

extern "C" {
#pragma push
#pragma fp_contract on
void TObjEneMe3Stelth::handle_breakup_state(s32 arg1) {
    Vec ofs;
    Vec v;
    switch (arg1) {
    case 4:
        requested_action = 5;
        refresh_and_send_entity_flags();
        vfunc_94();
        m_3cc &= ~0xF;
        m_424 = 0;
        break;
    case 3:
        break;
    case 0:
        switch (m_424) {
        case 0:
            advance_animation();
            if (is_passing_frame(18.0f) != 0 || is_passing_frame(lbl_805DA818) != 0) {
                play_sound_effect(0x3A836, (u8 *)&position, 0, 0);
            }
            if (get_flag_b4() != 0) {
                m_424 = 1;
                m_428 = 0;
                ofs.x = 0.0f;
                ofs.y = TObjEneMe3Stelth__data_805DA824;
                ofs.z = 20.0f;
                ((TObjBoss2Tunnel *)(&ofs))->init_zako((u8 *)&position, rotation_y);
                TObjPlayer::spawn_effect_f8((s32)&ofs, 0x14);
            } else if (is_passing_frame(2.0f) != 0) {
                m_3cc |= 8;
            } else if (is_passing_frame(6.0f) != 0) {
                m_3cc &= ~8;
                m_3c0 = 0;
            }
            break;
        case 1:
            m_428++;
            if (m_428 >= 0x14) {
                m_424 = 2;
                m_3cc |= 2;
                TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe3Stelth__breakup_model, (s32)&me3_stelth_breakup_params, (s32)texlist, (s32)&position, (s32)rotation_y);
                VecCopy((Vec *)&v, (const Vec *)&position);
                v.x += 20.0f * sin_table_lookup(rotation_y);
                v.z += 20.0f * cos_table_lookup(rotation_y);
                ((TObjPlayer *)(&v))->trigger_dell_biter_events();
                play_sound_effect(0x3AD3A, (u8 *)&position, 0, 0);
            }
            vfunc_102();
            break;
        case 2:
            queue_destruction();
            break;
        }
        break;
    case 5:
        m_3cc &= ~8;
        break;
    }
}
#pragma pop
}

extern "C" {
#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TObjEneMe3Stelth__sub_800F2270(TObjEneMe3Stelth *stelth, s32 arg1) {
    Vec v;
    Vec p;
    Vec q;
    s32 arr[3];
    s32 i;
    s32 ang;
    switch (arg1) {
    case 4:
        stelth->requested_action = 0xC;
        stelth->set_field_378(0xC);
        stelth->vfunc_95();
        stelth->m_3cc &= ~6;
        stelth->m_3cc |= 1;
        stelth->m_424 = 0;
        break;
    case 3:
        if (stelth->m_424 == 2) {
            stelth->m_3c0 = 1;
            stelth->m_3cc |= 0x40000;
            stelth->set_indexed_flags(0, 0x8000000);
            if (stelth->random_ratio() <= stelth->m_3d8) {
                if (stelth->sub_800F47D4() != 0) {
                    if (stelth->random_ratio() > TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8]->m_14) {
                        stelth->transition_enemy_state(0x10);
                    } else {
                        stelth->transition_enemy_state(0xB);
                    }
                } else {
                    stelth->transition_enemy_state(0x10);
                }
            } else {
                stelth->transition_enemy_state(1);
            }
        }
        break;
    case 0:
        switch (stelth->m_424) {
        case 0:
            stelth->advance_animation();
            if (stelth->get_flag_b4() != 0) {
                stelth->m_3cc |= 4;
                stelth->m_404.reset_color();
                VecCopy(&v, &stelth->position);
                v.y = stelth->m_3d0 - 20.0f;
                stelth->m_424 = 1;
                play_sound_effect(0x3B23B, &stelth->position, 0, 0);
            }
            stelth->vfunc_102();
            stelth->vfunc_89();
            break;
        case 1:
            if (stelth->m_404.decay_value_toward_floor() != 0) {
                stelth->m_3cc |= 2;
                if (stelth->update_linked_position(200.0f) != 0) {
                    if (stelth->target == NULL) {
                        break;
                    }
                    arr[0] = (s32)(3.0f * stelth->random_ratio()) - 1;
                    arr[1] = (s32)(2.0f * stelth->random_ratio()) - 1;
                    if (arr[1] <= arr[0]) {
                        arr[1]++;
                    }
                    arr[2] = -(arr[0] + arr[1]);
                    for (i = 0; i < 3; i++) {
                        VecCopy(&p, &stelth->target->position);
                        ang = stelth->target->rotation_y + ((arr[i] + 1) << 14);
                        p.x = 20.0f * cos_table_lookup(ang) + p.x;
                        p.z = p.z - 20.0f * sin_table_lookup(ang);
                        p.y = p.y + TObjEneMe3Stelth__data_805DA820;
                        VecCopy(&q, &p);
                        q.x += p.x - stelth->target->position.x;
                        q.z += p.z - stelth->target->position.z;
                        if (TObjEneMe3Stelth__sub_800F0F84(stelth, &q) == 0 &&
                            csnVector(&stelth->target->position, &q, 0x88E0) == 0 &&
                            csnVectorUnder(&p, (u32 *)&stelth->m_120, 0x15) != 0 &&
                            ((TScene *)(&p))->find_section_at_position() == stelth->room) {
                            VecCopy(&stelth->position, &p);
                            stelth->rotation_y = ang + 0xC000;
                            break;
                        }
                    }
                }
                stelth->m_424 = 2;
            }
            break;
        }
        break;
    case 5:
        stelth->m_3cc &= ~4;
        break;
    }
}
#pragma pop
}

extern "C" {
void TObjEneMe3Stelth::add_instance() {
    load_projection_tex_matrix(stelth_projection_texture_handle);
    TObjEneMe3Stelth__render_node_index = TObjEneMe3Stelth__render_node_index + 1;
}
}

extern "C" {
void TObjEneMe3Stelth::render() {
    s32 mode;
    s32 draw;
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_with_debug_info();
        return;
    }
    sub_800F47D4();
    if (m_3cc & 2) {
        mode = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        mode = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, TObjEneMe3Stelth__data_805DA808);
    } else if (update_object_view_visibility(400.0f, TObjEneMe3Stelth__data_805DA808) != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    if (m_3c0 != 0 && is_split_screen() == 0 && dispatch_input_to_instance__18TAdEnterPasswordGCFi(this) != 0) {
        return;
    }
    if (mode != 0) {
        vfunc_108();
        update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb(&saved_model_draw_color, &model_material_color);
        if (is_split_screen() != 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3Stelth__material_color_pointers[i] != 0) {
                    *TObjEneMe3Stelth__material_color_pointers[i] = m_3e8;
                }
            }
            draw = 1;
            if (m_3c0 != 0) {
                if (m_3cc & 8) {
                    m_404.set_flags_and_apply_damage_color();
                } else {
                    model_render_flags |= 0x820;
                    NJS_ARGB c = stelth_render_color_a;
                    set_constant_material(&c);
                    set_chunk_material_override_pair(0xFF00, 0x800);
                }
                if (defer_render() != 0) {
                    draw = 0;
                }
            } else if (check_active_flag() != 0) {
                if (defer_render() != 0) {
                    draw = 0;
                }
            } else {
                model_render_flags |= 0x820;
                NJS_ARGB c = stelth_render_color_b;
                set_constant_material(&c);
                set_chunk_material_override_pair(0xFF00, 0x800);
            }
            if (draw != 0) {
                set_global_param__8TObjFishFl(texlist);
                push_matrix();
                post_translate_matrix(&position.x);
                translate_matrix(0, 0.0f, m_3d4, 0.0f);
                rotate_matrix_y(0, rotation_y);
                TObjEneMe3Stelth__render_node_index = 0;
                if (mode == 1) {
                    TObjMotion::draw();
                } else {
                    draw_motion_model();
                }
                pop_matrix();
            }
            if (m_3c0 != 0) {
                if (m_3cc & 8) {
                    m_404.clear_flag_and_notify();
                }
            } else {
                check_flag();
            }
        } else {
            s32 i;
            if (m_3c0 != 0) {
                TParticleCtrl::begin_effect_render();
                if (m_3cc & 8) {
                    TObjPlayer::setup_tev_stage();
                    model_render_flags |= 0x8021;
                    NJS_ARGB c = me3_stelth_render_color;
                    set_constant_material(&c);
                    set_color_blend_mode(1, 4, 5, 0);
                } else {
                    setup_particle_tev(0);
                }
            } else {
                model_render_flags |= 0x8021;
                NJS_ARGB c = me3_stelth_secondary_render_color;
                set_constant_material(&c);
                set_color_blend_mode(1, 4, 5, 0);
            }
            set_global_param__8TObjFishFl(texlist);
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3Stelth__material_color_pointers[i] != 0) {
                    *TObjEneMe3Stelth__material_color_pointers[i] = m_3e8;
                }
            }
            check_active_flag();
            push_matrix();
            post_translate_matrix(&position.x);
            translate_matrix(0, 0.0f, m_3d4, 0.0f);
            rotate_matrix_y(0, rotation_y);
            TObjEneMe3Stelth__render_node_index = 0;
            m_420 += 0x222;
            stelth_projection_texture_handle = m_420;
            set_model_node_callback((s32)((void *)TObjEneMe3Stelth::add_instance));
            if (m_3c0 != 0) {
                set_ginja_draw_list_mask(3);
            }
            if (mode == 1) {
                draw_ginja_motion_model();
            } else {
                draw_model__16TObjEneMe3StelthFPv(this);
            }
            if (m_3c0 != 0) {
                set_ginja_draw_list_mask(2);
            }
            set_model_node_callback(0);
            pop_matrix();
            check_flag();
            if (m_3c0 != 0) {
                reset_particle_tev();
            }
        }
        copy_argb(&model_material_color, &saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
    }
    TParticleCtrl::end_effect_render();
}
}

extern "C" {
void TObjEneMe3Stelth::setup_move() {
    if (get_target_info() != 0) {
        setup_move_bounds();
        sub_800F4758();
    }
}
}

extern "C" {
void TObjEneMe3Stelth::draw_with_debug_info() {
    s32 save[3];
    s32 flag;
    NJS_MOTION *motion;
    f32 frame;
    if (get_target_info() != 0) {
        if (sub_800F4850() != 0) {
            debug_printf_at(pack_debug_text_position(0, 2), stelth_debug_stelth_enable);
        } else {
            debug_printf_at(pack_debug_text_position(0, 2), stelth_debug_stelth_disable);
        }
        if (is_angle_in_range() != 0) {
            debug_printf_at(pack_debug_text_position(0xF, 2), stelth_debug_appear_ground);
        } else {
            debug_printf_at(pack_debug_text_position(0xF, 2), stelth_debug_appear_roof);
        }
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 4), (char *)stelth_debug_tecniq_attack);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 3), (char *)stelth_debug_stelth_on);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 6), (char *)stelth_debug_stelth_off);
        TObjEneMe1Gee::queue_debug_text(pack_debug_text_position(0, 5), (char *)stelth_debug_warp);
        if (sub_800F47D4() != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), stelth_debug_tex_spigell);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), stelth_debug_tex_berill);
        }
    }
    flag = sub_800F47D4();
    if (update_object_view_visibility(400.0f, TObjEneMe3Stelth__data_805DA808) != 0) {
        set_global_param__8TObjFishFl(texlist);
        TObjPlayer::toggle_particle_effect();
        if (flag != 0) {
            NJS_TEXNAME *textures = ((NJS_TEXLIST *)texlist)->textures;
            s32 i;
            for (i = 0; i < 3; i++) {
                save[i] = textures[i].texaddr;
            }
            for (i = 0; i < 3; i++) {
                textures[i].texaddr = textures[i + 3].texaddr;
            }
        }
        push_matrix();
        post_translate_matrix((f32 *)&position);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, TObjEneMe3Stelth__data_805DA80C, TObjEneMe3Stelth__data_805DA80C, TObjEneMe3Stelth__data_805DA80C);
        {
            s32 i;
            for (i = 0; i < 3; i++) {
                if (TObjEneMe3Stelth__material_color_pointers[i] != NULL) {
                    *TObjEneMe3Stelth__material_color_pointers[i] = 0xB000FFB0;
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
            motion = (NJS_MOTION *)motion_list[action_table[idx].motion].motion;
            frame = parameters[3];
            if (frame < 0.0f) {
                frame = 0.0f;
            } else if (frame > (motion->nbFrame - 1)) {
                frame = (motion->nbFrame - 1);
            }
            set_ginja_draw_list_mask(3);
            set_motion_packed_rotation();
            draw_ginja_model_with_motion(model, motion, frame);
            clear_motion_packed_rotation();
            set_ginja_draw_list_mask(1);
            current_motion = motion;
            this->frame = frame;
            frame = get_node_world_y();
            print_float_padded(pack_debug_text_position(0, 7), 5, frame);
        } else {
            model_render_flags &= ~0x400;
        }
        pop_matrix();
        if (flag != 0) {
            s32 i;
            NJS_TEXNAME *textures = ((NJS_TEXLIST *)texlist)->textures;
            for (i = 0; i < 3; i++) {
                textures[i].texaddr = save[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}
}

extern "C" {
void exec__16TObjEneMe3StelthFPvi(TObjEneMe3Stelth *stelth, s32 arg1) {
    switch (arg1) {
    case 4:
        stelth->requested_action = 0xC;
        stelth->set_field_378(6);
        stelth->vfunc_96();
        stelth->m_3cc &= 0xFFFFFFF1;
        stelth->m_3cc |= 1;
        stelth->m_424 = 0;
        play_sound_effect(0x3B23B, &stelth->position, 0, 0);
        return;
    case 3:
        if (stelth->m_424 == 3) {
            stelth->transition_enemy_state(6);
            stelth->m_3cc &= ~1;
            stelth->m_3cc |= 0x40000;
            stelth->set_indexed_flags(0, 0x08000000);
        }
        return;
    case 0:
        stelth->advance_animation();
        if (stelth->get_flag_b4() != 0) {
            stelth->m_424 = 3;
        } else if (is_split_screen() != 0) {
            switch (stelth->m_424) {
            case 0:
                if (stelth->is_passing_frame(4.0f) != 0) {
                    stelth->m_3cc |= 8;
                    stelth->m_404.reset_obstruction_fade();
                    stelth->m_424 = 1;
                }
                break;
            case 1:
                if (((TObjEneMe3SinowZoa *)&stelth->m_404)->advance_timer(0.2f) != 0) {
                    stelth->m_3cc &= ~8;
                    stelth->m_3c0 = 0;
                    stelth->m_424 = 2;
                }
                break;
            }
        } else if (stelth->is_passing_frame(25.0f) != 0) {
            stelth->m_3cc |= 8;
            stelth->m_3c0 = 1;
        } else if (stelth->is_passing_frame(29.0f) != 0) {
            stelth->m_3cc &= ~8;
        }
        stelth->vfunc_102();
        stelth->vfunc_89();
        return;
    case 5:
        stelth->m_3cc &= ~8;
        break;
    }
}
}

extern "C" {
void TObjEneMe3Stelth__sub_800F1440(TObjEneMe3Stelth *stelth, s32 arg1) {
    switch (arg1) {
    case 4:
        stelth->requested_action = 0xB;
        stelth->set_field_378(6);
        stelth->vfunc_96();
        stelth->m_3cc &= 0xFFFFFFF1;
        stelth->m_3cc |= 1;
        stelth->m_3cc |= 0x40000;
        stelth->clear_player_status_flag(0, 0x08000000);
        stelth->m_424 = 0;
        play_sound_effect(0x3B23B, &stelth->position, 0, 0);
        break;
    case 3:
        if (stelth->m_424 == 3) {
            stelth->transition_enemy_state(6);
            stelth->m_3cc &= ~1;
        }
        break;
    case 0:
        stelth->advance_animation();
        if (stelth->get_flag_b4() != 0) {
            stelth->m_424 = 3;
        } else if (is_split_screen() != 0) {
            switch (stelth->m_424) {
            case 0:
                if (stelth->is_passing_frame(4.0f) != 0) {
                    stelth->m_3cc |= 8;
                    NJS_ARGB q = me3_stelth_offset_vec;
                    ((TObjEneMe3SinowZoa *)&stelth->m_404)->copy_position_vector(&q);
                    stelth->m_424 = 1;
                }
                break;
            case 1:
                if (stelth->m_404.decay_value_toward_floor() != 0) {
                    stelth->m_3cc &= ~8;
                    stelth->m_3c0 = 0;
                    stelth->m_424 = 2;
                }
                break;
            }
        } else if (stelth->is_passing_frame(4.0f) != 0) {
            stelth->m_3cc |= 8;
        } else if (stelth->is_passing_frame(6.0f) != 0) {
            stelth->m_3cc &= ~8;
            stelth->m_3c0 = 0;
        }
        stelth->vfunc_102();
        stelth->vfunc_89();
        break;
    case 5:
        stelth->m_3cc &= ~8;
        stelth->m_3c0 = 0;
        break;
    }
}
}

extern "C" {
void TObjEneMe3Stelth__sub_800F1098(TObjEneMe3Stelth *stelth, s32 arg1) {
    Vec d;
    Vec out;
    s32 c[3];
    s32 r;
    switch (arg1) {
    case 4:
        stelth->requested_action = 0xA;
        stelth->set_field_378(6);
        stelth->vfunc_96();
        stelth->m_3cc &= 0xFFFFFFF8;
        stelth->m_3cc |= 0x10000;
        stelth->enemy_copy_target_destination();
        stelth->m_424 = 0;
        break;
    case 3:
        if (stelth->m_424 == 3) {
            stelth->transition_enemy_state(6);
        }
        break;
    case 0:
        stelth->update_prev_position();
        switch (stelth->m_424) {
        case 0:
        default:
            if (stelth->target == NULL) {
                stelth->transition_enemy_state(6);
                break;
            }
            {
                Vec dest = stelth->m_394;
                if (select_enemy_destination(stelth, &dest, 1) != 0) {
                    Vec pos = *(Vec *)&stelth->m_2fc;
                    copy_position_if_valid__10TObjPlayerFii((s32)stelth, (s32)&pos);
                    stelth->m_300 += TObjEneMe3Stelth__data_805DA820;
                    r = enemy_turn_toward_dest(stelth, ((StelthMovementParams *)stelth->movementParameters)->turn);
                    enemy_set_heading_velocity(((StelthMovementParams *)stelth->movementParameters)->speed, stelth, stelth->rotation_y);
                    move_with_wall_slide((u8 *)stelth);
                } else {
                    VecCopy(&d, &stelth->m_394);
                    subtract_vector(&d, (Vec *)&stelth->m_2fc);
                    r = stelth->turn_toward_direction(((StelthMovementParams *)stelth->movementParameters)->turn, &d);
                }
            }
            if (r < 0x100) {
                stelth->m_424 = 1;
                stelth->requested_action = 8;
            } else {
                stelth->requested_action = 0xA;
            }
            break;
        case 1:
            stelth->advance_animation();
            if (stelth->get_flag_b4() != 0) {
                stelth->m_428 = 0;
                stelth->m_424 = 2;
            }
            if (stelth->is_passing_frame(TObjEneMe3Stelth__data_805DA824) != 0) {
                stelth->advance_animation();
                push_matrix_from(identity_matrix);
                post_translate_matrix((f32 *)&stelth->position);
                rotate_matrix_y(0, stelth->rotation_y);
                set_motion_packed_rotation();
                stelth->calc_joint_matrices(TObjEneMe3Stelth__data_805DA824);
                clear_motion_packed_rotation();
                pop_matrix();
                push_matrix_from(anim_model_matrix_array[3]);
                c[0] = lbl_8043D680[0];
                c[1] = lbl_8043D680[1];
                c[2] = lbl_8043D680[2];
                matrix_mult_vec(0, (Vec *)c, &out);
                pop_matrix();
                if (stelth->target != NULL) {
                    VecCopy(&d, &stelth->m_394);
                    subtract_vector(&d, (Vec *)&stelth->m_2fc);
                    r = stelth->turn_toward_direction(((StelthMovementParams *)stelth->movementParameters)->turn, &d);
                } else {
                    r = ((s32 *)stelth->m_318)[3];
                }
                if (r < ((s32 *)stelth->m_318)[3] / 2 && stelth->target != NULL) {
                    if (game_difficulty_selection == 3) {
                        ((TTecRaFoie *)stelth)->create(&out, (u8 *)&stelth->m_394, (void *)TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8]->attack_tech_level));
                    } else {
                        TTecGiFoie::create(stelth, &out, (void *)TObjEneDD::clamp_frame_index(TObjEneMe3Stelth__behavior_params_by_variant[stelth->m_3c8]->attack_tech_level));
                    }
                } else {
                    stelth->m_424 = 3;
                }
            }
            break;
        case 2:
            if (++stelth->m_428 >= 0x3C) {
                stelth->m_424 = 3;
            }
            break;
        }
        break;
    case 5:
        break;
    }
    ((TObjPlayer *)stelth)->update_collisions();
}
}

extern "C" {
s32 TObjEneMe3Stelth__sub_800F0F84(TObjEneMe3Stelth *stelth, Vec *pos) {
    CollisionBody *body;
    s32 result;
    u32 saved;
    Vec sp;
    u8 unused[12];
    body = stelth->bodies;
    saved = body->flags;
    body->flags = 0x9D01;
    VecCopy(&sp, &stelth->position);
    VecCopy(&stelth->position, pos);
    TObjPlayer::init_all_slots();
    stelth->vfunc_89();
    if ((body->flags & 0x80000) && get_valid_target_player__10TNpcPlayerFv(get_entity_id(stelth->target)) == 0) {
        VecCopy(&stelth->position, &sp);
        TObjPlayer::init_all_slots();
        return 1;
    }
    if ((body->flags & 0x100000) && get_valid_target_player__10TNpcPlayerFv(stelth->entity_id) == 0) {
        VecCopy(&stelth->position, &sp);
        TObjPlayer::init_all_slots();
        return 1;
    }
    result = (body->flags & 0x200000) != 0;
    VecCopy(&stelth->position, &sp);
    TObjPlayer::init_all_slots();
    copy_collision_body(body, &TObjEneMe3Stelth__collision_body_template);
    body->flags = saved;
    return result;
}
}

extern "C" {
f32 TObjEneMe3Stelth::receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32) {
    if (m_3c0 == 1 && get_entity_id(source) < 0x1000 && random_ratio() <= m_3e0) {
        transition_enemy_state(0x12);
    } else if (mode == 2) {
        transition_enemy_state(6);
    }
    return TObjChara::receive_direct_attack(source, payload, collider, -1, -1);
}
}

extern "C" {
void *TObjEneMe3StelthReal::create(void *set_data) {
    return new TObjEneMe3StelthReal(tl_04, set_data);
}
}

extern "C" {
TObjEneMe3StelthReal::TObjEneMe3StelthReal(TObject *parent, void *set_data) : TObjEneMe3Stelth(parent) {
    m_name = TObjEneMe3StelthReal__class_name;
    invoke_initialization_hook(set_data);
    setup_move_bounds();
    init_common();
    mode = 0;
    dispatch_action(mode, 4);
}
}

extern "C" {
TObjEneMe3StelthReal::~TObjEneMe3StelthReal() {}
}

extern "C" {
void TObjEneMe3StelthReal::vfunc_63() { TObjEneMe3Stelth::vfunc_63(); }
}

extern "C" {
void TObjEneMe3StelthReal::vfunc_62() { TObjEneMe3Stelth::vfunc_62(); }
}

extern "C" {
void TObjEneMe3StelthReal::vfunc_107() {
    m_3ec = m_3ec + 1;
    if (m_3ec >= 2 || random_ratio() < lbl_805DA81C) {
        transition_enemy_state(9);
        return;
    }
    transition_enemy_state(6);
}
}

extern "C" {
void TObjEneMe3StelthReal::vfunc_111() {  }
}

void TObjEneMe3Stelth__sub_800F0C90(TObjEneMe3Stelth *stelth) {
    if (stelth->is_passing_frame(lbl_805DA814) != 0 || stelth->is_passing_frame(lbl_805DA818) != 0) {
        stelth->try_spawn_ground_effect((s32)&stelth->position);
    }
}

void TObjEneMe3Stelth::play_hit_effect() {
    if (try_spawn_ground_effect((s32)&position) != 0) {
        play_sound_effect(0x3A836, &position, 0, 0);
        return;
    }
    spawn_particle_effect(&position, 0xF3);
    play_sound_effect(0x3A836, &position, 0, 0);
}

s32 TObjEneMe3Stelth::try_spawn_ground_effect(s32 arg1) {
    Vec pos;
    void *effect;
    s32 *hit;
    VecCopy(&pos, (const Vec *)arg1);
    pos.y += TObjEneMe3Stelth__data_805DA808;
    hit = csnVectorUnder(&pos, (u32 *)&m_120, 0x15);
    if (hit != NULL && (hit[0] & 4)) {
        effect = spawn_particle_effect((void *)(hit[1] + 0x38), 0x49);
        if (effect != NULL) {
            attach_particle_model((u8 *)effect, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, TObjEneMe3Stelth__data_805DA80C);
        }
        spawn_particle_effect((void *)(hit[1] + 0x38), 0xA4);
        TObjEneGibbles__sub_800D8988(&position);
        return 1;
    }
    return 0;
}
