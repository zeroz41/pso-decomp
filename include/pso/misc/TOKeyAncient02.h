#ifndef PSO_MISC_TOKEYANCIENT02_H
#define PSO_MISC_TOKEYANCIENT02_H

#include "types.h"
#include "pso/misc/TOKey.h"

// The ruins door switch (fs_obj_o_doorswitch01): a pedestal under a glass
// dome whose lamp pulses and spins, lit by o_key_ancient02.gvm once on.
class TOKeyAncient02 : public TOKey {
public:
    TOKeyAncient02(TObject *parent, void *set_data);
    virtual ~TOKeyAncient02();
    virtual void render();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void vfunc_25();
    static void *create(void *set_data);
    static void free_static();
    static void load_resources();

    s32 pulse_flags;  // bit 0: the lamp is growing
    s32 lamp_angle;   // the lamp's y rotation
};

typedef char TOKeyAncient02_size[sizeof(TOKeyAncient02) == 0xF0 ? 1 : -1];
#endif
