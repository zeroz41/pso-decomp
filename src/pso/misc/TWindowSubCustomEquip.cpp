#include "types.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TWindowSubCustomEquip.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80276D14_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80277014_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Vec2_8027654C { f32 x; f32 y; };

struct Vec2_802766C8
{
  f32 x;
  f32 y;
};

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
s32 forward_render__20TWindowSubStatusDispFv(int, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern f32 TWindowSubCustomEquip__ring_scale;
extern u8 TWindowSubCustomEquip__bank_ring_init_done;
extern f32 lbl_805D6478;
extern u8 lbl_805D647C;
extern const f32 lbl_805DD578;
extern const f32 lbl_805DD584;
extern const f32 lbl_805DD588;
extern const f32 lbl_805DD58C;
extern const f32 lbl_805DD590;
extern const f32 lbl_805DD594;
extern const f32 lbl_805DD598;
extern const f32 lbl_805DD59C;
extern const f32 lbl_805DD5A0;
s32 fn_8002AE08(int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
s32 apply_choice__20TWindowChoiceSettingFllll(void *, int, int, int);
s32 play_sound_effect(s32, s32, s32, s32);
extern RecoveredGlobal_80276D14_lbl_8050E208 controller_input_state;
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
extern const f32 lbl_805DD5A4;
s32 set_help_text__15TWindowHelpItemFll(u8 *, s32);
extern const f32 lbl_805DD570;
extern const f32 lbl_805DD574;
s32 select_action_palette__10TObjPlayerFi(u8 *, s32);
void *get_player_by_client_id(s32 i);
u8 *TWindowActionPalette__sub_801C1D7C(s32 arg0, s32 i, s32 arg2);
s32 get_slot_type__20TWindowActionPaletteFlll(s32, s32, s32);
extern const Vec2_802766C8 custom_equip_entry_offset_table[];
extern const f32 lbl_805DD57C;
extern const f32 lbl_805DD580;
void __dl__7TObjectFPv(void *);

extern const f32 lbl_805DD568;
extern const f32 lbl_805DD56C;

void TWindowSubCustomEquip::set_relative_pos(void *arg1) {
    *(f32 *)&this->m_name = (f32) (*(f32 *)((s8 *)arg1 + 8) - lbl_805DD568);
    *(f32 *)&this->m_flags = (f32) (*(f32 *)((s8 *)arg1 + 0xC) - lbl_805DD56C);
}

int TWindowSubCustomEquip::layout_selection_parts(void *arg1) {
    Vec2_8027654C pos;
    u8 *p;
    u8 *a;
    u8 *b;
    u8 *c;
    u8 *d;
    if (*(s8 *)&this->m_64 == 0) {
        a = (u8 *)get_array_entry(0x11);
        b = (u8 *)get_array_entry(0x10);
        c = (u8 *)get_array_entry(8);
        d = (u8 *)get_array_entry(7);
        p = (u8 *)get_array_entry(9);
    } else {
        a = (u8 *)get_array_entry(8);
        b = (u8 *)get_array_entry(7);
        c = (u8 *)get_array_entry(0x11);
        d = (u8 *)get_array_entry(0x10);
        p = (u8 *)get_array_entry(0);
    }
    pos.x = lbl_805DD570 + *(f32 *)((s8 *)p + 8);
    pos.y = lbl_805DD574 + *(f32 *)((s8 *)p + 0xC);
    set_help_text__15TWindowHelpItemFll(b, this->m_20);
    ((TWindowSubSymbolChatPartsSet *)(a + 8))->copy_vec2(&pos);
    ((TWindowSubSymbolChatPartsSet *)(b + 8))->copy_vec2(&pos);
    *(f32 *)((s8 *)a + 0x18) = *(f32 *)((s8 *)p + 0x18);
    *(f32 *)((s8 *)b + 0x18) = *(f32 *)((s8 *)p + 0x18);
    *(s32 *)((s8 *)a + 0x2C) = *(s32 *)((s8 *)p + 0x2C);
    *(u16 *)((s8 *)a + 0) &= ~2;
    *(u16 *)((s8 *)b + 0) &= ~2;
    *(u16 *)((s8 *)c + 0) |= 2;
    *(u16 *)((s8 *)d + 0) |= 2;
}

typedef struct Vec2_802766C8 Vec2_802766C8;
void TWindowSubCustomEquip::layout_entry_group(void *arg1) {
  u8 *base;
  u8 *e1;
  u8 *e2;
  u32 i;
  s32 idx;
  s32 v;
  base = (u8 *) get_array_entry((s32) arg1);
  for (i = 0; i < 3; i++)
  {
    idx = ((s32) arg1) + i;
    e1 = (u8 *) get_array_entry(idx + 1);
    e2 = (u8 *) get_array_entry(idx + 4);
    *((f32 *) (((s8 *) e1) + 8)) = (*((f32 *) (((s8 *) base) + 8))) + custom_equip_entry_offset_table[i].x;
    *((f32 *) (((s8 *) e1) + 0xC)) = (*((f32 *) (((s8 *) base) + 0xC))) + custom_equip_entry_offset_table[i].y;
    *((f32 *) (((s8 *) e1) + 0x18)) = lbl_805DD578 + (*((f32 *) (((s8 *) base) + 0x18)));
    *((f32 *) (((s8 *) e2) + 0x18)) = lbl_805DD57C + (*((f32 *) (((s8 *) base) + 0x18)));
    *((s32 *) (((s8 *) e2) + 0x1C)) = *((s32 *) (((s8 *) base) + 0x2C));
    v = lbl_805DD580 * (((unsigned char) ((*((u32 *) (((s8 *) base) + 0x2C))) & 0xFF)) * ((*((u32 *) (((s8 *) e1) + 0x2C))) & 0xFF));
    *((u32 *) (((s8 *) e1) + 0x2C)) = (v & 0xFF) | ((((v & 0xFF) << 16) | 0xFF000000) | ((v & 0xFF) << 8));
  }
}

void TWindowSubCustomEquip::reset_selection() { layout_entry_group((void *)((void*)9)); layout_entry_group((void *)((void*)0)); layout_selection_parts((void *)((void*)9)); }

s32 TWindowSubCustomEquip::refresh_palette_slots() {
    u8 *player;
    s32 pal;
    player = (u8 *)get_player_by_client_id(this->m_20);
    if (player == NULL || (pal = select_action_palette__10TObjPlayerFi(player, 0)) == 0) {
        return;
    }
    update_palette_slot(0, get_slot_type__20TWindowActionPaletteFlll(pal, *(s8 *)&this->m_64, 2), (s32)TWindowActionPalette__sub_801C1D7C(pal, *(s8 *)&this->m_64, 2));
    update_palette_slot(1, get_slot_type__20TWindowActionPaletteFlll(pal, *(s8 *)&this->m_64, 1), (s32)TWindowActionPalette__sub_801C1D7C(pal, *(s8 *)&this->m_64, 1));
    update_palette_slot(2, get_slot_type__20TWindowActionPaletteFlll(pal, *(s8 *)&this->m_64, 3), (s32)TWindowActionPalette__sub_801C1D7C(pal, *(s8 *)&this->m_64, 3));
    update_palette_slot(3, get_slot_type__20TWindowActionPaletteFlll(pal, *(s8 *)&this->m_65, 2), (s32)TWindowActionPalette__sub_801C1D7C(pal, *(s8 *)&this->m_65, 2));
    update_palette_slot(4, get_slot_type__20TWindowActionPaletteFlll(pal, *(s8 *)&this->m_65, 1), (s32)TWindowActionPalette__sub_801C1D7C(pal, *(s8 *)&this->m_65, 1));
    update_palette_slot(5, get_slot_type__20TWindowActionPaletteFlll(pal, *(s8 *)&this->m_65, 3), (s32)TWindowActionPalette__sub_801C1D7C(pal, *(s8 *)&this->m_65, 3));
}

#pragma push
#pragma fp_contract on
void TWindowSubCustomEquip::place_bank_slot_on_ring(s32 arg1, s32 arg2) {
    f32 temp_f1;
    f32 temp_f30;
    f32 temp_f31;
    s32 temp_r4;
    u8 *array_entry;
    if ((s8) TWindowSubCustomEquip__bank_ring_init_done == 0) {
        TWindowSubCustomEquip__bank_ring_init_done = 1;
        TWindowSubCustomEquip__ring_scale = lbl_805DD584;
    }
    if ((s8) lbl_805D647C == 0) {
        lbl_805D647C = 1;
        lbl_805D6478 = lbl_805DD588;
    }
    temp_f30 = sin_table_lookup(arg1);
    temp_f31 = cos_table_lookup(arg1);
    array_entry = (u8 *)(this->get_array_entry(arg2));
    *(f32 *)((s8 *)array_entry + 8) = (f32) ((TWindowSubCustomEquip__ring_scale * temp_f31) + lbl_805DD58C);
    *(f32 *)((s8 *)array_entry + 0xC) = (f32) ((lbl_805D6478 * temp_f30) + lbl_805DD590);
    if ((arg1 - 0x7200) & 0x8000) {
        temp_f1 = (lbl_805DD598 * cos_table_lookup(arg1 + 0xFFFF4E00)) + lbl_805DD594;
        *(f32 *)((s8 *)array_entry + 0x18) = (f32) lbl_805DD578;
        temp_r4 = (s32) (lbl_805DD59C * temp_f1);
        *(s32 *)((s8 *)array_entry + 0x2C) = (s32) ((u8) temp_r4 | (((temp_r4 << 0x10) & 0xFF0000) | 0xFF000000 | ((temp_r4 << 8) & 0xFF00)));
        return;
    }
    *(f32 *)((s8 *)array_entry + 0x18) = (f32) lbl_805DD5A0;
    *(s32 *)((s8 *)array_entry + 0x2C) = -1;
}
#pragma pop

void TWindowSubCustomEquip::update_rotate_anim() {
    s32 temp_r3;
    s32 var_r4;

    var_r4 = 0xB200;
    if ((s8) this->m_62 > 0) {
        var_r4 = 0x13200;
    }
    temp_r3 = this->m_68;
    if (var_r4 != temp_r3) {
        if ((s32) (u16) (var_r4 - temp_r3) < 0xC00) {
            this->m_68 = var_r4;
        } else {
            this->m_68 = (temp_r3 + 0xC00);
        }
    }
    if (this->m_68 & 0x8000) {
        this->m_64 = 0;
        this->m_65 = 1;
        place_bank_slot_on_ring(this->m_68, 9);
        place_bank_slot_on_ring(this->m_68 + 0x8000, 0);
        return;
    }
    this->m_64 = 1;
    this->m_65 = 0;
    place_bank_slot_on_ring(this->m_68 + 0x8000, 9);
    place_bank_slot_on_ring(this->m_68, 0);
}

void TWindowSubCustomEquip::handle_cancel() {
    if (is_selected() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_60 = (u8) (this->m_60 | 2);
    }
}

void TWindowSubCustomEquip::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
    ((TWindowSubStatusDisp *)(this->m_6c))->set_entry_state(2);
}

extern s32 __vt__21TWindowSubCustomEquip[];

typedef char RecoveredGlobal_80276D14_lbl_8050E208_size[sizeof(RecoveredGlobal_80276D14_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubCustomEquip::handle_cursor_input() {
    s32 temp_r29;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r4;
    u8 *temp_r31;
    u8 *window_choice_setting;
    u8 *array_entry;
    temp_r29 = is_player_input_active((this->m_20));
    temp_r31 = (u8 *)(((u8 *)get_array_entry(0x10)));
    array_entry = (u8 *)(((u8 *)get_array_entry(7)));
    temp_r4 = this->m_63;
    if ((s8) temp_r4 > 0) {
        this->m_63 = (temp_r4 - 1);
        *(s32 *)((s8 *)temp_r31 + 0x2C) = -1;
        *(s32 *)((s8 *)array_entry + 0x2C) = -1;
    } else {
        *(s32 *)((s8 *)temp_r31 + 0x2C) = 0xFF666666;
        *(s32 *)((s8 *)array_entry + 0x2C) = 0xFF666666;
    }
    window_choice_setting = (u8 *)&controller_input_state.value + (temp_r29 * 0x50) + 0x20;
    if ((apply_choice__20TWindowChoiceSettingFllll((void *)window_choice_setting, 0xF0, 6, 1) != 0) || (TWindowShortListCtrl__check_controller_button((int)window_choice_setting, (int) (fn_8002AE08((int)this->m_20))) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&controller_input_state.value + 0x160), 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0, 0, 0);
        if (TWindowShortListCtrl__check_controller_button((int)window_choice_setting, (int) (fn_8002AE08((int)this->m_20))) != 0) {
            this->m_62 = (u8) (1 - this->m_62);
            this->m_63 = 3U;
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x10, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&controller_input_state.value + 0x160), 0x10, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x20, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&controller_input_state.value + 0x160), 0x20, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x80, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&controller_input_state.value + 0x160), 0x80, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x40, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&controller_input_state.value + 0x160), 0x40, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        temp_r3_2 = this->m_61;
        if ((s8) temp_r3_2 < 0) {
            this->m_61 = (temp_r3_2 + 3);
        }
        temp_r3_3 = this->m_61;
        if ((s8) temp_r3_3 >= 3) {
            this->m_61 = (temp_r3_3 - 3);
        }
    }
}

void render__21TWindowSubCustomEquipFv(u8 *arg0) {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TUnk_804CE018 *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    ((TWindowSubCustomEquip *)arg0)->draw_cursor((u8 *)temp_r3);
    forward_render__20TWindowSubStatusDispFv((int) (((TWindowSubCustomEquip *)arg0)->m_6c), temp_r3);
}

typedef char RecoveredGlobal_80277014_lbl_8050E208_size[sizeof(RecoveredGlobal_80277014_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubCustomEquip::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    u8 *temp_r30_2;
    temp_r30 = is_player_input_active(((s32) this->m_20));
    if (((TWindowSubCustomEquip *)arg0)->is_selected() == 0) {
        ((TWindowSubCustomEquip *)arg0)->handle_cursor_input();
        temp_r30_2 = (u8 *)&(*(RecoveredGlobal_80277014_lbl_8050E208 *)&controller_input_state).value + (temp_r30 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_2, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&(*(RecoveredGlobal_80277014_lbl_8050E208 *)&controller_input_state).value + 0x160), 4) != 0)) {
            handle_decide();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_2, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&(*(RecoveredGlobal_80277014_lbl_8050E208 *)&controller_input_state).value + 0x160), 2) != 0)) {
            handle_cancel();
        }
    }
    update_rotate_anim();
    reset_selection();
    refresh_palette_slots();
    if ((f32) *(s32 *)&this->m_5c >= lbl_805DD5A4) {
        ((TWindowSubStatusDisp *)(*(s32 *)&this->m_6c))->update_subwindow();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TUnk_804CE018 *)arg0)->update_window_entry_list((u8 *)&this->m_24);
    this->m_66 = (this->m_66 + 1);
}

void *__dt__21TWindowSubCustomEquipFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TWindowSubCustomEquip;
        TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)arg0 + 0x6C)), (s16)1);
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *get_window_layout_position(s32 index);
extern u8 lbl_804D1488[];
extern const char *lbl_805D3A20;

TWindowSubCustomEquip *TWindowSubCustomEquip__ct(TWindowSubCustomEquip *self, s32 slot) {
    void *heading;
    ((TWindowDD *)self)->construct_base(lbl_804D1488, slot, get_window_layout_position(0xF));
    *(s32 **)((s8 *)self + 0x18) = __vt__21TWindowSubCustomEquip;
    self->m_name = lbl_805D3A20;
    self->m_20 = slot;
    self->m_60 = 0;
    self->m_61 = 1;
    self->m_62 = 0;
    self->m_63 = 0;
    self->m_64 = 0;
    self->m_65 = 1;
    self->m_66 = 0;
    self->m_68 = 0xB200;
    heading = (void *)::operator new(0x24);
    if (heading != NULL) {
        heading = ((TWindowSubStatusDisp *)heading)->construct_type1_heading((s32)TWindowSubStatusDisp::get_message_10(0x23), self->m_20);
    }
    self->m_6c = (u32)heading;
    self->refresh_palette_slots();
    return self;
}

s32 TWindowSubCustomEquip::calc_equip_index() {
    return *(s32 *)((s8 *)this + 0x78) + (((s8) *(u8 *)((s8 *)this + 0x70) + ((s8) *(u8 *)((s8 *)this + 0x71) * 3)) * 4);
}

}
