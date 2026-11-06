#ifndef PSO_OBJECT_TRAP_TOMINEICON02_H
#define PSO_OBJECT_TRAP_TOMINEICON02_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TOMineIcon02 : public TOMine {
    virtual ~TOMineIcon02();
    virtual void vfunc_84();
    virtual void vfunc_82();
    u32 m_374;
    u32 m_378;
    void *create();
};

typedef char TOMineIcon02_size[sizeof(TOMineIcon02) == 0x37C ? 1 : -1];

extern "C" {
void *TOMineIcon02__ct(void *arg0, void *arg1, void *arg2);
void *__dt__12TOMineIcon02Fv(void *arg0, s16 arg1);
}

#endif
