#ifndef PSO_UNK_TUNK_804B8E18_H
#define PSO_UNK_TUNK_804B8E18_H
#include "types.h"
#include "pso/player/TObjChara.h"

class TUnk_804B8E18 : public TObjChara {
public:
    virtual ~TUnk_804B8E18();
    s32 reflect_velocity_off_collision(void *, void *);
    void sub_8019A44C(s32);
    void update_goal_checks(u16);
    void update_best_time();
    void *destroy_player_obj(s16);
    u8 unk_334[0x4];
    s32 m_338;
    u8 unk_33C[0x4];
    f32 m_340;
    u8 unk_344[0x4];
    f32 m_348;
    u8 unk_34C[0x4];
    s32 m_350;
    s32 m_354;
    u8 unk_358[0x4];
    s32 m_35c;
    u8 unk_360[0x4];
    f32 m_364;
    u8 unk_368[0x4];
    f32 m_36c;
    u8 unk_370[0x4];
    f32 m_374;
    u8 unk_378[0x4];
    s32 m_37c;
    u8 unk_380[0x10];
    f32 m_390;
    u8 unk_394[0x4];
    f32 m_398;
    u8 unk_39C[0x8];
};
typedef char TUnk_804B8E18_size[sizeof(TUnk_804B8E18) == 0x3A4 ? 1 : -1];

#endif
