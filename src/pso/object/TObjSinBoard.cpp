#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/TMainTask.h"
#include "pso/unk/text_80198A2C.h"
#include "pso/unk/text_80235A8C.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804B8DD0.h"
#include "pso/misc/TWindowTimer.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TWindowTimer_80198814.h"
#include "pso/unk/text_80198960.h"
#include "pso/unk/TUnk_804B8DE8.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLanguage.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/unk/TUnk_804B8E18.h"
#include "pso/unk/TUnk_804B8E00.h"
#include <stddef.h>

struct RecoveredGlobal_801982D4_lbl_804B8DAC { s32 value; u8 remaining[0x20]; };
typedef char RecoveredGlobal_801982D4_lbl_804B8DAC_size[sizeof(RecoveredGlobal_801982D4_lbl_804B8DAC) == 0x24 ? 1 : -1];

struct RecoveredGlobal_80198228___vt__12TObjSinBoard {
    s32 value;
    u8 remaining[0x34];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pos_8019806C { u32 w[12]; };

struct Uv_8019806C { u32 w[4]; };

struct Desc_8019806C { Pos_8019806C *pos; Uv_8019806C *uv; s16 *col; s32 count; };

struct Vec_80198504 { f32 x, y, z; };

extern "C" {
s32 get_bml_model(void *, s32);
s32 draw_chunk_object(s32);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern s32 lobby_gvm_texture_handles[];
extern s32 gogo_ball_bml_resource;
s32 __ct__13TUnk_804B9870FP7TObject(void *, void *);
extern s32 __vt__12TObjSinBoard[];
extern s32 TObjSinBoard__class_name;
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_x(int, int);
extern Pos_8019806C TObjSinBoard__quad_position_table;
extern Uv_8019806C sin_board_uv_table;
extern u8 signboard_texture_list[];
extern u32 TObjSinBoard__texture_buffer;
struct Vec_80198E84;
extern Vec_80198E84 gogo_ball_sync_state[];
s32 play_sound_effect(int, void *, int, int);
void *__nw__7TObjectFUl(s32);
struct Sys_80198A2C;
extern Sys_80198A2C gogo_ball_configuration;

void __dl__7TObjectFPv(void *);

void TObjSinBoard::render() {
    u8 *arg0 = (u8 *)this;
    Pos_8019806C pos;
    Uv_8019806C uv;
    Desc_8019806C d;
    s16 col[8];
    if (TMainTask::get_render_pass() != 1 && TObjSinBoard__texture_buffer != 0) {
        pos = TObjSinBoard__quad_position_table;
        uv = sin_board_uv_table;
        col[0] = 0;
        col[1] = 0;
        col[2] = 0;
        col[3] = 0xFF;
        col[4] = 0xFF;
        col[5] = 0xFF;
        col[6] = 0xFF;
        col[7] = 0;
        d.pos = &pos;
        d.uv = &uv;
        d.col = col;
        d.count = 4;
        TObjPlayer::reset_transform_state();
        TObjFish::set_global_param((int) signboard_texture_list);
        set_texture_num(0);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        translate_matrix(0, *(f32 *)(arg0 + 0x38), *(f32 *)(arg0 + 0x3C), *(f32 *)(arg0 + 0x40));
        rotate_matrix_z(0, *(s32 *)(arg0 + 0x64));
        rotate_matrix_x(0, *(s32 *)(arg0 + 0x5C));
        rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
        scale_matrix(0, *(f32 *)(arg0 + 0x68), *(f32 *)(arg0 + 0x6C), *(f32 *)(arg0 + 0x70));
        ((TObjPlayer *)(&d))->draw_tri_fan_3d(4, 0xE);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjSinBoard::run_task() {  }

void *__dt__12TObjSinBoardFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjSinBoard;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80198228___vt__12TObjSinBoard_size[sizeof(RecoveredGlobal_80198228___vt__12TObjSinBoard) == 0x38 ? 1 : -1];
u8 *TObjSinBoard__ct(u8 *sin_board, s32 parent, s32 arg2) {
    __ct__13TUnk_804B9870FP7TObject((void *)sin_board, (void *)parent);
    *(s32 **)((s8 *)sin_board + 0x18) = &(*(RecoveredGlobal_80198228___vt__12TObjSinBoard *)&__vt__12TObjSinBoard).value;
    *(s32 *)((s8 *)sin_board + 0) = (s32) TObjSinBoard__class_name;
    ((TObjSinBoard *)(sin_board))->apply_object_set_data((void *)arg2);
    return sin_board;
}

void *TObjSinBoard__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x90);
    if (o != NULL) {
        o = TObjSinBoard__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}
void TUnk_804B8DD0::render() {
    u8 *bml_model;
    if ((s32) *(s32 *)&this->unk_3C != 0) {
        this->m_38 = (this->m_38 + 0x38E);
        if ((s32) this->m_38 >= 0x4000) {
            this->m_38 = 0x4000;
        }
    } else {
        this->m_38 = (this->m_38 - 0x38E);
        if ((s32) this->m_38 <= 0) {
            this->m_38 = 0;
        }
    }
    bml_model = (u8 *)(get_bml_model((void *)gogo_ball_bml_resource, 1));
    if (bml_model != NULL) {
        if ((s32) this->m_28 != 0) {
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)lobby_gvm_texture_handles + 0x1C)));
        } else {
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)lobby_gvm_texture_handles + 0x20)));
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->unk_1C);
        ::draw_ginja_model((*(s32 *)((s8 *)bml_model + 4)));
        push_matrix();
        ::draw_ginja_model((*(s32 *)((s8 *)(*(u8 **)((s8 *)bml_model + 0x2C)) + 4)));
        pop_matrix();
        push_matrix();
        rotate_matrix_z(0, this->m_38);
        rotate_matrix_y(0, 0x8000);
        ::draw_ginja_model((*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)bml_model + 0x2C)) + 0x30)) + 4)));
        pop_matrix();
        push_matrix();
        rotate_matrix_z(0, (int) (-this->m_38));
        ::draw_ginja_model((*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)bml_model + 0x2C)) + 0x30)) + 0x30)) + 4)));
        pop_matrix();
        pop_matrix();
    }
}
void TUnk_804B8DD0::run_task() {
    s32 t;
    if (this->m_28 != 0) {
        if (*(s16 *)((s8 *)&gogo_ball_sync_state + 0x10) & (this->m_40 != 0 ? 0x10 : 1)) {
            *(s32 *)&this->unk_3C = 1;
            update_effects();
        } else {
            *(s32 *)&this->unk_3C = 0;
            this->m_30 = 0;
        }
    } else {
        if (*(s16 *)((s8 *)&gogo_ball_sync_state + 0x10) & (this->m_40 != 0 ? 0x20 : 2)) {
            *(s32 *)&this->unk_3C = 1;
            update_effects();
        } else {
            *(s32 *)&this->unk_3C = 0;
            this->m_30 = 0;
        }
    }
    t = *(s32 *)&this->unk_2C;
    *(s32 *)&this->unk_2C = t + 1;
    if (t >= *(s32 *)&this->unk_34) {
        queue_destruction__7TObjectFv(this);
    }
}
void TUnk_804B8DD0::update_effects() {
    Vec_80198504 v6;
    Vec_80198504 v2a;
    Vec_80198504 v2b;
    Vec_80198504 vda;
    Vec_80198504 vdb;
    void *o;
    if (*(u16 *)((s8 *)&gogo_ball_configuration + 0x48) == 0) {
        (this->m_30)++;
        if (this->m_30 == 1) {
            o = (void *)__nw__7TObjectFUl(0x58);
            if (o != NULL) {
                TWindowTimer__sub_80198CF8((u8 *)o, (u8 *)&this->unk_1C, (s32)(*(s16 *)((s8 *)&gogo_ball_configuration + 0x14)), (s32)this->m_28, (s32)this->m_40, (u8 *)tl_06);
            }
        }
    } else if (*(u16 *)((s8 *)&gogo_ball_configuration + 0x48) == 6) {
        (this->m_30)++;
        if (this->m_30 % 5 == 0 && this->m_30 <= 0x1E) {
            VecCopy((Vec *)&v6, (const Vec *)&this->unk_1C);
            v6.y += 7.0f;
            spawn_particle_effect_with_flags(&v6, 0x20D, 0x40);
            play_sound_effect(0x4001A82E, (u8 *)&this->unk_1C, 0, 0);
        }
    } else if (*(u16 *)((s8 *)&gogo_ball_configuration + 0x48) == 2) {
        (this->m_30)++;
        if (this->m_28 != 0) {
            if (this->m_30 == 1) {
                TCameraCtrl::set_shake_preset(2);
                VecCopy((Vec *)&v2a, (const Vec *)&this->unk_1C);
                v2a.y += 7.0f;
                spawn_particle_effect_with_flags(&v2a, 0x45, 0x40);
                spawn_particle_effect_with_flags(&v2a, 0x189, 0x40);
                play_sound_effect(0x4001C112, (u8 *)&this->unk_1C, 0, 0);
            }
        } else {
            if (this->m_30 == 1) {
                TCameraCtrl::set_shake_preset(2);
                VecCopy((Vec *)&v2b, (const Vec *)&this->unk_1C);
                v2b.y += 7.0f;
                spawn_particle_effect_with_flags(&v2b, 0x45, 0x40);
                spawn_particle_effect_with_flags(&v2b, 0x189, 0x40);
                play_sound_effect(0x4001C112, (u8 *)&this->unk_1C, 0, 0);
            }
        }
    } else if (*(u16 *)((s8 *)&gogo_ball_configuration + 0x48) != 0) {
        (this->m_30)++;
        if (this->m_28 != 0) {
            if (this->m_30 % 5 == 0 && this->m_30 <= 0x32) {
                VecCopy((Vec *)&vda, (const Vec *)&this->unk_1C);
                vda.y += 7.0f;
                spawn_particle_effect_with_flags(&vda, 0x20E, 0x40);
                o = (void *)__nw__7TObjectFUl(0x28);
                if (o != NULL) {
                    construct_timed_sound_voice((u8 *)o, (s32)&this->unk_1C, (s16)(5), 0x4002A90C, 0, (s32)tl_05);
                }
            }
        } else {
            if (this->m_30 % 5 == 0 && this->m_30 <= 0x32) {
                VecCopy((Vec *)&vdb, (const Vec *)&this->unk_1C);
                vdb.y += 7.0f;
                spawn_particle_effect_with_flags(&vdb, 0x20F, 0x40);
                o = (void *)__nw__7TObjectFUl(0x28);
                if (o != NULL) {
                    construct_timed_sound_voice((u8 *)o, (s32)&this->unk_1C, (s16)(5), 0x4002A90C, 0, (s32)tl_05);
                }
            }
        }
    }
}

}

struct RecoveredGlobal_8019886C_lbl_804B8DD0 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801988E8_lbl_804B8DD0 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_804B8DD0[];
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void *__dt__13TUnk_804B8DD0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804B8DD0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8019886C_lbl_804B8DD0_size[sizeof(RecoveredGlobal_8019886C_lbl_804B8DD0) == 0x18 ? 1 : -1];
u8 *TWindowTimer__sub_8019886C(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5) {
    __ct__7TObjectFP7TObject(arg0, arg5);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8019886C_lbl_804B8DD0 *)&lbl_804B8DD0).value;
    VecCopy((Vec *)(arg0 + 0x1C), (const Vec *)arg1);
    ((TUnk_804B8DD0 *)arg0)->m_28 = arg2;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = arg4;
    ((TUnk_804B8DD0 *)arg0)->m_38 = 0;
    ((TUnk_804B8DD0 *)arg0)->m_30 = 0;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    ((TUnk_804B8DD0 *)arg0)->m_40 = arg3;
    return arg0;
}
typedef char RecoveredGlobal_801988E8_lbl_804B8DD0_size[sizeof(RecoveredGlobal_801988E8_lbl_804B8DD0) == 0x18 ? 1 : -1];
u8 *TWindowTimer__sub_801988E8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, u8 *arg4) {
    __ct__7TObjectFP7TObject(arg0, arg4);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801988E8_lbl_804B8DD0 *)&lbl_804B8DD0).value;
    VecCopy((Vec *)(arg0 + 0x1C), (const Vec *)arg1);
    ((TUnk_804B8DD0 *)arg0)->m_28 = arg2;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = arg3;
    ((TUnk_804B8DD0 *)arg0)->m_38 = 0;
    ((TUnk_804B8DD0 *)arg0)->m_30 = 0;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    ((TUnk_804B8DD0 *)arg0)->m_40 = 0;
    return arg0;
}

}

struct RecoveredGlobal_80198960_lbl_804B8DAC {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_80198960_lbl_8050DD58 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);

typedef char RecoveredGlobal_80198960_lbl_804B8DAC_size[sizeof(RecoveredGlobal_80198960_lbl_804B8DAC) == 0x24 ? 1 : -1];
typedef char RecoveredGlobal_80198960_lbl_8050DD58_size[sizeof(RecoveredGlobal_80198960_lbl_8050DD58) == 0x54 ? 1 : -1];
void TUnk_804B8DE8::render() {
    if ((((u32) gogo_ball_bml_resource != 0U) || ((u32) *(u32 *)((s8 *)lobby_gvm_texture_handles + 0x10) != 0U)) && ((u16) *(u16 *)((s8 *)&gogo_ball_configuration + 0x48) != 6)) {
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x50) == 1) {
            TObjFish::set_global_param((int) (*(u32 *)((s8 *)lobby_gvm_texture_handles + 0x10)));
        } else {
            TObjFish::set_global_param((int) (*(u32 *)((s8 *)lobby_gvm_texture_handles + 0x14)));
        }
        push_matrix();
        post_translate_matrix(((u8 *)this) + 0x1C);
        rotate_matrix_y(0, this->m_34);
        scale_matrix(0, 1.5f, 1.5f, 1.5f);
        draw_chunk_object(get_bml_model((void *)gogo_ball_bml_resource, 4));
        pop_matrix();
    }
}

}

struct Obj_8019978C;
struct Pair_80198F14;
struct RecoveredGlobal_80198DCC_lbl_8050E208;
struct Vec_80199674;
struct Vec_8019978C;
extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
extern Sys_80198A2C gogo_ball_configuration;
extern Vec_80198E84 gogo_ball_sync_state[];
void TWindowTimer__sub_8019A6F8(void*);
extern RecoveredGlobal_80198DCC_lbl_8050E208 controller_input_state;
u8* TWindowTimer__sub_80199410(u8*,u8*);
void __dl__7TObjectFPv(void*);
void* __nw__7TObjectFUl(s32);
extern s32 gogo_ball_bml_resource;
extern void* language_lobby_texture_descriptor[];
extern Pair_80198F14 gogo_ball_team_scores[];
void bswap_6x79_gogo_ball__12TWindowTimerFi(s32);
s32 rotate_matrix_y(int, int);
void TObjPlayer__sub_801994DC(s32,void*,void*,s32,void*,f32);
int TWindowTimer__sub_8019A770(void*);
f32 xyz_distance(Vec_80199674*,void*);
f32 vector_length(Vec_8019978C*);
void normalize_vector(Vec_8019978C*);
s32 reflect_velocity_off_collision__13TUnk_804B8E18FPvPv(Obj_8019978C*,Vec_8019978C*,Vec_8019978C*);
}
void draw_shadow_on_ground(u8*);
extern void* lbl_804B8D94[];
extern void* lbl_804B8DA0[];

struct Vec_80198A2C { f32 x, y, z; };

struct Obj_80198A2C {
    u8 pad0[0x1C];
    Vec_80198A2C pos;
    u8 pad28[0x34 - 0x28];
    s32 rot;
    u8 pad38[0x3C - 0x38];
    void *effect;
    s32 timer;
    s32 counter;
    s32 limit;
    s32 state;
    s32 f50;
    s32 f54;
};

struct Pad_80198A2C { u8 pad0[0x10]; s16 buttons; };

struct Sys_80198A2C { u8 pad0[0x48]; u16 mode; };

extern "C" {
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
void *spawn_particle_effect(void *pos, s32 id);
s32 play_sound_effect(int, void *, int, int);
extern Vec_80198A2C boss3_volopt_init_vec;
#pragma push
#pragma fp_contract on
void TUnk_804B8DE8::run_task() {
    Obj_80198A2C *self = (Obj_80198A2C *)this;
    s32 state;
    if (this->m_44++ >= self->limit) {
        spawn_particle_effect_with_flags(&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->pos, 0x46, 0x40);
        queue_destruction__7TObjectFv(self);
        return;
    }
    state = this->m_4c;
    if (state == 0) {
        if (self->f50 != 0) {
            if ((*(Pad_80198A2C *)&gogo_ball_sync_state).buttons & (this->m_54 != 0 ? 0x10 : 1)) {
                play_sound_effect(0x4002A605, &self->pos, 0, 0);
                play_sound_effect(0x40052D15, &self->pos, 0, 0);
                this->m_4c = 1;
                return;
            }
        } else {
            if ((*(Pad_80198A2C *)&gogo_ball_sync_state).buttons & (this->m_54 != 0 ? 0x20 : 2)) {
                play_sound_effect(0x4002A605, &self->pos, 0, 0);
                play_sound_effect(0x40052D15, &self->pos, 0, 0);
                this->m_4c = 1;
                return;
            }
        }
    }
    if (state != 0) {
        if (self->effect == NULL) {
            Vec_80198A2C init = boss3_volopt_init_vec;
            if (gogo_ball_configuration.mode != 6) {
                self->effect = spawn_particle_effect_with_rotation(&self->pos, &init, 0xC0, 2);
            }
        }
        if (self->timer++ >= 1000) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        this->m_34 += 0x16C;
        if (self->timer <= 0x14) {
            Vec_80198A2C v;
            VecCopy((Vec *)&v, (const Vec *)&self->pos);
            v.y += (18.0f);
            spawn_particle_effect(&v, 0x1DB);
        }
        self->pos.y = (0.001f) * (f32)(self->timer * self->timer) + self->pos.y;
        if (self->effect != NULL) {
            ((TNowLoading *)(self->effect))->copy_pos(&self->pos);
        }
    }
}
#pragma pop

}

struct Stack_80198DCC {
    s32 sp8;
    s32 spC;
    s32 sp10;
    f32 sp14;
    f32 sp18;
    s8 sp1C;
    u8 trailing_storage[0x3];
};

struct RecoveredGlobal_80198DCC_lbl_8050E208 { s32 value; u8 remaining[0x1AC]; };
typedef char RecoveredGlobal_80198DCC_lbl_8050E208_size[sizeof(RecoveredGlobal_80198DCC_lbl_8050E208) == 0x1B0 ? 1 : -1];

struct RecoveredGlobal_80198CF8_lbl_804B8DE8 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 is_on_current_screen__11TCameraCtrlFv(void *, int);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_804B8DE8[];
u8 *TWindowTimer__sub_80198CF8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5);
void *__dt__13TUnk_804B8DE8Fv(void *arg0, s16 arg1);
void TWindowTimer__sub_80198D98(void);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void * __nw__7TObjectFUl(s32);

void *__dt__13TUnk_804B8DE8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804B8DE8;
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3C)); ((TUnk_804B8DE8 *)arg0)->m_3c = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80198CF8_lbl_804B8DE8_size[sizeof(RecoveredGlobal_80198CF8_lbl_804B8DE8) == 0x18 ? 1 : -1];
u8 *TWindowTimer__sub_80198CF8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5) {
    __ct__7TObjectFP7TObject(arg0, arg5);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80198CF8_lbl_804B8DE8 *)&lbl_804B8DE8).value;
    VecCopy((Vec *)(arg0 + 0x1C), (const Vec *)arg1);
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(arg0 + 0x1C));
    ((TUnk_804B8DE8 *)arg0)->m_20 = (f32) (((TUnk_804B8DE8 *)arg0)->m_20 - (16.0f));
    ((TUnk_804B8DE8 *)arg0)->m_3c = 0;
    ((TUnk_804B8DE8 *)arg0)->m_34 = 0;
    *(s32 *)((s8 *)arg0 + 0x38) = 0;
    *(s32 *)((s8 *)arg0 + 0x48) = arg2;
    ((TUnk_804B8DE8 *)arg0)->m_44 = 0;
    *(s32 *)((s8 *)arg0 + 0x40) = 0;
    *(s32 *)((s8 *)arg0 + 0x50) = arg3;
    ((TUnk_804B8DE8 *)arg0)->m_54 = arg4;
    ((TUnk_804B8DE8 *)arg0)->m_4c = 0;
    return arg0;
}

void TWindowTimer__sub_80198D98(void) {
    void *obj = __nw__7TObjectFUl(0x20);
    if (obj != 0) {
        TWindowTimer__sub_80199410((u8 *)obj, (u8 *)tl_03);
    }
}
void TWindowTimer::throw_gogo_ball(s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_80198DCC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80198DCC, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80198DCC, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80198DCC, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_80198DCC, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_80198DCC, sp1C) == 0x14) ? 1 : -1];
    Stack_80198DCC stack;
    TWindowTimer__sub_8019A6F8((&stack.sp8));
    stack.spC = arg2;
    stack.sp10 = arg1;
    stack.sp14 = *(f32 *)((s8 *)((u8 *)this) + 0);
    stack.sp18 = *(f32 *)((s8 *)((u8 *)this) + 8);
    if (is_on_current_screen__11TCameraCtrlFv((void *) ((u8 *)&controller_input_state.value + 0x20), 4) != 0) {
        play_sound_effect(0x4001A311, this, 0, 0);
        stack.sp1C = 1;
    } else {
        play_sound_effect(0x4002A600, this, 0, 0);
        stack.sp1C = 0;
    }
    ((TWindowTimer *)((s32)&stack.sp8))->send_gogo_ball();
}

}

struct Vec_80198E84 { f32 x; f32 y; f32 z; s32 w; u8 pad10[2]; s16 f12; };

extern "C" {
void TLobby__sub_8001FE7C(s32, int, void *, f32);
extern s32 lobby_gvm_texture_handles[];
void fn_80198E84(void);
void fn_80198E84(void) {
    s32 off;
    s32 i;
    s32 z;
    gogo_ball_sync_state->f12 = 1;
    gogo_ball_sync_state->x = (63.0f);
    gogo_ball_sync_state->y = (0.0f);
    gogo_ball_sync_state->z = (63.0f);
    gogo_ball_sync_state->w = 0;
    TLobby__sub_8001FE7C(gogo_ball_bml_resource, 1, gogo_ball_sync_state, (63.0f));
    gogo_ball_bml_resource = 0;
    for (i = 0; i < 9; i++) {
        TObjPlayer::free_if_valid(lobby_gvm_texture_handles[i]);
        lobby_gvm_texture_handles[i] = 0;
    }
}

}

#define language_lobby_texture_descriptor (*(u8 (*)[1])&language_lobby_texture_descriptor)

struct Cfg_80198F14 { f32 f0; f32 f4; f32 f8; s32 fC; u8 pad10[2]; s16 f12; u8 pad14[4]; s8 f18; };

struct Pair_80198F14 { s32 a; s32 b; };

extern "C" {
void *load_resource_from_descriptor(void *, int, void *, int, int, int);
void *alloc__23TAdSinglePlyChrSelectGCFv(int);
u8 *load_gvm_texture_file(s32 arg0);
extern char lbl_80446088[];
extern char lbl_80446098[];
extern char lbl_804460A8[];
extern char lbl_804460B8[];
extern char lbl_804460C8[];
extern char lbl_804460E0[];
extern char lbl_804460FC[];
extern char lbl_8044610C[];
extern char lbl_80446124[];
void TLanguage::load_lobby_textures() {
    Pair_80198F14 *p = gogo_ball_team_scores;
    Cfg_80198F14 *c = &(*(Cfg_80198F14 *)&gogo_ball_sync_state);
    void *obj;
    c->f12 = 1;
    c->f0 = (63.0f);
    c->f4 = (0.0f);
    c->f8 = (63.0f);
    c->fC = 0;
    c->f18 = 0;
    p->a = 0;
    p->b = 0;
    obj = alloc__23TAdSinglePlyChrSelectGCFv(0x440);
    if (obj != 0) {
        obj = load_resource_from_descriptor(obj, 5, language_lobby_texture_descriptor, 0, 0, 0);
    }
    (*(void**)&gogo_ball_bml_resource) = obj;
    lobby_gvm_texture_handles[0] = (s32)load_gvm_texture_file((s32)lbl_80446088);
    lobby_gvm_texture_handles[1] = (s32)load_gvm_texture_file((s32)lbl_80446098);
    lobby_gvm_texture_handles[2] = (s32)load_gvm_texture_file((s32)lbl_804460A8);
    lobby_gvm_texture_handles[3] = (s32)load_gvm_texture_file((s32)lbl_804460B8);
    lobby_gvm_texture_handles[4] = (s32)load_gvm_texture_file((s32)lbl_804460C8);
    lobby_gvm_texture_handles[5] = (s32)load_gvm_texture_file((s32)lbl_804460E0);
    lobby_gvm_texture_handles[6] = (s32)load_gvm_texture_file((s32)lbl_804460FC);
    lobby_gvm_texture_handles[7] = (s32)load_gvm_texture_file((s32)lbl_8044610C);
    lobby_gvm_texture_handles[8] = (s32)load_gvm_texture_file((s32)lbl_80446124);
}

}

#undef language_lobby_texture_descriptor
#define gogo_ball_configuration (*(u8 (*)[1])&gogo_ball_configuration)
#define controller_input_state (*(s32 (*)[1])&controller_input_state)
#define __nw__7TObjectFUl ((void* (*)(int))__nw__7TObjectFUl)
#define bswap_6x79_gogo_ball__12TWindowTimerFi ((s32 (*)(void))bswap_6x79_gogo_ball__12TWindowTimerFi)
#define TWindowTimer__sub_8019A770 ((void (*)(void))TWindowTimer__sub_8019A770)

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct RecoveredGlobal_80199410_lbl_804B8E00 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80199410_lbl_804B8E00_size[sizeof(RecoveredGlobal_80199410_lbl_804B8E00) == 0x18 ? 1 : -1];

struct RecoveredGlobal_80199470_lbl_8050DDAC {
    s32 value;
    u8 remaining[0x18];
};

struct G_80199078 { u8 pad[0x10]; s16 flags; };

struct Fx_801994DC {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    s32 f;
    u32 g;
    void *h;
};

struct Col_801994DC { f32 r, g, b, a; };

struct Ang_801994DC { s32 x, y, z; };

extern s32 lbl_804B8E00[];
extern "C" {
u8 *TWindowTimer__sub_80199410(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern const f32 chunk_material_color_half_alpha_f32[];
extern u32 blob_shadow_texture_list;
void TObjPlayer__sub_801994DC(s32 arg0, void *arg1, void *arg2, s32 arg3, void *arg4, f32 farg0);

void TUnk_804B8E00::render() {
    (*(G_80199078 *)&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state)).flags &= ~1;
    (*(G_80199078 *)&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state)).flags &= ~2;
    (*(G_80199078 *)&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state)).flags &= ~0x10;
    (*(G_80199078 *)&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state)).flags &= ~0x20;
}

f32 fabs_float(f32);
u8 *TWindowTimer__sub_8019886C(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5);
u8 *TWindowTimer__sub_801988E8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, u8 *arg4);
u8 *TWindowTimer__sub_8019A574(u8 *arg0);
s32 TWindowShortListCtrl__check_controller_button(void *, int);

extern "C" u8 lbl_80445FF0[];
extern "C" u8 lbl_80446000[];
extern "C" u8 lbl_80446018[];
extern "C" u8 lbl_80446028[];
extern "C" u8 lbl_80446038[];
extern "C" u8 lbl_80446050[];
extern "C" u8 biri_ball_motion_names[];
void *lbl_804B8A10[210] = {
    (void *)0xbf000000, (void *)0x3f600000, (void *)0x0, (void *)0x40600000,
    (void *)0x40200000, (void *)0x8d480ff, (void *)0x0, (void *)0x41a00000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc3770000,
    (void *)0x0, (void *)0x0, (void *)0x43770000, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x60000, (void *)0x41000000,
    (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000, (void *)0x0,
    (void *)0x40600000, (void *)0x40200000, (void *)0x8d48000, (void *)0xff0000,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xc3770000, (void *)0x0, (void *)0x0, (void *)0x43770000,
    (void *)0x0, (void *)0x0, (void *)0x41f00000, (void *)0x20000,
    (void *)0x41000000, (void *)0x40400000, (void *)0xbdcccccd, (void *)0x3f000000,
    (void *)0x0, (void *)0x40133333, (void *)0x40133333, (void *)0x8d480ff,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0xc3770000, (void *)0x0, (void *)0x0,
    (void *)0x43770000, (void *)0x0, (void *)0x0, (void *)0x41f00000,
    (void *)0x30000, (void *)0x40400000, (void *)0x40600000, (void *)0xbf000000,
    (void *)0x3f600000, (void *)0x0, (void *)0x40600000, (void *)0x40200000,
    (void *)0x8d48000, (void *)0xff0000, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0xc3770000, (void *)0x0,
    (void *)0x0, (void *)0x43770000, (void *)0x0, (void *)0x0,
    (void *)0x41f00000, (void *)0x10000, (void *)0x41000000, (void *)0x40400000,
    (void *)0xbf000000, (void *)0x3f600000, (void *)0x0, (void *)0x40600000,
    (void *)0x40200000, (void *)0x8d480ff, (void *)0xff000000, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc3770000,
    (void *)0x0, (void *)0x0, (void *)0x43770000, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x60000, (void *)0x41000000,
    (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000, (void *)0x0,
    (void *)0x40600000, (void *)0x40200000, (void *)0x8d48000, (void *)0xff0000,
    (void *)0x41c80000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xc3770000, (void *)0x0, (void *)0x0, (void *)0x43770000,
    (void *)0x0, (void *)0x0, (void *)0x41f00000, (void *)0x0,
    (void *)0x41000000, (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000,
    (void *)0x0, (void *)0x40600000, (void *)0x40200000, (void *)0x8d480ff,
    (void *)0xff000000, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0xc3770000, (void *)0x0, (void *)0x0,
    (void *)0x43770000, (void *)0x0, (void *)0x0, (void *)0x41f00000,
    (void *)0x10000, (void *)0x41000000, (void *)0x40400000, (void *)0xbdcccccd,
    (void *)0x3f000000, (void *)0x0, (void *)0x40133333, (void *)0x40133333,
    (void *)0x8d480ff, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0xc3770000, (void *)0x0,
    (void *)0x0, (void *)0x43770000, (void *)0x0, (void *)0x0,
    (void *)0x41f00000, (void *)0x30000, (void *)0x40400000, (void *)0x40600000,
    (void *)0xbf000000, (void *)0x3f600000, (void *)0x0, (void *)0x40600000,
    (void *)0x40200000, (void *)0x8d480ff, (void *)0xff000000, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc3770000,
    (void *)0x0, (void *)0x0, (void *)0x43770000, (void *)0x0,
    (void *)0x0, (void *)0x41f00000, (void *)0x20000, (void *)0x41000000,
    (void *)0x40400000, (void *)0xbf000000, (void *)0x3f600000, (void *)0x0,
    (void *)0x40600000, (void *)0x40200000, (void *)0x8d480ff, (void *)0xff000000,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xc3770000, (void *)0x0, (void *)0x0, (void *)0x43770000,
    (void *)0x0, (void *)0x0, (void *)0x41f00000, (void *)0x0,
    (void *)0x41000000, (void *)0x40400000,
};
void *biri_ball_model_names[6] = {
    (void *)&lbl_80445FF0, (void *)&lbl_80446000, (void *)&lbl_80446018, (void *)&lbl_80446028,
    (void *)&lbl_80446038, (void *)0x0,
};
void *language_lobby_texture_descriptor[4] = {
    (void *)&lbl_80446050, (void *)&biri_ball_model_names, (void *)&biri_ball_motion_names, (void *)0x50000,
};
void *lbl_804B8D80[5] = {
    (void *)0x50005, (void *)0x0, (void *)0x0, (void *)0xff00ff,
    (void *)0x0,
};
void *lbl_804B8D94[3] = {
    (void *)0x43fa0000, (void *)0x41a00000, (void *)0x0,
};
void *lbl_804B8DA0[3] = {
    (void *)0xc3fa0000, (void *)0x41a00000, (void *)0x0,
};

struct E54_801990B4 { u8 b[0x54]; };

void TUnk_804B8E00::run_task() {
    u8 *pad;
    s32 m;
    s32 r;
    s32 idx;
    void *o;

    pad = (u8 *)controller_input_state + 0x20;
    if (is_on_current_screen__11TCameraCtrlFv(pad, 0x10000) != 0 && TWindowShortListCtrl__check_controller_button(pad, 0x400) != 0) {
        TWindowTimer::set_timer_value(1, 0);
        TWindowTimer::set_timer_value(0, 0);
    }
    if (TWindowTimer::get_timer_value(1) >= 999) {
        TWindowTimer::set_timer_value(1, 0);
    } else if (TWindowTimer::get_timer_value(0) >= 999) {
        TWindowTimer::set_timer_value(0, 0);
    }
    m = TLobby::get_internet_beat();
    r = (s32)fabs_float((f32)(m - *(s32 *)((s8 *)((u8 *)this) + 0x1C)));
    if (r == 1 || r == 999) {
        *(s16 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0x12) = 1;
        idx = m % 10;
        if (idx >= 10) {
            idx = 9;
        } else if (idx < 0) {
            idx = 0;
        }
        ((TWindowTimer *)gogo_ball_configuration)->copy_state(((E54_801990B4 *)lbl_804B8A10)[idx].b);
        if ((o = __nw__7TObjectFUl(0x3A4)) != NULL) {
            ((u8 *(*)(void *, void *))TWindowTimer__sub_8019A574)(o, (*(void**)&tl_03));
        }
        if ((o = __nw__7TObjectFUl(0x44)) != NULL) {
            TWindowTimer__sub_801988E8((u8 *)o, gogo_ball_configuration + 0x38, 1, *(s16 *)((s8 *)gogo_ball_configuration + 0x14), (u8 *)tl_04);
        }
        if ((o = __nw__7TObjectFUl(0x44)) != NULL) {
            TWindowTimer__sub_801988E8((u8 *)o, gogo_ball_configuration + 0x2C, 0, *(s16 *)((s8 *)gogo_ball_configuration + 0x14), (u8 *)tl_04);
        }
        if ((o = __nw__7TObjectFUl(0x44)) != NULL) {
            TWindowTimer__sub_8019886C((u8 *)o, (u8 *)lbl_804B8D94, 1, 1, (s32)(*(s16 *)((s8 *)gogo_ball_configuration + 0x14)), (u8 *)tl_04);
        }
        if ((o = __nw__7TObjectFUl(0x44)) != NULL) {
            TWindowTimer__sub_8019886C((u8 *)o, (u8 *)lbl_804B8DA0, 0, 1, (s32)(*(s16 *)((s8 *)gogo_ball_configuration + 0x14)), (u8 *)tl_04);
        }
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = m;
}

void TWindowTimer::copy_state(u8 *arg1) {
    *(f32 *)&this->m_name = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)&this->m_flags = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)&this->m_prev = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(f32 *)&this->m_next = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    *(f32 *)&this->m_up = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    *(s16 *)&this->m_down = (s16) *(s16 *)((s8 *)arg1 + 0x14);
    *(u8 *)((s8 *)((u8 *)this) + 0x16) = (u8) *(u8 *)((s8 *)arg1 + 0x16);
    *(u8 *)((s8 *)((u8 *)this) + 0x17) = (u8) *(u8 *)((s8 *)arg1 + 0x17);
    *(u8 *)((s8 *)((u8 *)this) + 0x18) = (u8) *(u8 *)((s8 *)arg1 + 0x18);
    *(u8 *)((s8 *)((u8 *)this) + 0x19) = (u8) *(u8 *)((s8 *)arg1 + 0x19);
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) *(f32 *)((s8 *)arg1 + 0x1C);
    *(ByteBlock_C *)((s32) ((u8 *)this) + 0x20) = *(const ByteBlock_C *)((s32) arg1 + 0x20);
    *(ByteBlock_C *)((s32) ((u8 *)this) + 0x2C) = *(const ByteBlock_C *)((s32) arg1 + 0x2C);
    *(ByteBlock_C *)((s32) ((u8 *)this) + 0x38) = *(const ByteBlock_C *)((s32) arg1 + 0x38);
    this->m_44 = (f32) *(f32 *)((s8 *)arg1 + 0x44);
    *(u16 *)((s8 *)((u8 *)this) + 0x48) = (u16) *(u16 *)((s8 *)arg1 + 0x48);
    this->m_4c = (f32) *(f32 *)((s8 *)arg1 + 0x4C);
    *(f32 *)((s8 *)((u8 *)this) + 0x50) = (f32) *(f32 *)((s8 *)arg1 + 0x50);
}

void *TUnk_804B8E00::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B8E00;
        TWindowTimer__sub_8019A770();
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
u8 *TWindowTimer__sub_80199410(u8 *object, u8 *arg1) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &(*(RecoveredGlobal_80199410_lbl_804B8E00 *)&lbl_804B8E00).value;
    *(s32 *)((s8 *)object + 0x1C) = TLobby::get_internet_beat();
    TWindowCtrl::create_timer();
    TWindowTimer::set_timer_value(1, 0);
    TWindowTimer::set_timer_value(0, 0);
    return object;
}
}
void handle_6x79_gogo_ball(u8 *arg0);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
typedef char RecoveredGlobal_80199470_lbl_8050DDAC_size[sizeof(RecoveredGlobal_80199470_lbl_8050DDAC) == 0x1C ? 1 : -1];
void handle_6x79_gogo_ball(u8 *arg0) {
    bswap_6x79_gogo_ball__12TWindowTimerFi();
    *(s16 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0x12) = 0;
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0) = (f32) *(f32 *)((s8 *)arg0 + 0xC);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 4) = (f32) (0.0f);
    *(f32 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 8) = (f32) *(f32 *)((s8 *)arg0 + 0x10);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0xC) = (s32) *(s32 *)((s8 *)arg0 + 8);
    *(u8 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0x18) = (u8) *(u8 *)((s8 *)arg0 + 0x14);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80199470_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0x14) = (s32) *(s32 *)((s8 *)arg0 + 4);
}
extern "C" {
void TObjPlayer__sub_801994DC(s32 arg0, void *arg1, void *arg2, s32 arg3, void *arg4, f32 farg0) {
    Ang_801994DC ang;
    Col_801994DC col;
    Fx_801994DC fx;
    if (blob_shadow_texture_list == 0) {
        return;
    }
    direction_to_rotation_xz((u8 *)arg2, &ang.x, &ang.z);
    push_matrix();
    post_translate_matrix(arg1);
    translate_matrix(0, 0.0f, 0.3f, 0.0f);
    rotate_matrix_z(0, ang.z);
    rotate_matrix_x(0, ang.x);
    rotate_matrix_y(0, arg3);
    if (arg4 != NULL) {
        scale_current_matrix(arg4);
    }
    rotate_matrix_x(0, -0x4000);
    fx.a = -5.0f;
    fx.b = 0.0f;
    fx.c = 0.0f;
    fx.d = 1.0f;
    fx.e = 1.0f;
    fx.f = 0;
    fx.g = blob_shadow_texture_list;
    fx.h = lbl_804B8D80;
    col.r = farg0;
    col.g = 1.0f;
    col.b = 1.0f;
    col.a = 1.0f;
    set_constant_material((const NJS_ARGB *)((&col)));
    TParticleCtrl::begin_effect_render();
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x22);
    fx.a = 0.0f;
    fx.b = 0.0f;
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x26);
    fx.a = -5.0f;
    fx.b = -5.0f;
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x2A);
    fx.a = 0.0f;
    fx.b = -5.0f;
    ((TObjPlayer *)(&fx))->draw_shadow_quad(0, 0x2E);
    TParticleCtrl::end_effect_render();
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    pop_matrix();
}

#undef gogo_ball_configuration
#undef controller_input_state
#undef __nw__7TObjectFUl
#undef bswap_6x79_gogo_ball__12TWindowTimerFi
#undef TWindowTimer__sub_8019A770
struct Vec_80199674 { f32 x, y, z; };
struct Seg_80199674 { Vec_80199674 a; Vec_80199674 b; };
struct Hit_80199674 { u32 f0; Seg_80199674 *seg; };

s32 *csnVectorUnder(s32 arg0, u32 *arg1, s32 arg2);
f32 xyz_distance(Vec_80199674 *, void *);
}
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];

#pragma push
#pragma fp_contract on
void draw_shadow_on_ground(u8 *arg0) {
    Hit_80199674 *hit;
    f32 t;
    f32 k;
    Vec_80199674 scale;

    hit = (Hit_80199674 *)csnVectorUnder((s32)(arg0 + 0x38), (u32 *)(arg0 + 0x120), 0x15);
    if (hit != 0) {
        Seg_80199674 *src = hit->seg;
        Seg_80199674 seg;
        seg.a.x = src->a.x;
        seg.a.y = src->a.y;
        seg.a.z = src->a.z;
        seg.b.x = src->b.x;
        seg.b.y = src->b.y;
        seg.b.z = src->b.z;
        t = 0.2f / (1.0f + xyz_distance(&seg.a, arg0 + 0x38));
        f32 s = 0.85f + t;
        scale.x = s;
        scale.y = s;
        scale.z = s;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        k = 2.0f * t + 0.5f;
        if (k >= 1.0f) {
            k = 1.0f;
        }
        TObjPlayer__sub_801994DC((s32)arg0, (void *)&seg.a, (void *)&seg.b, 0, (void *)&scale, (f32)k);
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
    }
}
#pragma pop

struct Vec_8019978C { f32 x, y, z; };

struct Tri_8019978C {
    Vec_8019978C p;
    Vec_8019978C n;
};

struct Hit_8019978C {
    u8 pad0[4];
    Tri_8019978C *tri;
};

struct Obj_8019978C {
    u8 pad0[0x340];
    f32 f340;
    u8 pad344[0x394 - 0x344];
    f32 f394;
};

extern "C" {
Hit_8019978C *csnVector(Vec_8019978C *, Vec_8019978C *, s32);
f32 vec3_dot(Vec_8019978C *, Vec_8019978C *);
f32 vector_length(Vec_8019978C *);
void normalize_vector(Vec_8019978C *);
s32 reflect_velocity_off_collision__13TUnk_804B8E18FPvPv(Obj_8019978C *o, Vec_8019978C *p, Vec_8019978C *v);
#pragma push
#pragma fp_contract on
s32 TUnk_804B8E18::reflect_velocity_off_collision(void *p, void *v) {
    Vec_8019978C end;
    Vec_8019978C dir;
    Vec_8019978C a;
    Vec_8019978C r;
    Vec_8019978C q;
    Vec_8019978C s;
    Hit_8019978C *hit;
    Tri_8019978C *tri;
    f32 len;
    f32 d;
    f32 px, py, pz, nx, ny, nz;
    end.x = ((Vec_8019978C *)p)->x + ((Vec_8019978C *)v)->x;
    end.y = ((Vec_8019978C *)p)->y + ((Vec_8019978C *)v)->y;
    end.z = ((Vec_8019978C *)p)->z + ((Vec_8019978C *)v)->z;
    VecCopy((Vec *)&dir, (const Vec *)((Vec_8019978C *)v));
    len = vector_length(&dir);
    if ((0.0f) != len) {
        normalize_vector(&dir);
        VecCopy((Vec *)&a, (const Vec *)((Vec_8019978C *)p));
        a.x -= (3.0f) * (dir.x * len);
        a.y -= (3.0f) * (dir.y * len);
        a.z -= (3.0f) * (dir.z * len);
    } else {
        return 0;
    }
    hit = csnVector(&a, &end, 0x17EF);
    if (hit != NULL) {
    tri = hit->tri;
    px = tri->p.x;
    py = tri->p.y;
    pz = tri->p.z;
    nx = tri->n.x;
    ny = tri->n.y;
    nz = tri->n.z;
    r.x = ((Vec_8019978C *)v)->x;
    r.y = ((Vec_8019978C *)v)->y;
    r.z = ((Vec_8019978C *)v)->z;
    d = (2.0f) * vec3_dot(&r, &tri->n);
    r.x -= d * nx;
    r.y -= d * ny;
    r.z -= d * nz;
    q.x = px - ((Vec_8019978C *)p)->x;
    q.z = pz - ((Vec_8019978C *)p)->z;
    q.y = (0.0f);
    vector_length(&q);
    ((Vec_8019978C *)v)->x = r.x * ((Obj_8019978C *)this)->f340;
    ((Vec_8019978C *)v)->z = r.z * ((Obj_8019978C *)this)->f340;
    normalize_vector(&r);
    ((Obj_8019978C *)this)->f394 *= ((Obj_8019978C *)this)->f340;
    ((Vec_8019978C *)v)->y = r.y * ((Obj_8019978C *)this)->f394;
    s.x = ((Vec_8019978C *)v)->x;
    s.z = ((Vec_8019978C *)v)->z;
    s.y = ((Obj_8019978C *)this)->f394;
    if (vector_length(&s) < (1.0f) - ((Obj_8019978C *)this)->f340) {
        ((Vec_8019978C *)v)->x = (0.0f);
        ((Vec_8019978C *)v)->y = (0.0f);
        ((Vec_8019978C *)v)->z = (0.0f);
    }
    ((Vec_8019978C *)p)->x += ((Vec_8019978C *)v)->x;
    ((Vec_8019978C *)p)->z += ((Vec_8019978C *)v)->z;
    ((Vec_8019978C *)p)->y = (0.001f) * r.y + py;
    return 1;
    }
    return 0;
}
#pragma pop

#define rotate_matrix_y ((s32 (*)(int,int))rotate_matrix_y)
#define vector_length ((f32 (*)(void*))vector_length)
#define normalize_vector ((s32 (*)(void*))normalize_vector)
#define draw_shadow_on_ground ((s32 (*)(void*))draw_shadow_on_ground)
struct Vec_80199A44 { f32 x, y, z; };
struct Color_80199A44 { f32 a, r, g, b; };
struct Glob_80199A44 { u8 pad[0x1C]; f32 scale; u8 pad20[0x28]; u16 kind; };

s32 get_bml_model(void *, s32);
}
void direction_to_rotation_yx(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 approach_angle_limited(int, int, int);
s32 matrix_mult_vec(int, void *, void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_about_axis(int, void *, int);
s32 translate_matrix_vec3(int, void *);
f32 vec_squared_length(void *);
s32 push_matrix_from(void *);
void set_chunk_material_override_pair(s32, s32);
s32 draw_chunk_object(s32);
extern Color_80199A44 fish_draw_color[];
extern u8 identity_matrix[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

#define F(t, o) (*(t *)(arg0 + (o)))

void draw_model__8TObjFishFPv(u8 *arg0) {
    Vec_80199A44 dir;
    Color_80199A44 color = fish_draw_color[0];
    Vec_80199A44 pos;
    f32 len;
    f32 rate;
    s32 step;

    VecCopy((Vec *)&pos, (const Vec *)(arg0 + 0x38));
    pos.y += (*(Glob_80199A44 *)&gogo_ball_configuration).scale - (2.0f * (*(Glob_80199A44 *)&gogo_ball_configuration).scale) / 10.0f;
    color.a = (F(s32, 0x358) != 0) ? 0.0f : -0.75f;
    VecCopy((Vec *)&dir, (const Vec *)(arg0 + 0x344));
    dir.y = 0.0f;
    len = vector_length(&dir);
    direction_to_rotation_yx((u8 *)&dir, (s32 *)(arg0 + 0x60), (s32 *)(arg0 + 0x64));
    F(s32, 0x334) = (u16)F(s32, 0x334);
    F(s32, 0x60) = (u16)F(s32, 0x60);
    if (0.0f != len) {
        normalize_vector(&dir);
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)&dir);
    } else {
        VecCopy((Vec *)&dir, (const Vec *)(arg0 + 0x44));
    }
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x4000);
    matrix_mult_vec(0, &dir, &dir);
    pop_matrices(1);
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x821;
    set_chunk_material_override_pair(-1, 0x800);
    rate = (s32)(182.04445f * (4096.0f * len));
    if (0.0f != rate) {
        step = rate;
        F(s32, 0x334) = approach_angle_limited(F(s32, 0x334), F(s32, 0x60), step);
        F(s32, 0x338) = approach_angle_limited(F(s32, 0x338), F(s32, 0x5C), step);
    }
    F(s32, 0x5C) += (s32)(182.04445f * (7.0f * len));
    push_matrix_from(0);
    translate_matrix_vec3(0, &pos);
    rate = 0.15f * (*(Glob_80199A44 *)&gogo_ball_configuration).scale;
    scale_matrix(0, rate, rate, rate);
    set_constant_material((const NJS_ARGB *)((&color)));
    if (vec_squared_length(&dir)) {
        rotate_matrix_about_axis(0, &dir, F(s32, 0x338));
    }
    rotate_matrix_y(0, F(s32, 0x334));
    if (lobby_gvm_texture_handles != 0 && (*(void**)&gogo_ball_bml_resource) != 0) {
        switch ((*(Glob_80199A44 *)&gogo_ball_configuration).kind) {
        case 0:
            TObjFish::set_global_param(lobby_gvm_texture_handles[0]);
            TObjFish::set_cull_back();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 3));
            TObjFish::set_cull_mode_front();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 3));
            TObjFish::set_cull_none();
            break;
        case 1:
            TObjFish::set_global_param(lobby_gvm_texture_handles[1]);
            TObjFish::set_cull_back();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 0));
            TObjFish::set_cull_mode_front();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 0));
            TObjFish::set_cull_none();
            break;
        case 2:
            TObjFish::set_global_param(lobby_gvm_texture_handles[2]);
            TObjFish::set_cull_back();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 0));
            TObjFish::set_cull_mode_front();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 0));
            TObjFish::set_cull_none();
            break;
        case 3:
            TObjFish::set_global_param(lobby_gvm_texture_handles[3]);
            TObjFish::set_cull_back();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 0));
            TObjFish::set_cull_mode_front();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 0));
            TObjFish::set_cull_none();
            break;
        case 6:
            TObjFish::set_global_param(lobby_gvm_texture_handles[6]);
            TObjFish::set_cull_back();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 2));
            TObjFish::set_cull_mode_front();
            draw_chunk_object(get_bml_model((*(void**)&gogo_ball_bml_resource), 2));
            TObjFish::set_cull_none();
            break;
        }
    }
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    pop_matrices(1);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
    draw_shadow_on_ground(arg0);
}
}

#undef rotate_matrix_y
#undef vector_length
#undef normalize_vector
#undef draw_shadow_on_ground
#define gogo_ball_sync_state (*(s32 (*)[1])&gogo_ball_sync_state)
#define __dl__7TObjectFPv ((s32 (*)(void*))__dl__7TObjectFPv)
#define gogo_ball_team_scores (*(int (*)[1])&gogo_ball_team_scores)
#define xyz_distance ((f32 (*)(void*,void*))xyz_distance)
#define vector_length ((f32 (*)(void*,f32))vector_length)
#define reflect_velocity_off_collision__13TUnk_804B8E18FPvPv ((s32 (*)(void*,void*,void*))reflect_velocity_off_collision__13TUnk_804B8E18FPvPv)

struct RecoveredGlobal_8019A574_lbl_804B8E18 {
    s32 value;
    u8 remaining[0x13C];
};

struct RecoveredGlobal_8019A574_lbl_8050DD58 {
    s32 value;
    u8 remaining[0x50];
};

struct RecoveredGlobal_8019A574_lbl_8050DDAC {
    s32 value;
    u8 remaining[0x18];
};

struct Pkt_8019A098 { u8 cmd; u8 size; u16 id; f32 x; f32 z; s32 flag; };

struct Player_8019A098 { u8 pad[0x60]; s32 area; };

struct Win_8019A44C { u8 pad0[0x50]; f32 f50[3]; u8 pad5C[0x2D8]; s32 f334; u8 pad338[0xC]; f32 f344; f32 f348; f32 f34C; u8 pad350[0x40]; f32 f390; f32 f394; f32 f398; f32 f39C; f32 f3A0; };

struct Vec_80199F14 { f32 x, y, z; };

struct Tbl_80199F14 { u8 pad[0x14]; s16 limit; u8 pad16[6]; f32 yofs; };

struct Timer_80199F14 {
    u8 pad0[0x38];
    Vec_80199F14 pos;
    u8 pad44[0x2f8];
    f32 f33c;
    u8 pad340[4];
    Vec_80199F14 vel;
    s32 time;
};

struct Vec_8019A104 { f32 x, y, z; };

struct Cfg_8019A104 { u8 pad0[0x1C]; f32 range; u8 pad20[0xC]; Vec_8019A104 p2C; Vec_8019A104 p38; f32 f44; u8 pad48[0xC]; };

struct State_8019A104 { u8 pad0[0x10]; s16 flags; u8 pad12[0xA]; };

struct Player_8019A104 { u8 pad0[0x38]; Vec_8019A104 pos; };

struct Timer_8019A104 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[4];
    Vec_8019A104 pos;
    u8 pad44[0x300];
    Vec_8019A104 vel;
    s32 time;
    u8 pad354[4];
    s32 f358;
    s32 f35C;
    s32 f360;
};

extern "C" {
s32 read_be16_field2__10TObjPlayerFv();
void bswap_6x79_gogo_ball__12TWindowTimerFi(s32 arg0);
void TWindowTimer__sub_8019A6F8(void* p);
int close_timer_window__11TWindowCtrlFv(void*);
int TWindowTimer__sub_8019A770(void* p);
u8 * __ct__13TUnk_804806E8FP7TObject(void *);
}
extern s32 lbl_804B8E18[];
void add_gogo_ball_three_point_score(s32 i);
void add_gogo_ball_one_point_score(s32 i);
void init_6x40_walk_packet(void *cmd);
extern "C" {
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
void TWindowTimer__sub_8019A098(void);
void rotate_vec_xz(void *, void *, s32);
s32 obj_getField1c(void *);
void vec3_add_to(void *, void *);
extern u8 lbl_8044613C[];
void update_motion__12TWindowTimerFPv(Timer_80199F14 *self);
f32 atan2_float(f32, f32);
extern u8 lbl_80446148[];
extern const f64 lbl_80446150[];

void TUnk_804B8E18::update_best_time() {
    if ((*(s16 *)((s8 *)gogo_ball_sync_state + 0x12) == 0) && ((s32) this->m_354 <= (s32) *(s32 *)((s8 *)gogo_ball_sync_state + 0x14))) {
        this->m_354 = (s32) *(s32 *)((s8 *)gogo_ball_sync_state + 0x14);
        *(f32 *)((s8 *)this + 0x38) = (f32) *(f32 *)((s8 *)gogo_ball_sync_state + 0);
        *(f32 *)((s8 *)this + 0x3C) = (f32) *(f32 *)((s8 *)gogo_ball_sync_state + 4);
        *(f32 *)((s8 *)this + 0x40) = (f32) *(f32 *)((s8 *)gogo_ball_sync_state + 8);
        sub_8019A44C((s32)(*(s32 *)((s8 *)gogo_ball_sync_state + 0xC)));
    }
    *(s16 *)((s8 *)gogo_ball_sync_state + 0x12) = 1;
}

void update_motion__12TWindowTimerFPv(Timer_80199F14 *self) {
    s32 i;
    Vec_80199F14 q;
    Vec_80199F14 p;
    i = 0;
    self->time = TLobby::get_clock_frames() % 2592;
    if (self->time >= ((Tbl_80199F14 *)&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration))->limit) {
        VecCopy((Vec *)&p, (const Vec *)&self->pos);
        p.y += ((Tbl_80199F14 *)&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration))->yofs;
        spawn_particle_effect_with_flags(&p, 0x45, 0x40);
        spawn_particle_effect_with_flags(&p, 0x46, 0x40);
        TWindowCtrl::open((s32)(obj_getField1c(self)), (s32)lbl_8044613C, 0x1B);
        queue_destruction__7TObjectFv(self);
        return;
    }
    ((TUnk_804B8E18 *)self)->update_goal_checks(local_client_id);
    ((TUnk_804B8E18 *)self)->update_best_time();
    if (self->pos.y <= (-5e+02f)) {
        queue_destruction__7TObjectFv(self);
    }
    VecCopy((Vec *)&q, (const Vec *)&self->pos);
    self->vel.y += self->f33c;
    vec3_add_to(&self->pos, &self->vel);
    for (;;) {
        if (i++ >= 3 || reflect_velocity_off_collision__13TUnk_804B8E18FPvPv(self, &q, &self->vel) == 0) {
            break;
        }
        VecCopy((Vec *)&self->pos, (const Vec *)&q);
        q.x += self->vel.x;
        q.y += self->vel.y;
        q.z += self->vel.z;
    }
}

void TWindowTimer__sub_8019A098(void) {
    Pkt_8019A098 pkt;
    f32 x;
    f32 z;
    Player_8019A098 *p;
    init_6x40_walk_packet(&pkt);
    p = (Player_8019A098 *)get_player_by_client_id(local_client_id);
    if (p != 0) {
        pkt.id = local_client_id;
        ((TObjPlayer *)p)->calc_movement_target(p->area, &x, &z);
        pkt.x = x;
        pkt.z = z;
        pkt.flag = 0;
        ((TNpcPlayer *)(&pkt))->sync_from_lobby();
    }
}

#define CFG (*(Cfg_8019A104 *)&gogo_ball_configuration)
#define ST (*(State_8019A104 *)gogo_ball_sync_state)
extern const char lbl_805DBF94[] = "Go!";
void TUnk_804B8E18::update_goal_checks(u16 id) {
    Timer_8019A104 *self;
    Player_8019A104 *p;
    f32 len;
    s32 ang;
    p = (Player_8019A104 *)get_player_by_client_id(id);
    self = (Timer_8019A104 *)this;
    if (p == NULL) {
        return;
    }
    if (xyz_distance(&CFG.p2C, &self->pos) <= CFG.f44 && (0.0f) == ((f32 (*)(void *))vector_length)(&self->vel)) {
        ST.flags |= 2;
        if (self->f360 == 0) {
            add_gogo_ball_one_point_score(1);
            self->f360 = 1;
        }
    }
    if (xyz_distance(&CFG.p38, &self->pos) <= CFG.f44 && (0.0f) == ((f32 (*)(void *))vector_length)(&self->vel)) {
        ST.flags |= 1;
        if (self->f360 == 0) {
            add_gogo_ball_one_point_score(0);
            self->f360 = 1;
        }
    }
    if (xyz_distance(&(*(Vec_8019A104 *)&lbl_804B8D94), &self->pos) <= CFG.f44 && (0.0f) == ((f32 (*)(void *))vector_length)(&self->vel)) {
        ST.flags |= 0x10;
        if (self->f360 == 0) {
            add_gogo_ball_three_point_score(0);
            self->f360 = 1;
        }
    }
    if (xyz_distance(&(*(Vec_8019A104 *)&lbl_804B8DA0), &self->pos) <= CFG.f44 && (0.0f) == ((f32 (*)(void *))vector_length)(&self->vel)) {
        ST.flags |= 0x20;
        if (self->f360 == 0) {
            add_gogo_ball_three_point_score(1);
            self->f360 = 1;
        }
    }
    if ((ST.flags & 2 || ST.flags & 1 || ST.flags & 0x20 || ST.flags & 0x10) && !(ST.flags & 8) && !(ST.flags & 4)) {
        TWindowCtrl::open((s32)(obj_getField1c(self)), (s32)lbl_80446148, 0x1B);
    }
    if (!(ST.flags & 0x33) && self->f360 != 0) {
        self->f360 = 0;
    }
    len = ((f32 (*)(void *))vector_length)(&self->vel);
    if ((0.0f) == len) {
        if (self->f358 == 0) {
            TWindowCtrl::open((s32)(((s32 (*)(void *, s32))obj_getField1c)(self, self->f35C++)), (s32)((void *)&lbl_805DBF94), 0x1B);
        }
        self->f358 = 1;
    } else {
        self->f358 = 0;
    }
    if (xyz_distance(&self->pos, &p->pos) > CFG.range) {
        self->f30 = 0;
        return;
    }
    if (self->f30 != 1) {
        self->f30 = 1;
        ang = lbl_80446150[0] * atan2_float(self->pos.x - p->pos.x, self->pos.z - p->pos.z);
        if ((0.0f) == len) {
            ((TWindowTimer *)((u8 *)&self->pos))->throw_gogo_ball((s32)ang, (s32)self->time);
            ((void (*)(void *))TWindowTimer__sub_8019A098)(self);
        }
    }
}

void TUnk_804B8E18::sub_8019A44C(s32 arg1) {
    Win_8019A44C *arg0 = (Win_8019A44C *)this;
    arg0->f390 = ((f32 *)&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration))[3];
    arg0->f394 = ((f32 *)&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration))[4];
    if ((s32)((u8 *)&gogo_ball_sync_state)[0x18] == 1) {
        arg0->f390 = ((f32 *)&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration))[0x13];
        arg0->f394 = ((f32 *)&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration))[0x14];
    }
    arg0->f398 = (0.1f);
    arg0->f39C = (0.1f);
    arg0->f344 = (0.0f);
    arg0->f348 = arg0->f394;
    arg0->f34C = arg0->f390;
    arg0->f3A0 = vector_length(&arg0->f344, (0.1f));
    rotate_vec_xz(&arg0->f344, &arg0->f344, arg1);
    arg0->f334 = arg1;
    VecCopy((Vec *)arg0->f50, (const Vec *)&arg0->f344);
    arg0->f50[1] = (0.0f);
}

void *TUnk_804B8E18::destroy_player_obj(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B8E18;
        unregister_object_by_id();
        clear_obj_links();
        destroy_motion_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
typedef char RecoveredGlobal_8019A574_lbl_804B8E18_size[sizeof(RecoveredGlobal_8019A574_lbl_804B8E18) == 0x140 ? 1 : -1];
typedef char RecoveredGlobal_8019A574_lbl_8050DD58_size[sizeof(RecoveredGlobal_8019A574_lbl_8050DD58) == 0x54 ? 1 : -1];
typedef char RecoveredGlobal_8019A574_lbl_8050DDAC_size[sizeof(RecoveredGlobal_8019A574_lbl_8050DDAC) == 0x1C ? 1 : -1];
u8 *TWindowTimer__sub_8019A574(u8 *arg0) {
    __ct__13TUnk_804806E8FP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8019A574_lbl_804B8E18 *)&lbl_804B8E18).value;
    ((TUnk_804B8E18 *)arg0)->m_390 = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x394) = (f32) (0.0f);
    ((TUnk_804B8E18 *)arg0)->m_398 = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x39C) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x344) = (f32) (0.0f);
    ((TUnk_804B8E18 *)arg0)->m_348 = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x34C) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)(&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration).value) + 0x20);
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) *(f32 *)((s8 *)(&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration).value) + 0x24);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) *(f32 *)((s8 *)(&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration).value) + 0x28);
    ((TUnk_804B8E18 *)arg0)->m_350 = 0;
    ((TUnk_804B8E18 *)arg0)->m_354 = 0;
    *(s32 *)((s8 *)arg0 + 0x334) = 0;
    ((TUnk_804B8E18 *)arg0)->m_338 = 0;
    *(f32 *)((s8 *)arg0 + 0x33C) = (f32) *(f32 *)((s8 *)(&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration).value) + 0);
    ((TUnk_804B8E18 *)arg0)->m_340 = (f32) *(f32 *)((s8 *)(&(*(RecoveredGlobal_8019A574_lbl_8050DD58 *)&gogo_ball_configuration).value) + 4);
    *(s32 *)((s8 *)arg0 + 0x358) = 0;
    ((TUnk_804B8E18 *)arg0)->m_364 = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x368) = (f32) (0.0f);
    ((TUnk_804B8E18 *)arg0)->m_36c = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x370) = (f32) (2.0f);
    ((TUnk_804B8E18 *)arg0)->m_374 = (f32) (1.0f);
    *(s32 *)((s8 *)arg0 + 0x378) = 1;
    ((TUnk_804B8E18 *)arg0)->m_37c = 0x40107;
    ((TUnk_804AF8A0 *)arg0)->initialize_linked_object_reference(arg0 + 0x364);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TUnk_804B8E18 *)arg0)->m_35c = 0;
    *(s16 *)((s8 *)(&(*(RecoveredGlobal_8019A574_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0x10) = 0;
    *(s8 *)((s8 *)(&(*(RecoveredGlobal_8019A574_lbl_8050DDAC *)&gogo_ball_sync_state).value) + 0x18) = 0;
    *(s32 *)((s8 *)arg0 + 0x360) = 0;
    return arg0;
}

void TWindowTimer::send_gogo_ball() {
    s32 arg0 = (s32)this;
    bswap_6x79_gogo_ball__12TWindowTimerFi(arg0);
    send_subcommand((u8 *)arg0);
}
void bswap_6x79_gogo_ball__12TWindowTimerFi(s32 arg0) {
    read_be16_field2__10TObjPlayerFv();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap_32((u32 *)(arg0 + 0x10));
}
void TWindowTimer__sub_8019A6F8(void* p) { *(u8*)((char*)p + 0x0) = 121; *(u8*)((char*)p + 0x1) = 6; }

s16 TWindowTimer::get_timer_value(s32 i) {
    return ((s32 *)&gogo_ball_team_scores)[i];
}

int TWindowTimer::set_timer_value(int a0, int a1) { gogo_ball_team_scores[a0] = a1; return (int)gogo_ball_team_scores; }

void add_gogo_ball_three_point_score(s32 i) {
    ((s32 *)&gogo_ball_team_scores)[i] += 3;
}

void add_gogo_ball_one_point_score(s32 i) {
    ((s32 *)&gogo_ball_team_scores)[i] += 1;
}

int TWindowTimer__sub_8019A770(void* p) { return close_timer_window__11TWindowCtrlFv(p); }

}

#undef gogo_ball_sync_state
#undef __dl__7TObjectFPv
#undef gogo_ball_team_scores
#undef xyz_distance
#undef vector_length
#undef reflect_velocity_off_collision__13TUnk_804B8E18FPvPv
#undef lbl_804B8DA0
