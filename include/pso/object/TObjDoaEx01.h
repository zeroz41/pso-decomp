#ifndef PSO_OBJECT_TOBJDOAEX01_H
#define PSO_OBJECT_TOBJDOAEX01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TObjDoaEx01 : public TODoorBase {
    virtual ~TObjDoaEx01();
    virtual void update_closing();
    virtual void update_open();
    virtual void update_opening();
    virtual void update_closed();
    virtual void render();
    s32 draw_object_tree(s32 arg1);
    static void free_resource();
    static void load_resources();
    u8 unk_D4[0x4];
    f32 m_d8;
    u8 unk_DC[0x4];
    f32 m_e0;
    void try_open();
    void draw_model();
};

typedef char TObjDoaEx01_size[sizeof(TObjDoaEx01) == 0xE4 ? 1 : -1];
#endif
