#ifndef PSO_OBJECT_TRAP_TOTRAPANCIENT02_H
#define PSO_OBJECT_TRAP_TOTRAPANCIENT02_H

#include "types.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/system/BmlResourceDescriptor.h"

struct TOTrapAncient02 : public TOTrap {
    TOTrapAncient02(TObject *parent, ObjectSetData *set_data);
    virtual ~TOTrapAncient02();
    virtual void update_springing();
    virtual void update_holding();
    virtual void update_effects();
    virtual void run_demo();
    virtual void vfunc_86();
    virtual void render();
    f32 h344;
    f32 h348;
    s32 spin_angle;     // name inferred: += 0x888 per update_effects frame, the y turn of the fourth model part
    s32 reset;
    s32 timer;
    s32 particle_tev;   // name inferred: rotation_z > 0 in the ctor; render draws with setup_particle_tev when set

    void render_particle_chain();
    void draw_effect_chain();
    static void *create(ObjectSetData *set_data);
    static void destroy_instance();
    static void load_resources();
};

LAYOUT_ASSERT(TOTrapAncient02_size_check, sizeof(TOTrapAncient02) == 0x35C);

struct TrapAncient02ResourceRecord {
    const char *model_filenames[2];
    BmlResourceDescriptor descriptor;
};

#endif
