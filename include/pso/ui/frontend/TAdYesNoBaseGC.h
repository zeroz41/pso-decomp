#ifndef PSO_UI_FRONTEND_TADYESNOBASEGC_H
#define PSO_UI_FRONTEND_TADYESNOBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

struct TWindowMessage;
struct TWindowMenu;

struct TAdYesNoBaseGC : public TObject {
    static const char *class_name;
    TAdYesNoBaseGC(TObject *parent);
    virtual ~TAdYesNoBaseGC();
    virtual void on_accept() = 0;
    virtual void on_cancel() = 0;
    virtual void on_yes_chosen() {}
    virtual void on_no_chosen() {}
    virtual const char *get_message_text() = 0;  // the prompt text: get_localized_text_entry
    virtual void run_dialog();
    virtual void render_dialog();
    TWindowMessage *create_message_window();
    u32 state;
    u32 prev_state;
    u32 exit_state;
    u32 state_frames;
    u32 default_selection;
    NJS_POINT2 message_position;
    NJS_POINT2 message_size;
    TWindowMessage *message_window;
    TWindowMenu *menu_window;
    TWindowMenu *create_menu_window();
    void init_parts(void *position, void *size);
};

LAYOUT_ASSERT(TAdYesNoBaseGC_size, sizeof(TAdYesNoBaseGC) == 0x48);
#endif
