#ifndef PSO_OBJECT_TUNK_804CCAC8_H
#define PSO_OBJECT_TUNK_804CCAC8_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Support technique charge effect: follows the casting player and spawns particles
// until the charge ends.
class TUnk_804CCAC8 : public TObject {
public:
    TUnk_804CCAC8(s32 actor, s32 parent);
    virtual ~TUnk_804CCAC8();
    virtual void run_task();
    void *actor;
    f32 position[3];
    s32 age;
    s32 sound;
};
typedef char TUnk_804CCAC8_size[sizeof(TUnk_804CCAC8) == 0x34 ? 1 : -1];

#endif
