#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubLog.h"
#include "pso/unk/text_8026A93C.h"
#include "pso/misc/TWindowCtrl_8024ADAC.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdScrollWinGC_8026A5F8.h"
#include "pso/unk/text_80076BC4.h"

#include "pso/misc/TWindowChat.h"
#include "pso/ui/TAdScrollWinGC.h"

#pragma readonly_strings on

extern "C" {
const char *TWindowSubLog__class_name = "TWindowSubLog";
}


struct VBase_18_204a81 { char pad[0x18]; };

struct VObj_18_204a81 : VBase_18_204a81 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

struct RecoveredGlobal_8027AF58_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Lg_8027B194 { s32 f0; u8 pad4[0x14]; void *vt; void *f1c; void *f20; s32 f24; void *f28; u8 f2c[0x10]; };

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
s32 is_flag_set__11TLoadingCurFv(void *, int);
s32 is_on_current_screen__11TCameraCtrlFv(int, int);
s32 play_sound_effect(int, int, int, int);
s32 TWindowCtrl__sub_8024701C(int);
void TWindowChat__sub_80247DFC(u8 *arg0);
void TWindowChat__sub_80247E50(u8 *arg0);
extern RecoveredGlobal_8027AF58_lbl_8050E208 controller_input_state;
extern u8 lbl_8044F9C8[];
extern u8 lbl_8044F9D0[];
extern const char *TWindowSubLog__class_name;
int show_child_window__17TWindowMainMenu4PFv(void*);
int update_trade_submenu__15TWindowMainMenuFv(void*);

void TWindowSubLog::render() {  }

typedef char RecoveredGlobal_8027AF58_lbl_8050E208_size[sizeof(RecoveredGlobal_8027AF58_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubLog::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r3;
    if ((((TWindowChat *)(this->m_28))->is_mode_bit4() != 0) && (chat_accept_submission((s32)(arg0 + 0x2C)) != 0)) {
        TWindowChat__sub_80247E50((u8 *)this->m_28);
    }
    if (((TWindowChat *)(this->m_28))->is_visible() != 0) {
        TWindowChat__sub_80247DFC((u8 *)this->m_28);
    }
    if (TWindowCtrl__sub_8024701C(this->m_28) != 0) {
        TWindowSubLog__sub_8026A664((*(u8 * *)&this->m_24), 200.0f);
        return;
    }
    TWindowSubLog__sub_8026A664((*(u8 * *)&this->m_24), 408.0f);
    temp_r31 = (u8 *)&controller_input_state.value + 0x20;
    if ((is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x10) != 0) || (is_flag_set__11TLoadingCurFv((void *) ((u8 *)&controller_input_state.value + 0x160), 0x10) != 0)) {
        fn_8026A61C((*(u8 * *)&this->m_24), -6.0f);
    }
    if ((is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x20) != 0) || (is_flag_set__11TLoadingCurFv((void *) ((u8 *)&controller_input_state.value + 0x160), 0x20) != 0)) {
        ((TAdScrollWinGC *)(this->m_24))->advance_scroll(6.0f);
    }
    temp_r3 = (u8 *)this->m_24;
    if ((*(f32 *)((s8 *)temp_r3 + 0x3C) == *(f32 *)((s8 *)temp_r3 + 0x4C)) && ((TWindowShortListCtrl__check_controller_button((int)temp_r31, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0))) {
        play_sound_effect(0x52F16, 0, 0, 0);
        ((VObj_18_204a81 *)(this->m_20))->m7();
        ((TWindowSubLog *)(this->m_20))->clear_flag4c_bit8();
    }
}

}
TWindowSubLog::~TWindowSubLog() {
    if (*(void **)((s8 *)this + 0x28) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x28)); this->m_28 = 0; }
    if (*(void **)((s8 *)this + 0x24) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x24)))->close(); this->m_24 = 0; }
    if (*(void **)((s8 *)this + 0x20) != NULL) { ((TWindowSubLog *)(*(void **)((s8 *)this + 0x20)))->clear_flag4c_bit8(); ((TWindowSubLog *)(*(void **)((s8 *)this + 0x20)))->cleanup(); }
    TWindowCtrl__sub_8024ADF0((s32)(*(void **)((s8 *)this + 0x1C)));
}
TWindowSubLog::TWindowSubLog(TObject *arg1, void *arg2) : TObject(arg1) {
    void *w;
    ((Lg_8027B194 *)this)->f0 = ((s32)TWindowSubLog__class_name);
    ((Lg_8027B194 *)this)->f20 = arg1;
    ((Lg_8027B194 *)this)->f1c = arg2;
    TWindowCtrl__sub_8024ADAC((s32)(((Lg_8027B194 *)this)->f1c));
    fn_8027B288((void*)(((Lg_8027B194 *)this)->f20));
    ((TWindowSubLog *)(((Lg_8027B194 *)this)->f20))->set_flag4c_bit8();
    ((Lg_8027B194 *)this)->f24 = (s32)create_message_log_window((s32)lbl_8044F9C8, (s32)lbl_8044F9D0, (s32)(((Lg_8027B194 *)this)->f1c));
    w = new TWindowChat((TObject *)((Lg_8027B194 *)this), (void *)((Lg_8027B194 *)this)->f2c);
    ((Lg_8027B194 *)this)->f28 = w;
    fn_8027B2A8((void*)(((Lg_8027B194 *)this)->f28));
}

void TWindowSubLog::clear_flag4c_bit8() { this->m_4c &= 0xfffffff7; }
int TWindowSubLog::cleanup() { return show_child_window__17TWindowMainMenu4PFv(this); }
void TWindowSubLog::set_flag4c_bit8() { this->m_4c |= 0x8; }
int fn_8027B288(void* p) { return update_trade_submenu__15TWindowMainMenuFv(p); }
void fn_8027B2A8(void* p) { *(u16*)((char*)p + 0x1e) |= 0x200; }
