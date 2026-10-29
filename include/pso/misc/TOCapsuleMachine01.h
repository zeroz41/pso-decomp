#ifndef PSO_MISC_TOCAPSULEMACHINE01_H
#define PSO_MISC_TOCAPSULEMACHINE01_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOCapsuleMachine01 : public TUnk_804AFBF8 {
    TOCapsuleMachine01(void *set_data);
    virtual ~TOCapsuleMachine01();
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    static void reset_static_state();
    static void alloc_and_load_resource();
};

typedef char TOCapsuleMachine01_size[sizeof(TOCapsuleMachine01) == 0xC8 ? 1 : -1];

#endif
