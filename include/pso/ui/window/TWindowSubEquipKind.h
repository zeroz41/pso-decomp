#ifndef PSO_UI_WINDOW_TWINDOWSUBEQUIPKIND_H
#define PSO_UI_WINDOW_TWINDOWSUBEQUIPKIND_H

#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

struct TWindowSubEquipKind : public TWindowMenuIconLine {
    TWindowSubEquipKind(u8 *parent, s32 client);
    virtual ~TWindowSubEquipKind();
    void draw_tab_label(void *);
    virtual void render();
    s16 m_88;
    s16 m_8a;
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubEquipKind_size, sizeof(TWindowSubEquipKind) == 0x8C);

extern const char *TWindowSubEquipKind__class_name;

struct NJS_POINT2;

extern "C" {
TWindowSubEquipKind *create_equip_kind_window(saddr position, const NJS_POINT2 *size, s32 client);
}

#endif
