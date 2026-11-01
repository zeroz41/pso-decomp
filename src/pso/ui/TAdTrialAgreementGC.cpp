#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/system/main_loop.h"
#include "pso/ui/TAdTrialAgreementGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/ui/TAdScrollWinGC.h"

struct Base_80335648 { char pad[0x18]; };
struct VObj_80335648 : Base_80335648 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
};

extern "C" {

s32 TAdPlayerLoadGC__sub_801E1B50(s32);
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);

void TAdTrialAgreementGC::render() {
    struct VObj_80335648 *o = (struct VObj_80335648 *)this;
    o->m10();
}

void TAdTrialAgreementGC::vfunc_8() { TKeyBoardControl__sub_8000F9CC((s32)((void*)0)); }
void TAdTrialAgreementGC::vfunc_7() { request_scene_change__21TAdMultiChgGameModeGCFv(this); }
void TAdTrialAgreementGC::vfunc_6() { if (this->m_38 != 0) { ((TAdScrollWinGC *)(this->m_38))->close_window(); this->m_38 = 0; } }
void TAdTrialAgreementGC::wait_for_load() {
loop_1:
    if ((TAdPlayerLoadGC::probe_card_slot(0) != 0) && (TAdPlayerLoadGC__sub_801E1B50(0) != 0)) {
        render_tick();
        goto loop_1;
    }
}

}
