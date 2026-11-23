#include "types.h"
#include "pso/weapon/TUnk_804A3260.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/weapon/TItemWeaponMechgun.h"
#include "pso/unk/text_80120D50.h"
#include "pso/item/TItem.h"

extern "C" {

s32 rotate_matrix_y(s32, s32);

void TUnk_804A3260::vfunc_60() {
    if ((s32) this->effectJoint == TObjPlayer::get_player_list()) {
        rotate_matrix_y(0, this->effectAngle);
    }
}

extern s32 tl_05;
void spawn_weapon_impact_effect();
}
void TUnk_804A3260::emit_marker_effects() {
    if (launch_shot((u8 *)&muzzle[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&muzzle[1], 0, 0, 0);
    } else {
        launch_shot((u8 *)&muzzle[1], 0, 0, 1);
    }
    advance_angle_wrap(&effectAngle, 0x2000);
    effectFrame = 1;
}

void TUnk_804A3260::update_weapon() {
    s32 effectFrame;
    if ((s32) this->effectScaleJoint != -1) {
        effectFrame = this->effectFrame;
        if (0.0f < (f32) effectFrame) {
            this->effectFrame = (s32) ((f32) effectFrame - 0.4f);
            if ((f32) this->effectFrame < 0.0f) {
                this->effectFrame = 0;
            }
        }
    }
}

void TUnk_804A3260::reserved_53() {
    u8 *arg0 = (u8 *)this;
    ((TItemWeapon *)arg0)->sample_dual_muzzles(&this->muzzle[0], &this->muzzle[1]);
}

TUnk_804A3260::TUnk_804A3260(saddr parent, u8 *item) : TItemWeapon((TObject *)((void *)parent), item) {
    this->set_weapon_flags(0x203);
    *(void (**)())((s8 *)this + 0x1EC) = &spawn_weapon_impact_effect;
    this->effectJoint = -1;
    this->effectAngle = 0;
    this->effectScaleJoint = -1;
    this->effectFrame = 0;
    switch ((s32) (*(u8 *)((s8 *)item + 2))) {
    case 6:
        break;
    case 5:
        this->effectJoint = 2;
        break;
    case 7:
        this->effectJoint = 2;
        break;
    }
    if ((u8) *(u8 *)((s8 *)item + 2) >= 5U) {
        set_color_node(-1);
    }
}

TItem *create_mechgun_weapon(u8 *item) {
    u8 *temp_r3;
    u8 *var_r0;
    if (item != NULL) {
        temp_r3 = (u8 *)((u8 *)TItem::operator new(0x220));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(__ct__13TUnk_804A3260FlPUc(temp_r3, tl_05, item));
        }
        return reinterpret_cast<TItem *>(var_r0);
    }
    return NULL;
}

TUnk_804A3260::~TUnk_804A3260() {

}
