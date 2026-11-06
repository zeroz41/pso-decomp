#include "types.h"
#include "pso/weapon/TUnk_804A1570.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80122F3C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

int scale_current_matrix(void*);

}

void TUnk_804A1570::vfunc_60() { if (TObjPlayer::get_player_list() == 1) { scale_current_matrix(&scale); } }

void TUnk_804A1570::update_idle() {
    if (1e-05f < scale.z) {
        scale.z -= 0.3f;
        if (scale.z < 1e-05f) {
            scale.z = 1e-05f;
        }
        scale.x = scale.y = scale.z;
    }
}

void TUnk_804A1570::update_attack() {
    if (scale.z < 1.0f) {
        scale.z += 0.3f;
        if (1.0f < scale.z) {
            scale.z = 1.0f;
        }
        scale.x = scale.y = scale.z;
    }
}

extern "C" {
void TUnk_804A1570::reserved_53() {
  s32 temp_r31;
  s32 new_var;
  temp_r31 = *((s32 *) (((s8 *) ((u8 *)this)) + 0xF4));
  new_var = (s32) this;
  draw_weapon_at_joint(new_var, 0x2F);
  update_trail_slot(0);
  update_trail_slot(1);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0xF4)) = (s32)this->second_model;
  draw_weapon_at_joint(new_var, 0x22);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0xF4)) = temp_r31;
}
}

TUnk_804A1570::~TUnk_804A1570() {}

TUnk_804A1570::TUnk_804A1570(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(513);
    scale.x = scale.y = scale.z = 0.0f;
}

u8 *TObjPlayer::create_state_513(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A1570(tl_05, (u8 *)arg0);
    }
    return NULL;
}
