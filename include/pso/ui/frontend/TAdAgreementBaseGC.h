#ifndef PSO_UI_FRONTEND_TADAGREEMENTBASEGC_H
#define PSO_UI_FRONTEND_TADAGREEMENTBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdAgreementBaseGC : public TObject {
    virtual ~TAdAgreementBaseGC();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void create_agreement_callback();
    virtual void update_state();
    virtual void check_main_task_state();
    u32 m_1c;
    u8 _pad20[0x4];
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    static void draw_agreement_text();
};

typedef char TAdAgreementBaseGC_size[sizeof(TAdAgreementBaseGC) == 0x38 ? 1 : -1];

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
