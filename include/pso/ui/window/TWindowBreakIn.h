#ifndef PSO_UI_WINDOW_TWINDOWBREAKIN_H
#define PSO_UI_WINDOW_TWINDOWBREAKIN_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayoutRecord.h"

struct TWindowBreakIn : public TWindowBase {
    static const char *class_name;
    TWindowBreakIn();
    virtual ~TWindowBreakIn();
    virtual void render();
    virtual void run_task();
    void update_entry_visibility();
};

LAYOUT_ASSERT(TWindowBreakIn_size, sizeof(TWindowBreakIn) == 0x60);

// window_break_in_layout_entries, the layout table window_break_in_layout points at
// (eight sprite parts, cf. window_timer_layout_entries).
struct BreakInWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec[8];
};


// The break-in indicators: short_mail_flags bit 3 trade, bit 2 com card, bit 1 guild card receive.
s32 is_com_card_active(void);
s32 is_guild_card_receive_active(void);
void set_guild_card_receive_active();
s32 is_trade_active(void);

#endif
