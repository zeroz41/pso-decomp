#ifndef PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H
#define PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TOJungleDesign : public TObjCollidable {
    TOJungleDesign(saddr, saddr);
    virtual ~TOJungleDesign();
    uaddr m_ac;
    u32 m_b0;
    void init_design_variant();
    // The floor table's resource pair (free_shared_resource: name inferred).
    static void free_shared_resource();
    static void load_shared_resource();
    virtual void render();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOJungleDesign_size, sizeof(TOJungleDesign) == 0xB4);

extern "C" {
NJS_TEXLIST *fn_802FF028(s32 index);
NJS_OBJECT *fn_802FF064(s32 index);
}

#endif
