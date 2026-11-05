#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A2260.h"
#include "pso/player/TObjPlayer.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TUnk_804A2358.h"
#include "pso/misc/TTecFoie.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);

extern f32 lbl_805DAD3C;

void TUnk_804A2260::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)((u8 *)this->owner + 0x7CC))->get_stage_strike_count() == 0) {
            ((TObjPlayer *)this)->drain_owner_hp_fraction(lbl_805DAD3C);
            sub_80124C90();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}

void TUnk_804A2260::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
        return;
    case 4:
        TItem::begin_effect_render();
        rotate_matrix_z(0, -*(s32 *)&this->unk_1F8);
        return;
    }
}

void TUnk_804A2260::update_weapon() {
    *(s32 *)&this->unk_1F8 = (s32) (*(s32 *)&this->unk_1F8 + 0xAAA);
}

}

TUnk_804A2260::~TUnk_804A2260() {

}

struct RecoveredGlobal_801250F8_lbl_804A2260 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
extern RecoveredGlobal_801250F8_lbl_804A2260 __vt__13TUnk_804A2260;
extern const f32 lbl_805DAD40;

typedef char RecoveredGlobal_801250F8_lbl_804A2260_size[sizeof(RecoveredGlobal_801250F8_lbl_804A2260) == 0xF8 ? 1 : -1];
u8 *TObjPlayer__sub_801250F8(u8 *player, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &__vt__13TUnk_804A2260.value;
    ((TItemWeapon *)player)->set_weapon_flags(0x100022);
    *(f32 *)((s8 *)player + 0x1E4) = (f32) lbl_805DAD40;
    *(s32 *)((s8 *)player + 0x1F8) = 0;
    return player;
}

u8 *TObjPlayer::create_state_80125154(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_801250F8((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern "C" {


s16 TObjPlayer::get_stage_strike_count() { return *(s16*)((char*)this + 0x12); }

}
