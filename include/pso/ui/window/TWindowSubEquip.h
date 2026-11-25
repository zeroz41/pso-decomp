#ifndef PSO_UI_WINDOW_TWINDOWSUBEQUIP_H
#define PSO_UI_WINDOW_TWINDOWSUBEQUIP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowHelpItem;
struct TWindowMainMenu;
class TWindowMenuIconLine;

struct TWindowSubEquip : public TObject {
    TWindowSubEquip(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubEquip();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 m_24;
    u32 client_id;
    TWindowMainMenu *parent;
    TWindowHelpItem *window_help_item;
    TWindowMenuIconLine *equip_list;
    TWindowMenuIconLine *equip_kind_list;
    void update_displayed_item();
    void update();
    s32 open_equip_kind_list(u32 arg1);
    virtual void render();
    virtual void run_task();
    void apply_slot_selection();
};

LAYOUT_ASSERT(TWindowSubEquip_size, sizeof(TWindowSubEquip) == 0x3C);
#endif
