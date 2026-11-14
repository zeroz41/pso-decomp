#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"

#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"

struct VBase_18_fbe024 { char pad[0x18]; };

struct VObj_18_fbe024 : VBase_18_fbe024 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual u32 m8();
};

struct RecoveredGlobal_80329830_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80329830_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Obj_80329AA8 { const char *f0; u8 pad[0x14]; void *vt; s32 f1C; u8 pad2[4]; s32 f24; s32 f28; s32 f2C; void *cur; s32 f34; };

struct Pos_803296E8 { f32 x, y; };

static const Pos_803296E8 agreement_item_rect_table[2] = {{89.0f, 394.0f}, {89.0f, 414.0f}};
static const Pos_803296E8 lbl_804770A0 = {462.0f, 18.0f};
const char *lbl_805D41B8 = "TAdAgreementBaseGC";
static const Pos_803296E8 lbl_804770BC = {85.0f, 384.0f};
static const Pos_803296E8 lbl_804770C4 = {470.0f, 60.0f};

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
extern RecoveredGlobal_80329830_lbl_8050E208 controller_input_state;
extern RecoveredGlobal_80329830_lbl_8050E3B8 controller_physical_port_bank;
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *, void *);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, TObject *, void *, void *);
extern s32 __vt__18TAdAgreementBaseGC[];
Obj_80329AA8 *TAdAgreementBaseGC__ct(Obj_80329AA8 *arg0, void *arg1);
void *get_localized_text_entry(int, u32);
s32 render_status_line__15TAdSubPlyItemGCFi(void *, int, f32, f32, f32);
void draw_window_frame__11TWindowBaseFPv();

void TAdAgreementBaseGC::check_main_task_state() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

#pragma push
#pragma fp_contract on
void TAdAgreementBaseGC::draw_agreement_text() {
    Pos_803296E8 pos[2];
    u32 i;
    draw_window_frame__11TWindowBaseFPv();
    for (i = 0; i < 2; i++) {
        pos[i].x = 320.0f - (f32) (calc_text_width((char *)(get_localized_text_entry(0x1B, i))) >> 1);
        pos[i].y = 20.0f * (f32) i + 394.0f;
        render_status_line__15TAdSubPlyItemGCFi(get_localized_text_entry(0x1B, i), -1, pos[i].x, pos[i].y, 0.8f);
    }
}
#pragma pop

void TAdAgreementBaseGC::vfunc_9() { this->m_1c = 4; }

typedef char RecoveredGlobal_80329830_lbl_8050E208_size[sizeof(RecoveredGlobal_80329830_lbl_8050E208) == 0x1B0 ? 1 : -1];
typedef char RecoveredGlobal_80329830_lbl_8050E3B8_size[sizeof(RecoveredGlobal_80329830_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

void TAdAgreementBaseGC::create_agreement_callback() {
    TAdEnterSerialAccessGC::create_callback((void *)&lbl_804770BC, (void *)&lbl_804770C4, (void *)TAdAgreementBaseGC::draw_agreement_text);
}

void TAdAgreementBaseGC::update_state() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    *(s32 *)&this->_pad20 = (s32) *(s32 *)&this->m_1c;
    switch (*(s32 *)&this->m_1c) {
    case 0:
        this->m_2c = ((VObj_18_fbe024 *)(arg0))->m8();
        *(s32 *)&this->m_1c = 1;
        break;
    case 1:
        if (((TAdSinglePlyChrSelectGC *)(*(s32 *)&this->m_30))->get_selected_slot() == 1) {
            switch (TAdSinglePlyChrSelectGC__sub_801334DC((void *)(*(s32 *)&this->m_30))) {
            case 0:
                *(s32 *)&this->m_1c = 2;
                *(s32 *)&this->m_24 = 3;
                break;
            case 1:
                *(s32 *)&this->m_1c = 2;
                *(s32 *)&this->m_24 = 4;
                break;
            }
        } else if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_physical_port_bank.value + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            *(s32 *)&this->m_1c = 2;
            *(s32 *)&this->m_24 = 5;
        }
        break;
    case 2:
        if ((u32) this->m_2c != 0U) {
            ((TWindowBase *)(*(void * *)&this->m_2c))->close();
            this->m_2c = 0U;
        }
        this->vfunc_6();
        temp_r4 = *(s32 *)&this->m_28 + 1;
        *(s32 *)&this->m_28 = temp_r4;
        if ((f32) temp_r4 > 4.5f) {
            *(s32 *)&this->m_1c = (s32) *(s32 *)&this->m_24;
        }
        break;
    case 3:
        this->vfunc_7();
        break;
    case 4:
        this->vfunc_8();
        break;
    case 5:
        this->vfunc_9();
        break;
    }
    if ((s32) *(s32 *)&this->_pad20 != (s32) *(s32 *)&this->m_1c) {
        *(s32 *)&this->m_28 = 0;
    }
}

}
TAdAgreementBaseGC::~TAdAgreementBaseGC() {
    if (*(void **)((s8 *)this + 0x2C) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x2C)))->queue_destruction(); this->m_2c = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x30)))->queue_destruction(); this->m_30 = 0; }
}


Obj_80329AA8 *TAdAgreementBaseGC__ct(Obj_80329AA8 *arg0, void *arg1) {
    void *p;
    __ct__7TObjectFP7TObject(arg0, arg1);
    arg0->vt = ((s32 *)&__vt__18TAdAgreementBaseGC);
    arg0->f0 = lbl_805D41B8;
    arg0->f28 = 0;
    arg0->f1C = 0;
    arg0->f24 = 0;
    arg0->f34 = 0;
    arg0->f2C = 0;
    arg0->cur = 0;
    p = __nw__7TObjectFUl(0x24);
    if (p != 0) {
        __ct__9TAdBackGCFv(p, arg0);
    }
    p = __nw__7TObjectFUl(0x28);
    if (p != 0) {
        __ct__12TAdBackTxtGCFv(p, arg0);
    }
    p = __nw__7TObjectFUl(0x708);
    if (p != 0) {
        p = __ct__14TAdSelectCurGCFv(p, tl_clipout, (void *)agreement_item_rect_table, (void *)&lbl_804770A0);
    }
    arg0->cur = p;
    ((TLevelSelect *)(arg0->cur))->add_item_rect((void *)&agreement_item_rect_table[0]);
    ((TLevelSelect *)(arg0->cur))->add_item_rect((void *)&agreement_item_rect_table[1]);
    fn_80329BAC(arg0->cur);
    ((TLobby *)(arg0->cur))->set_ad_field(1);
    return arg0;
}

void TAdAgreementBaseGC::vfunc_6() {  }
void TAdAgreementBaseGC::vfunc_7() {  }
void TAdAgreementBaseGC::vfunc_8() {  }
void fn_80329BAC(void* p) { *(s32*)((char*)p + 0xb8) = 1; }

