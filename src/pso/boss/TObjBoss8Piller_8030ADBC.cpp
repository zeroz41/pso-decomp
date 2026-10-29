#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/TObjBoss8Piller.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

extern "C" {
u8 *get_enemy_entity(u16 arg0);
s32 TBoss8Dragon__sub_802FB1B0(int, f32, void *);
extern const f32 lbl_805DF150;
extern const f32 lbl_805DF154;
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 draw_model_motion(int, int, f32);
s32 push_matrix();
s32 is_split_screen();

extern u8 *TObjBoss8Piller__shared_resource;

void TObjBoss8Piller::render() {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;

    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        if (is_split_screen() != 0) {
            var_r31 = *(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8Piller__shared_resource + 0x42C)) + 0x28);
        } else {
            var_r31 = *(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8Piller__shared_resource + 0x42C)) + 8);
        }
        TObjFish::set_global_param((s32)((void *) (*(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8Piller__shared_resource + 0x42C)) + 0xC))));
        push_matrix();
        post_translate_matrix(arg0 + 0x1C);
        scale_matrix(0, lbl_805DF150, lbl_805DF150, lbl_805DF150);
        draw_model_motion(var_r31, (int) (*(s32 *)((s8 *)arg0 + 0x2C)), (f32) (*(f32 *)((s8 *)arg0 + 0x28)));
        pop_matrix();
        set_default_alpha_blend();
    }
}
void TObjBoss8Piller::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 enemy_entity;
    u32 temp_r3_2;
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) (*(f32 *)((s8 *)arg0 + 0x28) + lbl_805DF150);
    enemy_entity = (u32)get_enemy_entity((*(u16 *)((s8 *)arg0 + 0x30)));
    if (enemy_entity != 0U) {
        TBoss8Dragon__sub_802FB1B0(enemy_entity, lbl_805DF154, arg0 + 0x1C);
    }
    temp_r3_2 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 4) - 1;
    if (*(f32 *)((s8 *)arg0 + 0x28) >= (f32) temp_r3_2) {
        *(f32 *)((s8 *)arg0 + 0x28) = (f32) temp_r3_2;
        queue_destruction__7TObjectFv((arg0));
    }
}

}
