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
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
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
NJS_TEXLIST *TODoorFourLightSeabedU__texture_list;
BmlResource *TODoorLabo__bml_resource;
NJS_TEXLIST *TODoorLabo__green_texture_list;
NJS_TEXLIST *labo_door_red_textures;
BmlResource *TODoorLabo__model_archive;
NJS_TEXLIST *TODoorLaboNormal__green_texture_list;
NJS_TEXLIST *TODoorLaboNormal__red_texture_list;

const char *TODoorFourLightBase__class_name = "TODoorFourLightBase";


TODoorFourLightBase::TODoorFourLightBase(TObject *parent, void *set_data) : TODoorBase(parent) {
    s32 i;
    m_name = TODoorFourLightBase__class_name;
    apply_object_set_data(set_data);
    init_door_switch_binding();
    for (i = 0; i < 8; i++) {
        light_nodes[i] = NULL;
    }
    light_count = 0;
}

TODoorFourLightBase::~TODoorFourLightBase() {

}

extern "C" {
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
        draw_ginja_model_with_motion((void *)model, (void *)motion, (f32)animation_frame);
        pop_matrix();
        break;
    case 2:
        push_matrix();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_lit_textures()));
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_model_with_motion((void *)model, (void *)motion, (f32)animation_end_frame);
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
        draw_ginja_object((void *)model);
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
    saddr temp_r31;
    NJS_OBJECT *node;
    NJS_OBJECT *var_r30;
    var_r30 = (NJS_OBJECT *)arg1;
    do {
        temp_r31 = var_r30->evalflags;
        if (temp_r31 & 0x100000) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_lit_textures()));
        } else {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(get_unlit_textures()));
        }
        if (var_r30->evalflags & 0x200000) {
            TParticleCtrl::begin_effect_render();
        } else {
            TParticleCtrl::end_effect_render();
        }
        push_matrix();
        if (!(temp_r31 & 1)) {
            post_translate_matrix(var_r30->pos);
        }
        if (!(temp_r31 & 2)) {
            rotate_matrix_by_node_angles(var_r30->ang, temp_r31 & 0x20);
        }
        if (!(temp_r31 & 4)) {
            scale_current_matrix(var_r30->scl);
        }
        if (!(temp_r31 & 8)) {
            draw_ginja_model(var_r30->model);
        }
        if (!(temp_r31 & 0x10)) {
            node = var_r30->child;
            if (node != NULL) {
                draw_node_tree((u8 *)node);
            }
        }
        pop_matrix();
        var_r30 = var_r30->sibling;
    } while (var_r30 != NULL);
}

void TODoorFourLightBase::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    switch (this->lock_mode) {
    case 1:
        ((TODoorBase *)arg0)->play_door_sound();
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
            ((TODoorBase *)arg0)->play_door_sound();
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
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags |= 1;
        }
        if (found == 0 && this->set_entry != NULL && ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) == 1) {
            sp8 = 1;
            ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
            ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        }
        break;
    }
    default:
        this->door_flags &= ~1;
        break;
    }
}

void TODoorFourLightBase::vfunc_6(s16 *arg1, s32) {
    if ((s16) *arg1 == 1) {
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
    saddr var_r0;
    saddr var_r0_2;
    area = get_current_floor_area();
    switch (area) {
    case AREA_SEABED_UPPER:
        var_r0 = (saddr)new BmlResource(5, &bm_o_door_seabed01_resource_descriptor, 0, 0, NULL);
        door_labo_bml_resource = (BmlResource *)var_r0;
        seabed_door_lit_textures = LoadPvmFileTls("fs_obj_doorx4_atui_green.GVM");
        seabed_door_unlit_textures = LoadPvmFileTls("fs_obj_doorx4_atui.GVM");
        return;
    case AREA_SEABED_LOWER:
        var_r0_2 = (saddr)new BmlResource(5, &bm_o_door_seabed01_resource_descriptor, 0, 0, NULL);
        door_labo_bml_resource = (BmlResource *)var_r0_2;
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
        delete (BmlResource *)door_labo_bml_resource;
        door_labo_bml_resource = NULL;
    }
}

}
const char *TODoorFourLightSeabed__class_name = "TODoorFourLightSeabed";
const FourLightNodeTable door_four_light_seabed_index_table = {{2, 4, 9, 11, 3, 5, 10, 12}};

TODoorFourLightSeabed::TODoorFourLightSeabed(TObject *parent, void *set_data) : TODoorFourLightBase(parent, set_data) {
    s32 i;
    m_name = TODoorFourLightSeabed__class_name;
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
    saddr var_r0;
    saddr var_r0_2;
    area = get_current_floor_area();
    switch (area) {
    case AREA_SEABED_UPPER:
        var_r0 = (saddr)new BmlResource(5, &bm_o_door_seabed01_u_resource_descriptor, 0, 0, NULL);
        seabed_four_light_door_bml_resource = (BmlResource *)var_r0;
        seabed_four_light_door_textures = LoadPvmFileTls("fs_obj_doorx4_u_green.GVM");
        TODoorFourLightSeabedU__texture_list = LoadPvmFileTls("fs_obj_doorx4_u.GVM");
        return;
    case AREA_SEABED_LOWER:
        var_r0_2 = (saddr)new BmlResource(5, &bm_o_door_seabed01_u_resource_descriptor, 0, 0, NULL);
        seabed_four_light_door_bml_resource = (BmlResource *)var_r0_2;
        seabed_four_light_door_textures = LoadPvmFileTls("fs_obj_doorx4_usui_green_02.GVM");
        TODoorFourLightSeabedU__texture_list = LoadPvmFileTls("fs_obj_doorx4_usui_02.GVM");
        return;
    }
}

void free_seabed_u_four_light_door_resources() {
    if (TODoorFourLightSeabedU__texture_list != NULL) {
        release_texture_list(TODoorFourLightSeabedU__texture_list);
        safe_free(TODoorFourLightSeabedU__texture_list);
        TODoorFourLightSeabedU__texture_list = NULL;
    }
    if (seabed_four_light_door_textures != NULL) {
        release_texture_list(seabed_four_light_door_textures);
        safe_free(seabed_four_light_door_textures);
        seabed_four_light_door_textures = NULL;
    }
    if (seabed_four_light_door_bml_resource != NULL) {
        delete (BmlResource *)seabed_four_light_door_bml_resource;
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
    return (saddr)TODoorFourLightSeabedU__texture_list;
}

s32 TODoorFourLightSeabedU::get_lit_textures() {
    return (saddr)seabed_four_light_door_textures;
}

void load_labo_door_resources(void) {
    saddr r = (saddr)new BmlResource(5, &labo_door_resource_descriptor, 0, 0, NULL);
    TODoorLabo__bml_resource = (BmlResource *)r;
    TODoorLabo__green_texture_list = LoadPvmFileTls("obj_o_labodoor_l_grn.GVM");
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
    if (TODoorLabo__green_texture_list != NULL) {
        release_texture_list(TODoorLabo__green_texture_list);
        safe_free(TODoorLabo__green_texture_list);
        TODoorLabo__green_texture_list = NULL;
    }
    if (TODoorLabo__bml_resource != NULL) {
        delete (BmlResource *)TODoorLabo__bml_resource;
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
    return (saddr)TODoorLabo__green_texture_list;
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
    TODoorLabo__model_archive = (BmlResource *)r;
    TODoorLaboNormal__green_texture_list = LoadPvmFileTls("o_labodoor_nrm_green.GVM");
    TODoorLaboNormal__red_texture_list = LoadPvmFileTls("o_labodoor_nrm_red.GVM");
}

void TODoorLabo::free_resources() {
    if (TODoorLaboNormal__red_texture_list != NULL) {
        release_texture_list(TODoorLaboNormal__red_texture_list);
        safe_free(TODoorLaboNormal__red_texture_list);
        TODoorLaboNormal__red_texture_list = NULL;
    }
    if (TODoorLaboNormal__green_texture_list != NULL) {
        release_texture_list(TODoorLaboNormal__green_texture_list);
        safe_free(TODoorLaboNormal__green_texture_list);
        TODoorLaboNormal__green_texture_list = NULL;
    }
    if (TODoorLabo__model_archive != NULL) {
        delete (BmlResource *)TODoorLabo__model_archive;
        TODoorLabo__model_archive = NULL;
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
    motion = (AnimationMotion *)get_bml_motion(TODoorLabo__model_archive, 0);
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
    return (saddr)TODoorLaboNormal__red_texture_list;
}

s32 TODoorLaboNormal::get_lit_textures() {
    return (saddr)TODoorLaboNormal__green_texture_list;
}

void TODoorLaboNormal::init_field_d4() { model = get_bml_model(TODoorLabo__model_archive, 0); }

