#ifndef PSO_UI_FRONTEND_TADSTORYSELECTGC_H
#define PSO_UI_FRONTEND_TADSTORYSELECTGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdStorySelectGC : public TObject {
public:
    virtual ~TAdStorySelectGC();
    virtual void run_task();
    virtual void render();
public:
    static void set_state(s32 arg0);
    // The story list's cursor (story_select_cursor); TKeyBoardControl::dispatch_select_phase
    // switches on it after the ending.
    static int get_story_select();
};

s32 request_story_select_state(s32 arg0);

// Cursor of the story list: cleared by the constructor, run_task stores the list's cursor every
// frame (name inferred from that).
extern s32 story_select_cursor;

#endif
