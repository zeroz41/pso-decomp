#ifndef PSO_UI_FRONTEND_TADSTORYSELECTGC_H
#define PSO_UI_FRONTEND_TADSTORYSELECTGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSelectCurGC;
class TAdGuideTxtGC;

class TAdStorySelectGC : public TObject {
public:
    TAdStorySelectGC(TObject *parent);
    virtual ~TAdStorySelectGC();
    virtual void run_task();
    virtual void render();
public:
    static void set_state(s32 arg0);
    // The story list's cursor (story_select_cursor); TKeyBoardControl::dispatch_select_phase
    // switches on it after the ending.
    static int get_story_select();

    TAdSelectCurGC *cursor;  // 0x1C: the story list's cursor
    TAdGuideTxtGC *guide;    // 0x20: the guide text; line 1 follows the cursor
};

LAYOUT_ASSERT(TAdStorySelectGC_size, sizeof(TAdStorySelectGC) == 0x24);

s32 request_story_select_state(s32 arg0);

// Cursor of the story list: cleared by the constructor, run_task stores the list's cursor every
// frame (name inferred from that).
extern s32 story_select_cursor;

#endif
