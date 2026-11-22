#ifndef PSO_UI_WINDOW_TOBJBAGWARNWIN_H
#define PSO_UI_WINDOW_TOBJBAGWARNWIN_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;

class TObjBagWarnWin : public TObject {
public:
    TObjBagWarnWin(TObject *parent);
    virtual ~TObjBagWarnWin();
    virtual void run_task();
public:
    static s32 should_show_warning(void *arg0);
    void open_message_window();
    static void *create(void *bag_warn_win);

    TWindowMessage *message_window;
    char message_text[0x80];
    s32 open_delay; // name inferred: frames left before the window opens
};

LAYOUT_ASSERT(TObjBagWarnWin_size, sizeof(TObjBagWarnWin) == 0xA4);

#endif
