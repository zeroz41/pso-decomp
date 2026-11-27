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
    static TAdPlyPltAnimCtrlGC *get_instance(TObject *parent);
    s32 is_plate_animation_running();
    static TAdPlyPltAnimGC *get_table_value(int index);
};

LAYOUT_ASSERT(TAdPlyPltAnimCtrlGC_size, sizeof(TAdPlyPltAnimCtrlGC) == 0x2C);

extern TAdPlyPltAnimCtrlGC *plyplt_anim_ctrl_instance;

void reset_plate_animations(TAdPlyPltAnimCtrlGC *ctrl);

// Whether every bit of `mask` is set in the flag word.
s32 test_flags_all(s32 *flags, s32 mask);

#endif
