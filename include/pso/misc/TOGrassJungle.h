#ifndef PSO_MISC_TOGRASSJUNGLE_H
#define PSO_MISC_TOGRASSJUNGLE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOGrassJungle : public TObjBase {
    virtual ~TOGrassJungle();
    u32 m_90;
    static void release_static_instance();
    static void load_resources();
    virtual void render();
};

typedef char TOGrassJungle_size[sizeof(TOGrassJungle) == 0x94 ? 1 : -1];

extern "C" {
void *TOGrassJungle__create(void *arg0);
}

#endif
