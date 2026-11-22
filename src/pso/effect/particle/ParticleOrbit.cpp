#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/effect/particle/ParticleOrbit.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_8048E778.h"
#include "pso/unk/TUnk_8048E7A8.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E790.h"

#include "types.h"
#include <stdlib.h>
#include "pso/effect/particle/TParticleCtrl_80327D30.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/system/task/TObject.h"
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


struct Obj_8008AC24 {
    u8 pad_0[0x18];
    s32 *f18;
    u16 f1C;
    u8 pad_1E[6];
    u16 f24;
    s16 f26;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    u8 pad_44[0x18];
    f32 f5C;
    u8 pad_60[8];
    f32 f68;
    u8 pad_6C[8];
    f32 f74;
    u8 pad_78[0x1D];
    s8 f95;
    s16 f96;
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 pad_A4[0x20];
    f32 fC4;
    f32 fC8;
    u8 pad_CC[4];
    f32 fD0;
    f32 fD4;
    s32 fD8;
    s32 fDC;
};

struct Desc_8008AC24 {
    u8 pad_0[0x18];
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad_2C[4];
    f32 f30;
    f32 f34;
    u8 pad_38[0x10];
    s32 f48;
    s32 f4C;
    u8 pad_50[0x10];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad_6C[8];
    f32 f74;
    u8 pad_78[0x10];
    u8 f88;
};

struct IVec_8008AC24 { s32 x, y, z; };

struct OObj_8008B060 {
    u8 pad_0[0x18]; s32 *f18; u16 f1C; u8 pad_1E[6]; u16 f24; s16 f26;
    f32 f28; f32 f2C; f32 f30; f32 f34; f32 f38; f32 f3C; f32 f40; u8 pad_44[0x18];
    f32 f5C; u8 pad_60[8]; f32 f68; u8 pad_6C[8]; f32 f74; u8 pad_78[0x1D];
    s8 f95; s16 f96; s32 f98; s32 f9C; s32 fA0; u8 pad_A4[0x20];
    f32 fC4; f32 fC8; u8 pad_CC[4]; f32 fD0; f32 fD4; s32 fD8; s32 fDC;
};

struct ODesc_8008B060 {
    u8 pad_0[0x18]; f32 f18; f32 f1C; f32 f20; f32 f24; f32 f28; u8 pad_2C[4];
    f32 f30; f32 f34; u8 pad_38[0x10]; s32 f48; s32 f4C; u8 pad_50[0x10];
    f32 f60; f32 f64; f32 f68; u8 pad_6C[8]; f32 f74; u8 pad_78[0x10]; u8 f88;
};

struct OIVec_8008B060 { s32 x, y, z; };

extern "C" {
s32 append_node_to_tail__13TParticleCtrlFPvPv(s32, void *);
s32 rotate_matrix_y(s32, s32);
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
}
void setup_particle_tev(s32 arg0);
void load_projected_texture_matrix(f32 farg0);
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


u8 *create_orbit_particle(u8 *arg0, u8 *pos, u8 *dir, s32 parent, u16 flags, s16 target_id) {
    return (u8 *)new TUnk_8048E790(arg0, pos, dir, parent, flags, target_id);
}
void *TParticleCtrl::alloc_child_particle(void *param, void *pos, void *dir, void *parent) {
    return new TUnk_8048E790(param, pos, dir, parent);
}
void TUnk_8048E790::retire_orbit_particle() {
    u8 *arg0 = (u8 *)this;
    if (this->age >= 1.0f) {
        ((TObject *)arg0)->queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TUnk_8048E790::run_task() {
    NJS_COLOR col;
    Vec follow_lift;
    Vec ring;
    Vec lift;
    ParticleParam *p;
    f32 t[2]; // [0] age this frame, [1] fade alpha
    f32 fade_in;
    f32 fade_out;
    f32 ch[3];
    f32 tilt;
    s32 frames;

    orbit_angle += (s32)(182.04445f * step.x);
    if (flags & 0x10) {
        TObjCollidable *target_obj = find_entity_by_id(target_id);
        if (target_obj == NULL) {
            queue_destruction();
            return;
        }
        Vec *center = (Vec *)target_obj->get_center();
        if (unk_98 != 0 && m_9c != 0 && unk_A0 != 0) {
            attach.x = orbit_center_x - origin.x;
            attach.z = orbit_center_z - origin.z;
            pos.x = orbit_radius * cos_table_lookup(orbit_angle) + center->x;
            pos.z = orbit_radius * sin_table_lookup(orbit_angle) + center->z;
        } else {
            attach.x = orbit_center_x - origin.x;
            attach.z = orbit_center_z - origin.z;
            pos.x = orbit_radius * cos_table_lookup(orbit_angle) + center->x;
            pos.z = orbit_radius * sin_table_lookup(orbit_angle) + center->z;
            pos.y = center->y;
            orbit_height += step.y;
            follow_lift.x = 0.0f;
            follow_lift.z = 0.0f;
            follow_lift.y = orbit_height;
            push_matrix_from(&identity_matrix);
            rotate_matrix_x(0, unk_98);
            rotate_matrix_y(0, m_9c);
            rotate_matrix_z(0, unk_A0);
            rotate_vector_by_current_matrix(&follow_lift, &follow_lift);
            pop_matrix();
            pos.x += follow_lift.x;
            pos.y += follow_lift.y;
            pos.z += follow_lift.z;
        }
    } else if (unk_98 != 0 && m_9c != 0 && unk_A0 != 0) {
        pos.x = orbit_radius * cos_table_lookup(orbit_angle) + orbit_center_x;
        pos.z = orbit_radius * sin_table_lookup(orbit_angle) + orbit_center_z;
    } else {
        ring.x = orbit_radius * cos_table_lookup(orbit_angle);
        ring.z = orbit_radius * sin_table_lookup(orbit_angle);
        ring.y = 0.0f;
        orbit_height += step.y;
        lift.x = 0.0f;
        lift.z = 0.0f;
        lift.y = orbit_height;
        push_matrix_from(&identity_matrix);
        rotate_matrix_x(0, unk_98);
        rotate_matrix_y(0, m_9c);
        rotate_matrix_z(0, unk_A0);
        rotate_vector_by_current_matrix(&ring, &ring);
        rotate_vector_by_current_matrix(&lift, &lift);
        pop_matrix();
        pos.x = lift.x + (orbit_center_x + ring.x);
        pos.z = lift.z + (orbit_center_z + ring.z);
        pos.y = lift.y + (origin.y + ring.y);
    }
    if (unk_98 != 0 && m_9c != 0 && unk_A0 != 0) {
        pos.y += step.y;
    }
    m_28 *= param->scale_decay;
    unk_2C *= param->scale_decay;
    p = param;
    t[0] = age;
    fade_in = 1.0f;
    fade_out = 1.0f;
    if (p->fade_in_end > t[0]) {
        fade_in = t[0] * fade_in_scale;
    }
    if (1.0f - t[0] < p->fade_out_start) {
        fade_out = (1.0f - t[0]) * fade_out_scale;
    }
    if (fade_in < fade_out) {
        t[1] = fade_in;
    } else {
        t[1] = fade_out;
    }
    if (TParticleCtrl__data_80511F70[sprite_index]->definition->flags & 1) {
        if (flags & 0x100) {
            ch[0] = fade_particle_channel(p->orbit_red_rate * t[0] + color_base[0], t[1]);
            ch[1] = fade_particle_channel(p->unk_38 * t[0] + color_base[1], t[1]);
            ch[2] = fade_particle_channel(p->unk_3C * t[0] + color_base[2], t[1]);
        } else {
            ch[0] = fade_particle_channel(p->orbit_red_rate * t[0] + p->color_base[0], t[1]);
            ch[1] = fade_particle_channel(p->unk_38 * t[0] + p->color_base[1], t[1]);
            ch[2] = fade_particle_channel(p->unk_3C * t[0] + p->color_base[2], t[1]);
        }
        t[1] = 1.0f;
    } else {
        if (flags & 0x100) {
            ch[0] = clamp_particle_channel(p->orbit_red_rate * t[0] + color_base[0]);
            ch[1] = clamp_particle_channel(p->unk_38 * t[0] + color_base[1]);
            ch[2] = clamp_particle_channel(p->unk_3C * t[0] + color_base[2]);
        } else {
            ch[0] = clamp_particle_channel(p->orbit_red_rate * t[0] + p->color_base[0]);
            ch[1] = clamp_particle_channel(p->unk_38 * t[0] + p->color_base[1]);
            ch[2] = clamp_particle_channel(p->unk_3C * t[0] + p->color_base[2]);
        }
    }
    col.argb.a = 254.0f * t[1];
    col.argb.r = 254.0f * ch[0];
    col.argb.g = 254.0f * ch[1];
    col.argb.b = 254.0f * ch[2];
    color = col.color;
    m_dc += (s32)(182.04445f * param->orbit_spin_rate);
    age += age_rate;
    tilt = 8.0f * step.x * step.y;
    if (fabs_float(tilt) > 10.0f) {
        tilt = 10.0f;
    }
    if (speed < 0.0f) {
        m_96 += (s32)(182.04445f * tilt);
    } else {
        m_96 -= (s32)(182.04445f * tilt);
    }
    frames = TParticleCtrl__data_80511F70[sprite_index]->definition->uv_count;
    if (param->flags & 0x10) {
        frame = age * (frames - 1);
    } else {
        frame++;
        if (frames <= frame) {
            frame = 0;
        }
    }
    m_28 *= m_a4;
    unk_2C *= unk_A8;
    if (motion != NULL) {
        motion_frame += unk_C0;
        if ((motion->nbFrame - 1) <= motion_frame) {
            motion_frame = motion->nbFrame - 1;
        }
    }
    retire_orbit_particle();
}
#pragma pop

void TUnk_8048E790::render() {
    u8 *arg0 = (u8 *)this;
    Vec sp8;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f3;
    s32 render_flags;
    u16 temp_r3;
    if ((s32)this->all_parents_unqueued_for_destruction() != 0) {
        temp_f3 = *(f32 *)((s8 *)this->param + 0x70) * cos_table_lookup(this->m_dc);
        this->m_88 = (f32) (this->m_28 * (1.0f + temp_f3));
        *(f32 *)((s8 *)arg0 + 0x8C) = (f32) (*(f32 *)&this->unk_2C * (1.0f - temp_f3));
        this->m_88 = (f32) (this->m_88 * this->m_a4);
        *(f32 *)((s8 *)arg0 + 0x8C) = (f32) (*(f32 *)((s8 *)arg0 + 0x8C) * *(f32 *)((s8 *)arg0 + 0xA8));
        temp_r3 = this->flags;
        if (temp_r3 & 0x200) {
            if (((is_split_screen() == 0) || !(this->flags & 0x400)) && ((u32) this->unk_B4 != 0U) && (this->model != NULL)) {
                sp8.x = this->pos.x + this->attach.x;
                sp8.y = this->pos.y + this->attach.y;
                sp8.z = this->pos.z + this->attach.z;
                push_matrix();
                post_translate_matrix(&sp8.x);
                temp_f1_2 = this->m_88;
                scale_matrix(0, temp_f1_2, temp_f1_2, temp_f1_2);
                rotate_matrix_z(0, *(s32 *)&this->unk_A0);
                rotate_matrix_x(0, *(s32 *)&this->unk_98);
                rotate_matrix_y(0, this->m_9c);
                saved_model_render_flags = model_render_flags;
                if (this->flags & 0x400) {
                    TParticleCtrl::begin_effect_render();
                    load_projected_texture_matrix(1.33f);
                }
                rotate_matrix_y(0, (s32) this->m_96);
                if ((this->flags & 0x1000) && ((void *) camera_ctrl_instance != NULL)) {
                    rotate_matrix_y(0, *(s32 *)((s8 *)camera_ctrl_instance + 0x194));
                }
                TParticleCtrl::end_effect_render();
                if (this->flags & 0x400) {
                    setup_particle_tev(0);
                } else {
                    render_flags = model_render_flags;
                    saved_model_render_flags = render_flags;
                    model_render_flags = render_flags | 0x8021;
                    if (((TUnk_8048E728 *)arg0)->is_particle_sprite_additive(render_flags) != 0) {
                        ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(1);
                    } else {
                        ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(0);
                    }
                }
                TObjFish::set_global_param(this->unk_B4);
                set_draw_list_mask(3);
                if ((uaddr) this->motion != 0U) {
                    draw_ginja_model_with_motion(this->model, this->motion, this->motion_frame);
                } else {
                    draw_ginja_object(this->model);
                }
                if (this->flags & 0x400) {
                    reset_particle_tev();
                }
                model_render_flags = saved_model_render_flags;
                TParticleCtrl::end_effect_render();
                pop_matrix();
            }
        } else {
            if (temp_r3 & 0x2000) {
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
}

TUnk_8048E790::~TUnk_8048E790() {}
#pragma push
#pragma fp_contract on
TUnk_8048E790::TUnk_8048E790(u8 *src, u8 *arg2, u8 *arg3, saddr parent, u16 arg5, s16 arg6)
    : TUnk_8048E728((ParticleParam *)src, (TObject *)parent) {
    Obj_8008AC24 *o = (Obj_8008AC24 *)this;
    Desc_8008AC24 *d = (Desc_8008AC24 *)src;
    Vec *p = (Vec *)arg2;
    IVec_8008AC24 *v = (IVec_8008AC24 *)arg3;
    s32 temp_r0;
    o->f98 = v->x;
    o->f9C = v->y;
    o->fA0 = v->z;
    o->fC4 = (2.0f * d->f18) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + p->x;
    o->fC8 = (2.0f * d->f20) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + p->z;
    o->f74 = (2.0f * d->f1C) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + p->y;
    o->f30 = p->x;
    o->f38 = p->z;
    o->f34 = o->f74;
    o->f24 = arg5;
    if (o->f24 & 0x80) {
        o->f95 = 1;
    }
    o->f26 = arg6;
    o->f28 = d->f28 * (3.0517578e-05f * (f32)rand()) + d->f24;
    o->f2C = o->f28;
    temp_r0 = (s32)((f32)d->f4C * (3.0517578e-05f * (f32)rand()) + (f32)d->f48);
    if (d->f88 & 1) {
        o->f5C = 1.0f / (f32)*(s32 *)((s8 *)(*(void **)((s8 *)(*(saddr *)((s8 *)TParticleCtrl__data_80511F70 + (o->f1C * 4))) + 0x28)) + 0xC);
    } else {
        o->f5C = 1.0f / (f32)temp_r0;
    }
    o->f3C = d->f74 * (3.0517578e-05f * (f32)rand()) + d->f30;
    o->f40 = d->f68 * (3.0517578e-05f * (f32)rand()) + d->f34;
    o->fD8 = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    o->fD0 = d->f64 * (3.0517578e-05f * (f32)rand()) + d->f60;
    o->fDC = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    o->f96 = o->fD8;
    o->f68 = (3.0517578e-05f * (f32)rand()) - 0.5f;
    o->fD4 = 0.0f;
    if (o->f24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on

TUnk_8048E790::TUnk_8048E790(void *src, void *pos, void *dir, void *parent)
    : TUnk_8048E728((ParticleParam *)src, (TObject *)parent) {
    OObj_8008B060 *o = (OObj_8008B060 *)this;
    ODesc_8008B060 *d = (ODesc_8008B060 *)src;
    Vec *p = (Vec *)pos;
    OIVec_8008B060 *v = (OIVec_8008B060 *)dir;
    s32 temp_r0;
    o->f98 = v->x;
    o->f9C = v->y;
    o->fA0 = v->z;
    o->fC4 = (2.0f * d->f18) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + p->x;
    o->fC8 = (2.0f * d->f20) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + p->z;
    o->f74 = (2.0f * d->f1C) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + p->y;
    o->f30 = p->x;
    o->f38 = p->z;
    o->f34 = o->f74;
    o->f28 = d->f28 * (3.0517578e-05f * (f32)rand()) + d->f24;
    o->f2C = o->f28;
    temp_r0 = (s32)((f32)d->f4C * (3.0517578e-05f * (f32)rand()) + (f32)d->f48);
    if (d->f88 & 1) {
        o->f5C = 1.0f / (f32)*(s32 *)((s8 *)(*(void **)((s8 *)(*(saddr *)((s8 *)((s32 *)&TParticleCtrl__data_80511F70) + (o->f1C * 4))) + 0x28)) + 0xC);
    } else {
        o->f5C = 1.0f / (f32)temp_r0;
    }
    o->f3C = d->f74 * (3.0517578e-05f * (f32)rand()) + d->f30;
    o->f40 = d->f68 * (3.0517578e-05f * (f32)rand()) + d->f34;
    o->fD8 = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    o->fD0 = d->f64 * (3.0517578e-05f * (f32)rand()) + d->f60;
    o->fDC = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    o->f96 = o->fD8;
    o->f68 = (3.0517578e-05f * (f32)rand()) - 0.5f;
    o->fD4 = 0.0f;
    if (o->f24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop
