#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/player/TUnk_804F1320.h"
#include "pso/item/TItemMag.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80355BA0_lbl_804F1320 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 * TItemWeapon__ct(void *, void *);
extern s32 lbl_804F1320[];
extern const f32 lbl_805DFFC0;
extern const f32 lbl_805DFFC4;
u8 *photon_field_weapon_ct(TObjPlayer *arg0, u8 *arg1);
void *__dt__13TUnk_804F1320Fv(void *arg0, s16 arg1);
s32 get_current_floor();
s8 get_mode__5TItemFv(u8 *arg0);
void *__dt__11TItemWeaponFv(void *arg0, s16 arg1);
s32 reset_key_machine_state__10TObjPlayerFv();

void TUnk_804F1320::vfunc_17(s32 item) {
    s32 temp_r31;

    if (((u32) this->player != 0U) && (reset_key_machine_state__10TObjPlayerFv() != 0)) {
        temp_r31 = ((TObjPlayer *)(this->player))->get_field_3e4();
        {
        s32 t = get_current_floor();
        if ((t == temp_r31) && (get_mode__5TItemFv((u8 *)this) == 2)) {
            spawn_pg_effect((void *)(*(u32 *)&this->player + 0x2FC), (s32)item, (f32)(*(f32 *)&this->unk_1F8));
        }
        }
    }
}
void TUnk_804F1320::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    if (((TObjPlayer *)arg0)->is_mode_two_and_ready() != 0) {
        temp_r3 = ((TItemMag *)(this->player))->get_sub_value();
        if (temp_r3 >= 0x14) {
            ((TItem *)arg0)->send_activate_effect(temp_r3);
            return;
        }
        ((TObjPlayer *)arg0)->update_active_game_effect();
        return;
    }
    ((TObjPlayer *)arg0)->update_active_game_effect();
}
typedef char RecoveredGlobal_80355BA0_lbl_804F1320_size[sizeof(RecoveredGlobal_80355BA0_lbl_804F1320) == 0xF8 ? 1 : -1];

void *__dt__13TUnk_804F1320Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F1320;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
u8 *photon_field_weapon_ct(TObjPlayer *player, u8 *arg1) {
    TItemWeapon__ct(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80355BA0_lbl_804F1320 *)&lbl_804F1320).value;
    player->set_status_flags(0x22);
    if (((TItem *)player)->get_item_group() == 0x3D) {
        *(f32 *)((s8 *)player + 0x1F8) = (f32) lbl_805DFFC0;
        player->set_status_flags(0x100000);
    } else {
        *(f32 *)((s8 *)player + 0x1F8) = (f32) lbl_805DFFC4;
    }
    return (u8 *)player;
}

}
