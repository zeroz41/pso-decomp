#include "types.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"

struct Stack_800B9D94 {
    s32 sp8;
    u8 pad_C[0x4];
    s32 sp10;
};

struct Obj_800B9E84 {
    u8 pad[0x2b8]; s16 a; s16 b;
    u8 pad2[0x32c - 0x2bc]; s16 c; s16 d;
};

extern "C" {
s32 minimap_render_dot(void *, int, int, int);
s32 rotate_matrix_y(int, void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern const f32 TObjEneDD__data_805D9E8C;
extern const f32 lbl_805D9E90;
int bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(void*);
int transform_to_view__11TCameraCtrlFii(void*);
int apply_split_screen_view_matrix__11TCameraCtrlFv(void*);
int restore_scene_lighting(void*);
int select_actor_lighting(void*);
int render_with_position_override__9TObjEnemyFPUcl(void*);
int set_param__9TObjEnemyFl(void*);

    extern int model_render_flags;

void TObjEneDD::vfunc_100() {
    if (!(this->actorFlags & 0x40800)) {
        minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    }
}

void TObjEneDD::clear_global_flag_400() { model_render_flags = (model_render_flags & 0xfffffbff); }

int TObjEneDD::update_player_state() { return render_with_position_override__9TObjEnemyFPUcl(this); }

void TObjEneDD::draw_oriented_shadow(s32 arg1, s32 arg2, u32 arg3) {
    s32 arg0 = (s32)this;
    Stack_800B9D94 stack;
    direction_to_rotation_xz((u8 *)arg1, (&stack.sp8), (&stack.sp10));
    push_matrix();
    post_translate_matrix((void *)arg0);
    translate_matrix(0, TObjEneDD__data_805D9E8C, lbl_805D9E90, TObjEneDD__data_805D9E8C);
    rotate_matrix_z(0, stack.sp10);
    rotate_matrix_x(0, stack.sp8);
    rotate_matrix_y(0, (void *)arg2);
    if (arg3 != 0U) {
        scale_current_matrix((void *)arg3);
    }
    rotate_matrix_x(0, -0x4000);
    draw_blob_shadow(0);
    pop_matrix();
}

int TObjEneDD::update_primary_light() { return restore_scene_lighting(this); }
int TObjEneDD::update_secondary_light() { return select_actor_lighting(this); }

void TObjEneDD::reload_stats_keep_hp_tp() {
    Obj_800B9E84 *self = (Obj_800B9E84 *)this;
    s16 a = this->hpmax;
    s16 c = this->hp;
    s16 b = this->tpmax;
    s16 d = *(s16 *)&this->tp;
    bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(self);
    this->hpmax = a;
    this->hp = c;
    this->tpmax = b;
    *(s16 *)&this->tp = d;
}

void TObjEneDD::reset_hp() { bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(this); this->referenceHp = this->hp; }
int TObjEneDD::get_camera_ctrl() { return transform_to_view__11TCameraCtrlFii(this); }
int TObjEneDD::update_camera_sequence() { return apply_split_screen_view_matrix__11TCameraCtrlFv(this); }
int TObjEneDD::initialize_enemy_state() { return set_param__9TObjEnemyFl(this); }

}
