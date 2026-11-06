#include "types.h"
#include "pso/weapon/TUnk_804A2A58.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80126740.h"
#include "pso/weapon/TUnk_804A2B98.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/unk/text_80126A34.h"
#include "pso/system/task/TMainTask.h"

// ---- pso/unk/text_80126740


void TUnk_804A2B98::vfunc_58() {
    ((PlayerAttackState *)((u8 *)this->owner + 0x7CC))->set_evp(1.0f);
}

// ---- pso/player/TObjPlayer_801267C4

extern "C" {


void TUnk_804A2B98::vfunc_57() {
    f32 var_f31;
    u8 temp_r3;

    var_f31 = 1.0f;
    temp_r3 = get_item_index();
    switch ((s32) temp_r3) {
    case 0:
        var_f31 = 1.05f;
        break;
    case 1:
        var_f31 = 1.1f;
        break;
    case 2:
        var_f31 = 1.15f;
        break;
    case 3:
        var_f31 = 1.2f;
        break;
    }
    ((PlayerAttackState *)((u8 *)this->owner + 0x7CC))->set_evp(var_f31);
}

}

// ---- pso/unk/text_8012685C

struct Stack_8012685C {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};


extern "C" {
s32 reflect_matrix_in_plane(s32, f32 *, f32);
void *spawn_particle_effect(void *pos, s32 id);
s16 get_validated_attack_stage(u8 *arg0);
}
extern s32 knuckle_second_hand_pass;

extern s32 knuckle_marker_joint_table[];
void TUnk_804A2B98::vfunc_60() {
    Stack_8012685C stack;
    if ((TObjPlayer::get_player_list() == 0) && (get_item_index() == 3) && ((s32) knuckle_second_hand_pass != 0)) {
        stack.sp10 = 0.0f;
        stack.spC = 0.0f;
        stack.sp8 = 0.0f;
        stack.sp1C = 0.0f;
        stack.sp18 = 0.0f;
        stack.sp14 = 1.0f;
        reflect_matrix_in_plane(0, &stack.sp8, 0.0f);
    }
}

void TUnk_804A2B98::emit_marker_effects() {
  u8 buf[16];
  s32 k;
  s16 stage;
  s32 index;
  if (get_item_index() == 3)
  {
    if (get_attack_stage() == 0)
    {
      ((TObjPlayer *)tl_05)->spawn_cane_effects(this, -1, -2);
    }
  }
  else
  {
    k = this->owner->has_valid_handle() * 3;
    stage = get_validated_attack_stage((u8 *)this->owner + 0x7CC);
    index = stage;
    index += k;
    this->owner->get_anim_node_position(knuckle_marker_joint_table[index], (Vec *)buf);
    spawn_particle_effect(buf, 0x1D0);
  }
}

// Joint each knuckle marker effect is spawned at, three per row.
s32 knuckle_marker_joint_table[18] = {
    0x09, 0x12, 0x30, 0x30, 0x12, 0x12, 0x30, 0x30, 0x30,
    0x23, 0x30, 0x30, 0x23, 0x30, 0x12, 0x30, 0x12, 0x12,
};

extern "C" {


void TUnk_804A2B98::reserved_53() {
    s32 arg0 = (s32)this;
    if (get_item_index() == 3) {
        knuckle_second_hand_pass = 0;
        ((TItemWeapon *)arg0)->draw_weapon_model();
        knuckle_second_hand_pass = 1;
        draw_weapon_at_joint(arg0, 0x23);
    }
}

TUnk_804A2B98::TUnk_804A2B98(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(577);
}
}

u8 *create_knuckle_weapon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A2B98(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A2B98::~TUnk_804A2B98() {

}
