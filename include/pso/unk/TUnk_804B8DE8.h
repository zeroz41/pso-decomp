#ifndef PSO_UNK_TUNK_804B8DE8_H
#define PSO_UNK_TUNK_804B8DE8_H
#include "types.h"
#include "pso/TObject.h"

// Gogo ball, spawned by TUnk_804B8DD0::update_effects.
class TUnk_804B8DE8 : public TObject {
public:
    TUnk_804B8DE8(Vec *position, s32 limit, s32 arg3, s32 arg4, TObject *parent);
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
    s32 unk_50;
    s32 unk_54;
};
typedef char TUnk_804B8DE8_size[sizeof(TUnk_804B8DE8) == 0x58 ? 1 : -1];

#endif
