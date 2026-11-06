#ifndef PSO_ENEMY_TOBJENEBM9MERICAROL_BOMB_H
#define PSO_ENEMY_TOBJENEBM9MERICAROL_BOMB_H
#include "types.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/TParticleCtrl.h"

class TObjEneBm9Mericarol;

class TObjEneBm9Mericarol_Bomb : public TUnk_804928CC {
public:
    TObjEneBm9Mericarol_Bomb(TObjEneBm9Mericarol *owner, Vec *start, Vec *target, f32 farg0, f32 farg1, s32 arg4);
    virtual ~TObjEneBm9Mericarol_Bomb();
    virtual void render();
    virtual void run_task();
    virtual s32 area_attack_deliver_direct(void *recoil, s32 arg2, void *object, f32 range);
    u16 owner_id;              // get_entity_id(owner); find_entity_by_id on impact
    u8 pad_B2[0x2];
    Vec pos;                   // the bomb's own position: ground-checked, moved by velocity
    Vec velocity;
    Vec look_ahead;            // pos + look_ahead is the segment tested against walls
    Vec shadow_pos;            // ground point under the bomb (draw_oriented_shadow)
    f32 attack_power;          // {power, flags} as DelbiterContactAttack; &attack_power goes to vfunc_16
    s32 attack_flags;
    s32 m_ec;
    s32 attack_type;           // 5 in v2 mode, else by phase; 0x12 for the final blast
    f32 m_f4;
    f32 fall_speed;
    s32 age;                   // frames alive; destroyed at 150
    s32 state;
    s32 phase_effect_id;       // 0x208..0x20A by the owner's phase
    s32 m_108;
    s32 shadow_visible;
    TParticleCtrl *effect;     // particle 0x207, follows pos
    TParticleCtrl *phase_effect;
};
typedef char TObjEneBm9Mericarol_Bomb_size[sizeof(TObjEneBm9Mericarol_Bomb) == 0x118 ? 1 : -1];

#endif
