#ifndef PSO_TECHNIQUE_TTECREVERSEREFF_H
#define PSO_TECHNIQUE_TTECREVERSEREFF_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TObjChara;
class TParticleCtrl;

// Revival effect around a character: three timed particle emitters, a
// burst after 10 frames, gone after 200.
class TTecReverserEff : public TObject {
public:
    TTecReverserEff(TObjChara *chara, TObject *parent);
    virtual ~TTecReverserEff();
    virtual void run_task();

    TParticleCtrl *m_emitters[3];
    s32 m_timer;
    Vec m_pos;
};
LAYOUT_ASSERT(TTecReverserEff_size, sizeof(TTecReverserEff) == 0x38);

#endif
