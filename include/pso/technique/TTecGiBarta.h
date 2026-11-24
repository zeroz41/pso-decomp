#ifndef PSO_TECHNIQUE_TTECGIBARTA_H
#define PSO_TECHNIQUE_TTECGIBARTA_H

#include "types.h"
#include "pso/technique/TTecShot.h"

class TParticleCtrl;

struct TTecGiBarta : public TTecShot {
    TTecGiBarta(saddr source, u8 *pos, u8 *target, s32 level);
    TTecGiBarta(saddr source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecGiBarta();
    virtual void vfunc_8(void *);
    TParticleCtrl **emitters;
    u16 hitIds[32];
    s32 hitCursor;
    void update_technique_by_phase();
    void create_particles();
    void calc_params();
    static void create(void *owner, Vec *position, Vec *target, s32 level);
    static void create_ex(void *owner, Vec *position, s32 angle, s32 level);
    void run_task();
    void render();
};
LAYOUT_ASSERT(TTecGiBarta_size, sizeof(TTecGiBarta)==0x178);

#endif
