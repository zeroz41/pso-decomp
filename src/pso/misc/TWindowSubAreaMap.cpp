#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubAreaMap.h"
#include "pso/misc/TWindowSubComCard_80244774.h"

#include "pso/misc/TWindowSubAreaMapDisp.h"
#include "pso/misc/TRaderMapCore.h"

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

struct RecoveredGlobal_80271480_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_802715F0_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 play_sound_effect(int, int, int, int);
extern RecoveredGlobal_80271480_lbl_8050E208 controller_input_state;
s32 is_flag_set__11TLoadingCurFv(void *, int);
s32 is_on_current_screen__11TCameraCtrlFv(int, int);
extern const f32 lbl_805DD478;
extern const f32 lbl_805DD47C;
void *__nw__7TObjectFUl(int);

void TWindowSubAreaMap::render() {  }


typedef char RecoveredGlobal_80271480_lbl_8050E208_size[sizeof(RecoveredGlobal_80271480_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubAreaMap::run_task() {
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        ((VObj_18_204a81 *)(this->m_20))->m7();
    }
}

}
TWindowSubAreaMap::~TWindowSubAreaMap() {
    if (*(void **)((s8 *)this + 0x24) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x24)))->close(); this->m_24 = 0; }
}
extern void *TWindowSubAreaMap__name;
TWindowSubAreaMap::TWindowSubAreaMap(TObject *object, void *arg2) : TObject(object) {
    void *o;
    *(void * *)&this->m_name = TWindowSubAreaMap__name;
    *(void **)((s8 *)this + 0x20) = object;
    *(void **)((s8 *)this + 0x1C) = arg2;
    o = __nw__7TObjectFUl(0x78);
    if (o != NULL) {
        o = TWindowSubAreaMapDisp__ct((TWindowSubAreaMapDisp *)((u8 *)o));
    }
    *(void **)((s8 *)this + 0x24) = o;
}

typedef char RecoveredGlobal_802715F0_lbl_8050E208_size[sizeof(RecoveredGlobal_802715F0_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubAreaMapDisp::update_manual_scroll() {
    u8 *temp_r31;
    if ((s32) this->m_6c != 0) {
        temp_r31 = (u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x20;
        if ((is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x10) != 0) || (is_flag_set__11TLoadingCurFv((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x10) != 0)) {
            this->m_64 = (f32) (this->m_64 + lbl_805DD478);
        }
        if ((is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x20) != 0) || (is_flag_set__11TLoadingCurFv((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x20) != 0)) {
            this->m_64 = (f32) (this->m_64 - lbl_805DD478);
        }
        if ((is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x40) != 0) || (is_flag_set__11TLoadingCurFv((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x40) != 0)) {
            *(f32 *)&this->unk_60 = (f32) (*(f32 *)&this->unk_60 + lbl_805DD478);
        }
        if ((is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x80) != 0) || (is_flag_set__11TLoadingCurFv((void *) ((u8 *)&(*(RecoveredGlobal_802715F0_lbl_8050E208 *)&controller_input_state).value + 0x160), 0x80) != 0)) {
            *(f32 *)&this->unk_60 = (f32) (*(f32 *)&this->unk_60 - lbl_805DD478);
        }
        if (is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x20000) != 0) {
            *(f32 *)&this->unk_68 = (f32) (*(f32 *)&this->unk_68 - lbl_805DD478);
        }
        if (is_on_current_screen__11TCameraCtrlFv((int)temp_r31, 0x10000) != 0) {
            *(f32 *)&this->unk_68 = (f32) (*(f32 *)&this->unk_68 + lbl_805DD478);
        }
        TRaderMapCore::pan_horizontal((f32) (*(f32 *)&this->unk_60));
        TRaderMapCore::pan_vertical(this->m_64);
        TRaderMapCore::add_zoom_distance((f32) (*(f32 *)&this->unk_68));
        *(f32 *)&this->unk_60 = (f32) (*(f32 *)&this->unk_60 * lbl_805DD47C);
        this->m_64 = (f32) (this->m_64 * lbl_805DD47C);
        *(f32 *)&this->unk_68 = (f32) (*(f32 *)&this->unk_68 * lbl_805DD47C);
    }
}
