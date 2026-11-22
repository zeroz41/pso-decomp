#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/text_80087278.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/PadRumble.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/olgaflow/Boss6Type2Appearance.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/olgaflow/TBoss6Demo20_TYPE2_APPEAR.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"


extern const Vec boss6_type2_appear_origin;
extern Vec boss6_type2_appear_offset_particle_origin;

typedef struct Ent_8033D6DC { s32 start; s32 end; s32 id; s32 src; } Ent_8033D6DC;

extern "C" {
const char TBoss6Demo20_TYPE2_APPEAR__class_name[] = "TBoss6Demo20_TYPE2_APPEAR";
}
const Vec boss6_type2_appear_origin = {-10000.0f, 0.0f, 0.0f};
extern "C" {
const ModelNodePositionEntry boss6_type2_appear_model_node_descriptors[9] = {
    {0x24}, {0x30}, {0x36}, {0x3A}, {0x48}, {0x4B}, {0x4E}, {0x52}, {-1},
};
const Ent_8033D6DC boss6_type2_appear_particle_schedule[9] = {
    {42, 142, 554, -1},
    {135, 385, 552, -1},
    {148, 200, 557, 1},
    {185, 228, 557, 2},
    {185, 228, 557, 6},
    {214, 257, 557, 3},
    {214, 257, 557, 7},
    {294, 357, 556, 0},
    {100, 157, 377, -2}
};
const Vec lbl_80478058 = {-10000.0f, 0.0f, 0.0f};
const CameraAngles lbl_80478064 = {0, 0, 0};
const CameraPlayback boss6_type2_appear_camera_script = {1, 3, 0, 0.0f, 0.7f};
void post_translate_matrix(const f32 *);

void TBoss6Demo20_TYPE2_APPEAR::draw_model_12() {
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&boss6_type2_appear_origin.x);
    TObjFish::set_global_param((saddr)(model12.texture));
    draw_model_motion(model12.model, model12.motion, frame);
    clear_motion_packed_rotation();
    pop_matrix();
}

void TBoss6Demo20_TYPE2_APPEAR::draw_fading_model_1_pair() {
    f32 var_f31;
    union { f64 d; u32 w[2]; } cvt;
    s32 temp_r3;
    temp_r3 = timer;
    if (temp_r3 < 0x181) {
        var_f31 = 0.0f;
    } else if (temp_r3 >= 0x190) {
        var_f31 = 1.0f;
    } else {
        var_f31 = (temp_r3 - 0x181) / (-15.0f);
    }
    if (0.0f != var_f31) {
        if (var_f31 < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(var_f31);
        }
        TObjFish::set_global_param((saddr)(model1.texture));
        set_motion_packed_rotation();
        push_matrix();
        post_translate_matrix(&effect_positions[4].x);
        draw_model_motion(model1.model, model1.motion, secondary_frame);
        pop_matrix();
        push_matrix();
        post_translate_matrix(&effect_positions[5].x);
        draw_model_motion(model1.model, model1.motion, secondary_frame);
        pop_matrix();
        clear_motion_packed_rotation();
        if (var_f31 < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo20_TYPE2_APPEAR::draw_fading_model_4() {
    f32 var_f31;
    s32 temp_r3;
    union { f64 d; u32 w[2]; } cvt;

    temp_r3 = timer;
    if (temp_r3 < 0x72) {
        var_f31 = 0.0f;
    } else if (temp_r3 >= 0x8E) {
        var_f31 = 1.0f;
    } else {
        var_f31 = (temp_r3 - 0x72) / 28.0f;
    }
    if ((0.0f != var_f31) && (capture != NULL)) {
        if (var_f31 < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(var_f31);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&boss6_type2_appear_origin.x);
        TObjFish::set_global_param((saddr)(model4.texture));
        capture->install();
        draw_model_motion(model4.model, model4.motion, frame);
        capture->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (var_f31 < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo20_TYPE2_APPEAR::draw_fading_model_pair() {
    f32 var_f31;
    s32 temp_r0;
    temp_r0 = timer;
    if (temp_r0 < 0x72) {
        var_f31 = 1.0f;
    } else if (temp_r0 >= 0x8E) {
        var_f31 = 0.0f;
    } else {
        var_f31 = (f32) (0x8E - temp_r0) / 28.0f;
    }
    if (0.0f != var_f31) {
        if (var_f31 < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(var_f31);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&boss6_type2_appear_origin.x);
        s32 i = 0;
        do {
            TObjFish::set_global_param((saddr)(opening_parts[i].texture));
            draw_model_motion(opening_parts[i].model, opening_parts[i].motion, frame);
            i++;
        } while (i < 2);
        clear_motion_packed_rotation();
        pop_matrix();
        if (var_f31 < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void render__25TBoss6Demo20_TYPE2_APPEARFv(void* p) { ((TBoss6Demo20_TYPE2_APPEAR *)p)->draw_model_12(); ((TBoss6Demo20_TYPE2_APPEAR *)p)->draw_fading_model_4(); ((TBoss6Demo20_TYPE2_APPEAR *)p)->draw_fading_model_pair(); ((TBoss6Demo20_TYPE2_APPEAR *)p)->draw_fading_model_1_pair(); }

}

extern "C" {
s32 __dt__7TObjectFv(void *, int);
extern saddr __vt__25TBoss6Demo20_TYPE2_APPEAR[];
TBoss6Demo20_TYPE2_APPEAR *__dt__25TBoss6Demo20_TYPE2_APPEARFv(TBoss6Demo20_TYPE2_APPEAR *self, s16 arg1);

extern const Ent_8033D6DC boss6_type2_appear_particle_schedule[];

void run_task__25TBoss6Demo20_TYPE2_APPEARFv(TBoss6Demo20_TYPE2_APPEAR *self);

void run_task__25TBoss6Demo20_TYPE2_APPEARFv(TBoss6Demo20_TYPE2_APPEAR *self) {
    s32 i;
    if ((self->frame += 0.7f) > 284.0f) {
        self->frame = 284.0f;
    }
    self->secondary_frame += 0.8f;
    if (self->secondary_frame >= 30.0f) {
        self->secondary_frame -= 30.0f;
    }
    switch (self->timer) {
    case 0xE:
        play_sound_effect(0x40039E28, 0, 0, 0);
        break;
    case 0x72:
        play_sound_effect(0x4003A129, 0, 0, 0);
        break;
    case 0xEE:
        play_sound_effect(0x4003972A, 0, 0, 0);
        break;
    case 0x11D:
        play_sound_effect(0x40031C2B, 0, 0, 0);
        break;
    }
    play_persistent_sound(0x4003C627, (saddr)self, 0, 0, 0);
    switch (self->timer) {
    case 0xB9:
        spawn_particle_effect_with_flags(&self->effect_positions[3], 0x220, 0x40);
        spawn_particle_effect_with_flags(&self->effect_positions[7], 0x220, 0x40);
        break;
    case 0xED:
        spawn_particle_effect_with_flags(&boss6_type2_appear_origin, 0x221, 0x40);
        spawn_particle_effect_with_flags(&boss6_type2_appear_origin, 0x225, 0x40);
        break;
    }
    for (i = 0; i < 9; i++) {
        const Ent_8033D6DC *e = &boss6_type2_appear_particle_schedule[i];
        if (self->timer >= e->start && self->timer < e->end) {
            const Vec *p = &boss6_type2_appear_origin;
            if (e->src == -2) {
                p = &boss6_type2_appear_offset_particle_origin;
            } else if (e->src >= 0) {
                p = &self->effect_positions[e->src];
            }
            if (self->emitters[i] == NULL) {
                self->emitters[i] = create_particle_emitter(p, e->id);
                if (self->emitters[i] != NULL) {
                    self->emitters[i]->set_flags(0x40);
                }
            } else {
                self->emitters[i]->set_position(const_cast<Vec *>(p));
            }
        } else if (self->emitters[i] != NULL) {
            TParticleCtrl::release(self->emitters[i]);
            self->emitters[i] = NULL;
        }
    }
    switch (self->timer) {
    case 5:
    case 0x32:
    case 0x78:
    case 0x8C:
    case 0xEB:
    case 0x122:
    case 0x136:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    self->timer++;
    if (self->timer >= 0x197 || self->plot->get_scene_state() != 5) {
        self->queue_destruction();
    }
}

TBoss6Demo20_TYPE2_APPEAR *__dt__25TBoss6Demo20_TYPE2_APPEARFv(TBoss6Demo20_TYPE2_APPEAR *self, s16 arg1) {
    s32 i;
    if (self != 0) {
        *(void **)((u8 *)self + 0x18) = __vt__25TBoss6Demo20_TYPE2_APPEAR;
        for (i = 0; i < 9; i++) {
            if (self->emitters[i] != 0) {
                TParticleCtrl::release(self->emitters[i]);
                self->emitters[i] = 0;
            }
        }
        restore_player_cameras();
        TBoss6PlotFalz::refresh_players_equipment();
        if (self->capture != 0) {
            ModelNodePositionCapture::destroy((ModelNodePositionCapture *)self->capture);
            self->capture = 0;
        }
        __dt__7TObjectFv(self, 0);
        if (arg1 > 0) {
            TObject::operator delete(self);
        }
    }
    return self;
}

}

#include "pso/camera/TCameraCtrl.h"

extern "C" {
void __ct__7TObjectFP7TObject(void *, TObject *);
extern const ModelNodePositionEntry boss6_type2_appear_model_node_descriptors[];
extern const Vec lbl_80478058;
extern const CameraAngles lbl_80478064;
extern const CameraPlayback boss6_type2_appear_camera_script;
extern s32 lbl_804DF614[];
__declspec(section ".data") extern s32 boss6_type2_appear_motion_indices[];
struct AppearanceClassTag { const char *value; u32 padding; };
__declspec(section ".sdata") extern AppearanceClassTag TBoss6Demo20_TYPE2_APPEAR__name;

#pragma push
#pragma opt_lifetimes off
#pragma pool_data off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
TBoss6Demo20_TYPE2_APPEAR *TBoss6Demo20_TYPE2_APPEAR__ct(TBoss6Demo20_TYPE2_APPEAR *demo, TBoss6PlotFalz *plot) {
    s32 v;
    BmlResource *archive;
    saddr i;
    __ct__7TObjectFP7TObject(demo, plot);
    *(saddr **)((s8 *)demo + 0x18) = __vt__25TBoss6Demo20_TYPE2_APPEAR;
    demo->m_name = TBoss6Demo20_TYPE2_APPEAR__name.value;
    demo->plot = plot;
    archive = TBoss6PlotFalz::get_scene_archive();
    for (i = 0; i < 2; i++) {
        {
            s32 t = lbl_804DF614[i];
            v = t;
            demo->opening_parts[i].model = (NJS_OBJECT *)get_bml_model(archive, t);
        }
        demo->opening_parts[i].texture = (GinjaTextureList *)get_bml_texlist(archive, v);
        demo->opening_parts[i].motion = get_bml_motion(archive, boss6_type2_appear_motion_indices[i]);
    }
    demo->model4.model = (NJS_OBJECT *)get_bml_model(archive, 4);
    demo->model4.texture = (GinjaTextureList *)get_bml_texlist(archive, 4);
    demo->model4.motion = get_bml_motion(archive, 0x20);
    demo->model1.model = (NJS_OBJECT *)get_bml_model(archive, 1);
    demo->model1.texture = (GinjaTextureList *)get_bml_texlist(archive, 1);
    demo->model1.motion = get_bml_motion(archive, 0x36);
    demo->model12.model = (NJS_OBJECT *)get_bml_model(archive, 0xC);
    demo->model12.texture = (GinjaTextureList *)get_bml_texlist(archive, 0xC);
    demo->model12.motion = get_bml_motion(archive, 0x22);
    demo->capture = ModelNodePositionCapture::create(boss6_type2_appear_model_node_descriptors, (Vec *)demo->effect_positions);
    for (i = 0; i < 9; i++) {
        demo->emitters[i] = 0;
    }
    activate_camera_mode(5);
    set_scripted_camera_pose(&lbl_80478058, &lbl_80478058, &lbl_80478064);
    boss6_type2_appear_camera_script.cache_target_and_forward(0x416C);
    demo->frame = 0.0f;
    demo->secondary_frame = 0.0f;
    demo->timer = 0;
    return demo;
}
}
#pragma pop

TBoss6Demo20_TYPE2_APPEAR *TBoss6Demo20_TYPE2_APPEAR::create(TBoss6PlotFalz *plot) {
    TBoss6Demo20_TYPE2_APPEAR *demo = (TBoss6Demo20_TYPE2_APPEAR *)TObject::operator new(sizeof(TBoss6Demo20_TYPE2_APPEAR));
    if (demo != NULL) {
        demo = TBoss6Demo20_TYPE2_APPEAR__ct(demo, plot);
    }
    return demo;
}

void initialize_boss6_type2_appear_particle_origin(void) {
    boss6_type2_appear_offset_particle_origin.x = boss6_type2_appear_origin.x;
    boss6_type2_appear_offset_particle_origin.y = 50.0f + boss6_type2_appear_origin.y;
    boss6_type2_appear_offset_particle_origin.z = boss6_type2_appear_origin.z;
}
extern "C" {
__declspec(section ".ctors") static void *const __sinit_text_8033DA94_cpp_ref = (void *)initialize_boss6_type2_appear_particle_origin;

}
__declspec(section ".data") Vec boss6_type2_appear_offset_particle_origin = {0.0f, 0.0f, 0.0f};
extern "C" {
__declspec(section ".data") s32 boss6_type2_appear_motion_indices[2] = {31, 33};
void render_shadows__7TObjectFv(void *);
saddr __vt__25TBoss6Demo20_TYPE2_APPEAR[7] = {0, 0,
    (saddr)__dt__25TBoss6Demo20_TYPE2_APPEARFv,
    (saddr)run_task__25TBoss6Demo20_TYPE2_APPEARFv, (saddr)render__25TBoss6Demo20_TYPE2_APPEARFv,
    (saddr)render_shadows__7TObjectFv, 0};
__declspec(section ".sdata") AppearanceClassTag TBoss6Demo20_TYPE2_APPEAR__name = {TBoss6Demo20_TYPE2_APPEAR__class_name, 0};
}
