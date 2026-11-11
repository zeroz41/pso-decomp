#ifndef PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H
#define PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOJungleDesign : public TObjCollidable {
    virtual ~TOJungleDesign();
    u32 m_ac;
    u32 m_b0;
    void init_design_variant();
    // The floor table's resource pair (free_shared_resource: name inferred).
    static void free_shared_resource();
    static void load_shared_resource();
    virtual void render();
};

typedef char TOJungleDesign_size[sizeof(TOJungleDesign) == 0xB4 ? 1 : -1];

extern "C" {
void *TOJungleDesign__create(void *arg0);
u8 *fn_802FF028(s32 arg0);
u8 *fn_802FF064(s32 arg0);
}

#endif
