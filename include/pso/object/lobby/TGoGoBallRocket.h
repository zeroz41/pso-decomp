#ifndef PSO_OBJECT_LOBBY_TGOGOBALLROCKET_H
#define PSO_OBJECT_LOBBY_TGOGOBALLROCKET_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The rocket (rokeorange_churoke.nj) a goal launches when it is scored, spawned by
// TGoGoBallGoal::update_effects.
class TGoGoBallRocket : public TObject {
public:
    TGoGoBallRocket(Vec *position, s32 limit, s32 team0, s32 three_point, TObject *parent);
    virtual ~TGoGoBallRocket();
    virtual void run_task();
    virtual void render();
    Vec pos;
    Vec initial_pos; // inferred: pos before the ctor lowers it by 16
    s32 rot;
    s32 pad_38;
    TObject *effect;
    s32 timer;
    s32 counter;
    s32 limit;
    s32 state;
    s32 team0;        // 1: orange team 0 ball, else blue team 1
    s32 three_point;  // spawned by a three-point goal marker
};
LAYOUT_ASSERT(TGoGoBallRocket_size, sizeof(TGoGoBallRocket) == 0x58);

#endif
