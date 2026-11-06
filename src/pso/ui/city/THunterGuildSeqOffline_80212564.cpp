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

struct Base_80212564 { char pad[0x18]; };
struct VObj_80212564 : Base_80212564 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};

int sub_802239EC__13TShopSequenceFv(void *);
int sub_80223A48__15TShopWindowBaseFv(void *);

extern struct VObj_80212564 *THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::set_state_4() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->m7(6, 1);
        *(s32 *)((s8 *)THunterGuildSeqOffline__active_instance + 0x38) = 4;
        ((TShopWindowBase *)THunterGuildSeqOffline__active_instance)->set_field_20(5);
    }
}

void THunterGuildSeqOffline::handle_click() {
    VObj_802125BC_80212564 *o = (VObj_802125BC_80212564 *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m7(0x19, 1);
        set_field_20(4);
    }
}

}
