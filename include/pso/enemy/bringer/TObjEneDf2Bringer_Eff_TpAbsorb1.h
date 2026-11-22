#ifndef PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_EFF_TPABSORB1_H
#define PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_EFF_TPABSORB1_H
#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class AreaAttackHistory;

// The Bringer's TP-absorb shot: a box hitbox that TObjEneDf2Bringer fires along its facing
// (setup_dir_shot) and that deals one hit per AreaAttackHistory entry. Its ctor names it with
// bringer_tp_absorb_effect_name ("TObjEneDf2Bringer_Eff_TpAbsorb1"), shared with TUnk_8048FE64 and
// TUnk_8048FE7C; the twin of TObjEneDellBiter_Eff_TpAbsorb1.
class TObjEneDf2Bringer_Eff_TpAbsorb1 : public TUnk_804928CC {
public:
    TObjEneDf2Bringer_Eff_TpAbsorb1(TObject *parent, TObjBase *owner, AreaAttackHistory *history);
    virtual ~TObjEneDf2Bringer_Eff_TpAbsorb1();
    virtual void run_task();
    virtual void render();
    void setup_dir_shot(const Vec *origin, s32 angle, f32 attack_power);
    void deactivate();  // active = 0: a hit wall, a hit body or the timer stops the shot
    s32 active;
    s32 timer;  // frames left before the shot stops
    Vec direction;
    AreaAttackHistory *attack_history;
    f32 distance;
    f32 sample_distance;
    f32 power;
};
LAYOUT_ASSERT(TObjEneDf2Bringer_Eff_TpAbsorb1_size, sizeof(TObjEneDf2Bringer_Eff_TpAbsorb1) == 0xD4);

#endif
