#ifndef PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H
#define PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOJungleDesign : public TObjCollidable {
    virtual ~TOJungleDesign();
    u32 m_ac;
    u32 m_b0;
    void init_design_variant();
    virtual void render();
};

typedef char TOJungleDesign_size[sizeof(TOJungleDesign) == 0xB4 ? 1 : -1];

extern "C" {
void *TOJungleDesign__create(void *arg0);
}

#endif
