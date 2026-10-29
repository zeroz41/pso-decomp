#ifndef PSO_MISC_TOKEYANCIENT01_H
#define PSO_MISC_TOKEYANCIENT01_H

#include "types.h"
#include "pso/misc/TOKey.h"

// The ruins floor switch (fd_obj_n_switch): plays its press motion while
// off and draws the pressed pose once on. Set param 5 picks one of its
// texture variants.
class TOKeyAncient01 : public TOKey {
public:
    TOKeyAncient01(TObject *parent, void *set_data);
    virtual ~TOKeyAncient01();
    virtual void render();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void vfunc_25();
    static void *create(void *set_data);
    static void free_shared_resources();
    static void load_resources();
};

typedef char TOKeyAncient01_size[sizeof(TOKeyAncient01) == 0xE8 ? 1 : -1];
#endif
