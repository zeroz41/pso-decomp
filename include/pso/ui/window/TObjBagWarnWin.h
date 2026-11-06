#ifndef PSO_UI_WINDOW_TOBJBAGWARNWIN_H
#define PSO_UI_WINDOW_TOBJBAGWARNWIN_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBagWarnWin : public TObject {
public:
    virtual ~TObjBagWarnWin();
    virtual void run_task();
public:
    static s32 should_show_warning(void *arg0);
    void open_message_window();
    static void *create(void *arg0);
};

extern "C" {
void *__ct__14TObjBagWarnWinFv(void *bag_warn_win, void *parent);
}

#endif
