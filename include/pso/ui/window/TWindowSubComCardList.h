#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARDLIST_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARDLIST_H

#include "types.h"
struct NJS_POINT2;
#include "pso/ui/window/TWindowMenu.h"

struct PageIndicator;

struct TWindowSubComCardList : public TWindowMenu {
    TWindowSubComCardList(const NJS_POINT2 *position);
    TWindowSubComCardList(const NJS_POINT2 *position, saddr card_slot, s32 arg3, s32 arg4);
    virtual ~TWindowSubComCardList();
    static const char *class_name;
    void refresh_page();
    void draw_card_list_selection(u8 *);

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
