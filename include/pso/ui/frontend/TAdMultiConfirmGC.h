#ifndef PSO_UI_FRONTEND_TADMULTICONFIRMGC_H
#define PSO_UI_FRONTEND_TADMULTICONFIRMGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdMultiOkGC;

struct TAdMultiConfirmGC : public TObject {
    TAdMultiConfirmGC(TObject *parent);
    virtual ~TAdMultiConfirmGC();
    u32 m_1c;
    u32 m_20;
    u8 _pad24[0x20];
    u32 m_44;
    TAdMultiOkGC *ok;
    virtual void render();
    virtual void run_task();
    static int reset_cursor(void* p);
    static int set_cursor_index_1(void* p);
    static int set_cursor_index_2(void* p);
};

LAYOUT_ASSERT(TAdMultiConfirmGC_size, sizeof(TAdMultiConfirmGC) == 0x4C);
#endif
