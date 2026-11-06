#ifndef PSO_OBJECT_TRAP_TOMINETRAPDISP_H
#define PSO_OBJECT_TRAP_TOMINETRAPDISP_H

#include "types.h"
#include "pso/object/trap/TOMineDisp.h"

struct TOMineTrapDisp : public TOMineDisp {
    TOMineTrapDisp(TObject *parent, u16 client, u16 owner);
    virtual ~TOMineTrapDisp();
    virtual void run_task();
    u16 m_ac;
    u8 unk_AE[0x2];
};

typedef char TOMineTrapDisp_size[sizeof(TOMineTrapDisp) == 0xB0 ? 1 : -1];
#endif
