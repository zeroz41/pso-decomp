#ifndef PSO_TECHNIQUE_TTECMEGID_H
#define PSO_TECHNIQUE_TTECMEGID_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecMegid : public TUnk_804CCC68 {
    virtual ~TTecMegid();
    void run_task();
    u8 unk_130[0x28];
    u32 m_158;
    void update_by_state();
    void spawn_particle_emitters();
    void init_parameters();
    static void create(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void create_ex(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void render();
    u8 *construct_facing(s32 _w1, s32 _w2, s32 _w3, s32 _w4);
    u8 unk_15C[0x18];
    s32 m_174;
    u8 unk_178[0x4];
};

typedef char TTecMegid_size[sizeof(TTecMegid) == 0x17C ? 1 : -1];
#endif
