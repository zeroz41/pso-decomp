#include <dolphin/mtx.h>
#include "pso/map/CsnQuery.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/system/vector.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"

#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"

#include <stddef.h>
#include "pso/network/TLobby.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

#pragma readonly_strings on


const char *TBoss5GryphonLightningWing::name = "TBoss5GryphonLightningWing";


#pragma opt_lifetimes off


void TBoss5GryphonLightningWing::apply_lightning_effect() {
    Vec pos;
    TBoss5Gryphon *owner;

    owner = TBoss5Gryphon::get_instance();
    if (owner != NULL) {
        this->get_end_position(&pos);
        TBoss5Gryphon::apply_lightning_hit(owner, &pos, 10.0f);
    }
}

void TBoss5GryphonLightningWing::render() {  }

#pragma push
#pragma opt_common_subs off
void TBoss5GryphonLightningWing::run_task() {
    Vec pos;
    this->life_progress = (f32)this->age / (f32)this->life_frames;
    if (this->life_progress > 1.0f) {
        this->life_progress = 1.0f;
    }
    this->grow_progress = (f32)this->age / (f32)this->grow_frames;
    if (this->grow_progress > 1.0f) {
        this->grow_progress = 1.0f;
    }
    this->update_endpoints();
    this->apply_lightning_effect();
    if (this->age == this->grow_frames) {
        this->get_end_position(&pos);
        play_sound_effect(0x40032516, &pos, 0, 0);
    }
    this->spawn_gryphon_lightning();
    if (this->age >= this->life_frames) {
        this->queue_destruction();
    }
}
#pragma pop

TBoss5GryphonLightningWing::~TBoss5GryphonLightningWing() {}

TBoss5GryphonLightningWing::TBoss5GryphonLightningWing(TObject *parent, Vec *start, Vec *mid, Vec *end,
                                                       s32 grow_frames, s32 hold_frames)
    : TBoss5GryphonLightning(parent, start, 20.0f) {
    m_name = name;
    segment_count = 3;
    this->grow_frames = grow_frames;
    life_frames = grow_frames + hold_frames;
    VecCopy(&segments[0].pos, start);
    VecCopy(&segments[segment_count - 1].pos, end);
    // CodeWarrior: the original addresses the segments from a copy of this, not as this + (i * 16 + 0x48).
#ifdef __MWERKS__
    TBoss5GryphonLightningWing *self = this;
    for (s32 i = 1; i < segment_count - 1; i++) {
        self->segments[i].pos.x = mid->x;
        self->segments[i].pos.y = mid->y;
        self->segments[i].pos.z = mid->z;
    }
#else
    for (s32 i = 1; i < segment_count - 1; i++) {
        segments[i].pos.x = mid->x;
        segments[i].pos.y = mid->y;
        segments[i].pos.z = mid->z;
    }
#endif
}

TBoss5GryphonLightningWing *TBoss5GryphonLightningWing::spawn(TObject *parent, Vec *start, Vec *mid, Vec *target,
                                                              s32 grow_frames, s32 hold_frames) {
    Vec end;
    CsnHit *hit;
    VecCopy(&end, target);
    hit = csnVecterUnder(&end, 0x16EF);
    if (hit == NULL) {
        end.y = gryphon_max_floor_height;
    } else if (hit->contact->point.y > gryphon_max_floor_height) {
        end.y = gryphon_max_floor_height;
    } else {
        end.y = hit->contact->point.y;
    }
    return new TBoss5GryphonLightningWing(parent, start, mid, &end, grow_frames, hold_frames);
}

TBoss5GryphonLightningWing *TBoss5GryphonLightningWing::spawn_corner(TObject *parent, Vec *start, Vec *target,
                                                                     s32 grow_frames, s32 hold_frames) {
    Vec corner;
    corner.x = target->x;
    corner.y = start->y;
    corner.z = target->z;
    return spawn(parent, start, &corner, target, grow_frames, hold_frames);
}
