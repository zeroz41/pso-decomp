#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/ControllerInputState.h"
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
#include "pso/system/ControllerInput.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/unk/TUnk_804CF9C8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/player/PlayerSlots.h"

struct Obj_80275DB4 { u8 pad[0x60]; char f60; u8 pad2[0x6c - 0x61]; void *f6c; };





const char *TWindowSubCustomEquip__name = "TWindowSubCustomEquip";

// Window entries of the palette icon and of its count label, per cursor cell (column + row * 3).
static const u8 lbl_8044F738[6] = {12, 10, 11, 3, 1, 2};
static const u8 lbl_8044F740[6] = {15, 13, 14, 6, 4, 5};

static const NJS_POINT2 custom_equip_entry_offset_table[3] = {
    {50.0f, 32.0f},
    {6.0f, 58.0f},
    {94.0f, 6.0f},
};

// Texel origin of each cursor animation frame (4 x 4 grid of 64 x 64 cells).
static const NJS_POINT2 custom_equip_cursor_frame_uv_table[16] = {
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
    {6, {51.0f, 59.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.1f, -1, &hud_texlist, 2, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &hud_texlist, 4, 4},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {6, {96.0f, 112.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.6f, 0xFF666666, &hud_texlist, 0, 6},
    {6, {96.0f, 112.0f}, {91.0f, 54.0f}, 93.0f, 108.0f, 0.6f, -1, &hud_texlist, 2, 6},
    {6, {3.0f, 9.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.6f, -1, &hud_texlist, 2, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {6, {48.0f, 62.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.6f, 0xFF666666, &hud_texlist, 0, 6},
    {6, {48.0f, 62.0f}, {91.0f, 54.0f}, 93.0f, 108.0f, 0.6f, -1, &hud_texlist, 2, 6},
};

WindowDescriptor lbl_804D1488 = {
    {212.0f, 188.0f}, 50050.0f, &lbl_804D1198, 3,
};

extern "C" {
s32 can_use_palette_action__10TObjPlayerFPvUcUc(void *, u8, u8);
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
void TWindowSubCustomEquip::draw_cursor_sprite(f32 depth_scale, WindowDrawContext *context, NJS_POINT2 *position, s32 frame) {
    TexturedQuad r;
    const NJS_POINT2 *t;
    f32 scale;
    if (context->open_tick < 0) {
        return;
    }
    t = &custom_equip_cursor_frame_uv_table[frame & 0xF];
    scale = (-1.0f) / (0.299f * depth_scale + context->depth);
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0xC, -1);
    r.x0 = position->x + context->inner_x;
    r.y0 = position->y + context->inner_y;
    r.x1 = 72.32f + r.x0;
    r.y1 = 72.32f + r.y0;
    r.u0 = t->x / 256.0f;
    r.v0 = t->y / 256.0f;
    r.u1 = (64.0f + t->x) / 256.0f;
    r.v1 = (64.0f + t->y) / 256.0f;
    if (context->clip_and_transform_quad(&r) != 0) {
        draw_textured_quad_at_depth(&r.x0, scale);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TWindowSubCustomEquip::get_cursor_origin(NJS_POINT2 *position) {
    s8 idx;
    if ((s8)m_64 == 0) {
        idx = m_61 + m_62 * 3;
    } else {
        idx = m_61 + (1 - m_62) * 3;
    }
    WindowSpritePart *entry = static_cast<WindowSpritePart *>(get_array_entry(lbl_8044F738[idx]));
    set_relative_pos(position, entry);
}

void TWindowSubCustomEquip::draw_cursor(WindowDrawContext *context) {
    NJS_POINT2 position;
    get_cursor_origin(&position);
    draw_cursor_sprite(0.8f, context, &position, m_66);
}

void TWindowSubCustomEquip::update_palette_slot(s32 arg1, u16 kind, u16 index) {
    void *pl;
    WindowSpritePart *icon;
    TUnk_804CF9C8 *label;
    pl = get_player_by_client_id(this->client_index);
    if (pl != NULL) {
        icon = static_cast<WindowSpritePart *>(get_array_entry(lbl_8044F738[arg1]));
        label = static_cast<TUnk_804CF9C8 *>(get_array_entry(lbl_8044F740[arg1]));
        if (can_use_palette_action__10TObjPlayerFPvUcUc(pl, kind, index) != 0) {
            icon->color = -1;
        } else {
            icon->color = 0xFF404040;
        }
        draw_action_palette_icon(icon, kind, index);
        update_palette_item_count_label(label, icon, kind, index, this->client_index);
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
s32 get_slot_type__20TWindowActionPaletteFPvll(s32, s32, s32);
s32 is_type_valid__21TWindowSubCustomEquipFv(void *, u8);
s32 get_saved_slot_for_index__21TWindowSubCustomEquipFlSc(void *, u8);
void TWindowSubCustomEquip::get_cursor_pos(void *arg1) {
    s32 i;
    u8 *player;
    s32 saved_slot;
    s32 temp_r29;

    if ((player = (u8 *)get_player_by_client_id(this->client_index), (player == 0U)) || (temp_r29 = (saddr)((TObjPlayer *)(player))->select_action_palette(0), ((temp_r29 == 0) != 0))) {
        *(s16 *)((s8 *)arg1 + 0) = 0;
        *(s16 *)((s8 *)arg1 + 2) = 0;
        return;
    }
    i = is_type_valid__21TWindowSubCustomEquipFv(this, this->m_62);
    saved_slot = get_saved_slot_for_index__21TWindowSubCustomEquipFlSc(this, this->m_61);
    *(s16 *)((s8 *)arg1 + 0) = get_slot_type__20TWindowActionPaletteFPvll(temp_r29, i, saved_slot);
    *(s16 *)((s8 *)arg1 + 2) = (s16)TWindowActionPalette__sub_801C1D7C(temp_r29, i, saved_slot);
}
void TWindowSubCustomEquip::remove_duplicate_bindings(void *arg1) {
    u8 *player;
    s32 temp_r29;
    if ((player = (u8 *)get_player_by_client_id(this->client_index), (player == 0U)) || (temp_r29 = (saddr)((TObjPlayer *)(player))->select_action_palette(0), ((temp_r29 == 0) != 0))) {
        return;
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFPvll(temp_r29, 0, 1) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 0, 1)) {
        ((TObjPlayer *)player)->set_action_palette_entry(0, 0, 1, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFPvll(temp_r29, 0, 3) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 0, 3)) {
        ((TObjPlayer *)player)->set_action_palette_entry(0, 0, 3, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFPvll(temp_r29, 0, 2) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 0, 2)) {
        ((TObjPlayer *)player)->set_action_palette_entry(0, 0, 2, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFPvll(temp_r29, 1, 1) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 1, 1)) {
        ((TObjPlayer *)player)->set_action_palette_entry(0, 1, 1, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFPvll(temp_r29, 1, 3) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 1, 3)) {
        ((TObjPlayer *)player)->set_action_palette_entry(0, 1, 3, 0, 0);
    }
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFPvll(temp_r29, 1, 2) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, 1, 2)) {
        ((TObjPlayer *)player)->set_action_palette_entry(0, 1, 2, 0, 0);
    }
}
void TWindowSubCustomEquip::toggle_action_binding(void *arg1) {
    u8 *player;
    s32 temp_r29;
    s32 valid;
    s32 idx;
    if ((player = (u8 *)get_player_by_client_id(this->client_index), (player == 0U)) || (temp_r29 = (saddr)((TObjPlayer *)(player))->select_action_palette(0), ((temp_r29 == 0) != 0))) {
        return;
    }
    valid = is_type_valid__21TWindowSubCustomEquipFv(this, this->m_62);
    idx = get_saved_slot_for_index__21TWindowSubCustomEquipFlSc(this, this->m_61);
    if (*(u16 *)((s8 *)arg1 + 0) == (u16)get_slot_type__20TWindowActionPaletteFPvll(temp_r29, valid, idx) && *(u16 *)((s8 *)arg1 + 2) == (u16)TWindowActionPalette__sub_801C1D7C(temp_r29, valid, idx)) {
        ((TObjPlayer *)player)->set_action_palette_entry(0, valid, idx, 0, 0);
        return;
    }
    remove_duplicate_bindings(arg1);
    ((TObjPlayer *)player)->set_action_palette_entry(0, valid, idx, *(u16 *)((s8 *)arg1 + 0), *(u16 *)((s8 *)arg1 + 2));
}

f32 TWindowSubCustomEquip__ring_scale;
u8 TWindowSubCustomEquip__bank_ring_init_done;
f32 lbl_805D6478;
u8 lbl_805D647C;
s32 play_sound_effect(s32, s32, s32, s32);


void set_relative_pos(NJS_POINT2 *position, WindowSpritePart *entry) {
    position->x = entry->x - 11.0f;
    position->y = entry->y - 15.0f;
}

void TWindowSubCustomEquip::layout_selection_parts(void *arg1) {
    NJS_POINT2 pos;
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
    TWindowHelpItem::set_help_text((saddr)b, (s32)this->client_index);
    copy_vec2((a + 8), &pos);
    copy_vec2((b + 8), &pos);
    *(f32 *)((s8 *)a + 0x18) = *(f32 *)((s8 *)p + 0x18);
    *(f32 *)((s8 *)b + 0x18) = *(f32 *)((s8 *)p + 0x18);
    *(s32 *)((s8 *)a + 0x2C) = *(s32 *)((s8 *)p + 0x2C);
    *(u16 *)((s8 *)a + 0) &= ~2;
    *(u16 *)((s8 *)b + 0) &= ~2;
    *(u16 *)((s8 *)c + 0) |= 2;
    *(u16 *)((s8 *)d + 0) |= 2;
}

void TWindowSubCustomEquip::layout_entry_group(void *index) {
  u8 *base;
  u8 *e1;
  u8 *e2;
  u32 i;
  s32 idx;
  s32 v;
  base = (u8 *) get_array_entry((saddr) index);
  for (i = 0; i < 3; i++)
  {
    idx = ((saddr) index) + i;
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

void TWindowSubCustomEquip::refresh_palette_slots() {
    TObjPlayer *player;
    TPlyDispConfigSmth *palette;
    player = get_player_by_client_id(this->client_index);
    if (player == NULL || (palette = player->select_action_palette(0)) == NULL) {
        return;
    }
    saddr palette_address = reinterpret_cast<saddr>(palette);
    update_palette_slot(0, TWindowActionPalette::get_slot_type(palette, *(s8 *)&this->m_64, 2), TWindowActionPalette__sub_801C1D7C(palette_address, *(s8 *)&this->m_64, 2));
    update_palette_slot(1, TWindowActionPalette::get_slot_type(palette, *(s8 *)&this->m_64, 1), TWindowActionPalette__sub_801C1D7C(palette_address, *(s8 *)&this->m_64, 1));
    update_palette_slot(2, TWindowActionPalette::get_slot_type(palette, *(s8 *)&this->m_64, 3), TWindowActionPalette__sub_801C1D7C(palette_address, *(s8 *)&this->m_64, 3));
    update_palette_slot(3, TWindowActionPalette::get_slot_type(palette, *(s8 *)&this->m_65, 2), TWindowActionPalette__sub_801C1D7C(palette_address, *(s8 *)&this->m_65, 2));
    update_palette_slot(4, TWindowActionPalette::get_slot_type(palette, *(s8 *)&this->m_65, 1), TWindowActionPalette__sub_801C1D7C(palette_address, *(s8 *)&this->m_65, 1));
    update_palette_slot(5, TWindowActionPalette::get_slot_type(palette, *(s8 *)&this->m_65, 3), TWindowActionPalette__sub_801C1D7C(palette_address, *(s8 *)&this->m_65, 3));
}

#pragma push
#pragma fp_contract on
void TWindowSubCustomEquip::place_bank_slot_on_ring(s32 angle, s32 index) {
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
    temp_f30 = sin_table_lookup(angle);
    temp_f31 = cos_table_lookup(angle);
    array_entry = (u8 *)(this->get_array_entry(index));
    *(f32 *)((s8 *)array_entry + 8) = (f32) ((TWindowSubCustomEquip__ring_scale * temp_f31) + 27.0f);
    *(f32 *)((s8 *)array_entry + 0xC) = (f32) ((lbl_805D6478 * temp_f30) + 34.0f);
    if ((angle - 0x7200) & 0x8000) {
        temp_f1 = (0.5f * cos_table_lookup(angle + 0xFFFF4E00)) + 1.0f;
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
    s32 angle;
    s32 var_r4;

    var_r4 = 0xB200;
    if ((s8) this->m_62 > 0) {
        var_r4 = 0x13200;
    }
    angle = this->angle;
    if (var_r4 != angle) {
        if ((s32) (u16) (var_r4 - angle) < 0xC00) {
            this->angle = var_r4;
        } else {
            this->angle = (angle + 0xC00);
        }
    }
    if (this->angle & 0x8000) {
        this->m_64 = 0;
        this->m_65 = 1;
        place_bank_slot_on_ring(this->angle, 9);
        place_bank_slot_on_ring(this->angle + 0x8000, 0);
        return;
    }
    this->m_64 = 1;
    this->m_65 = 0;
    place_bank_slot_on_ring(this->angle + 0x8000, 9);
    place_bank_slot_on_ring(this->angle, 0);
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
    m_6c->set_entry_state(2);
}

void TWindowSubCustomEquip::handle_cursor_input() {
    s32 temp_r29;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r4;
    u8 *temp_r31;
    ControllerInputContext *window_choice_setting;
    u8 *array_entry;
    temp_r29 = is_player_input_active((this->client_index));
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
    window_choice_setting = &controller_input_state.controllers[temp_r29];
    if ((test_buttons_press_or_repeat(window_choice_setting, 0xF0, 6, 1) != 0) || (test_pressed_buttons_packed(window_choice_setting, (int) (fn_8002AE08((int)this->client_index))) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0, 0, 0);
        if (test_pressed_buttons_packed(window_choice_setting, (int) (fn_8002AE08((int)this->client_index))) != 0) {
            this->m_62 = (u8) (1 - this->m_62);
            this->m_63 = 3U;
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->m_61 = (this->m_61 + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            this->m_61 = (this->m_61 - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
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

void TWindowSubCustomEquip::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_cursor(context);
    m_6c->forward_render(context);
}

void TWindowSubCustomEquip::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    ControllerInputContext *context;
    temp_r30 = is_player_input_active(((s32) this->client_index));
    if (((TWindowSubCustomEquip *)arg0)->is_selected() == 0) {
        ((TWindowSubCustomEquip *)arg0)->handle_cursor_input();
        context = &controller_input_state.controllers[temp_r30];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            handle_decide();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    update_rotate_anim();
    reset_selection();
    refresh_palette_slots();
    if ((f32)open_tick >= 7.5f) {
        m_6c->update_subwindow();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    this->m_66 = (this->m_66 + 1);
}

TWindowSubCustomEquip::~TWindowSubCustomEquip() {
    TWindowSubStatusDisp::destroy_status_display(reinterpret_cast<saddr>(m_6c), 1);
}

u8 *get_window_layout_position(s32 index);

TWindowSubCustomEquip::TWindowSubCustomEquip(s32 slot) : TWindowBase((u8 *)&lbl_804D1488, slot, get_window_layout_position(0xF)) {
    void *heading;
    this->m_name = TWindowSubCustomEquip__name;
    this->client_index = slot;
    this->m_60 = 0;
    this->m_61 = 1;
    this->m_62 = 0;
    this->m_63 = 0;
    this->m_64 = 0;
    this->m_65 = 1;
    this->m_66 = 0;
    this->angle = 0xB200;
    heading = (void *)::operator new(0x24);
    if (heading != NULL) {
        heading = ((TWindowSubStatusDisp *)heading)->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x23), this->client_index);
    }
    m_6c = static_cast<TWindowSubStatusDisp *>(heading);
    this->refresh_palette_slots();
}

void *TWindowSubCustomSelect::get_selected_action() {
    return reinterpret_cast<void *>(m_78 + (static_cast<s8>(m_70) + static_cast<s8>(m_71) * 3) * 4);
}

}
