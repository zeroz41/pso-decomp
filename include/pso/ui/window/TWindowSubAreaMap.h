#ifndef PSO_UI_WINDOW_TWINDOWSUBAREAMAP_H
#define PSO_UI_WINDOW_TWINDOWSUBAREAMAP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowSubAreaMapDisp;

struct TWindowSubAreaMap : public TObject {
    TWindowSubAreaMap(TObject *parent, s32 client);
    virtual ~TWindowSubAreaMap();
    static const char *class_name;
    s32 client;
    TWindowMainMenu *parent_menu;
    TWindowSubAreaMapDisp *map_disp;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubAreaMap_size, sizeof(TWindowSubAreaMap) == 0x28);

#endif
