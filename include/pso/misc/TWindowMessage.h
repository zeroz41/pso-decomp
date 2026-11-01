#ifndef PSO_MISC_TWINDOWMESSAGE_H
#define PSO_MISC_TWINDOWMESSAGE_H

#include "types.h"
#include "pso/misc/TWindowAddition.h"

struct TWindowMessageLine {
    s32 flags;
    s32 timer;
};

struct TWindowMessage : public TWindowAddition {
    virtual ~TWindowMessage();
    virtual void run_task();
    virtual void render();
    void update_scroll();
    void retire_scrolled_lines();
    void advance_reveal_cursor();
    void scroll_up_line(u8 *);
    int append_line(int text, int mode);
    static u8 *create(s32 arg0, s32 arg1, u32 arg2, s32 arg3);
    static u8 *create(void *arg0, s32 arg1, s32 arg2);
    u8 unk_1C[0x4];
    s16 m_20;
    u8 unk_22[0x2];
    void* m_24;
    u8 _pad28[0x4];
    u32 m_2c;
    u8 unk_30[0x8];
    f32 m_38;
    u8 unk_3C[0x4];
    u32 m_40;
    u8 unk_44[0x4];
    f32 m_48;
    f32 m_4c;
    u8 unk_50[0xC];
    u32 m_5c;
    u8 unk_60[0xC];
    f32 m_6c;
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

typedef char TWindowMessage_size[sizeof(TWindowMessage) == 0x90 ? 1 : -1];
#endif
