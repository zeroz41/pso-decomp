#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H

#include <stddef.h>

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMenu;

struct TWindowMessageYesNo : public TObject {
    TWindowMessageYesNo(TObject *parent, s32 client_id, void *arg3, void *arg4);
    virtual ~TWindowMessageYesNo();
    s32 is_child_visible();
    u32 m_1c;
    u32 m_20;
    s32 client_id;
    uaddr m_28;
    TWindowMenu *choice_menu;
    void set_choice_menu_flag70_bit10();
    virtual void render();
    virtual void run_task();
    static TWindowMessageYesNo *create(void *parent, s32 client_id, void *arg2, void *arg3);
    void set_menu_selected_index(s16 index);
    void open_yes_no_prompt_with_text(s32 text, s32 pos, f32 width);
};

LAYOUT_ASSERT(TWindowMessageYesNoChoiceMenuOffset, offsetof(TWindowMessageYesNo, choice_menu) == 0x2C);
LAYOUT_ASSERT(TWindowMessageYesNo_size, sizeof(TWindowMessageYesNo) == 0x30);
#endif
