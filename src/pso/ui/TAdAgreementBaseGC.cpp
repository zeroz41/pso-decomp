#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TMainTask.h"
#include "pso/ui/TAdAgreementBaseGC.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowSubStatusDisp_80144B14.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801334D4.h"

#include "pso/TLevelSelect.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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

struct Obj_80329AA8 { s32 f0; u8 pad[0x14]; void *vt; s32 f1C; u8 pad2[4]; s32 f24; s32 f28; s32 f2C; void *cur; s32 f34; };

struct Pos_803296E8 { f32 x, y; };

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
extern RecoveredGlobal_80329830_lbl_8050E208 controller_input_state;
extern RecoveredGlobal_80329830_lbl_8050E3B8 controller_physical_port_bank;
extern const f32 lbl_805DF710;
extern char lbl_804770BC[];
extern char lbl_804770C4[];
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *, void *);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, TObject *, void *, void *);
extern u8 agreement_item_rect_table[];
extern u8 lbl_804770A0[];
extern s32 __vt__18TAdAgreementBaseGC[];
extern s32 lbl_805D41B8;
Obj_80329AA8 *TAdAgreementBaseGC__ct(Obj_80329AA8 *arg0, void *arg1);
void *get_localized_text_entry(int, u32);
s32 render_status_line__15TAdSubPlyItemGCFi(void *, int, f32, f32, f32);
void draw_window_frame__11TWindowBaseFPv();
extern const f32 lbl_805DF700;
extern const f32 lbl_805DF704;
extern const f32 lbl_805DF708;
extern const f32 lbl_805DF70C;

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
        pos[i].x = lbl_805DF700 - (f32) (calc_text_width((char *)(get_localized_text_entry(0x1B, i))) >> 1);
        pos[i].y = lbl_805DF708 * (f32) i + lbl_805DF704;
        render_status_line__15TAdSubPlyItemGCFi(get_localized_text_entry(0x1B, i), -1, pos[i].x, pos[i].y, lbl_805DF70C);
    }
}
#pragma pop

void TAdAgreementBaseGC::vfunc_9() { this->m_1c = 4; }

typedef char RecoveredGlobal_80329830_lbl_8050E208_size[sizeof(RecoveredGlobal_80329830_lbl_8050E208) == 0x1B0 ? 1 : -1];
typedef char RecoveredGlobal_80329830_lbl_8050E3B8_size[sizeof(RecoveredGlobal_80329830_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

void TAdAgreementBaseGC::create_agreement_callback() {
    TAdEnterSerialAccessGC::create_callback(lbl_804770BC, lbl_804770C4, (void *)TAdAgreementBaseGC::draw_agreement_text);
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
        if ((f32) temp_r4 > lbl_805DF710) {
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
    if (*(void **)((s8 *)this + 0x2C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x2C)); this->m_2c = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x30)); this->m_30 = 0; }
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
        p = __ct__14TAdSelectCurGCFv(p, tl_clipout, agreement_item_rect_table, lbl_804770A0);
    }
    arg0->cur = p;
    ((TLevelSelect *)(arg0->cur))->add_item_rect(agreement_item_rect_table);
    ((TLevelSelect *)(arg0->cur))->add_item_rect(agreement_item_rect_table + 8);
    fn_80329BAC(arg0->cur);
    ((TLobby *)(arg0->cur))->set_ad_field(1);
    return arg0;
}

void TAdAgreementBaseGC::vfunc_6() {  }
void TAdAgreementBaseGC::vfunc_7() {  }
void TAdAgreementBaseGC::vfunc_8() {  }
void fn_80329BAC(void* p) { *(s32*)((char*)p + 0xb8) = 1; }

