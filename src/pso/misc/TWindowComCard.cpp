#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowComCard.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TUnk_804CE964.h"

struct RecoveredGlobal_80249BA8_lbl_804CE8D0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80249BA8___vt__14TWindowComCard {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
void render__14TWindowComCardFv(s32 arg0);
s32 TWindowSubComCard__sub_8007B070(s32);
void *__nw__7TObjectFUl(int);
extern s32 local_client_id;
s32 update_com_card_display(s32, s32);
extern s32 lbl_805D38C0;
u8 *TWindowComCard__ct(u8 *arg0, s32 arg1, s32 arg2);
void TWindowComCard__sub_80249920(s32 arg0, s32 arg1, s32 arg2);
u8 TWindowComCard__sub_80249C18(void* p);
u8 TWindowComCard__sub_80249C20(void* p);
void *__dt__14TWindowComCardFv(void *arg0, s16 arg1);
void run_task__14TWindowComCardFv(void* p);
s32 get_card_entry__17TWindowSubComCardFi(s32 arg0);
void __dl__7TObjectFPv(void *);
int initialize_subwindow__9TWindowDDFv(void*);

extern "C" u8 lbl_8044EB28[];
extern "C" u8 lbl_8044EB30[];
extern "C" u8 lbl_8044EB38[];
extern "C" u8 lbl_8044EB40[];
extern "C" u8 lbl_8044EB48[];
extern "C" u8 lbl_805D63F0[];
extern "C" u8 lbl_805DCBC8[];
extern "C" void render_shadows__7TObjectFv();
void run_task__13TUnk_804CE964Fv(u8 *arg0);
void *TWindowComCard__sub_80249E80(void *arg0, s16 arg1);
void render__13TUnk_804CE964Fv(s32 arg0);
extern void *lbl_804CE820[44];
extern void *lbl_804CE918[14];
void *lbl_804CE820[44] = {
    (void *)0x6, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x40,
    (void *)0x0, (void *)0x3, (void *)0x43460000, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x40, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x40, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x40, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x40,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
};
void *TWindowComCard__window_desc[5] = {
    (void *)0x434e0000, (void *)0x43340000, (void *)0x4743b400, (void *)&lbl_804CE820,
    (void *)0x23,
};
void *com_card_status_text_table[6] = {
    (void *)&lbl_8044EB28, (void *)&lbl_8044EB30, (void *)&lbl_8044EB38, (void *)&lbl_805DCBC8,
    (void *)&lbl_8044EB40, (void *)&lbl_8044EB48,
};
void *__vt__14TWindowComCard[7] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__14TWindowComCardFv, (void *)&run_task__14TWindowComCardFv,
    (void *)&render__14TWindowComCardFv, (void *)&render_shadows__7TObjectFv, (void *)0x0,
};
void *lbl_804CE918[14] = {
    (void *)0x1, (void *)0x1, (void *)0x6, (void *)0x0,
    (void *)0x0, (void *)0x42000000, (void *)0x41e00000, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)&lbl_805D63F0,
    (void *)0x1, (void *)0x4,
};
void *TWindowComCard__window_desc_b[5] = {
    (void *)0x42000000, (void *)0x41e00000, (void *)0x4788d100, (void *)&lbl_804CE918,
    (void *)0x82b,
};
void *lbl_804CE964[6] = {
    (void *)0x0, (void *)0x0, (void *)&TWindowComCard__sub_80249E80, (void *)&run_task__13TUnk_804CE964Fv,
    (void *)&render__13TUnk_804CE964Fv, (void *)&render_shadows__7TObjectFv,
};
#define TWindowComCard__window_desc (*(RecoveredGlobal_80249BA8_lbl_804CE8D0 *)TWindowComCard__window_desc)
#define __vt__14TWindowComCard ((s32 *)__vt__14TWindowComCard)
#define TWindowComCard__window_desc_b ((s32 *)TWindowComCard__window_desc_b)
#define lbl_804CE964 ((s32 *)lbl_804CE964)

void TWindowComCard__sub_80249920(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp = arg2 + (arg1 * 0x90);
    if (temp != 0) {
        update_com_card_display(arg0 + 0x24, temp);
    }
}

void TWindowComCard::set_display_value(s32 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    s32 temp = arg2 + (arg1 << 8);
    if (temp != 0) {
        update_com_card_display(arg0 + 0x24, temp);
    }
}

u8 *TWindowComCard::create_for_card(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r30;
    s32 var_r31;
    s32 var_r4;
    s32 var_r5;
    u8 *window_dd;
    u8 *var_r0;
    u8 *var_r3;
    var_r30 = arg0;
    if (arg1 < 0) {
        var_r3 = NULL;
        return NULL;
    }
    var_r3 = (u8 *)((void *)0x60);
    var_r31 = arg2 + (arg1 * 0x90);
    window_dd = (u8 *)(((u8 *)__nw__7TObjectFUl(0x60)));
    var_r0 = window_dd;
    if (var_r0 != NULL) {
        var_r4 = var_r30;
        var_r5 = var_r31;
        var_r0 = (u8 *)(((u8 *)TWindowComCard__ct(window_dd, var_r4, var_r5)));
    }
    var_r3 = var_r0;
    return var_r3;
}

void *TWindowComCard::create(void *arg0, void *arg1) {
    void *x0;
    void *o;
    x0 = (void *)get_card_entry__17TWindowSubComCardFi((s32)arg1);
    if (x0 == NULL) {
        return NULL;
    }
    o = __nw__7TObjectFUl(0x60);
    if (o != NULL) {
        o = TWindowComCard__ct((u8 *)o, (s32)arg0, (s32)x0);
    }
    return o;
}

s32 TWindowSubComCard::create_com_card_window(s32 arg0) {
    s32 keyboard_mode;
    s32 window_dd;
    s32 var_r0;
    keyboard_mode = TWindowSubComCard::get_keyboard_mode();
    if (keyboard_mode == 0) {
        return 0;
    }
    if (TWindowSubComCard__sub_8007B070(keyboard_mode) != 0) {
        ((TWindowSubComCard *)keyboard_mode)->clear_and_init((void *)local_client_id);
    }
    window_dd = ((s32)__nw__7TObjectFUl(0x60));
    var_r0 = window_dd;
    if (var_r0 != 0) {
        var_r0 = ((s32)TWindowComCard__ct((u8 *)window_dd, (s32)arg0, (s32)keyboard_mode));
    }
    return var_r0;
}

void render__14TWindowComCardFv(s32 arg0) {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)temp_r3);
}

void run_task__14TWindowComCardFv(void* p) { initialize_subwindow__9TWindowDDFv(p); ((TWindowBase *)p)->update_fade(); ((TWindowBase *)p)->update_window_entry_list((char*)p + 0x24); }

void *__dt__14TWindowComCardFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TWindowComCard;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80249BA8_lbl_804CE8D0_size[sizeof(RecoveredGlobal_80249BA8_lbl_804CE8D0) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80249BA8___vt__14TWindowComCard_size[sizeof(RecoveredGlobal_80249BA8___vt__14TWindowComCard) == 0x1C ? 1 : -1];
u8 *TWindowComCard__ct(u8 *window_dd, s32 arg1, s32 arg2) {
    ((TWindowDD *)window_dd)->construct_base((u8 *)((s32) &TWindowComCard__window_desc.value), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_dd + 0x18) = (s32 *)__vt__14TWindowComCard;
    *(s32 *)((s8 *)window_dd + 0) = (s32) lbl_805D38C0;
    update_com_card_display((s32)(window_dd + 0x24), arg2);
    return window_dd;
}

void*TWindowComCard::get_kbd_ptr() { return (char*)this + 0x20; }
u8 TWindowComCard__sub_80249C18(void* p) { return *(u8*)((char*)p + 0x8e); }
u8 TWindowComCard__sub_80249C20(void* p) { return *(u8*)((char*)p + 0x8d); }
}
extern u8 *text_language_group_table;
s32 get_class_name_text(s32 arg0);
s32 get_class_name_text(s32 arg0) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0x1C)) + (arg0 * 4));
}

s32 get_status_effect_icon_index(u32 arg0);
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);

extern u8 com_card_help_panel_rect_table[];

void TWindowComCard::set_help_mode(s32 arg1) {
    void *temp_r4;

    if (arg1 == 0xE) {
        *(u16 *)&this->m_name = (u16) (*(u16 *)&this->m_name | 2);
        return;
    }
    *(u16 *)&this->m_name = (u16) (*(u16 *)&this->m_name & 0xFFFFFFFD);
    if (arg1 < 0xA) {
        this->m_34 = 1;
    } else {
        this->m_34 = 2;
    }
    temp_r4 = com_card_help_panel_rect_table + (arg1 * 8);
    set_sprite_uv_from_pixels((u8 *)this, *(f32 *)((s8 *)temp_r4 + 0), *(f32 *)((s8 *)temp_r4 + 4));
}

void*TWindowComCard::get_card_name_ptr() { return (char*)this + 0xa; }
s32 get_status_effect_icon_index(u32 arg0) {
    switch (arg0) {
    case 3:
        return 1;
    case 9:
        return 6;
    case 10:
        return 8;
    case 11:
        return 7;
    case 12:
        return 9;
    case 15:
        return 3;
    case 16:
        return 4;
    case 17:
        return 5;
    case 18:
        return 0;
    case 2:
        return 2;
    default:
        return 0xE;
    }
}
extern "C" {

void TWindowComCard::set_selected_index(s32 arg1) {
    s32 temp;
    if ((s32) *(s32 *)((s8 *)this + 0x70) != arg1) {
        *(s32 *)((s8 *)this + 0x70) = arg1;
        temp = this->get_array_entry(0);
        ((TWindowComCard *)temp)->set_help_mode(*(s32 *)((s8 *)this + 0x70));
    }
}

void TWindowComCard__sub_80249D7C(u8 *arg0, s32 arg1);

extern const f32 lbl_805DCBD0;

#pragma push
#pragma fp_contract on
void TWindowComCard__sub_80249D7C(u8 *arg0, s32 arg1) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x6C) != arg1) {
        *(s32 *)((s8 *)arg0 + 0x6C) = arg1;
        *(f32 *)((s8 *)arg0 + 0x30) = (f32) ((lbl_805DCBD0 * (f32) *(s32 *)((s8 *)arg0 + 0x6C)) + (*(f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x60)) + 0x40) + *(f32 *)((s8 *)arg0 + 0x64)));
        *(s32 *)((s8 *)arg0 + 0x50) = 0xF;
    }
}
}
#pragma pop

#include "pso/misc/TWindowTradeRequest.h"

extern "C" {
typedef struct Parent_80249ED8 {
    u8 pad0[0x40];
    f32 x;
    f32 y;
} Parent_80249ED8;

typedef struct Vec2_80249ED8 {
    f32 x;
    f32 y;
} Vec2_80249ED8;

typedef struct Win_80249ED8 {
    u8 pad0[0x18];
    s32 *vtbl;
    u8 pad1C[0x30 - 0x1C];
    f32 x;
    f32 y;
    u8 pad38[0x60 - 0x38];
    Parent_80249ED8 *parent;
    Vec2_80249ED8 ofs;
    s32 col;
    s32 mode;
} Win_80249ED8;

extern struct Obj054_80249DE4 *TWindowCtrl__active_window;
extern u16 lbl_805D63FC;
struct Obj054_80249DE4 { char pad[0x38]; u32 field38; };

void request_active_window_close(void);

void TUnk_804CE964::render() {
    s32 arg0 = (s32)this;
    s8 *tmp = (s8 *)draw_default_entry__9TWindowDDFl();
    ((s32 (*)(s32, s32, s32))draw_visible_window_entries)(arg0, arg0 + 0x24, (s32)tmp);
}

void TUnk_804CE964::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    u8 *temp_r4;
    temp_r4 = (unsigned char *) (this->m_60);
    temp_f1 = *(f32 *)((s8 *)temp_r4 + 0x44);
    this->m_34 = (f32) (temp_f1 + this->m_68);
    this->m_44 = (f32) this->m_34;
    ((s32 (*)(void *, int, f32))initialize_subwindow__9TWindowDDFv)((void *)arg0, (int)temp_r4, (f32)temp_f1);
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(arg0 + 0x24);
}

void *TWindowComCard__sub_80249E80(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804CE964;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
Win_80249ED8 *TWindowComCard__sub_80249ED8(Win_80249ED8 *o, Parent_80249ED8 *parent, Vec2_80249ED8 *ofs, s32 col, s32 mode, s32 arg5) {
    ((TWindowDD *)o)->construct_base((u8 *)TWindowComCard__window_desc_b, (s16)arg5, (u8 *)(get_zero_vec2()));
    o->vtbl = (s32 *)lbl_804CE964;
    o->parent = parent;
    o->ofs.x = ofs->x;
    o->ofs.y = ofs->y;
    o->col = col;
    o->mode = mode;
    o->x = lbl_805DCBD0 * (f32)o->col + (o->parent->x + o->ofs.x);
    o->y = o->parent->y + o->ofs.y;
    ((TWindowBase *)o)->save_position();
    ((TWindowComCard *)((s32)((TWindowBase *)o)->get_array_entry(0)))->set_help_mode(mode);
    return o;
}
#pragma pop

void TWindowTradeRequest::close_request_window() {
    u8 *object;
    lbl_805D63FC &= 0xFFFFFFF7;
    if ((void *) (*(u8 * *)&TWindowCtrl__active_window) != NULL) {
        object = (u8 *)(*(u8 **)((s8 *)(*(u8 * *)&TWindowCtrl__active_window) + 0x40));
        if (object != NULL) {
            queue_destruction__7TObjectFv(object);
            *(u8 **)((s8 *)(*(u8 * *)&TWindowCtrl__active_window) + 0x40) = NULL;
        }
    }
}

void request_active_window_close(void) {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->field38 != 0U)) {
        ((TWindowCtrl *)((void*)TWindowCtrl__active_window->field38))->set_flag1e_bit8();
    }
}

}
