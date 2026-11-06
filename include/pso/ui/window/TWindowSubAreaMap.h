#ifndef PSO_UI_WINDOW_TWINDOWSUBAREAMAP_H
#define PSO_UI_WINDOW_TWINDOWSUBAREAMAP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubAreaMap : public TObject {
    TWindowSubAreaMap(TObject *arg1, void *arg2);
    virtual ~TWindowSubAreaMap();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    virtual void render();
    virtual void run_task();
};

typedef char TWindowSubAreaMap_size[sizeof(TWindowSubAreaMap) == 0x28 ? 1 : -1];

extern "C" {
void *__dt__17TWindowSubAreaMapFv(void *arg0, s16 arg1);
}

#endif
