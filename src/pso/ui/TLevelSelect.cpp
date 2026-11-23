#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"

#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"

struct Self_80133068 { u8 pad[0x20]; saddr f20; saddr f24; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Self_8013319C {
    const char *f0;
    u8 pad4[0x14];
    void *vt;
    s32 count;
    void *cur;
    void *guide;
};

struct Ent_8013319C { s32 id; f32 b; f32 c; };

struct Ents_8013319C { Ent_8013319C e[4]; };

struct Poss_8013319C { NJS_POINT2 p[4]; };

const char *level_select_class_name = "TLevelSelect";

extern "C" {
s32 game_difficulty_selection;
void __ct__7TObjectFP7TObject(void *, void *);
void __ct__14TAdSelectTxtGCFP7TObjectP18TAdSelectTxtLayoutl(void *, void *, void *, int);
extern u8 __vt__12TLevelSelect[];
extern void *tl_01;
Self_8013319C *__ct__12TLevelSelectFv(Self_8013319C *self);
void TLevelSelect::render() {  }
int TLevelSelect::count_unlocked_difficulties(void) {
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
    if (game_difficulty_selection != reinterpret_cast<TAdSelectCurGC *>(self->f20)->selection_index()) {
        ((TAdGuideTxtGC *)(self->f24))->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0xD, reinterpret_cast<TAdSelectCurGC *>(self->f20)->selection_index() + 1)));
    }
    game_difficulty_selection = reinterpret_cast<TAdSelectCurGC *>(self->f20)->selection_index();
    switch (((TAdSelectCurGC *)(self->f20))->confirmation_result()) {
    case 1:
        request_main_phase(0xE);
        break;
    case 0:
    default:
        if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            ((TObject *)self)->queue_destruction();
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
    self->count = ((int (*)(void *))TLevelSelect::count_unlocked_difficulties)(self);
    if (self->count == 0) {
        request_main_phase(0xE);
        ((TObject *)self)->queue_destruction();
        return self;
    }
    new TAdBackGC((TObject *)self);
    new TAdBackTxtGC((TObject *)self);
    new TAdRayGC((TObject *)self);
    new TAdTitleGC((TObject *)self, 2);
    new TAdTitleTexGC((TObject *)self);
    {
        Ents_8013319C ents = {{
            { 0x44FFFFFF, 238.0f, 145.0f }, { 0x44FFFFFF, 208.0f, 197.0f },
            { 0x44FFFFFF, 178.0f, 249.0f }, { 0x44FFFFFF, 148.0f, 301.0f },
        }};
        for (i = 0; i < self->count + 1; i++) {
            ents.e[i].id = -1;
        }
        if ((p = TObject::operator new(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectP18TAdSelectTxtLayoutl(p, self, &ents.e[0], 0);
        }
        if ((p = TObject::operator new(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectP18TAdSelectTxtLayoutl(p, self, &ents.e[1], 1);
        }
        if ((p = TObject::operator new(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectP18TAdSelectTxtLayoutl(p, self, &ents.e[2], 2);
        }
        if ((p = TObject::operator new(0xE0)) != NULL) {
            __ct__14TAdSelectTxtGCFP7TObjectP18TAdSelectTxtLayoutl(p, self, &ents.e[3], 3);
        }
        {
            NJS_POINT2 pos = { 302.0f, 28.0f };
            Poss_8013319C poss = {{ { 215.0f, 146.0f }, { 185.0f, 198.0f }, { 155.0f, 250.0f }, { 125.0f, 302.0f } }};
            p = new TAdSelectCurGC(reinterpret_cast<TObject *>(self),
                reinterpret_cast<const NJS_POINT2 *>(&poss),
                &pos);
            self->cur = p;
            ((TAdSelectCurGC *)(self->cur))->append_entry(&poss.p[0]);
            p = new TAdGuideTxtGC(reinterpret_cast<TObject *>(self));
            self->guide = p;
            ((TAdGuideTxtGC *)(self->guide))->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0xD, 0)));
            ((TAdGuideTxtGC *)(self->guide))->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0xD, 1)));
            switch (self->count) {
            case 1:
                ((TAdSelectCurGC *)(self->cur))->append_entry(&poss.p[1]);
                break;
            case 2:
                ((TAdSelectCurGC *)(self->cur))->append_entry(&poss.p[1]);
                ((TAdSelectCurGC *)(self->cur))->append_entry(&poss.p[2]);
                break;
            case 3:
                ((TAdSelectCurGC *)(self->cur))->append_entry(&poss.p[1]);
                ((TAdSelectCurGC *)(self->cur))->append_entry(&poss.p[2]);
                ((TAdSelectCurGC *)(self->cur))->append_entry(&poss.p[3]);
                break;
            }
        }
    }
    create_draw_line_ctrl((TObject *)self, 2, 0.0f);
    return self;
}

}
