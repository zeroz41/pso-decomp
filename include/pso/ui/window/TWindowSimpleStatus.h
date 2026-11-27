#ifndef PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H
#define PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayoutRecord.h"

struct NJS_POINT2;

struct TWindowSimpleStatus : public TWindowBase {
    TWindowSimpleStatus(const NJS_POINT2 *position, s32 client, u8 *descriptor);
    virtual ~TWindowSimpleStatus();
    static const char *class_name;
    void draw_background(WindowDrawContext *ctx);
    void apply_random_shake();
    void update_status_icons(NJS_POINT2 *offset);
    void start_hp_text_color_transition();
    void init_gauge_entry();
    void update_status_entry();
    s32 update_hp_gauge();
    s32 update_hp_entry();
    void update_hp_tp_level();
    s32 get_width();
    virtual void render();
    u32 shake_ticks; // frames apply_random_shake still shakes the window; set when HP drops
    virtual void run_task();
    static TWindowSimpleStatus *create(const NJS_POINT2 *position, s32 client);
    TWindowBase *w[5]; // child windows; the dtor closes the first four
};

LAYOUT_ASSERT(TWindowSimpleStatus_size, sizeof(TWindowSimpleStatus) == 0x78);

// simple_status_window_layout_entries, the layout table simple_status_window_layout
// points at (frame sprite, two text/value entries, the HP and TP gauges, three icon sprites).
struct SimpleStatusWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    LayoutEntryCopyRecord rec_3;
    LayoutEntryCopyRecord rec_4;
    SpritePartLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    SpritePartLayoutRecord rec_7;
};

struct WindowDrawContext;
class WindowSpritePart;

// Points the lock-on child (array entry 1) at the window's player.
void update_lockon_window(TWindowSimpleStatus *window);
// Fans a ring arc from start_angle to end_angle around center in color.
void draw_photon_blast_fan(TWindowSimpleStatus *window, NJS_POINT2 *center, WindowDrawContext *ctx, u32 color, f32 depth_offset, s32 start_angle, s32 end_angle, f32 radius);
// Draws the photon blast charge ring at pos: one full ring in the colour of the
// current hundred and the next colour over the part already charged.
void draw_photon_blast_gauge_ring(TWindowSimpleStatus *window, WindowDrawContext *ctx, const NJS_POINT2 *pos, f32 charge, f32 radius);
void update_photon_blast_player_marker(WindowSpritePart *help, s32 client);
// Updates the photon blast marker (array entry 0) for the window's player; none in the lobby.
void update_status_help_item(TWindowSimpleStatus *window);

#endif
