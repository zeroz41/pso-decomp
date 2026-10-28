#ifndef PSO_MISC_TOWRECKANCIENT_H
#define PSO_MISC_TOWRECKANCIENT_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOWreckAncient : public TObjCollidable {
    virtual ~TOWreckAncient();
    virtual void render();
    static void free_statics();
    static void load_resources();
    u8 unk_AC[0x4];
    f32 m_b0;
};

typedef char TOWreckAncient_size[sizeof(TOWreckAncient) == 0xB4 ? 1 : -1];
#endif
