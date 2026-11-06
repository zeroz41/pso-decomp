#ifndef PSO_QUEST_CHALLENGE_TCHALLENGE4PRESULT_H
#define PSO_QUEST_CHALLENGE_TCHALLENGE4PRESULT_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/item/TItemData.h"

struct TWindowMessagePage;

class TChallenge4PResult : public TObject {
public:
    TChallenge4PResult(TObject *parent, u16 slot, s32 resultCode);
    virtual ~TChallenge4PResult();
    void sub_8034BA2C();
    void sub_8034B918();
    void sub_8034B8BC();
    void sub_8034B8B0();
    virtual void run_task();
    void show_message(s32 text_handle);
    void handle_third_reward();
    s32 state_1c;
    s32 wait_frames;
    u16 slot_index;
    u8 unknown_26[2];
    s32 result_code;
    TWindowMessagePage *message_window;
    s32 unknown_30;
    TItemData reward_items[3];
    s32 reward_available[3];

public:
    static void create(int arg0, s32 arg1);
    static void clear_slot_entries();
    void set_entry_item(void *arg1, s32 arg2);
    void close_window();
    void init_timer();
    void init_result_state();
    void init();
    void queue_destruction();
    void update_wait_input();
    void handle_result_code();
    void update_input();
public:
    int get_player_rank();
};

#include <stddef.h>
typedef char TChallenge4PResult_size[sizeof(TChallenge4PResult) == 0x7c ? 1 : -1];
typedef char TChallenge4PResult_state_1c_offset[offsetof(TChallenge4PResult, state_1c) == 0x1c ? 1 : -1];
typedef char TChallenge4PResult_slot_index_offset[offsetof(TChallenge4PResult, slot_index) == 0x24 ? 1 : -1];
typedef char TChallenge4PResult_message_window_offset[offsetof(TChallenge4PResult, message_window) == 0x2c ? 1 : -1];

typedef char ChallengeRewardsOffset[offsetof(TChallenge4PResult,reward_items)==0x34 ? 1 : -1];
typedef char ChallengeRewardFlagsOffset[offsetof(TChallenge4PResult,reward_available)==0x70 ? 1 : -1];
#endif
