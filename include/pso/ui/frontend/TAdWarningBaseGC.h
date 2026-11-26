#ifndef PSO_UI_FRONTEND_TADWARNINGBASEGC_H
#define PSO_UI_FRONTEND_TADWARNINGBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TWindowBase;

struct TAdWarningBaseGC : public TObject {
    static int aram_alloc_size;
    static u32 aram_capacity;
    TAdWarningBaseGC(TObject *parent);
    virtual ~TAdWarningBaseGC();
    virtual void on_close() = 0;
    virtual saddr get_message_text() = 0;  // the warning text: get_localized_text_entry
    virtual void update_state();
    virtual void render_dialog();
    saddr create_message_window();   // creates the message window holding get_message_text's text
    s32 state;               // 0x1C: the update_state switch
    s32 prev_state;          // 0x20: state when update_state began; a change restarts frames
    s32 next_state;          // 0x24: entered when the closing state's frames run out
    s32 frames;              // 0x28: frames spent in the closing state
    TWindowBase *message_window; // 0x2C: create_message_window's message window
    static void create();
    static void init_heap();
    static s32 load_from_aram_sync(void *buf);
    static int get_alloc_size();
    static s32 post_aram_request(void *buf, int size);
};

LAYOUT_ASSERT(TAdWarningBaseGC_size, sizeof(TAdWarningBaseGC) == 0x30);

void clear_aram_request_busy(uaddr request);

#endif
