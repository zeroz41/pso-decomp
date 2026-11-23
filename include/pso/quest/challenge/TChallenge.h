#ifndef PSO_QUEST_CHALLENGE_TCHALLENGE_H
#define PSO_QUEST_CHALLENGE_TCHALLENGE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TChallenge : public TObject {
    TChallenge(TObject *parent);
    virtual ~TChallenge();
    virtual void render();
    s32 state;
    s32 frame_count;
    s32 missing_records_timer;
    s32 records_save_pending;
    s32 quest_send_timer; // frames until the selected quest is resent (inferred name)

    virtual void run_task();
    void update_active();
    void wait_for_quest();
    void initialize_windows();
    static void *create();
    void set_challenge_record_page(s32 mode);
    void show_challenge_record_window(s32 mode);
    void clear_challenge_record_window();
    void open_challenge_progress_window(void *slot);
    void refresh_challenge_windows();
    void request_missing_challenge_records();
    void send_6x7c_reset();
    void clear_four_slots();
    void restore_challenge_from_save();
    s32 destroy_on_phase_change();
    void update_quest_challenge_state();
    void update_battle_cleanup_flag();
    void create_time_window();
    void update_card_save_info();
};

LAYOUT_ASSERT(TChallenge_size, sizeof(TChallenge) == 0x30);

extern TChallenge *challenge_task;
#endif
