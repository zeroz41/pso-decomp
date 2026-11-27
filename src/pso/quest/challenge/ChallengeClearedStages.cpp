#include "types.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/quest/challenge/ChallengeMode.h"

s32 TChallenge::count_cleared_stages(ChallengeRecord *record, s32 slot) {
    s32 n;
    s32 i;
    s32 *p;
    slot = resolve_challenge_record_set(slot);
    p = challenge_set_stage_times(record, slot);
    n = challenge_set_stage_count(slot);
    for (i = 0; i < n; i++, p++) {
        s32 r = decode_challenge_time(*p);
        if (*p == 0 || r == 0) {
            break;
        }
    }
    return i;
}
