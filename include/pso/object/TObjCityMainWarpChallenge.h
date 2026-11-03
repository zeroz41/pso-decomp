#ifndef PSO_OBJECT_TOBJCITYMAINWARPCHALLENGE_H
#define PSO_OBJECT_TOBJCITYMAINWARPCHALLENGE_H

#include "types.h"
#include "pso/object/TObjAreaWarp.h"

struct TObjCityMainWarpChallenge : public TObjAreaWarp {
    virtual ~TObjCityMainWarpChallenge();
    void close_windows();
    virtual void debug_print_area_num();
    void count_players_in_warp_radius();
    void update_challenge_state();
    void trigger_warp_effect(s32);
    void send_6x6A_set_boss_warp_flags(u16);
    s32 are_all_players_in_range();
    u8 unk_AC[0x4];
    u32 m_b0;
    u32 m_b4;
    u8 _padB8[0x4];
    s32 dest_floor;
    u8 _padC0[0x10];
    u32 m_d0;
    u32 m_d4;
    u8 _padD8[0x4];
    s16 next_state;
    s16 state;
    s16 m_e0;
    s16 m_e2;
    char player_names[4][0x18];
    s32 player_in_range[4];
    s32 player_count;
    s32 players_in_range;
    s32 player_on_dest_floor;
    u8 _pad160[0x4];
    void *player_list_window;
    void *yes_no_window;
    u32 m_16c;
    void update_state();
    void render();
    void run_task();
    u8 unk_170[0x4];
    s32 m_174;
    u8 unk_178[0x8];
};

typedef char TObjCityMainWarpChallenge_size[sizeof(TObjCityMainWarpChallenge) == 0x180 ? 1 : -1];
typedef char TObjCityMainWarpChallenge_m_d0[offsetof(TObjCityMainWarpChallenge, m_d0) == 0xD0 ? 1 : -1];
typedef char TObjCityMainWarpChallenge_m_174[offsetof(TObjCityMainWarpChallenge, m_174) == 0x174 ? 1 : -1];

extern "C" {
u8 *TObjCityMainWarpChallenge__ct(u8 *arg0);
}

#endif
