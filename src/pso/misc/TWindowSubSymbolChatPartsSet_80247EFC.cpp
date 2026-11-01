#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_8025B050.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet_80247EFC.h"
#include "pso/misc/TWindowSubSymbolChat_80076F88.h"
#include "pso/misc/TWindowChatSymbol.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChat.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

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

typedef struct Vec2_80247F68 {
    f32 x;
    f32 y;
} Vec2_80247F68;

typedef struct Win_80247F68 {
    u8 pad0[8];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} Win_80247F68;

struct V2_80248374 { f32 x; f32 y; };

struct Win_80248374 { u8 pad[0x2C]; int f2c; };

extern UV_802480EC TWindowSubSymbolChatPartsSet__part_uv_table[];
extern const f32 lbl_805DCB78;
extern const f32 lbl_805DCB80;
extern const f32 lbl_805DCB84;
extern const f32 lbl_805DCB88;
extern const f32 lbl_805DCB8C;
extern const f32 lbl_805DCB90;
extern "C" {
void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(Part_802480EC *arg0, Part_802480EC *arg1, Part_802480EC *arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void apply_part_to_window__28TWindowSubSymbolChatPartsSetFPvPvi(Obj_80248088 *arg0, Part_80248088 *arg1, s32 arg2);
extern const Vec2_80247F68 symbol_chat_part_uv_table[];
extern const Vec2_80247F68 symbol_chat_part_size_table[];
extern const f32 lbl_805DCB7C;
extern const V2_80248374 symbol_chat_face_uv_table[];
struct Ctl_80248324 { u8 pad[4]; s32 *tbl; };

struct RecoveredGlobal_80248494_lbl_804CE2E8 {
    s32 value;
    u8 remaining[0x4B4];
};

typedef char RecoveredGlobal_80248494_lbl_804CE2E8_size[sizeof(RecoveredGlobal_80248494_lbl_804CE2E8) == 0x4B8 ? 1 : -1];

void allow_rendering__7TObjectFv(TObject *arg0);
void disallow_rendering__7TObjectFv(TObject *arg0);
u8 * draw_default_entry__9TWindowDDFl();
void fn_80248324(Ctl_80248324 *c, s32 arg1, s32 arg2);
s32 draw_visible_window_entries(void *, void *, void *, f32, f32, f32);
s32 init_window_layout_entries(void *, void *, void *);

extern int symbol_chat_parts_color_table[];
extern RecoveredGlobal_80248494_lbl_804CE2E8 symbol_chat_layout_sprite_records;
extern const float lbl_805DCB94;
extern const float lbl_805DCB98;
extern const f32 lbl_805DCB9C;

int TWindowSubSymbolChatPartsSet::get_parts_entry(int a0) {  return symbol_chat_parts_color_table[a0]; }

void TWindowSubSymbolChatPartsSet::set_pos(s16 arg1, s16 arg2) {
    *(f32 *)&this->m_prev = (f32) (lbl_805DCB78 + (f32) arg1);
    *(f32 *)&this->m_next = (f32) arg2;
}

#pragma push
#pragma fp_contract on
#define o ((Win_80247F68 *)arg0)
void TWindowSubSymbolChatPartsSet::set_part_sprite(void *arg0, s16 id, s32 a, s32 b) {
    const Vec2_80247F68 *e;
    const Vec2_80247F68 *size;
    f32 h;
    f32 w;
    f32 k;
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
    k = lbl_805DCB7C;
    w = size->x;
    h = size->y;
    o->x -= k * w;
    o->y -= k * h;
    o->w = w;
    o->h = h;
    e = &symbol_chat_part_uv_table[id];
    set_sprite_uv_from_pixels((u8 *)o, (f32)e->x, (f32)e->y);
    if (a != 0) {
        swap_sprite_u_edges((u8 *)o);
    }
    if (b != 0) {
        swap_sprite_v_edges((u8 *)o);
    }
}
#undef o
#pragma pop

void TWindowSubSymbolChatPartsSet::get_entry_offset_d(s32 arg1) {
    this->get_array_entry(arg1 + 0xD);
}

void apply_part_to_window__28TWindowSubSymbolChatPartsSetFPvPvi(Obj_80248088 *arg0, Part_80248088 *arg1, s32 arg2) {
    void *w;
    u8 f;
    w = arg0->tbl->win[arg2];
    ((TWindowSubSymbolChatPartsSet *)w)->set_pos(arg1->a, arg1->b);
    f = arg1->flags;
    TWindowSubSymbolChatPartsSet::set_part_sprite(w, arg1->id, (s32)(f & 1), (s32)((f >> 1) & 1));
}

void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(Part_802480EC *arg0, Part_802480EC *arg1, Part_802480EC *arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    f32 u;
    f32 v;
    UV_802480EC *uv;
    if (arg3 == 0xFF) {
        ((TWindowHelpItem *)arg2)->set_flag0_bit2();
        ((TWindowHelpItem *)arg0)->set_flag0_bit2();
        ((TWindowHelpItem *)arg1)->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)arg2)->clear_visible_flag();
    ((TWindowSubStatusDisp *)arg0)->clear_visible_flag();
    ((TWindowSubStatusDisp *)arg1)->clear_visible_flag();
    u = lbl_805DCB78 * (f32)(arg3 & 7);
    v = lbl_805DCB78 * (f32)((arg3 >> 3) & 7);
    arg0->kind = ((arg3 >> 6) & 3) + 7;
    arg0->entry = TWindowSubSymbolChatPartsSet::get_parts_entry(arg4);
    if (arg3 <= 0x12) {
        uv = &TWindowSubSymbolChatPartsSet__part_uv_table[arg7];
        set_sprite_dimensions(arg0, lbl_805DCB80, lbl_805DCB80);
        arg2->x = arg0->x - lbl_805DCB84;
        arg2->y = arg0->y;
        set_sprite_dimensions(arg2, lbl_805DCB88, lbl_805DCB8C);
        set_sprite_uv_from_pixels((u8 *)arg2, uv->u, uv->v);
        ((TWindowHelpItem *)arg1)->set_flag0_bit2();
    } else {
        set_sprite_dimensions(arg0, lbl_805DCB90, lbl_805DCB90);
        arg1->x = arg0->x;
        arg1->y = arg0->y;
        ((TWindowHelpItem *)arg2)->set_flag0_bit2();
    }
    set_sprite_uv_from_pixels((u8 *)arg0, u, v);
    if (arg5 != 0) {
        swap_sprite_u_edges((u8 *)arg0);
    }
    if (arg6 != 0) {
        swap_sprite_v_edges((u8 *)arg0);
    }
}

void TWindowSubSymbolChatPartsSet__sub_802482B8(s32 arg0, s32 arg1) {
    ((TWindowBase *)arg0)->get_array_entry(arg1 + 0x1);
}

void TWindowSubSymbolChatPartsSet::get_parts_entry(s32 arg1) {
    this->get_array_entry(arg1 + 9);
}

void get_parts_entry__28TWindowSubSymbolChatPartsSetFii(s32 arg0, s32 arg1) {
    ((TWindowBase *)arg0)->get_array_entry(arg1 + 5);
}

void fn_80248324(Ctl_80248324 *c, s32 arg1, s32 cur) {
    s32 *p = c->tbl + cur;
    setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii((Part_802480EC *)(p[5]), (Part_802480EC *)(p[9]), (Part_802480EC *)(p[1]), (u16)((u8)arg1), (s32)((arg1 >> 8) & 7), (s32)((arg1 >> 11) & 1), (s32)((arg1 >> 12) & 1), cur);
}
}

#define w ((Win_80248374 *)arg0)
int set_symbol_chat_face_sprite(void *arg0, u8 b) {
    const V2_80248374 *e;
    e = &symbol_chat_face_uv_table[b & 3];
    set_sprite_uv_from_pixels((u8 *)w, (f32)e->x, (f32)e->y);
    return w->f2c = TWindowSubSymbolChatPartsSet::get_parts_entry((b >> 2) & 7);
}
#undef w

void fn_802483C8(void *arg0, u8 _w1) {
    set_symbol_chat_face_sprite((void *)((void*)(*(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x4)) + 0x0))), _w1);
}

void TWindowSubSymbolChat__sub_802483F0(int a0, void* a1) { *(float*)((char*)a1 + 0x0) = lbl_805DCB94; *(float*)((char*)a1 + 0x4) = lbl_805DCB98; }

void set_symbol_chat_parts__20TWindowSubSymbolChatFiPv(s32 arg0, void *arg1) {
    s32 i;
    s32 j;
    s32 off;

    ((s32 (*)(s32, u8))fn_802483C8)(arg0, (u8) *(s32 *)((s8 *)arg1 + 0));
    for (i = 0; i < 4; i += 1) {
        ((s32 (*)(s32, u16, s32))fn_80248324)(arg0, ((u16 *)arg1)[i + 2], i);
    }
    j = 0;
    off = 0;
    do {
        apply_part_to_window__28TWindowSubSymbolChatPartsSetFPvPvi((Obj_80248088 *)(arg0), (Part_80248088 *)((s8 *)arg1 + off + 0xC), j);
        off += 4;
        j += 1;
    } while (j < 0xC);
}

void TWindowSubSymbolChat::init_layout_entries(s32 player) {
    s32 arg0 = (s32)this;
    init_window_layout_entries((void *)arg0, &symbol_chat_layout_sprite_records.value, (void *)player);
}

void TWindowSubSymbolChatPartsSet::update_visibility() {
    u8 *arg0 = (u8 *)this;
    if (((s32) this->m_64 == 0) && (((u32) this->m_60 == 0U) || (is_symbol_chat_preset_in_use((u32 *)this->m_60) == 0))) {
        disallow_rendering__7TObjectFv((TObject *)arg0);
        return;
    }
    allow_rendering__7TObjectFv((TObject *)arg0);
    set_symbol_chat_parts__20TWindowSubSymbolChatFiPv((s32)(arg0 + 0x24), (void *)(((TWindowSubSymbolChat *)(this->m_60))->get_data_ptr()));
}

void TWindowSubSymbolChatPartsSet::set_selection(u32 arg1) {
    if ((u32) this->m_60 != arg1) {
        this->m_60 = arg1;
        update_visibility();
    }
}

void TWindowSubSymbolChat::set_from_key(s32 arg1) {
    s32 arg0 = (s32)this;
    s8 *tmp = (s8 *)get_symbol_chat_preset(arg1);
    ((TWindowSubSymbolChatPartsSet *)arg0)->set_selection((u32)((s32)tmp));
}

#pragma push
#pragma fp_contract on
void render__17TWindowChatSymbolFv(u8 *window_chat_symbol) {
    f32 temp_f1;
    f32 temp_f2;
    u8 *c_arg;

    c_arg = draw_default_entry__9TWindowDDFl();
    if ((s32) *(s32 *)((s8 *)c_arg + 0x30) < 0) {
        *(f32 *)((s8 *)c_arg + 0x28) = (f32) ((f32) *(s32 *)&((TWindowChatSymbol *)window_chat_symbol)->m_5c / lbl_805DCB9C);
        *(f32 *)((s8 *)c_arg + 0x2C) = (f32) *(f32 *)((s8 *)c_arg + 0x28);
    }
    ((TWindowBase *)window_chat_symbol)->draw_quest_message_frame(c_arg);
    *(f32 *)((s8 *)c_arg + 0x10) = (f32) ((lbl_805DCB7C * (((TWindowChatSymbol *)window_chat_symbol)->m_48 - lbl_805DCB94)) + *(f32 *)((s8 *)c_arg + 0x10));
    temp_f2 = *(f32 *)((s8 *)window_chat_symbol + 0x4C);
    temp_f1 = temp_f2 - lbl_805DCB98;
    *(f32 *)((s8 *)c_arg + 0x14) = (f32) ((lbl_805DCB7C * temp_f1) + *(f32 *)((s8 *)c_arg + 0x14));
    draw_visible_window_entries(window_chat_symbol, window_chat_symbol + 0x24, c_arg, temp_f1, temp_f2, lbl_805DCB7C);
}
#pragma pop
