#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_804A68C8.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemProShield.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_80130178.h"
#include "pso/unk/text_801301D0.h"

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
}

extern s32 lbl_804A68C8[];

void TUnk_804A68C8::update_attack() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_1fc == 0) {
        switch ((s32) (((TItem *)arg0)->get_item_index())) {
        case 5:
            break;
        case 4:
            if (((TItemWeapon *)arg0)->get_attack_stage() == 0) {
                ((TObjPlayer *)tl_05)->create_item_eff_cane((TItem*)arg0, 1, 0x1AE);
            }
            break;
        case 6:
            if (((TItemWeapon *)arg0)->get_attack_stage() == 0) {
                ((TObjPlayer *)tl_05)->create_item_eff_cane((TItem*)arg0, 2, 0x101);
            }
            break;
        }
        this->m_1fc = 1;
    }
    if (((TItem *)arg0)->get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.1f, (f32)1.0f);
    }
}

void *__dt__13TUnk_804A68C8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A68C8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *construct_cane_weapon(u8 *arg0, u8 *arg1, u8 *arg2) {
    TItemWeapon__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A68C8[0];
    *(f32 *)((s8 *)arg0 + 0x1F8) = (f32) 1.0f;
    ((TUnk_804A68C8 *)arg0)->m_1fc = 0;
    if ((u8) *(u8 *)((s8 *)arg2 + 2) >= 4U) {
        ((TObjPlayer *)arg0)->set_atp(-1);
    }
    return arg0;
}

u8 *create_cane_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_cane_weapon((u8 *)temp_r3, (u8 *)tl_05, (u8 *)arg0));
        }
        return var_r0;
    }
    return NULL;
}
