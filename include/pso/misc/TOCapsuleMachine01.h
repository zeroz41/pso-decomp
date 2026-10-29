#ifndef PSO_MISC_TOCAPSULEMACHINE01_H
#define PSO_MISC_TOCAPSULEMACHINE01_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TOCapsuleMachine01 : public TObjMapObject {
    TOCapsuleMachine01(void *set_data);
    virtual ~TOCapsuleMachine01();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void reset_static_state();
    static void alloc_and_load_resource();
};

typedef char TOCapsuleMachine01_size[sizeof(TOCapsuleMachine01) == 0xC8 ? 1 : -1];

#endif
