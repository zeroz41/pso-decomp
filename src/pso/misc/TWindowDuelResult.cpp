#include "types.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowSubComCardList_8026CB08.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

struct RecoveredGlobal_8024F5B0___vt__17TWindowDuelResult {
    s32 value;
    u8 remaining[0x70];
};

struct RecoveredGlobal_8024F5B0_lbl_804CF020 {
    s32 value;
    u8 remaining[0x14];
};

struct Win_8024EF40 { u8 pad[0x20]; s16 player; u8 pad22[2]; u8 sub[4]; };

typedef struct Entry_8024F094 {
    u16 id;
    s16 rank;
    s32 value;
} Entry_8024F094;

typedef struct Win_8024F094 {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[2];
    u8 sub[4];
} Win_8024F094;

struct TWindowDuelResult {
    void sub_8024F094();
    void sub_8024EF40();
    void sub_8024F090();
    void sub_8024EF3C();
};

extern "C" {
const char *window_duel_result_class_name = "TWindowDuelResult";
}

extern "C" {
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_list_page_indicator(int, int);
void draw_window__17TWindowDuelResultFPv(u8 *arg0);
s32 construct_base__9TWindowDDFPUcsPUc(void *, void *, void *, int);
s32 TWindowDuelResult__sub_8024F3CC(void *);
u8 *init__21TWindowSubComCardListFiii(void *, s32, s32, s32);
s32 get_window_layout_position(int);

extern const char *window_duel_result_class_name;
u8 *TWindowDuelResult__ct(u8 *arg0, s16 arg1);
s32 get_localized_text_entry(int, int);
void *get_player_by_client_id(s32 i);
s32 TWindowDuelResult__sub_801C19AC(f32 *arg0);
u8 *get_array_entry__11TWindowBaseFi(void *, s32);
void init_window_layout_entries(void *, void *, int);
void set_default_status__17TWindowDuelResultFPvi(void *, int);
void sub_8024EF40__17TWindowDuelResultFv(Win_8024EF40 *arg0);
s32 get_shared_text_buffer(s32);
s32 *TWindowDuelResult__sub_801C257C(void);
void TWindowSubStatusDisp__sub_80228F5C(s32);
s32 text_builder_append(s32);
}
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2);
void text_builder_reset(void);
extern "C" {
void refresh_status_display__9TWindowDDFv(void *);
extern u8 lobby_rule_settings[];
void sub_8024F094__17TWindowDuelResultFv(Win_8024F094 *self);
void sub_8024F090__17TWindowDuelResultFv(void);
void sub_8024EF3C__17TWindowDuelResultFv(void);
void *destroy__17TWindowDuelResultFPvs(void *arg0, s16 arg1);
void update__17TWindowDuelResultFPv(u8 *arg0);
s32 TWindowDuelResult__sub_8024F330(void *);
s32 handle_list_page_flip_input(s32);
void __dl__7TObjectFPv(void *);

extern "C" u8 lbl_805D63F0[];
extern "C" const char lbl_805DCCA8[] = ":";
void *TWindowDuelResult__layout_entries[140] = {
    (void *)0x13, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x41a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCCA8, (void *)0x3,
    (void *)0x42aa0000, (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x41a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42200000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCCA8, (void *)0x3,
    (void *)0x42aa0000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCCA8, (void *)0x3,
    (void *)0x42aa0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x42960000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCCA8, (void *)0x3,
    (void *)0x42aa0000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43be0000,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x6, (void *)0x428c0000, (void *)0x43040000,
    (void *)0x41900000, (void *)0x41900000, (void *)0x43320000, (void *)0x434b0000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)&lbl_805D63F0, (void *)0x0,
    (void *)0x14, (void *)0x3, (void *)0x42b00000, (void *)0x43040000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x100, (void *)0x0,
};
void *duel_result_window_layout_table[119] = {
    (void *)0x10, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x43870000, (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DCCA8, (void *)0x4, (void *)0x43be0000,
    (void *)0x42200000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42700000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43870000, (void *)0x42700000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCCA8, (void *)0x4,
    (void *)0x43be0000, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x43870000, (void *)0x42a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCCA8,
    (void *)0x4, (void *)0x43be0000, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43870000,
    (void *)0x42c80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_805DCCA8, (void *)0x4, (void *)0x43be0000, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x6, (void *)0x428c0000, (void *)0x43040000, (void *)0x41900000,
    (void *)0x41900000, (void *)0x43320000, (void *)0x434b0000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)&lbl_805D63F0, (void *)0x0, (void *)0x14,
    (void *)0x3, (void *)0x42b00000, (void *)0x43040000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x100, (void *)0x0,
};
void *__vt__17TWindowDuelResult[5] = {
    (void *)0x43c20000, (void *)0x43240000, (void *)0x47437b00, (void *)0x0,
    (void *)0x3,
};
#define TWindowDuelResult__layout_entries ((u8 *)TWindowDuelResult__layout_entries)
#define duel_result_window_layout_table ((u8 *)duel_result_window_layout_table)
#define __vt__17TWindowDuelResult (*(RecoveredGlobal_8024F5B0___vt__17TWindowDuelResult *)__vt__17TWindowDuelResult)

void sub_8024EF3C__17TWindowDuelResultFv(void) {  }

void sub_8024EF40__17TWindowDuelResultFv(Win_8024EF40 *arg0) {
    s32 vals[4];
    u8 *pl;
    s32 i;
    u8 *a;
    u8 *b;
    u8 *c;
    init_window_layout_entries(arg0->sub, duel_result_window_layout_table, arg0->player);
    a = get_array_entry__11TWindowBaseFi(arg0, 0);
    set_default_status__17TWindowDuelResultFPvi(a, get_localized_text_entry(0x10, 0));
    c = get_array_entry__11TWindowBaseFi(arg0, 0xF);
    set_default_status__17TWindowDuelResultFPvi(c, get_localized_text_entry(0x10, 5));
    pl = (u8 *)get_player_by_client_id(arg0->player);
    if (pl != 0) {
        set_text_entry_string((u8 *)(get_array_entry__11TWindowBaseFi(arg0, 1)), (u32)(pl + 0x85C), 0x20);
        vals[0] = TWindowDuelResult__sub_801C19AC((f32 *)(pl + 0x75C));
        vals[1] = TWindowDuelResult__sub_801C19AC((f32 *)(pl + 0x76C));
        vals[2] = TWindowDuelResult__sub_801C19AC((f32 *)(pl + 0x78C));
        vals[3] = TWindowDuelResult__sub_801C19AC((f32 *)(pl + 0x77C));
        for (i = 0; i < 4; i++) {
            a = get_array_entry__11TWindowBaseFi(arg0, i * 3 + 2);
            b = get_array_entry__11TWindowBaseFi(arg0, i * 3 + 4);
            set_default_status__17TWindowDuelResultFPvi(a, get_localized_text_entry(0x10, i + 1));
            *(s32 *)(b + 0x20) = vals[i];
        }
    }
}

void sub_8024F090__17TWindowDuelResultFv(void) {  }

void sub_8024F094__17TWindowDuelResultFv(Win_8024F094 *self) {
    s32 i;
    s32 none;
    Entry_8024F094 *e;
    u8 *p;
    u8 *a;
    u8 *b;
    u8 *c;
    u8 *d;
    init_window_layout_entries(self->sub, TWindowDuelResult__layout_entries, self->player);
    a = get_array_entry__11TWindowBaseFi(self, 0);
    set_default_status__17TWindowDuelResultFPvi(a, get_localized_text_entry(0x10, 0));
    b = get_array_entry__11TWindowBaseFi(self, 0x12);
    set_default_status__17TWindowDuelResultFPvi(b, get_localized_text_entry(0x10, 5));
    none = 1;
    e = (Entry_8024F094 *)TWindowDuelResult__sub_801C257C();
    for (i = 0; i < 4; i++, e++) {
        p = (e->id == 0xFFFF) ? NULL : (u8 *)get_player_by_client_id(e->id);
        if (p != NULL && e->rank != 0) {
            none = 0;
        }
    }
    e = (Entry_8024F094 *)TWindowDuelResult__sub_801C257C();
    for (i = 0; i < 4; i++, e++) {
        a = get_array_entry__11TWindowBaseFi(self, i * 4 + 1);
        b = get_array_entry__11TWindowBaseFi(self, i * 4 + 2);
        c = get_array_entry__11TWindowBaseFi(self, i * 4 + 3);
        d = get_array_entry__11TWindowBaseFi(self, i * 4 + 4);
        p = (e->id == 0xFFFF) ? NULL : (u8 *)get_player_by_client_id(e->id);
        if (p == NULL) {
            *(u16 *)a |= 2;
            *(u16 *)b |= 2;
            *(u16 *)c |= 2;
            *(u16 *)d |= 2;
        } else {
            if (none) {
                set_default_status__17TWindowDuelResultFPvi(a, get_localized_text_entry(0x10, 0xA));
            } else if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1) {
                if (e->rank == 0) {
                    set_default_status__17TWindowDuelResultFPvi(a, get_localized_text_entry(0x10, 0xB));
                } else {
                    set_default_status__17TWindowDuelResultFPvi(a, get_localized_text_entry(0x10, 0xC));
                }
            } else {
                set_default_status__17TWindowDuelResultFPvi(a, get_localized_text_entry(0x10, e->rank + 6));
            }
            set_text_entry_string((u8 *)c, (u32)(p + 0x85C), 0x20);
            text_builder_reset();
            TWindowSubStatusDisp__sub_80228F5C(e->value);
            set_text_entry_string(d, (u32)((void *)get_shared_text_buffer(text_builder_append(get_localized_text_entry(0x10, 0xD)))), 0x20);
            refresh_status_display__9TWindowDDFv(d);
            *(f32 *)(d + 8) = (372.0f) - *(f32 *)(d + 0x10);
        }
    }
}

#pragma defer_codegen on
s32 TWindowDuelResult__sub_8024F3CC(void *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    typedef void (TWindowDuelResult::*PT)();
    static PT tbl[2] = { &TWindowDuelResult::sub_8024F094, &TWindowDuelResult::sub_8024EF40 };
    TWindowDuelResult *w = (TWindowDuelResult *)arg0;
    ((TWindowSubStatusDisp *)(arg0 + 0x24))->destroy_all_items();
    s8 t = ((TWindowSubStatusDisp *)(*(s32 *)(arg0 + 0x68)))->get_type();
    (w->*tbl[t])();
    TWindowDuelResult__sub_8024F330(arg0);
}

s32 TWindowDuelResult__sub_8024F330(void *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    typedef void (TWindowDuelResult::*PT)();
    static PT tbl[2] = { &TWindowDuelResult::sub_8024F090, &TWindowDuelResult::sub_8024EF3C };
    TWindowDuelResult *w = (TWindowDuelResult *)arg0;
    s8 t = ((TWindowSubStatusDisp *)(*(s32 *)(arg0 + 0x68)))->get_type();
    (w->*tbl[t])();
}
#pragma defer_codegen off

void draw_window__17TWindowDuelResultFPv(u8 *arg0) {
    s32 temp_r3;
    temp_r3 = ((TWindowBase *)arg0)->setup_window_draw_context((s32)(arg0 + 0x60));
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    draw_list_page_indicator((int) (*(s32 *)((s8 *)arg0 + 0x68)), temp_r3);
}

void update__17TWindowDuelResultFPv(u8 *arg0_) {
    if (!(*(s32 *)((s8 *)arg0_ + 0x2C) & 2)) {
        *(s32 *)((s8 *)arg0_ + 0x5C) = 0x01000000;
    }
    if (handle_list_page_flip_input(*(s32 *)((s8 *)arg0_ + 0x68)) != 0) {
        TWindowDuelResult__sub_8024F3CC(arg0_);
    }
    TWindowDuelResult__sub_8024F330(arg0_);
    ((TWindowDD *)arg0_)->initialize_subwindow();
    ((TWindowBase *)arg0_)->update_window_entry_list(arg0_ + 0x24);
}

extern "C" void render_shadows__7TObjectFv();
void *lbl_804CF020[6] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__17TWindowDuelResultFPvs, (void *)&update__17TWindowDuelResultFPv,
    (void *)&draw_window__17TWindowDuelResultFPv, (void *)&render_shadows__7TObjectFv,
};
#define lbl_804CF020 ((s32 *)lbl_804CF020)

void *destroy__17TWindowDuelResultFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804CF020;
        delete_if_allocated((s32)(*(void **)((s8 *)arg0 + 0x68)), 1);
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8024F5B0___vt__17TWindowDuelResult_size[sizeof(RecoveredGlobal_8024F5B0___vt__17TWindowDuelResult) == 0x74 ? 1 : -1];
typedef char RecoveredGlobal_8024F5B0_lbl_804CF020_size[sizeof(RecoveredGlobal_8024F5B0_lbl_804CF020) == 0x18 ? 1 : -1];
u8 *TWindowDuelResult__ct(u8 *arg0_, s16 arg1) {
    u8 *temp_r3;
    u8 *var_r0;
    construct_base__9TWindowDDFPUcsPUc((void *)arg0_, &__vt__17TWindowDuelResult.value, (void *)arg1, (int) (get_window_layout_position(0x24)));
    *(s32 **)((s8 *)arg0_ + 0x18) = &(*(RecoveredGlobal_8024F5B0_lbl_804CF020 *)lbl_804CF020).value;
    *(s32 *)((s8 *)arg0_ + 0) = (s32) ((s32)window_duel_result_class_name);
    temp_r3 = (u8 *)((int)::operator new(0xC));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(init__21TWindowSubComCardListFiii(temp_r3, 0, 2, (s32) *(s16 *)((s8 *)arg0_ + 0x20)));
    }
    *(u8 **)((s8 *)arg0_ + 0x68) = var_r0;
    if (TCameraCtrl::get_camera_id() > 2) {
        *(f32 *)((s8 *)arg0_ + 0x60) = (f32) (0.8f);
        *(f32 *)((s8 *)arg0_ + 0x64) = (f32) (0.8f);
    } else if (TCameraCtrl::get_camera_id() == 2) {
        *(f32 *)((s8 *)arg0_ + 0x60) = (f32) (1.0f);
        *(f32 *)((s8 *)arg0_ + 0x64) = (f32) (1.0f);
    } else {
        *(f32 *)((s8 *)arg0_ + 0x60) = (f32) (1.0f);
        *(f32 *)((s8 *)arg0_ + 0x64) = (f32) (1.0f);
    }
    TWindowDuelResult__sub_8024F3CC(arg0_);
    return arg0_;
}
}
