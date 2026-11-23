#ifndef PSO_OBJECT_TUNK_804CCAC8_H
#define PSO_OBJECT_TUNK_804CCAC8_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

struct TObjPlayer;

// Support technique charge effect: follows the casting player and spawns particles
// until the charge ends.
class TUnk_804CCAC8 : public TObject {
public:
    TUnk_804CCAC8(TObjPlayer *actor, TObject *parent);
    virtual ~TUnk_804CCAC8();
    virtual void run_task();
    TObjPlayer *actor;
    Vec position;
    s32 age;
    s32 sound;
};
LAYOUT_ASSERT(TUnk_804CCAC8_size, sizeof(TUnk_804CCAC8) == 0x34);

#endif
