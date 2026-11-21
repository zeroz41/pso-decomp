#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
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
#include "pso/object/ambient/TObjFish.h"

#pragma readonly_strings on

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_3C { u8 bytes[0x3C]; };

extern "C" {
f32 xz_distance_squared(void *, s32);
extern s32 camera_ctrl_instance;
s32 init_collision_body_parts(void *, int, int);
void *TObjLaboDesignBase__create(void *arg0);
void *TObjLaboDesignBase__sub_80364D38(void *arg0);
void *alloc_and_construct__18TObjLaboDesignBaseFPv(void *arg0);
void *create_instance__18TObjLaboDesignBaseFPv(void *arg0);
void free_collision_body_parts(void *);


s32 rotate_matrix_y(int, int);


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
void *labo_design_entry_table[66] = {
    (void *)0x0, (void *)0x41a00000, (void *)0x0, (void *)0x40a00000,
    (void *)0x41200000, (void *)0x1, (void *)0x10003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0x0, (void *)0x40a00000, (void *)0x41200000,
    (void *)0x1, (void *)0x10003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41a00000,
    (void *)0x0, (void *)0x40a00000, (void *)0x41200000, (void *)0x1,
    (void *)0x10003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41a00000, (void *)0x0,
    (void *)0x40a00000, (void *)0x41a00000, (void *)0x1, (void *)0x10003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41a00000, (void *)0x0, (void *)0x40a00000,
    (void *)0x41a00000, (void *)0x1, (void *)0x10003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0x0, (void *)0x41200000, (void *)0x42200000,
    (void *)0x1, (void *)0x10003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};

void *create_instance__18TObjLaboDesignBaseFPv(void *arg0) {
    return new TObjLaboDesignBase((TObject *)tl_05, arg0, 5);
}
}
void* get_labo_design_entry(int a0);
extern BmlResource *labo_design_object_table[6];

BmlResource *get_labo_design_object(int a0);
const char *TObjLaboDesignBase_class_name = "TObjLaboDesignBase";
void *create_labo_design_base(void *arg0);
void *create_obj_labo_design_base(void *arg0);
void *create_obj_labo_design_base(void *arg0) {
    return new TObjLaboDesignBase((TObject *)tl_05, arg0, 4);
}

void *TObjLaboDesignBase__sub_80364D38(void *arg0) {
    return new TObjLaboDesignBase((TObject *)tl_05, arg0, 3);
}

void *create_labo_design_base(void *arg0) {
    return new TObjLaboDesignBase((TObject *)tl_05, arg0, 2);
}

void *alloc_and_construct__18TObjLaboDesignBaseFPv(void *arg0) {
    return new TObjLaboDesignBase((TObject *)tl_05, arg0, 1);
}

void *TObjLaboDesignBase__create(void *arg0) {
    return new TObjLaboDesignBase((TObject *)tl_05, arg0, 0);
}

s32 TObjLaboDesignBase::update_object_view_visibility(f32 near_dist, f32 far_dist) {
    if (TMainTask::get_render_pass() == 1) {
        return visibility;
    }
    if (xz_distance_squared((u8 *)this + 0x38, camera_ctrl_instance + 0x178) < (far_dist * far_dist)) {
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
    TObjFish::set_global_param((saddr)get_bml_texlist((BmlResource *)model_resource, 0));
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
    struct CopyStack_80365210 { u8 bytes[0x3C]; };
    CopyStack_80365210 copy_storage_80365210;
    s32 temp_r0;
    m_name = TObjLaboDesignBase_class_name;
    apply_object_set_data(set_data);
    this->state = state;
    model_resource = get_labo_design_object(this->state);
    init_collision_body_parts(this, (s32)get_labo_design_entry(this->state), 1);
    register_object_by_id();
    xB4 = 400.0f;
    xB8 = 50.0f;
    map_csn = NULL;
    temp_r0 = this->state;
    if ((temp_r0 == 3) || (temp_r0 == 4)) {
        *(ByteBlock_3C *)(copy_storage_80365210.bytes) = *(const ByteBlock_3C *)set_data;
        (*(f32 *)(copy_storage_80365210.bytes + 0x24)) = 40.0f;
        (*(f32 *)(copy_storage_80365210.bytes + 0x28)) = 20.0f;
        (*(f32 *)(copy_storage_80365210.bytes + 0x2C)) = 10.0f;
        map_csn = TObjMapCsn::create(copy_storage_80365210.bytes);
    }
}

void* get_labo_design_entry(int a0) {  return (char*)labo_design_entry_table + a0 * 44; }

extern BmlResource *labo_design_object_table[6];

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
