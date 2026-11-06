#ifndef PSO_TECHNIQUE_TTECZONDEEFF_H
#define PSO_TECHNIQUE_TTECZONDEEFF_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TTecZondeEff : public TObject {
public:
    virtual ~TTecZondeEff();
    void randomize_bolt_jitter();
    void calc_lightning_scatter_direction(s32, void *);
    s32 build_lightning_strip(void *, void *, f32 *, f32 *);
    virtual void run_task();
    virtual void render();
public:
    s32 calc_dominant_axis();
    void init_bolt_points();
    static void init_resources();
public:
    u8 *construct(u8 *arg1, u8 *arg2, u8 *arg3, f32 farg0);
};

extern "C" {
u8 *__ct__12TTecZondeEffFv(u8 *object, u8 *arg1, s32 arg2, s32 arg3, f32 farg0);
void clear_zonde_beam_vertex_pointer(void);
}

#endif
