#ifndef PSO_ITEM_TOBJITEMLIGHT_H
#define PSO_ITEM_TOBJITEMLIGHT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjItemLight : public TObjBase {
    TObjItemLight(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjItemLight();
    void run_task();
    f32 m_radius;
    struct TParticleCtrl *m_particle;
    static void *create(ObjectSetData *set_data);
    static const char *class_name;
};

LAYOUT_ASSERT(TObjItemLight_size, sizeof(TObjItemLight) == 0x98);


#endif
