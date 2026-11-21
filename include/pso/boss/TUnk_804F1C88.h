#ifndef PSO_BOSS_TUNK_804F1C88_H
#define PSO_BOSS_TUNK_804F1C88_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/CollisionBodySet.h"

class TUnk_804F1C88 : public TObject {
public:
    virtual ~TUnk_804F1C88();
    virtual void render();
    virtual void run_task();
    // A growing sphere at the laser's impact: each frame it reports the
    // players it touches to the parent De Rol Le (role inferred).
    CollisionBodySet hit_set;
    CollisionBody hit_body;
};
LAYOUT_ASSERT(TUnk_804F1C88_size, sizeof(TUnk_804F1C88) == 0x60);

#endif
