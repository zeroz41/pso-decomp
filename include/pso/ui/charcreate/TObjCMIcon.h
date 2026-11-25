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
}

__declspec(section ".data") extern vec2f cm_icon_screen_position;

LAYOUT_ASSERT(CreationIconStateSize, sizeof(CreationIconState) == 12);
LAYOUT_ASSERT(CreationIconGroupSize, sizeof(CreationIconGroup) == 0x14);

class TObjCMIcon : public TObject {
public:
    TObjCMIcon(TObject *parent);
    virtual ~TObjCMIcon();
    virtual void render();
    virtual void run_task();
public:
    s32 get_sprite_id(s32 sprite_id);

    static void *create(void *object);
    static void set_screen_position(const vec2f *pos);
    static void reset_icon_flags();
    static void show_creation_icon(s32 index);
    static void show_only_creation_icons(s32 count, const s32 *ids);
    static void init_icon_table();
    static void copy_icon_state(CreationIconState *dst, CreationIconState *src);

    static CreationIconGroup icon_group_table[7];
    static f32 horizontal_scroll_offset;
};

#endif
