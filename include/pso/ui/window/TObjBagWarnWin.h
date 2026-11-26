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
    s32 should_show_warning();
    static const char *class_name;
    static f32 message_window_size[2];
    void open_message_window();
    static void *create(TObject *bag_warn_win);

    TWindowMessage *message_window;
    char message_text[0x80];
    s32 open_delay; // name inferred: frames left before the window opens
};

LAYOUT_ASSERT(TObjBagWarnWin_size, sizeof(TObjBagWarnWin) == 0xA4);

class TObjBagWarnWin4P;

TObjBagWarnWin4P *create_bag_warn_window_4p(TObject *parent);

s32 is_map_visible();

#endif
