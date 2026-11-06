#include "types.h"
#include "pso/item/TUnk_804A65E0.h"
#include "pso/player/TObjPlayer_8012F8E8.h"
#include "pso/items/TItemWeapon.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8012F9BC.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012F9F0.h"
#include "pso/item/TItem.h"
#include "pso/system/FlagWord.h"
#include "pso/item/SpecialProjectileWeapons.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/item/TUnk_804A66D8.h"

extern "C" {

u8 *get_captured_target_entry(s32, s32);
s32 get_captured_target_count();
s32 get_extended_state__10TObjPlayerFv(int);

void TUnk_804A65E0::emit_marker_effects() {
    s32 temp_r3;
    u8 *var_r30;
    s32 i;
    u8 *captured_target_entry;
    u8 *arg0 = (u8 *)this;

    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)arg0)->get_joint_position(0, (arg0 + 0x1F8));
        temp_r3 = get_extended_state__10TObjPlayerFv((int) (*(s32 *)((s8 *)arg0 + 0xF0)));
        if (temp_r3 != 0) {
            ((TUnk_804A65E0 *)arg0)->m_204 = get_captured_target_count();
            var_r30 = arg0 + 0x208;
            i = 0;
            do {
                captured_target_entry = get_captured_target_entry(temp_r3, i);
                if (captured_target_entry != NULL) {
                    *(u16 *)((s8 *)var_r30 + 0) = (u16) *(u16 *)((s8 *)captured_target_entry + 0);
                    *(s16 *)((s8 *)var_r30 + 2) = (s16) *(s16 *)((s8 *)captured_target_entry + 2);
                    var_r30 += 8;
                }
                i += 1;
            } while (i != 0xA);
            if ((s32) ((TUnk_804A65E0 *)arg0)->m_204 != 0) {
                ((TTecGiZonde *)(*(s32 *)((s8 *)arg0 + 0xF0)))->create((u8 *)&this->unk_1F8, (u8 *)&this->m_204, (void *) (((TObjPlayer *)arg0)->get_tp()));
            }
            ((TItemWeapon *)arg0)->roll_technique();
        }
    } else {
        ((TObjPlayer *)arg0)->update_active_game_effect();
    }
}

}

void TUnk_804A65E0::vfunc_57() { ((TItemWeapon *)this)->roll_technique(); ((TItemWeapon *)this)->roll_technique(); }

extern s32 __vt__13TUnk_804A65E0[];

TUnk_804A65E0::~TUnk_804A65E0() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 __vt__13TUnk_804A65E0[];

void *TObjPlayer::initialize_effect_object() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A65E0;
    ((TObjPlayer *)((char *)this + 516))->construct_target_cursor_records();
    ((FlagWord *)((char *)this + 376))->set(32);
    ((TItemWeapon *)this)->set_weapon_flags(34);
    set_effect_state(5);
    return this;
}

}

extern "C" {
u8 * initialize_effect_object__10TObjPlayerFv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void launch_rare_weapon_special__10TObjPlayerFPvlf(void *, void *, s32, f32);

u8 *TObjPlayer::create_effect_object(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x260));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(initialize_effect_object__10TObjPlayerFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
