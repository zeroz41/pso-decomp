#include "types.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/frontend/TAdMcSelectMcGC.h"

#include "pso/system/task/TMainTask.h"

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
void *create_draw_line_ctrl__13TAdMcSelectGCFiif(void *, s32, f32);
void *__nw__7TObjectFUl(u32);
struct Self_80329EC8 *TAdMcSelectGC__ct(struct Self_80329EC8 *self, void *parent);
void __ct__7TObjectFP7TObject(void *, void *);
void *__ct__9TAdBackGCFv(void *, void *);
void *__ct__12TAdBackTxtGCFv(void *, void *);
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, s32);
void *__ct__15TAdChrSelSlotGCFP7TObject(void *, void *);
void TAdMcSelectGC__sub_8032A180(void *, s32);
s32 fn_8033F314(s32 arg0, s32 arg1);
extern s32 __vt__13TAdMcSelectGC[];

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
    mc_count = (u8 *)(((int)TAdMcSelectGC::get_mc_count()));
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

Self_80329EC8 *TAdMcSelectGC__ct(Self_80329EC8 *self, void *parent) {
    void *back;
    void *txt;
    void *p;
    s32 i;
    s32 j;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = (void *)((s32 *)&__vt__13TAdMcSelectGC);
    self->f0 = TAdMcSelectGC__class_name;
    self->f28 = 0;
    self->f1C = 0;
    self->f24 = 0;
    self->f2C = 0;
    self->f30 = 0;
    back = __nw__7TObjectFUl(0x24);
    if (back != NULL) {
        back = __ct__9TAdBackGCFv(back, self);
    }
    txt = __nw__7TObjectFUl(0x28);
    if (txt != NULL) {
        txt = __ct__12TAdBackTxtGCFv(txt, self);
    }
    ((TAdMcSelectGC *)back)->set_float_1c(-160.0f);
    ((TAdMcSelectGC *)back)->set_field_20(0);
    ((TAdMcSelectGC *)txt)->set_field20(0.006666667f);
    ((TAdMcSelectGC *)txt)->set_field_24(0);
    p = __nw__7TObjectFUl(0x138);
    if (p != NULL) {
        p = __ct__10TAdTitleGCFP7TObjectl(p, self, 0xD);
    }
    ((TAdMcSelectGC *)p)->set_field_134(0);
    TAdMcSelectGC__sub_8032A180(create_draw_line_ctrl__13TAdMcSelectGCFiif(self, 0x16, 0.0f), 0);
    TAdMcSelectGC__sub_8032A180(create_draw_line_ctrl__13TAdMcSelectGCFiif(self, 0x17, 0.0f), 0);
    p = __nw__7TObjectFUl(0x128);
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
    ((TAdMcSelectGC *)(TAdMcSelectCursorGC::get_instance((s32)self)))->set_field_13c(0);
    for (j = 0; j < 2; j++) {
        fn_8033F314((s32)self, j);
    }
    return self;
}


extern "C" {

void *TAdMcSelectGC::create(void *arg0) {
    void *o;
    o = __nw__7TObjectFUl(0x34);
    if (o != NULL) {
        o = TAdMcSelectGC__ct((Self_80329EC8 *)o, arg0);
    }
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

void TAdMcSelectGC::set_field_134(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x134) = arg1;
    TAdMcSelectGC__sub_8032A180((void*)((int) (*(s32 *)((s8 *)arg0 + 0x130))), arg1);
}

void TAdMcSelectGC::set_field_24(s32 v) { this->m_24 = v; }
void TAdMcSelectGC::set_field20(f32 v) { *(f32 *)&this->_pad20 = v; }
void TAdMcSelectGC::set_field_20(s32 v) { *(s32 *)&this->_pad20 = v; }
void TAdMcSelectGC::set_float_1c(f32 v) { *(f32 *)&this->m_1c = v; }

}
