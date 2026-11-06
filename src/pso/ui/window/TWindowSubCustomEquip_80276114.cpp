#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"

extern "C" {
s32 select_action_palette__10TObjPlayerFi(s32, s32);
void *get_player_by_client_id(s32 i);
u8 *TWindowActionPalette__sub_801C1D7C(s32 arg0, s32 i, s32 arg2);
s16 get_slot_type__20TWindowActionPaletteFlll(s32, s32, s32);
s32 is_type_valid__21TWindowSubCustomEquipFv(void *, u8);
s32 get_saved_slot_for_index__21TWindowSubCustomEquipFlSc(void *, u8);
void TWindowSubCustomEquip::get_cursor_pos(void *arg1) {
    s32 i;
    s32 temp_r3;
    s32 saved_slot;
    s32 temp_r29;

    if ((temp_r3 = (s32)get_player_by_client_id(this->m_20), (temp_r3 == 0U)) || (temp_r29 = select_action_palette__10TObjPlayerFi(temp_r3, 0), ((temp_r29 == 0) != 0))) {
        *(s16 *)((s8 *)arg1 + 0) = 0;
        *(s16 *)((s8 *)arg1 + 2) = 0;
        return;
    }
    i = is_type_valid__21TWindowSubCustomEquipFv(this, this->m_62);
    saved_slot = get_saved_slot_for_index__21TWindowSubCustomEquipFlSc(this, this->m_61);
    *(s16 *)((s8 *)arg1 + 0) = get_slot_type__20TWindowActionPaletteFlll(temp_r29, i, saved_slot);
    *(s16 *)((s8 *)arg1 + 2) = (s16)TWindowActionPalette__sub_801C1D7C(temp_r29, i, saved_slot);
}
void TWindowSubCustomEquip::remove_duplicate_bindings(void *arg1) {
    s32 temp_r3;
    s32 temp_r29;
    if ((temp_r3 = (s32)get_player_by_client_id(this->m_20), (temp_r3 == 0U)) || (temp_r29 = select_action_palette__10TObjPlayerFi(temp_r3, 0), ((temp_r29 == 0) != 0))) {
        return;
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFlll(temp_r29, 0, 1) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 0, 1)) {
        ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, 0, 1, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFlll(temp_r29, 0, 3) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 0, 3)) {
        ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, 0, 3, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFlll(temp_r29, 0, 2) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 0, 2)) {
        ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, 0, 2, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFlll(temp_r29, 1, 1) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 1, 1)) {
        ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, 1, 1, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFlll(temp_r29, 1, 3) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 1, 3)) {
        ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, 1, 3, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFlll(temp_r29, 1, 2) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 1, 2)) {
        ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, 1, 2, 0, 0);
    }
}
void TWindowSubCustomEquip::toggle_action_binding(void *arg1) {
    s32 temp_r3;
    s32 temp_r29;
    s32 valid;
    s32 idx;
    if ((temp_r3 = (s32)get_player_by_client_id(this->m_20), (temp_r3 == 0U)) || (temp_r29 = select_action_palette__10TObjPlayerFi(temp_r3, 0), ((temp_r29 == 0) != 0))) {
        return;
    }
    valid = is_type_valid__21TWindowSubCustomEquipFv(this, this->m_62);
    idx = get_saved_slot_for_index__21TWindowSubCustomEquipFlSc(this, this->m_61);
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFlll(temp_r29, valid, idx) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, valid, idx)) {
        ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, valid, idx, 0, 0);
        return;
    }
    remove_duplicate_bindings(arg1);
    ((TObjPlayer *)temp_r3)->set_action_palette_entry(0, valid, idx, *(u16 *)((s8 *)arg1 + 0), *(u16 *)((s8 *)arg1 + 2));
}

}
