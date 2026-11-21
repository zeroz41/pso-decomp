#ifndef PSO_OBJECT_SWITCH_TOSWITCHTIMER_H
#define PSO_OBJECT_SWITCH_TOSWITCHTIMER_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOSwitchTimer : public TObjBase {
    TOSwitchTimer(saddr, saddr);
    virtual ~TOSwitchTimer();
    void sub_801782A0();
    void send_switch_states();
    u32 m_90;
    u32 m_94;
    u32 m_98;
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    u16 m_a8;
    u8 _padAA[0x6];
    u8 m_b0;
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
    u8 unk_B1[0x3];
    s32 m_b4;
};

LAYOUT_ASSERT(TOSwitchTimer_size, sizeof(TOSwitchTimer) == 0xB8);

extern "C" {
void TOSwitchTimer__sub_80178584(void);
void TOSwitchTimer__sub_80178588(void);
}

#endif
