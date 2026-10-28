#ifndef PSO_MISC_TOTRAPANCIENT02_H
#define PSO_MISC_TOTRAPANCIENT02_H

#include "types.h"
#include "pso/misc/TOTrap.h"

struct TOTrapAncient02 : public TOTrap {
    virtual ~TOTrapAncient02();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_86();
    virtual void render();
    f32 h344;
    f32 h348;
    u32 m_34c;
    s32 reset;
    s32 timer;
    u32 m_358;

    void render_particle_chain();
    void draw_effect_chain();
    static void *create(void *arg0);
    static void destroy_instance();
    static void load_resources();
};

typedef char TOTrapAncient02_size_check[(sizeof(TOTrapAncient02) == 0x35C) ? 1 : -1];

#endif
