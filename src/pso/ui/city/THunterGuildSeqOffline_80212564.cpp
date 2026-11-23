#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"

struct Base_802125BC_80212564 { char pad[0x18]; };
struct VObj_802125BC_80212564 : Base_802125BC_80212564 {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4();
    virtual int m5();
    virtual int m6();
    virtual int m7(int, int);
    virtual int m8();
};

extern "C" {



void THunterGuildSeqOffline::set_state_4(TShopWindowBase *) {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline__active_instance->unk_38 = 4;
        THunterGuildSeqOffline__active_instance->set_state(5);
    }
}

void THunterGuildSeqOffline::handle_click() {
    VObj_802125BC_80212564 *o = (VObj_802125BC_80212564 *)this;
    if (o->m8() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        o->m7(0x19, 1);
        set_state(4);
    }
}

}
