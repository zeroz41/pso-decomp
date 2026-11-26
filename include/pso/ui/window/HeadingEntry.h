#ifndef PSO_UI_WINDOW_HEADINGENTRY_H
#define PSO_UI_WINDOW_HEADINGENTRY_H

#include "types.h"

struct WindowDrawContext;
struct NJS_TEXLIST;

__declspec(section ".data") extern NJS_TEXLIST f256_hyouji_texlist;

// A heading line of a window (text, position, width) that reveals its text over time.
class HeadingEntry {
public:
    HeadingEntry(f32 *position, saddr title, s8 entry_state, s32 client_id);
    ~HeadingEntry();
    void update_color();
    void set_state(s8 entry_state);
    void draw_tab(WindowDrawContext *context);
    void draw(WindowDrawContext *context);
    void advance_reveal();
    s32 is_enabled(); // flags bit 0 clear: drawn white in state 0, else grey

    saddr text;
    f32 x;
    f32 y;
    f32 width;
    f32 text_width;
    u32 color;
    u8 state;
    u8 flags;
    u8 pad_1A[2];
    f32 reveal_pos;
    f32 reveal_step;
};

// The title heading a window keeps above its frame.
class WindowHeading : public HeadingEntry {
public:
    WindowHeading(saddr title, s32 client_id);
    ~WindowHeading();
    void render(WindowDrawContext *context);
    void update();
};

// Where a window's title heading sits relative to the window.
extern const f32 heading_title_offset[2];

void draw_window_tab(WindowDrawContext *context, f32 *position, f32 width, u8 style);
f32 get_base_y(f32 width);
f32 calc_title_overflow_width(f32 text_width);
f32 get_heading_frame_width(HeadingEntry *heading);
void draw_heading_text(HeadingEntry *heading, WindowDrawContext *context);

struct WindowTabUV {
    f32 u, v;
};


#endif
