#ifndef PSO_UNK_TUNK_80499988_H
#define PSO_UNK_TUNK_80499988_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The quest colour overlay (qst_op_add_color_overlay): fades the screen colour from
// its current value to target_color over duration frames. Field names are inferred.
class TUnk_80499988 : public TObject {
public:
    TUnk_80499988(TObject *parent, s32 unk_1C, s32 duration, u8 c3, u8 c0, u8 c1, u8 c2);
    virtual ~TUnk_80499988();
    virtual void run_task();
    s32 sub_800F8250(f32);
    s32 unk_1C;
    s32 frame;
    s32 duration;
    u8 start_color[4];
    u8 target_color[4];
};
LAYOUT_ASSERT(TUnk_80499988_size, sizeof(TUnk_80499988) == 0x30);

#endif
