#ifndef PSO_BOSS_TBOSS8DRAGONEFFTAIL_H
#define PSO_BOSS_TBOSS8DRAGONEFFTAIL_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

struct TBoss8DragonEffTail : public TUnk_804928CC {
    virtual ~TBoss8DragonEffTail();
    virtual void apply_hit_if_active(void *, f32 *);
    virtual void run_task();
    u32 m_b0;
    u32 m_b4;
    u32 m_b8;
    u32 m_bc;
    void* m_c0;
    virtual void render();
    void enable();
    void disable();
    int get_state();
    static void free_statics();
    u8 unk_C4[0x8];
};

typedef char TBoss8DragonEffTail_size[sizeof(TBoss8DragonEffTail) == 0xCC ? 1 : -1];

extern "C" {
void TBoss8DragonEffTail__vt18(s32 arg0, s32 arg1);
void *__dt__19TBoss8DragonEffTailFv(void *arg0, s16 arg1);
void fn_802FE48C(void);
void run_task__19TBoss8DragonEffTailFv(u8 *arg0p);
}

// --- C functions defined in TBoss8DragonEffTail.cpp ---
extern "C" {
void TBoss8DragonEffTail__vt18(s32 arg0, s32 arg1);
void *__dt__19TBoss8DragonEffTailFv(void *arg0, s16 arg1);
void fn_802FE48C(void);
void run_task__19TBoss8DragonEffTailFv(u8 *arg0p);
}
// --- end of C functions

extern "C" {
void fn_802FE8CC(void);
}

#endif
