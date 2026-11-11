#ifndef PSO_UI_FRONTEND_TADMULTISAVEGC_H
#define PSO_UI_FRONTEND_TADMULTISAVEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdMultiSaveGC : public TObject {
    virtual ~TAdMultiSaveGC();
    virtual void render();
    virtual void run_task();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    static void render(void *self);
    static void queue_destruction();
};

typedef char TAdMultiSaveGC_size[sizeof(TAdMultiSaveGC) == 0x34 ? 1 : -1];

extern "C" {
void *TAdMultiSaveGC__ct(TAdMultiSaveGC *arg0);
void *__dt__14TAdMultiSaveGCFv(TAdMultiSaveGC *arg0, s16 arg1);
}

#endif
