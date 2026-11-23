#ifndef PSO_UNK_TUNK_804B8DE8_H
#define PSO_UNK_TUNK_804B8DE8_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Gogo ball, spawned by TUnk_804B8DD0::update_effects.
class TUnk_804B8DE8 : public TObject {
public:
    TUnk_804B8DE8(Vec *position, s32 limit, s32 team0, s32 three_point, TObject *parent);
    virtual ~TUnk_804B8DE8();
    virtual void run_task();
    virtual void render();
    Vec pos;
    Vec initial_pos; // inferred: pos before the ctor lowers it by 16
    s32 rot;
    s32 unk_38;
    TObject *effect;
    s32 timer;
    s32 counter;
    s32 limit;
    s32 state;
    s32 team0;        // 1: orange team 0 ball, else blue team 1
    s32 three_point;  // spawned by a three-point goal marker
};
LAYOUT_ASSERT(TUnk_804B8DE8_size, sizeof(TUnk_804B8DE8) == 0x58);

#endif
