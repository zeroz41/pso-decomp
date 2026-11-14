#include "types.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"

struct Obj_80275DB4 { u8 pad[0x60]; char f60; u8 pad2[0x6c - 0x61]; void *f6c; };

struct Vec2_80275DE8 { f32 x, y; };

struct Win_80275F90 { u8 pad[0x66]; s16 f66; };

struct Rect_80275DE8 { f32 x0, y0, x1, y1, u0, v0, u1, v1; };


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

extern s32 lbl_805D63F0;

const char *TWindowSubCustomEquip__name = "TWindowSubCustomEquip";

// Window entries of the palette icon and of its count label, per cursor cell (column + row * 3).
static const u8 lbl_8044F738[6] = {12, 10, 11, 3, 1, 2};
static const u8 lbl_8044F740[6] = {15, 13, 14, 6, 4, 5};

static const Vec2_802766C8 custom_equip_entry_offset_table[3] = {
    {50.0f, 32.0f},
    {6.0f, 58.0f},
    {94.0f, 6.0f},
};

// Texel origin of each cursor animation frame (4 x 4 grid of 64 x 64 cells).
static const Vec2_80275DE8 custom_equip_cursor_frame_uv_table[16] = {
    {0.0f, 0.0f}, {64.0f, 0.0f}, {128.0f, 0.0f}, {192.0f, 0.0f},
    {0.0f, 64.0f}, {64.0f, 64.0f}, {128.0f, 64.0f}, {192.0f, 64.0f},
    {0.0f, 128.0f}, {64.0f, 128.0f}, {128.0f, 128.0f}, {192.0f, 128.0f},
    {0.0f, 192.0f}, {64.0f, 192.0f}, {128.0f, 192.0f}, {192.0f, 192.0f},
};

// Window layout: two rows of panel, three palette icons, three count labels and two tabs.
struct CustomEquipLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    SpritePartLayoutRecord rec_1;
    SpritePartLayoutRecord rec_2;
    SpritePartLayoutRecord rec_3;
    ValueLayoutRecord rec_4;
    ValueLayoutRecord rec_5;
    ValueLayoutRecord rec_6;
    SpritePartLayoutRecord rec_7;
    SpritePartLayoutRecord rec_8;
    SpritePartLayoutRecord rec_9;
    SpritePartLayoutRecord rec_10;
    SpritePartLayoutRecord rec_11;
    SpritePartLayoutRecord rec_12;
    ValueLayoutRecord rec_13;
    ValueLayoutRecord rec_14;
    ValueLayoutRecord rec_15;
    SpritePartLayoutRecord rec_16;
    SpritePartLayoutRecord rec_17;
};

CustomEquipLayout lbl_804D1198 = {
    18, 1,
    {6, {51.0f, 59.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.1f, -1, &lbl_805D63F0, 2, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &lbl_805D63F0, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &lbl_805D63F0, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &lbl_805D63F0, 4, 4},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {6, {96.0f, 112.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.6f, 0xFF666666, &lbl_805D63F0, 0, 6},
    {6, {96.0f, 112.0f}, {91.0f, 54.0f}, 93.0f, 108.0f, 0.6f, -1, &lbl_805D63F0, 2, 6},
    {6, {3.0f, 9.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.6f, -1, &lbl_805D63F0, 2, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &lbl_805D63F0, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &lbl_805D63F0, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &lbl_805D63F0, 4, 4},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {6, {48.0f, 62.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.6f, 0xFF666666, &lbl_805D63F0, 0, 6},
    {6, {48.0f, 62.0f}, {91.0f, 54.0f}, 93.0f, 108.0f, 0.6f, -1, &lbl_805D63F0, 2, 6},
};

WindowDescriptor lbl_804D1488 = {
    {212.0f, 188.0f}, 50050.0f, &lbl_804D1198, 3,
};

extern "C" {
void *get_player_by_client_id(s32);
s32 can_use_palette_action__10TObjPlayerFPvUcUc(void *, u8, u8);
u8 *get_array_entry__11TWindowBaseFi(void *, s32);
void update_palette_item_count_label(u8 *, u8 *, s32, s32, s32);
void draw_action_palette_icon(u8 *, s32, s32);
s32 try_open__19TWindowKeyBoardSoftFii(s32 arg0, s32 arg1);
void begin_screen_draw(s32 arg0);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);
void draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(u8 *arg0, Vec2_80275DE8 *arg1, s32 arg2, f32 farg0);
int TWindowSubCustomEquip__sub_80275DA8(void* p);

int TWindowSubCustomEquip::is_selected() { return this->m_60 & 0x1; }
int TWindowSubCustomEquip__sub_80275DA8(void* p) { return *(u8*)((char*)p + 0x60) & 0x2; }
void TWindowSubCustomEquip::clear_flag_and_set_entry_state() {
    Obj_80275DB4 *o = (Obj_80275DB4 *)this;
    o->f60 &= ~1;
    ((TWindowSubStatusDisp *)(o->f6c))->set_entry_state(1);
}

#pragma push
#pragma fp_contract on
void draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(u8 *arg0, Vec2_80275DE8 *arg1, s32 arg2, f32 farg0) {
    Rect_80275DE8 r;
    const Vec2_80275DE8 *t;
    f32 scale;
    if (*(s32 *)((s8 *)arg0 + 0x30) < 0) {
        return;
    }
    t = &custom_equip_cursor_frame_uv_table[arg2 & 0xF];
    scale = (-1.0f) / (0.299f * farg0 + *(f32 *)((s8 *)arg0 + 0x38));
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0xC, -1);
    r.x0 = arg1->x + *(f32 *)((s8 *)arg0 + 0x10);
    r.y0 = arg1->y + *(f32 *)((s8 *)arg0 + 0x14);
    r.x1 = 72.32f + r.x0;
    r.y1 = 72.32f + r.y0;
    r.u0 = t->x / 256.0f;
    r.v0 = t->y / 256.0f;
    r.u1 = (64.0f + t->x) / 256.0f;
    r.v1 = (64.0f + t->y) / 256.0f;
    if (try_open__19TWindowKeyBoardSoftFii((s32)arg0, (s32)&r) != 0) {
        draw_textured_quad_at_depth((f32 *)&r, scale);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TWindowSubCustomEquip::sub_80275F08(void *window_sub_custom_equip) {
    s8 idx;
    if ((s8)((u8 *)this)[0x64] == 0) {
        idx = ((u8 *)this)[0x61] + ((u8 *)this)[0x62] * 3;
    } else {
        idx = ((u8 *)this)[0x61] + (1 - ((u8 *)this)[0x62]) * 3;
    }
    u8 *e = get_array_entry__11TWindowBaseFi(this, lbl_8044F738[idx]);
    ((TWindowSubCustomEquip *)window_sub_custom_equip)->set_relative_pos(e);
}

void TWindowSubCustomEquip::draw_cursor(u8 *arg1) {
    Win_80275F90 *arg0 = (Win_80275F90 *)this;
    Vec2_80275DE8 pos;
    ((TWindowSubCustomEquip *)arg0)->sub_80275F08(&pos);
    ((void (*)(f32, u8 *, Vec2_80275DE8 *, s32))draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif)(0.8f, arg1, &pos, arg0->f66);
}

void TWindowSubCustomEquip::update_palette_slot(s32 arg1, s32 kind, s32 arg3) {
    void *pl;
    u8 *a;
    u8 *b;
    pl = get_player_by_client_id(this->m_20);
    if (pl != NULL) {
        a = get_array_entry__11TWindowBaseFi(this, lbl_8044F738[arg1]);
        b = get_array_entry__11TWindowBaseFi(this, lbl_8044F740[arg1]);
        if (can_use_palette_action__10TObjPlayerFPvUcUc(pl, kind, arg3) != 0) {
            *(s32 *)(a + 0x2C) = -1;
        } else {
            *(s32 *)(a + 0x2C) = 0xFF404040;
        }
        draw_action_palette_icon(a, kind, arg3);
        update_palette_item_count_label(b, a, kind, arg3, this->m_20);
    }
}

}


s32 TWindowSubCustomEquip::is_type_valid() {

    switch ((s8) this->m_62) {
    case 0:
        return 0;
    default:
    case 1:
        return 1;
    }
}
s32 TWindowSubCustomEquip::get_saved_slot_for_index(s32 arg0, s8 arg1) {
    switch (arg1) {
    case 0:
        return 2;
    case 1:
        return 1;
    case 2: break;
    }
    return 3;
}


extern "C" {
s32 select_action_palette__10TObjPlayerFi(u8 *, s32);
void *get_player_by_client_id(s32 i);
u8 *TWindowActionPalette__sub_801C1D7C(s32 arg0, s32 i, s32 arg2);
s32 get_slot_type__20TWindowActionPaletteFlll(s32, s32, s32);
s32 is_type_valid__21TWindowSubCustomEquipFv(void *, u8);
s32 get_saved_slot_for_index__21TWindowSubCustomEquipFlSc(void *, u8);
void TWindowSubCustomEquip::get_cursor_pos(void *arg1) {
    s32 i;
    u8 *temp_r3;
    s32 saved_slot;
    s32 temp_r29;

    if ((temp_r3 = (u8 *)get_player_by_client_id(this->m_20), (temp_r3 == 0U)) || (temp_r29 = select_action_palette__10TObjPlayerFi(temp_r3, 0), ((temp_r29 == 0) != 0))) {
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
    u8 *temp_r3;
    s32 temp_r29;
    if ((temp_r3 = (u8 *)get_player_by_client_id(this->m_20), (temp_r3 == 0U)) || (temp_r29 = select_action_palette__10TObjPlayerFi(temp_r3, 0), ((temp_r29 == 0) != 0))) {
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
    u8 *temp_r3;
    s32 temp_r29;
    s32 valid;
    s32 idx;
    if ((temp_r3 = (u8 *)get_player_by_client_id(this->m_20), (temp_r3 == 0U)) || (temp_r29 = select_action_palette__10TObjPlayerFi(temp_r3, 0), ((temp_r29 == 0) != 0))) {
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

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
s32 forward_render__20TWindowSubStatusDispFv(int, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 TWindowSubCustomEquip__ring_scale;
u8 TWindowSubCustomEquip__bank_ring_init_done;
f32 lbl_805D6478;
u8 lbl_805D647C;
s32 fn_8002AE08(int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
s32 apply_choice__20TWindowChoiceSettingFllll(void *, int, int, int);
s32 play_sound_effect(s32, s32, s32, s32);
extern RecoveredGlobal_80276D14_lbl_8050E208 controller_input_state;
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 set_help_text__15TWindowHelpItemFll(u8 *, s32);
s32 select_action_palette__10TObjPlayerFi(u8 *, s32);
void *get_player_by_client_id(s32 i);
u8 *TWindowActionPalette__sub_801C1D7C(s32 arg0, s32 i, s32 arg2);
s32 get_slot_type__20TWindowActionPaletteFlll(s32, s32, s32);
void __dl__7TObjectFPv(void *);


void TWindowSubCustomEquip::set_relative_pos(void *arg1) {
    *(f32 *)&this->m_name = (f32) (*(f32 *)((s8 *)arg1 + 8) - 11.0f);
    *(f32 *)&this->m_flags = (f32) (*(f32 *)((s8 *)arg1 + 0xC) - 15.0f);
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
    pos.x = 45.0f + *(f32 *)((s8 *)p + 8);
    pos.y = 53.0f + *(f32 *)((s8 *)p + 0xC);
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
    *((f32 *) (((s8 *) e1) + 0x18)) = 0.1f + (*((f32 *) (((s8 *) base) + 0x18)));
    *((f32 *) (((s8 *) e2) + 0x18)) = 0.2f + (*((f32 *) (((s8 *) base) + 0x18)));
    *((s32 *) (((s8 *) e2) + 0x1C)) = *((s32 *) (((s8 *) base) + 0x2C));
    v = 0.003921569f * (((unsigned char) ((*((u32 *) (((s8 *) base) + 0x2C))) & 0xFF)) * ((*((u32 *) (((s8 *) e1) + 0x2C))) & 0xFF));
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
        TWindowSubCustomEquip__ring_scale = 75.0f;
    }
    if ((s8) lbl_805D647C == 0) {
        lbl_805D647C = 1;
        lbl_805D6478 = 25.0f;
    }
    temp_f30 = sin_table_lookup(arg1);
    temp_f31 = cos_table_lookup(arg1);
    array_entry = (u8 *)(this->get_array_entry(arg2));
    *(f32 *)((s8 *)array_entry + 8) = (f32) ((TWindowSubCustomEquip__ring_scale * temp_f31) + 27.0f);
    *(f32 *)((s8 *)array_entry + 0xC) = (f32) ((lbl_805D6478 * temp_f30) + 34.0f);
    if ((arg1 - 0x7200) & 0x8000) {
        temp_f1 = (0.5f * cos_table_lookup(arg1 + 0xFFFF4E00)) + 1.0f;
        *(f32 *)((s8 *)array_entry + 0x18) = 0.1f;
        temp_r4 = (s32) (255.0f * temp_f1);
        *(s32 *)((s8 *)array_entry + 0x2C) = (s32) ((u8) temp_r4 | (((temp_r4 << 0x10) & 0xFF0000) | 0xFF000000 | ((temp_r4 << 8) & 0xFF00)));
        return;
    }
    *(f32 *)((s8 *)array_entry + 0x18) = 0.6f;
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
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
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
    if ((f32) *(s32 *)&this->m_5c >= 7.5f) {
        ((TWindowSubStatusDisp *)(*(s32 *)&this->m_6c))->update_subwindow();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
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

TWindowSubCustomEquip *TWindowSubCustomEquip__ct(TWindowSubCustomEquip *self, s32 slot) {
    void *heading;
    ((TWindowDD *)self)->construct_base((u8 *)&lbl_804D1488, slot, get_window_layout_position(0xF));
    *(s32 **)((s8 *)self + 0x18) = __vt__21TWindowSubCustomEquip;
    self->m_name = TWindowSubCustomEquip__name;
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
