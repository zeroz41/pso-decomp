// The seabed tanks: the set object TObjSeabedSuiso_CH, the breakable tank
// TObjSeabedSuisoBrakable and its debris chip TObjSuisoChip. The tank
// resources they share are loaded by TObjSeabedSuisoBrakable.cpp.
//
// Built -inline off,deferred: the functions come out last to first, so the
// file is written from the end of the unit's .text back.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/seabed/TObjSuisoChip.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/object/seabed/TObjSeabedSuiso_CH.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/map/FloorArea.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/vector.h"
#include "pso/render/NinjaUtil.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"

extern s32 actor_frame_tick;

// One kind of TObjSeabedSuiso_CH.
struct SeabedSuisoKind {
    s32 model;         // model index in the tank archive
    s32 motion;        // motion index, -1 for none
    f32 motion_speed;  // frames per update
    s32 particle;      // particle effect id, -1 for none
    f32 view_range;
    f32 model_radius;
};

// One piece of a broken tank: its model and where it sits on the tank.
struct SeabedSuisoPiece {
    s32 model;  // model index in the tank archive, -1 ends the set
    Vec pos;
};

// The whole tank of one TObjSeabedSuisoBrakable kind and the chips it
// breaks into.
struct SeabedSuisoBreakSet {
    SeabedSuisoPiece whole;
    SeabedSuisoPiece chips[17];
};
#pragma push
#pragma readonly_strings on
// The tank archives of the lower (bm_obj_seabed_suiso) and the upper
// (bm_obj_seabed_suiso_2) seabed: the same 50 models and 2 motions.
const char *bm_obj_seabed_suiso_model_names[51] = {
    "contena01_obj2.gj",
    "kowaremoni_1.gj",
    "kowaremoni_10.gj",
    "kowaremoni_2.gj",
    "kowaremoni_3.gj",
    "kowaremoni_4.gj",
    "kowaremoni_5.gj",
    "kowaremoni_6.gj",
    "kowaremoni_7.gj",
    "kowaremoni_8.gj",
    "kowaremoni_9.gj",
    "kowaremoni_obj.gj",
    "moni02.gj",
    "obj_o_orga.gj",
    "suisou_c2koware_1.gj",
    "suisou_c2koware_10.gj",
    "suisou_c2koware_11.gj",
    "suisou_c2koware_12.gj",
    "suisou_c2koware_13.gj",
    "suisou_c2koware_14.gj",
    "suisou_c2koware_15.gj",
    "suisou_c2koware_16.gj",
    "suisou_c2koware_17.gj",
    "suisou_c2koware_2.gj",
    "suisou_c2koware_3.gj",
    "suisou_c2koware_4.gj",
    "suisou_c2koware_5.gj",
    "suisou_c2koware_6.gj",
    "suisou_c2koware_7.gj",
    "suisou_c2koware_8.gj",
    "suisou_c2koware_9.gj",
    "suisou_c2koware_obj1.gj",
    "suisou_h_obj1.gj",
    "suisou_l2_obj1.gj",
    "suisou_l2koware_1.gj",
    "suisou_l2koware_10.gj",
    "suisou_l2koware_11.gj",
    "suisou_l2koware_12.gj",
    "suisou_l2koware_13.gj",
    "suisou_l2koware_14.gj",
    "suisou_l2koware_15.gj",
    "suisou_l2koware_16.gj",
    "suisou_l2koware_2.gj",
    "suisou_l2koware_3.gj",
    "suisou_l2koware_4.gj",
    "suisou_l2koware_5.gj",
    "suisou_l2koware_6.gj",
    "suisou_l2koware_7.gj",
    "suisou_l2koware_8.gj",
    "suisou_l2koware_9.gj",
    NULL,
};
const char *bm_obj_seabed_suiso_motion_names[3] = { "moni02.njm", "suisou_h_obj1.njm", NULL };
BmlResourceDescriptor bm_obj_seabed_suiso_resource_descriptor = {
    "bm_obj_seabed_suiso.bml", bm_obj_seabed_suiso_model_names, bm_obj_seabed_suiso_motion_names, 50, 2,
};
const char *bm_obj_seabed_suiso_2_model_names[51] = {
    "contena01_obj2.gj",
    "kowaremoni_1.gj",
    "kowaremoni_10.gj",
    "kowaremoni_2.gj",
    "kowaremoni_3.gj",
    "kowaremoni_4.gj",
    "kowaremoni_5.gj",
    "kowaremoni_6.gj",
    "kowaremoni_7.gj",
    "kowaremoni_8.gj",
    "kowaremoni_9.gj",
    "kowaremoni_obj.gj",
    "moni02.gj",
    "obj_o_orga.gj",
    "suisou_c2koware_1.gj",
    "suisou_c2koware_10.gj",
    "suisou_c2koware_11.gj",
    "suisou_c2koware_12.gj",
    "suisou_c2koware_13.gj",
    "suisou_c2koware_14.gj",
    "suisou_c2koware_15.gj",
    "suisou_c2koware_16.gj",
    "suisou_c2koware_17.gj",
    "suisou_c2koware_2.gj",
    "suisou_c2koware_3.gj",
    "suisou_c2koware_4.gj",
    "suisou_c2koware_5.gj",
    "suisou_c2koware_6.gj",
    "suisou_c2koware_7.gj",
    "suisou_c2koware_8.gj",
    "suisou_c2koware_9.gj",
    "suisou_c2koware_obj1.gj",
    "suisou_h_obj1.gj",
    "suisou_l2_obj1.gj",
    "suisou_l2koware_1.gj",
    "suisou_l2koware_10.gj",
    "suisou_l2koware_11.gj",
    "suisou_l2koware_12.gj",
    "suisou_l2koware_13.gj",
    "suisou_l2koware_14.gj",
    "suisou_l2koware_15.gj",
    "suisou_l2koware_16.gj",
    "suisou_l2koware_2.gj",
    "suisou_l2koware_3.gj",
    "suisou_l2koware_4.gj",
    "suisou_l2koware_5.gj",
    "suisou_l2koware_6.gj",
    "suisou_l2koware_7.gj",
    "suisou_l2koware_8.gj",
    "suisou_l2koware_9.gj",
    NULL,
};
const char *bm_obj_seabed_suiso_2_motion_names[3] = { "moni02.njm", "suisou_h_obj1.njm", NULL };
BmlResourceDescriptor bm_obj_seabed_suiso_2_resource_descriptor = {
    "bm_obj_seabed_suiso_2.bml", bm_obj_seabed_suiso_2_model_names, bm_obj_seabed_suiso_2_motion_names, 50, 2,
};

const SeabedSuisoTextureNames seabed_suiso_2_texture_names = {
    { "nk_h128_gazo0", "nk_h128_gazo02", "nk_h032_kasan05", "nk_o032_orga01", "nk_h064_gragh04" },
};
const SeabedSuisoTextureNames seabed_suiso_texture_names = {
    { "nk_h128_gazo0", "nk_h128_gazo02", "nk_h008_kasan03", "nk_o032_orga01", "nk_h064_gragh04" },
};

const char *TObjSeabedSuiso_CH::class_name = "TObjSeabedSuiso_CH";
const char *TObjSeabedSuisoBrakable::class_name = "TObjSeabedSuisoBrakable";
const char *TObjSuisoChip::class_name = "TObjSuisoChip";
#pragma pop

SeabedSuisoKind seabed_suiso_kind_params[4] = {
    { 32, 1, 0.1f, 514, 300.0f, 60.0f },
    { 0, -1, 0.0f, -1, 300.0f, 60.0f },
    { 12, 0, 0.05f, -1, 300.0f, 60.0f },
    { 13, -1, 0.1f, -1, 300.0f, 60.0f },
};

CollisionBody seabed_suiso_chip_collision_bodies[4] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 10.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 10.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 1.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 18.0f, 18.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

SeabedSuisoBreakSet seabed_suiso_break_sets[3] = {
    {
        { 33, { 0.0f, 0.0f, 0.0f } },
        {
            { 34, { 0.0f, 37.0f, 0.0f } }, { 42, { 0.0f, 37.0f, 0.0f } }, { 43, { 0.0f, 32.0f, 0.0f } },
            { 44, { 0.0f, 32.0f, 0.0f } }, { 45, { 14.0f, 20.0f, 0.0f } }, { 46, { -14.0f, 20.0f, 0.0f } },
            { 47, { 0.0f, 20.0f, -5.0f } }, { 48, { 0.0f, 20.0f, 5.0f } }, { 49, { 0.0f, 7.0f, 0.0f } },
            { 35, { 0.0f, 5.0f, 0.0f } }, { 36, { 0.0f, 26.0f, 0.0f } }, { 37, { 0.0f, 3.0f, 0.0f } },
            { 38, { 18.0f, 18.0f, 8.0f } }, { 39, { 18.0f, 18.0f, -8.0f } }, { 40, { -18.0f, 18.0f, -8.0f } },
            { 41, { -18.0f, 18.0f, 8.0f } }, { -1, { 0.0f, 0.0f, 0.0f } },
        },
    },
    {
        { 31, { 0.0f, 0.0f, 0.0f } },
        {
            { 14, { -3.0f, 53.0f, 0.0f } }, { 23, { 2.0f, 53.0f, 3.0f } }, { 24, { 3.0f, 34.0f, 0.0f } },
            { 25, { -3.0f, 34.0f, 0.0f } }, { 26, { 4.0f, 34.0f, 4.0f } }, { 27, { 4.0f, 20.0f, -4.0f } },
            { 28, { -4.0f, 20.0f, -4.0f } }, { 29, { -4.0f, 20.0f, 4.0f } }, { 30, { 0.0f, 26.0f, 0.0f } },
            { 15, { 0.0f, 27.0f, 0.0f } }, { 16, { 5.0f, 13.0f, 0.0f } }, { 17, { -5.0f, 13.0f, 0.0f } },
            { 18, { 6.0f, 6.0f, 6.0f } }, { 19, { 6.0f, 6.0f, -6.0f } }, { 20, { -6.0f, 6.0f, -6.0f } },
            { 21, { -6.0f, 6.0f, 6.0f } }, { 22, { 0.0f, 7.0f, 0.0f } },
        },
    },
    {
        { 11, { 0.0f, 0.0f, 0.0f } },
        {
            { 1, { -10.0f, 0.0f, 0.0f } }, { 3, { 10.0f, 10.0f, 0.0f } }, { 4, { 0.0f, 8.0f, 0.0f } },
            { 5, { 0.0f, 5.0f, 3.0f } }, { 6, { -5.0f, 15.0f, 1.0f } }, { 7, { 5.0f, 15.0f, 1.0f } },
            { 8, { -5.0f, 8.0f, 1.0f } }, { 9, { 5.0f, 8.0f, 1.0f } }, { 10, { 0.0f, 1.0f, -2.0f } },
            { 2, { 0.0f, 1.0f, 2.0f } }, { -1, { 0.0f, 0.0f, 0.0f } }, { -1, { 0.0f, 0.0f, 0.0f } },
            { -1, { 0.0f, 0.0f, 0.0f } }, { -1, { 0.0f, 0.0f, 0.0f } }, { -1, { 0.0f, 0.0f, 0.0f } },
            { -1, { 0.0f, 0.0f, 0.0f } }, { -1, { 0.0f, 0.0f, 0.0f } },
        },
    },
};

CollisionBody seabed_suiso_brakable_collision_bodies[3] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 10.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 12.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};


BmlResource *TObjSeabedSuisoBrakable::bml_resource;
u32 TObjSeabedSuisoBrakable::texture_list;
s32 TObjSeabedSuiso_CH::last_uv_scroll_tick;
s32 TObjSeabedSuisoBrakable::last_uv_scroll_tick;

void *TObjSeabedSuisoBrakable::get_model(int index) {
    if (bml_resource != NULL) {
        return (void *)get_bml_model(bml_resource, index);
    }
    return NULL;
}

s32 TObjSeabedSuisoBrakable::get_texlist(int index) {
    return texture_list;
}

AnimationMotion *TObjSeabedSuisoBrakable::get_bml_motion_by_index(s32 index) {
    if (bml_resource != NULL) {
        return get_bml_motion(bml_resource, index);
    }
    return NULL;
}


TObjSeabedSuiso_CH::TObjSeabedSuiso_CH(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    init_kind_params();
    kind = (s32)fabs_float((f32)set_params[0]);
    if (kind > 3) {
        kind = 3;
    }
    init_collision_body_parts(this, &seabed_suiso_chip_collision_bodies[kind], 1);
    register_object_by_id();
    if (seabed_suiso_kind_params[kind].particle >= 0) {
        emitter = create_particle_emitter(&position, seabed_suiso_kind_params[kind].particle);
    } else {
        emitter = NULL;
    }
}

void TObjSeabedSuiso_CH::init_kind_params() {
    u32 params;

    kind = (s32)fabs_float((f32)set_params[0]);
    if (kind > 3) {
        kind = 3;
    }
    kind_model = TObjSeabedSuisoBrakable::get_model(seabed_suiso_kind_params[kind].model);
    if (seabed_suiso_kind_params[kind].motion != -1) {
        motion = TObjSeabedSuisoBrakable::get_bml_motion_by_index(seabed_suiso_kind_params[kind].motion);
        animation_step = seabed_suiso_kind_params[kind].motion_speed;
    } else {
        motion = NULL;
        animation_step = 0.0f;
    }
    if (motion != NULL) {
        animation_end_frame = (f32)motion->frameCount - 1.0f;
    }
    view_range = seabed_suiso_kind_params[kind].view_range;
    model_radius = seabed_suiso_kind_params[kind].model_radius;
    if (kind == 3) {
        params = set_params[1];
        switch_count = params >> 16;
        switch_count = (s32)switch_count < 0 ? 0 : (0xFF < (s32)switch_count ? 0xFF : (s32)switch_count);
        first_switch = params & 0xFFFF;
        first_switch = first_switch < 0 ? 0 : (0x100 - (s32)switch_count < first_switch ? 0x100 - (s32)switch_count : first_switch);
    } else {
        switch_count = 0;
        first_switch = 0;
    }
}

TObjSeabedSuiso_CH::~TObjSeabedSuiso_CH() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjSeabedSuiso_CH::render() {
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        TParticleCtrl::end_effect_render();
        update_state();
        TObjFish::set_global_param(TObjSeabedSuisoBrakable::get_texlist(0));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (motion != NULL) {
            draw_ginja_model_with_motion(kind_model, motion, animation_frame);
        } else {
            draw_ginja_box_tree((u8 *)kind_model);
        }
        pop_matrix();
        set_model_node_callback(0);
    }
}

void TObjSeabedSuiso_CH::update_state() {
    switch (kind) {
    case 2:
        scroll_kind2_uvs();
        return;
    case 3:
        update_switch_lock();
    case 0:
        return;
    }
}

void TObjSeabedSuiso_CH::scroll_kind2_uvs() {
    s32 entry;
    NJS_OBJECT *node = find_object_node((NJS_OBJECT *)kind_model, 4);

    if (last_uv_scroll_tick != actor_frame_tick) {
        if (node != NULL && node->model != NULL) {
            entry = TObjSeabedSuisoBrakable::get_texture_entry(0);
            if (entry != -1) {
                scroll_ginja_mesh_uvs(node->model, 1, 0, entry, 1);
            }
        }
        last_uv_scroll_tick = actor_frame_tick;
    }
    set_model_node_callback((s32)TObjSeabedSuisoBrakable::notify_break);
}

void TObjSeabedSuiso_CH::update_switch_lock() {
    NJS_OBJECT *node;
    s32 entry;
    s32 all_set = 1;
    s32 i;

    if ((s32)switch_count > 0) {
        for (i = 0; i < (s32)switch_count; i++) {
            if (is_current_floor_switch_set((u16)(first_switch + i)) == 0) {
                all_set = 0;
            }
        }
    }
    if (all_set != 0) {
        if ((node = TObjSeabedSuisoBrakable::get_model13_node(1)) != NULL) {
            node->evalflags &= ~8;
        }
        if ((node = TObjSeabedSuisoBrakable::get_model13_node(2)) != NULL) {
            node->evalflags &= ~8;
        }
    } else {
        if ((node = TObjSeabedSuisoBrakable::get_model13_node(1)) != NULL) {
            node->evalflags |= 8;
        }
        if ((node = TObjSeabedSuisoBrakable::get_model13_node(2)) != NULL) {
            node->evalflags |= 8;
        }
    }
    if (last_uv_scroll_tick != actor_frame_tick) {
        entry = TObjSeabedSuisoBrakable::get_texture_entry(4);
        node = TObjSeabedSuisoBrakable::get_model13_node(2);
        if (node != NULL && entry != -1) {
            scroll_ginja_mesh_uvs(node->model, 0, 1, entry, 1);
        }
        entry = TObjSeabedSuisoBrakable::get_texture_entry(3);
        node = TObjSeabedSuisoBrakable::get_model13_node(0);
        if (node != NULL && entry != -1) {
            scroll_ginja_mesh_uvs(node->model, 0, 3, entry, 1);
        }
        last_uv_scroll_tick = actor_frame_tick;
    }
}

void TObjSeabedSuiso_CH::run_task() {
    if (motion != NULL) {
        update_anim_phase();
    }
}

void *TObjSeabedSuiso_CH::create(void *set_data) {
    return new TObjSeabedSuiso_CH(tl_05, set_data);
}

void TObjSeabedSuisoBrakable::notify_break(NJS_OBJECT *node) {
    if (get_model12_node(0) == node || get_model12_node(1) == node || get_model12_node(2) == node) {
        TParticleCtrl::begin_effect_render();
        return;
    }
    TParticleCtrl::end_effect_render();
}


TObjSeabedSuisoBrakable::TObjSeabedSuisoBrakable(void *set_data) {
    m_name = class_name;
    apply_object_set_data(set_data);
    kind = (s32)fabs_float((f32)set_params[1]);
    if (kind > 2) {
        kind = 2;
    }
    init_model();
    m_b8 = set_params[0];
    if ((s32)m_b8 < 0 || (s32)m_b8 >= 0x100) {
        m_b8 = -1;
    }
    init_collision_body_parts(this, &seabed_suiso_brakable_collision_bodies[kind], 1);
    register_object_by_id();
}

TObjSeabedSuisoBrakable::~TObjSeabedSuisoBrakable() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjSeabedSuisoBrakable::create_instance(void *set_data) {
    return new TObjSeabedSuisoBrakable(set_data);
}

void TObjSeabedSuisoBrakable::spawn_break_effect() {}

void TObjSeabedSuisoBrakable::vfunc_16() {
    TObjChipParams params;
    SeabedSuisoPiece *piece;
    s32 i;

    params.pad_0[0] = 0.35f;
    params.pad_0[1] = 0.07f;
    params.pad_0[2] = 0.54f;
    VecCopy((Vec *)params.pos, &position);
    params.pad_18[0] = 2.5f;
    params.pad_18[1] = 4.0f;
    params.pad_18[2] = 2.5f;
    params.pad_24[0] = 0x200;
    params.pad_24[1] = 0x150;
    params.pad_24[2] = 0x200;
    params.pad_30[0] = 1;
    params.pad_30[1] = 60;
    params.pad_38[0] = position.y;
    params.pad_38[1] = 1.0f;
    params.model = 0;
    params.textures = get_texlist(0);
    params.pad_48 = 17;
    piece = seabed_suiso_break_sets[kind].chips;
    for (i = 0; i < 17; i++, piece++) {
        if (piece->model >= 0) {
            params.model = (s32)get_model(piece->model);
            params.pos[0] = piece->pos.x;
            params.pos[1] = piece->pos.y;
            params.pos[2] = piece->pos.z;
            new TObjSuisoChip(this, &params);
        }
    }
}

void TObjSeabedSuisoBrakable::init_model() {
    model = get_model(seabed_suiso_break_sets[kind].whole.model);
    texlist = get_texlist(0);
    m_b0 = 40.0f;
}

void TObjSeabedSuisoBrakable::render() {
    vfunc_14();
    TORockCave::render();
}

void TObjSeabedSuisoBrakable::vfunc_14() {
    NJS_OBJECT *node;
    s32 entry;

    if (kind == 2) {
        node = find_object_node((NJS_OBJECT *)model, 2);
        if (last_uv_scroll_tick != actor_frame_tick) {
            if (node != NULL && node->model != NULL) {
                entry = get_texture_entry(1);
                if (entry != -1) {
                    scroll_ginja_mesh_uvs(node->model, 0, 1, entry, 1);
                }
            }
            last_uv_scroll_tick = actor_frame_tick;
        }
    }
    if (kind == 0) {
        node = find_object_node((NJS_OBJECT *)model, 8);
        if (last_uv_scroll_tick != actor_frame_tick) {
            if (node != NULL && node->model != NULL) {
                entry = get_texture_entry(2);
                if (entry != -1) {
                    scroll_ginja_mesh_uvs(node->model, 0, 1, entry, 1);
                }
            }
            last_uv_scroll_tick = actor_frame_tick;
        }
    }
}


TObjSuisoChip::TObjSuisoChip(TObjBase *owner, TObjChipParams *params) : TObjChip(tl_05, params) {
    m_name = class_name;
    if (owner != NULL) {
        VecCopy(&origin, &owner->position);
        rotation_y = owner->rotation_y;
    } else {
        origin.y = 0.0f;
        origin.y = 0.0f;
        origin.x = 0.0f;
        rotation_y = 0;
    }
    pad_244 = 0;
    pad_248 = 20;
}

TObjSuisoChip::TObjSuisoChip(TObjBase *owner, TObjChipSpawnParams *params) : TObjChip(tl_05, params) {
    m_name = class_name;
    if (owner != NULL) {
        VecCopy(&origin, &owner->position);
        rotation_y = owner->rotation_y;
    } else {
        origin.y = 0.0f;
        origin.y = 0.0f;
        origin.x = 0.0f;
        rotation_y = 0;
    }
    pad_244 = 0;
    pad_248 = 20;
}

TObjSuisoChip::~TObjSuisoChip() {}
