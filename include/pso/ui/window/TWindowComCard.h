#ifndef PSO_UI_WINDOW_TWINDOWCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWCOMCARD_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowComCard : public TWindowBase {
    TWindowComCard(void *position, void *data);
    virtual ~TWindowComCard();
    virtual void render();
    virtual void run_task();
    void set_display_value(s32 card_index, s32 cards);
    static u8 *create_for_card(s32 arg0, s32 index, s32 card_slot);
    static void *create(void *parent, void *arg1);
    void*get_kbd_ptr();
    void set_help_mode(s32 mode);
    void*get_card_name_ptr();
};

LAYOUT_ASSERT(TWindowComCard_size, sizeof(TWindowComCard) == 0x60);
#endif
