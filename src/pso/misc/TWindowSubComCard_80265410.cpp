#include "types.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowAddition.h"
#include <stddef.h>
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowDuelResult.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern const f32 lbl_805DD160;
extern "C" {
s32 get_selected_entry__11TWindowMenuFv(u8 *arg0);
struct Stack_80265500 {
    f32 sp8;
    f32 spC;
};

struct Stack_80265484 {
    f32 sp8;
    f32 spC;
};

struct Stack_8026556C {
    f32 sp8;
    f32 spC;
};

struct E_80265660 { u32 flags; u32 b; };

struct Obj_80265660 { u8 pad[0x80]; E_80265660 *entries; };

struct Rec_802655E4 { s32 a; s32 b; };

struct Win_802655E4 { u8 p0[0x72]; s16 f72; s16 f74; s16 f76; u8 p78[8]; Rec_802655E4 *f80; };

struct Rec_802656D8 { u32 flags; s32 b; };

struct Ent_802656D8 { u8 p0[0x24]; s32 f24; };

struct Win_802656D8 { u8 p0[0x80]; Rec_802656D8 *f80; };

struct Stack_80265A38 {
    f32 sp8;
    f32 spC;
};

struct E_80265BF8 { u32 a; u32 b; };

struct Obj_80265BF8 { u8 pad[0x78]; s16 f78; u8 pad2[6]; E_80265BF8 *entries; };

struct Win_80265C30 { u8 pad[0x38]; f32 x; u8 pad3c[0x3a]; s16 count; };

struct Ent_80265C30 { u8 pad[0x8]; f32 x; u8 padc[4]; f32 w; f32 h; };

struct Win_80265E60 { u8 pad[0x2c]; u32 flags; u8 pad30[8]; f32 x; f32 y; u8 pad40[0x36]; s16 count; u8 pad78[4]; f32 height; };

struct Ent_80265E60 { u8 pad[0x14]; f32 h; };

struct Ent_80265F60 { u8 pad[0x10]; f32 w; f32 h; };

struct Win_80265F60 { u8 pad[0x2C]; u32 flags; u8 pad30[8]; f32 x; f32 y; u8 pad40[0x36]; s16 count; u8 pad78[4]; f32 height; };

struct Ent_80265AA4 { u32 flags; u32 x; };

struct Card_80265AA4 {
    u8 pad0[0x74];
    s16 cur;
    s16 cnt;
    u8 pad1[8];
    Ent_80265AA4 *ents;
};

struct Ent_80265C30;

struct RecoveredGlobal_80266378_lbl_804D05A8 {
    s32 value;
    u8 remaining[0x20];
};

typedef char RecoveredGlobal_80266378_lbl_804D05A8_size[sizeof(RecoveredGlobal_80266378_lbl_804D05A8) == 0x24 ? 1 : -1];

struct RecoveredGlobal_80266B30_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

typedef char RecoveredGlobal_80266B30_lbl_8050E208_size[sizeof(RecoveredGlobal_80266B30_lbl_8050E208) == 0x1B0 ? 1 : -1];

void mem_free(void *);
void *mem_alloc(u32 size);
s32 TWindowShortListCtrl__check_controller_button(int, int);
Ent_80265C30 * get_array_entry__11TWindowBaseFi(void *w, s32 i);
s32 play_sound_effect(s32, s32, s32, s32);
void __dl__7TObjectFPv(void *);
s32 __nw__7TObjectFUl(int);
s32 get_draw_context__11TWindowBaseFPv();
s32 construct_with_parent__15TWindowAdditionFPv(void *, void *, s16, s32);
void * get_field_20__17TWindowSubComCardFv(void *e);
void refresh_status_display__9TWindowDDFv(void *);
void TWindowChat__sub_80247D2C(void *p);
s32 is_window_display_enabled();
s32 draw_visible_window_entries(void *, void *, s32);
void measure_message_text_width(Ent_80265C30 *e, f32 x);
void TWindowSubComCard__sub_80265500(u8 *arg0);
s32 TWindowSubComCard__sub_80265660(Obj_80265660 *o, s16 i);
void TWindowSubComCard__sub_80265680(u8 *arg0, s16 arg1);
void align_menu_entry_positions(Win_80265C30 *self);
void layout_entries__11TWindowMenuFv(u8 *arg0);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void* p, int a1, int a2, int a3);
void fn_80266378(s32 arg0);
u8 * create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
u8 * init_shop_judgment_window(void* p);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
void render__11TWindowMenuFv(TWindowMenu *arg0);
void * __dt__11TWindowMenuFv(void *arg0, s16 arg1);
u8 * TWindowMenu__ct(u8 *arg0, u32 arg1, s32 arg2, s32 arg3);
u8 test_menu_flag__11TWindowMenuFv(u8 *arg0);
s32 clamp_list_scroll_offset(int, void *, void *);
s32 draw_window_scrollbar(s32, s32, void *);
u32 reset_selection__20TWindowSubStatusDispFv(int, void *);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);
s32 construct_type1_heading__20TWindowSubStatusDispFll(s32, s32, s32);
}
void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2);
void update_chat_window(void* p);
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 __vt__11TWindowMenu[];
extern const f64 lbl_8044F330;
extern RecoveredGlobal_80266378_lbl_804D05A8 lbl_804D05A8;
extern u8 lbl_804D05CC[];
extern s8 controller_input_state[];
extern s32 lbl_805D3960;
extern s32 actor_frame_tick;
extern const f32 lbl_805DD148;
extern const f32 lbl_805DD14C;
extern const f32 lbl_805DD154;
extern const f32 lbl_805DD158;
extern const f32 lbl_805DD15C;
extern const f32 lbl_805DD164;
extern const f32 lbl_805DD168;
extern const f32 lbl_805DD16C;
extern const f32 lbl_805DD170;
extern const f32 lbl_805DD174;
extern const f32 lbl_805DD178;

void update_chat_window(void* p) { void* m = *(void**)((char*)p + 0x20); if (m) TWindowChat__sub_80247D2C(m); }

int TWindowSubComCard::get_flag() { return (*(u16*)((char*)this + 0x70) >> 2) & 0x1; }

void TWindowSubComCard::clear_flag_and_release2() {
    *(u16 *)((s8 *)this + 0x70) = (u16) (*(u16 *)((s8 *)this + 0x70) & 0xFFFFFFFD);
    if ((u32) this->m_78 != 0U) {
        ((TWindowSubStatusDisp *)(this->m_78))->set_entry_state(1);
    }
}

void TWindowSubComCardList::update_scroll_target_position() {
    Stack_80265484 stack;
    u8 *window_menu;
    window_menu = (u8 *)(*(u8 * *)&this->m_84);
    if (window_menu != NULL) {
        stack.sp8 = ((this->m_48) - lbl_805DD148) - lbl_805DD14C;
        stack.spC = (f32) ((*(s16 *)&this->m_72 * 0x14) - 2);
        ((TWindowMenu *)window_menu)->copy_position(&stack.sp8);
    }
}

void TWindowSubComCard__sub_80265500(u8 *arg0) {
    Stack_80265500 stack;
    f32 temp_f1;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x84) != 0U) {
        stack.sp8 = 0.0f;
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x4C) - lbl_805DD154;
        stack.spC = temp_f1;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x88) != 0U) {
            stack.spC = temp_f1 - lbl_805DD158;
        }
        clamp_list_scroll_offset((int) (*(u32 *)((s8 *)arg0 + 0x84)), arg0 + 0x68, &stack.sp8);
    }
}

void TWindowSubComCardList::sub_8026556C() {
    typedef char sp8_offset[(offsetof(Stack_8026556C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8026556C, spC) == 0x4) ? 1 : -1];
    Stack_8026556C stack;
    f32 temp_f1;
    f32 temp_f2;
    u32 temp_r3;
    u32 var_r0;
    if ((u32) this->m_84 == 0U) {
        temp_f2 = this->m_38;
        temp_f1 = temp_f2 - lbl_805DD15C;
        stack.spC = 0.0f;
        stack.sp8 = temp_f1;
        temp_r3 = ((u32 (*)(u32, f32, f32))(void *(*)(size_t))::operator new)(0xC, temp_f1, temp_f2);
        var_r0 = temp_r3;
        if (var_r0 != 0U) {
            var_r0 = reset_selection__20TWindowSubStatusDispFv(temp_r3, &stack.sp8);
        }
        this->m_84 = var_r0;
        this->m_2c = (s32) (this->m_2c | 0x80);
    }
}

void TWindowSubComCardList::reset_entries() {
    s32 i;
    Rec_802655E4 *r;
    void *e;
    ((Win_802655E4 *)this)->f72 = 0;
    ((Win_802655E4 *)this)->f74 = 0;
    r = ((Win_802655E4 *)this)->f80;
    for (i = 0; i < ((Win_802655E4 *)this)->f76; i++, r++) {
        e = ((void *)((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i));
        TWindowDuelResult::set_default_status(e, 0);
        refresh_status_display__9TWindowDDFv(e);
        r->a = 0;
        r->b = 0;
    }
}

s32 TWindowSubComCard__sub_80265660(Obj_80265660 *o, s16 i) {
    if (o->entries[i].flags & 0x10) return 0;
    return 1;
}

void TWindowSubComCard__sub_80265680(u8 *arg0, s16 arg1) {
  s32 *new_var;
  s16 var_r31;
  s16 var_r4;
  s32 temp_r3;
  s32 var_r3;
  s32 var_r5;
  u8 *var_r30;
  var_r31 = arg1;
  var_r30 = (u8 *) arg0;
  var_r4 = var_r31;
  temp_r3 = ((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(arg0, (s32)((s32) var_r4));
  var_r4 = 0xFF910000;
  var_r5 = *((s32 *) (((s8 *) var_r30) + 0x80));
  var_r4 = var_r31;
  new_var = (s32 *) (((s8 *) var_r5) + (var_r4 * 8));
  *((s32 *) (((s8 *) temp_r3) + 0x24)) = 0xFF909090;
  ;
  *new_var = (*new_var) | 0x10;
}

void TWindowSubComCard::set_entry_value_clear_flag(s32 idx, s32 val) {
    Win_802656D8 *w = (Win_802656D8 *)this;
    Ent_802656D8 *e = ((Ent_802656D8 *(*)(void *, s16))get_array_entry__11TWindowBaseFi)(w, idx);
    Rec_802656D8 *r = w->f80;
    e->f24 = val;
    r[(s16)idx].flags &= ~0x10;
}

s32 TWindowMenu::get_selected_entry() {
    s16 temp_r4;
    temp_r4 = *(s16 *)&this->m_78;
    if (temp_r4 < 0) {
        return 0;
    }
    if (temp_r4 >= (s16) *(s16 *)&this->m_76) {
        return 0;
    }
    return ((s32 (*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, (s32)((s32) temp_r4));
}

void TWindowMenu::set_active_flag() {
    if (!(this->m_70 & 8) && (is_decided() == 0)) {
        if (!(this->m_70 & 0x400)) {
            play_sound_effect(0x52F16, 0, 0, 0);
        }
        this->m_70 = (u16) (this->m_70 | 4);
    }
}

void TWindowMenu::confirm_selection() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    u8 *window_sub_status_disp;
    if (((int)((TWindowMenu *)arg0)->is_decided()) == 0) {
        temp_r3 = *(s32 *)((s8 *)(*(s32 *)&this->m_80) + (*(s16 *)&this->m_78 * 8));
        if (temp_r3 & 0x10) {
            if (!(temp_r3 & 0x20)) {
                play_sound_effect(0x53F06, 0, 0, 0);
            }
        } else {
            if (!(temp_r3 & 0x20)) {
                play_sound_effect(0x52D01, 0, 0, 0);
            }
            this->m_70 = (u16) (this->m_70 | 2);
            window_sub_status_disp = (u8 *)(*(u8 * *)&this->m_88);
            if (window_sub_status_disp != NULL) {
                ((TWindowSubStatusDisp *)window_sub_status_disp)->set_entry_state(2);
            }
        }
    }
}

void TWindowMenu::select_next_item() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = *(s16 *)&this->m_78;
loop_1:
    var_r31 += 1;
    if (var_r31 >= (s16) *(s16 *)&this->m_76) {
        if (!(this->m_70 & 1)) {
            var_r31 = 0;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) *(s16 *)&this->m_78) {
            if (sub_80266B18(var_r31) != 0) {
                *(s16 *)&this->m_78 = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}

void TWindowMenu::move_cursor_prev() {
    s16 var_r31;

    play_sound_effect(0x54100, 0, 0, 0);
    var_r31 = *(s16 *)&this->m_78;
loop_1:
    var_r31 -= 1;
    if (var_r31 < 0) {
        if (!(this->m_70 & 1)) {
            var_r31 = *(s16 *)&this->m_76 - 1;
            goto block_4;
        }
    } else {
block_4:
        if (var_r31 != (s16) *(s16 *)&this->m_78) {
            if (sub_80266B18(var_r31) != 0) {
                *(s16 *)&this->m_78 = var_r31;
            } else {
                goto loop_1;
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowMenu::update_target_y() {
    u8 *arg0 = (u8 *)this;
    f32 v;
    f32 t;
    f32 base;
    if (*(u32 *)(arg0 + 0x84) != 0 && *(u32 *)(arg0 + 0x50) == 0) {
        v = lbl_805DD14C + (f32)(*(s16 *)(arg0 + 0x78) * 0x14);
        v -= lbl_805DD160 * (*(f32 *)(arg0 + 0x4C) - lbl_805DD154);
        if (*(u32 *)(arg0 + 0x88) != 0) {
            v -= lbl_805DD164;
        }
        t = *(f32 *)(arg0 + 0x6C);
        *(f32 *)(arg0 + 0x6C) = t + (v - t);
    }
}
#pragma pop

void TWindowMenu::clamp_menu_choice_scroll() {
    Stack_80265A38 stack;
    f32 temp_f1;
    if ((u32) this->m_84 != 0U) {
        stack.sp8 = 0.0f;
        temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x4C) - lbl_805DD154;
        stack.spC = temp_f1;
        if ((u32) this->m_88 != 0U) {
            stack.spC = temp_f1 - lbl_805DD158;
        }
        clamp_list_scroll_offset(this->m_84, (void *) (((u8 *)this) + 0x68), &stack.sp8);
    }
}

void TWindowMenu::advance_past_disabled_menu_rows() {
    u16 *e;
    s16 t;
    if (((Card_80265AA4 *)this)->cur < ((Card_80265AA4 *)this)->cnt) {
        e = ((u16 *)get_array_entry__11TWindowBaseFi((void *)(((Card_80265AA4 *)this)), (s32)(((Card_80265AA4 *)this)->cur)));
        while (((u32)get_field_20__17TWindowSubComCardFv(e)) != 0 && (*e & 0x10)) {
            t = ((Card_80265AA4 *)this)->cur + 1;
            ((Card_80265AA4 *)this)->cur = t;
            if (t >= ((Card_80265AA4 *)this)->cnt) {
                break;
            }
            e = ((u16 *)get_array_entry__11TWindowBaseFi((void *)(((Card_80265AA4 *)this)), (s32)(((Card_80265AA4 *)this)->cur)));
            if (((Card_80265AA4 *)this)->ents[((Card_80265AA4 *)this)->cur].flags & 2) {
                ((Card_80265AA4 *)this)->ents[((Card_80265AA4 *)this)->cur].flags &= ~2;
                *e &= ~8;
            }
        }
    }
}

#pragma fp_contract on
void TWindowMenu::update_scroll_value() {
    u8 *arg0 = (u8 *)this;
  u8 *new_var2;
  f32 v;
  u32 *new_var;
  u32 n;
  new_var = (u32 *)(arg0 + 0x50);
  if ((*((u16 *)(arg0 + 0x70))) & 0x20)
  {
    v = *((f32 *) (get_selected_entry__11TWindowMenuFv(arg0) + 0xC));
  }
  else
  {
    v = 0.0f;
    new_var = (u32 *)(arg0 + 0x50);
  }
  n = *new_var;
  if (n == 0)
  {
    *((f32 *)(arg0 + 0x6C)) = v;
    return;
  }
  v += lbl_805DD160 * ((*((f32 *)(arg0 + 0x3C))) - (*((f32 *)(arg0 + 0x4C))));
  new_var2 = (u8 *)&this->_pad6C;
  *((f32 *) new_var2) += (v - (*((f32 *)(arg0 + 0x6C)))) / ((f32) n);
}

s32 TWindowMenu::get_selected_value() {
    Obj_80265BF8 *o = (Obj_80265BF8 *)this;
    return o->entries[o->f78].b;
}

void TWindowSubComCardList::set_selected_index(s16 arg1) {
    if ((arg1 >= 0) && (arg1 < (s16) *(s16 *)&this->m_76)) {
        *(s16 *)&this->m_78 = arg1;
    }
}

#pragma push
#pragma fp_contract on
void align_menu_entry_positions(Win_80265C30 *self) {
    f32 left = self->x - lbl_805DD15C;
    f32 right = lbl_805DD160 * self->x - lbl_805DD148;
    u32 i;
    for (i = 0; i < self->count; i++) {
        Ent_80265C30 *e = get_array_entry__11TWindowBaseFi(self, i);
        if (get_field_20__17TWindowSubComCardFv(e) != 0) {
            measure_message_text_width(e, left);
            if (e->h > lbl_805DD168) {
                e->x = 0.0f;
            } else {
                e->x = right - lbl_805DD160 * e->w;
            }
        }
    }
}
#pragma pop

void TWindowSubComCard::calc_layout_height(f32 farg0) {
    f32 h;
    u32 i;
    Ent_80265C30 *e;
    h = 0.0f;
    for (i = 0; i < *(s16 *)(((u8 *)this) + 0x76); i++) {
        e = get_array_entry__11TWindowBaseFi(this, i);
        if (get_field_20__17TWindowSubComCardFv(e) != 0 && !(e->h <= lbl_8044F330)) {
            measure_message_text_width(e, farg0);
            h += lbl_805DD16C + e->h;
        }
    }
    h -= lbl_805DD16C;
    if (this->m_2c & 0x40) {
        h += lbl_805DD158;
    }
    this->m_38 = farg0;
    *(f32 *)(((u8 *)this) + 0x3C) = lbl_805DD154 + h;
    *(f32 *)(((u8 *)this) + 0x7C) = h;
    ((TWindowBase *)((u8 *)this))->save_position();
}

void TWindowSubComCardList::set_scroll_target(f32 farg0, f32 farg1) {
    update_layout_height(farg0);
    if (*(f32 *)((s8 *)this + 0x3C) > farg1) {
        sub_8026556C();
    }
    *(f32 *)((s8 *)this + 0x3C) = farg1;
    *(f32 *)&(this->m_7c) = (f32) (farg1 - lbl_805DD154);
    save_position();
    update_scroll_target_position();
}

void TWindowSubComCardList::update_layout_height(f32 x) {
    f32 sum = 0.0f;
    u32 i;
    for (i = 0; i < ((Win_80265E60 *)this)->count; i++) {
        Ent_80265E60 *e = ((Ent_80265E60 *)get_array_entry__11TWindowBaseFi(this, i));
        if (get_field_20__17TWindowSubComCardFv(e) != 0) {
            if (!(e->h <= lbl_8044F330)) {
                sum += lbl_805DD16C + e->h;
            }
        }
    }
    sum -= lbl_805DD16C;
    if (((Win_80265E60 *)this)->flags & 0x40) {
        sum += lbl_805DD158;
    }
    ((Win_80265E60 *)this)->x = x;
    ((Win_80265E60 *)this)->y = lbl_805DD154 + sum;
    ((Win_80265E60 *)this)->height = sum;
    save_position();
}

void TWindowSubComCard::calc_window_size() {
    f32 width = 0.0f;
    f32 sum = width;
    u32 i;
    for (i = 0; i < ((Win_80265F60 *)this)->count; i++) {
        Ent_80265F60 *e = (Ent_80265F60 *)get_array_entry__11TWindowBaseFi(this, i);
        if (get_field_20__17TWindowSubComCardFv(e) != 0) {
            if (e->w > width) {
                width = e->w;
            }
            if (!(e->h <= lbl_8044F330)) {
                sum += lbl_805DD16C + e->h;
            }
        }
    }
    sum -= lbl_805DD16C;
    ((Win_80265F60 *)this)->height = sum;
    if (((Win_80265F60 *)this)->flags & 0x40) {
        sum += lbl_805DD158;
    }
    ((Win_80265F60 *)this)->x = lbl_805DD15C + width;
    ((Win_80265F60 *)this)->y = lbl_805DD154 + sum;
    ((TWindowBase *)((Win_80265F60 *)this))->save_position();
}

void TWindowMenu::layout_entries() {
    f32 gap;
    f64 zero;
    f32 y;
    u32 i;
    u8 *e;
    f32 h;
    y = 0.0f;
    gap = lbl_805DD16C;
    zero = lbl_8044F330;
    for (i = 0; i < *(s16 *)&this->m_76; i++) {
        e = (u8 *)get_array_entry__11TWindowBaseFi(this, i);
        if (((u32 (*)(void))get_field_20__17TWindowSubComCardFv)() != 0) {
            *(f32 *)(e + 0xC) = y;
            h = *(f32 *)(e + 0x14);
            if (!(h <= zero)) {
                y += gap + h;
            }
        }
    }
}

void TWindowSubComCard::clear_transition_flag() {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x70);
    if (temp_r4 & 0x20) {
        *(u16 *)((s8 *)this + 0x70) = (u16) (temp_r4 & 0xFFFFFFDF);
        *(f32 *)&this->unk_3C = (f32) (lbl_805DD154 + *(f32 *)&this->m_7c);
        this->m_50 = 3;
    }
}

void TWindowOptionCtrl::open() {
    u16 temp_r4;
    void *temp_r3;
    f32 temp_f1;

    temp_r4 = *(u16 *)((s8 *)this + 0x70);
    if (!(temp_r4 & 0x20)) {
        *(u16 *)((s8 *)this + 0x70) = (u16) (temp_r4 | 0x20);
        temp_r3 = ((void * (*)(void *))get_selected_entry__11TWindowMenuFv)(this);
        temp_f1 = lbl_805DD154;
        *(f32 *)&this->m_3c = (f32) (temp_f1 + *(f32 *)((s8 *)temp_r3 + 0x14));
        if (*(s32 *)&this->m_2c & 0x40) {
            *(f32 *)&this->m_3c = (f32) (*(f32 *)&this->m_3c + lbl_805DD158);
        }
        *(s32 *)((s8 *)this + 0x50) = 3;
    }
}

void TWindowSubComCard::draw_text_gray(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((TWindowSubTradeMain *)arg0)->add_text_entry(arg1, arg2 | 0x10, arg3, 0xFF909090);
}

s32 TWindowSubTradeMain::add_text_entry(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *arg0 = (u8 *)this;
    s16 temp_r7;
    u8 *window_help_item;
    u8 *temp_r30;

    if ((s16) *(s16 *)&this->unk_72 >= (s16) *(s16 *)((s8 *)arg0 + 0x76)) {
        return 0;
    }
    window_help_item = ((u8 * (*)(void *, s16))get_array_entry__11TWindowBaseFi)(arg0, *(s16 *)&this->unk_72);
    temp_r7 = *(s16 *)&this->unk_72;
    temp_r30 = (unsigned char *) (*(s32 *)&this->m_80 + (temp_r7 * 8));
    *(f32 *)((s8 *)window_help_item + 0xC) = (f32) (temp_r7 * 0x14);
    *(s32 *)((s8 *)window_help_item + 0x24) = arg4;
    if (arg2 & 1) {
        set_text_entry_string(window_help_item, (arg1), 0x20);
    } else {
        set_text_entry_string(window_help_item, (arg1), 0);
    }
    if (arg2 & 4) {
        *(u16 *)((s8 *)window_help_item + 0) = (u16) (*(u16 *)((s8 *)window_help_item + 0) | 1);
    }
    if (arg2 & 8) {
        *(u16 *)((s8 *)window_help_item + 0) = (u16) (*(u16 *)((s8 *)window_help_item + 0) | 0x40);
    }
    if (arg2 & 0x40) {
        *(u16 *)((s8 *)window_help_item + 0) = (u16) (*(u16 *)((s8 *)window_help_item + 0) | 0x200);
    }
    if (arg2 & 2) {
        if ((s16) *(s16 *)&this->unk_72 == (s16) this->m_74) {
            arg2 &= 0xFFFFFFFD;
        } else {
            *(u16 *)((s8 *)window_help_item + 0) = (u16) (*(u16 *)((s8 *)window_help_item + 0) | 8);
        }
    }
    if (this->m_70 & 0x100) {
        ((TWindowHelpItem *)window_help_item)->reset_float_field();
    }
    ((s32 (*)(int))refresh_status_display__9TWindowDDFv)((int)window_help_item);
    *(s32 *)((s8 *)temp_r30 + 0) = arg2;
    *(s32 *)((s8 *)temp_r30 + 4) = arg3;
    *(s16 *)&this->unk_72 = (s16) (*(s16 *)&this->unk_72 + 1);
    return 1;
}

int forward_trade_action_default__16TObjCityMainWarpFPviii(void* p, int a1, int a2, int a3) { return ((TWindowSubTradeMain *)p)->add_text_entry(a1, a2, a3, -1); }

void fn_80266378(s32 arg0) {
    *(s32 *)((s8 *)&lbl_804D05A8.value + 4) = arg0;
}

u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3) {
  u8 *temp_r31;
  u8 *window_menu;
  window_menu = (u8 *) ((u8 *)create_window_menu(arg0, 2, arg1));
  temp_r31 = (u8 *) window_menu;
  if (arg2 == 0U)
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((int) ((u8 *) window_menu), (void *) TWindowSubStatusDisp::get_message_10(0x5B), 6, 0);
  }
  else
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((int) window_menu, (void *) arg2, 6, 0);
  }
  if (0U == arg3)
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((int) ((u8 *) window_menu), (void *) TWindowSubStatusDisp::get_message_10(0x5C), 6, 1);
  }
  else
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((int) ((u8 *) window_menu), (void *) arg3, 6, 1);
  }
  ((TWindowSubComCard *)window_menu)->calc_window_size();
  if ((*((f32 *) (((s8 *) ((u8 *) window_menu)) + 0x48))) < lbl_805DD170)
  {
    ((TWindowSubComCardList *)window_menu)->update_layout_height((f32) lbl_805DD170);
  }
  ((s32 (*)(int))align_menu_entry_positions)((int) ((u8 *) window_menu));
  ((TCheckRoomSequence *)window_menu)->set_ready_flag();
  ((TWindowBase *)window_menu)->set_depth((f32) lbl_805DD174);
  return (u8 *) window_menu;
}

u8 * init_shop_judgment_window(void* p) { return create_yes_no_window((s32)p, 4, (u32)(0), (u32)(0)); }

s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 var_r0;
    ((s32 (*)(void *))fn_80266378)((void *)arg1);
    temp_r3 = __nw__7TObjectFUl(0x8C);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = ((s32 (*)(int, void *, void *, void *))TWindowMenu__ct)((int)temp_r3, (void *)arg1, (void *)arg2, (void *)arg0);
    }
    return var_r0;
}

void TAdChrSelASlotGC::check_room_seq_4(s32 arg1) {
    s32 arg0 = (s32)this;
    ((int (*)(void*, void*, void*))create_window_menu)((void*)arg0, (void*)arg1, (void*)(4));
}

s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r31;
    s32 temp_r3;
    s32 var_r0;
    temp_r31 = ((s32)((int (*)(void*, void*, void*))create_window_menu)((void*)arg0, (void*)arg1, (void*)arg3));
    temp_r3 = ((int (*)(void *))::operator new)((void *)0x24);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = construct_type1_heading__20TWindowSubStatusDispFll(temp_r3, arg2, arg3);
    }
    *(s32 *)((s8 *)temp_r31 + 0x88) = var_r0;
    *(s32 *)((s8 *)temp_r31 + 0x2C) = (s32) (*(s32 *)((s8 *)temp_r31 + 0x2C) | 0x40);
    return temp_r31;
}

void TWindowSubComCard::draw_card_icon(s32 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    ((int (*)(void*, void*, void*, void*))create_titled_window_menu)((void*)arg0, (void*)arg1, (void*)arg2, (void*)(4));
}

void TWindowMenu::draw_selected_bar(u8 *window_key_board_soft) {
    s16 temp_r4;
    u16 *temp_r3;
    if (!(actor_frame_tick & 0x10)) {
        temp_r4 = *(s16 *)&this->unk_7A;
        if (temp_r4 >= 0) {
            temp_r3 = (u16 *)(((s32)((u16 * (*)(void *, int))get_array_entry__11TWindowBaseFi)(this, (s32) temp_r4)));
            if (*temp_r3 & 1) {
                draw_selection_bar((window_key_board_soft), (u8 *)temp_r3, 1);
            }
        }
    }
}

void TWindowMenu::render_selected_entry(s32 window_key_board_soft) {
    u16 *temp_r3;

    temp_r3 = ((u16 * (*)(void *, int))get_array_entry__11TWindowBaseFi)(this, *(s16 *)&this->m_78);
    if (*temp_r3 & 1) {
        draw_selection_bar((u8 *)window_key_board_soft, (u8 *)temp_r3, is_decided());
    }
}

void render__11TWindowMenuFv(TWindowMenu *arg0) {
    s32 window_key_board_soft;

    window_key_board_soft = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)window_key_board_soft);
    draw_visible_window_entries(arg0, (u8 *)arg0 + 0x24, window_key_board_soft);
    if (!(arg0->m_70 & 0x80)) {
        arg0->render_selected_entry(window_key_board_soft);
        arg0->draw_selected_bar((u8 *)window_key_board_soft);
    }
    if ((u32) arg0->m_88 != 0U) {
        forward_render__20TWindowSubStatusDispFv(arg0->m_88, window_key_board_soft);
    }
    if ((u32) arg0->m_84 != 0U) {
        draw_window_scrollbar(arg0->m_84, window_key_board_soft, (u8 *)arg0 + 0x68);
    }
}

void TWindowMenu::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    u8 *input;
    u8 *temp_r29_2;
    u8 *temp_r29_3;

    ((s32 (*)(void))layout_entries__11TWindowMenuFv)();
    if (!(*(s32 *)&this->m_2c & 2)) {
        *(s32 *)&this->m_5c = 0x01000000;
    }
    if ((((TWindowMenu *)arg0)->sub_80266BB8() == 0) && (((TWindowMenu *)arg0)->is_decided() == 0) && ((s32) *(s32 *)&this->m_5c > 2) && (is_window_display_enabled() != 0) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        temp_r30 = is_player_input_active((this->m_20));
        if (this->m_70 & 0x10) {
            input = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        } else {
            temp_r29_2 = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        }
        temp_r29_3 = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 4) != 0) || (((s32 (*)(void *, int))test_menu_flag__11TWindowMenuFv)((void *)arg0, 4) != 0)) {
            confirm_selection();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 2) != 0) || (((s32 (*)(void *, int))test_menu_flag__11TWindowMenuFv)((void *)arg0, 2) != 0)) {
            set_active_flag();
        }
    }
    if ((f32) *(s32 *)&this->m_5c >= lbl_805DD178) {
        if ((u32) this->m_88 != 0U) {
            ((TWindowSubStatusDisp *)(*(void * *)&this->m_88))->update_subwindow();
        }
        if ((u32) this->m_84 != 0U) {
            ((TWindowSubStatusDisp *)(*(void * *)&this->m_84))->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowMenu *)arg0)->update_scroll_value();
    ((TWindowAddition *)arg0)->step_window_tween();
    ((TWindowMenu *)arg0)->update_target_y();
    ((TWindowMenu *)arg0)->clamp_menu_choice_scroll();
    ((TWindowMenu *)arg0)->advance_past_disabled_menu_rows();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

void *__dt__11TWindowMenuFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TWindowMenu;
        TWindowSubStatusDisp::destroy_allocation((s32)(*(void **)((s8 *)arg0 + 0x84)), (s16)1);
        TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)arg0 + 0x88)), (s16)1);
        mem_free(*(void **)((s8 *)arg0 + 0x80));
        ((TWindowAddition *)arg0)->destroy_window(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TWindowMenu__ct(u8 *window_menu, u32 arg1, s32 arg2, s32 arg3) {
    u32 i;
    u8 *p;
    construct_with_parent__15TWindowAdditionFPv(window_menu, lbl_804D05CC, arg2, arg3);
    *(void **)(window_menu + 0x18) = ((s32 *)&__vt__11TWindowMenu);
    *(s32 *)window_menu = lbl_805D3960;
    *(s16 *)(window_menu + 0x72) = 0;
    *(s16 *)(window_menu + 0x74) = 0;
    *(u16 *)(window_menu + 0x76) = arg1;
    *(s16 *)(window_menu + 0x78) = 0;
    *(s16 *)(window_menu + 0x70) = 0;
    *(s16 *)(window_menu + 0x20) = arg2;
    ((TWindowMenu *)window_menu)->reset_selection();
    *(u8 **)(window_menu + 0x80) = (u8 *)mem_alloc(arg1 * 8);
    p = *(u8 **)(window_menu + 0x80);
    for (i = 0; i < arg1; i++) {
        *(s32 *)p = 0;
        *(s32 *)(p + 4) = 0;
        p += 8;
    }
    *(s32 *)(window_menu + 0x88) = 0;
    *(s32 *)(window_menu + 0x84) = 0;
    return window_menu;
}

void TWindowMenu::copy_position(void* q) { *(f32 *)&this->m_name = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); }

s32 TWindowAddition::sub_80266B18(s32 arg1) {
    return *(u16 *)((s8 *)(*(u16 **)((s8 *)(*(s32 *)((s8 *)((u8 *)this) + 0x28) + (arg1 * 4)) + 0)) + 0) & 1;
}

u8 TWindowMenu::test_menu_flag() {
    if (this->m_70 & 0x200) {
        return 0U;
    }
    return ((TAdSinglePlyChrSelectGC *)((u8 *)&(*(RecoveredGlobal_80266B30_lbl_8050E208 *)&controller_input_state).value + 0x160))->test_flag_4c();
}

s32 TWindowMenu::is_locked(s32 arg1) {
    if (this->m_70 & 0x200) {
        return 0;
    }
    return TWindowChoiceSetting::apply_choice((s32)(controller_input_state + 0x160), (s32)arg1, 6, 1);
}

int TWindowMenu::sub_80266BB8() { return (this->m_70 >> 6) & 0x1; }
