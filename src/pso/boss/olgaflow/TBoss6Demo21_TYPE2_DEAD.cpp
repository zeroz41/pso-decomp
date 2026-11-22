#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/text_80087278.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/boss/olgaflow/Boss6Type2Death.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo21_TYPE2_DEAD.h"
#include "pso/boss/olgaflow/TBoss6Zanzo.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"

struct EmitterSchedule { s32 start; s32 end; s32 id; };

struct Pl_8033E0F0 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec pos;
};

extern "C" {
extern void *__vt__23TBoss6Demo21_TYPE2_DEAD[];
void __ct__7TObjectFP7TObject(void *, TObject *);
void vec3_add_to(void *, void *);
f32 vector_length(void *);
void subtract_vector(void *, void *);
#define __vt__23TBoss6Demo21_TYPE2_DEAD ((u8 *)__vt__23TBoss6Demo21_TYPE2_DEAD)
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
void run_task__23TBoss6Demo21_TYPE2_DEADFv(TBoss6Demo21_TYPE2_DEAD *self);

}
extern "C" const char TBoss6Demo21_TYPE2_DEAD__class_name_string[] = "TBoss6Demo21_TYPE2_DEAD";
extern "C" const Vec lbl_804780A0 = {-10000.0f, 0.0f, 0.0f};
extern "C" const Vec lbl_804780AC = {0.0f, 0.0f, -142.0f};
extern "C" const Vec lbl_804780B8 = {0.0f, -2.0f, 6.4f};
extern "C" const ModelNodePositionEntry boss6_type2_death_effect_desc_a[] = {{0x24}, {-1}};
extern "C" const ModelNodePositionEntry boss6_type2_death_effect_desc_b[] = {{0x19}, {-1}};
extern "C" const ModelNodePositionEntry boss6_type2_death_effect_desc_c[] = {{2}, {3}, {-1}};
extern "C" const CameraAngles lbl_80478134 = {0, 0, 0};
extern "C" const CameraPlayback lbl_80478140 = {1, 1, 0, 0.0f, 0.7f};
extern "C" const EmitterSchedule boss6_type2_death_emitter_ranges[4] = {{0, 0x8E, 0x228}, {0xFA, 0x13A, 0x22A}, {0x11D, 0x1AC, 0x22E}, {0xF2, 0x13A, 0x179}};
extern "C" const u32 lbl_8047817C[3] = {0xffff4000, 0xffffff60, 0xffff4000};
extern "C" const char *TBoss6Demo21_TYPE2_DEAD__name = TBoss6Demo21_TYPE2_DEAD__class_name_string;
#pragma pool_data off
extern "C" {
void TBoss6Demo21_TYPE2_DEAD::draw_model_13() {
    if (timer >= 0x1AC) {
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param((saddr)(models[3].texture));
        capture_13->install();
        draw_model_motion(models[3].model, models[3].motion, frame);
        capture_13->clear();
        clear_motion_packed_rotation();
        pop_matrix();
    }
}
void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_8() {
    f32 f;
    s32 t;
    f = 0.0f;
    t = timer;
    if (t > 0x11D && t < 0x1AC) {
        if (t >= 0x12C && t <= 0x1AC) {
            f = 1.0f;
        } else if (t > 0x11D && t < 0x12C) {
            f = (f32)(t - 0x11D) / 15.0f;
        }
    }
    if (0.0f != f) {
        if (f < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(f);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param((saddr)(models[2].texture));
        capture_8->install();
        draw_model_motion(models[2].model, models[2].motion, frame);
        capture_8->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (f < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_5() {

    f32 f;
    s32 t;

    f = 0.0f;
    t = timer;
    if (t > 0x101 && t < 0x12C) {
        if (t >= 0x10F && t <= 0x11D) {
            f = 1.0f;
        } else if (t > 0x101 && t < 0x10F) {
            f = (f32)(t - 0x101) / 14.0f;
        } else if (t > 0x11D && t < 0x12C) {
            f = (f32) (0x12C - t) / 15.0f;
        }
    }
    if (0.0f != f) {
        if (f < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(f);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param((saddr)(models[1].texture));
        capture_5->install();
        draw_model_motion(models[1].model, models[1].motion, frame);
        capture_5->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (f < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_4() {
    f32 var_f31;
    s32 temp_r0;
    temp_r0 = timer;
    if (temp_r0 < 0x101) {
        var_f31 = (1.0f);
    } else if (temp_r0 >= 0x10F) {
        var_f31 = (0.0f);
    } else {
        var_f31 = (f32) (0x10F - temp_r0) / (14.0f);
    }
    if ((0.0f) != var_f31) {
        if (var_f31 < (1.0f)) {
            TBoss6PlotFalz::set_fade_material_color(var_f31);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param((saddr)(models[0].texture));
        capture_5->install();
        draw_model_motion(models[0].model, models[0].motion, frame);
        capture_5->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (var_f31 < (1.0f)) {
            TObjFish::reset_fish_globals();
        }
    }
}

void render__23TBoss6Demo21_TYPE2_DEADFv(void* p) { ((TBoss6Demo21_TYPE2_DEAD *)p)->draw_fading_model_4(); ((TBoss6Demo21_TYPE2_DEAD *)p)->draw_fading_model_5(); ((TBoss6Demo21_TYPE2_DEAD *)p)->draw_fading_model_8(); ((TBoss6Demo21_TYPE2_DEAD *)p)->draw_model_13(); }

#pragma push
#pragma pool_data off
void run_task__23TBoss6Demo21_TYPE2_DEADFv(TBoss6Demo21_TYPE2_DEAD *self) {
    Vec points[3];
    if ((self->frame += 0.7f) > 499.0f) {
        self->frame = 499.0f;
    }
    switch (self->timer) {
    case 0x0:
        play_sound_effect(0x4003232C, 0, 0, 0);
        break;
    case 0xAE:
    case 0xCF:
        play_sound_effect(0x4003942D, 0, 0, 0);
        break;
    case 0x23B:
        play_sound_effect(0x40032830, 0, 0, 0);
        break;
    }
    if (self->timer >= 0x12C && self->timer <= 0x1AC) {
        play_persistent_sound(0x4003352E, (saddr)self, 0, 0, 0);
    }
    if (self->timer >= 0x1D7 && self->timer <= 0x23A) {
        play_persistent_sound(0x32D2F, (saddr)self, 0, 0, 0);
    }
    switch (self->timer) {
    case 0xAE:
    case 0xCF: {
        Vec p = self->camera_position;
        vec3_add_to(&p, (void *)&lbl_804780AC);
        spawn_particle_effect_with_flags(&p, 0x221, 0x40);
        spawn_particle_effect_with_flags(&p, 0x22F, 0x40);
        break;
    }
    case 0x1AC:
        spawn_particle_effect_with_flags(&self->effect_position_8, 0x223, 0x40);
        break;
    case 0x23A: {
        Vec p = self->camera_position;
        vec3_add_to(&p, (void *)&lbl_804780B8);
        spawn_particle_effect_with_flags(&p, 0xA4, 0x40);
        spawn_particle_effect_with_flags(&p, 0xE3, 0x40);
        break;
    }
    }
    if (self->timer >= 0x12C && self->timer < 0x1BA) {
        spawn_particle_effect_with_flags(&self->effect_position_8, 0x22E, 0x40);
    }
    {
        Vec *ptrs[4];
        s32 i;
        ptrs[0] = &self->camera_position;
        ptrs[1] = &self->effect_position_5;
        ptrs[2] = &self->effect_position_8;
        ptrs[3] = &self->effect_position_5;
        for (i = 0; i < 4; i++) {
            if (self->timer >= boss6_type2_death_emitter_ranges[i].start && self->timer < boss6_type2_death_emitter_ranges[i].end) {
                if (self->emitters[i] == 0) {
                    self->emitters[i] = create_particle_emitter(ptrs[i], boss6_type2_death_emitter_ranges[i].id);
                    if (self->emitters[i] != 0) {
                        self->emitters[i]->set_flags(0x40);
                    }
                } else {
                    self->emitters[i]->set_position(ptrs[i]);
                }
            } else if (self->emitters[i] != 0) {
                TParticleCtrl::release(self->emitters[i]);
                self->emitters[i] = 0;
            }
        }
    }
    if (self->timer >= 0x1AE) {
        VecCopy(&points[0], &self->trail_positions[0]);
        VecCopy(&points[2], &self->trail_positions[1]);
        VecCopy(&points[1], &points[0]);
        vec3_add_to(&points[1], &points[2]);
        points[1].x *= 0.5f;
        points[1].y *= 0.5f;
        points[1].z *= 0.5f;
        self->trail_effect->set_effect_points(points, lbl_8047817C);
    }
    if (self->timer == 0x23A) {
        s32 n = TLobby::get_game_mode();
        Vec c;
        s32 i;
        VecCopy((Vec *)&c, (const Vec *)&self->camera_position);
        vec3_add_to(&c, (void *)&lbl_804780B8);
        for (i = 0; i < n; i++) {
            Pl_8033E0F0 *p = (Pl_8033E0F0 *)TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_locally_controlled(p) != 0 && TBoss6PlotFalz::is_state_1f((TObjPlayer *)p) != 0) {
                Vec d;
                VecCopy((Vec *)&d, (const Vec *)&p->pos);
                subtract_vector(&d, &c);
                d.y = (0.0f);
                if (!(vector_length(&d) > (0.25f))) {
                    p->f30 |= 0x600;
                }
            }
        }
    }
    switch (self->timer) {
    case 0x5F:
    case 0x82:
    case 0xB1:
    case 0xCD:
    case 0xFA:
    case 0x10E:
    case 0x23C:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    self->timer++;
    if (self->timer >= 0x2CA || self->plot->get_scene_state() != 7) {
        self->queue_destruction();
    }
}
#pragma pop

}
TBoss6Demo21_TYPE2_DEAD::~TBoss6Demo21_TYPE2_DEAD() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (emitters[i] != NULL) {
            TParticleCtrl::release(emitters[i]);
            emitters[i] = NULL;
        }
    }
    restore_player_cameras();
    TBoss6PlotFalz::refresh_players_equipment();
    if (capture_5 != NULL) {
        ModelNodePositionCapture::destroy((ModelNodePositionCapture *)capture_5);
        capture_5 = NULL;
    }
    if (capture_8 != NULL) {
        ModelNodePositionCapture::destroy((ModelNodePositionCapture *)capture_8);
        capture_8 = NULL;
    }
    if (capture_13 != NULL) {
        ModelNodePositionCapture::destroy((ModelNodePositionCapture *)capture_13);
        capture_13 = NULL;
    }
}
#pragma push
#pragma opt_common_subs off
extern "C" {
TBoss6Demo21_TYPE2_DEAD *TBoss6Demo21_TYPE2_DEAD__ct(TBoss6Demo21_TYPE2_DEAD *demo, TBoss6PlotFalz *plot, const Vec *target) {
    Vec delta;
    s32 i;
    __ct__7TObjectFP7TObject(demo, plot);
    *(void **)((u8 *)demo + 0x18) = __vt__23TBoss6Demo21_TYPE2_DEAD;
    demo->m_name = TBoss6Demo21_TYPE2_DEAD__name;
    demo->plot = plot;
    VecCopy(&demo->camera_position, &lbl_804780A0);
    VecCopy(&delta, target);
    subtract_vector(&delta, (void *)&lbl_804780A0);
    delta.y = 0.0f;
    if (vector_length(&delta) > 60.0f) {
        normalize_vector(&delta);
        delta.x *= 60.0f;
        delta.z *= 60.0f;
    }
    vec3_add_to(&demo->camera_position, &delta);
    BmlResource *archive = TBoss6PlotFalz::get_scene_archive();
    demo->models[0].model = (NJS_OBJECT *)get_bml_model(archive, 4);
    demo->models[0].texture = (GinjaTextureList *)get_bml_texlist(archive, 4);
    demo->models[0].motion = get_bml_motion(archive, 7);
    demo->models[1].model = (NJS_OBJECT *)get_bml_model(archive, 5);
    demo->models[1].texture = (GinjaTextureList *)get_bml_texlist(archive, 5);
    demo->models[1].motion = get_bml_motion(archive, 7);
    demo->models[2].model = (NJS_OBJECT *)get_bml_model(archive, 8);
    demo->models[2].texture = (GinjaTextureList *)get_bml_texlist(archive, 8);
    demo->models[2].motion = get_bml_motion(archive, 8);
    demo->models[3].model = (NJS_OBJECT *)get_bml_model(archive, 0xD);
    demo->models[3].texture = (GinjaTextureList *)get_bml_texlist(archive, 0xD);
    demo->models[3].motion = get_bml_motion(archive, 0x3D);
    demo->capture_5 = ModelNodePositionCapture::create(boss6_type2_death_effect_desc_a, (Vec *)&demo->effect_position_5);
    demo->capture_8 = ModelNodePositionCapture::create(boss6_type2_death_effect_desc_b, (Vec *)&demo->effect_position_8);
    demo->capture_13 = ModelNodePositionCapture::create(boss6_type2_death_effect_desc_c, (Vec *)demo->trail_positions);
    activate_camera_mode(5);
    const Vec *camera_position = &demo->camera_position;
    set_scripted_camera_pose(camera_position, camera_position, &lbl_80478134);
    lbl_80478140.cache_target_and_forward(0x416C);
    for (i = 0; i < 4; i++) {
        demo->emitters[i] = NULL;
    }
    demo->trail_effect = TBoss6Zanzo::create(demo, 3, 0xF);
    demo->frame = 0.0f;
    demo->timer = 0;
    return demo;
}
}
#pragma pop

TBoss6Demo21_TYPE2_DEAD *TBoss6Demo21_TYPE2_DEAD::create(TBoss6PlotFalz *plot, const Vec *target) {
    TBoss6Demo21_TYPE2_DEAD *demo = (TBoss6Demo21_TYPE2_DEAD *)TObject::operator new(sizeof(TBoss6Demo21_TYPE2_DEAD));
    if (demo != NULL) {
        demo = TBoss6Demo21_TYPE2_DEAD__ct(demo, plot, target);
    }
    return demo;
}

#undef __vt__23TBoss6Demo21_TYPE2_DEAD
