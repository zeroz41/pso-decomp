#ifndef PSO_UI_WINDOW_TWINDOWSTATUSCATEGORYMENU_H
#define PSO_UI_WINDOW_TWINDOWSTATUSCATEGORYMENU_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;
struct TWindowSubStatusDisp;

// Opened by TWindowMainMenu::create_submenu (case 25): a three-entry category menu (messages 0x10A-0x10C)
// over a TWindowSubStatusDisp page window that follows the selected entry.
class TWindowStatusCategoryMenu : public TObject {
public:
    TWindowStatusCategoryMenu(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowStatusCategoryMenu();
    virtual void render();
    virtual void run_task();
    TWindowMenu *create_status_category_menu();
    s32 client_id;
    TWindowMainMenu *main_menu;
    TWindowMenu *category_menu;
    TWindowSubStatusDisp *status_disp;
};
LAYOUT_ASSERT(TWindowStatusCategoryMenu_size, sizeof(TWindowStatusCategoryMenu) == 0x2C);

#endif
