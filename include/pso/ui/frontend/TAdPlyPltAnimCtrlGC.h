#ifndef PSO_UI_FRONTEND_TADPLYPLTANIMCTRLGC_H
#define PSO_UI_FRONTEND_TADPLYPLTANIMCTRLGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

// Screen position of the player plates
struct PlyPltAnimVec2 {
    f32 x, y;
};

class TAdPlyPltAnimGC;

struct TAdPlyPltAnimCtrlGC : public TObject {
    static const char *class_name;
    TAdPlyPltAnimCtrlGC(TObject *parent);
    virtual ~TAdPlyPltAnimCtrlGC();
    virtual void render();
    u32 state;
    u32 frame;
    PlyPltAnimVec2 plate_position;
    static void render(void *self);
    void init(void* a1);
    virtual void run_task();
    static u32 get_instance(saddr parent);
    static TAdPlyPltAnimGC *get_table_value(int index);
};

LAYOUT_ASSERT(TAdPlyPltAnimCtrlGC_size, sizeof(TAdPlyPltAnimCtrlGC) == 0x2C);

extern "C" {
void TAdPlyPltAnimCtrlGC__sub_80355168(TAdPlyPltAnimCtrlGC *ctrl);
}

// Whether every bit of `mask` is set in the flag word.
s32 test_flags_all(s32 *flags, s32 mask);

#endif
