#ifndef PSO_ENEMY_TOBJENEHOLDEFFECT_H
#define PSO_ENEMY_TOBJENEHOLDEFFECT_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjEneHoldEffect : public TObjBase {
    virtual ~TObjEneHoldEffect();
    virtual void run_task();
    u32 m_90;
    u16 m_94;
    u8 _pad96[0x2];
    u32 m_98;
    u32 m_9c;
    u8 is_camera_visible();
    u8 is_in_view();
    virtual void render();
    static void create(void *arg0, void *arg1, void *arg2);
    s32 validate_6x49_packet();
};

typedef char TObjEneHoldEffect_size[sizeof(TObjEneHoldEffect) == 0xA0 ? 1 : -1];
#endif
