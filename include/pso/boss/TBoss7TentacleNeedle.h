#ifndef PSO_BOSS_TBOSS7TENTACLENEEDLE_H
#define PSO_BOSS_TBOSS7TENTACLENEEDLE_H

#include "types.h"
#include "pso/TObject.h"

struct TBoss7TentacleNeedle : public TObject {
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

typedef char TBoss7TentacleNeedle_size[sizeof(TBoss7TentacleNeedle) == 0x7C ? 1 : -1];

class TBoss7Tentacle;
extern "C" {
void TBoss7Tentacle__sub_802EF954(void *p);
u8 TBoss7Tentacle__sub_802F0904(u8 *arg0);
void TBoss7Tentacle__sub_802F0918(void *p);
void TBoss7Tentacle__sub_802F09B4(void *p);
void TBoss7Tentacle__sub_802F09C8(void *a0);
void sub_802F09EC__14TBoss7TentacleFv(void *p);
void sub_802F09FC__14TBoss7TentacleFv(u8 *arg0);
void TBoss7Tentacle__sub_802F0A14(u8 *arg0);
void TBoss7Tentacle__sub_802F0A2C(u8 *arg0);
void TBoss7Tentacle__sub_802F0A44(u8 *arg0);
void TBoss7Tentacle__sub_802F0AD0(void *a0);
void TBoss7Tentacle__sub_802F0AF0(u8 *arg0);
void TBoss7Tentacle__sub_802F0B58(u8 *arg0);
void TBoss7Tentacle__sub_802F0B70(void *p);
void TBoss7Tentacle__sub_802F0B80(void *p);
void TObjPlayer__sub_802EFEC4(void);
void TObjPlayer__sub_802F0D2C(void);
void advance_needle_timer__20TBoss7TentacleNeedleFv(void *arg0);
void damage_nearby_players__14TBoss7TentacleFPv(u8 *arg0);
void fn_802EFEA8(void);
void render__14TBoss7TentacleFv(u8 *arg0);
void run_task__14TBoss7TentacleFv(u8 *arg0);
void update_retract_state__14TBoss7TentacleFPv(TBoss7Tentacle *arg0);
}

#endif
