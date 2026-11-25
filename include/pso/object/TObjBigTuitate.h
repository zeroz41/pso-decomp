#ifndef PSO_OBJECT_TOBJBIGTUITATE_H
#define PSO_OBJECT_TOBJBIGTUITATE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/RenderFadeState.h"

struct TObjMapCsn;

struct TObjBigTuitate : public TObjCollidable {
    TObjBigTuitate(TObject *parent, void *arg2);
    virtual ~TObjBigTuitate();
    void render();
    void run_task();
    static void free_instance();
    RenderFadeState m_fade;  // fades the model out while it is close to the camera
    TObjMapCsn *m_csn;       // its collision wall
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjBigTuitate_size, sizeof(TObjBigTuitate) == 0xCC);

extern "C" {
void *__dt__14TObjBigTuitateFv(void *arg0, s16 arg1);
}

#endif
