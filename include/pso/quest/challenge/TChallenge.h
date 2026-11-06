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
};

typedef char TChallenge_size[sizeof(TChallenge) == 0x30 ? 1 : -1];
#endif
