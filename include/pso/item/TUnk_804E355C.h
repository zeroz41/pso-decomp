#ifndef PSO_ITEM_TUNK_804E355C_H
#define PSO_ITEM_TUNK_804E355C_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804E355C : public TObject {
public:
    virtual ~TUnk_804E355C();
    void check_hits();
    s32 try_add_hit_target(void *);
    virtual void vfunc_6(s32 *);
    void *destroy_attack_collision(s16);
    u8 has_game_join_id();
    s32 resolve_attack_col_hit(u8 *);
    u8 unk_1C[0x4];
    s32 m_20;
    f32 m_24;
    float m_28;
    u8 unk_2C[0x4];
    float m_30;
    u8 unk_34[0x4];
    f32 m_38;
    u8 unk_3C[0x4];
    f32 m_40;
    u8 unk_44[0x4];
    s32 m_48;
    u8 unk_4C[0x4];
    f32 m_50;
    u8 unk_54[0x4];
    f32 m_58;
    u8 unk_5C[0x44];
    s32 m_a0;
    s32 m_a4;
    u16 client_id; // compared with get_entity_id() and passed to get_player_by_client_id()
    u8 unk_AA[0x2];
    s32 m_ac;
    u8 unk_B0[0x4];
    f32 m_b4;
    u8 unk_B8[0x4];
    s32 m_bc;
    u8 unk_C0[0x4];
};

#endif
