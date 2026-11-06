#ifndef PSO_UI_FRONTEND_TADSCROLLWINGC_H
#define PSO_UI_FRONTEND_TADSCROLLWINGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdScrollWinGC : public TObject {
    virtual ~TAdScrollWinGC();
    void render_status_value();
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0x4];
    f32 m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x4];
    f32 m_38;
    u32 m_3c;
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u32 m_4c;
    u32 m_50;
    virtual void render();
    s32 get_scroll_delay_for_mode();
    void advance_scroll(f32 v);
    void close();
    void close_window();
    virtual void run_task();
};

extern const char *TAdScrollWinGC__class_name;

typedef char TAdScrollWinGC_size[sizeof(TAdScrollWinGC) == 0x54 ? 1 : -1];
#endif
