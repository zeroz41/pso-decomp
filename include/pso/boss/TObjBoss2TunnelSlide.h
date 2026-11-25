#ifndef PSO_BOSS_TOBJBOSS2TUNNELSLIDE_H
#define PSO_BOSS_TOBJBOSS2TUNNELSLIDE_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjBoss2TunnelSlide : public TObject {
public:
    TObjBoss2TunnelSlide(TObject *parent);
    virtual ~TObjBoss2TunnelSlide();
    virtual void run_task();
    // TObjBoss2Tunnel creates it when the brake starts: after 30 frames it slides the two
    // NJS_OBJECTs clear_target_flags picked 1 unit apart per frame, up to 70.
    s32 frame;
    f32 slide;
};
LAYOUT_ASSERT(TObjBoss2TunnelSlide_size, sizeof(TObjBoss2TunnelSlide) == 0x24);

#endif
