#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/TOMineDisp_8016EF68.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOMineTrapDisp.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOMineDisp.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TOMine.h"
#include "pso/misc/TOMineTrap.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8016EF68___vt__14TOMineTrapDisp {
    s32 value;
    u8 remaining[0x30];
};

struct VBase_8016EFB4 { u8 pad[0x18]; };

struct VObj_8016EFB4 : VBase_8016EFB4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
s32 TOMineDisp__ct(void *, void *, void *);
extern RecoveredGlobal_8016EF68___vt__14TOMineTrapDisp __vt__14TOMineTrapDisp;
extern s32 TOMineTrapDisp__name;
s32 is_locally_controlled__10TObjPlayerFPv(void);
f32 horizontal_distance_squared(void *, void *);
void get_player_state__6TOMineFv(void *, u16);
s32 fn_80171314(void *);
void *get_player_by_client_id(s32 i);
extern const f32 lbl_805DB850;
s32 get_camera_mode__11TCameraCtrlFv();
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805DB854;
extern const f32 lbl_805DB858;
typedef char RecoveredGlobal_8016EF68___vt__14TOMineTrapDisp_size[sizeof(RecoveredGlobal_8016EF68___vt__14TOMineTrapDisp) == 0x34 ? 1 : -1];
u8 *TOMineTrapDisp__ct(u8 *mine_trap_disp, s32 arg1, s32 arg2, s16 arg3) {
    TOMineDisp__ct((void *)mine_trap_disp, (void *)arg1, (void *)arg2);
    *(s32 **)((s8 *)mine_trap_disp + 0x18) = &__vt__14TOMineTrapDisp.value;
    *(s32 *)((s8 *)mine_trap_disp + 0) = (s32) TOMineTrapDisp__name;
    ((TOMineTrapDisp *)mine_trap_disp)->m_ac = arg3;
    return mine_trap_disp;
}

void TOMineDisp::render() {
    s32 temp_r31;
    s32 temp_r4;
    u16 id = TCameraCtrl::get_nth_view_player_id(get_camera_mode__11TCameraCtrlFv());
    if (id != this->m_a8) {
        return;
    }
    if (*(s32 *)&this->m_a4 != 2) {
        return;
    }
    if (((VObj_8016EFB4 *)((u8 *)this))->m8(lbl_805DB854, lbl_805DB858) == 0) {
        return;
    }
    push_matrix();
    temp_r31 = *(s32 *)&this->m_up;
    post_translate_matrix(((u8 *)this) + 0x38);
    rotate_matrix_y(0, this->rotation_y);
    ((TOMine *)temp_r31)->free_parts();
    TParticleCtrl::begin_effect_render();
    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x20;
    ((void (*)(void *, s32))set_constant_material)(((u8 *)this) + 0x94, temp_r4);
    ((TOMine *)temp_r31)->free_sub_objects();
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TOMineDisp::run_task() {
    void *mine = this->m_up;
    u8 *p;
    switch (this->m_a4) {
    case 0:
        p = (u8 *)get_player_by_client_id(this->m_a8);
        if (p != NULL && is_locally_controlled__10TObjPlayerFPv() != 0 && fn_80171314(p) != 0) {
            if (horizontal_distance_squared(((u8 *)this) + 0x38, p + 0x38) <= lbl_805DB850 ||
                ((TObjBase *)p)->get_room() == this->get_room()) {
                this->m_a4 = 2;
            }
        }
        break;
    case 3:
        break;
    case 2:
        get_player_state__6TOMineFv(mine, this->m_a8);
        VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((TOMineTrap *)mine)->get_mine_data_ptr()));
        break;
    }
}

}
