#ifndef PSO_TECHNIQUE_TTECLIGHTCHARGE_H
#define PSO_TECHNIQUE_TTECLIGHTCHARGE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TObjPlayer;

// The recovery technique charge effect (inferred: TTecCtrl creates it for technique
// kinds 9 and 15-17): it follows the caster actor, sheds particles 0xB7/0xB8 every
// 10 frames and lives while the charge flag 0x80 is set, up to 180 frames.
class TTecLightCharge : public TObject {
public:
    TTecLightCharge(TObjPlayer *actor, TObject *parent);
    virtual ~TTecLightCharge();
    virtual void run_task();
    TObjPlayer *actor;
    Vec position;
    s32 age;
    s32 sound_handle;
};
LAYOUT_ASSERT(TTecLightCharge_size, sizeof(TTecLightCharge) == 0x34);

#endif
