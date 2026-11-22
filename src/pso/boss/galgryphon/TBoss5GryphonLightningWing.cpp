#define TOBJECT_OUT_OF_LINE_HELPERS
#include <dolphin/mtx.h>
#include "pso/map/CsnQuery.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"

#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"

#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

#pragma readonly_strings on


const char *TBoss5GryphonLightningWing__name = "TBoss5GryphonLightningWing";


#pragma opt_lifetimes off


struct Pt_80351C18 { Vec v; f32 w; };

struct Wing_80351C18 {
    s32 x0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1C[0x48 - 0x1C];
    Pt_80351C18 pts[4];
    u8 pad88[8];
    s32 n;
    s32 pad94;
    s32 x98;
    s32 x9C;
};

extern "C" {
s32 __ct__22TBoss5GryphonLightningFP7TObjectP3Vecf(f32);
extern u8 __vt__26TBoss5GryphonLightningWing[];
}

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

// Written out by hand: the C++ constructor addresses the segment loop as this + (i * 16 + 0x48) with stfsx, the
// original as (this + i * 16) + 0x48.
saddr __ct__26TBoss5GryphonLightningWingFP7TObjectP3VecP3VecP3Vecll(saddr allocation, TObject *parent, Vec *start,
                                                                    Vec *mid, Vec *end, s32 grow_frames,
                                                                    s32 hold_frames) {
    s32 i;
    __ct__22TBoss5GryphonLightningFP7TObjectP3Vecf(20.0f);
    ((Wing_80351C18 *)allocation)->vt = __vt__26TBoss5GryphonLightningWing;
    ((Wing_80351C18 *)allocation)->x0 = ((saddr)TBoss5GryphonLightningWing__name);
    ((Wing_80351C18 *)allocation)->n = 3;
    ((Wing_80351C18 *)allocation)->x98 = grow_frames;
    ((Wing_80351C18 *)allocation)->x9C = grow_frames + hold_frames;
    VecCopy(&((Wing_80351C18 *)allocation)->pts[0].v, start);
    VecCopy(&((Wing_80351C18 *)allocation)->pts[((Wing_80351C18 *)allocation)->n - 1].v, end);
    for (i = 1; i < ((Wing_80351C18 *)allocation)->n - 1; i++) {
        ((Wing_80351C18 *)allocation)->pts[i].v.x = mid->x;
        ((Wing_80351C18 *)allocation)->pts[i].v.y = mid->y;
        ((Wing_80351C18 *)allocation)->pts[i].v.z = mid->z;
    }
    return allocation;
}

TBoss5GryphonLightningWing *TBoss5GryphonLightningWing::spawn(TObject *parent, Vec *start, Vec *mid, Vec *target,
                                                              s32 grow_frames, s32 hold_frames) {
    Vec end;
    CsnHit *hit;
    saddr wing;
    VecCopy(&end, target);
    hit = csnVecterUnder(&end, 0x16EF);
    if (hit == NULL) {
        end.y = gryphon_max_floor_height;
    } else if (hit->contact->point.y > gryphon_max_floor_height) {
        end.y = gryphon_max_floor_height;
    } else {
        end.y = hit->contact->point.y;
    }
    wing = (saddr)operator new(sizeof(TBoss5GryphonLightningWing));
    if (wing != 0) {
        wing = __ct__26TBoss5GryphonLightningWingFP7TObjectP3VecP3VecP3Vecll(wing, parent, start, mid, &end, grow_frames,
                                                                             hold_frames);
    }
    return (TBoss5GryphonLightningWing *)wing;
}

TBoss5GryphonLightningWing *TBoss5GryphonLightningWing::spawn_corner(TObject *parent, Vec *start, Vec *target,
                                                                     s32 grow_frames, s32 hold_frames) {
    Vec corner;
    corner.x = target->x;
    corner.y = start->y;
    corner.z = target->z;
    return spawn(parent, start, &corner, target, grow_frames, hold_frames);
}
