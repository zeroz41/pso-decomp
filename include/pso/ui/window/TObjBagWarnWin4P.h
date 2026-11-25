#ifndef PSO_UI_WINDOW_TOBJBAGWARNWIN4P_H
#define PSO_UI_WINDOW_TOBJBAGWARNWIN4P_H
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;

class TObjBagWarnWin4P : public TObject {
public:
    TObjBagWarnWin4P(TObject *parent);
    virtual ~TObjBagWarnWin4P();
    virtual void run_task();
public:
    s32 check_can_open();
    static const char *class_name;
    static f32 message_window_size[2];
    void create_window();

    TWindowMessage *message_window;
    char message_text[0x80];
    s32 open_delay; // name inferred: frames left before the window opens
};

LAYOUT_ASSERT(TObjBagWarnWin4P_size, sizeof(TObjBagWarnWin4P) == 0xA4);

#endif
