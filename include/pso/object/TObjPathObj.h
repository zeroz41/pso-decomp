#ifndef PSO_OBJECT_TOBJPATHOBJ_H
#define PSO_OBJECT_TOBJPATHOBJ_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjPathObj : public TObjBase {
    virtual ~TObjPathObj();
    virtual void vfunc_13(s32);
    virtual void vfunc_14();
    virtual void render();
    virtual void run_task();
    u8 unk_90[0x4];
    f32 m_94;
};

typedef char TObjPathObj_size[sizeof(TObjPathObj) == 0x98 ? 1 : -1];
#endif
