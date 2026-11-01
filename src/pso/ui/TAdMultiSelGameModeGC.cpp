#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/TAdMultiSelGameModeGC.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/enemy/TObjEneDolmOlm.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/ui/TAdMultiSelGameModeGC.h"
#include "pso/misc/TWindowSubComCardList.h"

#include "types.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TAdStorySelectGC.h"
#include "pso/TLevelSelect.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/TAdSelectTxtGC.h"
#include "pso/misc/TWindowMenu.h"

struct Self_80300770 {
    u8 pad0[0x1C];
    s32 state;
};
typedef void (TAdMultiSelGameModeGC::*Action_80300770)();

struct Ent_80300850 { u8 pad[0x364]; s32 f364; };

struct Pos_8030095C { s32 v[8]; };

struct Cur_8030095C { s32 v[2]; };

struct Obj_8030095C {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
};

extern "C" {
extern s32 TAdMultiSelGameModeGC__data_805D69F0;
s32 is_multiplayer_character_slot_selected(u32);
Ent_80300850 *get_char_table_entry__23TAdSinglePlyChrSelectGCFi(int);
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void __ct__8TAdRayGCFv(void *, void *);
void __ct__10TAdTitleGCFP7TObjectl(void *, void *, s32);
void *__ct__14TAdSelectTxtGCFP7TObjectPvPv(void *, void *, void *, s32);
void __ct__13TAdTitleTexGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
extern s32 lbl_80474E40[];
extern Cur_8030095C lbl_80474EAC[];
extern Pos_8030095C TAdMultiSelGameModeGC__menu_position_table;
extern void *__vt__21TAdMultiSelGameModeGC[];
extern s32 TAdMultiSelGameModeGC__name;
extern s32 game_difficulty_selection;
extern s32 lbl_805D69F4;
extern const f32 lbl_805DEF44;
Obj_8030095C *__ct__21TAdMultiSelGameModeGCFv(Obj_8030095C *self, s32 parent, s32 mode);
s32 set_default_camera__21TAdMultiChgGameModeGCFv(void *);
}

typedef struct Pos_803001B4 { s32 x, y; } Pos_803001B4;

typedef struct Pos3_803001B4 { Pos_803001B4 p[3]; } Pos3_803001B4;

typedef struct Arr3_803001B4 { s32 v[3]; } Arr3_803001B4;

extern "C" {
void align_menu_entry_positions(s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, u32);
extern Pos3_803001B4 multi_sel_game_mode_position;
extern Arr3_803001B4 lbl_80474EEC;
extern Arr3_803001B4 multi_sel_game_mode_arr3;
extern const f32 lbl_805DEF40;
extern u8 controller_input_state[];
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);

void TAdMultiSelGameModeGC::render() {  }

s32 TAdMultiSelGameModeGC::is_mode_entry_enabled(void *self, s32 mode, u32 idx) {
    switch (mode) {
    case 0:
        return idx < (u32)(get_max_difficulty_for_party_level() + 1) ? 1 : 0;
    case 1:
        return 1;
    case 2:
        if (TAdMultiSelGameModeGC__data_805D69F0 == 1) {
            return idx == 0 ? 1 : 0;
        }
        return 1;
    default:
        return 0;
    }
}

s32 TAdMultiSelGameModeGC::build_mode_menu(s32 arg1) {
    Pos3_803001B4 pos = multi_sel_game_mode_position;
    u32 counts[3];
    u32 n;
    s32 r;
    u32 i;
    counts[0] = 4;
    counts[1] = 3;
    counts[2] = 2;
    {
    Arr3_803001B4 a = lbl_80474EEC;
    Arr3_803001B4 b = multi_sel_game_mode_arr3;
    n = counts[arg1];
    r = check_room_seq_4__16TAdChrSelASlotGCFl(&pos.p[arg1], n);
    for (i = 0; i < n; i++) {
        if (TAdMultiSelGameModeGC::is_mode_entry_enabled(this, arg1, i) != 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)r, (int)(get_localized_text_entry(0x18, i + b.v[arg1])), 6, (int)(i + a.v[arg1]));
        } else {
            TWindowSubComCard::draw_text_gray(r, get_localized_text_entry(0x18, i + b.v[arg1]), 6, i + a.v[arg1]);
        }
        ((TWindowSubComCardList *)r)->update_layout_height(lbl_805DEF40);
        ((TWindowSubComCardList *)r)->set_selected_index(a.v[arg1]);
        align_menu_entry_positions(r);
    }
    return r;
    }
}

void TAdMultiSelGameModeGC::exit_keyboard_mode() { TObjEneDolmOlm::reset_count(); TKeyBoardControl__sub_8000F9CC(14); }
void TAdMultiSelGameModeGC::update_transition_state() {

    switch (*(s32 *)((s8 *)this + 0x20)) {
    case 0:
        TAdMultiChgGameModeGC::begin_transition();
        return;
    case 1:
        TAdMultiChgGameModeGC::begin_change_game_mode();
        return;
    }
}

void TAdMultiSelGameModeGC::sub_803003A4() {
    Obj_8030095C *self = (Obj_8030095C *)this;
    switch (TAdSinglePlyChrSelectGC__sub_801334DC(self->f3C)) {
    case 0:
        if (((TWindowMenu *)self->f2C)->is_cancelled() != 0) {
            ((TAdMultiSelGameModeGC *)self->f3C)->set_selection_state(1);
            self->f1C = 1;
        } else if (((TWindowMenu *)self->f2C)->is_decided() != 0) {
            game_difficulty_selection = ((TWindowMenu *)self->f2C)->get_selected_value();
            ((TAdSelectTxtGC *)self->f30)->reset_slots(&lbl_80474E40[12], (void *)game_difficulty_selection);
            ((TAdMultiSelGameModeGC *)self->f3C)->set_selection_state(1);
            self->f1C = 1;
        }
        break;
    case 1:
        if (((TWindowMenu *)self->f2C)->is_cancelled() != 0) {
            ((TAdMultiSelGameModeGC *)self->f3C)->set_selection_state(1);
            self->f1C = 1;
        } else if (((TWindowMenu *)self->f2C)->is_decided() != 0) {
            switch (((TWindowMenu *)self->f2C)->get_selected_value()) {
            case 0:
                TAdMultiSelGameModeGC__data_805D69F0 = 0;
                break;
            case 1:
                TAdMultiSelGameModeGC__data_805D69F0 = 1;
                break;
            case 2:
                TAdMultiSelGameModeGC__data_805D69F0 = 2;
                break;
            }
            ((TAdSelectTxtGC *)self->f34)->reset_slots(&lbl_80474E40[15], (void *)(TAdMultiSelGameModeGC__data_805D69F0 + 9));
            if (TAdMultiSelGameModeGC__data_805D69F0 == 1 && lbl_805D69F4 == 1) {
                lbl_805D69F4 = 0;
                TAdStorySelectGC::set_state(0);
                ((TAdSelectTxtGC *)self->f38)->reset_slots(&lbl_80474E40[18], (void *)(lbl_805D69F4 + 4));
            }
            if (TAdMultiSelGameModeGC__data_805D69F0 == 2 && game_difficulty_selection != 0) {
                game_difficulty_selection = 0;
                ((TAdSelectTxtGC *)self->f30)->reset_slots(&lbl_80474E40[12], (void *)0);
            }
            ((TAdMultiSelGameModeGC *)self->f3C)->set_selection_state(1);
            self->f1C = 1;
        }
        break;
    case 2:
        if (((TWindowMenu *)self->f2C)->is_cancelled() != 0) {
            ((TAdMultiSelGameModeGC *)self->f3C)->set_selection_state(1);
            self->f1C = 1;
        } else if (((TWindowMenu *)self->f2C)->is_decided() != 0) {
            switch (((TWindowMenu *)self->f2C)->get_selected_value()) {
            case 0:
                lbl_805D69F4 = 0;
                TAdStorySelectGC::set_state(0);
                break;
            case 1:
                lbl_805D69F4 = 1;
                TAdStorySelectGC::set_state(1);
                break;
            }
            ((TAdSelectTxtGC *)self->f38)->reset_slots(&lbl_80474E40[18], (void *)(lbl_805D69F4 + 4));
            ((TAdMultiSelGameModeGC *)self->f3C)->set_selection_state(1);
            self->f1C = 1;
        }
        break;
    case 3:
        break;
    }
}

void TAdMultiSelGameModeGC::sub_80300648() {
    Obj_8030095C *self = (Obj_8030095C *)this;
    self->f24 = TAdSinglePlyChrSelectGC__sub_801334DC(self->f3C);
    if (self->f28 != self->f24) {
        ((TAdMultiPlyChrSelectGC *)self->f40)->set_entry_value(0, get_localized_text_entry(0x18, self->f24));
    }
    if (self->f2C != NULL) {
        ((TObject *)self->f2C)->queue_destruction();
        self->f2C = NULL;
    }
    if (TWindowShortListCtrl__check_controller_button(&controller_input_state[0x20], 2) != 0 ||
        test_flag_4c__23TAdSinglePlyChrSelectGCFv(&controller_input_state[0x160], 2) != 0) {
        self->f1C = 3;
    } else if (((TAdSinglePlyChrSelectGC *)self->f3C)->get_selected_slot() == 1) {
        switch (TAdSinglePlyChrSelectGC__sub_801334DC(self->f3C)) {
        case 0:
        case 1:
        case 2:
            self->f2C = (void *)((TAdMultiSelGameModeGC *)self)->build_mode_menu(TAdSinglePlyChrSelectGC__sub_801334DC(self->f3C));
            self->f1C = 2;
            break;
        case 3:
            self->f1C = 4;
            break;
        }
    }
    self->f28 = self->f24;
}

void TAdMultiSelGameModeGC::sub_80300764() { *(s32*)((char*)this + 0x1c) = 1; }

void run_task__21TAdMultiSelGameModeGCFv(Self_80300770 *self) {
    set_default_camera__21TAdMultiChgGameModeGCFv(self);
    static Action_80300770 tbl[5] = {
        &TAdMultiSelGameModeGC::sub_80300764, &TAdMultiSelGameModeGC::sub_80300648,
        &TAdMultiSelGameModeGC::sub_803003A4, &TAdMultiSelGameModeGC::update_transition_state,
        &TAdMultiSelGameModeGC::exit_keyboard_mode,
    };
    (((TAdMultiSelGameModeGC *)self)->*tbl[self->state])();
}
}
s32 get_max_difficulty_for_party_level(void) {
    s32 m;
    s32 i;
    if (TAdMultiSelGameModeGC__data_805D69F0 == 2) {
        return 0;
    }
    m = TObjEneDolmOlm__sub_80300CF0();
    for (i = 0; i < 4; i++) {
        if (is_multiplayer_character_slot_selected(i) != 0) {
            s32 t = get_char_table_entry__23TAdSinglePlyChrSelectGCFi(i)->f364 + 1;
            if ((u32)t < (u32)m) {
                m = t;
            }
        }
    }
    if (m < 20) {
        return 0;
    }
    if (m < 40) {
        return 1;
    }
    return (m < 80 ? -1 : 0) + 3;
}

TAdMultiSelGameModeGC::~TAdMultiSelGameModeGC() {}

Obj_8030095C *__ct__21TAdMultiSelGameModeGCFv(Obj_8030095C *self, s32 parent, s32 mode) {
    void *p;
    __ct__7TObjectFP7TObject(self);
    self->vt = __vt__21TAdMultiSelGameModeGC;
    self->f0 = TAdMultiSelGameModeGC__name;
    self->f1C = 0;
    self->f24 = 3;
    self->f20 = mode;
    self->f28 = -1;
    self->f40 = 0;
    self->f3C = 0;
    self->f30 = 0;
    self->f34 = 0;
    self->f38 = 0;
    self->f2C = 0;
    lbl_805D69F4 = TLobby::get_instance();
    if (TAdMultiSelGameModeGC__data_805D69F0 == 1) {
        lbl_805D69F4 = 0;
    }
    switch (lbl_805D69F4) {
    case 0:
        TAdStorySelectGC::set_state(0);
        break;
    case 1:
        TAdStorySelectGC::set_state(1);
        break;
    }
    if ((p = __nw__7TObjectFUl(0x24)) != NULL) {
        __ct__9TAdBackGCFv(p, self);
    }
    if ((p = __nw__7TObjectFUl(0x28)) != NULL) {
        __ct__12TAdBackTxtGCFv(p, self);
    }
    if ((p = __nw__7TObjectFUl(0x24)) != NULL) {
        __ct__8TAdRayGCFv(p, self);
    }
    if ((p = __nw__7TObjectFUl(0x138)) != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(p, self, 0xE);
    }
    if ((p = __nw__7TObjectFUl(0x9C)) != NULL) {
        __ct__13TAdTitleTexGCFv(p, self);
    }
    if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
        __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &lbl_80474E40[0], 0x10);
    }
    if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
        __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &lbl_80474E40[3], 0x11);
    }
    if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
        __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &lbl_80474E40[6], 0x8);
    }
    if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
        __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &lbl_80474E40[9], 0xF);
    }
    {
        s32 max = ((s32 (*)(void *))get_max_difficulty_for_party_level)(self);
        game_difficulty_selection = (game_difficulty_selection <= max) ? game_difficulty_selection : 0;
    }
    if (TAdMultiSelGameModeGC__data_805D69F0 == 2) {
        game_difficulty_selection = 0;
    }
    p = __nw__7TObjectFUl(0xE0);
    if (p != NULL) {
        p = __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &lbl_80474E40[12], game_difficulty_selection);
    }
    self->f30 = p;
    p = __nw__7TObjectFUl(0xE0);
    if (p != NULL) {
        p = __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &lbl_80474E40[15], TAdMultiSelGameModeGC__data_805D69F0 + 9);
    }
    self->f34 = p;
    p = __nw__7TObjectFUl(0xE0);
    if (p != NULL) {
        p = __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &lbl_80474E40[18], lbl_805D69F4 + 4);
    }
    self->f38 = p;
    {
        Cur_8030095C cur = lbl_80474EAC[0];
        Pos_8030095C pos = TAdMultiSelGameModeGC__menu_position_table;
        p = __nw__7TObjectFUl(0x708);
        if (p != NULL) {
            p = __ct__14TAdSelectCurGCFv(p, self, &pos, &cur);
        }
        self->f3C = p;
        ((TLevelSelect *)(self->f3C))->add_item_rect(&pos.v[0]);
        ((TLevelSelect *)(self->f3C))->add_item_rect(&pos.v[2]);
        ((TLevelSelect *)(self->f3C))->add_item_rect(&pos.v[4]);
        ((TLevelSelect *)(self->f3C))->add_item_rect(&pos.v[6]);
    }
    ((TLobby *)(self->f3C))->set_ad_field(self->f24);
    p = __nw__7TObjectFUl(0x44);
    if (p != NULL) {
        p = __ct__13TAdGuideTxtGCFv(p, self);
    }
    self->f40 = p;
    create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)self, 0x10, (f32)lbl_805DEF44);
    return self;
}
