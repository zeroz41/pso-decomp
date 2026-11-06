#ifndef PSO_UI_CHARCREATE_TOBJCMICON_H
#define PSO_UI_CHARCREATE_TOBJCMICON_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct CreationIconState {
    s32 hidden;
    f32 fade;
    f32 x;
};

extern "C" {
extern CreationIconState creation_icon_states[7];
extern CreationIconState creation_initial_icon_state;
extern f32 TObjCMIcon__horizontal_scroll_offset;
}

typedef char CreationIconStateSize[sizeof(CreationIconState) == 12 ? 1 : -1];

class TObjCMIcon : public TObject {
public:
    virtual ~TObjCMIcon();
    virtual void render();
    virtual void run_task();
public:
    static void *create(void *arg0);
    static void reset_icon_flags();
    static void init_icon_table();
};

#endif
