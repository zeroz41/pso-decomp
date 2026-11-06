#ifndef PSO_UI_FRONTEND_TADMULTICONFIRMGC_H
#define PSO_UI_FRONTEND_TADMULTICONFIRMGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdMultiConfirmGC : public TObject {
    TAdMultiConfirmGC(TObject *parent);
    virtual ~TAdMultiConfirmGC();
    u32 m_1c;
    u32 m_20;
    u8 _pad24[0x20];
    u32 m_44;
    u32 m_48;
    virtual void render();
    virtual void run_task();
    static int reset_cursor(void* p);
    static int set_cursor_index_1(void* p);
    static int set_cursor_index_2(void* p);
};

typedef char TAdMultiConfirmGC_size[sizeof(TAdMultiConfirmGC) == 0x4C ? 1 : -1];
#endif
