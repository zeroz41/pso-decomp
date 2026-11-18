#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/unk/text_80299420.h"
#include "pso/object/TObjPathObj.h"

#include "types.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"

struct Obj_802C3288 { u8 pad[0x1C]; s32 f1C; s32 f20; };

struct B_802C3400 { NJS_POINT2 e[2]; };

struct CE_802C3400 { s32 a; f32 x, y; };

struct C_802C3400 { CE_802C3400 e[2]; };

struct Self_802C3400 { const char *name; u8 pad4[0x14]; void *vt; void *f1C; void *f20; };

__declspec(section ".rodata") extern const char TAdStorySelectGC__class_name_string[] = "TAdStorySelectGC";
const char *TAdStorySelectGC__class_name = TAdStorySelectGC__class_name_string;

s32 story_select_cursor;
extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
void play_sound_effect(s32, s32, s32, s32);
extern u8 controller_input_state[];
void __ct__7TObjectFP7TObject(void *, void *);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void __ct__8TAdRayGCFv(void *, void *);
void __ct__10TAdTitleGCFP7TObjectl(void *, void *, s32);
void __ct__14TAdSelectTxtGCFP7TObjectPvPv(void *, void *, void *, s32);
void __ct__13TAdTitleTexGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
void *__ct__13TAdGuideTxtGCFv(void *, void *);
extern void *__vt__16TAdStorySelectGC[];
Self_802C3400 *__ct__16TAdStorySelectGCFv(Self_802C3400 *self, void *parent);
void TAdStorySelectGC::render() {  }
void TAdStorySelectGC::run_task() {
    Obj_802C3288 *self = (Obj_802C3288 *)this;
    TAdMultiChgGameModeGC::set_default_camera();
    if (story_select_cursor != TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f1C)) {
        ((TAdMultiPlyChrSelectGC *)(self->f20))->set_entry_value(1, get_localized_text_entry(0x14, TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f1C) + 1));
    }
    story_select_cursor = TAdSinglePlyChrSelectGC__sub_801334DC((void *)self->f1C);
    switch (((TAdSinglePlyChrSelectGC *)(self->f1C))->get_selected_slot()) {
    case 1:
        switch (TAdStorySelectGC::get_story_select()) {
        case 0:
            TAdStorySelectGC::set_state(0);
            break;
        case 1:
            TAdStorySelectGC::set_state(1);
            break;
        }
        ((TObject *)self)->queue_destruction();
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
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__16TAdStorySelectGC;
    self->name = TAdStorySelectGC__class_name;
    story_select_cursor = 0;
    self->f1C = 0;
    self->f20 = 0;
    if (TAdSinglePlyChrSelectGC::get_data() == 0) {
        TAdMultiChgGameModeGC::request_transition();
        ((TObject *)self)->queue_destruction();
        return self;
    }
    if (TAdSelectGameModeGC::get_mode_data() == 1) {
        TAdStorySelectGC::set_state(0);
        ((TObject *)self)->queue_destruction();
        if (TAdMultiPlyChrSelectGC__sub_80299454() != 0) {
            TAdMultiChgGameModeGC::set_change_game_mode();
        } else {
            TAdMultiChgGameModeGC::set_change_mode_flags();
        }
        return self;
    }
    p = TObject::operator new(0x24);
    if (p != NULL) {
        __ct__9TAdBackGCFv(p, self);
    }
    p = TObject::operator new(0x28);
    if (p != NULL) {
        __ct__12TAdBackTxtGCFv(p, self);
    }
    p = TObject::operator new(0x24);
    if (p != NULL) {
        __ct__8TAdRayGCFv(p, self);
    }
    p = TObject::operator new(0x138);
    if (p != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(p, self, 1);
    }
    p = TObject::operator new(0x9C);
    if (p != NULL) {
        __ct__13TAdTitleTexGCFv(p, self);
    }
    {
        C_802C3400 c = {{{-1, 208.0f, 197.0f}, {-1, 178.0f, 249.0f}}};
        p = TObject::operator new(0xE0);
        if (p != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &c.e[0], 4);
        }
        p = TObject::operator new(0xE0);
        if (p != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectPvPv(p, self, &c.e[1], 5);
        }
        {
        NJS_POINT2 a = {302.0f, 28.0f};
        B_802C3400 b = {{{185.0f, 198.0f}, {155.0f, 250.0f}}};
        p = TObject::operator new(0x708);
        if (p != NULL) {
            p = __ct__14TAdSelectCurGCFv(p, self, &b, &a);
        }
        self->f1C = p;
        ((TLevelSelect *)(self->f1C))->add_item_rect(&b.e[0]);
        ((TLevelSelect *)(self->f1C))->add_item_rect(&b.e[1]);
        }
    }
    p = TObject::operator new(0x44);
    if (p != NULL) {
        p = __ct__13TAdGuideTxtGCFv(p, self);
    }
    self->f20 = p;
    ((TAdMultiPlyChrSelectGC *)((s32)self->f20))->set_entry_value(0, get_localized_text_entry(0x14, 0));
    ((TAdMultiPlyChrSelectGC *)((s32)self->f20))->set_entry_value(1, get_localized_text_entry(0x14, 1));
    create_draw_line_ctrl((TObject *)self, 0xA, 0.0f);
    return self;
}

}
