#ifndef PSO_OBJECT_TOBJCOMPUTER_H
#define PSO_OBJECT_TOBJCOMPUTER_H

#include "types.h"
#include "pso/object/TObjMesBase.h"

struct TObjComputer : public TObjMesBase {
    virtual ~TObjComputer();
    virtual void vfunc_14();
    virtual void clear_ref_if_destroyed();
    virtual void debug_draw_label();
    u32 m_bc;
    f32 uv_scroll_time; /* UV scroll accumulator: +0.2 per tick, the mesh scrolls once it reaches 1 (name inferred) */
    u32 m_c4;
    s32 draw_model();
    virtual void render();
    void *create();
    static void free_resources();
};

typedef char TObjComputer_size[sizeof(TObjComputer) == 0xC8 ? 1 : -1];
#endif
