#ifndef PSO_UI_FRONTEND_TADDIALINGMESSAGEWINDOW_H
#define PSO_UI_FRONTEND_TADDIALINGMESSAGEWINDOW_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdDialingMessageWindow : public TObject {
    TAdDialingMessageWindow(const char *message, u32 delay);
    virtual ~TAdDialingMessageWindow();
    u32 flags;
    const char *message;
    TObject *timer;
    TObject *line_root;
    void set_flag_and_notify();
    void run_child_tasks();
    virtual void render();
};

LAYOUT_ASSERT(TAdDialingMessageWindow_size, sizeof(TAdDialingMessageWindow) == 0x2C);

class TUnk_804F3428 : public TObject {
public:
    TUnk_804F3428(TObject *parent, TAdDialingMessageWindow *window, u32 delay);
    virtual ~TUnk_804F3428();
    virtual void run_task();
    u32 countdown;
    TAdDialingMessageWindow *window;
};
LAYOUT_ASSERT(TUnk_804F3428_size, sizeof(TUnk_804F3428) == 0x24);

#endif
