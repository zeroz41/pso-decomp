#ifndef PSO_PLAYER_PLAYERBATTLESCORE_H
#define PSO_PLAYER_PLAYERBATTLESCORE_H

#include "types.h"
#include <stddef.h>

// One damage accumulation slot of a battle score: the weighted running total,
// the raw amount, and the two weight factors damage_weight picks between.
struct DamageStatSlot {
    f32 total;
    f32 accumulated;
    f32 normal_weight;
    f32 bonus_weight;

    DamageStatSlot();
    void init();
    f32 get_bonus_weight();
    s32 get_total();
    void set_total(f32 v);
    void reset();
    void set_accumulated(f32 v);
    void set_normal_weight(f32 v);
    void set_bonus_weight(f32 v);
};

// The tail of the battle score; the battle controllers rank players by score.
struct PlayerSubObjectSlots {
    s32 pad_0[4];
    s32 pad_10;
    s32 score;

    PlayerSubObjectSlots();
    s32 get_score();
    void set_score(s32 v);
};

// TObjPlayer + 0x754, the battle-rule score. The duel result window shows the
// kill, death, damage-given and damage-taken slots; meseta adds to the score
// by its own weight.
struct PlayerBattleScore {
    s32 timer;
    s32 pad_4;
    DamageStatSlot kills;
    DamageStatSlot deaths;
    DamageStatSlot damage_taken;
    DamageStatSlot damage_given;
    DamageStatSlot meseta;
    PlayerSubObjectSlots slots;

    PlayerBattleScore();
    ~PlayerBattleScore();
    // Clears the timer and every score slot.
    void reset();
    void set_timer(s32 v);
    s32 get_timer();
};

LAYOUT_ASSERT(DamageStatSlot_size, sizeof(DamageStatSlot) == 0x10);
LAYOUT_ASSERT(PlayerSubObjectSlots_size, sizeof(PlayerSubObjectSlots) == 0x18);
LAYOUT_ASSERT(PlayerBattleScore_kills_offset, offsetof(PlayerBattleScore, kills) == 0x8);
LAYOUT_ASSERT(PlayerBattleScore_size, sizeof(PlayerBattleScore) == 0x70);

class TObject;
// Adds amount to the slot's raw sum and its weight-scaled amount (damage_weight) to its total.
s32 accumulate_damage_stats(DamageStatSlot *slot, TObject *target, s32 amount);
f32 damage_weight(DamageStatSlot *slot, TObject *target, s32 amount);

#endif
