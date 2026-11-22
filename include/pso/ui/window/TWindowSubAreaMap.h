#ifndef PSO_UI_WINDOW_TWINDOWSUBAREAMAP_H
#define PSO_UI_WINDOW_TWINDOWSUBAREAMAP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowSubAreaMapDisp;

struct TWindowSubAreaMap : public TObject {
    TWindowSubAreaMap(TObject *object, void *arg2);
    virtual ~TWindowSubAreaMap();
    u32 m_1c;
    TWindowMainMenu *parent_menu;
    TWindowSubAreaMapDisp *map_disp;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubAreaMap_size, sizeof(TWindowSubAreaMap) == 0x28);

extern "C" {
void *__dt__17TWindowSubAreaMapFv(void *arg0, s16 arg1);
}

#endif
