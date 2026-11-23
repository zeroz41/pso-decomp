#ifndef PSO_UI_FRONTEND_TADAGREEMENTBASEGC_H
#define PSO_UI_FRONTEND_TADAGREEMENTBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSelectCurGC;

struct TAdAgreementBaseGC : public TObject {
    TAdAgreementBaseGC(TObject *parent);
    virtual ~TAdAgreementBaseGC();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void *create_agreement_callback();
    virtual void update_state();
    virtual void check_main_task_state();
    s32 state;               // 0x1C: the update_state switch
    s32 prev_state;          // 0x20: state when update_state began; a change restarts frames
    s32 next_state;          // 0x24: entered when the closing state's frames run out
    s32 frames;              // 0x28: frames spent in the closing state
    void *callback_window;   // 0x2C: create_agreement_callback's text window
    TAdSelectCurGC *cursor;  // 0x30: the two-entry agree/decline cursor
    u32 m_34;
    static void draw_agreement_text(void *window, void *frame_context);
};

LAYOUT_ASSERT(TAdAgreementBaseGC_size, sizeof(TAdAgreementBaseGC) == 0x38);

extern "C" {
void *__dt__18TAdAgreementBaseGCFv(void *arg0, s16 arg1);
void fn_80329BAC(void *p);
}

// --- C functions defined in TAdAgreementBaseGC.cpp ---
extern "C" {
void fn_80329BAC(void *p);
}
// --- end of C functions

#endif
