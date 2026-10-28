#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss8Dragon_802F3F20.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/MaterialAlphaCompare.h"
#include "pso/unk/text_801414B0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802F4098_main_task { s32 value; u8 remaining[0x30]; };
typedef char RecoveredGlobal_802F4098_main_task_size[sizeof(RecoveredGlobal_802F4098_main_task) == 0x34 ? 1 : -1];

typedef struct Vec_802F3F20 { f32 x, y, z; } Vec_802F3F20;

typedef struct Obj_802F3F20 {
    u8 pad0[0x326];
    s16 x326;
    u8 pad328[0x434 - 0x328];
    Vec_802F3F20 pts[8];
} Obj_802F3F20;

struct VBase_14_681f8e { char pad[0x14]; };

struct VObj_14_681f8e : VBase_14_681f8e {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
};

struct Fade_802F4114 { u8 pad[0x1C]; };

struct Obj_802F4114 { u8 pad[0x6DC]; Fade_802F4114 fades[4]; };

extern "C" {
s32 get_mode__11TCameraCtrlFPv(void *);
s32 TBoss8Dragon__sub_802FCCBC(void *);
extern const f32 lbl_805DED68;
extern const f32 lbl_805DED6C;
u8 *find_entity_by_id(void);
s32 TBoss8Dragon__sub_802F4760(void *, void *, f32);
void subtract_vector(void *, void *);
extern s32 boss8_dragon_point_index_table[];
extern u8 boss8_dragon_reference_pos_vec[];
extern u8 dragon_forward_reference_vec[];
extern u8 *camera_ctrl_instance;
extern f32 boss8_dragon_visibility_distance;
extern const f32 TBoss8Dragon__data_805DED50;
extern const f32 TBoss8Dragon__data_805DED64;
s32 isFading__15RenderFadeStateCFv(int);
s32 TObjLight__sub_801337F8(void *);
s32 has_enough_enemies__12TBoss8DragonFv();
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern s32 current_scene_light;
extern s32 saved_model_render_flags;
extern u8 *TBoss8Dragon__data_805D6988;
extern s32 model_render_flags;
extern const f32 lbl_805DED70;

s32 TBoss8Dragon__sub_802F3F20(u8 *arg0) {
    Vec_802F3F20 sp14;
    Vec_802F3F20 sp8;
    f32 temp_f31;
    u8 *entity;
    s32 i;
    if (camera_ctrl_instance == 0) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 30) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 21) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 22) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 23) {
        return 1;
    }
    if (*(s32 *)(arg0 + 0x3E4) != 0) {
        return 0;
    }
    TCameraCtrl::get_camera_target_id(-1);
    entity = find_entity_by_id();
    if (entity == 0) {
        return 0;
    }
    VecCopy((Vec *)&sp14, (const Vec *)(camera_ctrl_instance + 0x178));
    sp14.y = TBoss8Dragon__data_805DED50;
    VecCopy((Vec *)&sp8, (const Vec *)(entity + 0x38));
    subtract_vector(&sp8, &sp14);
    sp8.y = TBoss8Dragon__data_805DED50;
    temp_f31 = ((TObjBoss2Tunnel *)(&sp8))->clamp_velocity();
    VecCopy((Vec *)boss8_dragon_reference_pos_vec, (const Vec *)&sp14);
    VecCopy((Vec *)dragon_forward_reference_vec, (const Vec *)&sp8);
    boss8_dragon_visibility_distance = temp_f31;
    for (i = 0; i < 4; i++) {
        if (TBoss8Dragon__sub_802F4760(arg0, &((Obj_802F3F20 *)arg0)->pts[boss8_dragon_point_index_table[i]], TBoss8Dragon__data_805DED64) != 0) {
            return 1;
        }
    }
    return 0;
}

void TBoss8Dragon::sub_802F4098(u8 *arg1) {
    VecCopy((Vec *)arg1, (const Vec *)(((u8 *)this) + 0x38));
    if ((get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_802F4098_main_task *)&main_task).value) & 0x10) && (TBoss8Dragon__sub_802FCCBC(this) == 0) && !(this->m_c0 > lbl_805DED68)) {
        *(f32 *)((s8 *)arg1 + 8) = (f32) (*(f32 *)((s8 *)arg1 + 8) + lbl_805DED6C);
    }
}
void TBoss8Dragon::draw_with_fade(s32 arg1, s32 arg2) {
    u8 *temp_r31;
    if (!(*(f32 *)&this->unk_3C <= lbl_805DED70)) {
        TObjFish::set_global_param(this->m_24);
        TObjEneDD::clear_global_flag_400();
        saved_model_render_flags = model_render_flags;
        set_material_alpha_compare_reference(0);
        if (TBoss8Dragon__sub_802F3F20(((u8 *)this)) != 0) {
            ((RenderFadeState *)(&((Obj_802F4114 *)((u8 *)this))->fades[arg2]))->fadeOut();
        } else {
            ((RenderFadeState *)(&((Obj_802F4114 *)((u8 *)this))->fades[arg2]))->restore();
        }
        temp_r31 = (u8 *)&((Obj_802F4114 *)((u8 *)this))->fades[arg2];
        if (isFading__15RenderFadeStateCFv((int)temp_r31) != 0) {
            ((VObj_14_681f8e *)(temp_r31))->m6();
        }
        push_matrix();
        post_translate_matrix((void *)arg1);
        rotate_matrix_y(0, this->m_60);
        rotate_matrix_x(0, this->m_5c);
        rotate_matrix_z(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x64)));
        scale_current_matrix((void *) (((u8 *)this) + 0x68));
        TObjPlayer::toggle_particle_effect();
        if (this->m_3c0 & 0x80) {
            fn_801414B0(3, 3, 3, 3);
        }
        if (has_enough_enemies__12TBoss8DragonFv() != 0) {
            this->m_34 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 0x18);
        } else {
            this->m_34 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 8);
        }
        ((TObjMotion *)((u8 *)this))->draw();
        TObjPlayer::setup_tev_swap();
        TParticleCtrl::end_effect_render();
        TObjLight__sub_801337F8((void *)current_scene_light);
        pop_matrix();
        set_chunk_material_override_pair(0xFF00, 0);
        set_material_alpha_compare_reference(0xBF);
        model_render_flags = saved_model_render_flags;
    }
}

}
