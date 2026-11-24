#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "types.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/fence/TObjLazerFenceExtra.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/fence/TObjLazerFenceNorm.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"

struct AnimationMotion;

extern "C" {
__declspec(section ".data") const char *fe_obj_lazer2_4m_model_names[9] = {
    "fe_obj_lazer2_4m.gj", "fe_obj_lazer2_4m_moto.gj", "fe_obj_lazer2_6m.gj", "fe_obj_lazer2_6m_moto.gj",
    "fe_obj_lazer4_4m.gj", "fe_obj_lazer4_4m_moto.gj", "fe_obj_lazer4_6m.gj", "fe_obj_lazer4_6m_moto.gj", NULL,
};
__declspec(section ".data") const char *fe_obj_lazer2_4m_motion_names[5] = {
    "fe_obj_lazer2_4m.njm", "fe_obj_lazer2_6m.njm", "fe_obj_lazer4_4m.njm", "fe_obj_lazer4_6m.njm", NULL,
};
BmlResourceDescriptor lazer_fence_norm_episode1_resource_descriptor = {
    "fe_obj_lazer2_4m.bml", fe_obj_lazer2_4m_model_names, fe_obj_lazer2_4m_motion_names, 8, 4,
};
__declspec(section ".data") const char *fe_obj_lazer2_2_model_names[9] = {
    "fe_obj_lazer2_4m.gj", "fe_obj_lazer2_4m_moto.gj", "fe_obj_lazer2_6m.gj", "fe_obj_lazer2_6m_moto.gj",
    "fe_obj_lazer4_4m.gj", "fe_obj_lazer4_4m_moto.gj", "fe_obj_lazer4_6m.gj", "fe_obj_lazer4_6m_moto.gj", NULL,
};
__declspec(section ".data") const char *fe_obj_lazer2_2_motion_names[5] = {
    "fe_obj_lazer2_4m.njm", "fe_obj_lazer2_6m.njm", "fe_obj_lazer4_4m.njm", "fe_obj_lazer4_6m.njm", NULL,
};
}
BmlResourceDescriptor lazer_fence_norm_episode2_resource_descriptor = {
    "fe_obj_lazer2_2.bml", fe_obj_lazer2_2_model_names, fe_obj_lazer2_2_motion_names, 8, 4,
};

const u16 lbl_80445B7C[] = {0, 1, 2, 3};

const char *obj_lazer_fence_norm_class_name = "TObjLazerFenceNorm";
const char *lazer_fence_extra_class_name = "TObjLazerFenceExtra";

// Two sets (set data's size flag), each a box across the fence and a post at each end.
CollisionBody laser_fence_collision_body_parts[2][3] = {
    {
        {{0.0f, 0.0f, 0.0f}, 28.0f, 4.0f, 1, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, 20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, -20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
    {
        {{0.0f, 0.0f, 0.0f}, 35.0f, 4.0f, 1, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, 30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, -30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
};

NJS_TEXLIST *lazer_fence_norm_texture_list;
BmlResource *lazer_fence_norm_bml_resource;

struct Obj_80192554 { u8 pad0[0x38]; u8 f38[0x24]; s32 f5C; s32 f60; u8 pad64[0x48]; s32 fAC; u8 padB0[8]; f32 fB8; s32 fBC; saddr model; s32 fC4; saddr fC8[4]; };
extern "C" {

void post_translate_matrix(void *);

struct Motion_801926D0 { u8 pad[4]; u32 frames; };
struct TObjLazerFenceExtra_801926D0 {
    u8 pad[0xB0];
    s16 switchId;
    u8 padb2[2];
    s32 state;
    f32 frame;
    u8 padbc[8];
    Motion_801926D0 *motion;
};

static const f32 lbl_805DBE58[1] = {0.0f};

struct Node_80192A3C { u32 flags; void *model; u8 pad8[0x24]; Node_80192A3C *child; Node_80192A3C *sibling; };

struct Fish_80192A3C { u8 pad0[0x8C]; s32 f8C; u8 pad90[0x2C]; Node_80192A3C *fBC; Node_80192A3C *bml_model; s32 fC4; void *fC8[4]; };

struct Obj_80192B5C { u8 pad0[0x38]; u8 f38[0x24]; s32 f5C; s32 angle; u8 pad64[0x48]; s32 fAC; u8 padB0[8]; f32 frame; saddr fBC; saddr model; saddr motion; saddr fC8[4]; };


struct Motion_80192CCC { u8 pad[4]; u32 frames; };

struct TObjLazerFenceNorm_80192CCC {
    u8 pad[0xB0];
    s16 switchId;
    u8 padb2[2];
    s32 state;
    f32 frame;
    u8 padbc[8];
    Motion_80192CCC *motion;
};

}

void load_lazer_fence_norm_resources(void) {
    BmlResource *obj;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        obj = new BmlResource(5, (BmlResourceDescriptor *)&lazer_fence_norm_episode2_resource_descriptor, 0, 0, NULL);
        lazer_fence_norm_bml_resource = obj;
        lazer_fence_norm_texture_list = load_gvm_texture_file("fe_obj_lazer2_2.gvm");
        break;
    default:
        obj = new BmlResource(5, (BmlResourceDescriptor *)&lazer_fence_norm_episode1_resource_descriptor, 0, 0, NULL);
        lazer_fence_norm_bml_resource = obj;
        lazer_fence_norm_texture_list = load_gvm_texture_file("fe_obj_lazer2.gvm");
        break;
    }
}

void TObjLazerFenceNorm::free_resources() {
    if (lazer_fence_norm_bml_resource != NULL) {
        delete (BmlResource *)lazer_fence_norm_bml_resource;
        lazer_fence_norm_bml_resource = NULL;
    }
    if (lazer_fence_norm_texture_list != NULL) {
        release_texture_list(lazer_fence_norm_texture_list);
        safe_free(lazer_fence_norm_texture_list);
        lazer_fence_norm_texture_list = NULL;
    }
}


void *TObjLazerFenceNorm::create(void *set_data) {
    return new TObjLazerFenceNorm(tl_05, set_data);
}

TObjLazerFenceNorm::TObjLazerFenceNorm(TObject *parent, void *set_data) : TObjCollidable(parent) {
    m_name = obj_lazer_fence_norm_class_name;
    apply_object_set_data(set_data);
    m_b4 = 0;
    frame = lbl_805DBE58[0];
    scale_level = (s32)scale.x;
    if ((s32)scale_level < 0) {
        scale_level = 0;
    }
    if ((s32)scale_level > 3) {
        scale_level = 3;
    }
    switch_id = (s16)set_params[0];
    select_models();
    init_collision_body_parts(this, laser_fence_collision_body_parts[set_params[2] % 2], 3);
    actorFlags |= 0x40000000;
    register_object_by_id();
    refresh_collision_body_centers();
}

TObjLazerFenceNorm::~TObjLazerFenceNorm() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjLazerFenceNorm::run_task() {

    switch (this->m_b4) {
    case 0:
        update_closed();
        return;
    case 1:
        reset_by_door();
        return;
    }
}

void TObjLazerFenceNorm::reset_by_door() {
    if (is_current_floor_switch_set((u16) *(s16 *)&this->switch_id) == 0) {
        set_indexed_flags(0, 1);
        *(s32 *)&this->m_b4 = 0;
    }
}

void TObjLazerFenceNorm::update_closed() {
    this->frame += 0.9f;
    if ((f32)(((TObjLazerFenceNorm_80192CCC *)this)->motion->frames - 1) < ((TObjLazerFenceNorm_80192CCC *)this)->frame) {
        this->frame = lbl_805DBE58[0];
    }
    if (is_current_floor_switch_set((u16)((TObjLazerFenceNorm_80192CCC *)this)->switchId) == 1) {
        clear_player_status_flag(0, 1);
        ((TObjLazerFenceNorm_80192CCC *)this)->state = 1;
    }
}

void TObjLazerFenceNorm::render() {

    if (update_object_view_visibility(300.0f, 40.0f) != 0) {
        switch (this->m_b4) {
        case 0:
            draw_animated_beam();
            return;
        case 1:
            draw_model();
            break;
        }
    }
}

void TObjLazerFenceNorm::draw_model() {
    TObjFish::set_global_param(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    rotate_matrix_y(NULL, this->rotation_y);
    draw_ginja_object(this->m_bc);
    pop_matrix();
}

void TObjLazerFenceNorm::draw_animated_beam() {
    s32 i;
    for (i = 0; i < 4; i++) {
        set_ginja_model_texture_slot(reinterpret_cast<void *>((((Obj_80192B5C *)this)->fC8[i])), (lbl_80445B7C[((Obj_80192B5C *)this)->fAC]));
    }
    TObjFish::set_global_param(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(((Obj_80192B5C *)this)->f38);
    rotate_matrix_y(NULL, ((Obj_80192B5C *)this)->angle);
    draw_ginja_object((void *)((Obj_80192B5C *)this)->fBC);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion((void *)(((Obj_80192B5C *)this)->model), (void *)(((Obj_80192B5C *)this)->motion), ((Obj_80192B5C *)this)->frame);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjLazerFenceNorm::select_models() {
    Fish_80192A3C *arg0 = (Fish_80192A3C *)this;
    s32 i;
    Node_80192A3C *node;
    s32 j;
    if (this->set_params[2] % 2 == 0) {
        this->m_bc = (Node_80192A3C *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 1);
        arg0->bml_model = (Node_80192A3C *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 0);
        this->bml_motion = (saddr)get_bml_motion(lazer_fence_norm_bml_resource, 0);
    } else {
        this->m_bc = (Node_80192A3C *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 3);
        arg0->bml_model = (Node_80192A3C *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 2);
        this->bml_motion = (saddr)get_bml_motion(lazer_fence_norm_bml_resource, 1);
    }
    for (j = 0; j < 4; j++) {
        arg0->fC8[j] = 0;
    }
    i = 0;
    node = arg0->bml_model->child;
    if (node != 0) {
        arg0->fC8[i++] = node->model;
        node = node->sibling;
        while (node != 0 && i < 4) {
            arg0->fC8[i++] = node->model;
            node = node->sibling;
        }
    }
}


void *TObjLazerFenceExtra::create(void *set_data) {
    return new TObjLazerFenceExtra(tl_05, set_data);
}

TObjLazerFenceExtra::TObjLazerFenceExtra(TObject *parent, void *set_data) : TObjCollidable(parent) {
    s32 i;
    m_name = lazer_fence_extra_class_name;
    apply_object_set_data(set_data);
    m_b4 = 0;
    frame = lbl_805DBE58[0];
    scale_level = (s32)scale.x;
    if (scale_level < 0) {
        scale_level = 0;
    }
    if (scale_level > 3) {
        scale_level = 3;
    }
    switch_id = set_params[0];
    if (set_params[2] < 0 || set_params[2] > 1) {
        size_valid = 0;
        set_params[2] = 0;
    } else {
        size_valid = 1;
    }
    init_models();
    init_collision_body_parts(this, laser_fence_collision_body_parts[set_params[2] % 2], 3);
    actorFlags |= 0x40000000;
    bodies->half_width = scale.y;
    bodies->radius = scale.z;
    register_object_by_id();
    refresh_collision_body_centers();
    if (size_valid == 0) {
        for (i = 1; i < body_count; i++) {
            clear_player_status_flag(i, 1);
        }
    }
}

TObjLazerFenceExtra::~TObjLazerFenceExtra() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjLazerFenceExtra::run_task() {
    switch (m_b4) {
    case 0:
        update_wait_switch();
        return;
    case 1:
        reset_by_door();
        return;
    }
}

void TObjLazerFenceExtra::reset_by_door() {
    if (is_current_floor_switch_set((u16)switch_id) == 0) {
        set_indexed_flags(0, 1);
        m_b4 = 0;
    }
}

void TObjLazerFenceExtra::update_wait_switch() {
    this->frame += 0.9f;
    if ((f32)(((TObjLazerFenceExtra_801926D0 *)this)->motion->frames - 1) < ((TObjLazerFenceExtra_801926D0 *)this)->frame) {
        this->frame = lbl_805DBE58[0];
    }
    if (is_current_floor_switch_set((u16)((TObjLazerFenceExtra_801926D0 *)this)->switchId) == 1) {
        clear_player_status_flag(0, 1);
        ((TObjLazerFenceExtra_801926D0 *)this)->state = 1;
    }
}

void TObjLazerFenceExtra::render() {
    if (update_object_view_visibility(300.0f, 40.0f) != 0 && size_valid != 0) {
        switch (m_b4) {
        case 0:
            draw_lazer_fence_extra_model();
            return;
        case 1:
            render_lazer_fence_model();
            break;
        }
    }
}

void TObjLazerFenceExtra::render_lazer_fence_model() {
    TObjFish::set_global_param(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    rotate_matrix_y(NULL, this->rotation_y);
    draw_ginja_object(*(void * *)&this->base_model);
    pop_matrix();
}

void TObjLazerFenceExtra::draw_lazer_fence_extra_model() {
    Obj_80192554 *arg0 = (Obj_80192554 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        set_ginja_model_texture_slot(reinterpret_cast<void *>((arg0->fC8[i])), lbl_80445B7C[this->scale_level]);
    }
    TObjFish::set_global_param(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(NULL, this->rotation_y);
    draw_ginja_object((void *)this->base_model);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion((void *)arg0->model, (void *)this->beam_motion, this->frame);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}
