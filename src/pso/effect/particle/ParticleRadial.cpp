#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "pso/effect/particle/TParticleCtrl_80085EE4.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_8048E778.h"
#include "pso/unk/TUnk_8048E790.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E7A8.h"
#include "pso/unk/text_80086B64.h"

#include "types.h"
#include <stdlib.h>
#include "pso/effect/particle/TParticleCtrl_80327D30.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


extern "C" {
f32 vec_squared_length(u8 *arg0);
void set_queued_main_phase(s32 arg0);
void request_main_phase(s32 arg0);
s32 append_node_to_tail__13TParticleCtrlFPvPv(s32, void *);
s32 rotate_matrix_y(s32, s32);
s32 post_translate_matrix(void *);
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
f32 vector_length(void *);
void project_world_to_screen(s32, void *, void *);
static const ParticleAngles radial_particle_zero_angles = { 0, 0, 0 };
void __ct__7TObjectFP7TObject(void *, void *);
}
void stop_cue_stream(void);
void setup_particle_tev(s32 arg0);
void load_projected_texture_matrix(f32 farg0);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern void *__vt__13TParticleCtrl[];
extern s32 TParticleCtrl__class_name_descriptor;
extern const f32 TParticleCtrl__data_805D94E0;
extern const f32 TParticleCtrl__data_805D94E4;

#define COPY_PARTICLE_DIRECTION(particle, direction) do {                      \
    s32 component;                                                             \
    component = direction->x;                                                  \
    particle->direction.x = component;                                         \
    component = direction->z;                                                  \
    particle->direction.z = component;                                         \
    component = direction->y;                                                  \
    particle->direction.y = component;                                         \
} while (0)
#define CLEAR_PARTICLE_DIRECTION(particle, unused) do {                        \
    particle->direction.x = 0;                                                 \
    particle->direction.y = 0;                                                 \
    particle->direction.z = 0;                                                 \
} while (0)

#define INITIALIZE_PARTICLE(particle, position, particle_index, field30,       \
                            field34, field38, use_self, particle_flags,        \
                            direction_action, direction_source) do {           \
    __ct__7TObjectFP7TObject(particle, tl_07);                                 \
    particle->vtable = __vt__13TParticleCtrl;                                  \
    particle->descriptor = TParticleCtrl__class_name_descriptor;                       \
    particle->field4C = 0;                                                     \
    particle->field50 = 0;                                                     \
    particle->field54 = 0;                                                     \
    particle->field48 = 0;                                                     \
    particle->field40 = TParticleCtrl__data_805D94E4;                          \
    particle->field44 = TParticleCtrl__data_805D94E4;                          \
    particle->field1C = TParticleCtrl__data_805D94E0;                          \
    particle->field20 = 0;                                                     \
    particle->field24 = TParticleCtrl__data_805D94E4;                          \
    particle->particle_index = particle_index;                                 \
    VecCopy(&particle->position, position);                      \
    particle->flags = particle_flags;                                          \
    particle->field2E = 0xFFFF;                                                \
    direction_action(particle, direction_source);                              \
    particle->field30 = field30;                                               \
    particle->field34 = field34;                                               \
    particle->field38 = field38;                                               \
    particle->field3C = 0;                                                     \
    if (use_self != 0) {                                                       \
        particle->owner = particle;                                            \
    } else if (particle->flags & 0x800) {                                      \
        if (particle->flags & 0x4000) {                                        \
            particle->owner = tl_clipout;                                      \
        } else {                                                               \
            particle->owner = tl_07;                                           \
        }                                                                      \
    } else {                                                                   \
        particle->owner = tl_07;                                               \
    }                                                                          \
} while (0)

#include "pso/unk/TLobby.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"


u8 *create_radial_particle(u8 *arg0, u8 *pos, s32 parent, u16 flags, s16 target_id) {
    return (u8 *)new TUnk_8048E7A8(arg0, pos, parent, flags, target_id);
}
void *create_random_particle(void *arg0, void *pos, void *parent) {
    return new TUnk_8048E7A8(arg0, pos, parent);
}

void TUnk_8048E7A8::check_radial_particle_retire() {
    u8 *arg0 = (u8 *)this;
    if ((this->age >= 1.0f) || (0.0f == vec_squared_length((arg0 + 0x3C)))) {
        ((TObject *)arg0)->queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TUnk_8048E7A8::run_task() {
    NJS_COLOR col;
    Vec target;
    f32 t[2];                  // [0] age this frame, [1] fade alpha; kept in memory
    f32 fade_in;
    f32 fade_out;
    f32 rest;
    f32 ch[3];
    ParticleParam *p;
    s32 frames;
    u32 last;

    speed *= param->speed_decay;
    approach_vector_fixed_distance(&pos, &origin, &target, speed);
    step.x = target.x - pos.x;
    step.y = target.y - pos.y;
    step.z = target.z - pos.z;
    vec3_add_to(&pos, &step);
    fade_in = 1.0f;
    fade_out = fade_in;
    m_28 *= param->scale_decay;
    unk_2C *= param->scale_decay;
    age += age_rate;
    p = param;
    t[0] = age;
    if (p->fade_in_end > t[0]) {
        fade_in = t[0] * fade_in_scale;
    }
    rest = 1.0f - t[0];
    if (rest < p->fade_out_start) {
        fade_out = rest * fade_out_scale;
    }
    t[1] = (fade_in < fade_out) ? fade_in : fade_out;
    if (TParticleCtrl__data_80511F70[sprite_index]->definition->flags & 1) {
        if (flags & 0x100) {
            ch[0] = fade_particle_channel(p->color_rate[0] * t[0] + color_base[0], t[1]);
            ch[1] = fade_particle_channel(p->color_rate[1] * t[0] + color_base[1], t[1]);
            ch[2] = fade_particle_channel(p->color_rate[2] * t[0] + color_base[2], t[1]);
        } else {
            ch[0] = fade_particle_channel(p->color_rate[0] * t[0] + p->color_base[0], t[1]);
            ch[1] = fade_particle_channel(p->color_rate[1] * t[0] + p->color_base[1], t[1]);
            ch[2] = fade_particle_channel(p->color_rate[2] * t[0] + p->color_base[2], t[1]);
        }
        t[1] = 1.0f;
    } else if (flags & 0x100) {
        ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + color_base[0]);
        ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + color_base[1]);
        ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + color_base[2]);
    } else {
        ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + p->color_base[0]);
        ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + p->color_base[1]);
        ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + p->color_base[2]);
    }
    col.argb.a = 254.0f * t[1];
    col.argb.r = 254.0f * ch[0];
    col.argb.g = 254.0f * ch[1];
    col.argb.b = 254.0f * ch[2];
    color = col.color;
    frames = TParticleCtrl__data_80511F70[sprite_index]->definition->uv_count;
    if (param->flags & 0x10) {
        frame = age * (frames - 1);
    } else {
        frame++;
        if (frames <= frame) {
            frame = 0;
        }
    }
    if (flags & 0x10) {
        TObjCollidable *target_obj = find_entity_by_id(target_id);
        if (target_obj == NULL) {
            queue_destruction();
            return;
        }
        Vec *center = (Vec *)target_obj->get_center();
        attach.x = center->x - origin.x;
        attach.y = center->y - origin.y;
        attach.z = center->z - origin.z;
    }
    if (motion != NULL) {
        motion_frame += unk_C0;
        last = motion->nbFrame - 1;
        if ((f32)last <= motion_frame) {
            motion_frame = last;
        }
    }
    check_radial_particle_retire();
}
#pragma pop

void TUnk_8048E7A8::render() {
    u8 *arg0 = (u8 *)this;
    NJS_POINT2 s1;
    NJS_POINT2 s2;
    Vec end;
    Vec pos;
    f32 len;
    u16 flags;
    if ((s32)this->all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    if (*(u8 *)((s8 *)(*(u8 * *)&this->param) + 0x88) & 4) {
        if (this->flags & 0x10) {
            pos.x = this->pos.x + this->attach.x;
            pos.y = this->pos.y + this->attach.y;
            pos.z = this->pos.z + this->attach.z;
        } else {
            VecCopy((Vec *)&pos, (const Vec *)&this->pos);
        }
        end.x = pos.x + this->step.x;
        end.y = pos.y + this->step.y;
        end.z = pos.z + this->step.z;
        len = vector_length((u8 *)&this->step);
        if (0.0f == len) {
            return;
        }
        project_world_to_screen(0, &pos, &s1);
        project_world_to_screen(0, &end, &s2);
        s2.x = s2.x - s1.x;
        s2.y = s2.y - s1.y;
        this->m_96 = (s16)(10430.38043493439 * atan2_float(s2.y, s2.x));
        this->m_88 = *(f32 *)((s8 *)(*(u8 * *)&this->param) + 0x60) * len;
        *(f32 *)((s8 *)arg0 + 0x8C) = *(f32 *)((s8 *)(*(u8 * *)&this->param) + 0x64) * len;
    } else {
        this->m_88 = this->m_28;
        *(f32 *)((s8 *)arg0 + 0x8C) = *(f32 *)&this->unk_2C;
    }
    this->m_88 = this->m_88 * this->m_a4;
    *(f32 *)((s8 *)arg0 + 0x8C) = *(f32 *)((s8 *)arg0 + 0x8C) * *(f32 *)((s8 *)arg0 + 0xA8);
    flags = this->flags;
    if (flags & 0x200) {
        if (((is_split_screen() == 0) || !(this->flags & 0x400)) && (this->unk_B4 != 0U) && (this->model != NULL)) {
            ParticleAngles ang = radial_particle_zero_angles;
            Vec pos2;
            direction_to_rotation_xz((u8 *)&this->step, &ang.x, &ang.z);
            if (*(u8 *)((s8 *)(*(u8 * *)&this->param) + 0x88) & 4) {
                pos2.x = this->pos.x + this->attach.x;
                pos2.y = this->pos.y + this->attach.y;
                pos2.z = this->pos.z + this->attach.z;
            } else {
                VecCopy((Vec *)&pos2, (const Vec *)&this->pos);
            }
            push_matrix();
            post_translate_matrix(&pos2);
            scale_matrix(0, this->m_88, this->m_88, this->m_88);
            if (*(u8 *)((s8 *)(*(u8 * *)&this->param) + 0x88) & 4) {
                rotate_matrix_z(0, ang.z);
                rotate_matrix_x(0, ang.x);
                rotate_matrix_y(0, ang.y);
            }
            if ((this->flags & 0x1000) && (camera_ctrl_instance != NULL)) {
                rotate_matrix_y(0, *(s32 *)((s8 *)camera_ctrl_instance + 0x194));
            }
            TParticleCtrl::begin_effect_render();
            if (this->flags & 0x400) {
                load_projected_texture_matrix(1.33f);
            }
            rotate_matrix_y(0, this->m_96);
            if (this->flags & 0x400) {
                setup_particle_tev(0);
            } else {
                s32 render_flags = model_render_flags;
                saved_model_render_flags = render_flags;
                model_render_flags = render_flags | 0x8021;
                if (((TUnk_8048E728 *)arg0)->is_particle_sprite_additive(render_flags) != 0) {
                    ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(1);
                } else {
                    ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(0);
                }
            }
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->unk_B4));
            set_draw_list_mask(3);
            if (this->motion != 0U) {
                draw_ginja_model_with_motion(this->model, this->motion, this->motion_frame);
            } else {
                draw_ginja_object(this->model);
            }
            if (this->flags & 0x400) {
                reset_particle_tev();
            } else {
                model_render_flags = saved_model_render_flags;
            }
            TParticleCtrl::end_effect_render();
            pop_matrix();
        }
    } else {
        if (flags & 0x2000) {
            ((TUnk_8048E728 *)arg0)->draw_particle_refraction_quad();
            return;
        }
        if (*(u8 *)((s8 *)this->param + 0x88) & 0x20) {
            append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)((u8 *)&TParticleCtrl__data_80511F70 + 0xD8))[this->sprite_index], (u8 *)&this->unk_6C);
            return;
        }
        append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)&TParticleCtrl__data_80511F70)[this->sprite_index], (u8 *)&this->unk_6C);
    }
}

TUnk_8048E7A8::~TUnk_8048E7A8() {}

#pragma push
#pragma fp_contract on

#pragma push
#pragma fp_contract on
TUnk_8048E7A8::TUnk_8048E7A8(u8 *src, u8 *arg2, saddr parent, u16 arg4, s16 arg5)
    : TUnk_8048E728((ParticleParam *)src, (TObject *)parent) {
    struct Fields_arg0 { u8 pad_0[24]; s32 * field_18; u16 field_1C; u8 pad_1E[6]; u16 field_24; s16 field_26; f32 field_28; f32 field_2C; f32 field_30; f32 field_34; f32 field_38; f32 field_3C; f32 field_40; f32 field_44; u8 pad_48[20]; f32 field_5C; u8 pad_60[8]; f32 field_68; u8 pad_6C[4]; f32 field_70; f32 field_74; f32 field_78; u8 pad_7C[25]; s8 field_95; };
    struct Fields_arg1 { u8 pad_0[24]; f32 field_18; f32 field_1C; f32 field_20; f32 field_24; f32 field_28; u8 pad_2C[4]; f32 field_30; u8 pad_34[4]; f32 field_38; u8 pad_3C[12]; s32 field_48; s32 field_4C; u8 pad_50[56]; u8 field_88; };
    struct Fields_arg2 { f32 field_0; f32 field_4; f32 field_8; };
    s32 temp_r0;
    ((Fields_arg0*)this)->field_70 = (f32) ((((Fields_arg1*)src)->field_18 * ((3.0517578e-05f * (f32) rand()) - 0.5f)) + ((Fields_arg2*)arg2)->field_0);
    ((Fields_arg0*)this)->field_74 = (f32) ((((Fields_arg1*)src)->field_1C * ((3.0517578e-05f * (f32) rand()) - 0.5f)) + ((Fields_arg2*)arg2)->field_4);
    ((Fields_arg0*)this)->field_78 = (f32) ((((Fields_arg1*)src)->field_20 * ((3.0517578e-05f * (f32) rand()) - 0.5f)) + ((Fields_arg2*)arg2)->field_8);
    ((Fields_arg0*)this)->field_24 = arg4;
    if (((Fields_arg0*)this)->field_24 & 0x80) {
        ((Fields_arg0*)this)->field_95 = 1;
    }
    ((Fields_arg0*)this)->field_26 = arg5;
    ((Fields_arg0*)this)->field_30 = (f32) ((Fields_arg2*)arg2)->field_0;
    ((Fields_arg0*)this)->field_34 = (f32) ((Fields_arg2*)arg2)->field_4;
    ((Fields_arg0*)this)->field_38 = (f32) ((Fields_arg2*)arg2)->field_8;
    ((Fields_arg0*)this)->field_28 = (f32) ((((Fields_arg1*)src)->field_28 * (3.0517578e-05f * (f32) rand())) + ((Fields_arg1*)src)->field_24);
    ((Fields_arg0*)this)->field_2C = (f32) ((Fields_arg0*)this)->field_28;
    temp_r0 = (s32) (((f32) ((Fields_arg1*)src)->field_4C * (3.0517578e-05f * (f32) rand())) + (f32) ((Fields_arg1*)src)->field_48);
    if (((Fields_arg1*)src)->field_88 & 1) {
        ((Fields_arg0*)this)->field_5C = (f32) (1.0f / (f32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(saddr *)((s8 *)&TParticleCtrl__data_80511F70 + (((Fields_arg0*)this)->field_1C * 4))) + 0x28)) + 0xC));
    } else {
        ((Fields_arg0*)this)->field_5C = (f32) (1.0f / (f32) temp_r0);
    }
    ((Fields_arg0*)this)->field_68 = (f32) ((((Fields_arg1*)src)->field_38 * (3.0517578e-05f * (f32) rand())) + ((Fields_arg1*)src)->field_30);
    ((Fields_arg0*)this)->field_3C = 0.0f;
    ((Fields_arg0*)this)->field_40 = 0.0f;
    ((Fields_arg0*)this)->field_44 = 0.0f;
    if (((Fields_arg0*)this)->field_24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop

TUnk_8048E7A8::TUnk_8048E7A8(void *src, void *arg2, void *parent)
    : TUnk_8048E728((ParticleParam *)src, (TObject *)parent) {
    struct Fields_arg0 { u8 pad_0[24]; s32 * field_18; u16 field_1C; u8 pad_1E[6]; u16 field_24; u8 pad_26[2]; f32 field_28; f32 field_2C; f32 field_30; f32 field_34; f32 field_38; f32 field_3C; f32 field_40; f32 field_44; u8 pad_48[20]; f32 field_5C; u8 pad_60[8]; f32 field_68; u8 pad_6C[4]; f32 field_70; f32 field_74; f32 field_78; };
    struct Fields_arg1 { u8 pad_0[24]; f32 field_18; f32 field_1C; f32 field_20; f32 field_24; f32 field_28; u8 pad_2C[4]; f32 field_30; u8 pad_34[4]; f32 field_38; u8 pad_3C[12]; s32 field_48; s32 field_4C; u8 pad_50[56]; u8 field_88; };
    struct Fields_arg2 { f32 field_0; f32 field_4; f32 field_8; };
    s32 temp_r0;
    ((Fields_arg0*)((u8 *)this))->field_70 = (f32) ((((Fields_arg1*)src)->field_18 * ((3.0517578e-05f * (f32) rand()) - 0.5f)) + ((Fields_arg2*)arg2)->field_0);
    ((Fields_arg0*)((u8 *)this))->field_74 = (f32) ((((Fields_arg1*)src)->field_1C * ((3.0517578e-05f * (f32) rand()) - 0.5f)) + ((Fields_arg2*)arg2)->field_4);
    ((Fields_arg0*)((u8 *)this))->field_78 = (f32) ((((Fields_arg1*)src)->field_20 * ((3.0517578e-05f * (f32) rand()) - 0.5f)) + ((Fields_arg2*)arg2)->field_8);
    ((Fields_arg0*)((u8 *)this))->field_30 = (f32) ((Fields_arg2*)arg2)->field_0;
    ((Fields_arg0*)((u8 *)this))->field_34 = (f32) ((Fields_arg2*)arg2)->field_4;
    ((Fields_arg0*)((u8 *)this))->field_38 = (f32) ((Fields_arg2*)arg2)->field_8;
    ((Fields_arg0*)((u8 *)this))->field_28 = (f32) ((((Fields_arg1*)src)->field_28 * (3.0517578e-05f * (f32) rand())) + ((Fields_arg1*)src)->field_24);
    ((Fields_arg0*)((u8 *)this))->field_2C = (f32) ((Fields_arg0*)((u8 *)this))->field_28;
    temp_r0 = (s32) (((f32) ((Fields_arg1*)src)->field_4C * (3.0517578e-05f * (f32) rand())) + (f32) ((Fields_arg1*)src)->field_48);
    if (((Fields_arg1*)src)->field_88 & 1) {
        ((Fields_arg0*)((u8 *)this))->field_5C = (f32) (1.0f / (f32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(saddr *)((s8 *)TParticleCtrl__data_80511F70 + (((Fields_arg0*)((u8 *)this))->field_1C * 4))) + 0x28)) + 0xC));
    } else {
        ((Fields_arg0*)((u8 *)this))->field_5C = (f32) (1.0f / (f32) temp_r0);
    }
    ((Fields_arg0*)((u8 *)this))->field_68 = (f32) ((((Fields_arg1*)src)->field_38 * (3.0517578e-05f * (f32) rand())) + ((Fields_arg1*)src)->field_30);
    ((Fields_arg0*)((u8 *)this))->field_3C = 0.0f;
    step.y = 0.0f;
    step.z = 0.0f;
    if (((Fields_arg0*)((u8 *)this))->field_24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop

void destroy_keyboard_objects(void * object) { ((TObject *)object)->queue_destruction(); set_queued_main_phase(2); request_main_phase(18); TLobby::stop_audio_streams(); stop_cue_stream(); }
