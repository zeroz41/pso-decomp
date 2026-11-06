#ifndef PSO_TECHNIQUE_TTECGIBARTA_H
#define PSO_TECHNIQUE_TTECGIBARTA_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecGiBarta : public TUnk_804CCC68 {
    virtual ~TTecGiBarta();
    virtual void vfunc_8(void *);
    u8 unk_130[0x44];
    u32 m_174;
    void update_technique_by_phase();
    void create_particles();
    void calc_params();
    void create(void *arg1, void *arg2, void *arg3);
    void create_ex(void *arg1, void *arg2, void *arg3);
    void run_task();
    u8 *construct_facing(void * _w1, void * _w2, void * _w3, void * _w4);
    void render();
};
typedef char TTecGiBarta_size[sizeof(TTecGiBarta)==0x178?1:-1];

#endif
