#ifndef PSO_MISC_TODOORMACHINE02_H
#define PSO_MISC_TODOORMACHINE02_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorMachine02 : public TODoorBase {
    virtual ~TODoorMachine02();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    void* m_d4;
    virtual void render();
    static void *create(void *arg0);
    static void free_statics();
    static void load_resources();
    u8 unk_D8[0x4];
    f32 m_dc;
    u8 unk_E0[0x4];
};

typedef char TODoorMachine02_size[sizeof(TODoorMachine02) == 0xE4 ? 1 : -1];
#endif
