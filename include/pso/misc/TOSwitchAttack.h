#ifndef PSO_MISC_TOSWITCHATTACK_H
#define PSO_MISC_TOSWITCHATTACK_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOSwitchAttack : public TObjBase {
    virtual ~TOSwitchAttack();
    u8 unk_90[0x4];
    f32 m_94;
    u8 unk_98[0x4];
    u32 m_9c;
    u16 m_a0;
    u16 m_a2;
    u16 m_a4;
    u8 m_a6;
    u8 m_a7;
    u32 m_a8;
    static void create_sub(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0);
    void init_params();
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
};

typedef char TOSwitchAttack_size[sizeof(TOSwitchAttack) == 0xAC ? 1 : -1];
#endif
