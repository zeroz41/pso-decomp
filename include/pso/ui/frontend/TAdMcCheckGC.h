#ifndef PSO_UI_FRONTEND_TADMCCHECKGC_H
#define PSO_UI_FRONTEND_TADMCCHECKGC_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

struct TAdMcCheckGC : public TObject {
    static const char *name;
    TAdMcCheckGC(TObject *parent, s32 slot);
    virtual ~TAdMcCheckGC();
    // Check steps: 0 waits for a card, 1-4 test it, 5 is done. Each test step
    // shows its warning window after 10 frames without passing.
    u32 check_step;
    u32 previous_step;
    u32 step_frames;
    s32 card_slot;
    TObject *warning_windows[4];
    virtual void render();
    TObject *create(s32 message);
    s32 get_check_step();
    // Returns the check task of card slot `slot`, creating it under `parent` if there is none.
    static TAdMcCheckGC *get_instance(TObject *parent, s32 slot);
    virtual void run_task();
};

LAYOUT_ASSERT(TAdMcCheckGC_slot_offset, offsetof(TAdMcCheckGC, card_slot) == 0x28);
LAYOUT_ASSERT(TAdMcCheckGC_warnings_offset, offsetof(TAdMcCheckGC, warning_windows) == 0x2C);
LAYOUT_ASSERT(TAdMcCheckGC_size, sizeof(TAdMcCheckGC) == 0x3C);


// The check task of each card slot, cleared when the task ends.
extern TAdMcCheckGC *memcard_cursor_instance_table[];

#endif
