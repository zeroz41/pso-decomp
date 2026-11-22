#ifndef PSO_TECHNIQUE_TTECGIBARTA_H
#define PSO_TECHNIQUE_TTECGIBARTA_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecGiBarta : public TUnk_804CCC68 {
    TTecGiBarta(saddr source, u8 *pos, u8 *target, s32 level);
    TTecGiBarta(saddr source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecGiBarta();
    virtual void vfunc_8(void *);
    void **emitters;
    u16 hitIds[32];
    s32 hitCursor;
    void update_technique_by_phase();
    void create_particles();
    void calc_params();
    static void create(void *source, void *origin, void *aim, s32 level);
    static void create_ex(void *source, void *origin, s32 angle, s32 level);
    void run_task();
    void render();
};
LAYOUT_ASSERT(TTecGiBarta_size, sizeof(TTecGiBarta)==0x178);

#endif
