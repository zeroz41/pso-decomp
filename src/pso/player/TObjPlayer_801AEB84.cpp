#include "types.h"
#include "pso/player/TObjPlayer_801AEB84.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 add_actor_tp_bonus(void *, int);
s32 add_actor_hp_bonus(void *, int);
s32 get_class_index__10TObjPlayerFv(void *);
s32 is_camera_mode_active__10TObjPlayerFv();

extern "C" {
extern "C" {
extern "C" {
extern "C" {
extern "C" {
extern "C" {
#include "pso/ui/hud/TRaderMapCore.h"

extern "C" {

void TObjPlayer::apply_luck_reward(u8 arg1) {
    u8 var_r31;
    s32 arg0 = (s32)this;

    var_r31 = arg1;
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        var_r31 *= 5;
    }
    ((TObjPlayer *)arg0)->add_lck(var_r31);
    TObjPlayer::add_item_count_kind4(arg0 + 0x374, (s32)((void *) (get_class_index__10TObjPlayerFv((void *)arg0))), 1);
}

}
void TObjPlayer::add_dfp_material(u8 arg1) {
    u8 var_r31;
    s32 arg0 = (s32)this;

    var_r31 = arg1;
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        var_r31 *= 5;
    }
    ((TObjPlayer *)arg0)->add_dfp(var_r31);
    TObjPlayer::try_add_item_count_kind3(arg0 + 0x374, (s32)((void *) (get_class_index__10TObjPlayerFv((void *)arg0))), 1);
}

}
void TObjPlayer::add_evp_material(u8 arg1) {
    u8 var_r31;
    s32 arg0 = (s32)this;

    var_r31 = arg1;
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        var_r31 *= 5;
    }
    ((TObjPlayer *)arg0)->add_evp(var_r31);
    TObjPlayer::try_add_item_count_type2(arg0 + 0x374, (s32)((void *) (get_class_index__10TObjPlayerFv((void *)arg0))), 1);
}

}
void TObjPlayer::add_mst_and_item(u8 arg1) {
    u8 var_r31;
    s32 arg0 = (s32)this;

    var_r31 = arg1;
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        var_r31 *= 5;
    }
    ((TObjPlayer *)arg0)->add_mst(var_r31);
    TObjPlayer::add_item_count(arg0 + 0x374, (s32)((void *) (get_class_index__10TObjPlayerFv((void *)arg0))), 1);
}

}
void TObjPlayer::add_stat_and_item(u8 arg1) {
    u8 var_r31;
    s32 arg0 = (s32)this;

    var_r31 = arg1;
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        var_r31 *= 5;
    }
    ((TObjPlayer *)arg0)->add_stat(var_r31);
    TObjPlayer::try_add_item(arg0 + 0x374, (s32)((void *) (get_class_index__10TObjPlayerFv((void *)arg0))), 1);
}

}
void TObjPlayer::set_speed_scaled_by_camera(u8 arg1) {
    u8 var_r31;
    s32 arg0 = (s32)this;

    var_r31 = arg1;
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        var_r31 *= 5;
    }
    add_actor_tp_bonus((void *)arg0, (int)var_r31);
}

}
void TObjPlayer::apply_speed_with_camera_scale(u8 arg1) {
    u8 var_r31;
    s32 arg0 = (s32)this;

    var_r31 = arg1;
    if (is_camera_mode_active__10TObjPlayerFv() != 0) {
        var_r31 *= 5;
    }
    add_actor_hp_bonus((void *)arg0, (int)var_r31);
}

}

}
