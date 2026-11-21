#ifndef PSO_TECHNIQUE_TTECDEBAND_H
#define PSO_TECHNIQUE_TTECDEBAND_H

#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecDeband : public TTecPlayerInfluence {
    TTecDeband(void *owner, void *pos, void *arg3, s32 level);
    TTecDeband(void *owner, void *pos, s32 level);
    virtual ~TTecDeband();
    virtual void vfunc_7(void *);
    virtual void run_task();
    u32 m_e0;
    u8 _padE4[0x58];
    u32 m_13c;
    int init_params();
    void update_effect_params();
    static void create(saddr arg0, saddr arg1, saddr arg2, s32 arg3);
    static void create(void *owner, void *pos, s32 level);
    virtual void render();
    void play_state_sound();
};

LAYOUT_ASSERT(TTecDeband_size, sizeof(TTecDeband) == 0x140);

extern "C" {
void *__dt__10TTecDebandFv(void *arg0, s16 arg1);
}

#endif
