#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80122388.h"
#include "pso/item/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804A0FA0.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/unk/text_801224D4.h"

struct Self_801223E0 { u8 pad[0x1f8]; f32 f1f8; };

extern "C" {
u8 * guld_milla_ct(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void scale_matrix(s32, f32, f32, f32);

void apply_blade_dance_model_scale(Self_801223E0 *self);
}
u8 *create_guld_milla(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x210));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(guld_milla_ct(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void apply_blade_dance_model_scale(Self_801223E0 *self) {
    if (((TItem *)self)->get_item_index() == 5) {
        s32 n = TObjPlayer::get_player_list();
        switch (n) {
        case 3:
        case 4:
            scale_matrix(0, 1.0f, self->f1f8, self->f1f8);
            break;
        }
    }
}

extern "C" {

u8 get_item_index__5TItemFv();

void TUnk_804A0FA0::update_idle() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.2f, (f32)0.0f);
    }
}

void TUnk_804A0FA0::update_attack() {
    s32 arg0 = (s32)this;
    if (get_item_index__5TItemFv() == 5) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)0.5f, (f32)1.0f);
    }
}

}

struct RecoveredGlobal_801224D4_lbl_804A0FA0 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
}
extern RecoveredGlobal_801224D4_lbl_804A0FA0 lbl_804A0FA0;

typedef char RecoveredGlobal_801224D4_lbl_804A0FA0_size[sizeof(RecoveredGlobal_801224D4_lbl_804A0FA0) == 0xF8 ? 1 : -1];
u8 *construct_dagger_weapon(u8 *player, u8 *arg1, u8 *arg2) {
    u8 temp_r0;
    TItemWeapon__ct(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &lbl_804A0FA0.value;
    ((TObjPlayer *)player)->set_status_flags(0x600);
    *(f32 *)((s8 *)player + 0x1F8) = (f32) 1.0f;
    temp_r0 = *(u8 *)((s8 *)arg2 + 2);
    if ((temp_r0 >= 5U) && (temp_r0 != 7)) {
        ((TObjPlayer *)player)->set_atp(-1);
    }
    return player;
}

u8 *create_dagger_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_dagger_weapon((u8 *)temp_r3, (u8 *)tl_05, (u8 *)arg0));
        }
        return var_r0;
    }
    return NULL;
}
