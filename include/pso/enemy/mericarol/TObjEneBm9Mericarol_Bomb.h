#ifndef PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_BOMB_H
#define PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_BOMB_H
#include <stddef.h>
#include "types.h"
#include "pso/enemy/AreaAttackContact.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/effect/particle/TParticleCtrl.h"

class TObjEneBm9Mericarol;

class TObjEneBm9Mericarol_Bomb : public TUnk_804928CC {
public:
    TObjEneBm9Mericarol_Bomb(TObjEneBm9Mericarol *owner, Vec *start, Vec *target, f32 power, f32 speed, s32 final_blast);
    virtual ~TObjEneBm9Mericarol_Bomb();
    virtual void render();
    virtual void run_task();
    virtual s32 area_attack_deliver_direct(void *recoil, saddr desc, void *object, f32 range);
    u16 owner_id;              // get_entity_id(owner); find_entity_by_id on impact
    u8 pad_B2[0x2];
    Vec pos;                   // the bomb's own position: ground-checked, moved by velocity
    Vec velocity;
    Vec look_ahead;            // pos + look_ahead is the segment tested against walls
    Vec ground_normal;        // ground surface orientation used by the shadow
    AreaAttackContact contact;
    s32 m_ec;
    s32 attack_type;           // 5 in v2 mode, else by phase; 0x12 for the final blast
    f32 power;                 // {attack_type, power} is the DirectAttackPayload &attack_type passes
    f32 fall_speed;
    s32 age;                   // frames alive; destroyed at 150
    s32 state;
    s32 phase_effect_id;       // 0x208..0x20A by the owner's phase
    s32 final_blast;           // phase 0: upgrades attack_type to 0x12 when the bomb lands
    s32 shadow_visible;
    TParticleCtrl *effect;     // particle 0x207, follows pos
    TParticleCtrl *phase_effect;
};
LAYOUT_ASSERT(MericarolBombContactOffset, offsetof(TObjEneBm9Mericarol_Bomb, contact) == 0xE4);
LAYOUT_ASSERT(TObjEneBm9Mericarol_Bomb_size, sizeof(TObjEneBm9Mericarol_Bomb) == 0x118);

LAYOUT_ASSERT(TObjEneBm9Mericarol_Bomb_ground_normal_offset, offsetof(TObjEneBm9Mericarol_Bomb, ground_normal) == 0xD8);

#endif
