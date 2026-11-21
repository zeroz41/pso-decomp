#ifndef PSO_BOSS_TUNK_804835D8_H
#define PSO_BOSS_TUNK_804835D8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804835D8 : public TObject {
public:
    TUnk_804835D8(TObject *parent);
    virtual ~TUnk_804835D8();
    virtual void run_task();
    // TObjBoss2Tunnel creates it when the brake starts: after 30 frames it slides the two
    // NJS_OBJECTs clear_target_flags picked 1 unit apart per frame, up to 70.
    s32 frame;
    f32 slide;
};
LAYOUT_ASSERT(TUnk_804835D8_size, sizeof(TUnk_804835D8) == 0x24);

#endif
