#ifndef PSO_MISC_TOHANGERMACHINE01_H
#define PSO_MISC_TOHANGERMACHINE01_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TOHangerMachine01 : public TObjMapObject {
    TOHangerMachine01(void *set_data);
    virtual ~TOHangerMachine01();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void free_static_model();
    static void load_shared_resource();
    s32 fan_angle;
};

typedef char TOHangerMachine01_size[sizeof(TOHangerMachine01) == 0xCC ? 1 : -1];

#endif
