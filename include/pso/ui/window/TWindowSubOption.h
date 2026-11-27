#ifndef PSO_UI_WINDOW_TWINDOWSUBOPTION_H
#define PSO_UI_WINDOW_TWINDOWSUBOPTION_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;
class TWindowCheckBox;

// The main menu's "Options" sub-window: a list of the six options and the value window of the
// selected one.
class TWindowSubOption : public TObject {
public:
    TWindowSubOption(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubOption();
    void update_photon_selection();
    TWindowMenu *create_option_menu_window();
    TWindowCheckBox *create_option_value_window(s32);
    void update_quest_board_card_flags();
    virtual void render();
    virtual void run_task();
    s8 state;
    u8 vibration;          // the vibration option (entry 4) as last shown
    u8 pad_1e[0x2];
    saddr client_id;
    TWindowMainMenu *parent;
    TWindowMenu *menu;     // the option list create_option_menu_window makes
    TWindowCheckBox *value_window;      // the value window create_option_value_window opens for the selected option
};
LAYOUT_ASSERT(TWindowSubOption_size, sizeof(TWindowSubOption) == 0x30);

#endif
