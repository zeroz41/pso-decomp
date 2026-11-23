#ifndef PSO_TECHNIQUE_TSLICERHISTORY_H
#define PSO_TECHNIQUE_TSLICERHISTORY_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

class TTecSlicer;

// An afterimage a flying slicer leaves each frame: a copy of its model at the
// slicer's pose that fades out.
class TSlicerHistory : public TObject {
public:
    TSlicerHistory(TTecSlicer *slicer, NJS_TEXLIST *texlist, NJS_ARGB *color, u32 weapon_handle);
    static const char *class_name;
    virtual ~TSlicerHistory();
    virtual void run_task();
    virtual void render();

    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
    Vec position;
    void *model;
    NJS_TEXLIST *texlist;
    NJS_ARGB color;     // alpha drops by 0.2 a frame; gone below zero
    Vec scale;
    u32 weapon_handle;  // the slicer weapon's item id; the copy hides once it is unequipped
    s32 has_color;      // set when the slicer had a colour override
};
LAYOUT_ASSERT(TSlicerHistorySize, sizeof(TSlicerHistory) == 0x60);

#endif
