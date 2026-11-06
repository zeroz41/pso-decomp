#ifndef PSO_UI_FRONTEND_TADTRIALAGREEMENTGC_H
#define PSO_UI_FRONTEND_TADTRIALAGREEMENTGC_H

#include "types.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"

struct TAdTrialAgreementGC : public TAdAgreementBaseGC {
    virtual ~TAdTrialAgreementGC();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    u32 m_38;
    virtual void render();
    static void wait_for_load();
    virtual void run_task();
    static void draw_record_with_camera(s32 arg0, s32 arg1, s32 arg2);
    void update_title_prompt();
    void handle_cursor_input();
    void render_screen();
    void run_state();
    static s32 check_card_file(s32 arg0);
};

typedef char TAdTrialAgreementGC_size[sizeof(TAdTrialAgreementGC) == 0x3C ? 1 : -1];
#endif
