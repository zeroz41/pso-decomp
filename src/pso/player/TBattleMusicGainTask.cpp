#include "types.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/player/TBattleMusicGainTask.h"
#include "pso/network/TLobby.h"
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/player/TBattleMusicGainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/audio/SoundRequests.h"
#include "pso/ui/hud/SplitScreenQuery.h"

TBattleMusicGainTask *duel_result_window;

void show_duel_result_window(saddr gain, saddr duration) {
    if (duel_result_window != NULL) {
        duel_result_window->countdown = duration;
        duel_result_window->gain_offset = gain;
        set_and_notify(gain);
        return;
    }
    duel_result_window = new TBattleMusicGainTask(tl_00, gain, duration);
}

TBattleMusicGainTask::~TBattleMusicGainTask() {
    duel_result_window = NULL;
}

void TBattleMusicGainTask::run_task() {
    if (--countdown <= 0) {
        set_and_notify(0);
        queue_destruction();
        return;
    }
    if (countdown <= 15) {
        set_and_notify((s32)((0.06666667f * (f32)countdown) * (f32)gain_offset));
    }
}

TBattleMusicGainTask::TBattleMusicGainTask(TObject *parent, s32 gain, s32 duration) : TObject(parent) {
    countdown = duration;
    gain_offset = gain;
    set_and_notify(gain);
}


BattleRanking *get_battle_rankings(void) {
    if (is_not_split_screen() == 1) {
        return get_split_screen_battle_rankings();
    }
    return duel_result_table;
}
