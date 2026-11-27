#ifndef PSO_OBJECT_TOBJBIGTUITATE_H
#define PSO_OBJECT_TOBJBIGTUITATE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/RenderFadeState.h"

struct TObjMapCsn;
struct BmlResource;

struct TObjBigTuitate : public TObjCollidable {
    TObjBigTuitate(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjBigTuitate();
    void render();
    void run_task();
    static void free_instance();
    RenderFadeState fade;    // fades the model out while the camera is close
    TObjMapCsn *map_csn;     // the object's map collision
    static void *create(ObjectSetData *set_data);
    static const char *class_name;
    static CollisionBody collision_parts[1];
    static BmlResource *bml_resource;
    static void load_resources();
};

LAYOUT_ASSERT(TObjBigTuitate_size, sizeof(TObjBigTuitate) == 0xCC);

#endif
