#ifndef PSO_UI_WINDOW_TWINDOWMESSAGE_H
#define PSO_UI_WINDOW_TWINDOWMESSAGE_H

#include "types.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/unk/WindowLayoutRecord.h"

struct NJS_POINT2;

struct TWindowMessageLine {
    s32 flags;
    s32 timer;
};

// A window's width and height, as create's size argument reads them.
struct WindowSize {
    f32 dimensions[2];
};

struct TWindowMessage : public TWindowAddition {
    TWindowMessage(const NJS_POINT2 *position, u32 rows, s32 client);
    virtual ~TWindowMessage();
    static const char *class_name;
    virtual void run_task();
    virtual void render();
    void update_scroll();
    void retire_scrolled_lines();
    void advance_reveal_cursor();
    void scroll_up_line(u8 *line_entry);
    int append_line(const char *text, int mode);
    static TWindowMessage *create(const NJS_POINT2 *position, const f32 *size, uaddr rows, s32 client);
    static TWindowMessage *create(const NJS_POINT2 *pos, const f32 *size, saddr rows);
    s32 oldest_line;
    s32 reveal_line;
    u32 line_display_ticks;
    TWindowMessageLine *lines;
    f32 next_line_y;
    f32 target_scroll_y;
    s32 next_line;
    s32 line_count;
    void complete_reveal();
    // Adds "label : value" with the colon at the window's centre.
    s32 add_label_value_line(const char *label, const char *value, u32 flags);
    void update_line_timers();
};

s32 append_message_window_line(TWindowMessage *self, const char *text, s32 flags, s32 color);

LAYOUT_ASSERT(TWindowMessage_size, sizeof(TWindowMessage) == 0x90);
TWindowMessage *create_message_window_for_size(NJS_POINT2 *pos, NJS_POINT2 *size);

// message_window_layout_entries, the layout table message_window_settings points at: one
// text record per row, rows set to the line count by set_message_window_size.
struct MessageWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};

struct WindowDescriptor;

void set_message_window_default_flags(void);
void set_message_window_flags(s32 flags);
WindowDescriptor *get_message_window_settings(void);

#endif
