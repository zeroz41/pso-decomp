#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZAKO_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZAKO_H
#include "types.h"
struct TBoss4ZakoVec3 { f32 x, y, z; };
struct TBoss4ZakoCollisionState { u8 _pad0[0x18]; s32 flags; };
struct TBoss4Zako {
    s32 sub_8005D6B0();
    s32 sub_8005D698();
 u8 _pad0[0x1c]; u16 m_1c; u8 _pad1e[6];
 u32 m_24; u8 _pad28[0xc]; u32 m_34;
 TBoss4ZakoVec3 m_38, m_44, m_50;
 s32 m_5c, m_60; u8 _pad64[0x10]; TBoss4ZakoVec3 m_74;
 u8 _pad80[0x228]; u32 m_2a8; u8 _pad2ac[0x1C]; s16 m_2c8; u8 _pad2ca[0x32];
 u8 m_2fc[0x30]; s16 m_32c; u8 _pad32e[0x10]; u16 m_33e;
 u8 _pad340[0x34]; s32 m_374; void *m_378; u8 _pad37c[4];
 u32 m_380; TBoss4ZakoCollisionState *m_384; s32 m_388;
 TBoss4ZakoVec3 m_38c; f32 m_398, m_39c, m_3a0;
 s32 m_3a4, m_3a8, m_3ac; f32 m_3b0; void *m_3b4;
 s32 m_3b8, m_3bc, m_3c0;
 void apply_contact_damage();
 void run_task();
 void update_rise_state();
 void update_move_to_target_state();
 void update_surround_player_state();
 void update_sink_state();
    static s32 create(s32 arg0);
    void set_state3();
    void update_orbit_velocity();
    static s32 queue_entry(void *v, s32 a, s32 b);
    void update_target_position();
};
typedef char TBoss4ZakoSize[(sizeof(TBoss4Zako)==0x3C4)?1:-1];
#include <stddef.h>
#define ZAKO_OFFSET(field, offset) typedef char ZakoOffset_##field[(offsetof(TBoss4Zako, field)==offset)?1:-1]
ZAKO_OFFSET(m_1c, 0x1C);
ZAKO_OFFSET(m_24, 0x24);
ZAKO_OFFSET(m_34, 0x34);
ZAKO_OFFSET(m_38, 0x38);
ZAKO_OFFSET(m_44, 0x44);
ZAKO_OFFSET(m_50, 0x50);
ZAKO_OFFSET(m_5c, 0x5C);
ZAKO_OFFSET(m_60, 0x60);
ZAKO_OFFSET(m_74, 0x74);
ZAKO_OFFSET(m_2a8, 0x2A8);
ZAKO_OFFSET(m_2c8, 0x2C8);
ZAKO_OFFSET(m_2fc, 0x2FC);
ZAKO_OFFSET(m_32c, 0x32C);
ZAKO_OFFSET(m_33e, 0x33E);
ZAKO_OFFSET(m_374, 0x374);
ZAKO_OFFSET(m_378, 0x378);
ZAKO_OFFSET(m_380, 0x380);
ZAKO_OFFSET(m_384, 0x384);
ZAKO_OFFSET(m_388, 0x388);
ZAKO_OFFSET(m_38c, 0x38C);
ZAKO_OFFSET(m_398, 0x398);
ZAKO_OFFSET(m_39c, 0x39C);
ZAKO_OFFSET(m_3a0, 0x3A0);
ZAKO_OFFSET(m_3a4, 0x3A4);
ZAKO_OFFSET(m_3a8, 0x3A8);
ZAKO_OFFSET(m_3ac, 0x3AC);
ZAKO_OFFSET(m_3b0, 0x3B0);
ZAKO_OFFSET(m_3b4, 0x3B4);
ZAKO_OFFSET(m_3b8, 0x3B8);
ZAKO_OFFSET(m_3bc, 0x3BC);
ZAKO_OFFSET(m_3c0, 0x3C0);
#undef ZAKO_OFFSET
#endif
