#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "types.h"
#include "pso/unk/text_8033F314.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/frontend/TAdMcSelectMcGC.h"

#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

// Screen positions of the two memory card slots, passed to TAdChrSelSlotGC::init_slot by the ctor.
static const CharacterSlotPosition lbl_804770F8 = { 95.0f, 118.0f };
static const CharacterSlotPosition lbl_80477100 = { 381.0f, 118.0f };
const char *TAdMcSelectGC__class_name = "TAdMcSelectGC";
TAdMcSelectGC *TAdMcSelectGC__instance;

void TAdMcSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void TAdMcSelectGC::update_state() {
    TAdMcSelectCursorGC *cursor = TAdMcSelectGC::get_mc_count();
    if (cursor != NULL) {
        cursor->sub_8032A140();
    }
}

s32 TAdMcSelectGC::get_selected_slot_index() {
    s32 index;
    TAdMcSelectCursorGC *cursor = TAdMcSelectGC::get_mc_count();
    index = 0;
    if (cursor != NULL) {
        index = cursor->get_slot_index();
    }
    return index;
}

void TAdMcSelectGC::select_if_mc_present() {
    TAdMcSelectCursorGC *cursor = TAdMcSelectGC::get_mc_count();
    if (cursor != NULL) {
        cursor->sub_8032A15C();
    }
}

void TAdMcSelectGC::run_task() {

    switch (this->m_1c) {
    case 0:
        this->m_1c = 1;
        return;
    case 1:
        return;
    }
}

TAdMcSelectGC::~TAdMcSelectGC() {
    if (TAdMcSelectGC__instance != NULL) {
        TAdMcSelectGC__instance = NULL;
    }
}

TAdMcSelectGC::TAdMcSelectGC(TObject *parent) : TObject(parent) {
    TAdBackGC *back;
    TAdBackTxtGC *txt;
    TAdTitleGC *title;
    TAdMcSelectMcGC *mc;
    s32 i;
    s32 j;
    m_name = TAdMcSelectGC__class_name;
    m_28 = 0;
    m_1c = 0;
    m_24 = 0;
    m_2c = 0;
    slot_gc = 0;
    back = new TAdBackGC(this);
    txt = new TAdBackTxtGC(this);
    back->set_depth(-160.0f);
    back->set_field_20(0);
    txt->set_depth(0.006666667f);
    txt->set_field_24(0);
    title = new TAdTitleGC(this, 0xD);
    title->set_field_134(0);
    create_draw_line_ctrl(this, 0x16, 0.0f)->sub_8032A180(0);
    create_draw_line_ctrl(this, 0x17, 0.0f)->sub_8032A180(0);
    slot_gc = new TAdChrSelSlotGC(this);
    slot_gc->set_select_index(0);
    slot_gc->init_slot(0, (void *)&lbl_804770F8);
    slot_gc->init_slot(1, (void *)&lbl_80477100);
    for (i = 0; i < 2; i++) {
        mc = new TAdMcSelectMcGC(this, i);
        mc->set_field_0x1c(0);
    }
    TAdMcSelectCursorGC::get_instance(this)->set_field_13c(0);
    for (j = 0; j < 2; j++) {
        fn_8033F314((saddr)this, j);
    }
}


TAdMcSelectGC *TAdMcSelectGC::create(TObject *parent) {
    TAdMcSelectGC__instance = new TAdMcSelectGC(parent);
    return TAdMcSelectGC__instance;
}


void TAdMcSelectGC::open() { TLobby__sub_802C78EC(); TAdMcSelectMcGC::release_selected_entry(); TAdMcSelectCursorGC::release_cursor_entry(); }
void TAdMcSelectGC::close() { TAdMcSelectCursorGC::init_resource(); TAdMcSelectMcGC::init_memorycard(); TLobby__sub_802C7920(); }
void TAdMcSelectCursorGC::sub_8032A140() { m_1c = 0; }

TAdMcSelectCursorGC *TAdMcSelectGC::get_mc_count() { return TAdMcSelectCursorGC__instance; }

s32 TAdMcSelectCursorGC::get_slot_index() { return selected_slot; }
void TAdMcSelectCursorGC::sub_8032A15C() { m_1c = 1; }
void TAdMcSelectCursorGC::set_field_13c(s32 v) { m_13c = v; }
void TAdMcSelectMcGC::set_field_0x1c(s32 v) { pad_1c = v; }
void TAdChrSelSlotGC::set_select_index(s32 v) { enabled = v; }
void TAdDrawLineCtrl::sub_8032A180(s32 mode) { render_mode = mode; }

void TAdTitleGC::set_field_134(s32 value) {
    render_direct = value;
    draw_line_ctrl->sub_8032A180(value);
}

void TAdBackTxtGC::set_field_24(s32 render_pass) { m_24 = render_pass; }
void TAdBackTxtGC::set_depth(f32 value) { m_depth = value; }
void TAdBackGC::set_field_20(s32 render_pass) { m_20 = render_pass; }
void TAdBackGC::set_depth(f32 value) { m_depth = value; }
