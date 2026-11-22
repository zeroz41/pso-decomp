#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/unk/text_8033F314.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/frontend/TAdMcSelectMcGC.h"

#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

// Screen positions of the two memory card slots, passed to TAdChrSelSlotGC::init_slot by the ctor.
static const f32 lbl_804770F8[2] = { 95.0f, 118.0f };
static const f32 lbl_80477100[2] = { 381.0f, 118.0f };
const char *TAdMcSelectGC__class_name = "TAdMcSelectGC";
void *TAdMcSelectGC__instance;

struct Self_80329EC8 {
    const char *f0;
    u8 pad4[0x14];
    void *vt;
    s32 f1C;
    u8 pad20[4];
    s32 f24;
    s32 f28;
    s32 f2C;
    void *f30;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
void *__ct__15TAdChrSelSlotGCFP7TObject(void *, void *);
void TAdMcSelectGC__sub_8032A180(void *, s32);

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
    s32 var_r0;
    u8 *mc_count;
    mc_count = (u8 *)(((saddr)TAdMcSelectGC::get_mc_count()));
    var_r0 = 0;
    if (mc_count != NULL) {
        var_r0 = ((TAdMcSelectGC *)mc_count)->get_slot_index();
    }
    return var_r0;
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

}
TAdMcSelectGC::~TAdMcSelectGC() {
    if (TAdMcSelectGC__instance != NULL) {
        TAdMcSelectGC__instance = NULL;
    }
}

#define self ((Self_80329EC8 *)this)
TAdMcSelectGC::TAdMcSelectGC(TObject *parent) : TObject(parent) {
    TAdBackGC *back;
    TAdBackTxtGC *txt;
    TAdTitleGC *title;
    void *p;
    s32 i;
    s32 j;
    self->f0 = TAdMcSelectGC__class_name;
    self->f28 = 0;
    self->f1C = 0;
    self->f24 = 0;
    self->f2C = 0;
    self->f30 = 0;
    back = new TAdBackGC((TObject *)self);
    txt = new TAdBackTxtGC((TObject *)self);
    back->set_depth(-160.0f);
    back->set_field_20(0);
    txt->set_depth(0.006666667f);
    txt->set_field_24(0);
    title = new TAdTitleGC((TObject *)self, 0xD);
    title->set_field_134(0);
    TAdMcSelectGC__sub_8032A180(create_draw_line_ctrl((TObject *)self, 0x16, 0.0f), 0);
    TAdMcSelectGC__sub_8032A180(create_draw_line_ctrl((TObject *)self, 0x17, 0.0f), 0);
    p = TObject::operator new(0x128);
    if (p != NULL) {
        p = __ct__15TAdChrSelSlotGCFP7TObject(p, self);
    }
    self->f30 = p;
    ((TAdMcSelectGC *)(self->f30))->set_select_index(0);
    ((TAdMcSelectGC *)(self->f30))->init_slot(0, (void *)lbl_804770F8);
    ((TAdMcSelectGC *)(self->f30))->init_slot(1, (void *)lbl_80477100);
    for (i = 0; i < 2; i++) {
        p = new TAdMcSelectMcGC((TObject *)self, i);
        ((TAdMcSelectGC *)p)->set_field_0x1c(0);
    }
    ((TAdMcSelectGC *)(TAdMcSelectCursorGC::get_instance((saddr)self)))->set_field_13c(0);
    for (j = 0; j < 2; j++) {
        fn_8033F314((saddr)self, j);
    }
}
#undef self


void *TAdMcSelectGC::create(void *arg0) {
    void *o;
    o = new TAdMcSelectGC((TObject *)arg0);
    TAdMcSelectGC__instance = o;
    return o;
}

void TAdMcSelectGC::open() { TLobby__sub_802C78EC(); TAdMcSelectMcGC::release_selected_entry(); TAdMcSelectCursorGC::release_cursor_entry(); }
void TAdMcSelectGC::close() { TAdMcSelectCursorGC::init_resource(); TAdMcSelectMcGC::init_memorycard(); TLobby__sub_802C7920(); }
void TAdMcSelectCursorGC::sub_8032A140() { m_1c = 0; }

extern TAdMcSelectCursorGC *TAdMcSelectCursorGC__instance;
TAdMcSelectCursorGC *TAdMcSelectGC::get_mc_count() { return TAdMcSelectCursorGC__instance; }

s32 TAdMcSelectGC::get_slot_index() { return *(s32 *)&this->_pad20; }
void TAdMcSelectCursorGC::sub_8032A15C() { m_1c = 1; }
void TAdMcSelectGC::set_field_13c(s32 v) { *(s32*)((char*)this + 0x13c) = v; }
void TAdMcSelectGC::set_field_0x1c(s32 v) { this->m_1c = v; }
void TAdMcSelectGC::set_select_index(s32 v) { *(s32*)((char*)this + 0x124) = v; }
void TAdMcSelectGC__sub_8032A180(void* p, s32 v) { *(s32*)((char*)p + 0x28) = v; }

void TAdTitleGC::set_field_134(s32 value) {
    render_direct = value;
    TAdMcSelectGC__sub_8032A180(draw_line_ctrl, value);
}

void TAdBackTxtGC::set_field_24(s32 v) { m_24 = v; }
void TAdBackTxtGC::set_depth(f32 v) { m_depth = v; }
void TAdBackGC::set_field_20(s32 v) { m_20 = v; }
void TAdBackGC::set_depth(f32 v) { m_depth = v; }

