#ifndef PSO_PLAYER_BATTLEMUSICSTATE_H
#define PSO_PLAYER_BATTLEMUSICSTATE_H

#include "types.h"

class TObjPlayer;

// TObjPlayer + 0x63C. qst_op_start_battlebgm and qst_op_end_battlebgm drive it,
// update_target_lock runs it each frame and tick_battle_music_timer counts down
// its timer. Flag 1: the battle music is on; flag 2: a quest holds it
// (update_target_lock leaves it alone).
struct BattleMusicState {
    s32 flags;  // a FlagWord
    s32 timer;  // frames left before the music stops, -1 when not counting

    BattleMusicState *reset_and_clear();
    void reset_counter_field4();
    void clear_flag0_bit1();
    void set_flag_2();
    void reset_ring();
    void clear_target_lock();
    s32 tick_battle_music_timer();
    void update_target_lock(TObjPlayer *player);
    int is_quest_held();
    void set_lock_timer(s32 v);
    void clear_target_lock_flag();
    int set_lock_flag();
};

#endif
