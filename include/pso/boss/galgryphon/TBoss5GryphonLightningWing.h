#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGWING_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGWING_H

#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "types.h"

struct Vec;

class TBoss5GryphonLightningWing : public TBoss5GryphonLightning {
public:
    virtual ~TBoss5GryphonLightningWing();
    virtual void run_task();
    virtual void render();
    void apply_lightning_effect();
    // A bolt from start through mid to the ground under target: the head reaches it after grow_frames, the tail
    // follows after grow_frames + hold_frames.
    static TBoss5GryphonLightningWing *spawn(TObject *parent, Vec *start, Vec *mid, Vec *target, s32 grow_frames,
                                             s32 hold_frames);
    // spawn with the middle point over target at the height of start.
    static TBoss5GryphonLightningWing *spawn_corner(TObject *parent, Vec *start, Vec *target, s32 grow_frames,
                                                    s32 hold_frames);

    s32 grow_frames;
    s32 life_frames;  // run_task removes the wing once age reaches it
};

extern "C" {
// The constructor TBoss5GryphonLightningWing(TObject *parent, Vec *start, Vec *mid, Vec *end, s32 grow_frames,
// s32 hold_frames), written as a function of the allocation.
saddr __ct__26TBoss5GryphonLightningWingFP7TObjectP3VecP3VecP3Vecll(saddr allocation, TObject *parent, Vec *start,
                                                                    Vec *mid, Vec *end, s32 grow_frames,
                                                                    s32 hold_frames);
}

#endif
