#ifndef PSO_UNK_TUNK_804D1818_H
#define PSO_UNK_TUNK_804D1818_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;

// The main menu's pad option sub-window (vtable 0x804D1818, class name unknown): a list of the six
// options and the value window of the selected one. Field names inferred from their uses.
class TUnk_804D1818 : public TObject {
public:
    virtual ~TUnk_804D1818();
    void update_photon_selection();
    saddr create_option_menu_window();
    saddr sub_8027C884(s32);
    void update_quest_board_card_flags();
    virtual void render();
    virtual void run_task();
    s8 state;
    u8 vibration;          // the vibration option (entry 4) as last shown
    u8 pad_1e[0x2];
    saddr client_id;
    TWindowMainMenu *parent;
    TWindowMenu *menu;     // the option list create_option_menu_window makes
    uaddr value_window;      // the value window sub_8027C884 opens for the selected option
};
LAYOUT_ASSERT(TUnk_804D1818_size, sizeof(TUnk_804D1818) == 0x30);

#endif
