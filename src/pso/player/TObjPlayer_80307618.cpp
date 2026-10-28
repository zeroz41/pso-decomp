#include "types.h"
#include "pso/player/TUnk_804E71A0.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer_80307618.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804E70A8.h"
#include "pso/item/TItem.h"


struct RecoveredGlobal_80307784_lbl_804E70A8 {
    s32 value;
    u8 remaining[0xF4];
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
extern const f32 lbl_805DF0AC;
u8 get_item_index__5TItemFv(void *);
u8 * TItemWeapon__ct(void *, void *);
s32 set_status_flags__10TObjPlayerFUl(void *, s32);
extern s32 lbl_804E70A8[];
extern char shared_capture_texture_list[];
f32 sin_table_lookup(s32);
void TKeyBoardControl__sub_8000F91C(s32 arg0);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s32 draw_weapon_model__11TItemWeaponFv();
void draw_weapon_at_joint(s32 arg0, s8 arg1);
s32 queue_destruction__7TObjectFv();

void TUnk_804E70A8::reserved_53() {
    s32 temp_r31;

    temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0xF4);
    draw_weapon_model__11TItemWeaponFv();
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = (s32) this->projectile;
    draw_weapon_at_joint((s32)this, 0x23);
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = temp_r31;
}

extern f32 lbl_805DF0A8;

void TUnk_804E70A8::update_weapon() {
    if ((s32) *(s32 *)((s8 *)this + 0x1F8) > 0) {
        if (get_item_index__5TItemFv(this) == 1) {
            *(s32 *)((s8 *)this + 0x1F8) = (s32) (*(s32 *)((s8 *)this + 0x1F8) - 1);
            if ((s32) *(s32 *)((s8 *)this + 0x1F8) == 0) {
                set_status_flags__10TObjPlayerFUl(this, 0x800);
            }
        }
    } else {
        *(s32 *)&this->unk_200 = (s32) (*(s32 *)&this->unk_200 + 0xB6);
        this->m_1fc = (s32) (lbl_805DF0A8 * sin_table_lookup(*(s32 *)&this->unk_200));
    }
}

void TObjPlayer__sub_803076F8(u8 *arg0) {
    s32 player_list;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x1F8) == 0) {
        player_list = TObjPlayer::get_player_list();
        ((TItem *)arg0)->begin_particle_tev();
        TObjPlayer::load_projection_tex((s32)arg0, (s32)((int) ((s32) (lbl_805DF0AC * (f32) (((TUnk_804E70A8 *)arg0)->m_1fc + (player_list * 3))))));
    }
}

typedef char RecoveredGlobal_80307784_lbl_804E70A8_size[sizeof(RecoveredGlobal_80307784_lbl_804E70A8) == 0xF8 ? 1 : -1];
u8 *TObjPlayer__sub_80307784(TObjPlayer *player, u8 *arg1, s32 _w2) {
    TItemWeapon__ct(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80307784_lbl_804E70A8 *)&lbl_804E70A8).value;
    set_status_flags__10TObjPlayerFUl(player, 1);
    if (get_item_index__5TItemFv(player) == 1) {
        set_status_flags__10TObjPlayerFUl(player, 0x800);
    }
    *(s32 *)((s8 *)player + 0x1F8) = 5;
    ((TUnk_804E70A8 *)player)->m_1fc = 0;
    *(s32 *)((s8 *)player + 0x200) = 0;
    return (u8 *)player;
}

u8 *TObjPlayer__sub_80307800(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x204));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_80307784((TObjPlayer *)((u8 *)temp_r3), (u8 *)((u8 *)tl_05), (s32)((s32)arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void *__dt__13TUnk_804E70A8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E70A8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
}
char *get_shared_capture_texture_list(void) {
    return shared_capture_texture_list;
}

void TUnk_804E71A0::render() {  }

extern s32 ending_movie_active_flag;

void TObjPlayer::disable_keyboard_control() {
    queue_destruction__7TObjectFv();
    if ((s32) ending_movie_active_flag != 0) {
        TKeyBoardControl__sub_8000F9CC(2);
        return;
    }
    TKeyBoardControl__sub_8000F91C(2);
    TKeyBoardControl__sub_8000F9CC(0x12);
}

void TUnk_804E71A0::run_task() {  }


TUnk_804E71A0::~TUnk_804E71A0() {

}
