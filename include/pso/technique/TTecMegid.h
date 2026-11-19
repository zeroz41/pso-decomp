#ifndef PSO_TECHNIQUE_TTECMEGID_H
#define PSO_TECHNIQUE_TTECMEGID_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecMegid : public TUnk_804CCC68 {
    TTecMegid(s32 source, u8 *pos, u8 *target, s32 level);
    TTecMegid(s32 source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecMegid();
    void run_task();
    virtual void vfunc_8(void *);
    void **emitters;   // one particle per row of the band's TTecMegid__emitter_bands entry
    u16 hitIds[32];    // entities already hit, 0xFFFF when free
    s32 hitCursor;     // next free hitIds slot, capped at 31
    void update_by_state();
    void spawn_particle_emitters();
    void init_parameters();
    static void create(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void create_ex(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void render();
    u8 unk_178[0x4];
};

typedef char TTecMegid_size[sizeof(TTecMegid) == 0x17C ? 1 : -1];
#endif
