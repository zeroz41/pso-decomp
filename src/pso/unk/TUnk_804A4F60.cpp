#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/TUnk_804A4F60.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8012BC28.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/unk/text_8012BCD4.h"

void psycho_wand_node_callback(void *arg0);
extern "C" {
s32 rotate_matrix_z(s32, s32);
s32 add_actor_tp(u8 *arg0, s32 arg1);
s32 get_attack_stage__11TItemWeaponFv();
s32 reset_key_machine_state__10TObjPlayerFv();
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
s16 get_actor_tp(u8 *p);

void TUnk_804A4F60::update_weapon() {
    s16 temp_r0;
    s16 temp_r3;

    if (reset_key_machine_state__10TObjPlayerFv() != 0) {
        temp_r3 = get_actor_tp((u8 *)this->player);
        temp_r0 = *(s16 *)((s8 *)this + 0x1F8) - temp_r3;
        if (temp_r0 != 0) {
            *(s16 *)((s8 *)this + 0x1F8) = temp_r3;
        }
        if (temp_r0 > 0) {
            TObjectV8047c128_subtract_hp((u8 *)this->player, temp_r0);
            add_actor_tp((u8 *)this->player, (s16) (temp_r0 / 2));
        }
    }
}

extern s32 tl_05;

void TUnk_804A4F60::emit_marker_effects() {
    s32 item = (s32)this;
    if (get_attack_stage__11TItemWeaponFv() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 4);
    }
    if (((TObjPlayer *)item)->is_mode_two_and_ready() != 0) {
        ((TUnk_804A4F60 *)item)->psycho_wand_roll_extra();
        return;
    }
    ((TObjPlayer *)item)->update_active_game_effect();
}
}

void psycho_wand_node_callback(void *arg0) {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_z(0, *(s32 *)((s8 *)arg0 + 0x278));
        return;
    case 5:
        rotate_matrix_z(0, -*(s32 *)((s8 *)arg0 + 0x278));
        return;
    case 1:
        translate_matrix(0, 0.0f, (-1.0f) * ((TUnk_804A4F60 *)arg0)->m_274, 0.0f);
        return;
    case 3:
    case 4:
    case 6:
        TItem::begin_effect_render();
        return;
    }
}

void TUnk_804A4F60::update_idle() {
    u8 *arg0 = (u8 *)this;
    TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x278), 0x38E, 0x2AAA);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x278) == 0x2AAA) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x274), (f32)0.5f, (f32)6.0f);
    }
}

void TUnk_804A4F60::update_attack() {
    u8 *arg0 = (u8 *)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x274), (f32)(-2.0f), (f32)0.0f);
    if (0.0f == this->m_274) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x278), -0x71C, 0);
    }
}

struct RecoveredGlobal_8012BCD4_lbl_804A4F60 { s32 value; u8 remaining[0xF4]; };
typedef char RecoveredGlobal_8012BCD4_lbl_804A4F60_size[sizeof(RecoveredGlobal_8012BCD4_lbl_804A4F60) == 0xF8 ? 1 : -1];

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * TItemWeapon__ct(void *, void *);
}
extern RecoveredGlobal_8012BCD4_lbl_804A4F60 psycho_wand_weapon_vtable;

u8 *psycho_wand_ct(u8 *arg0, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &psycho_wand_weapon_vtable.value;
    ((TObjPlayer *)(arg0 + 0x208))->construct_target_cursor_records();
    ((TObjPlayer *)arg0)->set_status_flags(0x22);
    *(s32 *)((s8 *)arg0 + 0x278) = 0;
    ((TUnk_804A4F60 *)arg0)->m_274 = (f32) 0.0f;
    *(s16 *)((s8 *)arg0 + 0x1F8) = -1;
    ((TUnk_804A4F60 *)arg0)->m_204 = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x200) = (f32) 0.0f;
    ((TUnk_804A4F60 *)arg0)->m_1fc = (f32) 0.0f;
    ((TUnk_804A4F60 *)arg0)->m_264 = 0;
    *(s32 *)((s8 *)arg0 + 0x208) = 0;
    return arg0;
}

u8 *create_psycho_wand(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x27c));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(psycho_wand_ct((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}
