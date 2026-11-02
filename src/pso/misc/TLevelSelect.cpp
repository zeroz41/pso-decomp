#include "pso/TLevelSelect.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLevelSelect.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801334D4.h"

#include "types.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Self_80133068 { u8 pad[0x20]; s32 f20; s32 f24; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Self_8013319C {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    s32 count;
    void *cur;
    void *guide;
};

struct Ent_8013319C { s32 id; s32 b; s32 c; };

struct Ents_8013319C { Ent_8013319C e[4]; };

struct Pos_8013319C { s32 x; s32 y; };

struct Poss_8013319C { Pos_8013319C p[4]; };

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
extern s32 game_difficulty_selection;
void __ct__7TObjectFP7TObject(void *, void *);
void *__nw__7TObjectFUl(u32);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void __ct__8TAdRayGCFv(void *, void *);
void __ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void __ct__13TAdTitleTexGCFv(void *, void *);
void __ct__14TAdSelectTxtGCFP7TObjectPvPv(void *, void *, void *, int);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
extern Ents_8013319C level_select_entry_table;
extern Pos_8013319C lbl_8043ED58[];
extern Poss_8013319C level_select_position_table;
extern u8 __vt__12TLevelSelect[];
extern s32 level_select_class_name;
extern void *tl_01;
Self_8013319C *__ct__12TLevelSelectFv(Self_8013319C *self);
void TLevelSelect::render() {  }
int count_unlocked_difficulties__12TLevelSelectFv(void) {
    u8 f;
    int n;
    f = 0;
    if (TLevelSelect::get_difficulty_flag_bit(0, 0x35) != 0 || TLevelSelect::get_difficulty_flag_bit(0, 0x57) != 0) {
        f = 1;
    }
    n = f;
    f = 0;
    if (TLevelSelect::get_difficulty_flag_bit(1, 0x37) != 0 || TLevelSelect::get_difficulty_flag_bit(1, 0x57) != 0) {
        f = 1;
    }
    n += f;
    f = 0;
    if (TLevelSelect::get_difficulty_flag_bit(2, 0x37) != 0 || TLevelSelect::get_difficulty_flag_bit(2, 0x57) != 0) {
        f = 1;
    }
    n += f;
    return n;
}
void TLevelSelect::run_task() {
    Self_80133068 *self = (Self_80133068 *)this;
    TAdMultiChgGameModeGC::set_default_camera();
    if (game_difficulty_selection != TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f20)) {
        ((TAdMultiPlyChrSelectGC *)(self->f24))->set_entry_value(1, get_localized_text_entry(0xD, TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f20) + 1));
    }
    game_difficulty_selection = TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f20);
    switch (((TAdSinglePlyChrSelectGC *)(self->f20))->get_selected_slot()) {
    case 1:
        TKeyBoardControl__sub_8000F9CC(0xE);
        break;
    case 0:
    default:
        if (TWindowShortListCtrl__check_controller_button(&controller_physical_port_bank[0x20], 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(&controller_input_state[0x160], 2) != 0) {
            queue_destruction__7TObjectFv(self);
            TAdMultiChgGameModeGC::set_game_mode_changed();
        }
        break;
    }
}
TLevelSelect::~TLevelSelect() {}
Self_8013319C *__ct__12TLevelSelectFv(Self_8013319C *self) {
    void *p;
    u32 i;
    __ct__7TObjectFP7TObject(self, tl_01);
    self->vt = __vt__12TLevelSelect;
    self->f0 = level_select_class_name;
    TKeyBoardControl__sub_8000F90C(2);
    game_difficulty_selection = 0;
    self->count = ((int (*)(void *))count_unlocked_difficulties__12TLevelSelectFv)(self);
    if (self->count == 0) {
        TKeyBoardControl__sub_8000F9CC(0xE);
        queue_destruction__7TObjectFv(self);
        return self;
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
        __ct__10TAdTitleGCFP7TObjectl(p, self, 2);
    }
    if ((p = __nw__7TObjectFUl(0x9C)) != NULL) {
        __ct__13TAdTitleTexGCFv(p, self);
    }
    {
        Ents_8013319C ents = level_select_entry_table;
        for (i = 0; i < self->count + 1; i++) {
            ents.e[i].id = -1;
        }
        if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &ents.e[0], 0);
        }
        if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &ents.e[1], 1);
        }
        if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &ents.e[2], 2);
        }
        if ((p = __nw__7TObjectFUl(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &ents.e[3], 3);
        }
        {
            Pos_8013319C pos = lbl_8043ED58[0];
            Poss_8013319C poss = level_select_position_table;
            p = __nw__7TObjectFUl(0x708);
            if (p != NULL) {
                p = __ct__14TAdSelectCurGCFv(p, self, &poss, &pos);
            }
            self->cur = p;
            ((TLevelSelect *)(self->cur))->add_item_rect(&poss.p[0]);
            p = __nw__7TObjectFUl(0x44);
            if (p != NULL) {
                p = __ct__13TAdGuideTxtGCFv(p, self);
            }
            self->guide = p;
            ((TAdMultiPlyChrSelectGC *)(self->guide))->set_entry_value(0, get_localized_text_entry(0xD, 0));
            ((TAdMultiPlyChrSelectGC *)(self->guide))->set_entry_value(1, get_localized_text_entry(0xD, 1));
            switch (self->count) {
            case 1:
                ((TLevelSelect *)(self->cur))->add_item_rect(&poss.p[1]);
                break;
            case 2:
                ((TLevelSelect *)(self->cur))->add_item_rect(&poss.p[1]);
                ((TLevelSelect *)(self->cur))->add_item_rect(&poss.p[2]);
                break;
            case 3:
                ((TLevelSelect *)(self->cur))->add_item_rect(&poss.p[1]);
                ((TLevelSelect *)(self->cur))->add_item_rect(&poss.p[2]);
                ((TLevelSelect *)(self->cur))->add_item_rect(&poss.p[3]);
                break;
            }
        }
    }
    create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)self, 2, 0.0f);
    return self;
}

}
