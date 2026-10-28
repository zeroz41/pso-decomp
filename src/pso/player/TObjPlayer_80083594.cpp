#include "types.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/unk/text_803D96A8.h"

#include <stddef.h>
#include "pso/misc/TOTrapAncient02.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjFish.h"
struct Stack_800836E8 {
    f32 sp8;
    f32 spC;
    s32 sp10;
    u8 trailing_storage[0x2C];
};

extern "C" {
s32 is_split_screen();
s32 TCameraCtrl__sub_800689F4();
s32 PSMTXConcat(void *, void *, void *);
s32 C_MTXLightPerspective(void *, f32, f32, f32, f32, f32, f32);
s32 rotate_matrix_y(int, void *);
s32 push_matrix();
s32 GXSetTevOp(s32, s32);
s32 GXSetTevOrder(s32, s32, s32, s32);
}
void calc_projection_screen_offset(f32 *arg0, f32 *arg1);
f32 calc_camera_fov_degrees(void);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
extern const f64 lbl_80439358;
extern s32 current_matrix;
extern const f32 lbl_805D93DC;
extern const f32 lbl_805D940C;
extern const f32 lbl_805D9414;
void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);

extern s32 shared_capture_texture_list[];
extern s32 model_render_flags;

void TObjPlayer::setup_tev_stage() {
    if (is_split_screen() == 0) {
        GXSetTevOrder(1, 1, 1, 4);
        GXSetTevOp(1, 2);
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        TObjFish::set_global_param((s32)shared_capture_texture_list);
        load_list_texture(0, 0, 0, 1);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}

void setup_particle_tev(s32 arg0) {
    if (is_split_screen() == 0) {
        GXSetTevOrder(1, 1, 1, 4);
        if (arg0 != 0) {
            GXSetTevOp(1, 0);
        } else {
            GXSetTevOp(1, 1);
        }
        TObjPlayer::set_tex_coord_gen(1, 0, 0, 0x1E);
        TObjFish::set_global_param((s32)shared_capture_texture_list);
        load_list_texture(0, 0, 0, 1);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
    }
}

void load_projected_texture_matrix(f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_800836E8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800836E8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800836E8, sp10) == 0x8) ? 1 : -1];
    Stack_800836E8 stack;
    f32 temp_f31;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&stack.spC, &stack.sp8);
        push_matrix();
        temp_f31 = (f32) (lbl_80439358 * calc_camera_fov_degrees());
        if (TCameraCtrl__sub_800689F4() != 0) {
            C_MTXLightPerspective(&stack.sp10, temp_f31, farg0, lbl_805D93DC, lbl_805D9414, (f32) (lbl_805D93DC - stack.spC), (f32) (lbl_805D93DC - stack.sp8));
        } else {
            C_MTXLightPerspective(&stack.sp10, temp_f31, farg0, lbl_805D93DC, lbl_805D9414, lbl_805D93DC, lbl_805D93DC);
        }
        PSMTXConcat(&stack.sp10, (void *)current_matrix, (void *)current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}

void load_projection_tex_matrix(s32 rotation_y) {
    u8 sp10[0x30];
    f32 spC;
    f32 sp8;
    f32 temp_f31;
    if (is_split_screen() == 0) {
        calc_projection_screen_offset(&spC, &sp8);
        push_matrix();
        rotate_matrix_y(0, (void *)rotation_y);
        temp_f31 = (f32) (lbl_80439358 * calc_camera_fov_degrees());
        if (TCameraCtrl__sub_800689F4() != 0) {
            C_MTXLightPerspective(sp10, temp_f31, lbl_805D940C, lbl_805D93DC, lbl_805D9414, (f32) (lbl_805D93DC - spC), (f32) (lbl_805D93DC - sp8));
        } else {
            C_MTXLightPerspective(sp10, temp_f31, lbl_805D940C, lbl_805D93DC, lbl_805D9414, lbl_805D93DC, lbl_805D93DC);
        }
        PSMTXConcat((void *)sp10, (void *)current_matrix, (void *)current_matrix);
        load_current_tex_matrix(0);
        pop_matrix();
        load_current_pos_matrix(0);
    }
}
