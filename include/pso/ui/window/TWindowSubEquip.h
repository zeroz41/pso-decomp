#ifndef PSO_UI_WINDOW_TWINDOWSUBEQUIP_H
#define PSO_UI_WINDOW_TWINDOWSUBEQUIP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubEquip : public TObject {
    TWindowSubEquip(s32 arg1, s32 arg2);
    virtual ~TWindowSubEquip();
    int build_equipment_list();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    void update_displayed_item();
    void update();
    static void open_submenu(s32 arg0, s32 arg1);
    s32 open_equip_kind_list(u32 arg1);
    virtual void render();
    virtual void run_task();
    void update_window();
    void apply_slot_selection();
};

typedef char TWindowSubEquip_size[sizeof(TWindowSubEquip) == 0x3C ? 1 : -1];
#endif
