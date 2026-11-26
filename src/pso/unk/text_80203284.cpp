#include "types.h"
#include "pso/unk/text_80203284.h"
#include "pso/quest/challenge/TChallenge.h"
u8 is_challenge_task_running(void) {
    s32 r = 0;
    if (challenge_task != NULL && challenge_task->state == 2) r = 1;
    return r;
}
