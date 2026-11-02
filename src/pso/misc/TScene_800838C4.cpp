#include "types.h"
#include "pso/misc/TScene_800838C4.h"
#include "pso/unk/text_803D96A8.h"

#include <stddef.h>
#include "pso/misc/TScene.h"
#include "pso/player/TObjPlayer.h"
struct Stack_80083914 {
    f32 sp8;
    u8 pad_C[0x4];
    s32 sp10;
    u8 trailing_storage[0x2C];
};

struct RecoveredGlobal_80083914_lbl_8048E5D0 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
f32 translate_current_matrix_ps(f32, f32, f32);
s32 GXSetTevOp(int, int);
s32 GXSetTevOrder(int, int, int, int);
s32 is_split_screen();
f32 PSMTXConcat(void *, void *, void *);
s32 C_MTXLightFrustum(void *, f32, f32, f32, f32, f32, f32, f32, f32);
f32 rotate_matrix_by_node_angles(void *, int);
f32 rotate_current_matrix_x_ps(int);
}
void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
extern "C" {
s32 push_identity_matrix_ps();
extern RecoveredGlobal_80083914_lbl_8048E5D0 shadow_light_position;
extern s32 current_matrix;
extern s32 model_render_flags;
extern const f32 lbl_805D93D0;
extern const f32 lbl_805D93DC;
extern const f32 lbl_805D9418;
extern const f32 lbl_805D941C;
extern const f32 lbl_805D9420;
extern const f32 lbl_805D9424;
f64 get_end_text_value__10TObjPlayerFv(f32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern u8 *camera_ctrl_instance;
extern const f32 lbl_805D940C;
void TScene::apply_single_screen_state() {
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        model_render_flags &= 0xFFF7FFFF;
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
    }
}
#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80083914_lbl_8048E5D0_size[sizeof(RecoveredGlobal_80083914_lbl_8048E5D0) == 0xC ? 1 : -1];
void render_projected_shadow_receiver(u8 *arg0, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_80083914, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80083914, sp10) == 0x8) ? 1 : -1];
    Stack_80083914 stack;
    if ((is_split_screen() == 0) && (TObjPlayer::check_all_players_ready() != 0)) {
        push_identity_matrix_ps();
        translate_current_matrix_ps(lbl_805D93D0, lbl_805D93D0, lbl_805D9418);
        rotate_current_matrix_x_ps(0x3800);
        translate_current_matrix_ps(-*(f32 *)((s8 *)&shadow_light_position.value + 0), -*(f32 *)((s8 *)&shadow_light_position.value + 4), -*(f32 *)((s8 *)&shadow_light_position.value + 8));
        translate_current_matrix_ps(*(f32 *)((s8 *)arg0 + 0), *(f32 *)((s8 *)arg0 + 4), *(f32 *)((s8 *)arg0 + 8));
        rotate_matrix_by_node_angles((void *)arg1, 1);
        stack.sp8 = lbl_805D93DC;
        C_MTXLightFrustum((void *)&stack.sp10, (f32) (-lbl_805D941C), lbl_805D941C, lbl_805D9420, (f32) (-lbl_805D9420), lbl_805D9424, lbl_805D93DC, lbl_805D93DC, lbl_805D93DC);
        PSMTXConcat((void *)&stack.sp10, (void *)current_matrix, (void *)current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
        GXSetTevOrder(1, 1, 1, 4);
        GXSetTevOp(1, 1);
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(((int) (1U)));
        set_ginja_post_texgen_count(((int) (1U)));
    }
}
}
#pragma pop

f32 calc_camera_fov_degrees(void) {
    f32 temp_f2;
    f32 temp_f31;
    f32 var_f1;
    s32 temp_r31;
    var_f1 = 11832.0f;
    if ((void *) camera_ctrl_instance != NULL) {
        temp_f2 = (f32) (*(s32 *)((s8 *)camera_ctrl_instance + 0x19C));
        temp_f2 *= 0.85f;
        temp_r31 = (s32) (temp_f2 * lbl_805D93DC);
        temp_f31 = cos_table_lookup(temp_r31);
        var_f1 = (f32) ((s32) (10430.38043493439 * get_end_text_value__10TObjPlayerFv((f32) ((sin_table_lookup(temp_r31) / temp_f31) / lbl_805D940C))) * 2);
    }
    return var_f1;
}
