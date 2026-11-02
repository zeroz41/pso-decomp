#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/FlagWord.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/player/TUnk_804A4C78.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012B198.h"

extern "C" {

s32 rand();


s32 TObjPlayer::is_rand_below_threshold() {
    return (u32)__cntlzw(((3.0517578e-05f * (f32) rand()) < 0.3f)) >> 5;
}

}

struct Obj_8012AFF8 {
    u8 pad0[0xF4];
    s32 unkF4;
    u8 padF8[0x188 - 0xF8];
    s32 unk188;
};

extern "C" {
s32 is_rand_below_threshold__10TObjPlayerFv(void *);
void TUnk_804A4C78::reserved_53() {
    s32 saved;
    s32 savedF4;
    saved = sub_8012B1F8();
    savedF4 = ((Obj_8012AFF8 *)this)->unkF4;
    if (is_rand_below_threshold__10TObjPlayerFv(this) == 0) {
        sub_8012B1F0(8);
        item_render_state.set(4);
    }
    draw_weapon_model();
    if (sub_8012B1F8() != 8) {
        update_trail_slot(0);
    }
    ((Obj_8012AFF8 *)this)->unkF4 = ((Obj_8012AFF8 *)this)->unk188;
    if (is_rand_below_threshold__10TObjPlayerFv(this) == 0) {
        sub_8012B1F0(8);
        item_render_state.set(4);
    } else {
        sub_8012B1F0(saved);
    }
    draw_weapon_at_joint((s32)this, 0x23);
    if (sub_8012B1F8() != 8) {
        update_trail_slot(1);
    }
    ((Obj_8012AFF8 *)this)->unkF4 = savedF4;
    sub_8012B1F0(saved);
}

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *, s32, u8 *);

extern s32 p_arms_blade_weapon_vtable[];

void *TObjPlayer__sub_8012B0F8(void *player, s32 parent, u8 *item) {
    __ct__11TItemWeaponFP7TObjectPUc(player, parent, item);
    *(s32 **)((s8 *)player + 0x18) = p_arms_blade_weapon_vtable;
    ((TItemWeapon *)player)->set_weapon_flags(513);
    return player;
}

}

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_obj_8012B140(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_8012B0F8(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

extern s32 p_arms_blade_weapon_vtable[];

void *__dt__13TUnk_804A4C78Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = p_arms_blade_weapon_vtable;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TUnk_804A4C78::sub_8012B1F0(s16 v) { *(s16*)((char*)this + 0x1e8) = v; }
s16 TUnk_804A4C78::sub_8012B1F8() { return *(s16*)((char*)this + 0x1e8); }
