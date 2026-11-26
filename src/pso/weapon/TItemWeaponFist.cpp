#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponBaranzLauncher.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeaponFist.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/unk/text_80126A34.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/effect/item/TItemEffCane.h"
#include "pso/weapon/TItemWeaponFistTypes.h"

// ---- pso/unk/text_80126740


void TItemWeaponFist::on_unequipped() {
    owner->attack_state.set_evp(1.0f);
}

// ---- pso/player/TObjPlayer_801267C4


void TItemWeaponFist::on_equipped() {
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




extern "C" {
s32 reflect_matrix_in_plane(s32, f32 *, f32);
}
s32 knuckle_second_hand_pass;

extern s32 knuckle_marker_joint_table[];
void TItemWeaponFist::transform_model_node() {
    MirrorPlane plane;
    if ((get_model_node_counter() == 0) && (get_item_index() == 3) && (knuckle_second_hand_pass != 0)) {
        plane.point_z = 0.0f;
        plane.point_y = 0.0f;
        plane.point_x = 0.0f;
        plane.normal_z = 0.0f;
        plane.normal_y = 0.0f;
        plane.normal_x = 1.0f;
        reflect_matrix_in_plane(0, &plane.point_x, 0.0f);
    }
}

void TItemWeaponFist::emit_marker_effects() {
  u8 buf[16];
  s32 k;
  s16 stage;
  s32 index;
  if (get_item_index() == 3)
  {
    if (get_attack_stage() == 0)
    {
      TItemEffCane::spawn_pair(tl_05, this, -1, -2);
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


void TItemWeaponFist::draw_held_model() {
    TItemWeapon *weapon = this;
    if (get_item_index() == 3) {
        knuckle_second_hand_pass = 0;
        weapon->draw_weapon_model();
        knuckle_second_hand_pass = 1;
        draw_weapon_at_joint(weapon, 0x23);
    }
}

TItemWeaponFist::TItemWeaponFist(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(577);
}

TItem *TItemWeaponFist::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponFist(tl_05, item);
    }
    return NULL;
}

TItemWeaponFist::~TItemWeaponFist() {

}
