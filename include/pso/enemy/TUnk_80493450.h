#ifndef PSO_ENEMY_TUNK_80493450_H
#define PSO_ENEMY_TUNK_80493450_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"

class TUnk_80493450 : public TObjEnemy {
public:
    virtual void run_task();
    virtual ~TUnk_80493450();
    TUnk_80493450(TObject *parent);
    virtual void vfunc_28();
    virtual void vfunc_58();
    virtual void vfunc_63();
    s32 update_target_near_flag();
    void sub_800C4E08();
    virtual void vfunc_62();
    u8 test_elt_flag(s32, s32);
    s32 countChildren();
    void link_into_group_chain();
    void unlink_enemy_group_relations();
    virtual void vfunc_83();
    virtual void beast_idle_update();
    virtual void update_turn_toward_target();
    virtual void beast_update_approach();
    virtual void beast_update_group_chase();
    virtual void beast_update_attack();
    virtual void vfunc_89();
    virtual void beast_update_hurt();
    virtual void beast_update_dead();
    virtual int beast_retire_corpse();
    virtual void vfunc_93();
    virtual void vfunc_94();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_97();
    virtual void vfunc_98();
    virtual void vfunc_99();
    virtual void vfunc_100();
    virtual void vfunc_101();
    virtual void request_stand_action();
    virtual void vfunc_61();
    virtual void vfunc_59();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void vfunc_60();
    virtual int test_flag_256();
    s16 m_374;
    u16 m_376;
    s32 m_378;
    u32 m_37c;
    f32 unk_380;
    f32 m_384;
    f32 unk_388;
    u32 m_38c;
    s32 m_390;
    f32 unk_394;
    float m_398;
    f32 unk_39C;
    float m_3a0;
    f32 unk_3A4;
};

#endif
