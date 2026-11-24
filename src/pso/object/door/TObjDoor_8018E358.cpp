#include "pso/render/NinjaUtil.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/object/door/TObjDoor.h"
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/model_render_state.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/ui/hud/TRaderMapCore.h"

struct BmlResource;
struct NJS_TEXLIST;
struct AnimationMotion;

struct Node_8018E358 { s32 pad0; void *model; };
// The five door models load_resources takes from the door BML (models 4, 3, 0, 1, 2).
struct DoorModelSet { NJS_OBJECT *f0; NJS_OBJECT *f4; Node_8018E358 *c; Node_8018E358 *a; Node_8018E358 *b; };
struct DoorMotionHeader { void* rows; u32 frameCount; };

s32 check_player_door_proximity(saddr arg0, s32 arg1, f32 farg0);

const char *fe_obj_doa_kanban_model_names[6] = {
    "fe_obj_doa_kanban.gj", "fs_obj_doa_shingo_omote.gj", "fs_obj_doa_shingo_ura.gj", "taiki_fe_obj_doa_laz_oya.gj",
    "taiki_fe_obj_doa_oya.gj", NULL,
};
const char *fe_obj_doa_kanban_motion_names[3] = {"fe_obj_doa_oya.njm", "taiki_fe_obj_doa_laz_oya.njm", NULL};
BmlResourceDescriptor door_resource_descriptor = {
    "fe_obj_doa_kanban.bml", fe_obj_doa_kanban_model_names, fe_obj_doa_kanban_motion_names, 5, 2,
};
CollisionBody TObjDoor::collision_desc = {{0.0f, 0.0f, 0.0f}, 10.0f, 40.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
/* label colour (a, r, g, b) per door id */
NJS_ARGB TObjDoor::label_color_table[10] = {
    { 1.0f, 0.8235294f, 0.09803922f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.8235294f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.8235294f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.5019608f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.5019608f, 0.8235294f },
    { 1.0f, 0.7058824f, 0.9019608f, 0.09803922f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.39215687f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
};
const char *TObjDoor::name = "TObjDoor";

DoorMotionHeader *TObjDoor::motion_table[2];
DoorModelSet TObjDoor::model_resource_ptrs;

NJS_TEXLIST *TObjDoor::resource_param;
BmlResource *door_resource_handle;
s32 TObjDoor__data_805D5BC8;

#pragma push
#pragma fp_contract on
void *TObjDoorJung::create(void *set_data) {
    return new TObjDoorJung(tl_05, set_data);
}

void TObjDoor::load_resources() {
    BmlResource *p = new BmlResource(5, &door_resource_descriptor, 0, 0, NULL);
    door_resource_handle = p;
    resource_param = load_gvm_texture_file("fe_obj_door.gvm");
    model_resource_ptrs.f0 = get_bml_model((BmlResource *)door_resource_handle, 4);
    model_resource_ptrs.f4 = get_bml_model((BmlResource *)door_resource_handle, 3);
    model_resource_ptrs.c = (Node_8018E358 *)get_bml_model((BmlResource *)door_resource_handle, 0);
    model_resource_ptrs.a = (Node_8018E358 *)get_bml_model((BmlResource *)door_resource_handle, 1);
    model_resource_ptrs.b = (Node_8018E358 *)get_bml_model((BmlResource *)door_resource_handle, 2);
    motion_table[0] = (DoorMotionHeader *)get_bml_motion(door_resource_handle, 0);
    motion_table[1] = (DoorMotionHeader *)get_bml_motion(door_resource_handle, 1);
}

void TObjDoor::free_resources() {
    TObjPlayer::free_if_valid((saddr)resource_param);
    resource_param = NULL;
    if (door_resource_handle != NULL) {
        delete (BmlResource *)door_resource_handle;
        door_resource_handle = NULL;
    }
}

void *TObjDoor::create(void *set_data) {
    return new TObjDoor(tl_05, set_data);
}

TObjDoor::TObjDoor(TObject *parent, void *set_data) : TObjCollidable(parent) {
    this->m_name = name;
    apply_object_set_data(set_data);
    this->state = 0;
    this->accentFrame = 0.0f;
    this->frame = 0.0f;
    this->behavior = 1;
    this->cameraMode = this->set_params[2] % 2;
    this->cameraTicks = 80;
    this->glow = 0.0f;
    this->phase = 0;
    this->switchId = (u8)this->set_params[0];
    this->label = (u8)((u32)this->set_params[0] >> 8) % 10;
    if (this->cameraMode < 0) {
        this->cameraMode = 0;
    }
    if (this->cameraMode > 1) {
        this->cameraMode = 1;
    }
    init_collision_body_parts(this, &collision_desc, 1);
    this->actorFlags |= 0x40000000;
    register_object_by_id();
}

TObjDoor::~TObjDoor() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjDoor::run_task() {
    static void (TObjDoor::*update_fns[6])() = {
        &TObjDoor::update_locked_pulse, &TObjDoor::update_anim, &TObjDoor::draw_closed_glow,
        &TObjDoor::update_closing, &TObjDoor::update_opening_glow, &TObjDoor::update_open,
    };
    s32 saved = this->state;
    if (TObjDoor__data_805D5BC8 != 0) {
        this->state = 0;
        set_indexed_flags(0, 1);
    } else {
        update_state();
    }
    (this->*update_fns[this->state])();
    if (this->state == 0) {
        minimap_render_gate(&this->position, 0xFFFF0000, this->rotation_y, 0, 0);
    } else {
        minimap_render_gate(&this->position, 0xFF00FF00, this->rotation_y, 0, 0);
    }
    if (TObjDoor__data_805D5BC8 != 0) {
        this->state = saved;
    }
}

void TObjDoor::update_state() {
    Vec target,position;
    switch(this->state) {
    case 0:
        if(is_current_floor_switch_set((u16)this->switchId)==1) {
            if(TObjDoor__data_805D5BC8==0)this->accentFrame=(0.0f);
            if(this->cameraMode==0)this->state=2;
            else this->state=1;
        }
        set_indexed_flags(0, 1);return;
    case 1:
        if(this->cameraMode==1 && activate_camera_mode(9)!=0) {
            VecCopy(&target, &this->position);
            VecCopy(&position, (const Vec *)((f32 *)&this->scale));
            set_active_camera_pose(&position, &target);this->cameraMode=2;
        }
        if(this->cameraMode==2) {
            s32 ticks=this->cameraTicks-1;this->cameraTicks=ticks;
            if(ticks==0) {restore_player_cameras();this->state=2;return;}
        }
        if(this->cameraTicks>60) {
            this->accentFrame+=(2.0f);
            if(this->accentFrame>(motion_table[1]->frameCount-1))this->accentFrame=(0.0f);
        }
        return;
    case 2:
        set_indexed_flags(0, 1);
        if(check_player_door_proximity((saddr)this, 0, (7e+01f))!=0) {
            this->frame=(0.0f);this->state=4;clear_player_status_flag(0, 1);
        }
        break;
    case 4:
        play_persistent_sound(0x49e08, this, &this->position, 0, 0);
        this->frame+=(1.8f);
        if(this->frame>(motion_table[0]->frameCount-1)) {
            this->frame=(motion_table[0]->frameCount-1);this->state=5;
        }
        break;
    case 3:
        play_persistent_sound(0x49e08, this, &this->position, 0, 0);
        this->frame-=1.8f;
        if(this->frame<0.0f) {this->frame=0.0f;this->state=2;}
        break;
    case 5:
        clear_player_status_flag(0, 1);
        if(check_player_door_proximity((saddr)this, 1, 100.0f)!=0) {this->state=3;set_indexed_flags(0, 1);}
        break;
    }
}

void TObjDoor::render() {
    static void (TObjDoor::*draw_fns[6])() = {
        &TObjDoor::draw_locked, &TObjDoor::update_timer, &TObjDoor::draw_closed,
        &TObjDoor::draw_closing, &TObjDoor::draw_opening, &TObjDoor::draw_model,
    };
    s32 saved = this->state;
    if (TObjDoor__data_805D5BC8 != 0) {
        this->state = 0;
    }
    if (this->state == 0 || this->state == 2) {
        if (is_visible(700.0f, 250.0f) != 0) {
            (this->*draw_fns[this->state])();
        }
    } else if (update_object_view_visibility(700.0f, 250.0f) != 0) {
        (this->*draw_fns[this->state])();
    }
    if (TObjDoor__data_805D5BC8 != 0) {
        this->state = saved;
    }
}

s32 TObjDoor::is_visible(f32 far_dist, f32 near_dist) {
    f32 screen_x;
    f32 dist = xyz_distance_squared(&this->position, &camera_ctrl_instance->pos);
    if (dist > far_dist * far_dist) {
        return 0;
    }
    if (dist < near_dist * near_dist) {
        return 1;
    }
    project_world_to_screen(NULL, &this->position, &screen_x);
    if (-near_dist <= screen_x && screen_x <= 640.0f + near_dist) {
        return 1;
    }
    return 0;
}

void TObjDoor::update_locked_pulse() {
    this->accentFrame += 2.0f;
    if (this->accentFrame > motion_table[1]->frameCount - 1) this->accentFrame = 0.0f;
    this->phase += 0x300;
    this->glow = 0.2f * sin_table_lookup(this->phase) + 0.4f;
}

void TObjDoor::update_anim() {
    this->phase += 0x300;
    this->glow = 0.2f * sin_table_lookup(this->phase) + 0.4f;
}

#pragma pop

void TObjDoor::draw_closed_glow() {
    this->frame += 1.5f;
    if (this->frame > motion_table[0]->frameCount - 1) this->frame = 0.0f;
    this->glow += 0.05f;
    if (this->glow > 0.5f) this->glow = 0.5f;
}

void TObjDoor::update_closing() {}

#pragma push
#pragma opt_common_subs off
void TObjDoor::update_opening_glow() {
    this->glow -= 0.05f;
    if (this->glow < 0.0f) {
        this->glow = 0.0f;
    }
}
#pragma pop

void TObjDoor::update_open() {}

void TObjDoor::draw_locked() {
    TObjFish::set_global_param(resource_param);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_object(model_resource_ptrs.f0);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion(model_resource_ptrs.f4, motion_table[1], this->accentFrame);
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    NJS_ARGB color = label_color_table[this->label];
    color.a = this->glow;
    set_constant_material(&color);
    DoorModelSet *g0 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g0->c->model)), ((u16)this->label));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    DoorModelSet *g1 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->model)), 0xB);
    DoorModelSet *g2 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->model)), 0xB);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoor::update_timer() {
    if (this->cameraTicks < 60) {
        draw_closed();
        return;
    }
    draw_locked();
}

void TObjDoor::draw_closed() {
    TObjFish::set_global_param(resource_param);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_object(model_resource_ptrs.f0);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    NJS_ARGB color = label_color_table[this->label];
    color.a = this->glow;
    set_constant_material(&color);
    DoorModelSet *g0 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g0->c->model)), ((u16)this->label));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    DoorModelSet *g1 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->model)), 0xA);
    DoorModelSet *g2 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->model)), 0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoor::draw_closing() {
    TObjFish::set_global_param(resource_param);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_model_with_motion(model_resource_ptrs.f0, motion_table[0], this->frame);
    TParticleCtrl::begin_effect_render();
    DoorModelSet *g1 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->model)), 0xA);
    DoorModelSet *g2 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->model)), 0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoor::draw_opening() {
    TObjFish::set_global_param(resource_param);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_model_with_motion(model_resource_ptrs.f0, motion_table[0], this->frame);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    NJS_ARGB color = label_color_table[this->label];
    color.a = this->glow;
    set_constant_material(&color);
    DoorModelSet *g0 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g0->c->model)), ((u16)this->label));
    draw_ginja_object(g0->c);
    model_render_flags = saved_model_render_flags;
    DoorModelSet *g1 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->model)), 0xA);
    DoorModelSet *g2 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->model)), 0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoor::draw_model() {
    TObjFish::set_global_param(resource_param);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_model_with_motion(model_resource_ptrs.f0, motion_table[0], this->frame);
    TParticleCtrl::begin_effect_render();
    DoorModelSet *g1 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g1->a->model)), 0xA);
    DoorModelSet *g2 = &model_resource_ptrs;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((g2->b->model)), 0xA);
    draw_ginja_object(g1->a);
    draw_ginja_object(g2->b);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

