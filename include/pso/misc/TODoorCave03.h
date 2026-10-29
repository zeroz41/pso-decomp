#ifndef PSO_MISC_TODOORCAVE03_H
#define PSO_MISC_TODOORCAVE03_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorCave03 : public TODoorBase {
    virtual ~TODoorCave03();
    virtual void update_demo();
    virtual void update_closing();
    virtual void update_open();
    virtual void update_opening();
    virtual void update_closed();
    virtual void render();
    void* m_d4;
    static void *create(void *arg0);
    static void free_shared_data();
    static void load_resources();
    u8 unk_D8[0x4];
    f32 m_dc;
    u8 unk_E0[0x4];
};

typedef char TODoorCave03_size[sizeof(TODoorCave03) == 0xE4 ? 1 : -1];
#endif
