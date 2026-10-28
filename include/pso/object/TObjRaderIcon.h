#ifndef PSO_OBJECT_TOBJRADERICON_H
#define PSO_OBJECT_TOBJRADERICON_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjRaderIcon : public TObjBase {
    virtual ~TObjRaderIcon();
    u32 m_90;
    u32 m_94;
    u32 m_98;
    u8 _pad9C[0x4];
    u32 m_a0;
    virtual void render();
    virtual void run_task();
    void initialize_from_placement();
};

typedef char TObjRaderIcon_size[sizeof(TObjRaderIcon) == 0xA4 ? 1 : -1];

extern "C" {
void *TObjRaderIcon__create(void *arg0);
u8 *TObjRaderIcon__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__13TObjRaderIconFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjRaderIcon.cpp ---
extern "C" {
void *TObjRaderIcon__create(void *arg0);
u8 *TObjRaderIcon__ct(u8 *rader_icon, s32 arg1, s32 arg2);
void *__dt__13TObjRaderIconFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
