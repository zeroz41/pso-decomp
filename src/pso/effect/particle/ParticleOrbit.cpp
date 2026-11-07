#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleOrbit.h"
#include "pso/render/render_util.h"
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
#include "pso/effect/particle/TParticleCtrl_80327D30.h"
#include "pso/player/TObjPlayer_80083594.h"
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

struct RecoveredGlobal_8008C21C_TParticleCtrl__data_80511F70 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Vec_8008A92C { f32 x, y, z; };

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

struct Vec_8008AC24 { f32 x, y, z; };

struct IVec_8008AC24 { s32 x, y, z; };

extern ParticleTexture *TParticleCtrl__data_80511F70[];
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

struct OVec_8008B060 { f32 x, y, z; };

struct OIVec_8008B060 { s32 x, y, z; };

extern "C" {
void *alloc_particle_memory(int);
void queue_destruction__7TObjectFv(void *arg0);
extern const f32 TParticleCtrl__data_805D9528;
extern s32 TParticleCtrl__data_8048E790[];
s32 rand(void);
s32 is_particle_sprite_additive__13TUnk_8048E728Fv(void *, s32);
s32 append_node_to_tail__13TParticleCtrlFPvPv(s32, void *);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_y(s32, s32);
s32 draw_ginja_object(u32);
s32 draw_ginja_model_with_motion(u32, NJS_MOTION *, f32);
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9540;
extern const f32 TParticleCtrl__data_805D952C;
extern const f32 TParticleCtrl__data_805D9530;
extern const f32 lbl_805D9544;
extern const f32 lbl_805D9548;
extern const f32 lbl_805D954C;
extern const f32 lbl_805D9550;
void __ct__7TObjectFP7TObject(void *, void *);
}
void setup_particle_tev(s32 arg0);
void load_projected_texture_matrix(f32 farg0);
extern void *__vt__13TParticleCtrl[];
extern s32 TParticleCtrl__class_name_descriptor;
extern void *tl_07;
extern void *tl_clipout;
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

extern "C" {

void clear_active_flag__13TParticleCtrlFv(void* p);

void clear_active_flag__13TParticleCtrlFv(void* p) { *(u16*)((char*)p + 0x2c) &= 0xfffe; }
u8 *create_orbit_particle(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u16 arg4, s16 arg5) {
    u8 *particle_memory;
    u8 *var_r0;
    particle_memory = (u8 *)(((u8 *)alloc_particle_memory(0xE0)));
    var_r0 = particle_memory;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(init_orbit_sprite_particle(particle_memory, arg0, arg1, arg2, arg3, arg4, arg5));
    }
    return var_r0;
}
void *TParticleCtrl::alloc_child_particle(void *arg1, void *arg2, void *arg3) {
    void *o;
    o = alloc_particle_memory(0xe0);
    if (o != NULL) {
        o = ((TUnk_8048E790 *)o)->init_random_particle(this, arg1, arg2, arg3);
    }
    return o;
}
void TUnk_8048E790::retire_orbit_particle() {
    u8 *arg0 = (u8 *)this;
    if (this->age >= TParticleCtrl__data_805D9528) {
        queue_destruction__7TObjectFv((arg0));
    }
}

// Colour channel scaled by the fade alpha; nothing below zero, at most alpha.
inline f32 fade_particle_channel(f32 c, f32 alpha) {
    if (c < 0.0f) {
        return 0.0f;
    }
    return alpha * ((c < 1.0f) ? c : 1.0f);
}

inline f32 clamp_particle_channel(f32 c) {
    if (c < 0.0f) {
        return 0.0f;
    }
    return (c < 1.0f) ? c : 1.0f;
}

#pragma push
#pragma fp_contract on
void TUnk_8048E790::run_task() {
    NJS_COLOR col;
    Vec lift;
    Vec ring;
    Vec follow_lift;
    ParticleParam *p;
    f32 t;
    f32 fade_in;
    f32 fade_out;
    f32 alpha;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
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
        ring.y = 0.0f;
        ring.z = orbit_radius * sin_table_lookup(orbit_angle);
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
    t = age;
    fade_in = 1.0f;
    fade_out = 1.0f;
    if (p->fade_in_end > t) {
        fade_in = t * fade_in_scale;
    }
    if (1.0f - t < p->fade_out_start) {
        fade_out = (1.0f - t) * fade_out_scale;
    }
    if (fade_in < fade_out) {
        alpha = fade_in;
    } else {
        alpha = fade_out;
    }
    if (TParticleCtrl__data_80511F70[sprite_index]->sprites->flags & 1) {
        if (flags & 0x100) {
            r = fade_particle_channel(p->orbit_red_rate * t + color_base[0], alpha);
            g = fade_particle_channel(p->unk_38 * t + color_base[1], alpha);
            b = fade_particle_channel(p->unk_3C * t + color_base[2], alpha);
        } else {
            r = fade_particle_channel(p->orbit_red_rate * t + p->color_base[0], alpha);
            g = fade_particle_channel(p->unk_38 * t + p->color_base[1], alpha);
            b = fade_particle_channel(p->unk_3C * t + p->color_base[2], alpha);
        }
        a = 1.0f;
    } else {
        if (flags & 0x100) {
            r = clamp_particle_channel(p->orbit_red_rate * t + color_base[0]);
            g = clamp_particle_channel(p->unk_38 * t + color_base[1]);
            b = clamp_particle_channel(p->unk_3C * t + color_base[2]);
        } else {
            r = clamp_particle_channel(p->orbit_red_rate * t + p->color_base[0]);
            g = clamp_particle_channel(p->unk_38 * t + p->color_base[1]);
            b = clamp_particle_channel(p->unk_3C * t + p->color_base[2]);
        }
        a = alpha;
    }
    col.argb.a = 254.0f * a;
    col.argb.r = 254.0f * r;
    col.argb.g = 254.0f * g;
    col.argb.b = 254.0f * b;
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
    frames = TParticleCtrl__data_80511F70[sprite_index]->sprites->frame_count;
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
        if ((f32)(motion->nbFrame - 1) <= motion_frame) {
            motion_frame = motion->nbFrame - 1;
        }
    }
    retire_orbit_particle();
}
#pragma pop

void TUnk_8048E790::render() {
    u8 *arg0 = (u8 *)this;
    Vec_8008A92C sp8;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f3;
    s32 temp_r4;
    u16 temp_r3;
    if (all_parents_unqueued_for_destruction__7TObjectFv() != 0) {
        temp_f3 = *(f32 *)((s8 *)this->param + 0x70) * cos_table_lookup(this->m_dc);
        this->m_88 = (f32) (this->m_28 * (TParticleCtrl__data_805D9528 + temp_f3));
        *(f32 *)((s8 *)arg0 + 0x8C) = (f32) (*(f32 *)&this->unk_2C * (TParticleCtrl__data_805D9528 - temp_f3));
        this->m_88 = (f32) (this->m_88 * this->m_a4);
        *(f32 *)((s8 *)arg0 + 0x8C) = (f32) (*(f32 *)((s8 *)arg0 + 0x8C) * *(f32 *)((s8 *)arg0 + 0xA8));
        temp_r3 = *(u16 *)((s8 *)arg0 + 0x24);
        if (temp_r3 & 0x200) {
            if (((is_split_screen() == 0) || !(*(u16 *)((s8 *)arg0 + 0x24) & 0x400)) && ((u32) *(u32 *)&this->unk_B4 != 0U) && ((u32) this->m_b0 != 0U)) {
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
                if (*(u16 *)((s8 *)arg0 + 0x24) & 0x400) {
                    TParticleCtrl::begin_effect_render();
                    load_projected_texture_matrix(lbl_805D9540);
                }
                rotate_matrix_y(0, (s32) this->m_96);
                if ((*(u16 *)((s8 *)arg0 + 0x24) & 0x1000) && ((void *) camera_ctrl_instance != NULL)) {
                    rotate_matrix_y(0, *(s32 *)((s8 *)camera_ctrl_instance + 0x194));
                }
                TParticleCtrl::end_effect_render();
                if (*(u16 *)((s8 *)arg0 + 0x24) & 0x400) {
                    setup_particle_tev(0);
                } else {
                    temp_r4 = model_render_flags;
                    saved_model_render_flags = temp_r4;
                    model_render_flags = temp_r4 | 0x8021;
                    if (is_particle_sprite_additive__13TUnk_8048E728Fv(arg0, temp_r4) != 0) {
                        ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(1);
                    } else {
                        ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(0);
                    }
                }
                TObjFish::set_global_param(*(u32 *)&this->unk_B4);
                set_draw_list_mask(3);
                if ((u32) this->motion != 0U) {
                    draw_ginja_model_with_motion(this->m_b0, this->motion, this->motion_frame);
                } else {
                    draw_ginja_object(this->m_b0);
                }
                if (*(u16 *)((s8 *)arg0 + 0x24) & 0x400) {
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
                append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)((u8 *)&TParticleCtrl__data_80511F70 + 0xD8))[*(u16 *)((s8 *)arg0 + 0x1C)], arg0 + 0x6C);
                return;
            }
            append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)&TParticleCtrl__data_80511F70)[*(u16 *)((s8 *)arg0 + 0x1C)], arg0 + 0x6C);
        }
    }
}

void *__dt__13TUnk_8048E790Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = TParticleCtrl__data_8048E790;
        __dt__13TUnk_8048E728Fv((u8 *)arg0, 0);
        if (arg1 > 0) {
            ((TUnk_8048E728 *)arg0)->free_from_heap();
        }
    }
    return arg0;
}
}
#pragma push
#pragma fp_contract on
u8 *init_orbit_sprite_particle(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4, u16 arg5, s16 arg6) {
    Obj_8008AC24 *o = (Obj_8008AC24 *)object;
    Desc_8008AC24 *d = (Desc_8008AC24 *)arg1;
    Vec_8008AC24 *p = (Vec_8008AC24 *)arg2;
    IVec_8008AC24 *v = (IVec_8008AC24 *)arg3;
    s32 temp_r0;
    init_particle_base(object, arg1, arg4);
    o->f18 = TParticleCtrl__data_8048E790;
    o->f98 = v->x;
    o->f9C = v->y;
    o->fA0 = v->z;
    o->fC4 = (lbl_805D9544 * d->f18) * ((lbl_805D9548 * (f32)rand()) - lbl_805D954C) + p->x;
    o->fC8 = (lbl_805D9544 * d->f20) * ((lbl_805D9548 * (f32)rand()) - lbl_805D954C) + p->z;
    o->f74 = (lbl_805D9544 * d->f1C) * ((lbl_805D9548 * (f32)rand()) - lbl_805D954C) + p->y;
    o->f30 = p->x;
    o->f38 = p->z;
    o->f34 = o->f74;
    o->f24 = arg5;
    if (o->f24 & 0x80) {
        o->f95 = 1;
    }
    o->f26 = arg6;
    o->f28 = d->f28 * (lbl_805D9548 * (f32)rand()) + d->f24;
    o->f2C = o->f28;
    temp_r0 = (s32)((f32)d->f4C * (lbl_805D9548 * (f32)rand()) + (f32)d->f48);
    if (d->f88 & 1) {
        o->f5C = TParticleCtrl__data_805D9528 / (f32)*(s32 *)((s8 *)(*(void **)((s8 *)(*(s32 *)((s8 *)TParticleCtrl__data_80511F70 + (o->f1C * 4))) + 0x28)) + 0xC);
    } else {
        o->f5C = TParticleCtrl__data_805D9528 / (f32)temp_r0;
    }
    o->f3C = d->f74 * (lbl_805D9548 * (f32)rand()) + d->f30;
    o->f40 = d->f68 * (lbl_805D9548 * (f32)rand()) + d->f34;
    o->fD8 = (s32)(TParticleCtrl__data_805D952C * (lbl_805D9550 * (lbl_805D9548 * (f32)rand())));
    o->fD0 = d->f64 * (lbl_805D9548 * (f32)rand()) + d->f60;
    o->fDC = (s32)(TParticleCtrl__data_805D952C * (lbl_805D9550 * (lbl_805D9548 * (f32)rand())));
    o->f96 = o->fD8;
    o->f68 = (lbl_805D9548 * (f32)rand()) - lbl_805D954C;
    o->fD4 = TParticleCtrl__data_805D9530;
    if (o->f24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
    return object;
}
#pragma pop

#pragma push
#pragma fp_contract on

void *TUnk_8048E790::init_random_particle(void *arg1, void *arg2, void *arg3, void *arg4) {
    OObj_8008B060 *o = (OObj_8008B060 *)this;
    ODesc_8008B060 *d = (ODesc_8008B060 *)arg1;
    OVec_8008B060 *p = (OVec_8008B060 *)arg2;
    OIVec_8008B060 *v = (OIVec_8008B060 *)arg3;
    s32 temp_r0;
    init_particle_base(this, arg1, (s32)arg4);
    o->f18 = TParticleCtrl__data_8048E790;
    o->f98 = v->x;
    o->f9C = v->y;
    o->fA0 = v->z;
    o->fC4 = (lbl_805D9544 * d->f18) * ((lbl_805D9548 * (f32)rand()) - lbl_805D954C) + p->x;
    o->fC8 = (lbl_805D9544 * d->f20) * ((lbl_805D9548 * (f32)rand()) - lbl_805D954C) + p->z;
    o->f74 = (lbl_805D9544 * d->f1C) * ((lbl_805D9548 * (f32)rand()) - lbl_805D954C) + p->y;
    o->f30 = p->x;
    o->f38 = p->z;
    o->f34 = o->f74;
    o->f28 = d->f28 * (lbl_805D9548 * (f32)rand()) + d->f24;
    o->f2C = o->f28;
    temp_r0 = (s32)((f32)d->f4C * (lbl_805D9548 * (f32)rand()) + (f32)d->f48);
    if (d->f88 & 1) {
        o->f5C = TParticleCtrl__data_805D9528 / (f32)*(s32 *)((s8 *)(*(void **)((s8 *)(*(s32 *)((s8 *)((s32 *)&TParticleCtrl__data_80511F70) + (o->f1C * 4))) + 0x28)) + 0xC);
    } else {
        o->f5C = TParticleCtrl__data_805D9528 / (f32)temp_r0;
    }
    o->f3C = d->f74 * (lbl_805D9548 * (f32)rand()) + d->f30;
    o->f40 = d->f68 * (lbl_805D9548 * (f32)rand()) + d->f34;
    o->fD8 = (s32)(TParticleCtrl__data_805D952C * (lbl_805D9550 * (lbl_805D9548 * (f32)rand())));
    o->fD0 = d->f64 * (lbl_805D9548 * (f32)rand()) + d->f60;
    o->fDC = (s32)(TParticleCtrl__data_805D952C * (lbl_805D9550 * (lbl_805D9548 * (f32)rand())));
    o->f96 = o->fD8;
    o->f68 = (lbl_805D9548 * (f32)rand()) - lbl_805D954C;
    o->fD4 = TParticleCtrl__data_805D9530;
    if (o->f24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
    return this;
}
#pragma pop
