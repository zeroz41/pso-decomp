#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARDLIST_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARDLIST_H

#include "types.h"
#include "pso/ui/window/TWindowMenu.h"

struct PageIndicator;

struct TWindowSubComCardList : public TWindowMenu {
    TWindowSubComCardList(void *parent);
    TWindowSubComCardList(void *parent, s32 card_slot, s32 arg3, s32 arg4);
    virtual ~TWindowSubComCardList();
    static const char *class_name;
    void sub_80275360();
    void draw_card_list_selection(u8 *);
    s16 get_field_72();
    s16 get_selected_index();

    void set_scroll_target(f32, f32);
    void set_selected_index(s16);
    void reset_entries();
    void sub_8026556C();
    void update_scroll_target_position();
    void set_flag70_bit100();
    virtual void render();
    PageIndicator *storage;
    uaddr cards;
    uaddr card_slots;
    u32 card_count;
    u8 empty_message;
    virtual void run_task();
    u8 unk_9D[0x3];
};

LAYOUT_ASSERT(TWindowSubComCardList_size, sizeof(TWindowSubComCardList) == 0xA0);
#endif
