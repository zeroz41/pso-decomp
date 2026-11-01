#ifndef PSO_MISC_TWINDOWMENUICONLINE_H
#define PSO_MISC_TWINDOWMENUICONLINE_H
#include "types.h"
#include "pso/misc/TWindowAddition.h"

struct Scroll_8026D790;

class TWindowMenuIconLine : public TWindowAddition {
public:
    virtual ~TWindowMenuIconLine();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_6(u32, s32);
    void draw_selected_list_entry(s32);
    void update_scroll_offset();
    void clamp_item_list_scroll();
    void center_list_selection();
    void ensure_status_display(s32);
    void create_menu_scroll_bar();
    void move_cursor();
    void move_cursor_next();
    void handle_open();
    void set_flag4();
    int get_flag();
    int is_decided();
    int is_cancelled();
    void clear_decided();
    void reset_list();
    void add_list_entry(s32 arg1, s32 arg2, s32 arg3);
    s32 get_cursor_value();
    void calc_content_extent();
    void disable_cancel();
    u8 unk_1C[0x4];
    s16 m_20;
    u8 unk_22[0xA];
    s32 m_2c;
    u8 unk_30[0x8];
    f32 m_38;
    u8 unk_3C[0x10];
    void* m_4c;
    u8 unk_50[0xC];
    s32 m_5c;
    u8 unk_60[0x4];
    u32 m_64;
    u32 m_68;
    u8 unk_6C[0x4];
    u16 state_flags;
    s16 entry_count;
    s16 cursor;
    s16 entry_capacity;
    s16 m_78;
    u8 unk_7A[0x2];
    s32 m_7c;
    void * status_display;
    Scroll_8026D790 *unk_84;
};
typedef char TWindowMenuIconLine_size[sizeof(TWindowMenuIconLine) == 0x88 ? 1 : -1];

#endif
