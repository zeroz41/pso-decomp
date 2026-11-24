#ifndef PSO_UI_WINDOW_TWINDOWMESSAGE_H
#define PSO_UI_WINDOW_TWINDOWMESSAGE_H

#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

struct NJS_POINT2;

struct TWindowMessageLine {
    s32 flags;
    s32 timer;
};

struct TWindowMessage : public TWindowAddition {
    TWindowMessage(saddr parent, u32 rows, s32 client);
    virtual ~TWindowMessage();
    virtual void run_task();
    virtual void render();
    void update_scroll();
    void retire_scrolled_lines();
    void advance_reveal_cursor();
    void scroll_up_line(u8 *);
    int append_line(int text, int mode);
    static u8 *create(saddr parent, const f32 *size, uaddr rows, s32 client);
    static u8 *create(const NJS_POINT2 *pos, const f32 *size, saddr rows);
    s32 oldest_line;
    s32 reveal_line;
    u32 line_display_ticks;
    TWindowMessageLine *lines;
    f32 next_line_y;
    f32 target_scroll_y;
    s32 next_line;
    s32 line_count;
    void complete_reveal();
    void update_line_timers();
};

LAYOUT_ASSERT(TWindowMessage_size, sizeof(TWindowMessage) == 0x90);
extern "C" u8 *create_message_window_for_size(NJS_POINT2 *pos, NJS_POINT2 *size);

#endif
