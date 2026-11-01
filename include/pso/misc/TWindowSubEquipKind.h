#ifndef PSO_MISC_TWINDOWSUBEQUIPKIND_H
#define PSO_MISC_TWINDOWSUBEQUIPKIND_H

#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"

struct TWindowSubEquipKind : public TWindowMenuIconLine {
    virtual ~TWindowSubEquipKind();
    void draw_tab_label(void *);
    virtual void render();
    s16 m_88;
    s16 m_8a;
    virtual void run_task();
};

typedef char TWindowSubEquipKind_size[sizeof(TWindowSubEquipKind) == 0x8C ? 1 : -1];

extern "C" {
u8 *TWindowSubEquipKind__ct(u8 *window_sub_equip_kind, s32 arg1, s16 arg2);
void *__dt__19TWindowSubEquipKindFv(void *arg0, s16 arg1);
void render__19TWindowSubEquipKindFv(u8 *arg0);
}

// --- C functions defined in TWindowSubEquipKind.cpp ---
extern "C" {
u8 *TWindowSubEquipKind__ct(u8 *window_sub_equip_kind, s32 arg1, s16 arg2);
void *__dt__19TWindowSubEquipKindFv(void *arg0, s16 arg1);
void render__19TWindowSubEquipKindFv(u8 *arg0);
}
// --- end of C functions

#endif
