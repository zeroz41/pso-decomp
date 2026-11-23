#ifndef PSO_OBJECT_SWITCH_TOSWITCHATTACK_H
#define PSO_OBJECT_SWITCH_TOSWITCHATTACK_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOSwitchAttack : public TObjBase {
    TOSwitchAttack(TObject *parent, void *set_data);
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
    static void create_sub(saddr parent, s32 stop_switch, s32 required_switch, s32 type, f32 scale);
    void init_params();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOSwitchAttack_size, sizeof(TOSwitchAttack) == 0xAC);
#endif
