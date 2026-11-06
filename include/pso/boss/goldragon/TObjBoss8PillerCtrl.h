#ifndef PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLERCTRL_H
#define PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLERCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjBoss8PillerCtrl : public TObject {
    virtual ~TObjBoss8PillerCtrl();
    virtual void run_task();
    void* m_1c;
    u8 _pad20[0x8];
    u32 m_28;
    u16 m_2c;
    u8 _pad2E[0x2];
    u32 m_30;
    u32 m_34;
    virtual void render();
};

typedef char TObjBoss8PillerCtrl_size[sizeof(TObjBoss8PillerCtrl) == 0x38 ? 1 : -1];

extern "C" {
u8 *TObjBoss8PillerCtrl__ct(u8 *boss8_piller_ctrl, s32 arg1, s32 arg2, s16 arg3);
void TObjBoss8PillerCtrl__sub_8035C034(void *_w0, void *_w1);
void *__dt__19TObjBoss8PillerCtrlFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjBoss8PillerCtrl.cpp ---
extern "C" {
u8 *TObjBoss8PillerCtrl__ct(u8 *boss8_piller_ctrl, s32 arg1, s32 arg2, s16 arg3);
void TObjBoss8PillerCtrl__sub_8035C034(void *_w0, void *_w1);
void *__dt__19TObjBoss8PillerCtrlFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
