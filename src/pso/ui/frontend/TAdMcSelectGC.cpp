#include "types.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"

#include "pso/system/task/TMainTask.h"

struct Self_80329EC8 {
    s32 f0;
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
void __ct__7TObjectFP7TObject(void *, void *);
void *__ct__9TAdBackGCFv(void *, void *);
void *__ct__12TAdBackTxtGCFv(void *, void *);
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, s32);
void *__ct__15TAdChrSelSlotGCFP7TObject(void *, void *);
void TAdMcSelectGC__sub_8032A180(void *, s32);
void *__ct__15TAdMcSelectMcGCFv(void *, void *, s32);
s32 fn_8033F314(s32 arg0, s32 arg1);
extern u8 lbl_804770F8[];
extern u8 lbl_80477100[];
extern s32 __vt__13TAdMcSelectGC[];
extern s32 lbl_805D41C8;
Self_80329EC8 *TAdMcSelectGC__ct(Self_80329EC8 *self, void *parent);
int TAdMcSelectGC__sub_8032A140();
int TAdMcSelectGC__sub_8032A15C();

void TAdMcSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void TAdMcSelectGC::update_state() {
    if (TAdMcSelectGC::get_mc_count() != 0U) {
        TAdMcSelectGC__sub_8032A140();
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
    if (TAdMcSelectGC::get_mc_count() != 0U) {
        TAdMcSelectGC__sub_8032A15C();
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

extern u32 TAdMcSelectGC__instance;

}
TAdMcSelectGC::~TAdMcSelectGC() {
    if ((u32) TAdMcSelectGC__instance != 0U) {
        TAdMcSelectGC__instance = 0U;
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
    self->f0 = lbl_805D41C8;
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
    ((TAdMcSelectGC *)(self->f30))->init_slot(0, lbl_804770F8);
    ((TAdMcSelectGC *)(self->f30))->init_slot(1, lbl_80477100);
    for (i = 0; i < 2; i++) {
        p = __nw__7TObjectFUl(0x134);
        if (p != NULL) {
            p = __ct__15TAdMcSelectMcGCFv(p, self, i);
        }
        ((TAdMcSelectGC *)p)->set_field_0x1c(0);
    }
    ((TAdMcSelectGC *)(TAdMcSelectCursorGC::get_instance((s32)self)))->set_field_13c(0);
    for (j = 0; j < 2; j++) {
        fn_8033F314((s32)self, j);
    }
    return self;
}

