#ifndef PSO_BOSS_BARBARAY_TBOSS7TENTACLENEEDLE_H
#define PSO_BOSS_BARBARAY_TBOSS7TENTACLENEEDLE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct Vec;
struct TBoss7TentacleNeedle : public TObject {
    TBoss7TentacleNeedle(TObject *parent, Vec *pos);
    virtual ~TBoss7TentacleNeedle();
    void advance_needle_timer();
    void* m_1c;
    u8 _pad20[0x8];
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u8 _pad34[0x4];
    u32 m_38;
    u32 m_3c;
    TObject *particle_emitter; // create_particle_emitter(pos, 0x212) in the ctor
    u8 unk_44[0x30];
    f32 m_74;
    u32 m_78;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TBoss7TentacleNeedle_size, sizeof(TBoss7TentacleNeedle) == 0x7C);

class TBoss7Tentacle;
extern "C" {
void TBoss7Tentacle__sub_802EF954(void *p);
s32 TBoss7Tentacle__is_retract_complete(u8 *arg0);
void TBoss7Tentacle__sub_802F0918(void *p);
void TBoss7Tentacle__sub_802F09B4(void *p);
void TBoss7Tentacle__sub_802F09C8(void *a0);
void sub_802F09EC__14TBoss7TentacleFv(void *p);
void sub_802F09FC__14TBoss7TentacleFv(u8 *arg0);
void TBoss7Tentacle__sub_802F0A14(u8 *arg0);
void TBoss7Tentacle__sub_802F0A2C(u8 *arg0);
void TBoss7Tentacle__sub_802F0A44(u8 *arg0);
void TBoss7Tentacle__enable_fast_wobble_advance(void *a0);
void TBoss7Tentacle__sub_802F0AF0(u8 *arg0);
void TBoss7Tentacle__sub_802F0B58(u8 *arg0);
void TBoss7Tentacle__enable_retract(void *p);
void TBoss7Tentacle__enable_extend(void *p);
void TObjPlayer__capture_tentacle_needle_target_state(void);
void TObjPlayer__sub_802F0D2C(void);
void advance_needle_timer__20TBoss7TentacleNeedleFv(void *arg0);
void damage_nearby_players__14TBoss7TentacleFPv(u8 *arg0);
void reset_tentacle_needle_target_state(void);
void render__14TBoss7TentacleFv(u8 *arg0);
void run_task__14TBoss7TentacleFv(u8 *arg0);
void update_retract_state__14TBoss7TentacleFPv(TBoss7Tentacle *arg0);
}

// boss7_tentacle_needle_target_state: layout known from its uses only.
struct Boss7TentacleNeedleTargetState { s32 value; u8 remaining[0xC]; };
extern Boss7TentacleNeedleTargetState boss7_tentacle_needle_target_state;

#endif
