#ifndef PSO_OBJECT_TOBJSEABEDSUISO_CH_H
#define PSO_OBJECT_TOBJSEABEDSUISO_CH_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

class TParticleCtrl;

class TObjSeabedSuiso_CH : public TObjMapObject {
public:
    TObjSeabedSuiso_CH(TObject *parent, void *set_data);
    virtual ~TObjSeabedSuiso_CH();
    virtual void run_task();
    virtual void render();
    void init_kind_params();
    void update_state();
    s32 kind;  // abs(set_params[0]) clamped to 3, indexes the kind table
    u32 m_cc;
    s32 m_d0;
    s32 kind_model;  // the kind's model
    TParticleCtrl *emitter;  // the kind's particle emitter, 0 for none
};
typedef char TObjSeabedSuiso_CH_size[sizeof(TObjSeabedSuiso_CH) == 0xDC ? 1 : -1];

#endif
