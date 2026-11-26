#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/network/TLobby.h"
#include "pso/object/door/TODoorFourLightBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/door/TODoorLabo.h"
#include "pso/object/door/TODoorLaboNormal.h"
#include "pso/object/door/TODoorFourLightSeabedU.h"
#include "pso/object/door/TODoorFourLightSeabed.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/door/TODoorAncient01.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/GinjaTexture.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/MatrixStack.h"

struct BmlResource;
struct NJS_TEXLIST;

#pragma defer_codegen on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
__declspec(section ".data") const char *bm_o_door_seabed01_model_names[2] = { "fs_obj_doorx4_atui.gj", NULL };
__declspec(section ".data") const char *bm_o_door_seabed01_motion_names[2] = { "fs_obj_doorx4_atui.njm", NULL };
BmlResourceDescriptor bm_o_door_seabed01_resource_descriptor = { "bm_o_door_seabed01.bml", bm_o_door_seabed01_model_names, bm_o_door_seabed01_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_o_door_seabed01_u_model_names[2] = { "fs_obj_doorx4_u.gj", NULL };
__declspec(section ".data") const char *bm_o_door_seabed01_u_motion_names[2] = { "fs_obj_doorx4_u.njm", NULL };
BmlResourceDescriptor bm_o_door_seabed01_u_resource_descriptor = { "bm_o_door_seabed01_u.bml", bm_o_door_seabed01_u_model_names, bm_o_door_seabed01_u_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_obj_door_labo_model_names[3] = { "obj_o_labodoor_l.gj", "obj_o_labodoor_l2.gj", NULL };
__declspec(section ".data") const char *bm_obj_door_labo_motion_names[2] = { "obj_o_labodoor_l.njm", NULL };
BmlResourceDescriptor labo_door_resource_descriptor = { "bm_obj_door_labo.bml", bm_obj_door_labo_model_names, bm_obj_door_labo_motion_names, 2, 1 };
__declspec(section ".data") const char *bm_obj_labodoor_nrm_model_names[2] = { "obj_m_cdoor_l.gj", NULL };
__declspec(section ".data") const char *bm_obj_labodoor_nrm_motion_names[2] = { "obj_m_cdoor_l.njm", NULL };
BmlResourceDescriptor labo_door_resource_descriptor_2 = { "bm_obj_labodoor_nrm.bml", bm_obj_labodoor_nrm_model_names, bm_obj_labodoor_nrm_motion_names, 1, 1 };
}
CollisionBody labo_door_collision_body_parts[] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
// The BML archives and texture lists the door classes load and free (TODoorFourLightSeabed,
// TODoorFourLightSeabedU, TODoorLabo, TODoorLaboNormal), in address order.
BmlResource *door_labo_bml_resource;
NJS_TEXLIST *seabed_door_lit_textures;
NJS_TEXLIST *seabed_door_unlit_textures;
BmlResource *seabed_four_light_door_bml_resource;
NJS_TEXLIST *seabed_four_light_door_textures;
NJS_TEXLIST *door_four_light_seabed_u_texture_list;
BmlResource *TODoorLabo__bml_resource;
NJS_TEXLIST *door_labo_green_texture_list;
NJS_TEXLIST *labo_door_red_textures;
BmlResource *door_labo_model_archive;
NJS_TEXLIST *door_labo_normal_green_texture_list;
NJS_TEXLIST *door_labo_normal_red_texture_list;

const char *door_four_light_base_class_name = "TODoorFourLightBase";


TODoorFourLightBase::TODoorFourLightBase(TObject *parent, void *set_data) : TODoorBase(parent) {
    s32 i;
    m_name = door_four_light_base_class_name;
    apply_object_set_data(set_data);
    init_door_switch_binding();
    for (i = 0; i < 8; i++) {
        light_nodes[i] = NULL;
    }
    light_count = 0;
}

TODoorFourLightBase::~TODoorFourLightBase() {

}

void TODoorFourLightBase::render() {
    if (update_object_view_visibility(view_range, model_radius) != 1) {
        return;
    }
    switch (object_state) {
    case 1:
    case 3:
        push_matrix();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_lit_textures()));
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion(model, motion, (f32)animation_frame);
        pop_matrix();
        break;
    case 2:
        push_matrix();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_lit_textures()));
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion(model, motion, (f32)animation_end_frame);
        pop_matrix();
        break;
    case 0:
        if (lock_mode == 2 || lock_mode == 3) {
            render_lights();
            break;
        }
        push_matrix();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_lit_textures()));
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_object(model);
        pop_matrix();
        break;
    }
}

void TODoorFourLightBase::render_lights() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (light_nodes[i] != NULL) {
            light_nodes[i]->evalflags |= 0x100000;
            light_nodes[i]->evalflags |= 0x200000;
        }
        if (light_nodes[4 + i] != NULL) {
            light_nodes[4 + i]->evalflags |= 0x100000;
            light_nodes[i]->evalflags |= 0x200000;
        }
    }
    if (!(door_flags & 1)) {
        for (i = 0; i < light_count; i++) {
            if (is_current_floor_switch_set((u16)(switch_id + i)) == 1) {
                if (light_nodes[i] != NULL) {
                    light_nodes[i]->evalflags |= 0x100000;
                }
                if (light_nodes[4 + i] != NULL) {
                    light_nodes[4 + i]->evalflags |= 0x100000;
                }
            } else {
                if (light_nodes[i] != NULL) {
                    light_nodes[i]->evalflags &= ~0x100000;
                }
                if (light_nodes[4 + i] != NULL) {
                    light_nodes[4 + i]->evalflags &= ~0x100000;
                }
            }
        }
    }
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_node_tree((u8 *)model);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TODoorFourLightBase::draw_node_tree(u8 *arg1) {
    saddr eval_flags;
    NJS_OBJECT *node;
    NJS_OBJECT *cur;
    cur = (NJS_OBJECT *)arg1;
    do {
        eval_flags = cur->evalflags;
        if (eval_flags & 0x100000) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_lit_textures()));
        } else {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_unlit_textures()));
        }
        if (cur->evalflags & 0x200000) {
            TParticleCtrl::begin_effect_render();
        } else {
            TParticleCtrl::end_effect_render();
        }
        push_matrix();
        if (!(eval_flags & 1)) {
            post_translate_matrix(cur->pos);
        }
        if (!(eval_flags & 2)) {
            rotate_matrix_by_node_angles(cur->ang, eval_flags & 0x20);
        }
        if (!(eval_flags & 4)) {
            scale_current_matrix(cur->scl);
        }
        if (!(eval_flags & 8)) {
            draw_ginja_model(cur->model);
        }
        if (!(eval_flags & 0x10)) {
            node = cur->child;
            if (node != NULL) {
                draw_node_tree((u8 *)node);
            }
        }
        pop_matrix();
        cur = cur->sibling;
    } while (cur != NULL);
}

void TODoorFourLightBase::update_door_switch_state() {
    s16 sp8;
    switch (this->lock_mode) {
    case 1:
        this->play_door_sound();
        this->door_flags |= 1;
        break;
    case 2: {
        s32 found = 0;
        s32 i;
        for (i = 0; i < light_count; i++) {
            if (((u8 (*)(u16))is_current_floor_switch_set)(this->switch_id + i) == 0) {
                found = 1;
            }
        }
        if (found != 0) {
            this->door_flags &= ~1;
        } else {
            this->play_door_sound();
            this->door_flags |= 1;
        }
        break;
    }
    case 3: {
        s32 found;
        s32 i;
        if (this->door_flags & 1) {
            break;
        }
        found = 0;
        for (i = 0; i < light_count; i++) {
            if (((u8 (*)(u16))is_current_floor_switch_set)(this->switch_id + i) == 0) {
                found = 1;
            }
        }
        if (found != 0) {
            this->door_flags &= ~1;
        } else {
            this->play_door_sound();
            this->door_flags |= 1;
        }
        if (found == 0 && this->set_entry != NULL && this->access_object_saved_state(&sp8, 1) == 1) {
            sp8 = 1;
            this->send_object_state_update(&sp8);
            this->access_object_saved_state(&sp8, 0);
        }
        break;
    }
    default:
        this->door_flags &= ~1;
        break;
    }
}

void TODoorFourLightBase::apply_saved_state(s16 *state, s32) {
    if ((s16) *state == 1) {
        this->door_flags = (s32) (this->door_flags | 1);
    }
}

s32 TODoorFourLightBase::init_door_switch_binding() {
    s32 switch_id;

    this->switch_id = (s32) this->set_params[0];
    switch_id = this->switch_id;
    if (switch_id > 0x100) {
        this->lock_mode = 0;
    } else if (switch_id < 0) {
        this->lock_mode = 1;
    } else if ((s32) this->set_params[2] < 0) {
        if ((get_main_phase() == 0xF) || (TRaderMapCore::is_not_split_screen() == 1)) {
            this->lock_mode = 3;
        } else {
            this->lock_mode = 2;
        }
    } else {
        this->lock_mode = 2;
    }
    return this->switch_id;
}

void TODoorFourLightBase::clamp_light_index() {
    if ((s32) this->set_params[1] < 0) {
        this->set_params[1] = 0;
    }
    if ((s32) this->set_params[1] > 4) {
        this->set_params[1] = 4;
    }
    light_count = this->set_params[1];
}

void load_seabed_four_light_door_resources(void) {
    s32 area;
    saddr resource_a;
    saddr resource_b;
    area = get_current_floor_area();
    switch (area) {
    case AREA_SEABED_UPPER:
        resource_a = (saddr)new BmlResource(5, &bm_o_door_seabed01_resource_descriptor, 0, 0, NULL);
        door_labo_bml_resource = (BmlResource *)resource_a;
        seabed_door_lit_textures = LoadPvmFileTls("fs_obj_doorx4_atui_green.GVM");
        seabed_door_unlit_textures = LoadPvmFileTls("fs_obj_doorx4_atui.GVM");
        return;
    case AREA_SEABED_LOWER:
        resource_b = (saddr)new BmlResource(5, &bm_o_door_seabed01_resource_descriptor, 0, 0, NULL);
        door_labo_bml_resource = (BmlResource *)resource_b;
        seabed_door_lit_textures = LoadPvmFileTls("fs_obj_doorx4_atui_green_02.GVM");
        seabed_door_unlit_textures = LoadPvmFileTls("fs_obj_doorx4_atui_02.GVM");
        return;
    }
}

void free_seabed_four_light_door_resources() {
    if (seabed_door_unlit_textures != NULL) {
        release_texture_list(seabed_door_unlit_textures);
        safe_free(seabed_door_unlit_textures);
        seabed_door_unlit_textures = NULL;
    }
    if (seabed_door_lit_textures != NULL) {
        release_texture_list(seabed_door_lit_textures);
        safe_free(seabed_door_lit_textures);
        seabed_door_lit_textures = NULL;
    }
    if (door_labo_bml_resource != NULL) {
        delete door_labo_bml_resource;
        door_labo_bml_resource = NULL;
    }
}
const char *door_four_light_seabed_class_name = "TODoorFourLightSeabed";
const FourLightNodeTable door_four_light_seabed_index_table = {{2, 4, 9, 11, 3, 5, 10, 12}};

TODoorFourLightSeabed::TODoorFourLightSeabed(TObject *parent, void *set_data) : TODoorFourLightBase(parent, set_data) {
    s32 i;
    m_name = door_four_light_seabed_class_name;
    init_collision_body_parts(this, labo_door_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    model = get_bml_model(door_labo_bml_resource, 0);
    motion = (AnimationMotion *)get_bml_motion(door_labo_bml_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 0.5f;
    {
        FourLightNodeTable tbl = door_four_light_seabed_index_table;
        for (i = 0; i < 8; i++) {
            light_nodes[i] = find_object_node(model, tbl.node[i]);
        }
    }
    clamp_light_index();
}


TODoorFourLightSeabed::~TODoorFourLightSeabed() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorFourLightSeabed::get_unlit_textures() {
    return (saddr)seabed_door_unlit_textures;
}

s32 TODoorFourLightSeabed::get_lit_textures() {
    return (saddr)seabed_door_lit_textures;
}

void load_seabed_u_four_light_door_resources(void) {
    s32 area;
    saddr resource_a;
    saddr resource_b;
    area = get_current_floor_area();
    switch (area) {
    case AREA_SEABED_UPPER:
        resource_a = (saddr)new BmlResource(5, &bm_o_door_seabed01_u_resource_descriptor, 0, 0, NULL);
        seabed_four_light_door_bml_resource = (BmlResource *)resource_a;
        seabed_four_light_door_textures = LoadPvmFileTls("fs_obj_doorx4_u_green.GVM");
        door_four_light_seabed_u_texture_list = LoadPvmFileTls("fs_obj_doorx4_u.GVM");
        return;
    case AREA_SEABED_LOWER:
        resource_b = (saddr)new BmlResource(5, &bm_o_door_seabed01_u_resource_descriptor, 0, 0, NULL);
        seabed_four_light_door_bml_resource = (BmlResource *)resource_b;
        seabed_four_light_door_textures = LoadPvmFileTls("fs_obj_doorx4_usui_green_02.GVM");
        door_four_light_seabed_u_texture_list = LoadPvmFileTls("fs_obj_doorx4_usui_02.GVM");
        return;
    }
}

void free_seabed_u_four_light_door_resources() {
    if (door_four_light_seabed_u_texture_list != NULL) {
        release_texture_list(door_four_light_seabed_u_texture_list);
        safe_free(door_four_light_seabed_u_texture_list);
        door_four_light_seabed_u_texture_list = NULL;
    }
    if (seabed_four_light_door_textures != NULL) {
        release_texture_list(seabed_four_light_door_textures);
        safe_free(seabed_four_light_door_textures);
        seabed_four_light_door_textures = NULL;
    }
    if (seabed_four_light_door_bml_resource != NULL) {
        delete seabed_four_light_door_bml_resource;
        seabed_four_light_door_bml_resource = NULL;
    }
}

const char *odoor_four_light_seabed_u_class_name = "TODoorFourLightSeabedU";
const FourLightNodeTable door_four_light_seabed_u_table = {{2, 4, 7, 9, 3, 5, 8, 10}};

TODoorFourLightSeabedU::TODoorFourLightSeabedU(TObject *parent, void *set_data) : TODoorFourLightBase(parent, set_data) {
    s32 i;
    m_name = odoor_four_light_seabed_u_class_name;
    init_collision_body_parts(this, labo_door_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    model = get_bml_model(seabed_four_light_door_bml_resource, 0);
    motion = (AnimationMotion *)get_bml_motion(seabed_four_light_door_bml_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 0.5f;
    {
        FourLightNodeTable tbl = door_four_light_seabed_u_table;
        for (i = 0; i < 8; i++) {
            light_nodes[i] = find_object_node(model, tbl.node[i]);
        }
    }
    clamp_light_index();
}


TODoorFourLightSeabedU::~TODoorFourLightSeabedU() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorFourLightSeabedU::get_unlit_textures() {
    return (saddr)door_four_light_seabed_u_texture_list;
}

s32 TODoorFourLightSeabedU::get_lit_textures() {
    return (saddr)seabed_four_light_door_textures;
}

void load_labo_door_resources(void) {
    saddr r = (saddr)new BmlResource(5, &labo_door_resource_descriptor, 0, 0, NULL);
    TODoorLabo__bml_resource = (BmlResource *)r;
    door_labo_green_texture_list = LoadPvmFileTls("obj_o_labodoor_l_grn.GVM");
    labo_door_red_textures = LoadPvmFileTls("obj_o_labodoor_l_red.GVM");
}

const char *odoor_labo_class_name = "TODoorLabo";
const FourLightNodeTable door_labo_link_table = {{1, -1, -1, -1, 4, -1, -1, -1}};


void TAdSinglePlyChrSelectGC::free_all_resources() {
    if (labo_door_red_textures != NULL) {
        release_texture_list(labo_door_red_textures);
        safe_free(labo_door_red_textures);
        labo_door_red_textures = NULL;
    }
    if (door_labo_green_texture_list != NULL) {
        release_texture_list(door_labo_green_texture_list);
        safe_free(door_labo_green_texture_list);
        door_labo_green_texture_list = NULL;
    }
    if (TODoorLabo__bml_resource != NULL) {
        delete TODoorLabo__bml_resource;
        TODoorLabo__bml_resource = NULL;
    }
}

TODoorLabo::TODoorLabo(TObject *parent, void *set_data) : TODoorFourLightBase(parent, set_data) {
    FourLightNodeTable tbl;
    s32 i;

    m_name = odoor_labo_class_name;
    init_collision_body_parts(this, labo_door_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_model_by_type();
    motion = (AnimationMotion *)get_bml_motion(TODoorLabo__bml_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 0.5f;
    tbl = door_labo_link_table;
    for (i = 0; i < 8; i++) {
        if (tbl.node[i] != -1) {
            light_nodes[i] = find_object_node(model, tbl.node[i]);
        }
    }
    light_count = 1;
    model_radius = 50.0f;
}

TODoorLabo::~TODoorLabo() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorLabo::get_unlit_textures() {
    return (saddr)labo_door_red_textures;
}

s32 TODoorLabo::get_lit_textures() {
    return (saddr)door_labo_green_texture_list;
}

void TODoorLabo::init_model_by_type() {
    s32 tbl[2] = {0, 1};
    if (this->set_params[1] < 0) {
        this->set_params[1] = 0;
    }
    if (this->set_params[1] > 1) {
        this->set_params[1] = 1;
    }
    model = get_bml_model(TODoorLabo__bml_resource, tbl[this->set_params[1]]);
}

void TODoorLabo::load_resources() {
    saddr r = (saddr)new BmlResource(5, &labo_door_resource_descriptor_2, 0, 0, NULL);
    door_labo_model_archive = (BmlResource *)r;
    door_labo_normal_green_texture_list = LoadPvmFileTls("o_labodoor_nrm_green.GVM");
    door_labo_normal_red_texture_list = LoadPvmFileTls("o_labodoor_nrm_red.GVM");
}

void TODoorLabo::free_resources() {
    if (door_labo_normal_red_texture_list != NULL) {
        release_texture_list(door_labo_normal_red_texture_list);
        safe_free(door_labo_normal_red_texture_list);
        door_labo_normal_red_texture_list = NULL;
    }
    if (door_labo_normal_green_texture_list != NULL) {
        release_texture_list(door_labo_normal_green_texture_list);
        safe_free(door_labo_normal_green_texture_list);
        door_labo_normal_green_texture_list = NULL;
    }
    if (door_labo_model_archive != NULL) {
        delete door_labo_model_archive;
        door_labo_model_archive = NULL;
    }
}

const char *door_labo_normal_class_name = "TODoorLaboNormal";

TODoorLaboNormal::TODoorLaboNormal(TObject *parent, void *set_data) : TODoorFourLightBase(parent, set_data) {
    s32 i;
    m_name = door_labo_normal_class_name;
    init_collision_body_parts(this, labo_door_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_field_d4();
    motion = (AnimationMotion *)get_bml_motion(door_labo_model_archive, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 0.5f;
    {
        FourLightNodeTable t = {{1, -1, -1, -1, 4, -1, -1, -1}};
        for (i = 0; i < 8; i++) {
            if (t.node[i] != -1) {
                light_nodes[i] = NULL;
            }
        }
    }
    light_count = 1;
    model_radius = 50.0f;
}

TODoorLaboNormal::~TODoorLaboNormal() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorLaboNormal::get_unlit_textures() {
    return (saddr)door_labo_normal_red_texture_list;
}

s32 TODoorLaboNormal::get_lit_textures() {
    return (saddr)door_labo_normal_green_texture_list;
}

void TODoorLaboNormal::init_field_d4() { model = get_bml_model(door_labo_model_archive, 0); }

