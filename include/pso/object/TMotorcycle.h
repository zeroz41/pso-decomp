#ifndef PSO_OBJECT_TMOTORCYCLE_H
#define PSO_OBJECT_TMOTORCYCLE_H

#include "types.h"
#include "pso/object/TObjMesBase.h"

struct TMotorcycle : public TObjMesBase {
    virtual ~TMotorcycle();
    virtual void vfunc_14();
    virtual void debug_draw_label();
    u32 m_bc;
    virtual void render();
    void *create();
    static void free_statics();
    static void load_resources();
    static void add_entry(s16 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
};

typedef char TMotorcycle_size[sizeof(TMotorcycle) == 0xC0 ? 1 : -1];

extern "C" {
void *TMotorcycle__ct(void *arg0, void *arg1, void *arg2);
void *__dt__11TMotorcycleFv(void *arg0, s16 arg1);
}

#endif
