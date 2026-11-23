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
#endif
