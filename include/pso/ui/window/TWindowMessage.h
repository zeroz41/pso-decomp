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
    static u8 *create(saddr arg0, const f32 *size, uaddr arg2, s32 arg3);
    static u8 *create(const NJS_POINT2 *pos, const f32 *size, saddr rows);
    u32 m_70;
    s32 m_74;
    u32 m_78;
    TWindowMessageLine *lines;
    f32 unk_80;
    f32 m_84;
    s32 next_line;
    s32 line_count;
    void complete_reveal();
    void update_line_timers();
};

LAYOUT_ASSERT(TWindowMessage_size, sizeof(TWindowMessage) == 0x90);
extern "C" u8 *create_message_window_for_size(NJS_POINT2 *pos, NJS_POINT2 *size);

#endif
