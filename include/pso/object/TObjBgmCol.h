#ifndef PSO_OBJECT_TOBJBGMCOL_H
#define PSO_OBJECT_TOBJBGMCOL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjBgmCol : public TObjBase {
    virtual ~TObjBgmCol();
    u32 m_90;
    u8 unk_94[0x4];
    f32 m_98;
    u32 m_9c;
    s32 check();
    virtual void run_task();
    s32 is_within_distance(f32 farg0);
};

typedef char TObjBgmCol_size[sizeof(TObjBgmCol) == 0xA0 ? 1 : -1];
#endif
