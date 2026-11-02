#include "types.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/item/TItemWeaponMechgun.h"
#include "pso/unk/text_80120D50.h"
#include "pso/item/TUnk_804A3260.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void spawn_weapon_impact_effect();
extern s32 __vt__13TUnk_804A3260[];
}
void TUnk_804A3260::emit_marker_effects() {
    if (launch_shot((u8 *)muzzle[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)muzzle[1], 0, 0, 0);
    } else {
        launch_shot((u8 *)muzzle[1], 0, 0, 1);
    }
    advance_angle_wrap(&effectAngle, 0x2000);
    effectFrame = 1;
}

void TUnk_804A3260::update_weapon() {
    s32 temp_r4;
    if ((s32) this->effectScaleJoint != -1) {
        temp_r4 = this->effectFrame;
        if (0.0f < (f32) temp_r4) {
            this->effectFrame = (s32) ((f32) temp_r4 - 0.4f);
            if ((f32) this->effectFrame < 0.0f) {
                this->effectFrame = 0;
            }
        }
    }
}

void TUnk_804A3260::reserved_53() {
    u8 *arg0 = (u8 *)this;
    ((TObjPlayer *)arg0)->draw_status_icons((u8 *)this->muzzle[0], (u8 *)this->muzzle[1]);
}

void *TItemWeaponMechgun__ct(void *arg0, s32 parent, void *item) {
    __ct__11TItemWeaponFP7TObjectPUc((TItemWeapon *)((u8 *)arg0), (void *)parent, (u8 *)item);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804A3260;
    ((TItemWeapon *)arg0)->set_weapon_flags(0x203);
    *(void (**)())((s8 *)arg0 + 0x1EC) = &spawn_weapon_impact_effect;
    ((TUnk_804A3260 *)arg0)->effectJoint = -1;
    *(s32 *)((s8 *)arg0 + 0x214) = 0;
    ((TUnk_804A3260 *)arg0)->effectScaleJoint = -1;
    *(s32 *)((s8 *)arg0 + 0x21C) = 0;
    switch ((s32) (*(u8 *)((s8 *)item + 2))) {
    case 6:
        break;
    case 5:
        ((TUnk_804A3260 *)arg0)->effectJoint = 2;
        break;
    case 7:
        ((TUnk_804A3260 *)arg0)->effectJoint = 2;
        break;
    }
    if ((u8) *(u8 *)((s8 *)item + 2) >= 5U) {
        ((TObjPlayer *)arg0)->set_atp(-1);
    }
    return arg0;
}

u8 *create_mechgun_weapon(u8 *item) {
    u8 *temp_r3;
    u8 *var_r0;
    if (item != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x220));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TItemWeaponMechgun__ct(temp_r3, tl_05, item));
        }
        return var_r0;
    }
    return NULL;
}
