#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 get_owner_client__5TItemFv(void *);
u8 get_item_index__5TItemFv();
s32 __nw__15TItemHeapObjectFUl(s32);
s32 create_ex__9TTecMegidFllll(void *, s32 *, s32, s32);
s32 ct__13TUnk_804A0688Fv(s32, u32, s32, s32);

void TObjPlayer::create_shield() {
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
extern f32 lbl_805DAF18;

void TObjPlayer::trigger_megid_special() {
    s32 sp8;
    void *tec_megid;

    if (get_item_index__5TItemFv() == 1) {
        ((TObjPlayer *)tl_05)->create_item_eff_cane((TItem*)this, 2, 0x101);
        if (((TItemWeapon *)this)->is_mode_two_and_ready() != 0) {
            if (((TItemWeapon *)this)->get_joint_position(2, &sp8) != 0) {
                tec_megid = *(void * *)&this->unk_F0;
                create_ex__9TTecMegidFllll(tec_megid, &sp8, *(s32 *)((s8 *)tec_megid + 0x60), 0);
                drain_owner_hp_fraction(lbl_805DAF18);
            }
        } else {
            update_active_game_effect();
        }
    }
}

}
