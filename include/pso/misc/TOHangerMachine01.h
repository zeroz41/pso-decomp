#ifndef PSO_MISC_TOHANGERMACHINE01_H
#define PSO_MISC_TOHANGERMACHINE01_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOHangerMachine01 : public TUnk_804AFBF8 {
    TOHangerMachine01(void *set_data);
    virtual ~TOHangerMachine01();
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    static void free_static_model();
    static void load_shared_resource();
    static s32 is_valid_slot(int arg0, u16 arg1);
    u32 m_c8;
};

typedef char TOHangerMachine01_size[sizeof(TOHangerMachine01) == 0xCC ? 1 : -1];

extern "C" {
void TOHangerMachine01__sub_80169168(void *self);
}

#endif
