#ifndef PSO_OBJECT_TRAP_TOMINEICON04_H
#define PSO_OBJECT_TRAP_TOMINEICON04_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TOMineIcon04 : public TOMine {
    TOMineIcon04(TObject *parent, void *set_data);
    virtual ~TOMineIcon04();
    virtual void vfunc_84();
    virtual void vfunc_82();
    virtual void vfunc_80();
    u32 m_374;
    u32 m_378;
    void *create();
};

typedef char TOMineIcon04_size[sizeof(TOMineIcon04) == 0x37C ? 1 : -1];
#endif
