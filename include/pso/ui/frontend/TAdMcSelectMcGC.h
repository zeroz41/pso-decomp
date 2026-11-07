#ifndef PSO_UI_FRONTEND_TADMCSELECTMCGC_H
#define PSO_UI_FRONTEND_TADMCSELECTMCGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

// One textured screen quad: position rect, then texture-coordinate rect
struct McSelectMcQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

// Memory card picture of one slot on the memory card select screen
class TAdMcSelectMcGC : public TObject {
public:
    s32 pad_1c;                // 1 (ctor): drawn outside render pass 1; TAdMcSelectGC clears it
    McSelectMcQuad quads[8];
    u32 pad_120;               // alpha of the picture
    s32 pad_124;               // fade-in step, follows the slot's cursor state
    s32 pad_128;
    s32 pad_12c;               // memory card slot (ctor argument)
    s32 pad_130;

    TAdMcSelectMcGC(TObject *parent, s32 slot);
    virtual ~TAdMcSelectMcGC();
    void draw_status_window();
    virtual void render();
    virtual void run_task();
    static void release_selected_entry();
    static void init_memorycard();
};

typedef char TAdMcSelectMcGC_size[sizeof(TAdMcSelectMcGC) == 0x134 ? 1 : -1];

#endif
