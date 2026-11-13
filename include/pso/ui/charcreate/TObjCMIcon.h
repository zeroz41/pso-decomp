#ifndef PSO_UI_CHARCREATE_TOBJCMICON_H
#define PSO_UI_CHARCREATE_TOBJCMICON_H
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "types.h"

struct CreationIconState {
    s32 hidden;
    f32 fade;
    f32 x;
};

struct CreationIconGroup {
    s32 count;
    s32 sprite_ids[4];
};

extern "C" {
extern CreationIconState creation_icon_states[7];
extern CreationIconState creation_initial_icon_state;
extern f32 TObjCMIcon__horizontal_scroll_offset;
}

extern CreationIconGroup TObjCMIcon__icon_group_table[7];
__declspec(section ".data") extern vec2f cm_icon_screen_position;

typedef char CreationIconStateSize[sizeof(CreationIconState) == 12 ? 1 : -1];
typedef char CreationIconGroupSize[sizeof(CreationIconGroup) == 0x14 ? 1 : -1];

class TObjCMIcon : public TObject {
public:
    TObjCMIcon(TObject *parent);
    virtual ~TObjCMIcon();
    virtual void render();
    virtual void run_task();
public:
    static void *create(void *arg0);
    static void reset_icon_flags();
    static void init_icon_table();
};

#endif
