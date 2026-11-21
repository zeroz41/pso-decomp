#ifndef PSO_UI_WINDOW_TWINDOWCHALLENGERESULT_H
#define PSO_UI_WINDOW_TWINDOWCHALLENGERESULT_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChallengeResult : public TWindowBase {
    TWindowChallengeResult(const char *team_name, s32 clear_seconds, s32 death_count);
    virtual ~TWindowChallengeResult();
    virtual void run_task();
    virtual void render();

    f32 scale_x;
    f32 scale_y;
};

typedef char ChallengeResultScaleOffset[offsetof(TWindowChallengeResult, scale_x) == 0x60 ? 1 : -1];
typedef char TWindowChallengeResult_size[sizeof(TWindowChallengeResult) == 0x68 ? 1 : -1];

#endif
