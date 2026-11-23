#ifndef PSO_OBJECT_JUNGLE_TOGRASSJUNGLE_H
#define PSO_OBJECT_JUNGLE_TOGRASSJUNGLE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOGrassJungle : public TObjBase {
    virtual ~TOGrassJungle();
    u32 m_90;
    static void release_static_instance();
    static void load_resources();
    virtual void render();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOGrassJungle_size, sizeof(TOGrassJungle) == 0x94);

#endif
