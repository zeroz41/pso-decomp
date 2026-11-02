#include "types.h"
#include "pso/unk/TUnk_804A5838.h"
#include "pso/player/TObjPlayer_8012D034.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_8012D354.h"
#include "pso/item/TItemProShield.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012D410.h"

extern "C" {

int rotate_matrix_z(void*, void*);
int get_player_list__10TObjPlayerFv(void*);

void TUnk_804A5838::update_idle() { *(s32*)((char*)this + 0x1f8) = 0; }
void TUnk_804A5838::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 0) { rotate_matrix_z((void*)0, *(void* *)&this->unk_1F8); } }

}

extern "C" {
s32 test_action_mask__10TObjPlayerFl(void *, s32);
#pragma push
#pragma fp_contract on
void TUnk_804A5838::update_attack() {
    s32 flag;
    s32 ok;
    s32 lo;
    s32 hi;
    f32 speed;
    f32 flo;
    f32 fhi;
    if (this->owner != NULL) {
        speed = ((TObjChara *)(this->owner))->get_frame();
        flag = ((TObjPlayer *)(this->owner))->is_flag_b0_4();
        ok = 1;
        if (test_action_mask__10TObjPlayerFl(this->owner, 0x20) != 0) {
            flo = 15.6f;
            lo = 0;
            fhi = 20.4f;
            hi = 0x4000;
        } else if (test_action_mask__10TObjPlayerFl(this->owner, 0x40) != 0) {
            flo = 12.0f;
            lo = 0x4000;
            fhi = 24.0f;
            hi = -0x4000;
        } else if (test_action_mask__10TObjPlayerFl(this->owner, 0x80) != 0) {
            flo = 14.4f;
            lo = -0x4000;
            fhi = 20.0f;
            hi = 0x2000;
        } else {
            ok = 0;
        }
        if (ok == 1) {
            if (flag == 0) {
                if (speed < flo) {
                    *(s32 *)&this->unk_1F8 = lo;
                } else if (flo <= speed && speed <= fhi) {
                    *(s32 *)&this->unk_1F8 = (s32)((speed - flo) * ((f32)(hi - lo) / (fhi - flo)) + (f32)lo);
                } else {
                    *(s32 *)&this->unk_1F8 = hi;
                }
            } else {
                *(s32 *)&this->unk_1F8 = hi;
            }
        }
    }
}
#pragma pop

}

extern "C" {

s32 get_owner_client__5TItemFv(void *);
u8 get_item_index__5TItemFv();
s32 __nw__15TItemHeapObjectFUl(s32);
s32 create_ex__9TTecMegidFllll(void *, s32 *, s32, s32);
s32 ct__13TUnk_804A0688Fv(s32, u32, s32, s32);

void TUnk_804A5838::vfunc_57() {
    s32 temp_r3;
    s32 temp_r3_2;

    if ((u32) *(u32 *)((s8 *)this + 0x174) != 0U) {
        if (get_item_index__5TItemFv() == 0) {
            temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
            if (temp_r3 != 0) {
                ct__13TUnk_804A0688Fv(temp_r3, *(u32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x96);
            }
        } else {
            temp_r3_2 = __nw__15TItemHeapObjectFUl(0x2C);
            if (temp_r3_2 != 0) {
                ct__13TUnk_804A0688Fv(temp_r3_2, *(u32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x5A);
            }
        }
    }
}

extern s32 tl_05;

void TObjPlayer::trigger_megid_special() {
    s32 sp8;
    void *tec_megid;

    if (get_item_index__5TItemFv() == 1) {
        ((TObjPlayer *)tl_05)->create_item_eff_cane((TItem*)this, 2, 0x101);
        if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
            if (((TItemWeapon *)this)->get_joint_position(2, &sp8) != 0) {
                tec_megid = *(void * *)&this->blend.frame[1];
                create_ex__9TTecMegidFllll(tec_megid, &sp8, *(s32 *)((s8 *)tec_megid + 0x60), 0);
                drain_owner_hp_fraction(0.07f);
            }
        } else {
            update_active_game_effect();
        }
    }
}

}

struct RecoveredGlobal_8012D354_lbl_804A5838 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
}
extern RecoveredGlobal_8012D354_lbl_804A5838 lbl_804A5838;

typedef char RecoveredGlobal_8012D354_lbl_804A5838_size[sizeof(RecoveredGlobal_8012D354_lbl_804A5838) == 0xF8 ? 1 : -1];
u8 *construct_soul_eater_weapon(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A5838.value;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    if (((TItem *)arg0)->get_item_index() == 1) {
        ((TItemWeapon *)arg0)->set_weapon_flags(0x22);
    }
    return arg0;
}

u8 *create_soul_eater_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_soul_eater_weapon((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}


void *__dt__13TUnk_804A5838Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A5838.value;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
