#ifndef PSO_OBJECT_TOBJRADERHIDECOL_H
#define PSO_OBJECT_TOBJRADERHIDECOL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjRaderHideCol : public TObjBase {
    virtual ~TObjRaderHideCol();
    u8 unk_90[0x4];
    u32 m_94;
    virtual void render();
    virtual void run_task();
};

typedef char TObjRaderHideCol_size[sizeof(TObjRaderHideCol) == 0x98 ? 1 : -1];

extern "C" {
u8 *TObjRaderHideCol__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__16TObjRaderHideColFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjRaderHideCol.cpp ---
extern "C" {
u8 *TObjRaderHideCol__ct(u8 *rader_hide_col, s32 arg1, s32 arg2);
void *__dt__16TObjRaderHideColFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
