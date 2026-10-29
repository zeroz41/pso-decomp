#include "types.h"
#include "pso/boss/TBoss8DragonDemo.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_802F1D1C.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/unk/TUnk_804E4B24.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TObjBoss7TunnelCol.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct GE_802F1DAC { s32 a, b, obj, d; };

struct GE_802F1E54 { s32 a, b, obj, d; };

extern "C" {
s32 copy_position__16TBoss8DragonDemoFv(int, void *);
s32 draw_ginja_object(int);
s32 is_in_camera_range__18TObjBoss7TunnelColFv(void *);
s32 push_matrix();
extern u8 *boss7_common_bml_resource;
extern u8 *boss7_common_texture_list;

void draw_tunnel_segment(u8 *boss7_tunnel_col) {
    s32 var_r31;
    u8 *var_r30;
    u8 *var_r3;
    u8 *var_r4;
    var_r30 = boss7_tunnel_col;
    if (is_in_camera_range__18TObjBoss7TunnelColFv(boss7_tunnel_col) != 0) {
        var_r3 = (u8 *)((void *)2);
        var_r4 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x3C));
        var_r4 += *(s32 *)((s8 *)var_r30 + 0x38) * 4;
        var_r31 = *(s32 *)((s8 *)var_r4 + (-4));
        set_draw_list_mask(2);
        var_r3 = boss7_common_texture_list;
        TObjFish::set_global_param((int)var_r3);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        var_r4 = (var_r30 + 0x48);
        var_r3 = NULL;
        TObjPlayer::concat_matrix(0, (int)var_r4);
        var_r3 = boss7_common_bml_resource;
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x42C));
        var_r3 += var_r31 * 0x10;
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 8));
        draw_ginja_object((int)var_r3);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        restore_draw_list_mask();
    }
}

void fn_802F1DAC(u8 *arg0) {
    if (((s32 (*)(void))is_in_camera_range__18TObjBoss7TunnelColFv)() != 0) {
        set_draw_list_mask(2);
        TObjFish::set_global_param((int)boss7_common_texture_list);
        push_matrix();
        TObjPlayer::concat_matrix(0, (int)(arg0 + 0x48));
        ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1DAC **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[1]].obj, boss7_common_bml_resource);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x38) == 4) {
            ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1DAC **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[2]].obj, boss7_common_bml_resource);
        }
        pop_matrix();
        restore_draw_list_mask();
    }
}

void fn_802F1E54(u8 *arg0) {
    if (((s32 (*)(void))is_in_camera_range__18TObjBoss7TunnelColFv)() != 0) {
        set_draw_list_mask(1);
        TObjFish::set_global_param((int)boss7_common_texture_list);
        push_matrix();
        TObjPlayer::concat_matrix(0, (int)(arg0 + 0x48));
        ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1E54 **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[0]].obj, boss7_common_bml_resource);
        pop_matrix();
        restore_draw_list_mask();
    }
}

void TUnk_804E4B24::run_task() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x1C) = TBoss8DragonDemo__sub_802F2CBC((void *)this->m_34);
    this->m_24 = (f32) (this->m_24 - TBoss8DragonDemo__sub_802F2CB4((void *)this->m_34));
    if ((s32) this->m_40 == 4) {
        copy_position__16TBoss8DragonDemoFv(this->m_34, (u8 *)&this->unk_1C);
    }
    if (this->m_24 <= -*(f32 *)((s8 *)arg0 + 0x44)) {
        queue_destruction__7TObjectFv((arg0));
    }
    ((TUnk_804E4B24 *)arg0)->update_collision();
}

}
