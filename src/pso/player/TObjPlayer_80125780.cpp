#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer_80125780.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/player/TUnk_804A2564.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemProShield.h"

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
}
extern const f32 lbl_805DAD50;

void TObjPlayer::draw_faust_loaded_projectile() {
    void *temp_r31;
    void *temp_r3;

    if (TObjPlayer::get_player_list() == 1) {
        temp_r3 = *(void **)((s8 *)this + 0x188);
        if ((temp_r3 != NULL) && ((s32) *(s32 *)((s8 *)this + 0x234) == 0)) {
            temp_r31 = *(void **)((s8 *)temp_r3 + 0x2C);
            if (temp_r31 != NULL) {
                *(f32 *)((s8 *)temp_r31 + 0x20) = 0.1f;
                *(f32 *)((s8 *)temp_r31 + 0x24) = 0.1f;
                *(f32 *)((s8 *)temp_r31 + 0x28) = 0.1f;
                *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) & 0xFFFFFFFB);
                draw_ginja_object(*(void **)((s8 *)this + 0x188));
                *(s32 *)((s8 *)temp_r31 + 0) = (s32) (*(s32 *)((s8 *)temp_r31 + 0) | 4);
                *(f32 *)((s8 *)temp_r31 + 0x20) = 1.0f;
                *(f32 *)((s8 *)temp_r31 + 0x24) = 1.0f;
                *(f32 *)((s8 *)temp_r31 + 0x28) = 1.0f;
            }
        }
    }
}

void TUnk_804A2564::emit_marker_effects() { *(s32*)((char*)this + 0x234) = 60; }

void TUnk_804A2564::update_weapon() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x234);
    if (temp_r4 > 0) {
        *(s32 *)((s8 *)arg0 + 0x234) = (temp_r4 - 1);
    }
}

void clear_faust_reload_timer(void* p) { *(s32*)((char*)p + 0x234) = 0; }

extern s32 lbl_804A2564[];

void *__dt__13TUnk_804A2564Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2564;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *construct_panzer_faust(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A2564;
    *(f32 *)((s8 *)arg0 + 0x200) = 0.1f;
    ((TUnk_804A2564 *)arg0)->m_1fc = 0.1f;
    *(f32 *)((s8 *)arg0 + 0x1F8) = 0.1f;
    ((TUnk_804A2564 *)arg0)->m_234 = 0;
    *(f32 *)((s8 *)arg0 + 0x1E4) = (f32) lbl_805DAD50;
    ((TItemWeapon *)arg0)->set_weapon_flags(0x8000);
    if (((TItem *)arg0)->get_item_index() == 1) {
        *(f32 *)((s8 *)arg0 + 0x238) = (f32) lbl_805DAD50;
        ((TUnk_804A2564 *)arg0)->m_23c = 0x80;
    } else {
        *(f32 *)((s8 *)arg0 + 0x238) = 2.5f;
        ((TUnk_804A2564 *)arg0)->m_23c = 0;
    }
    return arg0;
}

u8 *create_panzer_faust(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x240));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_panzer_faust((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
