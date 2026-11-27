#ifndef PSO_OBJECT_TOBJTUITATE_H
#define PSO_OBJECT_TOBJTUITATE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/RenderFadeState.h"

struct TObjMapCsn;
struct BmlResource;

struct TObjTuitate : public TObjCollidable {
    TObjTuitate(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjTuitate();
    void render();
    void run_task();
    RenderFadeState fade;    // fades the model out while the camera is close
    TObjMapCsn *map_csn;     // the object's map collision
    static void *create(ObjectSetData *set_data);
    static const char *class_name;
    static CollisionBody collision_parts[1];
    static BmlResource *bml_resource;
    static void load_resources();
    static void free_resources();
};

LAYOUT_ASSERT(TObjTuitate_size, sizeof(TObjTuitate) == 0xCC);

#endif
