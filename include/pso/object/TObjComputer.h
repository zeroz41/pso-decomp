#ifndef PSO_OBJECT_TOBJCOMPUTER_H
#define PSO_OBJECT_TOBJCOMPUTER_H

#include "types.h"
#include "pso/object/TObjMesBase.h"

struct NJS_OBJECT;

struct TObjComputer : public TObjMesBase {
    TObjComputer(TObject *parent, ObjectSetData *placement);
    virtual ~TObjComputer();
    virtual void vfunc_14();
    virtual void clear_ref_if_destroyed();
    virtual void debug_draw_label();
    NJS_OBJECT *screen_model;
    f32 uv_scroll_time; /* UV scroll accumulator: +0.2 per tick, the mesh scrolls once it reaches 1 (name inferred) */
    u32 m_c4;
    void draw_model();
    virtual void render();
    static void free_resources();
};

LAYOUT_ASSERT(TObjComputer_size, sizeof(TObjComputer) == 0xC8);
extern "C" void *create_stage_computer(void *placement);
void load_computer_resources();

#endif
