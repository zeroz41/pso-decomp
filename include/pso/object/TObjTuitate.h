#ifndef PSO_OBJECT_TOBJTUITATE_H
#define PSO_OBJECT_TOBJTUITATE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/RenderFadeState.h"

struct TObjMapCsn;

struct TObjTuitate : public TObjCollidable {
    TObjTuitate(TObject *parent, void *arg2);
    virtual ~TObjTuitate();
    void render();
    void run_task();
    RenderFadeState m_fade;  // fades the model out while it is close to the camera
    TObjMapCsn *m_csn;       // its collision wall
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjTuitate_size, sizeof(TObjTuitate) == 0xCC);

extern "C" {
void *__dt__11TObjTuitateFv(void *arg0, s16 arg1);
void free_tuitate_bml_resource(void);
void load_tuitate_bml_resource(void);
}

#endif
