#include "pso/TParticleCtrl.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_8048E778.h"
#include "pso/misc/TUnk_8048E790.h"
#include "pso/misc/TUnk_8048E728.h"
#include "pso/misc/TUnk_8048E7A8.h"

#include "types.h"
#include "pso/misc/TParticleCtrl_80327D30.h"
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

struct RecoveredGlobal_8008C21C_TParticleCtrl__data_8048E7A8 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8008C21C_TParticleCtrl__data_80511F70 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_8008BF58_TParticleCtrl__data_8048E7A8 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8008BF58_TParticleCtrl__data_80511F70 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Vec_8008BAF8 { f32 x, y, z; };

struct Ang_8008BAF8 { s32 x, y, z; };

struct Scr_8008BAF8 { f32 x, y; };

extern "C" {
void *alloc_particle_memory(int);
void queue_destruction__7TObjectFv(void *arg0);
f32 vec_squared_length(u8 *arg0);
u8 *__dt__13TUnk_8048E728Fv(u8 *arg0, s16 arg1);
u8 *create_radial_particle(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, s16 arg4);
void *__dt__13TUnk_8048E7A8Fv(void *arg0, s16 arg1);
void TKeyBoardControl__sub_8000F91C(s32 arg0);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
void destroy_keyboard_objects(void * _w0);
s32 rand(void);
s32 is_split_screen();
s32 is_particle_sprite_additive__13TUnk_8048E728Fv(void *, s32);
s32 append_node_to_tail__13TParticleCtrlFPvPv(s32, void *);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 push_matrix(f32);
s32 pop_matrix();
s32 post_translate_matrix(void *);
s32 draw_ginja_object(u32);
s32 draw_ginja_model_with_motion(u32, u32, f32);
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
f32 atan2_float(f32, f32);
f32 vector_length(void *);
void project_world_to_screen(s32, void *, void *);
extern const Ang_8008BAF8 radial_particle_zero_angles;
extern const f64 lbl_80439560[];
extern const f32 lbl_805D9564;
void __ct__7TObjectFP7TObject(void *, void *);
}
void * create_random_particle(void *arg0, void *arg1, void *arg2);
extern const f32 TParticleCtrl__data_805D9558;
extern const f32 TParticleCtrl__data_805D955C;
extern s32 TParticleCtrl__data_8048E7A8[];
void stop_cue_stream(void);
void *init_particle_base(void *arg0, void *arg1, s32 arg2);
extern RecoveredGlobal_8008C21C_TParticleCtrl__data_80511F70 TParticleCtrl__data_80511F70;
extern const f32 lbl_805D9568;
extern const f32 lbl_805D956C;
u8 *construct_radial_particle(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u16 arg4, s16 arg5);
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

#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

void clear_active_flag__13TParticleCtrlFv(void* p);

void clear_active_flag__13TParticleCtrlFv(void* p) { *(u16*)((char*)p + 0x2c) &= 0xfffe; }
u8 *create_radial_particle(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, s16 arg4) {
    u8 *particle_memory;
    u8 *var_r0;
    particle_memory = (u8 *)(((u8 *)alloc_particle_memory(0xC4)));
    var_r0 = particle_memory;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(construct_radial_particle(particle_memory, arg0, arg1, arg2, arg3, arg4));
    }
    return var_r0;
}
}
void * create_random_particle(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = alloc_particle_memory(0xc4);
    if (o != NULL) {
        o = ((TParticleCtrl *)o)->init_random_particle((u8 *)arg0, (u8 *)arg1, (s32)arg2);
    }
    return o;
}

void TUnk_8048E7A8::check_radial_particle_retire() {
    u8 *arg0 = (u8 *)this;
    if ((this->m_58 >= TParticleCtrl__data_805D9558) || (TParticleCtrl__data_805D955C == vec_squared_length((arg0 + 0x3C)))) {
        queue_destruction__7TObjectFv((arg0));
    }
}

void TUnk_8048E7A8::render() {
    u8 *arg0 = (u8 *)this;
    Scr_8008BAF8 s1;
    Scr_8008BAF8 s2;
    Vec_8008BAF8 end;
    Vec_8008BAF8 pos;
    f32 len;
    u16 flags;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0) {
        return;
    }
    if (*(u8 *)((s8 *)(*(u8 * *)&this->m_20) + 0x88) & 4) {
        if (*(u16 *)((s8 *)arg0 + 0x24) & 0x10) {
            pos.x = this->m_70 + *(f32 *)&this->unk_7C;
            pos.y = *(f32 *)&this->unk_74 + this->m_80;
            pos.z = this->m_78 + *(f32 *)&this->unk_84;
        } else {
            VecCopy((Vec *)&pos, (const Vec *)&this->m_70);
        }
        end.x = pos.x + this->m_3c;
        end.y = pos.y + *(f32 *)&this->unk_40;
        end.z = pos.z + this->m_44;
        len = vector_length((u8 *)&this->m_3c);
        if (TParticleCtrl__data_805D955C == len) {
            return;
        }
        project_world_to_screen(0, &pos, &s1);
        project_world_to_screen(0, &end, &s2);
        s2.x = s2.x - s1.x;
        s2.y = s2.y - s1.y;
        this->m_96 = (s16)(lbl_80439560[0] * atan2_float(s2.y, s2.x));
        this->m_88 = *(f32 *)((s8 *)(*(u8 * *)&this->m_20) + 0x60) * len;
        *(f32 *)((s8 *)arg0 + 0x8C) = *(f32 *)((s8 *)(*(u8 * *)&this->m_20) + 0x64) * len;
    } else {
        this->m_88 = this->m_28;
        *(f32 *)((s8 *)arg0 + 0x8C) = *(f32 *)&this->unk_2C;
    }
    this->m_88 = this->m_88 * this->m_a4;
    *(f32 *)((s8 *)arg0 + 0x8C) = *(f32 *)((s8 *)arg0 + 0x8C) * *(f32 *)((s8 *)arg0 + 0xA8);
    flags = *(u16 *)((s8 *)arg0 + 0x24);
    if (flags & 0x200) {
        if (((is_split_screen() == 0) || !(*(u16 *)((s8 *)arg0 + 0x24) & 0x400)) && (*(u32 *)&this->unk_B4 != 0U) && (this->m_b0 != 0U)) {
            Ang_8008BAF8 ang = radial_particle_zero_angles;
            Vec_8008BAF8 pos2;
            direction_to_rotation_xz((u8 *)&this->m_3c, &ang.x, &ang.z);
            if (*(u8 *)((s8 *)(*(u8 * *)&this->m_20) + 0x88) & 4) {
                pos2.x = this->m_70 + *(f32 *)&this->unk_7C;
                pos2.y = *(f32 *)&this->unk_74 + this->m_80;
                pos2.z = this->m_78 + *(f32 *)&this->unk_84;
            } else {
                VecCopy((Vec *)&pos2, (const Vec *)&this->m_70);
            }
            ((void (*)(void))push_matrix)();
            post_translate_matrix(&pos2);
            scale_matrix(0, this->m_88, this->m_88, this->m_88);
            if (*(u8 *)((s8 *)(*(u8 * *)&this->m_20) + 0x88) & 4) {
                rotate_matrix_z(0, ang.z);
                rotate_matrix_x(0, ang.x);
                rotate_matrix_y(0, ang.y);
            }
            if ((*(u16 *)((s8 *)arg0 + 0x24) & 0x1000) && (camera_ctrl_instance != NULL)) {
                rotate_matrix_y(0, *(s32 *)((s8 *)camera_ctrl_instance + 0x194));
            }
            TParticleCtrl::begin_effect_render();
            if (*(u16 *)((s8 *)arg0 + 0x24) & 0x400) {
                load_projected_texture_matrix(lbl_805D9564);
            }
            rotate_matrix_y(0, this->m_96);
            if (*(u16 *)((s8 *)arg0 + 0x24) & 0x400) {
                setup_particle_tev(0);
            } else {
                s32 temp_r4 = model_render_flags;
                saved_model_render_flags = temp_r4;
                model_render_flags = temp_r4 | 0x8021;
                if (is_particle_sprite_additive__13TUnk_8048E728Fv(arg0, temp_r4) != 0) {
                    ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(1);
                } else {
                    ((TUnk_8048E728 *)arg0)->apply_particle_model_fade_color(0);
                }
            }
            TObjFish::set_global_param(*(u32 *)&this->unk_B4);
            set_depth_buffer_settings_id(3);
            if (this->m_b8 != 0U) {
                draw_ginja_model_with_motion(this->m_b0, this->m_b8, *(f32 *)&this->unk_BC);
            } else {
                draw_ginja_object(this->m_b0);
            }
            if (*(u16 *)((s8 *)arg0 + 0x24) & 0x400) {
                TParticleCtrl::disable_if_single_screen();
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
        if (*(u8 *)((s8 *)this->m_20 + 0x88) & 0x20) {
            append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)((u8 *)&TParticleCtrl__data_80511F70 + 0xD8))[*(u16 *)((s8 *)arg0 + 0x1C)], arg0 + 0x6C);
            return;
        }
        append_node_to_tail__13TParticleCtrlFPvPv(((s32 *)&TParticleCtrl__data_80511F70)[*(u16 *)((s8 *)arg0 + 0x1C)], arg0 + 0x6C);
    }
}

void *__dt__13TUnk_8048E7A8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = TParticleCtrl__data_8048E7A8;
        __dt__13TUnk_8048E728Fv((u8 *)arg0, 0);
        if (arg1 > 0) {
            ((TUnk_8048E728 *)arg0)->free_from_heap();
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8008C21C_TParticleCtrl__data_8048E7A8_size[sizeof(RecoveredGlobal_8008C21C_TParticleCtrl__data_8048E7A8) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8008C21C_TParticleCtrl__data_80511F70_size[sizeof(RecoveredGlobal_8008C21C_TParticleCtrl__data_80511F70) == 0x1B0 ? 1 : -1];

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8008BF58_TParticleCtrl__data_8048E7A8_size[sizeof(RecoveredGlobal_8008BF58_TParticleCtrl__data_8048E7A8) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8008BF58_TParticleCtrl__data_80511F70_size[sizeof(RecoveredGlobal_8008BF58_TParticleCtrl__data_80511F70) == 0x1B0 ? 1 : -1];
u8 *construct_radial_particle(u8 *object, u8 *arg1, u8 *arg2, s32 arg3, u16 arg4, s16 arg5) {
    struct Fields_arg0 { u8 pad_0[24]; s32 * field_18; u16 field_1C; u8 pad_1E[6]; u16 field_24; s16 field_26; f32 field_28; f32 field_2C; f32 field_30; f32 field_34; f32 field_38; f32 field_3C; f32 field_40; f32 field_44; u8 pad_48[20]; f32 field_5C; u8 pad_60[8]; f32 field_68; u8 pad_6C[4]; f32 field_70; f32 field_74; f32 field_78; u8 pad_7C[25]; s8 field_95; };
    struct Fields_arg1 { u8 pad_0[24]; f32 field_18; f32 field_1C; f32 field_20; f32 field_24; f32 field_28; u8 pad_2C[4]; f32 field_30; u8 pad_34[4]; f32 field_38; u8 pad_3C[12]; s32 field_48; s32 field_4C; u8 pad_50[56]; u8 field_88; };
    struct Fields_arg2 { f32 field_0; f32 field_4; f32 field_8; };
    s32 temp_r0;
    init_particle_base(object, arg1, arg3);
    ((Fields_arg0*)object)->field_18 = &(*(RecoveredGlobal_8008BF58_TParticleCtrl__data_8048E7A8 *)&TParticleCtrl__data_8048E7A8).value;
    ((Fields_arg0*)object)->field_70 = (f32) ((((Fields_arg1*)arg1)->field_18 * ((lbl_805D9568 * (f32) rand()) - lbl_805D956C)) + ((Fields_arg2*)arg2)->field_0);
    ((Fields_arg0*)object)->field_74 = (f32) ((((Fields_arg1*)arg1)->field_1C * ((lbl_805D9568 * (f32) rand()) - lbl_805D956C)) + ((Fields_arg2*)arg2)->field_4);
    ((Fields_arg0*)object)->field_78 = (f32) ((((Fields_arg1*)arg1)->field_20 * ((lbl_805D9568 * (f32) rand()) - lbl_805D956C)) + ((Fields_arg2*)arg2)->field_8);
    ((Fields_arg0*)object)->field_24 = arg4;
    if (((Fields_arg0*)object)->field_24 & 0x80) {
        ((Fields_arg0*)object)->field_95 = 1;
    }
    ((Fields_arg0*)object)->field_26 = arg5;
    ((Fields_arg0*)object)->field_30 = (f32) ((Fields_arg2*)arg2)->field_0;
    ((Fields_arg0*)object)->field_34 = (f32) ((Fields_arg2*)arg2)->field_4;
    ((Fields_arg0*)object)->field_38 = (f32) ((Fields_arg2*)arg2)->field_8;
    ((Fields_arg0*)object)->field_28 = (f32) ((((Fields_arg1*)arg1)->field_28 * (lbl_805D9568 * (f32) rand())) + ((Fields_arg1*)arg1)->field_24);
    ((Fields_arg0*)object)->field_2C = (f32) ((Fields_arg0*)object)->field_28;
    temp_r0 = (s32) (((f32) ((Fields_arg1*)arg1)->field_4C * (lbl_805D9568 * (f32) rand())) + (f32) ((Fields_arg1*)arg1)->field_48);
    if (((Fields_arg1*)arg1)->field_88 & 1) {
        ((Fields_arg0*)object)->field_5C = (f32) (TParticleCtrl__data_805D9558 / (f32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_8008BF58_TParticleCtrl__data_80511F70 *)&TParticleCtrl__data_80511F70).value) + (((Fields_arg0*)object)->field_1C * 4))) + 0x28)) + 0xC));
    } else {
        ((Fields_arg0*)object)->field_5C = (f32) (TParticleCtrl__data_805D9558 / (f32) temp_r0);
    }
    ((Fields_arg0*)object)->field_68 = (f32) ((((Fields_arg1*)arg1)->field_38 * (lbl_805D9568 * (f32) rand())) + ((Fields_arg1*)arg1)->field_30);
    ((Fields_arg0*)object)->field_3C = (f32) TParticleCtrl__data_805D955C;
    ((Fields_arg0*)object)->field_40 = (f32) TParticleCtrl__data_805D955C;
    ((Fields_arg0*)object)->field_44 = (f32) TParticleCtrl__data_805D955C;
    if (((Fields_arg0*)object)->field_24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
    return object;
}
#pragma pop

u8 *TParticleCtrl::init_random_particle(u8 *arg1, u8 *arg2, s32 arg3) {
    struct Fields_arg0 { u8 pad_0[24]; s32 * field_18; u16 field_1C; u8 pad_1E[6]; u16 field_24; u8 pad_26[2]; f32 field_28; f32 field_2C; f32 field_30; f32 field_34; f32 field_38; f32 field_3C; f32 field_40; f32 field_44; u8 pad_48[20]; f32 field_5C; u8 pad_60[8]; f32 field_68; u8 pad_6C[4]; f32 field_70; f32 field_74; f32 field_78; };
    struct Fields_arg1 { u8 pad_0[24]; f32 field_18; f32 field_1C; f32 field_20; f32 field_24; f32 field_28; u8 pad_2C[4]; f32 field_30; u8 pad_34[4]; f32 field_38; u8 pad_3C[12]; s32 field_48; s32 field_4C; u8 pad_50[56]; u8 field_88; };
    struct Fields_arg2 { f32 field_0; f32 field_4; f32 field_8; };
    s32 temp_r0;
    init_particle_base(this, arg1, arg3);
    ((Fields_arg0*)((u8 *)this))->field_18 = &(*(RecoveredGlobal_8008C21C_TParticleCtrl__data_8048E7A8 *)&TParticleCtrl__data_8048E7A8).value;
    ((Fields_arg0*)((u8 *)this))->field_70 = (f32) ((((Fields_arg1*)arg1)->field_18 * ((lbl_805D9568 * (f32) rand()) - lbl_805D956C)) + ((Fields_arg2*)arg2)->field_0);
    ((Fields_arg0*)((u8 *)this))->field_74 = (f32) ((((Fields_arg1*)arg1)->field_1C * ((lbl_805D9568 * (f32) rand()) - lbl_805D956C)) + ((Fields_arg2*)arg2)->field_4);
    ((Fields_arg0*)((u8 *)this))->field_78 = (f32) ((((Fields_arg1*)arg1)->field_20 * ((lbl_805D9568 * (f32) rand()) - lbl_805D956C)) + ((Fields_arg2*)arg2)->field_8);
    ((Fields_arg0*)((u8 *)this))->field_30 = (f32) ((Fields_arg2*)arg2)->field_0;
    ((Fields_arg0*)((u8 *)this))->field_34 = (f32) ((Fields_arg2*)arg2)->field_4;
    ((Fields_arg0*)((u8 *)this))->field_38 = (f32) ((Fields_arg2*)arg2)->field_8;
    ((Fields_arg0*)((u8 *)this))->field_28 = (f32) ((((Fields_arg1*)arg1)->field_28 * (lbl_805D9568 * (f32) rand())) + ((Fields_arg1*)arg1)->field_24);
    ((Fields_arg0*)((u8 *)this))->field_2C = (f32) ((Fields_arg0*)((u8 *)this))->field_28;
    temp_r0 = (s32) (((f32) ((Fields_arg1*)arg1)->field_4C * (lbl_805D9568 * (f32) rand())) + (f32) ((Fields_arg1*)arg1)->field_48);
    if (((Fields_arg1*)arg1)->field_88 & 1) {
        ((Fields_arg0*)((u8 *)this))->field_5C = (f32) (TParticleCtrl__data_805D9558 / (f32) *(s32 *)((s8 *)(*(void **)((s8 *)(*(s32 *)((s8 *)&TParticleCtrl__data_80511F70.value + (((Fields_arg0*)((u8 *)this))->field_1C * 4))) + 0x28)) + 0xC));
    } else {
        ((Fields_arg0*)((u8 *)this))->field_5C = (f32) (TParticleCtrl__data_805D9558 / (f32) temp_r0);
    }
    ((Fields_arg0*)((u8 *)this))->field_68 = (f32) ((((Fields_arg1*)arg1)->field_38 * (lbl_805D9568 * (f32) rand())) + ((Fields_arg1*)arg1)->field_30);
    ((Fields_arg0*)((u8 *)this))->field_3C = (f32) TParticleCtrl__data_805D955C;
    ((Fields_arg0*)((u8 *)this))->field_40 = (f32) TParticleCtrl__data_805D955C;
    ((Fields_arg0*)((u8 *)this))->field_44 = (f32) TParticleCtrl__data_805D955C;
    if (((Fields_arg0*)((u8 *)this))->field_24 & 0x2000) {
        request_indirect_effect(0x1F);
    }
    return ((u8 *)this);
}
#pragma pop

void destroy_keyboard_objects(void * _w0) { queue_destruction__7TObjectFv((_w0)); TKeyBoardControl__sub_8000F91C(2); TKeyBoardControl__sub_8000F9CC(18); TLobby::stop_audio_streams(); stop_cue_stream(); }
