#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGHORN_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGHORN_H
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "types.h"

class TBoss5GryphonLightningHorn : public TBoss5GryphonLightning {
public:
    TBoss5GryphonLightningHorn(TObject *parent, Vec *pos, s32 rotation_y);
    virtual ~TBoss5GryphonLightningHorn();
    void rebuild_lightning_segments();
    // Moves to onto the segment from + dir * [0, dist] when it lies outside it; 1 when it moved.
    s32 clamp_to_segment(Vec *from, Vec *dir, Vec *to, f32 dist);
    // Hits every player at the closest point of the bolt's ground line.
    void apply_lightning_effect();
    virtual void run_task();
    virtual void render();
    void queue_destruction();
    static TBoss5GryphonLightningHorn *spawn_ground_lightning(TObject *parent, Vec *pos, s32 rotation_y);

    Vec velocity;  // 5 units along rotation_y
    s32 rotation_y;
};

extern const char *TBoss5GryphonLightningHorn__name;

#endif
