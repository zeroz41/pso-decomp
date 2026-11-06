#ifndef PSO_ENEMY_TUNK_8048FE08_H
#define PSO_ENEMY_TUNK_8048FE08_H
#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class AreaAttackHistory;

// The Bringer's TP-absorb shot: a box hitbox that TObjEneDf2Bringer fires along its facing
// (setup_dir_shot) and that deals one hit per AreaAttackHistory entry. Its ctor names it with
// bringer_tp_absorb_effect_name ("TObjEneDf2Bringer_Eff_TpAbsorb1"), shared with TUnk_8048FE64 and
// TUnk_8048FE7C; the twin of TObjEneDellBiter_Eff_TpAbsorb1.
class TUnk_8048FE08 : public TUnk_804928CC {
public:
    TUnk_8048FE08(TObject *parent, TObjBase *owner, AreaAttackHistory *history);
    virtual ~TUnk_8048FE08();
    virtual void run_task();
    virtual void render();
    void setup_dir_shot(const Vec *origin, s32 angle, f32 attack_power);
    void sub_8009A11C();
    s32 active;
    s32 timer;  // frames left before the shot stops
    Vec direction;
    AreaAttackHistory *attack_history;
    f32 distance;
    f32 sample_distance;
    f32 power;
};
typedef char TUnk_8048FE08_size[sizeof(TUnk_8048FE08) == 0xD4 ? 1 : -1];

#endif
