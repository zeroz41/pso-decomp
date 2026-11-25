#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEYESNO_H

#include <stddef.h>

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMenu;
struct NJS_POINT2;

struct TWindowMessageYesNo : public TObject {
    TWindowMessageYesNo(TObject *parent, s32 client_id, void *yes_label, void *no_label);
    virtual ~TWindowMessageYesNo();
    s32 is_child_visible();
    void close();
    s32 get_selected_value();
    s32 is_cancelled();
    u32 no_text;
    u32 yes_text;
    s32 client_id;
    TWindowMenu *message_menu;
    TWindowMenu *choice_menu;
    void set_choice_menu_flag70_bit10();
    virtual void render();
    virtual void run_task();
    static TWindowMessageYesNo *create(void *parent, s32 client_id, void *yes_label, void *no_label);
    void set_menu_selected_index(s16 index);
    void open_yes_no_prompt_with_text(s32 text, const NJS_POINT2 *pos, f32 width);
    void get_choice_menu_position(NJS_POINT2 *position);
    void move_to(const NJS_POINT2 *position);
};

LAYOUT_ASSERT(TWindowMessageYesNoChoiceMenuOffset, offsetof(TWindowMessageYesNo, choice_menu) == 0x2C);
LAYOUT_ASSERT(TWindowMessageYesNo_size, sizeof(TWindowMessageYesNo) == 0x30);
#endif
