#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowMenu.h"

#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/system/task/TObject.h"

#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/chat/SymbolChatPayload.h"

extern "C" {

struct SymbolChatSpriteLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord recs[25];
};


SymbolChatSpriteLayout symbol_chat_layout_sprite_records = {
    25, 1,
    {
        {6, {34.0f, 5.0f}, {60.0f, 60.0f}, 0.0f, 128.0f, 0.2f, -1, &hud_texlist, 10, 4},
        {6, {-5.0f, 0.0f}, {50.0f, 40.0f}, 178.0f, 168.0f, 0.23f, -1, &hud_texlist, 10, 20},
        {6, {91.0f, 0.0f}, {50.0f, 40.0f}, 128.0f, 168.0f, 0.23f, -1, &hud_texlist, 10, 20},
        {6, {-5.0f, 38.0f}, {50.0f, 40.0f}, 178.0f, 128.0f, 0.23f, -1, &hud_texlist, 10, 20},
        {6, {91.0f, 38.0f}, {50.0f, 40.0f}, 128.0f, 128.0f, 0.23f, -1, &hud_texlist, 10, 20},
        {6, {0.0f, 0.0f}, {32.0f, 32.0f}, 0.0f, 96.0f, 0.25f, -1, &hud_texlist, 7, 4},
        {6, {96.0f, 0.0f}, {32.0f, 32.0f}, 0.0f, 96.0f, 0.25f, -1, &hud_texlist, 7, 4},
        {6, {0.0f, 38.0f}, {32.0f, 32.0f}, 0.0f, 96.0f, 0.25f, -1, &hud_texlist, 7, 4},
        {6, {96.0f, 38.0f}, {32.0f, 32.0f}, 0.0f, 96.0f, 0.25f, -1, &hud_texlist, 7, 4},
        {6, {0.0f, 0.0f}, {32.0f, 32.0f}, 128.0f, 208.0f, 0.3f, -1, &hud_texlist, 10, 20},
        {6, {96.0f, 0.0f}, {32.0f, 32.0f}, 128.0f, 208.0f, 0.3f, -1, &hud_texlist, 10, 20},
        {6, {0.0f, 38.0f}, {32.0f, 32.0f}, 128.0f, 208.0f, 0.3f, -1, &hud_texlist, 10, 20},
        {6, {96.0f, 38.0f}, {32.0f, 32.0f}, 128.0f, 208.0f, 0.3f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.35f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.4f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.45f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.5f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.55f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.6f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.65f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.7f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.75f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.8f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.85f, -1, &hud_texlist, 10, 20},
        {6, {64.0f, 35.0f}, {16.0f, 16.0f}, 0.0f, 0.0f, 0.9f, -1, &hud_texlist, 10, 20},
    },
};

#pragma push
#pragma readonly_strings on
const char *window_chat_symbol_name = "TWindowChatSymbol";
#pragma pop

extern const NJS_POINT2 symbol_chat_face_uv_table[4];
extern const NJS_POINT2 symbol_chat_parts_set_part_uv_table[4];
extern const NJS_POINT2 symbol_chat_part_uv_table[70];
extern const NJS_POINT2 symbol_chat_part_size_table[3];
extern const int symbol_chat_parts_color_table[8];
extern const int chat_help_color_table[8];

// Texture coordinates of the face sprites, one per face direction.
const NJS_POINT2 symbol_chat_face_uv_table[4] = {
    { 2.0f, 194.0f }, { 2.0f, 130.0f }, { 66.0f, 130.0f }, { 66.0f, 194.0f },
};
const NJS_POINT2 symbol_chat_parts_set_part_uv_table[4] = {
    { 178.0f, 168.0f }, { 128.0f, 168.0f }, { 178.0f, 128.0f }, { 128.0f, 128.0f },
};
// Texture coordinates of the 70 symbol-chat parts in r256_symparts.
const NJS_POINT2 symbol_chat_part_uv_table[70] = {
    { 0.0f, 0.0f }, { 16.0f, 0.0f }, { 32.0f, 0.0f }, { 48.0f, 0.0f },
    { 64.0f, 0.0f }, { 80.0f, 0.0f }, { 96.0f, 0.0f }, { 112.0f, 0.0f },
    { 0.0f, 16.0f }, { 16.0f, 16.0f }, { 32.0f, 16.0f }, { 48.0f, 16.0f },
    { 64.0f, 16.0f }, { 80.0f, 16.0f }, { 96.0f, 16.0f }, { 112.0f, 16.0f },
    { 0.0f, 32.0f }, { 16.0f, 32.0f }, { 32.0f, 32.0f }, { 48.0f, 32.0f },
    { 64.0f, 32.0f }, { 80.0f, 32.0f }, { 96.0f, 32.0f }, { 112.0f, 32.0f },
    { 0.0f, 48.0f }, { 16.0f, 48.0f }, { 32.0f, 48.0f }, { 48.0f, 48.0f },
    { 64.0f, 48.0f }, { 80.0f, 48.0f }, { 96.0f, 48.0f }, { 112.0f, 48.0f },
    { 0.0f, 64.0f }, { 16.0f, 64.0f }, { 32.0f, 64.0f }, { 48.0f, 64.0f },
    { 64.0f, 64.0f }, { 80.0f, 64.0f }, { 96.0f, 64.0f }, { 112.0f, 64.0f },
    { 0.0f, 80.0f }, { 16.0f, 80.0f }, { 32.0f, 80.0f }, { 48.0f, 80.0f },
    { 64.0f, 80.0f }, { 80.0f, 80.0f }, { 96.0f, 80.0f }, { 112.0f, 80.0f },
    { 128.0f, 0.0f }, { 168.0f, 0.0f }, { 208.0f, 0.0f }, { 128.0f, 20.0f },
    { 168.0f, 20.0f }, { 208.0f, 20.0f }, { 128.0f, 40.0f }, { 168.0f, 40.0f },
    { 208.0f, 40.0f }, { 128.0f, 60.0f }, { 168.0f, 60.0f }, { 208.0f, 60.0f },
    { 0.0f, 96.0f }, { 32.0f, 96.0f }, { 64.0f, 96.0f }, { 96.0f, 96.0f },
    { 128.0f, 96.0f }, { 160.0f, 96.0f }, { 192.0f, 96.0f }, { 224.0f, 96.0f },
    { 192.0f, 224.0f }, { 224.0f, 224.0f },
};
const NJS_POINT2 symbol_chat_part_size_table[3] = {
    { 15.0f, 15.0f }, { 40.0f, 20.0f }, { 31.0f, 31.0f },
};
const int symbol_chat_parts_color_table[8] = {
    0xFFCFCFCF, 0xFFF3503C, 0xFFFFA32F, 0xFFDFFD04, 0xFF79FD79, 0xFF87ACFA, 0xFFD58BF6, 0xFF787878,
};
// The same eight colours, darkened, for the help window.
const int chat_help_color_table[8] = {
    0xFF676767, 0xFF79281E, 0xFF805117, 0xFF6FB002, 0xFF3CB03C, 0xFF3E56AF, 0xFF6A407B, 0xFF3C3C3C,
};


int TWindowSubSymbolChatPartsSet::get_parts_color(int index) { return symbol_chat_parts_color_table[index]; }

void TWindowSubSymbolChatPartsSet::set_pos(WindowSpritePart *sprite, s16 x, s16 y) {
    sprite->x = (f32)(32.0f + (f32)x);
    sprite->y = (f32)y;
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatPartsSet::set_part_sprite(WindowSpritePart *sprite, s16 id, s32 flip_u, s32 flip_v) {
    const NJS_POINT2 *e;
    const NJS_POINT2 *size;
    if (id == -1) {
        ((TWindowLayoutEntry *)sprite)->hide();
        return;
    }
    ((TWindowLayoutEntry *)sprite)->show();
    if (id < 0x30) {
        size = &symbol_chat_part_size_table[0];
    } else if (id < 0x3C) {
        size = &symbol_chat_part_size_table[1];
    } else {
        size = &symbol_chat_part_size_table[2];
    }
    sprite->x -= 0.5f * size->x;
    sprite->y -= 0.5f * size->y;
    sprite->w = size->x;
    sprite->h = size->y;
    e = &symbol_chat_part_uv_table[id];
    set_sprite_uv_from_pixels(sprite, (f32)e->x, (f32)e->y);
    if (flip_u != 0) {
        swap_sprite_u_edges(sprite);
    }
    if (flip_v != 0) {
        swap_sprite_v_edges(sprite);
    }
}
#pragma pop

WindowSpritePart *TWindowSubSymbolChatPartsSet::get_entry_offset_d(s32 sel) {
    return (WindowSpritePart *)this->get_array_entry(sel + 0xD);
}

void TWindowSubSymbolChatPartsSet::apply_part_to_window(WindowLayoutEntries *entries, SymbolChatPart *part, s32 index) {
    WindowSpritePart *w;
    u8 f;
    w = static_cast<WindowSpritePart *>(entries->items[index + 13]);
    set_pos(w, part->x, part->y);
    f = part->flags;
    set_part_sprite(w, part->id, (s32)(f & 1), (s32)((f >> 1) & 1));
}

void TWindowSubSymbolChatPartsSet::setup_part_sprites(WindowSpritePart *help, WindowSpritePart *alternate, WindowSpritePart *shortcut_icon, u16 code, s32 color, s32 flip_u, s32 flip_v, s32 uv_index) {
    f32 u;
    f32 v;
    const NJS_POINT2 *uv;
    if (code == 0xFF) {
        ((TWindowLayoutEntry *)shortcut_icon)->hide();
        ((TWindowLayoutEntry *)help)->hide();
        ((TWindowLayoutEntry *)alternate)->hide();
        return;
    }
    ((TWindowLayoutEntry *)shortcut_icon)->show();
    ((TWindowLayoutEntry *)help)->show();
    ((TWindowLayoutEntry *)alternate)->show();
    u = 32.0f * (f32)(code & 7);
    v = 32.0f * (f32)((code >> 3) & 7);
    help->kind = ((code >> 6) & 3) + 7;
    help->color = get_parts_color(color);
    if (code <= 0x12) {
        uv = &symbol_chat_parts_set_part_uv_table[uv_index];
        set_sprite_dimensions(help, 31.0f, 31.0f);
        shortcut_icon->x = help->x - 5.0f;
        shortcut_icon->y = help->y;
        set_sprite_dimensions(shortcut_icon, 50.0f, 40.0f);
        set_sprite_uv_from_pixels(shortcut_icon, uv->x, uv->y);
        ((TWindowLayoutEntry *)alternate)->hide();
    } else {
        set_sprite_dimensions(help, 30.0f, 30.0f);
        alternate->x = help->x;
        alternate->y = help->y;
        ((TWindowLayoutEntry *)shortcut_icon)->hide();
    }
    set_sprite_uv_from_pixels(help, u, v);
    if (flip_u != 0) {
        swap_sprite_u_edges(help);
    }
    if (flip_v != 0) {
        swap_sprite_v_edges(help);
    }
}

WindowSpritePart *get_shortcut_icon_entry(void *window, s32 sel) {
    return (WindowSpritePart *)((TWindowBase *)window)->get_array_entry(sel + 0x1);
}

WindowSpritePart *TWindowSubSymbolChatPartsSet::get_parts_entry(saddr index) {
    return (WindowSpritePart *)get_array_entry(index + 9);
}

WindowSpritePart *TWindowSubSymbolChatPartsSet::get_parts_entry(void *window, int sel) {
    return (WindowSpritePart *)((TWindowBase *)window)->get_array_entry(sel + 5);
}

void apply_facial_part_sprites(WindowLayoutEntries *entries, s32 packed, s32 cur) {
    WindowSpritePart **p = (WindowSpritePart **)entries->items + cur;
    TWindowSubSymbolChatPartsSet::setup_part_sprites(p[5], p[9], p[1], (u16)((u8)packed), (s32)((packed >> 8) & 7), (s32)((packed >> 11) & 1), (s32)((packed >> 12) & 1), cur);
}
}

int set_symbol_chat_face_sprite(WindowSpritePart *sprite, u8 b) {
    const NJS_POINT2 *e;
    e = &symbol_chat_face_uv_table[b & 3];
    set_sprite_uv_from_pixels(sprite, (f32)e->x, (f32)e->y);
    return sprite->color = TWindowSubSymbolChatPartsSet::get_parts_color((b >> 2) & 7);
}

void apply_face_appearance_sprite(WindowLayoutEntries *entries, u8 appearance) {
    set_symbol_chat_face_sprite(static_cast<WindowSpritePart *>(entries->items[0]), appearance);
}

void get_symbol_chat_frame_size(int a0, void* a1) { *(float*)((char*)a1 + 0x0) = 136.0f; *(float*)((char*)a1 + 0x4) = 90.0f; }

void set_symbol_chat_parts(WindowLayoutEntries *entries, void *data) {
    SymbolChatPayload *payload = static_cast<SymbolChatPayload *>(data);
    s32 i;
    s32 j;

    apply_face_appearance_sprite(entries, (u8)payload->appearance);
    for (i = 0; i < 4; i += 1) {
        apply_facial_part_sprites(entries, payload->facial_parts[i], i);
    }
    j = 0;
    do {
        TWindowSubSymbolChatPartsSet::apply_part_to_window(entries, &payload->parts[j], j);
        j += 1;
    } while (j < 0xC);
}

void TWindowSubSymbolChat::init_layout_entries(saddr player) {
    saddr window_addr = (saddr)this;
    init_window_layout_entries(
        reinterpret_cast<WindowLayoutEntries *>(window_addr),
        &symbol_chat_layout_sprite_records,
        player);
}

void TWindowChatSymbol::update_visibility() {
    if (((s32) this->always_visible == 0) && (selected_preset == NULL || is_symbol_chat_preset_in_use(selected_preset) == 0)) {
        this->disallow_rendering();
        return;
    }
    this->allow_rendering();
    set_symbol_chat_parts(&this->entry_list, selected_preset->get_data_ptr());
}

void TWindowChatSymbol::set_selection(SymbolChatPreset *preset) {
    if (selected_preset != preset) {
        selected_preset = preset;
        update_visibility();
    }
}

void TWindowChatSymbol::set_from_key(s32 index) {
    SymbolChatPreset *preset = get_symbol_chat_preset(index);
    set_selection(preset);
}

#pragma push
#pragma fp_contract on
void TWindowChatSymbol::render() {
    WindowDrawContext *c_arg;

    c_arg = draw_default_entry();
    if (c_arg->open_tick < 0) {
        c_arg->scale[0] = (f32) ((f32) this->open_tick / 7.5f);
        c_arg->scale[1] = (f32) c_arg->scale[0];
    }
    draw_quest_message_frame(c_arg);
    c_arg->inner_x = (f32) ((0.5f * (frame_size[0] - 136.0f)) + c_arg->inner_x);
    c_arg->inner_y = (f32) ((0.5f * (this->frame_size[1] - 90.0f)) + c_arg->inner_y);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        c_arg);
}
#pragma pop

void TWindowChatSymbol::run_task() {
    update_window();
    update_fade();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char *)this + 0x24));
}


TWindowChatSymbol::~TWindowChatSymbol() {}

WindowDescriptor window_chat_symbol_settings = {
    {203.0f, 78.0f}, 50100.0f, &symbol_chat_layout_sprite_records, 0xB,
};

TWindowChatSymbol::TWindowChatSymbol(const NJS_POINT2 *position, saddr size) : TWindowBase((u8 *)&window_chat_symbol_settings, (s16)4, (u8 *)position) {
    this->m_name = window_chat_symbol_name;
    set_size((f32 *)size);
    this->selected_preset = 0;
    this->always_visible = 0;
}
