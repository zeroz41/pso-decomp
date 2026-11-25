#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdMcCheckGC.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/frontend/TAdMcSelectMcGC.h"

#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

// Screen positions of the two memory card slots, passed to TAdChrSelSlotGC::init_slot by the ctor.
static const CharacterSlotPosition mc_slot_a_position = { 95.0f, 118.0f };
static const CharacterSlotPosition mc_slot_b_position = { 381.0f, 118.0f };
const char *TAdMcSelectGC__class_name = "TAdMcSelectGC";
TAdMcSelectGC *TAdMcSelectGC::instance;

void TAdMcSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void TAdMcSelectGC::update_state() {
    TAdMcSelectCursorGC *cursor = TAdMcSelectGC::get_mc_count();
    if (cursor != NULL) {
        cursor->unlock_selection();
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
        cursor->lock_selection();
    }
}

void TAdMcSelectGC::run_task() {

    switch (this->state) {
    case 0:
        this->state = 1;
        return;
    case 1:
        return;
    }
}

TAdMcSelectGC::~TAdMcSelectGC() {
    if (TAdMcSelectGC::instance != NULL) {
        TAdMcSelectGC::instance = NULL;
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
    state = 0;
    m_24 = 0;
    m_2c = 0;
    slot_gc = 0;
    back = new TAdBackGC(this);
    txt = new TAdBackTxtGC(this);
    back->set_depth(-160.0f);
    back->set_render_direct(0);
    txt->set_depth(0.006666667f);
    txt->set_render_direct(0);
    title = new TAdTitleGC(this, 0xD);
    title->set_render_direct(0);
    create_draw_line_ctrl(this, 0x16, 0.0f)->set_render_mode(0);
    create_draw_line_ctrl(this, 0x17, 0.0f)->set_render_mode(0);
    slot_gc = new TAdChrSelSlotGC(this);
    slot_gc->set_select_index(0);
    slot_gc->init_slot(0, (void *)&mc_slot_a_position);
    slot_gc->init_slot(1, (void *)&mc_slot_b_position);
    for (i = 0; i < 2; i++) {
        mc = new TAdMcSelectMcGC(this, i);
        mc->set_render_direct(0);
    }
    TAdMcSelectCursorGC::get_instance(this)->set_render_direct(0);
    for (j = 0; j < 2; j++) {
        TAdMcCheckGC::get_instance(this, j);
    }
}


TAdMcSelectGC *TAdMcSelectGC::create(TObject *parent) {
    TAdMcSelectGC::instance = new TAdMcSelectGC(parent);
    return TAdMcSelectGC::instance;
}


void TAdMcSelectGC::open() { TLobby__sub_802C78EC(); TAdMcSelectMcGC::release_selected_entry(); TAdMcSelectCursorGC::release_cursor_entry(); }
void TAdMcSelectGC::close() { TAdMcSelectCursorGC::init_resource(); TAdMcSelectMcGC::init_memorycard(); TLobby__sub_802C7920(); }
void TAdMcSelectCursorGC::unlock_selection() { selection_locked = 0; }

TAdMcSelectCursorGC *TAdMcSelectGC::get_mc_count() { return TAdMcSelectCursorGC::instance; }

s32 TAdMcSelectCursorGC::get_slot_index() { return selected_slot; }
void TAdMcSelectCursorGC::lock_selection() { selection_locked = 1; }
void TAdMcSelectCursorGC::set_render_direct(s32 v) { render_direct = v; }
void TAdMcSelectMcGC::set_render_direct(s32 v) { render_direct = v; }
void TAdChrSelSlotGC::set_select_index(s32 v) { enabled = v; }
void TAdDrawLineCtrl::set_render_mode(s32 mode) { render_mode = mode; }

void TAdTitleGC::set_render_direct(s32 value) {
    render_direct = value;
    draw_line_ctrl->set_render_mode(value);
}

void TAdBackTxtGC::set_render_direct(s32 value) { render_direct = value; }
void TAdBackTxtGC::set_depth(f32 value) { m_depth = value; }
void TAdBackGC::set_render_direct(s32 value) { render_direct = value; }
void TAdBackGC::set_depth(f32 value) { m_depth = value; }
