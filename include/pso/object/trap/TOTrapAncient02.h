#ifndef PSO_OBJECT_TRAP_TOTRAPANCIENT02_H
#define PSO_OBJECT_TRAP_TOTRAPANCIENT02_H

#include "types.h"
#include "pso/object/trap/TOTrap.h"

struct TOTrapAncient02 : public TOTrap {
    TOTrapAncient02(TObject *parent, void *set_data);
    virtual ~TOTrapAncient02();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_86();
    virtual void render();
    f32 h344;
    f32 h348;
    s32 spin_angle;     // name inferred: += 0x888 per vfunc_84 frame, the y turn of the fourth model part
    s32 reset;
    s32 timer;
    s32 particle_tev;   // name inferred: rotation_z > 0 in the ctor; render draws with setup_particle_tev when set

    void render_particle_chain();
    void draw_effect_chain();
    static void *create(void *set_data);
    static void destroy_instance();
    static void load_resources();
};

typedef char TOTrapAncient02_size_check[(sizeof(TOTrapAncient02) == 0x35C) ? 1 : -1];

#endif
