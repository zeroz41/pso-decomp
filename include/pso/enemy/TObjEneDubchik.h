#ifndef PSO_ENEMY_TOBJENEDUBCHIK_H
#define PSO_ENEMY_TOBJENEDUBCHIK_H
#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"

class TUnk_80491478;

class TObjEneDubchik : public TObjEnemyCustom {
public:
    virtual ~TObjEneDubchik();
    void init_level_stats(s32);
    void sub_800AA10C();
    void sub_800A8B8C();
    void sub_800A8A7C();
    void update_fall_apart();  // state 5 (TObjEnemyCustom::vfunc_63): falls apart into parts, reassembles
    virtual s32 update_shock_clock();
    s32 sub_800AB068();
    f32 sub_800AAF78(s32);
    virtual void vfunc_59();
    virtual void vfunc_58();
    s16 reassemble_count;  // 0x38C: bumped each time it falls apart; at 5 it stays dead (inferred)
    u8 pad_38E[0x2];
    s16 attack_count;  // 0x390: attacks since the last retarget; past 3 it retargets the nearest player (inferred)
    s16 collapsed;  // 0x392: set while the parts lie apart; render then draws with the base texlist (inferred)
    TUnk_80491478 *parts[3];  // the pieces it falls apart into
    s8 part_hit[3];
    u8 pad_3A3[0x1];
    f32 chase_distance;  // 0x3A4: distance walked while chasing; past a threshold it may switch target (inferred)
    u8 unk_3A8[0x28];
    f32 search_range;  // 0x3D0: passed to find_target_in_range (inferred)
    Vec part_offsets[3];
    u8 pad_3F8[0x24];
};
typedef char TObjEneDubchik_size[sizeof(TObjEneDubchik) == 0x41C ? 1 : -1];

#endif
