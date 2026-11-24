#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet_80247EFC.h"
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
#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"

#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/system/task/TObject.h"

struct Part_802480EC {
    u8 pad0[8];
    f32 x;
    f32 y;
    u8 pad10[0x1C];
    s32 entry;
    u8 pad30[4];
    s32 kind;
};

struct UV_802480EC {
    f32 u;
    f32 v;
};

typedef struct Tbl_80248088 { u8 pad[0x34]; void *win[1]; } Tbl_80248088;

typedef struct Obj_80248088 { u8 pad[4]; Tbl_80248088 *tbl; } Obj_80248088;

typedef struct Part_80248088 { s8 id; u8 a; u8 b; u8 flags; } Part_80248088;

typedef struct Win_80247F68 {
    u8 pad0[8];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} Win_80247F68;

struct Win_80248374 { u8 pad[0x2C]; int parts_entry; };

extern "C" {
void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(Part_802480EC *arg0, Part_802480EC *arg1, Part_802480EC *arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void apply_part_to_window__28TWindowSubSymbolChatPartsSetFPvPvi(Obj_80248088 *arg0, Part_80248088 *arg1, s32 arg2);

struct SymbolChatSpriteLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord recs[25];
};

void fn_80248324(WindowLayoutEntries *entries, s32 arg1, s32 arg2);


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
const char *TWindowChatSymbol__name = "TWindowChatSymbol";
#pragma pop

extern const NJS_POINT2 symbol_chat_face_uv_table[4];
extern const UV_802480EC TWindowSubSymbolChatPartsSet__part_uv_table[4];
extern const NJS_POINT2 symbol_chat_part_uv_table[70];
extern const NJS_POINT2 symbol_chat_part_size_table[3];
extern const int symbol_chat_parts_color_table[8];
extern const int chat_help_color_table[8];

// Texture coordinates of the face sprites, one per face direction.
const NJS_POINT2 symbol_chat_face_uv_table[4] = {
    { 2.0f, 194.0f }, { 2.0f, 130.0f }, { 66.0f, 130.0f }, { 66.0f, 194.0f },
};
const UV_802480EC TWindowSubSymbolChatPartsSet__part_uv_table[4] = {
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


int TWindowSubSymbolChatPartsSet::get_parts_entry(int a0) {  return symbol_chat_parts_color_table[a0]; }

void TWindowSubSymbolChatPartsSet::set_pos(s16 arg1, s16 next) {
    *(f32 *)&this->m_prev = (f32) (32.0f + (f32) arg1);
    *(f32 *)&this->m_next = (f32) next;
}

#pragma push
#pragma fp_contract on
#define o ((Win_80247F68 *)arg0)
void TWindowSubSymbolChatPartsSet::set_part_sprite(void *arg0, s16 id, s32 a, s32 b) {
    const NJS_POINT2 *e;
    const NJS_POINT2 *size;
    if (id == -1) {
        ((TWindowHelpItem *)o)->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)o)->clear_visible_flag();
    if (id < 0x30) {
        size = &symbol_chat_part_size_table[0];
    } else if (id < 0x3C) {
        size = &symbol_chat_part_size_table[1];
    } else {
        size = &symbol_chat_part_size_table[2];
    }
    o->x -= 0.5f * size->x;
    o->y -= 0.5f * size->y;
    o->w = size->x;
    o->h = size->y;
    e = &symbol_chat_part_uv_table[id];
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(o), (f32)e->x, (f32)e->y);
    if (a != 0) {
        swap_sprite_u_edges(reinterpret_cast<WindowSpritePart *>(o));
    }
    if (b != 0) {
        swap_sprite_v_edges(reinterpret_cast<WindowSpritePart *>(o));
    }
}
#undef o
#pragma pop

u16 *TWindowSubSymbolChatPartsSet::get_entry_offset_d(s32 sel) {
    return (u16 *)this->get_array_entry(sel + 0xD);
}

void apply_part_to_window__28TWindowSubSymbolChatPartsSetFPvPvi(Obj_80248088 *arg0, Part_80248088 *arg1, s32 arg2) {
    void *w;
    u8 f;
    w = arg0->tbl->win[arg2];
    ((TWindowSubSymbolChatPartsSet *)w)->set_pos(arg1->a, arg1->b);
    f = arg1->flags;
    TWindowSubSymbolChatPartsSet::set_part_sprite(w, arg1->id, (s32)(f & 1), (s32)((f >> 1) & 1));
}

void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(Part_802480EC *help, Part_802480EC *arg1, Part_802480EC *shortcut_icon, u16 arg3, s32 sel, s32 arg5, s32 arg6, s32 arg7) {
    f32 u;
    f32 v;
    const UV_802480EC *uv;
    if (arg3 == 0xFF) {
        ((TWindowHelpItem *)shortcut_icon)->set_flag0_bit2();
        ((TWindowHelpItem *)help)->set_flag0_bit2();
        ((TWindowHelpItem *)arg1)->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)shortcut_icon)->clear_visible_flag();
    ((TWindowSubStatusDisp *)help)->clear_visible_flag();
    ((TWindowSubStatusDisp *)arg1)->clear_visible_flag();
    u = 32.0f * (f32)(arg3 & 7);
    v = 32.0f * (f32)((arg3 >> 3) & 7);
    help->kind = ((arg3 >> 6) & 3) + 7;
    help->entry = TWindowSubSymbolChatPartsSet::get_parts_entry(sel);
    if (arg3 <= 0x12) {
        uv = &TWindowSubSymbolChatPartsSet__part_uv_table[arg7];
        set_sprite_dimensions(reinterpret_cast<WindowSpritePart *>(help), 31.0f, 31.0f);
        shortcut_icon->x = help->x - 5.0f;
        shortcut_icon->y = help->y;
        set_sprite_dimensions(reinterpret_cast<WindowSpritePart *>(shortcut_icon), 50.0f, 40.0f);
        set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(shortcut_icon), uv->u, uv->v);
        ((TWindowHelpItem *)arg1)->set_flag0_bit2();
    } else {
        set_sprite_dimensions(reinterpret_cast<WindowSpritePart *>(help), 30.0f, 30.0f);
        arg1->x = help->x;
        arg1->y = help->y;
        ((TWindowHelpItem *)shortcut_icon)->set_flag0_bit2();
    }
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), u, v);
    if (arg5 != 0) {
        swap_sprite_u_edges(reinterpret_cast<WindowSpritePart *>(help));
    }
    if (arg6 != 0) {
        swap_sprite_v_edges(reinterpret_cast<WindowSpritePart *>(help));
    }
}

u16 *TWindowSubSymbolChatPartsSet__sub_802482B8(void *window, s32 sel) {
    return (u16 *)((TWindowBase *)window)->get_array_entry(sel + 0x1);
}

u16 *TWindowSubSymbolChatPartsSet::get_parts_entry(saddr index) {
    return (u16 *)get_array_entry(index + 9);
}

u16 *TWindowSubSymbolChatPartsSet::get_parts_entry(void *window, int sel) {
    return (u16 *)((TWindowBase *)window)->get_array_entry(sel + 5);
}

void fn_80248324(WindowLayoutEntries *entries, s32 arg1, s32 cur) {
    Part_802480EC **p = (Part_802480EC **)entries->items + cur;
    setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(p[5], p[9], p[1], (u16)((u8)arg1), (s32)((arg1 >> 8) & 7), (s32)((arg1 >> 11) & 1), (s32)((arg1 >> 12) & 1), cur);
}
}

#define w ((Win_80248374 *)arg0)
int set_symbol_chat_face_sprite(void *arg0, u8 b) {
    const NJS_POINT2 *e;
    e = &symbol_chat_face_uv_table[b & 3];
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(w), (f32)e->x, (f32)e->y);
    return w->parts_entry = TWindowSubSymbolChatPartsSet::get_parts_entry((b >> 2) & 7);
}
#undef w

void fn_802483C8(WindowLayoutEntries *entries, u8 appearance) {
    set_symbol_chat_face_sprite(entries->items[0], appearance);
}

void TWindowSubSymbolChat__sub_802483F0(int a0, void* a1) { *(float*)((char*)a1 + 0x0) = 136.0f; *(float*)((char*)a1 + 0x4) = 90.0f; }

void set_symbol_chat_parts(WindowLayoutEntries *entries, void *data) {
    SymbolChatPayload *arg1 = static_cast<SymbolChatPayload *>(data);
    s32 i;
    s32 j;

    fn_802483C8(entries, (u8)arg1->appearance);
    for (i = 0; i < 4; i += 1) {
        fn_80248324(entries, arg1->facial_parts[i], i);
    }
    j = 0;
    do {
        apply_part_to_window__28TWindowSubSymbolChatPartsSetFPvPvi((Obj_80248088 *)entries, (Part_80248088 *)&arg1->parts[j], j);
        j += 1;
    } while (j < 0xC);
}

void TWindowSubSymbolChat::init_layout_entries(saddr player) {
    saddr arg0 = (saddr)this;
    init_window_layout_entries(
        reinterpret_cast<WindowLayoutEntries *>(arg0),
        &symbol_chat_layout_sprite_records,
        player);
}

void TWindowChatSymbol::update_visibility() {
    u8 *arg0 = (u8 *)this;
    if (((s32) this->m_64 == 0) && (selected_preset == NULL || is_symbol_chat_preset_in_use(selected_preset) == 0)) {
        ((TObject *)arg0)->disallow_rendering();
        return;
    }
    ((TObject *)arg0)->allow_rendering();
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
    u8 *c_arg;

    c_arg = reinterpret_cast<u8 *>(draw_default_entry());
    if ((s32) *(s32 *)((s8 *)c_arg + 0x30) < 0) {
        *(f32 *)((s8 *)c_arg + 0x28) = (f32) ((f32) this->open_tick / 7.5f);
        *(f32 *)((s8 *)c_arg + 0x2C) = (f32) *(f32 *)((s8 *)c_arg + 0x28);
    }
    draw_quest_message_frame(c_arg);
    *(f32 *)((s8 *)c_arg + 0x10) = (f32) ((0.5f * (frame_size[0] - 136.0f)) + *(f32 *)((s8 *)c_arg + 0x10));
    *(f32 *)((s8 *)c_arg + 0x14) = (f32) ((0.5f * (this->frame_size[1] - 90.0f)) + *(f32 *)((s8 *)c_arg + 0x14));
    draw_visible_window_entries(
        this,
        &this->entry_list,
        reinterpret_cast<WindowDrawContext *>(c_arg));
}
#pragma pop

void TWindowChatSymbol::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char *)this + 0x24));
}

extern "C" {

TWindowChatSymbol::~TWindowChatSymbol() {}

WindowDescriptor window_chat_symbol_settings = {
    {203.0f, 78.0f}, 50100.0f, &symbol_chat_layout_sprite_records, 0xB,
};

TWindowChatSymbol::TWindowChatSymbol(saddr arg1, saddr arg2) : TWindowBase((u8 *)&window_chat_symbol_settings, (s16)4, (u8 *)arg1) {
    this->m_name = TWindowChatSymbol__name;
    set_size((f32 *)arg2);
    this->selected_preset = 0;
    this->m_64 = 0;
}
}
