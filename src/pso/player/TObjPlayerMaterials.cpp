#include "types.h"
#include "pso/player/TObjPlayer.h"

// Defined with TObjChara: raise the HP/TP item bonus, floored at 0.
extern "C" {
s32 add_actor_tp_bonus(void *actor, s32 amount);
s32 add_actor_hp_bonus(void *actor, s32 amount);
// TObjPlayer::get_class_index as its callers see it: the whole return register.
s32 get_class_index__10TObjPlayerFv(TObjPlayer *player);
}

// The material handlers an item use calls; the gain is five times larger
// while is_camera_mode_active() holds.
void TObjPlayer::apply_luck_reward(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_lck(amount);
    materials.add_item_count_kind4(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::add_dfp_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_dfp(amount);
    materials.try_add_item_count_kind3(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::add_evp_material(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_evp(amount);
    materials.try_add_item_count_type2(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::add_mst_and_item(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_mst(amount);
    materials.add_item_count(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::add_stat_and_item(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_stat(amount);
    materials.try_add_item(get_class_index__10TObjPlayerFv(this), 1);
}

void TObjPlayer::set_speed_scaled_by_camera(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_actor_tp_bonus(this, amount);
}

void TObjPlayer::apply_speed_with_camera_scale(u8 amount) {
    if (TObjPlayer::is_camera_mode_active() != 0) {
        amount *= 5;
    }
    add_actor_hp_bonus(this, amount);
}
