#ifndef PSO_UI_WINDOW_TCUSTOMIZEMENUCTRL_H
#define PSO_UI_WINDOW_TCUSTOMIZEMENUCTRL_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowSubCustomSelect;
struct PaletteAction;

// The main menu's customize submenu (TWindowMainMenu ids 0 and 1): the custom
// equip list, the custom select window it opens and a help window.
class TCustomizeMenuCtrl : public TObject {
public:
    TCustomizeMenuCtrl(TWindowMainMenu *parent, s32 client);
    virtual ~TCustomizeMenuCtrl();
    void update_customize_help_text(const PaletteAction *action);
    virtual void render();
    virtual void run_task();
    u8 state;
    u8 pad_1D[0x3];
    s32 client_id;
    TWindowMainMenu *main_menu;
    uaddr custom_equip;
    TWindowSubCustomSelect *custom_select;
    uaddr help_window;
    u16 help_kind;
    u16 help_id;
};
LAYOUT_ASSERT(TCustomizeMenuCtrl_size, sizeof(TCustomizeMenuCtrl) == 0x38);

#endif
