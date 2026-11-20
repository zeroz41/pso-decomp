#ifndef PSO_UNK_TUNK_804D1AD0_H
#define PSO_UNK_TUNK_804D1AD0_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;
struct TWindowSubStatusDisp;

// Opened by TWindowMainMenu::create_submenu (case 25): a three-entry category menu (messages 0x10A-0x10C)
// over a TWindowSubStatusDisp page window that follows the selected entry.
class TUnk_804D1AD0 : public TObject {
public:
    TUnk_804D1AD0(TWindowMainMenu *parent, s32 client);
    virtual ~TUnk_804D1AD0();
    virtual void render();
    virtual void run_task();
    TWindowMenu *create_status_category_menu();
    s32 client_id;
    TWindowMainMenu *main_menu;
    TWindowMenu *category_menu;
    TWindowSubStatusDisp *status_disp;
};
LAYOUT_ASSERT(TUnk_804D1AD0_size, sizeof(TUnk_804D1AD0) == 0x2C);

#endif
