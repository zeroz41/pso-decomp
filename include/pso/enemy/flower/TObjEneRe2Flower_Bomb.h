#ifndef PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_BOMB_H
#define PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_BOMB_H
#include <stddef.h>

#include "types.h"
#include "pso/enemy/AreaAttackContact.h"
#include "pso/object/base/TAttackCollider.h"

struct TObjEneRe2Flower;
class TParticleCtrl;

class TObjEneRe2Flower_Bomb : public TAttackCollider {
public:
    TObjEneRe2Flower_Bomb(TObjEneRe2Flower *owner, const Vec *start, s32 heading);
    virtual ~TObjEneRe2Flower_Bomb();
    virtual s32 area_attack_deliver_direct(const AreaAttackContact *contact, DirectAttackPayload *attack, AreaAttackHistory *history, f32 range);
    virtual void render();
    virtual void run_task();
    static const char *class_name;
    u16 owner_id;
    u8 pad_b2[2];
    Vec start_position;
    Vec velocity;
    Vec probe_velocity;
    Vec ground_normal;
    AreaAttackContact contact;
    s32 heading;
    f32 vertical_speed;
    s32 age;
    s32 state;
    TParticleCtrl *effect;
    s32 has_ground;
};
LAYOUT_ASSERT(TObjEneRe2Flower_Bomb_size, sizeof(TObjEneRe2Flower_Bomb) == 0x104);

LAYOUT_ASSERT(FlowerBombStartOffset, offsetof(TObjEneRe2Flower_Bomb, start_position) == 0xB4);
LAYOUT_ASSERT(FlowerBombGroundNormalOffset, offsetof(TObjEneRe2Flower_Bomb, ground_normal) == 0xD8);
LAYOUT_ASSERT(FlowerBombContactOffset, offsetof(TObjEneRe2Flower_Bomb, contact) == 0xE4);
LAYOUT_ASSERT(FlowerBombEffectOffset, offsetof(TObjEneRe2Flower_Bomb, effect) == 0xFC);

#endif
