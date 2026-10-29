#ifndef PSO_MISC_TODOORCAVE02_H
#define PSO_MISC_TODOORCAVE02_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorCave02 : public TODoorBase {
    virtual ~TODoorCave02();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    s32 draw_parts(void *arg1_);
    virtual void render();
    static void *create(void *arg0);
    static void free_globals();
    static void load_resources();
    u8 unk_D4[0x4];
    f32 m_d8;
    u8 unk_DC[0x4];
    f32 m_e0;
};

typedef char TODoorCave02_size[sizeof(TODoorCave02) == 0xE4 ? 1 : -1];
#endif
