#include "pso/effect/particle/ParticleFactory.h"
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
#include "pso/player/TObjPlayer_801D2E20.h"

// ---- pso/unk/text_80126740


void TUnk_804A2B98::on_unequipped() {
    owner->attack_state.set_evp(1.0f);
}

// ---- pso/player/TObjPlayer_801267C4


void TUnk_804A2B98::on_equipped() {
    f32 scale;
    u8 item_index;

    scale = 1.0f;
    item_index = get_item_index();
    switch ((s32) item_index) {
    case 0:
        scale = 1.05f;
        break;
    case 1:
        scale = 1.1f;
        break;
    case 2:
        scale = 1.15f;
        break;
    case 3:
        scale = 1.2f;
        break;
    }
    owner->attack_state.set_evp(scale);
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
}
s32 knuckle_second_hand_pass;

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
    stage = owner->attack_state.get_validated_attack_stage();
    index = stage;
    index += k;
    this->owner->get_anim_node_position(knuckle_marker_joint_table[index], (Vec *)buf);
    spawn_particle_effect((const Vec *)buf, 0x1D0);
  }
}

// Joint each knuckle marker effect is spawned at, three per row.
s32 knuckle_marker_joint_table[18] = {
    0x09, 0x12, 0x30, 0x30, 0x12, 0x12, 0x30, 0x30, 0x30,
    0x23, 0x30, 0x30, 0x23, 0x30, 0x12, 0x30, 0x12, 0x12,
};


void TUnk_804A2B98::reserved_53() {
    saddr arg0 = (saddr)this;
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

TItem *create_knuckle_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2B98(tl_05, item);
    }
    return NULL;
}

TUnk_804A2B98::~TUnk_804A2B98() {

}
