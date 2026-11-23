#ifndef PSO_OBJECT_JUNGLE_TOGRASSJUNGLE_H
#define PSO_OBJECT_JUNGLE_TOGRASSJUNGLE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOGrassJungle : public TObjBase {
    TOGrassJungle(TObject *parent, void *set_data);
    virtual ~TOGrassJungle();
    s32 model_index;  // set_params[0] clamped to 0..1: which of the two grass models render draws
    static void release_static_instance();
    static void load_resources();
    virtual void render();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOGrassJungle_size, sizeof(TOGrassJungle) == 0x94);

#endif
