#ifndef PSO_MISC_TODOORVS2DOOR01_H
#define PSO_MISC_TODOORVS2DOOR01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorVS2Door01 : public TODoorBase {
    virtual ~TODoorVS2Door01();
    u8 is_open();
    virtual void update_demo();
    virtual void update_closing();
    virtual void update_open();
    virtual void update_opening();
    virtual void update_closed();
    virtual void render();
    static void *create(void *arg0);
    static void free_resources();
    static void load_resources();
    u8 unk_D4[0x4];
};

typedef char TODoorVS2Door01_size[sizeof(TODoorVS2Door01) == 0xD8 ? 1 : -1];
#endif
