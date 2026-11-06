#ifndef PSO_UI_FRONTEND_TADWARNINGBASEGC_H
#define PSO_UI_FRONTEND_TADWARNINGBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdWarningBaseGC : public TObject {
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
    u32 m_2c;
    int destroy();
    static void create();
    static void init_heap();
};

typedef char TAdWarningBaseGC_size[sizeof(TAdWarningBaseGC) == 0x30 ? 1 : -1];

extern "C" {
void *TAdWarningBaseGC__ct(TAdWarningBaseGC *arg0);
void clear_aram_request_busy(void);
}

#endif
