#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARDLIST_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARDLIST_H

#include "types.h"
#include "pso/ui/window/TWindowMenu.h"

struct TWindowSubComCardList : public TWindowMenu {
    TWindowSubComCardList(void *parent);
    TWindowSubComCardList(void *parent, s32 arg2, s32 arg3, s32 arg4);
    virtual ~TWindowSubComCardList();
    void sub_80275360();
    void draw_card_list_selection(u8 *);
    s16 get_field_72();
    s16 get_selected_index();
    void update_layout_height(f32);
    void set_scroll_target(f32, f32);
    void set_selected_index(s16);
    void reset_entries();
    void sub_8026556C();
    void update_scroll_target_position();
    void set_flag70_bit100();
    void set_flag70_bit10();
    virtual void render();
    uaddr m_8c;
    uaddr m_90;
    uaddr m_94;
    u32 m_98;
    u8 m_9c;
    virtual void run_task();
    void init(int a1, int a2, int a3);
    u8 unk_9D[0x3];
};

LAYOUT_ASSERT(TWindowSubComCardList_size, sizeof(TWindowSubComCardList) == 0xA0);
#endif
