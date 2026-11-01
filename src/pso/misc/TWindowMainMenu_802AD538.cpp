#include "types.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowMainMenu_802AD538.h"
struct TWindowSubComCard;
#include "pso/misc/TWindowMenuMainMenu.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TLanguage.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Item_802AE4DC { u8 pad[0x12]; u8 sel; };

struct Menu_802AE4DC {
    u8 pad[0x61];
    s8 cur;
    u8 pad2[0x124 - 0x62];
    Item_802AE4DC *items[8];
};

extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
void play_cursor_sound__15TWindowMainMenuFv(Menu_802AE4DC *m, int d);
struct Item_802ADADC { u8 pad[0x12]; u8 f12; };

struct Obj_802ADADC { u8 pad[0x61]; s8 idx; u8 pad2[0x124 - 0x62]; Item_802ADADC *items[8]; };

struct Item_802ADAAC { u8 pad[0x11]; s8 f11; };

struct Obj_802ADAAC { u8 pad[0x61]; s8 idx; u8 pad2[0x124 - 0x62]; Item_802ADAAC *items[8]; };

struct MM_802AD90C {
    u8 pad0[0x60];
    u8 flags;
    u8 pad61;
    s16 cnt;
    u8 pad64[0x124 - 0x64];
    void *slots[8];
};

struct Hd_802ADA48 { u32 w[4]; };

struct Col_802ADA48 { Hd_802ADA48 h; u8 b0, b1, b2, b3, b4, b5, b6, b7; };

struct Menu_802AD980 {
    u8 pad[0x60];
    u8 flags;
    s8 cur;
    s16 count;
    u8 pad2[0x124 - 0x64];
    Col_802ADA48 *slots[8];
};

struct Obj_802ADC04 { u8 pad[0x124]; void *items[8]; };

struct Menu_802ADD38 {
    u8 pad[0x60];
    u8 flags;
    s8 cur;
    s16 count;
    u8 pad2[0x124 - 0x64];
    s32 slots[8];
};

struct RecoveredGlobal_802AE59C_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Rect_802AE2B0 { f32 x, y, w, h; u8 pad[0x34 - 0x10]; u32 color; };

typedef char RecoveredGlobal_802AE59C_lbl_8050E208_size[sizeof(RecoveredGlobal_802AE59C_lbl_8050E208) == 0x1B0 ? 1 : -1];

struct Item_802AD538 {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xc;
    s8 x10;
    s8 x11;
    s8 x12;
    u8 x13;
    s8 x14;
};

struct Win_802AD538 {
    u8 pad[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
};

struct UV_802AD538 { f32 u, v; };

struct Rect_802AD538 {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

struct Item_802AD7F0 {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xc;
    s8 x10;
    s8 x11;
    s8 x12;
    u8 x13;
    s8 x14;
};

s32 is_split_screen();
int copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *, void *);
void begin_render__20TWindowSubStatusDispFl(void);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
s32 apply_choice__20TWindowChoiceSettingFllll(void *, int, int, int);
f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *);
s32 is_window_reveal_complete__11TWindowBaseFv();
s32 sub_80246948__11TWindowBaseFv();
s32 try_open__19TWindowKeyBoardSoftFii(s32 arg0, s32 arg1);
Rect_802AE2B0 * open_singleton__19TWindowKeyBoardSoftFiiii(void *, void *, s32, f32, s32);
s32 fn_8026CB68();
void draw_item_labels__15TWindowMainMenuFv(Item_802AD538 *p, Win_802AD538 *w);
void park_selection__15TWindowMainMenuFPv(Menu_802AD980 *arg0);
void copy_color_entry__15TWindowMainMenuFPvPv(Col_802ADA48 *arg0, Col_802ADA48 *arg1);
void TWindowMainMenu__sub_802ADADC(Obj_802ADADC *self, s8 i);
int find_free_item_slot__15TWindowMainMenuFPv(Obj_802ADC04 *self);
s32 append_child_rows__15TWindowMainMenuFPvi(Menu_802ADD38 *arg0, s32 arg1);
Rect_802AE2B0 * setup_content_frame__15TWindowMainMenuFPv(u8 *arg0);
void begin_screen_draw(s32 arg0);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);

extern UV_802AD538 main_menu_label_uv_table[];
extern RecoveredGlobal_802AE59C_lbl_8050E208 controller_input_state;
extern const f32 lbl_805DE138;
extern const f32 lbl_805DE13C;
extern const f32 lbl_805DE140;
extern const f32 lbl_805DE144;
extern const f32 lbl_805DE148;
extern const f32 lbl_805DE150;
extern const float lbl_805DE158;
extern f32 lbl_805DE15C;
extern f32 lbl_805DE160;
extern f32 lbl_805DE164;
extern const f32 lbl_805DE1A4;
extern f32 lbl_805DE1A8;

void draw_item_labels__15TWindowMainMenuFv(Item_802AD538 *p, Win_802AD538 *w) {
    Rect_802AD538 r;
    f32 scale;
    UV_802AD538 *uv;
    u32 color;
    u32 rgb;
    f32 a;

    if (((TWindowMainMenu *)p)->is_item_active() != 0 && p->x10 > 0) {
        scale = lbl_805DE138 / (lbl_805DE13C + w->x38);
        uv = &main_menu_label_uv_table[p->x11];
        begin_render__20TWindowSubStatusDispFl();
        switch (p->x12) {
        case 0:
            rgb = 0xFFFFFF;
            if (p->x13 & 2) {
                rgb = 0x686868;
            }
            if (p->x10 >= 4) {
                a = lbl_805DE140;
            } else {
                a = p->x10 * lbl_805DE144;
            }
            color = rgb | ((s32)(lbl_805DE148 * a) << 24);
            break;
        case 1:
            TLanguage::set_entry_index(2, 0x4C);
            color = 0xFFFF6121;
            break;
        case 2:
            TLanguage::set_entry_index(2, 0x4C);
            color = 0xFF51EAFF;
            break;
        }
        begin_screen_draw(1);
        set_draw_texture_and_color(2, color);
        r.x0 = w->x3c + p->x8;
        r.y0 = w->x40 + p->xc;
        r.x1 = 98.0f + r.x0;
        r.y1 = 16.0f + r.y0;
        r.u0 = uv->u / 256.0f;
        r.v0 = uv->v / 256.0f;
        r.u1 = (98.0f + uv->u) / 256.0f;
        r.v1 = (16.0f + uv->v) / 256.0f;
        if (try_open__19TWindowKeyBoardSoftFii((s32)w, (s32)&r) != 0) {
            draw_textured_quad_at_depth((f32 *)&r, scale);
        }
        TWindowSubStatusDisp::get_player();
        TLanguage::set_entry_index(2, 0x4B);
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TWindowMainMenu::is_item_active() { return *(u8*)((char*)this + 0x13) & 0x1; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TWindowMainMenu__sub_802AD74C(void* p) { *(u8*)((char*)p + 0x13) |= 0x2; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TWindowMainMenu::set_symbol_chat_parts(void * _w1) { copy_vec2__28TWindowSubSymbolChatPartsSetFPv(this, _w1); *(unsigned char *)&this->m_down = 8; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void init_row_entry__15TWindowMainMenuFPvicc(u8 *window_sub_symbol_chat_parts_set, s32 arg1, s8 arg2, s8 arg3) {
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv((void *)window_sub_symbol_chat_parts_set, (void *)arg1);
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv(window_sub_symbol_chat_parts_set + 8, (void *)arg1);
    *(s8 *)((s8 *)window_sub_symbol_chat_parts_set + 0x10) = arg3;
    *(s8 *)((s8 *)window_sub_symbol_chat_parts_set + 0x11) = arg2;
    *(s8 *)((s8 *)window_sub_symbol_chat_parts_set + 0x12) = 0;
    *(u8 *)((s8 *)window_sub_symbol_chat_parts_set + 0x13) = (u8) (*(u8 *)((s8 *)window_sub_symbol_chat_parts_set + 0x13) | 1);
}
#pragma pop

void TWindowMainMenu::update_item_tween() {
    Item_802AD7F0 *p = (Item_802AD7F0 *)this;
    if (is_item_active() != 0) {
        if (p->x14 <= 0) {
            p->x8 = p->x0;
            p->xc = p->x4;
        } else {
            p->x8 += (p->x0 - p->x8) / p->x14;
            p->xc += (p->x4 - p->xc) / p->x14;
            p->x14--;
        }
        if (p->x10 < 4) {
            p->x10++;
        }
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TWindowMainMenu::init_color() {
  int new_var;
  char *new_var2;
  *((float *) (((char *) this) + 0xc)) = (*((float *) (((char *) this) + 0x8)) = (*((float *) (((char *) this) + 0x4)) = (*((float *) (((char *) this) + 0x0)) = lbl_805DE158)));
  new_var2 = (char *) this;
  *((unsigned char *) (new_var2 + 0x10)) = 0;
  *((unsigned char *) (new_var2 + 0x11)) = -((double) 1);
  *((unsigned char *) (new_var2 + 0x12)) = 0;
  new_var = 0x13;
  *((unsigned char *) (new_var2 + new_var)) = 0;
  *((unsigned char *) (new_var2 + 0x14)) = 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TWindowMainMenu::pop_level() {
    MM_802AD90C *arg0 = (MM_802AD90C *)this;
    s32 i;
    arg0->cnt--;
    arg0->flags |= 8;
    for (i = 0; i < 8; i++) {
        if (arg0->slots[i] != 0) {
            ((TWindowMainMenu *)(arg0->slots[i]))->init_color();
            arg0->slots[i] = 0;
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void park_selection__15TWindowMainMenuFPv(Menu_802AD980 *arg0) {
    Col_802ADA48 buf;
    u8 sp8[8];
    s32 i;
    Col_802ADA48 *slot;
    copy_color_entry__15TWindowMainMenuFPvPv(&buf, arg0->slots[arg0->cur]);
    for (i = 0; i < 8; i++) {
        if (arg0->slots[i] != NULL) {
            ((TWindowMainMenu *)(arg0->slots[i]))->init_color();
            arg0->slots[i] = NULL;
        }
    }
    ((s32 (*)(void *, void *, s32))get_row_position__15TWindowMainMenuFiPvi)(arg0, sp8, arg0->count);
    slot = (Col_802ADA48 *)((TWindowMainMenu *)arg0)->find_free_slot();
    copy_color_entry__15TWindowMainMenuFPvPv(slot, &buf);
    ((TWindowMainMenu *)slot)->set_symbol_chat_parts(sp8);
    ((u8 *)slot)[0x12] = 2;
    arg0->flags |= 4;
    arg0->count++;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void copy_color_entry__15TWindowMainMenuFPvPv(Col_802ADA48 *arg0, Col_802ADA48 *arg1) {
    arg0->h = arg1->h;
    arg0->b0 = arg1->b0;
    arg0->b1 = arg1->b1;
    arg0->b2 = arg1->b2;
    arg0->b3 = arg1->b3;
    arg0->b4 = arg1->b4;
    arg0->b5 = arg1->b5;
    arg0->b6 = arg1->b6;
    arg0->b7 = arg1->b7;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TWindowMainMenu::get_selected_item_type() {
    Obj_802ADAAC *self = (Obj_802ADAAC *)this;
    Item_802ADAAC *p = self->items[self->idx];
    if (p == 0) return 0x1f;
    return p->f11;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TWindowMainMenu__sub_802ADADC(Obj_802ADADC *self, s8 i) {
    self->idx = i;
    self->items[self->idx]->f12 = 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TWindowMainMenu__sub_802ADB00(u8 *arg0) {
  long long new_var;
  return new_var = (s8) ((*((u8 *) (((s8 *) arg0) + 0x61))) & 0xFFFFFFFFFFFFFFFFu);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TWindowMainMenu::clear_menu_flags() { *(u8*)((char*)this + 0x60) &= 0xfc; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TWindowMenuMainMenu::is_flag_set() { return (this->m_60 >> 1) & 0x1; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TWindowMenuMainMenu::get_menu_flag() { return this->m_60 & 0x1; }
#pragma pop

#pragma push
#pragma fp_contract on
u8 *find_active_item_by_id__15TWindowMainMenuFii(s32 arg0, s32 arg1) {
    s32 var_r31;
    u8 *var_r30;
    s32 var_r29;
    var_r29 = arg1;
    if (var_r29 == 0x1B) {
        var_r29 = 0x1A;
    }
    var_r30 = (u8 *)(arg0 + 0x64);
    var_r31 = 0;
loop_3:
    if ((((TWindowMainMenu *)var_r30)->is_item_active() != 0) && ((s8) *(u8 *)((s8 *)var_r30 + 0x11) == var_r29)) {
        return var_r30;
    }
    var_r31 += 1;
    var_r30 += 0x18;
    if (var_r31 >= 8) {
        return NULL;
    }
    goto loop_3;
}
#pragma pop

s32 TWindowMainMenu::find_free_slot() {
    s32 arg0 = (s32)this;
    s32 counter;
    s32 ptr;

    ptr = arg0 + 0x64;
    counter = 0;
loop_1:
    if (((TWindowMainMenu *)ptr)->is_item_active() == 0) {
        return ptr;
    }
    counter += 1;
    ptr += 0x18;
    if (counter >= 8) {
        return 0;
    }
    goto loop_1;
}

int find_free_item_slot__15TWindowMainMenuFPv(Obj_802ADC04 *self) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (self->items[i] == 0) return i;
    }
    return 8;
}

s32 count_active_items__15TWindowMainMenuFi(s32 arg0) {
    s32 counter;
    s32 ptr;

    ptr = arg0 + 0x64;
    counter = 0;
loop_1:
    if (((TWindowMainMenu *)ptr)->is_item_active() == 0) {
        return counter;
    }
    counter += 1;
    ptr += 0x18;
    if (counter >= 8) {
        return 8;
    }
    goto loop_1;
}

void get_row_position__15TWindowMainMenuFiPvi(s32 arg0, void *arg1, s32 arg2) {
    *(f32 *)((s8 *)arg1 + 0) = (f32) lbl_805DE158;
    *(f32 *)((s8 *)arg1 + 4) = (f32) (lbl_805DE150 * (f32) arg2);
}

s32 is_not_split_screen__15TWindowMainMenuFv(void) {
    return (u32)__cntlzw(is_split_screen()) >> 5;
}

s32 TWindowMainMenu::update_if_active(s32 _w1) {
    Menu_802ADD38 *_w0 = (Menu_802ADD38 *)this;
    s32 temp_r3;

    temp_r3 = append_child_rows__15TWindowMainMenuFPvi((Menu_802ADD38 *)(_w0), _w1);
    if (temp_r3 != 0) {
        ((s32 (*)(void))TWindowMainMenu__sub_802AD74C)();
    }
    return temp_r3;
}

s32 append_child_rows__15TWindowMainMenuFPvi(Menu_802ADD38 *arg0, s32 arg1) {
    u8 sp8[8];
    s32 n;
    s32 slot;
    n = ((s32 (*)(void))find_free_item_slot__15TWindowMainMenuFPv)();
    if (n >= 8) {
        return 0;
    }
    ((s32 (*)(void *, void *, s32))get_row_position__15TWindowMainMenuFiPvi)(arg0, sp8, n + arg0->count);
    slot = ((s32 (*)(void *, s32))find_active_item_by_id__15TWindowMainMenuFii)(arg0, arg1);
    if (slot == 0) {
        slot = ((TWindowMainMenu *)arg0)->find_free_slot();
        if (slot == 0) {
            return 0;
        }
        ((s32 (*)(s32, void *, s8, s8))init_row_entry__15TWindowMainMenuFPvicc)(slot, sp8, arg1, -(n * 2));
    } else {
        ((TWindowMainMenu *)slot)->set_symbol_chat_parts(sp8);
    }
    arg0->slots[n] = slot;
    arg0->flags &= ~4;
    return slot;
}

void TWindowMainMenu::set_target_y(f32 farg0) {
    if (is_not_split_screen__15TWindowMainMenuFv() != 0) {
        farg0 += lbl_805DE15C;
    } else {
        farg0 += lbl_805DE160;
    }
    farg0 += lbl_805DE164;
    if (*(f32 *)&this->_pad58 != farg0) {
        *(f32 *)&this->_pad58 = farg0;
        *(s32 *)((s8 *)this + 0x50) = 8;
    }
}

void TWindowMainMenu::update_scaled_position() {
    s32 arg0 = (s32)this;
    set_target_y(lbl_805DE150 * (f32) ((s32 (*)())count_active_items__15TWindowMainMenuFi)());
}

void TWindowMainMenu::draw_entries_reversed(u8 *arg1) {
    s32 arg0 = (s32)this;
    s32 var_r31;
    u8 *var_r30;
    var_r30 = (u8 *)(arg0 + 0x10C);
    var_r31 = 0;
    do {
        ((void (*)(void *, void *))draw_item_labels__15TWindowMainMenuFv)(var_r30, arg1);
        var_r31 += 1;
        var_r30 -= 0x18;
    } while (var_r31 < 8);
}

Rect_802AE2B0 *setup_content_frame__15TWindowMainMenuFPv(u8 *window_menu_main_menu) {
    f32 v;
    Rect_802AE2B0 *r;
    r = open_singleton__19TWindowKeyBoardSoftFiiii(window_menu_main_menu + 0x40, window_menu_main_menu + 0x48, fn_8026CB68(), ((TWindowMenuMainMenu *)window_menu_main_menu)->m_54, ((TWindowMenuMainMenu *)window_menu_main_menu)->m_2c);
    if (((s32 (*)(void *))is_not_split_screen__15TWindowMainMenuFv)(window_menu_main_menu) != 0) {
        v = lbl_805DE15C;
    } else {
        v = lbl_805DE164;
    }
    ((TWindowKeyBoardSoft *)r)->set_bounds(lbl_805DE1A4 + r->x, r->y + v, (r->x + r->w) - lbl_805DE1A4, (r->y + r->h) - lbl_805DE164);
    r->color = ((s32)(lbl_805DE148 * TWindowSubComCard__sub_80244784((TWindowSubComCard *)window_menu_main_menu)) << 24) | 0xFF0000 | 0xFFFF;
    return r;
}

void TWindowMainMenu::update_slide_position() {
    if (sub_80246948__11TWindowBaseFv() != 0) {
        set_target_y(lbl_805DE158);
        *(u32 *)((s8 *)this + 0x50) = (u32) (lbl_805DE1A8 - (f32) (*(s16 *)((s8 *)this + 0x22)));
        return;
    }
    update_scaled_position();
}

void TWindowMenuMainMenu::handle_cancel() {
    play_sound_effect(0x52F16, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 2);
}

void TWindowMenuMainMenu::handle_confirm() {
    u8 *arg0 = (u8 *)this;
  char new_var;
  u8 *new_var2;
  int new_var3;
  u8 *temp_r3;
  new_var2 = arg0;
  new_var2 = new_var2 + (((s8)this->m_61) * 4);
  temp_r3 = (unsigned char *) (*((void **) (((s8 *) new_var2) + 0x124)));
  if (temp_r3 != 0)
  {
    new_var = 0;
    if ((*((u8 *) (((s8 *) temp_r3) + 0x13))) & 2)
    {
      play_sound_effect(0x53F06, 0, 0, 0);
      return;
    }
    new_var3 = 0x52D01;
    play_sound_effect((s32)new_var3, 0, 0, (s32)new_var);
    this->m_60 = (u8) ((this->m_60) | 1);
  }
}

struct Obj_802ADC04;
void play_cursor_sound__15TWindowMainMenuFv(Menu_802AE4DC *m, int d) {
    int n;
    play_sound_effect(0x54100, 0, 0, 0);
    m->items[m->cur]->sel = 0;
    n = find_free_item_slot__15TWindowMainMenuFPv((Obj_802ADC04 *)m);
    m->cur += d;
    if (m->cur < 0) {
        m->cur = n - 1;
    }
    if (m->cur > n - 1) {
        m->cur = 0;
    }
    m->items[m->cur]->sel = 1;
}

void TWindowMenuMainMenu::handle_navigation_input() {
    u8 *window_choice_setting;
    if ((is_window_reveal_complete__11TWindowBaseFv() != 0) && (this->get_menu_flag() == 0) && (this->is_flag_set() == 0) && !(this->m_60 & 4)) {
        window_choice_setting = (u8 *)&controller_input_state.value + (is_player_input_active((*(s16 *)&this->m_20)) * 0x50) + 0x20;
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x10, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&controller_input_state.value + 0x160), 0x10, 6, 1) != 0)) {
            play_cursor_sound__15TWindowMainMenuFv((Menu_802AE4DC *)(this), -1);
        }
        if ((apply_choice__20TWindowChoiceSettingFllll(window_choice_setting, 0x20, 6, 1) != 0) || (apply_choice__20TWindowChoiceSettingFllll((void *) ((u8 *)&controller_input_state.value + 0x160), 0x20, 6, 1) != 0)) {
            play_cursor_sound__15TWindowMainMenuFv((Menu_802AE4DC *)(this), 1);
        }
        if ((TWindowShortListCtrl__check_controller_button((int)window_choice_setting, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            this->handle_confirm();
        }
        if ((this->get_menu_flag() == 0) && ((TWindowShortListCtrl__check_controller_button((int)window_choice_setting, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0))) {
            this->handle_cancel();
        }
    }
}

}
