#ifndef PSO_UI_FRONTEND_TADEP3EXIST_H
#define PSO_UI_FRONTEND_TADEP3EXIST_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSelectCurGC;
class TAdScrollWinGC;

struct TAdEp3Exist : public TObject {
    static const char *name;
    TAdEp3Exist(TObject *parent);
    virtual ~TAdEp3Exist();
    static void draw_message_window(void *window, void *frame_context);
    virtual void *create_callback_window();     // creates the message callback window
    TAdScrollWinGC *scroll_window; // 0x1C: the scrolling text window
    TAdSelectCurGC *cursor;      // 0x20: the one-entry cursor
    void *callback_window;       // 0x24: create_callback_window's window
    s32 state;                   // 0x28: the run_task switch
    s32 prev_state;              // 0x2C: state when run_task began; a change restarts frames
    s32 next_state;              // 0x30: entered when the closing state's frames run out
    s32 frames;                  // 0x34: frames spent in the closing state
    virtual void render();
    void request_game_mode_transition();
    void request_scene_change();
    void request_ppp_pass_scene();
    void close_window();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdEp3Exist_size, sizeof(TAdEp3Exist) == 0x38);
#endif
