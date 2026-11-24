#include "pso/object/base/TObjChara.h"
#include "types.h"
#include "pso/player/TObjPlayer_801AEB84.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 get_class_index__10TObjPlayerFv(void *);

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
    saddr arg0 = (saddr)this;

    var_r31 = arg1;
    if (TObjPlayer::is_camera_mode_active() != 0) {
        var_r31 *= 5;
    }
    this->add_lck(var_r31);
    this->materials.add_item_count_kind4(get_class_index__10TObjPlayerFv(this), 1);
}

}
void TObjPlayer::add_dfp_material(u8 arg1) {
    u8 var_r31;
    saddr arg0 = (saddr)this;

    var_r31 = arg1;
    if (TObjPlayer::is_camera_mode_active() != 0) {
        var_r31 *= 5;
    }
    this->add_dfp(var_r31);
    this->materials.try_add_item_count_kind3(get_class_index__10TObjPlayerFv(this), 1);
}

}
void TObjPlayer::add_evp_material(u8 arg1) {
    u8 var_r31;
    saddr arg0 = (saddr)this;

    var_r31 = arg1;
    if (TObjPlayer::is_camera_mode_active() != 0) {
        var_r31 *= 5;
    }
    this->add_evp(var_r31);
    this->materials.try_add_item_count_type2(get_class_index__10TObjPlayerFv(this), 1);
}

}
void TObjPlayer::add_mst_and_item(u8 arg1) {
    u8 var_r31;
    saddr arg0 = (saddr)this;

    var_r31 = arg1;
    if (TObjPlayer::is_camera_mode_active() != 0) {
        var_r31 *= 5;
    }
    this->add_mst(var_r31);
    this->materials.add_item_count(get_class_index__10TObjPlayerFv(this), 1);
}

}
void TObjPlayer::add_stat_and_item(u8 arg1) {
    u8 var_r31;
    saddr arg0 = (saddr)this;

    var_r31 = arg1;
    if (TObjPlayer::is_camera_mode_active() != 0) {
        var_r31 *= 5;
    }
    this->add_stat(var_r31);
    this->materials.try_add_item(get_class_index__10TObjPlayerFv(this), 1);
}

}
void TObjPlayer::set_speed_scaled_by_camera(u8 arg1) {
    u8 var_r31;

    var_r31 = arg1;
    if (TObjPlayer::is_camera_mode_active() != 0) {
        var_r31 *= 5;
    }
    add_actor_tp_bonus(this, (int)var_r31);
}

}
void TObjPlayer::apply_speed_with_camera_scale(u8 arg1) {
    u8 var_r31;

    var_r31 = arg1;
    if (TObjPlayer::is_camera_mode_active() != 0) {
        var_r31 *= 5;
    }
    add_actor_hp_bonus(this, (int)var_r31);
}

}

}
