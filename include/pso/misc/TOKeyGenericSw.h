#ifndef PSO_MISC_TOKEYGENERICSW_H
#define PSO_MISC_TOKEYGENERICSW_H

#include "types.h"
#include "pso/misc/TOKey.h"

// The general-purpose floor switch (fs_obj_hanyousu): a body and a light
// that plays its motion, the light drawn blue (light_ao) once on. The
// jungle and seabed floors load the _j models.
class TOKeyGenericSw : public TOKey {
public:
    TOKeyGenericSw(TObject *parent, void *set_data);
    virtual ~TOKeyGenericSw();
    virtual void render();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void vfunc_25();
    static void *create(void *set_data);
    static void free_shared_resources();
    static void load_resources();

    u8 floor_area;  // get_current_floor_area() when it was made
    // Set every frame by the on / off steps (no reader in this unit).
    s32 on_state;
    s32 on_state_copy;
    s32 off_state;
    s32 off_state_copy;
};

typedef char TOKeyGenericSw_size[sizeof(TOKeyGenericSw) == 0xFC ? 1 : -1];
#endif
