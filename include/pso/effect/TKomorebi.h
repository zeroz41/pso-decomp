#ifndef PSO_EFFECT_TKOMOREBI_H
#define PSO_EFFECT_TKOMOREBI_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct BmlResource;
struct ObjectSetData;

// Sunlight shafts through the forest canopy (komorebi): a model drawn
// additively, its UVs scrolled once per frame by scale.x.
struct TKomorebi : public TObjBase {
    static const char *class_name;
    static void *create(void *set_data);
    TKomorebi(TObject *parent, ObjectSetData *set_data);
    virtual ~TKomorebi();
    virtual void render();
    virtual void run_task();
    static void free_static();
    static void load_resources();
};

LAYOUT_ASSERT(TKomorebi_size, sizeof(TKomorebi) == 0x90);

#endif
