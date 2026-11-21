#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/Scroll_8026D790.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowAddition.h"
#include <stddef.h>
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"


#pragma readonly_strings on

extern "C" {
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


struct Ent_80265C30 { u8 pad[0x8]; f32 x; u8 padc[4]; f32 w; f32 h; };


struct Ent_80265E60 { u8 pad[0x14]; f32 h; };

struct Ent_80265F60 { u8 pad[0x10]; f32 w; f32 h; };


struct Ent_80265AA4 { u32 flags; u32 x; };

struct Card_80265AA4 {
    u8 pad0[0x74];
    s16 cur;
    s16 cnt;
    u8 pad1[8];
    Ent_80265AA4 *ents;
};

struct Ent_80265C30;

s32 play_sound_effect(s32, s32, s32, s32);
void measure_message_text_width(Ent_80265C30 *e, f32 x);
void TWindowSubComCard__sub_80265500(u8 *arg0);
s32 TWindowSubComCard__sub_80265660(Obj_80265660 *o, s16 i);
void TWindowSubComCard__sub_80265680(u8 *arg0, s16 arg1);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void* p, int a1, int a2, int a3);
void fn_80266378(s32 arg0);
u8 * create_yes_no_window(s32 arg0, s32 arg1, uaddr arg2, uaddr arg3);
u8 * init_shop_judgment_window(void* p);
saddr create_window_menu_default(saddr pos, s32 entries);
saddr create_titled_window_menu_default(saddr pos, s32 entries, saddr title);
void render__11TWindowMenuFv(TWindowMenu *arg0);
s32 clamp_list_scroll_offset(int, void *, void *);
s32 draw_window_scrollbar(s32, s32, void *);
}
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
saddr create_titled_window_menu(saddr arg0, s32 arg1, saddr arg2, s32 arg3);
const f64 lbl_8044F330 = 0.0;
// The TWindowMenu layout table (one type-3 text record; fn_80266378 sets the row count) and
// the window descriptor the TWindowMenu constructor passes to TWindowAddition.
struct MenuWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec;
};
MenuWindowLayout lbl_804D05A8 = {1, 0, {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 0}};
WindowDescriptor lbl_804D05CC = {{0.0f, 0.0f}, 50050.0f, &lbl_804D05A8, 3};
extern s8 controller_input_state[];
const char *lbl_805D3960 = "TWindowMenu";
extern s32 actor_frame_tick;

void TKeyBoardControl::set_composer_flag62_bit4() {
    TWindowKeyBoardBase *keyboard = m_base;
    if (keyboard != NULL) {
        keyboard->set_flag62_bit4();
    }
}

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
        stack.sp8 = ((this->frame_size[0]) - 4.0f) - 9.0f;
        stack.spC = (f32) ((*(s16 *)&this->m_72 * 0x14) - 2);
        ((Scroll_8026D790 *)window_menu)->copy_position(&stack.sp8);
    }
}

void TWindowSubComCard__sub_80265500(u8 *menu_window) {
    Stack_80265500 stack;
    f32 temp_f1;
    if ((u32) *(u32 *)((s8 *)menu_window + 0x84) != 0U) {
        stack.sp8 = 0.0f;
        temp_f1 = *(f32 *)((s8 *)menu_window + 0x4C) - 20.0f;
        stack.spC = temp_f1;
        if ((u32) *(u32 *)((s8 *)menu_window + 0x88) != 0U) {
            stack.spC = temp_f1 - 6.0f;
        }
        clamp_list_scroll_offset((int) (*(u32 *)((s8 *)menu_window + 0x84)), menu_window + 0x68, &stack.sp8);
    }
}

void TWindowSubComCardList::sub_8026556C() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8026556C, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8026556C, spC) == 0x4);
    Stack_8026556C stack;
    f32 temp_f1;
    f32 temp_f2;
    u32 temp_r3;
    uaddr var_r0;
    if ((u32) this->m_84 == 0U) {
        temp_f2 = this->target_size[0];
        temp_f1 = temp_f2 - 8.0f;
        stack.spC = 0.0f;
        stack.sp8 = temp_f1;
        var_r0 = reinterpret_cast<uaddr>(new Scroll_8026D790(&stack.sp8));
        this->m_84 = var_r0;
        this->window_flags = (s32) (this->window_flags | 0x80);
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
        e = ((void *)get_array_entry(i));
        TWindowDuelResult::set_default_status(e, 0);
        measure_message_text_width_default(e);
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
  saddr temp_r3;
  s32 var_r3;
  saddr var_r5;
  u8 *var_r30;
  var_r31 = arg1;
  var_r30 = (u8 *) arg0;
  var_r4 = var_r31;
  temp_r3 = reinterpret_cast<saddr>(((TWindowBase *)arg0)->get_array_entry((s16)var_r4));
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
    Ent_802656D8 *e = (Ent_802656D8 *)((TWindowBase *)w)->get_array_entry((s16)idx);
    Rec_802656D8 *r = w->f80;
    e->f24 = val;
    r[(s16)idx].flags &= ~0x10;
}

void *TWindowMenu::get_selected_entry() {
    s16 temp_r4;
    temp_r4 = *(s16 *)&this->m_78;
    if (temp_r4 < 0) {
        return 0;
    }
    if (temp_r4 >= (s16) *(s16 *)&this->m_76) {
        return 0;
    }
    return get_array_entry(temp_r4);
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
        temp_r3 = *(s32 *)((s8 *)(*(saddr *)&this->m_80) + (*(s16 *)&this->m_78 * 8));
        if (temp_r3 & 0x10) {
            if (!(temp_r3 & 0x20)) {
                play_sound_effect(0x53F06, 0, 0, 0);
            }
        } else {
            if (!(temp_r3 & 0x20)) {
                play_sound_effect(0x52D01, 0, 0, 0);
            }
            this->m_70 = (u16) (this->m_70 | 2);
            window_sub_status_disp = (u8 *)this->m_88;
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
        v = 9.0f + (f32)(*(s16 *)(arg0 + 0x78) * 0x14);
        v -= 0.5f * (*(f32 *)(arg0 + 0x4C) - 20.0f);
        if (*(u32 *)(arg0 + 0x88) != 0) {
            v -= 3.0f;
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
        temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x4C) - 20.0f;
        stack.spC = temp_f1;
        if (this->m_88 != 0) {
            stack.spC = temp_f1 - 6.0f;
        }
        clamp_list_scroll_offset(this->m_84, (void *) (((u8 *)this) + 0x68), &stack.sp8);
    }
}

void TWindowMenu::advance_past_disabled_menu_rows() {
    u16 *e;
    s16 t;
    if (((Card_80265AA4 *)this)->cur < ((Card_80265AA4 *)this)->cnt) {
        e = ((u16 *)((TWindowBase *)((Card_80265AA4 *)this))->get_array_entry((s32)(((Card_80265AA4 *)this)->cur)));
        while (((u32)((TWindowSubComCard *)e)->get_field_20()) != 0 && (*e & 0x10)) {
            t = ((Card_80265AA4 *)this)->cur + 1;
            ((Card_80265AA4 *)this)->cur = t;
            if (t >= ((Card_80265AA4 *)this)->cnt) {
                break;
            }
            e = ((u16 *)((TWindowBase *)((Card_80265AA4 *)this))->get_array_entry((s32)(((Card_80265AA4 *)this)->cur)));
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
    v = *((f32 *) (static_cast<u8 *>(reinterpret_cast<TWindowMenu *>(arg0)->get_selected_entry()) + 0xC));
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
  v += 0.5f * ((*((f32 *)(arg0 + 0x3C))) - (*((f32 *)(arg0 + 0x4C))));
  new_var2 = (u8 *)&this->scroll_offset[1];
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
void align_menu_entry_positions(TWindowMenu *self) {
    f32 left = self->target_size[0] - 8.0f;
    f32 right = 0.5f * self->target_size[0] - 4.0f;
    u32 i;
    for (i = 0; i < *reinterpret_cast<const s16 *>(&self->m_76); i++) {
        Ent_80265C30 *e = (Ent_80265C30 *)self->get_array_entry(i);
        if (((TWindowSubComCard *)e)->get_field_20() != 0) {
            measure_message_text_width(e, left);
            if (e->h > 18.0f) {
                e->x = 0.0f;
            } else {
                e->x = right - 0.5f * e->w;
            }
        }
    }
}
#pragma pop

void TWindowSubComCard::calc_layout_height(f32 width) {
    f32 h;
    u32 i;
    Ent_80265C30 *e;
    h = 0.0f;
    for (i = 0; i < *(s16 *)(((u8 *)this) + 0x76); i++) {
        e = (Ent_80265C30 *)((TWindowBase *)this)->get_array_entry(i);
        if (((TWindowSubComCard *)e)->get_field_20() != 0 && !(e->h <= lbl_8044F330)) {
            measure_message_text_width(e, width);
            h += 2.0f + e->h;
        }
    }
    h -= 2.0f;
    if (this->m_2c & 0x40) {
        h += 6.0f;
    }
    this->m_38 = width;
    *(f32 *)(((u8 *)this) + 0x3C) = 20.0f + h;
    *(f32 *)(((u8 *)this) + 0x7C) = h;
    ((TWindowBase *)((u8 *)this))->save_position();
}

void TWindowSubComCardList::set_scroll_target(f32 width, f32 farg1) {
    update_layout_height(width);
    if (*(f32 *)((s8 *)this + 0x3C) > farg1) {
        sub_8026556C();
    }
    *(f32 *)((s8 *)this + 0x3C) = farg1;
    layout_height = (f32) (farg1 - 20.0f);
    save_position();
    update_scroll_target_position();
}

void TWindowMenu::update_layout_height(f32 x) {
    f32 sum = 0.0f;
    u32 i;
    for (i = 0; i < *reinterpret_cast<const s16 *>(&m_76); i++) {
        Ent_80265E60 *e = ((Ent_80265E60 *)this->TWindowBase::get_array_entry(i));
        if (reinterpret_cast<TWindowSubComCard *>(e)->get_field_20() != 0) {
            if (!(e->h <= lbl_8044F330)) {
                sum += 2.0f + e->h;
            }
        }
    }
    sum -= 2.0f;
    if (window_flags & 0x40) {
        sum += 6.0f;
    }
    target_size[0] = x;
    target_size[1] = 20.0f + sum;
    layout_height = sum;
    save_position();
}

void TWindowMenu::calc_window_size() {
    f32 width = 0.0f;
    f32 row_gap = 2.0f;
    f32 sum = width;
    f64 minimum_entry_height = lbl_8044F330;
    u32 i;
    for (i = 0; i < *reinterpret_cast<s16 *>(&m_76); i++) {
        Ent_80265F60 *e = static_cast<Ent_80265F60 *>(get_array_entry(i));
        if (reinterpret_cast<TWindowSubComCard *>(e)->get_field_20() != 0) {
            if (e->w > width) {
                width = e->w;
            }
            if (!(e->h <= minimum_entry_height)) {
                sum += row_gap + e->h;
            }
        }
    }
    sum -= 2.0f;
    layout_height = sum;
    if (window_flags & 0x40) {
        sum += 6.0f;
    }
    target_size[0] = 8.0f + width;
    target_size[1] = 20.0f + sum;
    save_position();
}

void TWindowMenu::layout_entries() {
    f32 gap;
    f64 zero;
    f32 y;
    u32 i;
    u8 *e;
    f32 h;
    y = 0.0f;
    gap = 2.0f;
    zero = lbl_8044F330;
    for (i = 0; i < *(s16 *)&this->m_76; i++) {
        e = (u8 *)get_array_entry(i);
        if (((TWindowSubComCard *)e)->get_field_20() != 0) {
            *(f32 *)(e + 0xC) = y;
            h = *(f32 *)(e + 0x14);
            if (!(h <= zero)) {
                y += gap + h;
            }
        }
    }
}

void TWindowMenu::clear_transition_flag() {
    u16 flags = m_70;
    if (flags & 0x20) {
        m_70 = flags & ~0x20;
        target_size[1] = 20.0f + layout_height;
        tween_ticks = 3;
    }
}

void TWindowOptionCtrl::open() {
    u16 temp_r4;
    void *temp_r3;
    f32 temp_f1;

    temp_r4 = *(u16 *)((s8 *)this + 0x70);
    if (!(temp_r4 & 0x20)) {
        *(u16 *)((s8 *)this + 0x70) = (u16) (temp_r4 | 0x20);
        temp_r3 = (void *)((TWindowMenu *)this)->get_selected_entry();
        temp_f1 = 20.0f;
        *(f32 *)&this->m_3c = (f32) (temp_f1 + *(f32 *)((s8 *)temp_r3 + 0x14));
        if (*(s32 *)&this->m_2c & 0x40) {
            *(f32 *)&this->m_3c += 6.0f;
        }
        *(s32 *)((s8 *)this + 0x50) = 3;
    }
}

void add_gray_text_entry(TWindowSubTradeMain *list, const char *text, s32 kind, s32 id) {
    list->add_text_entry((saddr)text, kind | 0x10, id, 0xFF909090);
}

s32 TWindowSubTradeMain::add_text_entry(saddr text, s32 arg2, s32 id, s32 arg4) {
    u8 *arg0 = (u8 *)this;
    s16 temp_r7;
    u8 *window_help_item;
    u8 *temp_r30;

    if ((s16) *(s16 *)&this->unk_72 >= (s16) *(s16 *)((s8 *)arg0 + 0x76)) {
        return 0;
    }
    window_help_item = (u8 *)((TWindowBase *)arg0)->get_array_entry(*(s16 *)&this->unk_72);
    temp_r7 = *(s16 *)&this->unk_72;
    temp_r30 = (unsigned char *) (*(saddr *)&this->m_80 + (temp_r7 * 8));
    *(f32 *)((s8 *)window_help_item + 0xC) = (f32) (temp_r7 * 0x14);
    *(s32 *)((s8 *)window_help_item + 0x24) = arg4;
    if (arg2 & 1) {
        set_text_entry_string(window_help_item, (text), 0x20);
    } else {
        set_text_entry_string(window_help_item, (text), 0);
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
    measure_message_text_width_default(window_help_item);
    *(s32 *)((s8 *)temp_r30 + 0) = arg2;
    *(s32 *)((s8 *)temp_r30 + 4) = id;
    *(s16 *)&this->unk_72 = (s16) (*(s16 *)&this->unk_72 + 1);
    return 1;
}

int forward_trade_action_default__16TObjCityMainWarpFPviii(void* p, int a1, int a2, int a3) { return ((TWindowSubTradeMain *)p)->add_text_entry(a1, a2, a3, -1); }

void fn_80266378(s32 arg0) {
    lbl_804D05A8.rows = arg0;
}

u8 *create_yes_no_window(s32 position, s32 id, uaddr yes_text, uaddr no_text) {
  TWindowMenu *window_menu = create_window_menu(position, 2, id);
  if (yes_text == 0U)
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((saddr) ((u8 *) window_menu), (void *) TWindowSubStatusDisp::get_message_10(0x5B), 6, 0);
  }
  else
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((saddr) window_menu, (void *) yes_text, 6, 0);
  }
  if (0U == no_text)
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((saddr) ((u8 *) window_menu), (void *) TWindowSubStatusDisp::get_message_10(0x5C), 6, 1);
  }
  else
  {
    ((s32 (*)(int, void *, int, int))forward_trade_action_default__16TObjCityMainWarpFPviii)((saddr) ((u8 *) window_menu), (void *) no_text, 6, 1);
  }
  window_menu->calc_window_size();
  if (window_menu->frame_size[0] < 104.0f)
  {
    window_menu->update_layout_height(104.0f);
  }
  align_menu_entry_positions(window_menu);
  window_menu->set_ready_flag();
  window_menu->set_depth(50030.0f);
  return (u8 *) window_menu;
}

u8 * init_shop_judgment_window(void* p) { return create_yes_no_window((saddr)p, 4, (u32)(0), (u32)(0)); }

TWindowMenu *create_window_menu(saddr position, s32 count, s32 client_id) {
    fn_80266378(count);
    return new TWindowMenu(count, client_id, position);
}

saddr create_window_menu_default(saddr pos, s32 entries) {
    return reinterpret_cast<saddr>(create_window_menu(pos, entries, 4));
}

saddr create_titled_window_menu(saddr arg0, s32 arg1, saddr title, s32 client_id) {
    saddr temp_r31;
    saddr temp_r3;
    saddr var_r0;
    temp_r31 = reinterpret_cast<saddr>(create_window_menu(arg0, arg1, client_id));
    temp_r3 = (saddr)::operator new(0x24);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (saddr)((TWindowSubStatusDisp *)temp_r3)->construct_type1_heading(title, client_id);
    }
    *(s32 *)((s8 *)temp_r31 + 0x88) = var_r0;
    *(s32 *)((s8 *)temp_r31 + 0x2C) = (s32) (*(s32 *)((s8 *)temp_r31 + 0x2C) | 0x40);
    return temp_r31;
}

saddr create_titled_window_menu_default(saddr pos, s32 entries, saddr title) {
    return create_titled_window_menu(pos, entries, title, 4);
}

void TWindowMenu::draw_selected_bar(u8 *window_key_board_soft) {
    s16 temp_r4;
    u16 *entry;
    if (!(actor_frame_tick & 0x10)) {
        temp_r4 = *(s16 *)&this->unk_7A;
        if (temp_r4 >= 0) {
            entry = (u16 *)(((saddr)get_array_entry((s32) temp_r4)));
            if (*entry & 1) {
                draw_selection_bar(reinterpret_cast<WindowDrawContext *>(window_key_board_soft), (u8 *)entry, 1);
            }
        }
    }
}

void TWindowMenu::render_selected_entry(saddr window_key_board_soft) {
    u16 *entry;

    entry = (u16 *)this->get_array_entry(*(s16 *)&this->m_78);
    if (*entry & 1) {
        draw_selection_bar(reinterpret_cast<WindowDrawContext *>(window_key_board_soft), (u8 *)entry, is_decided());
    }
}

void render__11TWindowMenuFv(TWindowMenu *arg0) {
    saddr window_key_board_soft;

    window_key_board_soft = reinterpret_cast<saddr>(arg0->get_draw_context());
    ((TWindowBase *)arg0)->draw_window_frame((void *)window_key_board_soft);
    draw_visible_window_entries(
        reinterpret_cast<const void *>(arg0),
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)arg0 + 0x24),
        reinterpret_cast<WindowDrawContext *>(window_key_board_soft));
    if (!(arg0->m_70 & 0x80)) {
        arg0->render_selected_entry(window_key_board_soft);
        arg0->draw_selected_bar((u8 *)window_key_board_soft);
    }
    if (arg0->m_88 != 0) {
        arg0->m_88->forward_render((void *)(window_key_board_soft));
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
    u8 *context;

    ((TWindowMenu *)this)->layout_entries();
    if (!(*(s32 *)&this->window_flags & 2)) {
        *(s32 *)&this->open_tick = 0x01000000;
    }
    if ((((TWindowMenu *)arg0)->sub_80266BB8() == 0) && (((TWindowMenu *)arg0)->is_decided() == 0) && ((s32) *(s32 *)&this->open_tick > 2) && (is_window_display_enabled() != 0) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        temp_r30 = is_player_input_active((this->client_index));
        if (this->m_70 & 0x10) {
            input = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
            if ((test_buttons_press_or_repeat((saddr)input, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat((saddr)input, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        } else {
            temp_r29_2 = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        }
        context = (u8 *)controller_input_state + (temp_r30 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (((TWindowMenu *)arg0)->test_menu_flag(4) != 0)) {
            confirm_selection();
        }
        if ((TWindowShortListCtrl__check_controller_button(context, 2) != 0) || (((TWindowMenu *)arg0)->test_menu_flag(2) != 0)) {
            set_active_flag();
        }
    }
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        if (this->m_88 != 0) {
            this->m_88->update_subwindow();
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
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowMenu::~TWindowMenu() {
    TWindowSubStatusDisp::destroy_allocation((saddr)(*(void **)((s8 *)this + 0x84)), (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)(*(void **)((s8 *)this + 0x88)), (s16)1);
    mem_free(*(void **)((s8 *)this + 0x80));
}

TWindowMenu::TWindowMenu(u32 count, s32 arg2, saddr arg3) : TWindowAddition((u8 *)&lbl_804D05CC, (s16)arg2, (u8 *)arg3) {
    #define window_menu ((u8 *)this)
    u32 i;
    u8 *p;
    *(const char **)window_menu = lbl_805D3960;
    *(s16 *)(window_menu + 0x72) = 0;
    *(s16 *)(window_menu + 0x74) = 0;
    *(u16 *)(window_menu + 0x76) = count;
    *(s16 *)(window_menu + 0x78) = 0;
    *(s16 *)(window_menu + 0x70) = 0;
    *(s16 *)(window_menu + 0x20) = arg2;
    ((TWindowMenu *)window_menu)->reset_selection();
    *(u8 **)(window_menu + 0x80) = (u8 *)mem_alloc(count * 8);
    p = *(u8 **)(window_menu + 0x80);
    for (i = 0; i < count; i++) {
        *(s32 *)p = 0;
        *(s32 *)(p + 4) = 0;
        p += 8;
    }
    *(s32 *)(window_menu + 0x88) = 0;
    *(s32 *)(window_menu + 0x84) = 0;
    #undef window_menu
}

void Scroll_8026D790::copy_position(void *pair) {
    f32 *point = static_cast<f32 *>(pair);
    m_0 = point[0];
    height = point[1];
}

s32 TWindowAddition::sub_80266B18(s32 arg1) {
    return *(u16 *)((s8 *)(*(u16 **)((s8 *)(*(saddr *)((s8 *)((u8 *)this) + 0x28) + (arg1 * 4)) + 0)) + 0) & 1;
}

s32 TWindowMenu::test_menu_flag(s32 buttons) {
    if (this->m_70 & 0x200) {
        return 0U;
    }
    return test_controller_flag_4c_color((u8 *)&controller_input_state + 0x160, buttons);
}

s32 TWindowMenu::is_locked(s32 buttons) {
    if (this->m_70 & 0x200) {
        return 0;
    }
    return test_buttons_press_or_repeat((saddr)(controller_input_state + 0x160), (s32)buttons, 6, 1);
}

int TWindowMenu::sub_80266BB8() { return (this->m_70 >> 6) & 0x1; }
