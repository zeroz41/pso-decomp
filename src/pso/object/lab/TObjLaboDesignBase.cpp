#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/object/lab/TObjLaboDesignBase.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"


#pragma readonly_strings on

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

const char *bm_obj_comp_army_motion_filenames[1] = {0};
const char *bm_obj_comp_norm_motion_filenames[1] = {0};
const char *bm_obj_desk_motion_filenames[1] = {0};
const char *bm_obj_partition_army_motion_filenames[1] = {0};
const char *bm_obj_partition_norm_motion_filenames[1] = {0};
const char *bm_obj_table_labo_motion_filenames[1] = {0};
extern const char *bm_obj_comp_army_model_filenames[2];
extern BmlResourceDescriptor bm_obj_comp_army_resource_descriptor;
extern const char *bm_obj_comp_norm_model_filenames[2];
extern BmlResourceDescriptor bm_obj_comp_norm_resource_descriptor;
extern const char *bm_obj_desk_model_filenames[2];
extern BmlResourceDescriptor bm_obj_desk_resource_descriptor;
extern const char *bm_obj_partition_army_model_filenames[2];
extern BmlResourceDescriptor bm_obj_partition_army_resource_descriptor;
extern const char *bm_obj_partition_norm_model_filenames[2];
extern BmlResourceDescriptor bm_obj_partition_norm_resource_descriptor;
extern const char *bm_obj_table_labo_model_filenames[2];
extern BmlResourceDescriptor bm_obj_table_labo_resource_descriptor;
__declspec(section ".data") const char *bm_obj_comp_army_model_filenames[2] = {
    "labocity_computer_army.gj", NULL,
};
BmlResourceDescriptor bm_obj_comp_army_resource_descriptor = {
    "bm_obj_comp_army.bml", bm_obj_comp_army_model_filenames, bm_obj_comp_army_motion_filenames, 1, 0,
};
__declspec(section ".data") const char *bm_obj_comp_norm_model_filenames[2] = {
    "labocity_computer_norm.gj", NULL,
};
BmlResourceDescriptor bm_obj_comp_norm_resource_descriptor = {
    "bm_obj_comp_norm.bml", bm_obj_comp_norm_model_filenames, bm_obj_comp_norm_motion_filenames, 1, 0,
};
__declspec(section ".data") const char *bm_obj_desk_model_filenames[2] = {
    "labocity_desk.gj", NULL,
};
BmlResourceDescriptor bm_obj_desk_resource_descriptor = {
    "bm_obj_desk.bml", bm_obj_desk_model_filenames, bm_obj_desk_motion_filenames, 1, 0,
};
__declspec(section ".data") const char *bm_obj_partition_army_model_filenames[2] = {
    "labocity_partition_army.gj", NULL,
};
BmlResourceDescriptor bm_obj_partition_army_resource_descriptor = {
    "bm_obj_partition_army.bml", bm_obj_partition_army_model_filenames, bm_obj_partition_army_motion_filenames, 1, 0,
};
__declspec(section ".data") const char *bm_obj_partition_norm_model_filenames[2] = {
    "labocity_partition_norm.gj", NULL,
};
BmlResourceDescriptor bm_obj_partition_norm_resource_descriptor = {
    "bm_obj_partition_norm.bml", bm_obj_partition_norm_model_filenames, bm_obj_partition_norm_motion_filenames, 1, 0,
};
__declspec(section ".data") const char *bm_obj_table_labo_model_filenames[2] = {
    "labocity_table.gj", NULL,
};
BmlResourceDescriptor bm_obj_table_labo_resource_descriptor = {
    "bm_obj_table_labo.bml", bm_obj_table_labo_model_filenames, bm_obj_table_labo_motion_filenames, 1, 0,
};
// Archive descriptors of the six laboratory design objects, by object id.
struct LaboDesignObjectEntry {
    s32 id;
    BmlResourceDescriptor *descriptor;
};

LaboDesignObjectEntry labo_design_object_descriptors[7] = {
    {0, &bm_obj_comp_army_resource_descriptor},
    {1, &bm_obj_comp_norm_resource_descriptor},
    {2, &bm_obj_desk_resource_descriptor},
    {3, &bm_obj_partition_army_resource_descriptor},
    {4, &bm_obj_partition_norm_resource_descriptor},
    {5, &bm_obj_table_labo_resource_descriptor},
    {-1, NULL},
};
CollisionBody labo_design_entry_table[6] = {
    { { 0.0f, 20.0f, 0.0f }, 5.0f, 10.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 20.0f, 0.0f }, 5.0f, 10.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 20.0f, 0.0f }, 5.0f, 10.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 20.0f, 0.0f }, 5.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 20.0f, 0.0f }, 5.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 20.0f, 0.0f }, 10.0f, 40.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

void *TObjLaboDesignBase::create_state5(void *set_data) {
    return new TObjLaboDesignBase(tl_05, set_data, 5);
}
const char *TObjLaboDesignBase::class_name = "TObjLaboDesignBase";
void *TObjLaboDesignBase::create_state4(void *set_data) {
    return new TObjLaboDesignBase(tl_05, set_data, 4);
}

void *TObjLaboDesignBase::create_state3(void *set_data) {
    return new TObjLaboDesignBase(tl_05, set_data, 3);
}

void *TObjLaboDesignBase::create_state2(void *set_data) {
    return new TObjLaboDesignBase(tl_05, set_data, 2);
}

void *TObjLaboDesignBase::create_state1(void *set_data) {
    return new TObjLaboDesignBase(tl_05, set_data, 1);
}

void *TObjLaboDesignBase::create(void *set_data) {
    return new TObjLaboDesignBase(tl_05, set_data, 0);
}

s32 TObjLaboDesignBase::update_object_view_visibility(f32 near_dist, f32 far_dist) {
    if (TMainTask::get_render_pass() == 1) {
        return visibility;
    }
    if (xz_distance_squared(&this->position, &camera_ctrl_instance->pos) < (far_dist * far_dist)) {
        visibility = 1;
        return visibility;
    }
    return TObjBase::update_object_view_visibility(near_dist, far_dist);
}

void TObjLaboDesignBase::draw_node_tree(NJS_OBJECT *node) {
    u32 flags;
    NJS_OBJECT *child;
    do {
        flags = node->evalflags;
        if (flags & 0x100000) {
            TParticleCtrl::begin_effect_render();
        } else {
            TParticleCtrl::end_effect_render();
        }
        push_matrix();
        if (!(flags & 1)) {
            post_translate_matrix(node->pos);
        }
        if (!(flags & 2)) {
            rotate_matrix_by_node_angles(node->ang, flags & 0x20);
        }
        if (!(flags & 4)) {
            scale_current_matrix(node->scl);
        }
        if (!(flags & 8)) {
            draw_ginja_model(node->model);
        }
        if (!(flags & 0x10)) {
            child = node->child;
            if (child != NULL) {
                draw_node_tree(child);
            }
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}

void TObjLaboDesignBase::render_model() {
    TObjFish::set_global_param(get_bml_texlist(model_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_node_tree((NJS_OBJECT *)get_bml_model(model_resource, 0));
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

typedef void (TObjLaboDesignBase::*RenderAction)();

void TObjLaboDesignBase::render() {
    static RenderAction tbl[8] = {
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
    };
    if (update_object_view_visibility(view_depth, view_radius) == 1) {
        (this->*(tbl[state]))();
    }
}

void TObjLaboDesignBase::run_task() {}

TObjLaboDesignBase::~TObjLaboDesignBase() {
    if (map_csn != NULL) {
        map_csn->queue_destruction();
        map_csn = 0;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TObjLaboDesignBase::TObjLaboDesignBase(TObject *parent, void *set_data, s32 state) : TObjCollidable(parent) {
    s32 design;
    m_name = class_name;
    apply_object_set_data(set_data);
    this->state = state;
    model_resource = get_labo_design_object(this->state);
    init_collision_body_parts(this, get_labo_design_entry(this->state), 1);
    register_object_by_id();
    view_depth = 400.0f;
    view_radius = 50.0f;
    map_csn = NULL;
    design = this->state;
    if ((design == 3) || (design == 4)) {
        ObjectSetData wall_set = *(ObjectSetData *)set_data;
        wall_set.scale.x = 40.0f;
        wall_set.scale.y = 20.0f;
        wall_set.scale.z = 10.0f;
        map_csn = TObjMapCsn::create(&wall_set);
    }
}

CollisionBody *get_labo_design_entry(int design) { return &labo_design_entry_table[design]; }


BmlResource *get_labo_design_object(int design) { return labo_design_object_table[design]; }

void free_object_table(void) {
    s32 i;
    for (i = 5; i >= 0; i--) {
        if (labo_design_object_table[i] != 0) {
            delete labo_design_object_table[i];
            labo_design_object_table[i] = NULL;
        }
    }
}

void load_labo_design_object_table(void) {
    s32 i;
    LaboDesignObjectEntry *e;
    BmlResource *resource;
    for (i = 0; i < 6; i++) {
        labo_design_object_table[i] = NULL;
    }
    e = labo_design_object_descriptors;
    if (e != NULL) {
        while (e->id != -1) {
            resource = new BmlResource(5, e->descriptor, 0, 0, NULL);
            labo_design_object_table[e->id] = resource;
            e++;
        }
    }
}


BmlResource *labo_design_object_table[6];
