#ifndef PSO_UNK_TLOBBY_80228C84_H
#define PSO_UNK_TLOBBY_80228C84_H

#include "types.h"

void refresh_player_status(s32 client_id);

struct Base_80228C84 { char pad[0x18]; };

struct VObj_80228C84 : Base_80228C84 {
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
    virtual const char *m10();
};

#endif
