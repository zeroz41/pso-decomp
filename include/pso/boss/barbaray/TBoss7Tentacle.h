#ifndef PSO_BOSS_BARBARAY_TBOSS7TENTACLE_H
#define PSO_BOSS_BARBARAY_TBOSS7TENTACLE_H
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>

class TBoss7Tentacle : public TObject {
public:
    TBoss7Tentacle(TObject *arg1, s32 arg2, s32 arg3);
    virtual ~TBoss7Tentacle();
    void sub_802F09FC();
    void sub_802F09EC();
    virtual void render();
    virtual void run_task();
public:
    void restart_particle_effect();
    s32 advance_anim_time_wrapped(f32 d);
    s32 advance_toward_limit(f32 farg0);
    void update_extend_amount();
    void switch_state();
    void advance_path_position();
    void reset_state();
    void setup_state();
    void init_segments();
    void start_attack_at_position(u8 *arg1, s32 arg2);

    s32 m_1c;
    void *m_20;
    f32 m_24;
    f32 m_28;
    f32 m_2c;
    s32 m_30;
    s32 m_34;
    s32 m_38;
    s32 m_3c;
    u8 unk_40[0x4];
    f32 m_44;
    u8 unk_48[0x4];
    s32 m_4c;
    Vec m_50[14];
    s32 m_f8[14];
    s32 m_130;
    f32 m_134;
    f32 m_138;
    s32 m_13c;
    s32 m_140;
    s32 m_144;
    s32 m_148;
    f32 m_14c;
    f32 m_150;
    f32 m_154;
    f32 m_158;
    f32 m_15c;
    f32 m_160;
    s32 m_164;
    s32 m_168;
};

typedef char TBoss7TentacleM50[offsetof(TBoss7Tentacle, m_50) == 0x50 ? 1 : -1];
typedef char TBoss7TentacleM158[offsetof(TBoss7Tentacle, m_158) == 0x158 ? 1 : -1];

#endif
