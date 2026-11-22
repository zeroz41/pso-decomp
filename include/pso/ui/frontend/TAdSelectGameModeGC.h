#ifndef PSO_UI_FRONTEND_TADSELECTGAMEMODEGC_H
#define PSO_UI_FRONTEND_TADSELECTGAMEMODEGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSelectCurGC;
class TAdGuideTxtGC;

class TAdSelectGameModeGC : public TObject {
public:
    TAdSelectGameModeGC(TObject *parent);
    virtual ~TAdSelectGameModeGC();
    virtual void run_task();
public:
    static int get_mode_data();
    static void enable_camera();
    virtual void render();
    static void call_enable_camera(void* p);

    TAdSelectCurGC *cursor;  // 0x1C: the game mode list's cursor
    TAdGuideTxtGC *guide;    // 0x20: the guide text; line 1 follows the cursor
};

LAYOUT_ASSERT(TAdSelectGameModeGC_size, sizeof(TAdSelectGameModeGC) == 0x24);

extern s32 TAdSelectGameModeGC__cached_mode_value;

#endif
