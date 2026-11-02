#include "pso/TAdStorySelectGC.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/ui/TAdStorySelectGC_8019DC14.h"
#include "pso/unk/text_80299420.h"
#include "pso/object/TObjPathObj.h"

#include "types.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TAdSelectGameModeGC.h"
#include "pso/TLevelSelect.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Obj_802C3288 { u8 pad[0x1C]; s32 f1C; s32 f20; };

struct A_802C3400 { f32 x, y; };

struct B_802C3400 { A_802C3400 e[2]; };

struct CE_802C3400 { s32 a; f32 x, y; };

struct C_802C3400 { CE_802C3400 e[2]; };

struct Self_802C3400 { s32 f0; u8 pad4[0x14]; void *vt; void *f1C; void *f20; };

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void play_sound_effect(s32, s32, s32, s32);
extern u8 controller_input_state[];
extern s32 lbl_805D67C0;
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *, void *);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void __ct__8TAdRayGCFv(void *, void *);
void __ct__10TAdTitleGCFP7TObjectl(void *, void *, s32);
void __ct__14TAdSelectTxtGCFP7TObjectPvPv(void *, void *, void *, s32);
void __ct__13TAdTitleTexGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
s32 get_data__23TAdSinglePlyChrSelectGCFv(s32);
extern C_802C3400 story_select_colors_and_positions;
extern A_802C3400 lbl_804719FC[];
extern B_802C3400 story_select_rect_table;
extern void *__vt__16TAdStorySelectGC[];
extern s32 lbl_805D3EC8;
Self_802C3400 *__ct__16TAdStorySelectGCFv(Self_802C3400 *self, void *parent);
void TAdStorySelectGC::render() {  }
void TAdStorySelectGC::run_task() {
    Obj_802C3288 *self = (Obj_802C3288 *)this;
    TAdMultiChgGameModeGC::set_default_camera();
    if (lbl_805D67C0 != TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f1C)) {
        ((TAdMultiPlyChrSelectGC *)(self->f20))->set_entry_value(1, get_localized_text_entry(0x14, TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f1C) + 1));
    }
    lbl_805D67C0 = TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f1C);
    switch (((TAdSinglePlyChrSelectGC *)(self->f1C))->get_selected_slot()) {
    case 1:
        switch (TAdStorySelectGC__sub_8019DC14()) {
        case 0:
            TAdStorySelectGC::set_state(0);
            break;
        case 1:
            TAdStorySelectGC::set_state(1);
            break;
        }
        queue_destruction__7TObjectFv(self);
        TAdMultiChgGameModeGC::set_change_mode_flags();
        break;
    case 0:
    default:
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            TAdMultiChgGameModeGC::set_game_mode();
        }
        break;
    }
}
TAdStorySelectGC::~TAdStorySelectGC() {}
Self_802C3400 *__ct__16TAdStorySelectGCFv(Self_802C3400 *self, void *parent) {
    void *p;
    s32 id;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__16TAdStorySelectGC;
    id = lbl_805D3EC8;
    self->f0 = id;
    lbl_805D67C0 = 0;
    self->f1C = 0;
    self->f20 = 0;
    if (get_data__23TAdSinglePlyChrSelectGCFv(id) == 0) {
        TAdMultiChgGameModeGC::request_transition();
        queue_destruction__7TObjectFv(self);
        return self;
    }
    if (TAdSelectGameModeGC::get_mode_data() == 1) {
        TAdStorySelectGC::set_state(0);
        queue_destruction__7TObjectFv(self);
        if (TAdMultiPlyChrSelectGC__sub_80299454() != 0) {
            TAdMultiChgGameModeGC::set_change_game_mode();
        } else {
            TAdMultiChgGameModeGC::set_change_mode_flags();
        }
        return self;
    }
    p = __nw__7TObjectFUl(0x24);
    if (p != NULL) {
        __ct__9TAdBackGCFv(p, self);
    }
    p = __nw__7TObjectFUl(0x28);
    if (p != NULL) {
        __ct__12TAdBackTxtGCFv(p, self);
    }
    p = __nw__7TObjectFUl(0x24);
    if (p != NULL) {
        __ct__8TAdRayGCFv(p, self);
    }
    p = __nw__7TObjectFUl(0x138);
    if (p != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(p, self, 1);
    }
    p = __nw__7TObjectFUl(0x9C);
    if (p != NULL) {
        __ct__13TAdTitleTexGCFv(p, self);
    }
    {
        C_802C3400 c = story_select_colors_and_positions;
        p = __nw__7TObjectFUl(0xE0);
        if (p != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &c.e[0], 4);
        }
        p = __nw__7TObjectFUl(0xE0);
        if (p != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &c.e[1], 5);
        }
        {
        A_802C3400 a = lbl_804719FC[0];
        B_802C3400 b = story_select_rect_table;
        p = __nw__7TObjectFUl(0x708);
        if (p != NULL) {
            p = __ct__14TAdSelectCurGCFv(p, self, &b, &a);
        }
        self->f1C = p;
        ((TLevelSelect *)(self->f1C))->add_item_rect(&b.e[0]);
        ((TLevelSelect *)(self->f1C))->add_item_rect(&b.e[1]);
        }
    }
    p = __nw__7TObjectFUl(0x44);
    if (p != NULL) {
        p = __ct__13TAdGuideTxtGCFv(p, self);
    }
    self->f20 = p;
    ((TAdMultiPlyChrSelectGC *)((s32)self->f20))->set_entry_value(0, get_localized_text_entry(0x14, 0));
    ((TAdMultiPlyChrSelectGC *)((s32)self->f20))->set_entry_value(1, get_localized_text_entry(0x14, 1));
    create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)self, 0xA, 0.0f);
    return self;
}

}
