#ifndef PSO_OBJECT_TRAP_TOMINEICON01_H
#define PSO_OBJECT_TRAP_TOMINEICON01_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TOMineIcon01 : public TOMine {
    TOMineIcon01(TObject *parent, void *set_data);
    virtual ~TOMineIcon01();
    virtual void vfunc_84();
    u32 m_374;
    u32 m_378;
    void *create();
};

typedef char TOMineIcon01_size[sizeof(TOMineIcon01) == 0x37C ? 1 : -1];

extern "C" {
void *__dt__12TOMineIcon01Fv(void *arg0, s16 arg1);
}

#endif
