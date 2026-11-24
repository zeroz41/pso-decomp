#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_80365348.h"
#include "pso/system/task/TObject.h"
#include "pso/object/lab/TObjLaboDesignBase.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"


#pragma readonly_strings on

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_3C { u8 bytes[0x3C]; };

extern "C" {
const char *lbl_805D4488[1] = {0};
const char *lbl_805D448C[1] = {0};
const char *lbl_805D4490[1] = {0};
const char *lbl_805D4494[1] = {0};
const char *lbl_805D4498[1] = {0};
const char *lbl_805D449C[1] = {0};
extern const char *lbl_804F2B78[2];
extern BmlResourceDescriptor lbl_804F2B80;
extern const char *lbl_804F2B90[2];
extern BmlResourceDescriptor lbl_804F2B98;
extern const char *lbl_804F2BA8[2];
extern BmlResourceDescriptor lbl_804F2BB0;
extern const char *lbl_804F2BC0[2];
extern BmlResourceDescriptor lbl_804F2BC8;
extern const char *lbl_804F2BD8[2];
extern BmlResourceDescriptor lbl_804F2BE0;
extern const char *lbl_804F2BF0[2];
extern BmlResourceDescriptor lbl_804F2BF8;
__declspec(section ".data") const char *lbl_804F2B78[2] = {
    "labocity_computer_army.gj", NULL,
};
BmlResourceDescriptor lbl_804F2B80 = {
    "bm_obj_comp_army.bml", lbl_804F2B78, lbl_805D4488, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2B90[2] = {
    "labocity_computer_norm.gj", NULL,
};
BmlResourceDescriptor lbl_804F2B98 = {
    "bm_obj_comp_norm.bml", lbl_804F2B90, lbl_805D448C, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BA8[2] = {
    "labocity_desk.gj", NULL,
};
BmlResourceDescriptor lbl_804F2BB0 = {
    "bm_obj_desk.bml", lbl_804F2BA8, lbl_805D4490, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BC0[2] = {
    "labocity_partition_army.gj", NULL,
};
BmlResourceDescriptor lbl_804F2BC8 = {
    "bm_obj_partition_army.bml", lbl_804F2BC0, lbl_805D4494, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BD8[2] = {
    "labocity_partition_norm.gj", NULL,
};
BmlResourceDescriptor lbl_804F2BE0 = {
    "bm_obj_partition_norm.bml", lbl_804F2BD8, lbl_805D4498, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BF0[2] = {
    "labocity_table.gj", NULL,
};
BmlResourceDescriptor lbl_804F2BF8 = {
    "bm_obj_table_labo.bml", lbl_804F2BF0, lbl_805D449C, 1, 0,
};
// Archive descriptors of the six laboratory design objects, by object id.
struct LaboDesignObjectEntry {
    s32 id;
    BmlResourceDescriptor *descriptor;
};

LaboDesignObjectEntry lbl_804F2C08[7] = {
    {0, &lbl_804F2B80},
    {1, &lbl_804F2B98},
    {2, &lbl_804F2BB0},
    {3, &lbl_804F2BC8},
    {4, &lbl_804F2BE0},
    {5, &lbl_804F2BF8},
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

}

void *TObjLaboDesignBase::create_state5(void *set_data) {
    return new TObjLaboDesignBase((TObject *)tl_05, set_data, 5);
}
CollisionBody *get_labo_design_entry(int a0);
extern BmlResource *labo_design_object_table[6];

BmlResource *get_labo_design_object(int a0);
const char *TObjLaboDesignBase_class_name = "TObjLaboDesignBase";
void *TObjLaboDesignBase::create_state4(void *set_data) {
    return new TObjLaboDesignBase((TObject *)tl_05, set_data, 4);
}

void *TObjLaboDesignBase::create_state3(void *set_data) {
    return new TObjLaboDesignBase((TObject *)tl_05, set_data, 3);
}

void *TObjLaboDesignBase::create_state2(void *set_data) {
    return new TObjLaboDesignBase((TObject *)tl_05, set_data, 2);
}

void *TObjLaboDesignBase::create_state1(void *set_data) {
    return new TObjLaboDesignBase((TObject *)tl_05, set_data, 1);
}

void *TObjLaboDesignBase::create(void *set_data) {
    return new TObjLaboDesignBase((TObject *)tl_05, set_data, 0);
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
    TObjFish::set_global_param(get_bml_texlist((BmlResource *)model_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_node_tree((NJS_OBJECT *)get_bml_model((BmlResource *)model_resource, 0));
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

typedef void (TObjLaboDesignBase::*Action_80365040)();

void TObjLaboDesignBase::render() {
    static Action_80365040 tbl[8] = {
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
        &TObjLaboDesignBase::render_model,
    };
    if (update_object_view_visibility(xB4, xB8) == 1) {
        (this->*(tbl[state]))();
    }
}

void TObjLaboDesignBase::run_task() {}

TObjLaboDesignBase::~TObjLaboDesignBase() {
    if (map_csn != NULL) {
        ((TObject *)map_csn)->queue_destruction();
        map_csn = 0;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TObjLaboDesignBase::TObjLaboDesignBase(TObject *parent, void *set_data, s32 state) : TObjCollidable(parent) {
    union {
        u8 bytes[0x3C];
        struct {
            u8 pad[0x24];
            f32 x;
            f32 y;
            f32 z;
        } extents;
    } copy_storage;
    s32 temp_r0;
    m_name = TObjLaboDesignBase_class_name;
    apply_object_set_data(set_data);
    this->state = state;
    model_resource = get_labo_design_object(this->state);
    init_collision_body_parts(this, get_labo_design_entry(this->state), 1);
    register_object_by_id();
    xB4 = 400.0f;
    xB8 = 50.0f;
    map_csn = NULL;
    temp_r0 = this->state;
    if ((temp_r0 == 3) || (temp_r0 == 4)) {
        *(ByteBlock_3C *)(copy_storage.bytes) = *(const ByteBlock_3C *)set_data;
        copy_storage.extents.x = 40.0f;
        copy_storage.extents.y = 20.0f;
        copy_storage.extents.z = 10.0f;
        map_csn = TObjMapCsn::create(copy_storage.bytes);
    }
}

CollisionBody *get_labo_design_entry(int a0) { return &labo_design_entry_table[a0]; }


BmlResource *get_labo_design_object(int a0) {  return labo_design_object_table[a0]; }

void free_object_table(void) {
    s32 i;
    for (i = 5; i >= 0; i--) {
        if (labo_design_object_table[i] != 0) {
            delete (BmlResource *)labo_design_object_table[i];
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
    e = lbl_804F2C08;
    if (e != NULL) {
        while (e->id != -1) {
            resource = new BmlResource(5, (BmlResourceDescriptor *)e->descriptor, 0, 0, NULL);
            labo_design_object_table[e->id] = resource;
            e++;
        }
    }
}


BmlResource *labo_design_object_table[6];
