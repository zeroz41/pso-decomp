#ifndef PSO_UNK_TUNK_804CCC28_H
#define PSO_UNK_TUNK_804CCC28_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TObjChara;
class TParticleCtrl;

// Revival effect around a character: three timed particle emitters, a
// burst after 10 frames, gone after 200.
class TUnk_804CCC28 : public TObject {
public:
    TUnk_804CCC28(TObjChara *chara, TObject *parent);
    virtual ~TUnk_804CCC28();
    virtual void run_task();

    TParticleCtrl *m_emitters[3];
    s32 m_timer;
    Vec m_pos;
};
LAYOUT_ASSERT(TUnk_804CCC28_size, sizeof(TUnk_804CCC28) == 0x38);

#endif
