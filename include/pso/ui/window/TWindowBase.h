#ifndef PSO_UI_WINDOW_TWINDOWBASE_H
#define PSO_UI_WINDOW_TWINDOWBASE_H
#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/NinjaTypes.h"

struct WindowDescriptor;

struct WindowDrawContext;
struct TexturedQuad;
class TWindowLayoutRect;

class TWindowBase : public TObject {
public:
    TWindowBase(u8 *descriptor, s16 client, u8 *parent);
    virtual ~TWindowBase();
    void reparent_to_main_ctrl();
    void draw_window_frame(WindowDrawContext *context);
    void draw_window_frame_strips(TexturedQuad *quad, WindowDrawContext *context);
    void draw_message_frame_row(TexturedQuad *quad, WindowDrawContext *context);
    void resort_window_order();
    void close();
    void request_close();
    void request_refresh();
    void request_show();
    // The per-frame open/close animation every window runs from its run_task.
    void update_open_close();
    void update_window();
    void set_depth(f32 depth);
    void set_position(f32 *pos);
    void calc_inner_rect(WindowDrawContext *context);
    void bring_to_front();
    void update_window_entry_list(const WindowLayoutEntries *entries);
    void update_fade();
    void draw_quest_message_frame(WindowDrawContext *c);
    void init_window(WindowDescriptor *descriptor, u8 *parent, s16 client);
    WindowDrawContext *setup_window_draw_context(f32 *scale);
    WindowDrawContext *draw_default_entry();
    s32 is_window_reveal_complete();
    s32 is_open_and_unblocked();
    void save_position();
    f32 get_transition_progress();
    f32 get_close_progress();
    f32 get_normalized_progress();
    f32 get_scale();
    s32 is_closed();
    void *get_array_entry(int index);
    virtual void render();
    virtual void run_task();
    void slide_to(f32 *pos);
    void set_size(f32 *size);
    void snap_to(f32 *pos);

    static const char *class_name;

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

LAYOUT_ASSERT(WindowSortDepthOffset, offsetof(TWindowBase, sort_depth) == 0x1C);
LAYOUT_ASSERT(WindowClientOffset, offsetof(TWindowBase, client_index) == 0x20);
LAYOUT_ASSERT(WindowClosingTickOffset, offsetof(TWindowBase, closing_tick) == 0x22);
LAYOUT_ASSERT(WindowEntriesOffset, offsetof(TWindowBase, entry_list) == 0x24);
LAYOUT_ASSERT(WindowFlagsOffset, offsetof(TWindowBase, window_flags) == 0x2C);
LAYOUT_ASSERT(WindowBaseSize, sizeof(TWindowBase) == 0x60);
LAYOUT_ASSERT(WindowTargetPositionOffset, offsetof(TWindowBase, target_position) == 0x30);
LAYOUT_ASSERT(WindowTargetSizeOffset, offsetof(TWindowBase, target_size) == 0x38);
LAYOUT_ASSERT(WindowFramePositionOffset, offsetof(TWindowBase, frame_position) == 0x40);
LAYOUT_ASSERT(WindowFrameSizeOffset, offsetof(TWindowBase, frame_size) == 0x48);
LAYOUT_ASSERT(WindowTweenOffset, offsetof(TWindowBase, tween_ticks) == 0x50);
LAYOUT_ASSERT(WindowDrawDepthOffset, offsetof(TWindowBase, draw_depth) == 0x54);
LAYOUT_ASSERT(WindowOpenTickOffset, offsetof(TWindowBase, open_tick) == 0x5C);

struct TWindowSubComCard;
class TWindowFukidasi;
BOOL scanline_crosses_window(void *ctx, void *position, void *size);
void hide_window(TWindowBase *window);
int get_area_total(void);
void draw_selection_bar(WindowDrawContext *context, TWindowLayoutRect *entry, s32 active);
// The highlight sweep drawn over a status window: begin sets the texture and blend
// (skipped for UI themes 0 and 1), draw_window_sweep_strip draws it over quad, end restores.
void begin_window_sweep_draw(s32 texture);
void draw_window_sweep_strip(TexturedQuad *quad, WindowDrawContext *context);
void end_window_sweep_draw(s32 texture);
void draw_window_scanlines(TWindowBase *window, WindowDrawContext *context);
bool is_balloon_overlapping(u8 *balloon, u8 *position, u8 *size);

struct NJS_TEXLIST;
// The HUD palette and glyph texture list loaded for the window system.
extern NJS_TEXLIST *hud_texlist;
void load_hud_palette_textures(void);

struct SelectionBarCoordinates { NJS_POINT2 e[2]; };

#endif
