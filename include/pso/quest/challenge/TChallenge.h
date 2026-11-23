#ifndef PSO_QUEST_CHALLENGE_TCHALLENGE_H
#define PSO_QUEST_CHALLENGE_TCHALLENGE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TChallenge : public TObject {
    virtual ~TChallenge();
    virtual void render();
    s32 state;
    s32 frame_count;
    u32 m_24;
    u32 m_28;
    u32 m_2c;

    virtual void run_task();
    void update_active();
    void wait_for_quest();
    void initialize_windows();
    static void *create();
    void set_challenge_record_page(s32 mode);
    void show_challenge_record_window(s32 mode);
    void clear_challenge_record_window();
    void open_challenge_progress_window(void *slot);
};

LAYOUT_ASSERT(TChallenge_size, sizeof(TChallenge) == 0x30);

extern TChallenge *challenge_task;
#endif
