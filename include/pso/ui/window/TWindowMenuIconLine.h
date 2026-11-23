#ifndef PSO_UI_WINDOW_TWINDOWMENUICONLINE_H
#define PSO_UI_WINDOW_TWINDOWMENUICONLINE_H
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

struct TItem;
struct WindowScrollBar;

class TWindowMenuIconLine : public TWindowAddition {
public:
    TWindowMenuIconLine(u8 *parent, u32 count, s16 client, u8 *descriptor);
    TWindowMenuIconLine(u8 *parent, u32 count, s16 client);
    virtual ~TWindowMenuIconLine();
    virtual void run_task();
    virtual void render();
    virtual void init(u32, s32);
    void draw_selected_list_entry(saddr);
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
    void add_list_entry(u8 icon, s32 src, s32 item);
    void add_list_entry(TItem *item, s32 index);
    void add_item(TItem *item, s32 price, s32 index);
    saddr get_cursor_value();
    void calc_content_extent();
    void disable_cancel();
    void advance_line(s32 message);
    u16 state_flags;
    s16 entry_count;
    s16 cursor;
    s16 entry_capacity;
    s16 m_78;
    u8 unk_7A[0x2];
    s32 m_7c;
    void * status_display;
    WindowScrollBar *scroll_bar; // created by create_menu_scroll_bar, drawn by draw_window_scrollbar
};
LAYOUT_ASSERT(TWindowMenuIconLine_size, sizeof(TWindowMenuIconLine) == 0x88);

#endif
