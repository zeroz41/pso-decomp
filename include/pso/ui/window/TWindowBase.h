#ifndef PSO_UI_WINDOW_TWINDOWBASE_H
#define PSO_UI_WINDOW_TWINDOWBASE_H
#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WindowLayoutEntries.h"

struct WindowDrawContext;

class TWindowBase : public TObject {
public:
    TWindowBase(u8 *descriptor, s16 client, u8 *parent);
    virtual ~TWindowBase();
    void draw_window_frame(void *);
    void draw_window_frame_strips(void *, void *);
    void draw_message_frame_row(void *, void *);
    void resort_window_order();
    void close();
    void request_close();
    void set_depth(f32 depth);
    void calc_inner_rect(WindowDrawContext *context);
    void sub_8026CC28();
    void update_window_entry_list(const WindowLayoutEntries *entries);
    void update_fade();
    void draw_quest_message_frame(void *);
    void sub_80244F2C(u8 *, u8 *, s16);
    WindowDrawContext *setup_window_draw_context(f32 *scale);
    WindowDrawContext *draw_default_entry();
    s32 is_window_reveal_complete();
    s32 sub_80244994();
    void save_position();
    f32 get_scale();
    s32 sub_80246948();
    void *get_array_entry(int index);
    virtual void render();
    virtual void run_task();

    f32 sort_depth;
    s16 client_index;
    s16 closing_tick;
    WindowLayoutEntries entry_list;
    s32 window_flags;
    f32 target_position[2];
    f32 target_size[2];
    f32 frame_position[2];
    f32 frame_size[2];
    u32 tween_ticks;
    f32 draw_depth;
    f32 m_58;
    s32 open_tick;
};

typedef char WindowSortDepthOffset[offsetof(TWindowBase, sort_depth) == 0x1C ? 1 : -1];
typedef char WindowClientOffset[offsetof(TWindowBase, client_index) == 0x20 ? 1 : -1];
typedef char WindowClosingTickOffset[offsetof(TWindowBase, closing_tick) == 0x22 ? 1 : -1];
typedef char WindowEntriesOffset[offsetof(TWindowBase, entry_list) == 0x24 ? 1 : -1];
typedef char WindowFlagsOffset[offsetof(TWindowBase, window_flags) == 0x2C ? 1 : -1];
typedef char WindowBaseSize[sizeof(TWindowBase) == 0x60 ? 1 : -1];
typedef char WindowTargetPositionOffset[offsetof(TWindowBase, target_position) == 0x30 ? 1 : -1];
typedef char WindowTargetSizeOffset[offsetof(TWindowBase, target_size) == 0x38 ? 1 : -1];
typedef char WindowFramePositionOffset[offsetof(TWindowBase, frame_position) == 0x40 ? 1 : -1];
typedef char WindowFrameSizeOffset[offsetof(TWindowBase, frame_size) == 0x48 ? 1 : -1];
typedef char WindowTweenOffset[offsetof(TWindowBase, tween_ticks) == 0x50 ? 1 : -1];
typedef char WindowDrawDepthOffset[offsetof(TWindowBase, draw_depth) == 0x54 ? 1 : -1];
typedef char WindowOpenTickOffset[offsetof(TWindowBase, open_tick) == 0x5C ? 1 : -1];

#endif
