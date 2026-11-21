#ifndef PSO_UI_FRONTEND_TADWARNINGBASEGC_H
#define PSO_UI_FRONTEND_TADWARNINGBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdWarningBaseGC : public TObject {
    TAdWarningBaseGC(TObject *parent);
    virtual ~TAdWarningBaseGC();
    virtual int vfunc_6() = 0;
    virtual void vfunc_7() = 0;
    virtual void vfunc_8();
    virtual void vfunc_9();
    s32 sub_8032D214();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    uaddr m_2c;
    void destroy();
    static void create();
    static void init_heap();
};

LAYOUT_ASSERT(TAdWarningBaseGC_size, sizeof(TAdWarningBaseGC) == 0x30);

extern "C" {
void clear_aram_request_busy(void);
}

#endif
