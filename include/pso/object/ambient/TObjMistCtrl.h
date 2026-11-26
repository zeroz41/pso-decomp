#ifndef PSO_OBJECT_AMBIENT_TOBJMISTCTRL_H
#define PSO_OBJECT_AMBIENT_TOBJMISTCTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;

struct TObjMistCtrl : public TObjBase {
    static const char *class_name;
    TObjMistCtrl(TObject *parent, void *set_data);
    virtual ~TObjMistCtrl();
    static TObjMistCtrl *create(TObject *parent, void *set_data);
    void follow_camera();
    void run_task();
    TParticleCtrl *particle;
};

LAYOUT_ASSERT(TObjMistCtrl_size, sizeof(TObjMistCtrl) == 0x94);

#endif
