#ifndef PSO_MISC_TOMONUMENTANCIENT01_H
#define PSO_MISC_TOMONUMENTANCIENT01_H

#include "types.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/system/BmlResource.h"

// The Ruins' stone tablet: the stone, then its crystal and its letters drawn
// as effects.
struct TOMonumentAncient01 : public TUnk_804B27D8 {
    TOMonumentAncient01(TObject *parent, void *set_data);
    virtual ~TOMonumentAncient01();
    virtual void update_demo();
    virtual void render();

    static void *create(void *set_data);
    static void unload_resources();
    static void load_resources();

    static const char *class_name;
    static BmlResource *model_resource;
};

typedef char TOMonumentAncient01_size[sizeof(TOMonumentAncient01) == 0xE4 ? 1 : -1];

#endif
