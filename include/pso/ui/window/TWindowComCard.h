#ifndef PSO_UI_WINDOW_TWINDOWCOMCARD_H
#define PSO_UI_WINDOW_TWINDOWCOMCARD_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

// The six text entries of the card: name, card id, class, language, stat and keyboard.
struct ComCardLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord text[6];
};

struct TWindowComCard : public TWindowBase {
    static const char *class_name;
    TWindowComCard(const NJS_POINT2 *position, void *data);
    virtual ~TWindowComCard();
    virtual void render();
    virtual void run_task();
    void set_display_value(s32 card_index, s32 cards);
    // Shows record `card_index` of a GuildCardEntry table (set_display_value takes GuildCardSlots).
    void set_display_entry(s32 card_index, s32 records);
    static TWindowComCard *create_for_card(const NJS_POINT2 *position, s32 index, saddr card_slot);
    static TWindowComCard *create(const NJS_POINT2 *position, s32 index);
    void*get_kbd_ptr();
    void set_help_mode(s32 mode);
    void*get_card_name_ptr();
};

LAYOUT_ASSERT(TWindowComCard_size, sizeof(TWindowComCard) == 0x60);

s32 get_class_name_text(s32 class_index);
#endif
