#ifndef PSO_OBJECT_TOBJGRASSWEB_H
#define PSO_OBJECT_TOBJGRASSWEB_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjGrassWeb : public TObjBase {
    virtual ~TObjGrassWeb();
    virtual void render();
    u32 m_90;
    u8 _pad94[0x10];
    u16 m_a4;
    int queue_destruction();
    void apply_to_player();
    void run_task();
    u8 unk_A6[0x2];
};

typedef char TObjGrassWeb_size[sizeof(TObjGrassWeb) == 0xA8 ? 1 : -1];
#endif
