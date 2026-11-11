#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/effect/particle/ParticleBallistic.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/unk/text_8023601C.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_8048E790.h"
#include "pso/unk/TUnk_8048E7A8.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E778.h"

#include "types.h"

#include "pso/effect/particle/TParticleCtrl_80327D30.h"
#include "pso/player/TObjPlayer_80083594.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Stack_80088844 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

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

struct RecoveredGlobal_8008C21C_TParticleCtrl__data_80511F70;
struct Fields0_800896E4 {
    u8 pad_0[0x18]; s32 *field_18; u16 field_1C; u8 pad_1E[6]; u16 field_24; s16 field_26;
    f32 field_28; f32 field_2C; f32 field_30; f32 field_34; f32 field_38; f32 field_3C; f32 field_40; f32 field_44;
    u8 pad_48[0x14]; f32 field_5C; u8 pad_60[8]; f32 field_68; u8 pad_6C[4]; f32 field_70; f32 field_74; f32 field_78;
    u8 pad_7C[0x19]; s8 field_95; s16 field_96; s32 field_98; s32 field_9C; s32 field_A0;
    u8 pad_A4[0x20]; f32 field_C4; f32 field_C8; f32 field_CC;
};

struct Fields1_800896E4 {
    u8 pad_0[0x18]; f32 field_18; f32 field_1C; f32 field_20; f32 field_24; f32 field_28; u8 pad_2C[4];
    f32 field_30; f32 field_34; f32 field_38; f32 field_3C; u8 pad_40[8]; s32 field_48; s32 field_4C;
    u8 pad_50[4]; f32 field_54; u8 pad_58[0x30]; u8 field_88;
};

struct Fields2_800896E4 { f32 field_0; f32 field_4; f32 field_8; };

struct Fields3_800896E4 { s32 field_0; s32 field_4; s32 field_8; };

struct Vec_800890F4 { f32 x, y, z; };

struct Ang_800890F4 { s32 x, y, z; };

static const Vec_800890F4 lbl_804394E8 = { 0.0f, 0.0f, -1.0f };
static const Vec_800890F4 lbl_804394F4 = { 0.0f, 0.0f, -1.0f };
static const Vec_800890F4 lbl_80439500 = { 0.0f, 0.0f, 1.0f };
static const Ang_800890F4 lbl_8043950C = { 0, 0, 0 };

struct Scr_800890F4 { f32 x, y; };

struct Def_800890F4 {
    u8 pad0[0x64];
    f32 sx;
    f32 sy;
    u8 pad6C[0x88 - 0x6C];
    u8 flags;
};

struct Part_800890F4 {
    u8 pad0[0x1C];
    u16 tex;
    u8 pad1E[0x20 - 0x1E];
    Def_800890F4 *def;
    u16 flags;
    u8 pad26[0x28 - 0x26];
    f32 w;
    f32 h;
    u8 pad30[0x6C - 0x30];
    u8 f6C[4];
    Vec_800890F4 pos;
    Vec_800890F4 ofs;
    f32 sw;
    f32 sh;
    u8 pad90[0x96 - 0x90];
    s16 angle;
    u8 pad98[0x9C - 0x98];
    s32 rotY;
    u8 padA0[0xA4 - 0xA0];
    f32 scx;
    f32 scy;
    u8 padAC[0xB0 - 0xAC];
    u32 model;
    u32 texlist;
    u32 motion;
    f32 frame;
    u8 padC0[0xC4 - 0xC0];
    Vec_800890F4 vel;
};

extern "C" {
void *alloc_particle_memory(int);
void queue_destruction__7TObjectFv(void *arg0);
f32 vec_squared_length(u8 *arg0);
extern s32 TParticleCtrl__data_8048E778[];
s32 rand(void);
s32 rotate_matrix_y(s32, s32);
void project_world_to_screen(int, void *, void *);
s32 push_matrix(f32);
s32 post_translate_matrix(void *);
void rotate_vector_by_current_matrix(void *, void *);
extern ParticleTexture *TParticleCtrl__data_80511F70[];
s32 is_particle_sprite_additive__13TUnk_8048E728Fv(void *, s32);
s32 append_node_to_tail__13TParticleCtrlFPvPv(s32, void *);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 draw_ginja_object(u32);
s32 draw_ginja_model_with_motion(u32, u32, f32);
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
f32 vector_length(void *);
void restore_saved_depth_alpha_state();
f32 vec3_dot(void *, void *);
void __ct__7TObjectFP7TObject(void *, void *);
}
void setup_particle_tev(s32 arg0);
void load_projected_texture_matrix(f32 farg0);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
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

u8 *create_ballistic_particle(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u16 arg4, s16 arg5) {
    u8 *temp_r3;
    u8 *var_r0;
    temp_r3 = (u8 *)(((u8 *)alloc_particle_memory(0xD0)));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(construct_ballistic_particle(temp_r3, arg0, arg1, arg2, arg3, arg4, arg5));
    }
    return var_r0;
}
void *TParticleCtrl::create_random_spread(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = alloc_particle_memory(0xd0);
    if (o != NULL) {
        o = ((TUnk_8048E778 *)o)->init_particle_random_spread(arg0, arg1, arg2);
    }
    return o;
}
void TUnk_8048E778::retire_ballistic_particle_if_done() {
    u8 *arg0 = (u8 *)this;
    Stack_80088844 stack;
    if (*(u8 *)((s8 *)this->param + 0x88) & 8) {
        stack.sp8 = this->pos.x - this->origin.x;
        stack.spC = this->pos.y - *(f32 *)((s8 *)arg0 + 0x34);
        stack.sp10 = this->pos.z - this->origin.z;
        if (0.0f == vec_squared_length((u8 *)&stack.sp8)) {
            queue_destruction__7TObjectFv((arg0));
            return;
        }
    }
    if (this->age >= 1.0f) {
        queue_destruction__7TObjectFv((arg0));
    }
}

#pragma push
#pragma fp_contract on
void TUnk_8048E778::run_task() {
    NJS_COLOR col;
    Vec toward_camera;
    ParticleParam *p;
    f32 t[2]; // [0] age this frame, [1] fade alpha
    f32 fade_in;
    f32 fade_out;
    f32 ch[3];
    f32 tilt;
    s32 frames;

    if (param->flags & 8) {
        if (age >= 0.5f) {
            approach_camera_vector(&pos, &origin, fabs_float(step.y));
        } else {
            vec3_add_to(&pos, &step);
            VecCopy(&velocity, &step);
        }
    } else {
        if (flags & 2) {
            push_matrix_from(&identity_matrix);
            rotate_matrix_x(0, unk_98);
            rotate_matrix_y(0, m_9c);
            rotate_matrix_z(0, unk_A0);
            rotate_vector_by_current_matrix(&step, &velocity);
            pop_matrix();
        } else if (unk_98 == 0 && m_9c == 0 && unk_A0 == 0) {
            VecCopy(&velocity, &step);
        } else {
            push_matrix_from(&identity_matrix);
            rotate_matrix_z(0, unk_A0);
            rotate_matrix_x(0, unk_98);
            rotate_matrix_y(0, m_9c);
            rotate_vector_by_current_matrix(&step, &velocity);
            pop_matrix();
        }
        vec3_add_to(&pos, &velocity);
    }
    p = param;
    if ((p->flags & 2) && origin.y > pos.y) {
        step.y = p->unk_60 * (p->unk_3C * (3.0517578e-05f * rand()) + p->unk_34);
    }
    step.x *= param->speed_decay;
    step.z *= param->speed_decay;
    step.y += param->gravity;
    m_28 *= param->scale_decay;
    unk_2C *= param->scale_decay;
    age += age_rate;
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
    if (TParticleCtrl__data_80511F70[sprite_index]->sprites->flags & 1) {
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
    } else {
        if (flags & 0x100) {
            ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + color_base[0]);
            ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + color_base[1]);
            ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + color_base[2]);
        } else {
            ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + p->color_base[0]);
            ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + p->color_base[1]);
            ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + p->color_base[2]);
        }
    }
    col.argb.a = 254.0f * t[1];
    col.argb.r = 254.0f * ch[0];
    col.argb.g = 254.0f * ch[1];
    col.argb.b = 254.0f * ch[2];
    color = col.color;
    p = param;
    if (0.0f == p->gravity && 0.0f == p->unk_34 && 0.0f == p->unk_30) {
        m_96 += (s32)(182.04445f * p->unk_60);
    } else if (!(p->flags & 4)) {
        tilt = step.y * (p->unk_64 * step.x);
        if (fabs_float(tilt) > 20.0f) {
            tilt = 20.0f;
        }
        if (speed < 0.0f) {
            m_96 += (s32)(182.04445f * tilt);
        } else {
            m_96 -= (s32)(182.04445f * tilt);
        }
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
    if (flags & 0x10) {
        TObjCollidable *target_obj = find_entity_by_id(target_id);
        if (target_obj == NULL) {
            queue_destruction();
            return;
        }
        Vec *center = (Vec *)target_obj->get_center();
        if (center != NULL) {
            if (flags & 0x20) {
                offset_point_toward_camera((u8 *)center, (u8 *)&toward_camera, 8.0f);
                attach.x = toward_camera.x - origin.x;
                attach.y = toward_camera.y - origin.y;
                attach.z = toward_camera.z - origin.z;
            } else {
                attach.x = center->x - origin.x;
                attach.y = center->y - origin.y;
                attach.z = center->z - origin.z;
            }
        }
    }
    motion_frame += unk_C0;
    if (motion != NULL && (f32)(motion->nbFrame - 1) <= motion_frame) {
        motion_frame = motion->nbFrame - 1;
    }
    retire_ballistic_particle_if_done();
}
#pragma pop

void TUnk_8048E778::render() {
    Part_800890F4 *p = (Part_800890F4 *)this;
    u16 flags;
    int id;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0) {
        return;
    }
    if (p->def->flags & 4) {
        Vec_800890F4 b;
        Vec_800890F4 a;
        Scr_800890F4 s0;
        Scr_800890F4 s1;
        f32 len;
        if (p->flags & 0x10) {
            a.x = p->pos.x + p->ofs.x;
            a.y = p->pos.y + p->ofs.y;
            a.z = p->pos.z + p->ofs.z;
        } else {
            VecCopy((Vec *)&a, (const Vec *)&p->pos);
        }
        b.x = a.x + p->vel.x;
        b.y = a.y + p->vel.y;
        b.z = a.z + p->vel.z;
        len = vector_length(&p->vel);
        project_world_to_screen(0, &a, &s0);
        project_world_to_screen(0, &b, &s1);
        s1.x -= s0.x;
        s1.y -= s0.y;
        p->angle = 10430.38043493439 * atan2_float(s1.y, s1.x);
        p->sw = p->def->sx * len;
        p->sh = p->def->sy * len;
    } else if (p->def->flags & 0x40) {
        Vec_800890F4 a = lbl_804394E8;
        Vec_800890F4 b = lbl_804394F4;
        Vec_800890F4 c = lbl_80439500;
        f32 d1;
        f32 d2;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, p->rotY);
        rotate_vector_by_current_matrix(&c, &c);
        pop_matrix();
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, *(s32 *)(camera_ctrl_instance + 0x194));
        rotate_vector_by_current_matrix(&a, &a);
        pop_matrix();
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, *(s32 *)(camera_ctrl_instance + 0x190));
        rotate_vector_by_current_matrix(&b, &b);
        pop_matrix();
        d1 = vec3_dot(&c, &a);
        d2 = vec3_dot(&c, &b);
        if (d2 < 0.0f) {
            d2 *= -1.0f;
        }
        if (d1 < 0.0f) {
            d1 *= -1.0f;
        }
        flags = p->flags;
        if (flags & 8) {
            p->sw = p->w;
            p->sh = p->h * d2;
        } else if (flags & 4) {
            p->sw = p->w * d1;
            p->sh = p->h;
        } else {
            p->sw = p->w * d1;
            p->sh = p->h * d2;
        }
    } else {
        p->sw = p->w;
        p->sh = p->h;
    }
    p->sw *= p->scx;
    p->sh *= p->scy;
    flags = p->flags;
    if (flags & 0x200) {
        Vec_800890F4 t;
        if (is_split_screen() != 0 && (p->flags & 0x400)) {
            return;
        }
        if (p->texlist == 0) {
            return;
        }
        if (p->model == 0) {
            return;
        }
        t.x = p->pos.x + p->ofs.x;
        t.y = p->pos.y + p->ofs.y;
        t.z = p->pos.z + p->ofs.z;
        Ang_800890F4 r = lbl_8043950C;
        direction_to_rotation_xz((u8 *)&p->vel, &r.x, &r.z);
        ((s32 (*)())push_matrix)();
        post_translate_matrix(&t);
        scale_matrix(0, p->sw, p->sw, p->sw);
        rotate_matrix_z(0, r.z);
        rotate_matrix_x(0, r.x);
        if (p->flags & 0x1000) {
            if (camera_ctrl_instance != NULL) {
                rotate_matrix_y(0, *(s32 *)(camera_ctrl_instance + 0x194));
            }
        } else {
            rotate_matrix_y(0, r.y);
            rotate_matrix_y(0, p->angle);
        }
        if (p->flags & 0x400) {
            load_projected_texture_matrix(1.33f);
        }
        TParticleCtrl::begin_effect_render();
        if (p->flags & 0x400) {
            setup_particle_tev(0);
        } else {
            s32 st = model_render_flags;
            saved_model_render_flags = st;
            model_render_flags = st | 0x8021;
            if (is_particle_sprite_additive__13TUnk_8048E728Fv(p, st) != 0) {
                ((TUnk_8048E728 *)p)->apply_particle_model_fade_color(1);
            } else {
                ((TUnk_8048E728 *)p)->apply_particle_model_fade_color(0);
            }
        }
        TObjFish::set_global_param(p->texlist);
        set_draw_list_mask(3);
        if (p->motion != 0) {
            draw_ginja_model_with_motion(p->model, p->motion, p->frame);
        } else {
            draw_ginja_object(p->model);
        }
        if (p->flags & 0x400) {
            reset_particle_tev();
        } else {
            model_render_flags = saved_model_render_flags;
        }
        restore_draw_list_mask();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    } else if (flags & 0x2000) {
        ((TUnk_8048E728 *)p)->draw_particle_refraction_quad();
    } else if (flags & 0x800) {
        if (p->def->flags & 0x20) {
            id = p->tex + 0x36;
        } else {
            id = p->tex;
        }
        set_depth_buffer_settings_2();
        ((TUnk_8048E778 *)p)->draw_sprite_quad(id);
        restore_saved_depth_alpha_state();
    } else if (p->def->flags & 0x20) {
        id = p->tex + 0x36;
        append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)&TParticleCtrl__data_80511F70)[id], p->f6C);
    } else {
        append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)&TParticleCtrl__data_80511F70)[p->tex], p->f6C);
    }
}

void *__dt__13TUnk_8048E778Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = TParticleCtrl__data_8048E778;
        __dt__13TUnk_8048E728Fv((u8 *)arg0, 0);
        if (arg1 > 0) {
            ((TUnk_8048E728 *)arg0)->free_from_heap();
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
u8 *construct_ballistic_particle(void *a0, void *a1, void *a2, void *a3, s32 arg4, u16 arg5, s16 arg6) {
    Fields0_800896E4 *p = (Fields0_800896E4 *)a0;
    Fields1_800896E4 *d = (Fields1_800896E4 *)a1;
    Fields2_800896E4 *pos = (Fields2_800896E4 *)a2;
    Fields3_800896E4 *c = (Fields3_800896E4 *)a3;
    s32 temp_r0;
    f32 *v;
    init_particle_base(a0, a1, arg4);
    p->field_18 = TParticleCtrl__data_8048E778;
    p->field_C4 = 0.0f;
    p->field_C8 = 0.0f;
    p->field_CC = 0.0f;
    p->field_24 = arg5;
    if (p->field_24 & 0x80) {
        p->field_95 = 1;
    }
    p->field_26 = arg6;
    p->field_98 = c->field_0;
    p->field_9C = c->field_4;
    p->field_A0 = c->field_8;
    p->field_70 = (d->field_18 * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + pos->field_0;
    p->field_78 = (d->field_20 * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + pos->field_8;
    if (d->field_88 & 2) {
        p->field_74 = pos->field_4 + d->field_1C;
    } else {
        p->field_74 = (d->field_1C * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + pos->field_4;
    }
    p->field_30 = pos->field_0;
    p->field_38 = pos->field_8;
    if (d->field_88 & 2) {
        p->field_34 = pos->field_4;
    } else {
        p->field_34 = pos->field_4;
    }
    p->field_28 = (d->field_28 * (3.0517578e-05f * (f32)rand())) + d->field_24;
    p->field_2C = p->field_28;
    temp_r0 = (s32)(((f32)d->field_4C * (3.0517578e-05f * (f32)rand())) + (f32)d->field_48);
    if (d->field_88 & 1) {
        p->field_5C = 1.0f / (f32)((s32 **)(((void **)&TParticleCtrl__data_80511F70)[p->field_1C]))[0x28 / 4][0xC / 4];
    } else {
        p->field_5C = 1.0f / (f32)temp_r0;
    }
    p->field_3C = (d->field_38 * (3.0517578e-05f * (f32)rand())) + d->field_30;
    p->field_40 = (d->field_3C * (3.0517578e-05f * (f32)rand())) + d->field_34;
    v = &p->field_3C;
    p->field_44 = 0.0f;
    rotate_vec_xz(v, v, (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()))));
    if (0.0f == d->field_54 && 0.0f == d->field_34 && 0.0f == d->field_30) {
        p->field_96 = 0;
        p->field_68 = 0.0f;
    } else {
        p->field_96 = (s16)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
        p->field_68 = (3.0517578e-05f * (f32)rand()) - 0.5f;
    }
    if (p->field_24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
    return (u8 *)a0;
}
#pragma pop

struct RecoveredGlobal_8008C21C_TParticleCtrl__data_80511F70;
struct BF0_80089B50 {
    u8 pad_0[0x18]; s32 *field_18; u16 field_1C; u8 pad_1E[6]; u16 field_24; s16 field_26;
    f32 field_28; f32 field_2C; f32 field_30; f32 field_34; f32 field_38; f32 field_3C; f32 field_40; f32 field_44;
    u8 pad_48[0x14]; f32 field_5C; u8 pad_60[8]; f32 field_68; u8 pad_6C[4]; f32 field_70; f32 field_74; f32 field_78;
    u8 pad_7C[0x19]; s8 field_95; s16 field_96; s32 field_98; s32 field_9C; s32 field_A0;
    u8 pad_A4[0x20]; f32 field_C4; f32 field_C8; f32 field_CC;
};
struct BF1_80089B50 {
    u8 pad_0[0x18]; f32 field_18; f32 field_1C; f32 field_20; f32 field_24; f32 field_28; u8 pad_2C[4];
    f32 field_30; f32 field_34; f32 field_38; f32 field_3C; u8 pad_40[8]; s32 field_48; s32 field_4C;
    u8 pad_50[4]; f32 field_54; u8 pad_58[0x30]; u8 field_88;
};
struct BF2_80089B50 { f32 field_0; f32 field_4; f32 field_8; };

#pragma push
#pragma fp_contract on
void *TUnk_8048E778::init_particle_random_spread(void *a1, void *a2, void *a3) {
    BF0_80089B50 *p = (BF0_80089B50 *)this;
    BF1_80089B50 *d = (BF1_80089B50 *)a1;
    BF2_80089B50 *pos = (BF2_80089B50 *)a2;
    s32 temp_r0;
    f32 *v;
    init_particle_base(this, a1, (s32)a3);
    p->field_18 = TParticleCtrl__data_8048E778;
    p->field_C4 = 0.0f;
    p->field_C8 = 0.0f;
    p->field_CC = 0.0f;
    p->field_70 = (d->field_18 * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + pos->field_0;
    p->field_78 = (d->field_20 * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + pos->field_8;
    if (d->field_88 & 2) {
        p->field_74 = pos->field_4 + d->field_1C;
    } else {
        p->field_74 = (d->field_1C * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + pos->field_4;
    }
    p->field_30 = pos->field_0;
    p->field_38 = pos->field_8;
    if (d->field_88 & 2) {
        p->field_34 = pos->field_4;
    } else {
        p->field_34 = pos->field_4;
    }
    p->field_28 = (d->field_28 * (3.0517578e-05f * (f32)rand())) + d->field_24;
    p->field_2C = p->field_28;
    temp_r0 = (s32)(((f32)d->field_4C * (3.0517578e-05f * (f32)rand())) + (f32)d->field_48);
    if (d->field_88 & 1) {
        p->field_5C = 1.0f / (f32)((s32 **)(((void **)&TParticleCtrl__data_80511F70)[p->field_1C]))[0x28 / 4][0xC / 4];
    } else {
        p->field_5C = 1.0f / (f32)temp_r0;
    }
    p->field_3C = (d->field_38 * (3.0517578e-05f * (f32)rand())) + d->field_30;
    p->field_40 = (d->field_3C * (3.0517578e-05f * (f32)rand())) + d->field_34;
    v = &p->field_3C;
    p->field_44 = 0.0f;
    rotate_vec_xz(v, v, (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()))));
    if (0.0f == d->field_54 && 0.0f == d->field_34 && 0.0f == d->field_30) {
        p->field_96 = 0;
        p->field_68 = 0.0f;
    } else {
        p->field_96 = (s16)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
        p->field_68 = (3.0517578e-05f * (f32)rand()) - 0.5f;
    }
    if (p->field_24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
    return this;
}
#pragma pop
