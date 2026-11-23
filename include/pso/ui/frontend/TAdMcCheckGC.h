#ifndef PSO_UI_FRONTEND_TADMCCHECKGC_H
#define PSO_UI_FRONTEND_TADMCCHECKGC_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

struct TAdMcCheckGC : public TObject {
    TAdMcCheckGC(TObject *parent, s32 slot);
    virtual ~TAdMcCheckGC();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    s32 card_slot;
    TObject *m_2c;
    TObject *m_30;
    TObject *m_34;
    TObject *m_38;
    virtual void render();
    TObject *create(s32 message);
    virtual void run_task();
};

LAYOUT_ASSERT(TAdMcCheckGC_slot_offset, offsetof(TAdMcCheckGC, card_slot) == 0x28);
LAYOUT_ASSERT(TAdMcCheckGC_warnings_offset, offsetof(TAdMcCheckGC, m_2c) == 0x2C);
LAYOUT_ASSERT(TAdMcCheckGC_size, sizeof(TAdMcCheckGC) == 0x3C);

void set_tex_coord_gen2(s32 arg0, s32 func, s32 arg2, s32 mtx);

extern "C" {
extern TAdMcCheckGC *memcard_cursor_instance_table[];
void TLobby__sub_8033EE38(void *p);
u8 *__dt__12TAdMcCheckGCFv(TAdMcCheckGC *arg0, s16 arg1);
}

// --- C functions defined in TAdMcCheckGC.cpp ---
extern "C" {
void TLobby__sub_8033EE38(void *p);
}
// --- end of C functions

#endif
