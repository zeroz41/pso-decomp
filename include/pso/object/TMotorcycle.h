#ifndef PSO_OBJECT_TMOTORCYCLE_H
#define PSO_OBJECT_TMOTORCYCLE_H

#include "types.h"
#include "pso/object/TObjMesBase.h"

struct TMotorcycle : public TObjMesBase {
    TMotorcycle(TObject *parent, ObjectSetData *placement);
    virtual ~TMotorcycle();
    virtual void vfunc_14();
    virtual void debug_draw_label();
    virtual s32 update_object_view_visibility(f32 depth, f32 radius);
    s32 m_bc; // model index, picked by placement parity (scale.x)
    virtual void render();
    static void free_statics();
    static void load_resources();
    static void add_entry(s16 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
};

typedef char TMotorcycle_size[sizeof(TMotorcycle) == 0xC0 ? 1 : -1];

extern "C" void *create_stage_motorcycle(void *placement);

#endif
