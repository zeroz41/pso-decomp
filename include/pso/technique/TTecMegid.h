#ifndef PSO_TECHNIQUE_TTECMEGID_H
#define PSO_TECHNIQUE_TTECMEGID_H

#include "types.h"
#include "pso/technique/TTecShot.h"

struct TTecMegid : public TTecShot {
    static const char *class_name;
    TTecMegid(saddr source, u8 *pos, u8 *target, s32 level);
    TTecMegid(saddr source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecMegid();
    void run_task();
    virtual void apply_to_target(TObjChara *);
    void **emitters;   // one particle per row of the band's megid_emitter_bands entry
    u16 hitIds[32];    // entities already hit, 0xFFFF when free
    s32 hitCursor;     // next free hitIds slot, capped at 31
    void update_by_state();
    void spawn_particle_emitters();
    void init_parameters();
    static void create(saddr source, saddr pos, saddr target, s32 level);
    static void create_ex(saddr source, saddr pos, s32 angle, s32 level);
    void render();
    f32 pad_178;  // cleared by both constructors, never read
};

LAYOUT_ASSERT(TTecMegid_size, sizeof(TTecMegid) == 0x17C);
#endif
