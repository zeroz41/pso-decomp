#include "types.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

struct Base_80212644 { char pad[0x18]; };
struct VObj_80212644 : Base_80212644 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};
extern struct VObj_80212644 *THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::set_state_3() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->m7(6, 1);
        *(s32 *)((s8 *)THunterGuildSeqOffline__active_instance + 0x38) = 3;
        ((TShopWindowBase *)THunterGuildSeqOffline__active_instance)->set_field_20(5);
    }
}
