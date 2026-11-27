#ifndef PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H
#define PSO_OBJECT_JUNGLE_TOJUNGLEDESIGN_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TOJungleDesign : public TObjCollidable {
    TOJungleDesign(TObject *parent, ObjectSetData *set_data);
    virtual ~TOJungleDesign();
    NJS_OBJECT *design_model;
    s32 variant;  // set_params[0], clamped to 0..2
    void init_design_variant();
    // The floor table's resource pair (free_shared_resource: name inferred).
    static void free_shared_resource();
    static void load_shared_resource();
    virtual void render();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOJungleDesign_size, sizeof(TOJungleDesign) == 0xB4);

NJS_TEXLIST *get_jungle_design_texlist(s32 index);
NJS_OBJECT *get_jungle_design_model(s32 index);

#endif
