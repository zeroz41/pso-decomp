#ifndef PSO_UI_WINDOW_TWINDOWSUBEQUIPKIND_H
#define PSO_UI_WINDOW_TWINDOWSUBEQUIPKIND_H

#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
struct WindowDrawContext;

struct WindowDrawContext;

struct TWindowSubEquipKind : public TWindowMenuIconLine {
    static const char *class_name;
    TWindowSubEquipKind(u8 *parent, s32 client);
    virtual ~TWindowSubEquipKind();
    void draw_tab_label(WindowDrawContext *context);
    void set_trade_state(s16 trade_state);
    virtual void render();
    s16 trade_state;  // indexes the status-display tab labels; 4 after the list opens
    s16 state_timer;  // 60 when set_trade_state enters state 3, counted down to 0
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubEquipKind_size, sizeof(TWindowSubEquipKind) == 0x8C);


struct NJS_POINT2;

TWindowSubEquipKind *create_equip_kind_window(const NJS_POINT2 *position, const NJS_POINT2 *size, s32 client);

#endif
