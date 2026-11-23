#ifndef PSO_UI_FRONTEND_TADWARNINGBASEGC_H
#define PSO_UI_FRONTEND_TADWARNINGBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TWindowBase;

struct TAdWarningBaseGC : public TObject {
    TAdWarningBaseGC(TObject *parent);
    virtual ~TAdWarningBaseGC();
    virtual void vfunc_6() = 0;
    virtual saddr vfunc_7() = 0;  // the warning text: get_localized_text_entry
    virtual void vfunc_8();
    virtual void vfunc_9();
    saddr sub_8032D214();   // creates the message window holding vfunc_7's text
    s32 state;               // 0x1C: the vfunc_8 switch
    s32 prev_state;          // 0x20: state when vfunc_8 began; a change restarts frames
    s32 next_state;          // 0x24: entered when the closing state's frames run out
    s32 frames;              // 0x28: frames spent in the closing state
    TWindowBase *message_window; // 0x2C: sub_8032D214's message window
    static void create();
    static void init_heap();
    static s32 load_from_aram_sync(int buf);
    static int get_alloc_size();
    static s32 post_aram_request(int buf, int size);
};

LAYOUT_ASSERT(TAdWarningBaseGC_size, sizeof(TAdWarningBaseGC) == 0x30);

extern "C" {
void clear_aram_request_busy(uaddr request);
}

#endif
