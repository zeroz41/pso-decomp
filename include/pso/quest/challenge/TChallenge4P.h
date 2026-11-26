#ifndef PSO_QUEST_CHALLENGE_TCHALLENGE4P_H
#define PSO_QUEST_CHALLENGE_TCHALLENGE4P_H

#include "types.h"
#include "pso/system/task/TObject.h"

// The split-screen challenge task: TChallenge's twin for challenge4p_mode_state.
struct TChallenge4P : public TObject {
    TChallenge4P(TObject *parent);
    virtual ~TChallenge4P();
    virtual void run_task();
    static TChallenge4P *create();
    void create_time_window();
    void refresh_challenge_windows();
    void clear_four_slots();
    void restore_challenge_from_save();
    s32 destroy_on_phase_change();
    void update_active();

    s32 frame_count;
    s32 pad_20;
    s32 pad_24;
    s32 pad_28;
};

LAYOUT_ASSERT(TChallenge4P_size, sizeof(TChallenge4P) == 0x2C);

extern TChallenge4P *challenge_retry_object;

struct TLobby;
struct TItemData;
void challenge_set_min_clear_time(s32 v);
void challenge_set_boss_warp_disabled(s32 disabled);
s32 get_challenge4p_retry_choice(void);
s32 challenge_get_time_record(void);
void challenge_set_time_record(s32 seed);
extern "C" {
s32 challenge_set_rank_override(const char *match, const char *title, s32 color);
}
s32 challenge_check_rank_time(s32 seed, s32 card);
s32 challenge_set_rank_threshold(s32 idx, s32 value, s32 arg);
s32 challenge_create_reward_item(TItemData *item, u16 slot_index);
s32 challenge_check_any_player_dead(void);
s32 challenge_check_all_players_dead(void);
extern "C" {
s32 TLobby__sub_80292AB4(s32 total, u16 card, s32 slot);
s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id);
s32 TLobby__sub_80292DA0(s32 seed, u16 card);
}
s32 is_challenge_time_limit_invalid(s32 limit);
int get_camera_view_count(void);
void clear_challenge_and_split_screen_flags(void);
void load_tombstone_resources();
void save_challenge_tombstone_spot(s32 client);
s32 count_card_layout_entries(s32 client);
void enable_split_screen_challenge_mode(void);
s32 is_challenge_mode_active(void);
void setup_split_screen(void);

struct RebuildPlayersForStageHdr { u32 w[2]; };

struct RebuildPlayersForStageInfo { u8 pad0[0x31]; u8 cls; u8 pad32[2]; u32 flags; u8 pad38[0x50 - 0x38]; };

struct ByteBlock_690 { u8 bytes[0x690]; };

s32 calc_min_challenge_progress();
s32 check_ready_status();
void clamp_and_store_layout_index(s32 stage);
void copy_global_value_block();
void destroy_tombstone();
void draw_if_ready2();
s32 get_normalized_mode();
void rebuild_players_for_stage(s32 stage);
void reset_menu_state_globals();
s32 set_camera_height_if_valid(f32 multiplier);
void set_challenge_split_flag();
void set_retry_selection(s32 choice);
void spawn_player_tombstones2();
void store_challenge_seeds(s32 seed);
s32 try_set_split_screen(s32 difficulty);
void update_challenge_timer(s32 time);
void update_screen();

void set_split_screen_name(const char *name);

s32 get_challenge_mode_flag();

#endif
