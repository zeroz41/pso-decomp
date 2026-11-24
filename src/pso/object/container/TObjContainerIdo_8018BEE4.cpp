#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/RenderFadeState.h"
#include "pso/object/container/TObjContainerIdo.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/container/TObjContainerJungEnemy.h"

#include "pso/item/TUnk_804B97C0.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/object/container/TContainerAncient01R.h"
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/GinjaTexture.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"


extern "C" {
__declspec(section ".data") const char *fe_obj_hako_i_rail_model_names[3] = { "fe_obj_hako_i_rail.gj", "fe_obj_hako_ido.gj", NULL };
const char *fe_obj_hako_i_rail_motion_names[1] = { NULL };
BmlResourceDescriptor container_ido_resource_descriptor = { "fe_obj_hako_i_rail.bml", fe_obj_hako_i_rail_model_names, fe_obj_hako_i_rail_motion_names, 2, 0 };
CollisionBody container_ido_collision_parts[] = { { { 0.0f, 0.0f, 0.0f }, 20.0f, 20.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f } };
const char *obj_container_ido_class_name = "TObjContainerIdo";
}

#pragma push
#pragma fp_contract on
s32 TObjContainerIdo::update_object_view_visibility(f32 far_depth, f32 radius) {
    Vec p;
    f32 out[2];
    matrix_mult_vec(0, &home_position, &p);
    if (xyz_distance_squared(&position, &camera_ctrl_instance->pos) < radius * radius) {
        return 1;
    }
    if (p.z + radius / 2.0f > 0.0f) {
        return 0;
    }
    if (p.z < -far_depth) {
        return 0;
    }
    if (p.x < 0.0f) {
        p.x = camera_right.x * radius + position.x;
        p.y = camera_right.y * radius + position.y;
        p.z = camera_right.z * radius + position.z;
        project_world_to_screen(0, &p, out);
        if (out[0] < 0.0f) {
            return 0;
        }
    } else {
        p.x = position.x - camera_right.x * radius;
        p.y = position.y - camera_right.y * radius;
        p.z = position.z - camera_right.z * radius;
        project_world_to_screen(0, &p, out);
        if (out[0] > 6.4e+02f) {
            return 0;
        }
    }
    return 1;
}
#pragma pop

BmlResource *container_ido_model_archive;
NJS_TEXLIST *container_ido_textures;

void TObjContainerIdo::render() {
    s32 fading;

    if (update_object_view_visibility(4e+02f, 2e+02f) != 0) {
        fading = 0;
        if (TRaderMapCore::is_not_split_screen() == 0) {
            fading = fade.updateFromCamera(&position.x);
        }
        if (fading != 0) {
            fade.set_flags_and_apply_damage_color();
        }
        {
            NJS_TEXLIST *textures = container_ido_textures;
            if (textures != NULL) {
                TObjFish::set_global_param(textures);
            }
        }
        push_matrix();
        post_translate_matrix(&home_position.x);
        rotate_matrix_y(0, rotation_y);
        rotate_matrix_x(0, rotation_x);
        draw_ginja_object((void *)get_bml_model(container_ido_model_archive, 0));
        pop_matrix();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        rotate_matrix_x(0, rotation_x);
        draw_ginja_object((void *)get_bml_model(container_ido_model_archive, 1));
        pop_matrix();
        if (fading != 0) {
            fade.clear_flag_and_notify();
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjContainerIdo::run_task() {
    f32 prev;
    u32 old;
    s32 i;

    prev = target_distance;
    old = state & 0xF;
    target_distance = 0.0f;
    for (i = 0; i < switch_count; i++) {
        if (is_current_floor_switch_set((u16)switch_ids[i]) == 1) {
            state |= 1 << i;
            target_distance += step_distance;
        } else {
            state &= ~(1 << i);
        }
    }
    if ((old ^ (state & 0xF)) != 0) {
        if (prev - target_distance < 0.0f) {
            state &= ~0x02000000;
            state &= ~0x01000000;
        } else {
            state |= 0x02000000;
            state &= ~0x01000000;
        }
    }
    state &= ~0x04000000;
    if (state & 0x02000000) {
        if (xyz_distance(&home_position, &position) > target_distance) {
            Vec v = { 0.0f, 0.0f, 0.0f };
            v.z = -speed;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, rotation_y);
            rotate_matrix_x(0, rotation_x);
            rotate_vector_by_matrix(0, &v, &v);
            pop_matrix();
            position.x -= v.x;
            position.y -= v.y;
            position.z -= v.z;
            state |= 0x04000000;
            play_persistent_sound(0x4B717, this, &position, 0, 0);
        } else if (!(state & 0x01000000)) {
            play_sound_effect(0x4C118, &position, 0, 0);
            state |= 0x01000000;
        }
    } else {
        if (xyz_distance(&home_position, &position) < target_distance) {
            Vec w = { 0.0f, 0.0f, 0.0f };
            w.z = -speed;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, rotation_y);
            rotate_matrix_x(0, rotation_x);
            rotate_vector_by_matrix(0, &w, &w);
            pop_matrix();
            position.x += w.x;
            position.y += w.y;
            position.z += w.z;
            state |= 0x04000000;
            play_persistent_sound(0x4B717, this, &position, 0, 0);
        } else if (!(state & 0x01000000)) {
            play_sound_effect(0x4C118, &position, 0, 0);
            state |= 0x01000000;
        }
    }
    if (!(state & 0x08000000) && (state & 0x04000000)) {
        if (3.0517578e-05f * (f32)rand() < 0.4f && update_object_view_visibility(4e+02f, 1e+02f) != 0) {
            Vec a;
            Vec b;
            Vec out;
            a.x = 1e+01f;
            a.y = 2.0f;
            a.z = 3e+01f * (3.0517578e-05f * (f32)rand()) - 15.0f;
            b.x = (-1e+01f);
            b.y = 2.0f;
            b.z = 3e+01f * (3.0517578e-05f * (f32)rand()) - 15.0f;
            push_matrix_from(&identity_matrix);
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            rotate_matrix_x(0, rotation_x);
            matrix_mult_vec(0, &a, &out);
            spawn_particle_effect(&out, 0x42);
            matrix_mult_vec(0, &b, &out);
            spawn_particle_effect(&out, 0x42);
            pop_matrix();
        }
    }
    fade.update();
}
#pragma pop

void *TObjContainerIdo::create(void *set) {
    return new TObjContainerIdo(tl_05, set);
}

void TObjContainerIdo::free_resources() {
    if (container_ido_textures != NULL) {
        release_texture_list(container_ido_textures);
        safe_free(container_ido_textures);
        container_ido_textures = NULL;
    }
    if (container_ido_model_archive != NULL) {
        delete container_ido_model_archive;
        container_ido_model_archive = NULL;
    }
}

void TObjContainerIdo::load_resources() {
    BmlResource *archive = new BmlResource(5, &container_ido_resource_descriptor, 0, 0, NULL);
    container_ido_model_archive = archive;
    container_ido_textures = load_gvm_texture_file("obj_containerido.GVM");
}

TObjContainerIdo::~TObjContainerIdo() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TObjContainerIdo::TObjContainerIdo(TObject *parent, void *set) : TUnk_804B97C0(parent) {
    s32 i;
    m_name = obj_container_ido_class_name;
    apply_object_set_data(set);
    VecCopy(&home_position, &position);
    VecCopy(&m_b4, &position);
    view_radius = 1e+02f;
    switch_count = set_params[1];
    if (switch_count < 1) {
        switch_count = 1;
    }
    if (switch_count > 4) {
        switch_count = 4;
    }
    for (i = 0; i < switch_count; i++) {
        switch_ids[i] = set_params[0] + i;
    }
    state = 0;
    if (set_params[2] != 0) {
        state |= 0x08000000;
    } else {
        state &= ~0x08000000;
    }
    target_distance = 0.0f;
    step_distance = scale.x / switch_count;
    speed = scale.y;
    fade.activate_and_dispatch();
    init_collision_body_parts(this, container_ido_collision_parts, 1);
    actorFlags |= 0x40000000;
    register_object_by_id();
}
