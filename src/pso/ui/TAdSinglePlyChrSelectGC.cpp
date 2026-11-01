#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TPlyCharData.h"

struct P_802D4F2C { f32 x, y; };

struct T_802D4F2C { P_802D4F2C p[3]; };

struct Self_802D4B6C {
    s32 pad[7];
    s32 flag1c;
    s32 state;
    s32 prev;
};
typedef void (TAdSinglePlyChrSelectGC::*Act_802D4B6C)();

extern "C" {
s32 set_default_camera__21TAdMultiChgGameModeGCFv(void *);
void *__nw__7TObjectFUl(u32);
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 __ct__9TAdBackGCFv(void *, void *);
s32 __ct__12TAdBackTxtGCFv(void *, void *);
s32 __ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void *__ct__13TAdTitleTexGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
u8 *get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1);
extern u8 single_chr_select_item_rect_table[];
extern u8 lbl_80472530[];
extern T_802D4F2C single_chr_select_position_table;
extern s32 __vt__23TAdSinglePlyChrSelectGC[];
extern s32 lbl_805D3F40;
u8 *TAdSinglePlyChrSelectGC__ct(u8 *arg0, void *parent);
void *__dt__23TAdSinglePlyChrSelectGCFv(void *arg0, s16 arg1);
s32 *get_localized_text_entry(s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s32, s32, s32 *);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
TPlyCharData *get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);

extern char controller_input_state[];
extern s32 lbl_805DE784;

void TAdSinglePlyChrSelectGC::cleanup() {
    ((TAdEnterSerialAccessGC *)(*(s32 *)((s8 *)this + 0x2C)))->reset_input_state();
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x30)))->set_field_100(1);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)((s8 *)this + 0x34), 0, &lbl_805DE784);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)((s8 *)this + 0x34), 1, &lbl_805DE784);
    *(s32 *)((s8 *)this + 0x58) = -1;
    if ((u32) *(u32 *)((s8 *)this + 0x38) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x38)))->close();
        *(u32 *)((s8 *)this + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x44) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x44)))->close();
        *(u32 *)((s8 *)this + 0x44) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x48) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x48)))->close();
        *(u32 *)((s8 *)this + 0x48) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x4C) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x4C)))->close();
        *(u32 *)((s8 *)this + 0x4C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x50) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x50)))->close();
        *(u32 *)((s8 *)this + 0x50) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x3C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x3C)))->close();
        *(u32 *)((s8 *)this + 0x3C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x40) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x40)))->close();
        *(u32 *)((s8 *)this + 0x40) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x54) != 0U) {
        queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)this + 0x54)));
        *(u32 *)((s8 *)this + 0x54) = 0U;
    }
    if ((TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        *(s32 *)((s8 *)this + 0x20) = 0xB;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)this + 0x28)))->get_player_index() == 0xE) {
        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)((s8 *)this + 0x34), 0, get_localized_text_entry(0x1E, 0));
        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(*(s32 *)((s8 *)this + 0x34), 1, &lbl_805DE784);
        *(s32 *)((s8 *)this + 0x20) = 1;
    }
}

void TAdSinglePlyChrSelectGC::run_task() {
    Self_802D4B6C *self = (Self_802D4B6C *)this;
    set_default_camera__21TAdMultiChgGameModeGCFv(self);
    static Act_802D4B6C tbl[13] = {
        &TAdSinglePlyChrSelectGC::cleanup,
        &TAdSinglePlyChrSelectGC::sub_802D486C,
        &TAdSinglePlyChrSelectGC::sub_802D4730,
        &TAdSinglePlyChrSelectGC::sub_802D4664,
        &TAdSinglePlyChrSelectGC::sub_802D4570,
        &TAdSinglePlyChrSelectGC::handle_slot_selection,
        &TAdSinglePlyChrSelectGC::handle_menu_selection,
        &TAdSinglePlyChrSelectGC::update,
        &TAdSinglePlyChrSelectGC::update_card_input,
        &TAdSinglePlyChrSelectGC::handle_card_select2,
        &TAdSinglePlyChrSelectGC::handle_card_select,
        &TAdSinglePlyChrSelectGC::close_and_change_scene,
        &TAdSinglePlyChrSelectGC::finish_character_selection_transition,
    };
    (this->*tbl[self->state])();
    if (self->state != self->prev) {
        self->flag1c = 0;
    }
    self->prev = self->state;
}

s32 TAdSinglePlyChrSelectGC__sub_802D4D9C() {
    player_stats stats = get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)->m_disp_data.m_stats;
    if (stats.meseta >= 10000) {
        return 1;
    }
    return 0;
}

void TAdSinglePlyChrSelectGC::sub_802D4E08() {
    *(s32 *)((s8 *)this + 0x20) = 0;
    *(s32 *)((s8 *)this + 0x24) = (s32) *(s32 *)((s8 *)this + 0x20);
    *(s32 *)((s8 *)this + 0x2C) = 0;
    *(s32 *)((s8 *)this + 0x30) = 0;
    *(s32 *)((s8 *)this + 0x54) = 0;
    *(s32 *)((s8 *)this + 0x34) = 0;
    *(s32 *)((s8 *)this + 0x38) = 0;
    *(s32 *)((s8 *)this + 0x44) = 0;
    *(s32 *)((s8 *)this + 0x48) = 0;
    *(s32 *)((s8 *)this + 0x4C) = 0;
    *(s32 *)((s8 *)this + 0x50) = 0;
    *(s32 *)((s8 *)this + 0x3C) = 0;
    *(s32 *)((s8 *)this + 0x40) = 0;
    *(s32 *)((s8 *)this + 0x1C) = -1;
    *(s32 *)((s8 *)this + 0x58) = -1;
    *(s32 *)((s8 *)this + 0x5C) = -1;
}

void *__dt__23TAdSinglePlyChrSelectGCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TAdSinglePlyChrSelectGC;
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x38))); *(s32 *)((s8 *)arg0 + 0x38) = 0; }
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x3C))); *(s32 *)((s8 *)arg0 + 0x3C) = 0; }
        if (*(void **)((s8 *)arg0 + 0x40) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x40))); *(s32 *)((s8 *)arg0 + 0x40) = 0; }
        if (*(void **)((s8 *)arg0 + 0x44) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x44))); *(s32 *)((s8 *)arg0 + 0x44) = 0; }
        if (*(void **)((s8 *)arg0 + 0x48) != NULL) { queue_destruction__7TObjectFv((void *)(*(void **)((s8 *)arg0 + 0x48))); *(s32 *)((s8 *)arg0 + 0x48) = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TAdSinglePlyChrSelectGC__ct(u8 *arg0, void *parent) {
    void *p;
    __ct__7TObjectFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TAdSinglePlyChrSelectGC;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D3F40;
    ((TAdSinglePlyChrSelectGC *)arg0)->sub_802D4E08();
    p = __nw__7TObjectFUl(0x24);
    if (p != NULL) {
        __ct__9TAdBackGCFv(p, arg0);
    }
    p = __nw__7TObjectFUl(0x28);
    if (p != NULL) {
        __ct__12TAdBackTxtGCFv(p, arg0);
    }
    p = __nw__7TObjectFUl(0x138);
    if (p != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(p, arg0, 0);
    }
    *(s32 *)((s8 *)arg0 + 0x28) = (s32)get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii((s32)arg0, 0);
    *(s32 *)((s8 *)arg0 + 0x30) = get_or_create_player__22TAdMultiPlyChrSelectGCFiiii((s32)arg0, 0, -1, 0);
    p = __nw__7TObjectFUl(0x44);
    if (p != NULL) {
        p = __ct__13TAdGuideTxtGCFv(p, arg0);
    }
    *(void **)((s8 *)arg0 + 0x34) = p;
    p = __nw__7TObjectFUl(0x708);
    if (p != NULL) {
        p = __ct__14TAdSelectCurGCFv(p, arg0, single_chr_select_item_rect_table, lbl_80472530);
    }
    *(void **)((s8 *)arg0 + 0x2C) = p;
    p = __nw__7TObjectFUl(0x9C);
    if (p != NULL) {
        p = __ct__13TAdTitleTexGCFv(p, arg0);
    }
    T_802D4F2C t = single_chr_select_position_table;
    fn_802D50B8(p, &t.p[0], &t.p[1], &t.p[2]);
    return arg0;
}

}
