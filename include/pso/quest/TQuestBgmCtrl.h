#ifndef PSO_QUEST_TQUESTBGMCTRL_H
#define PSO_QUEST_TQUESTBGMCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TQuestBgmCtrl : public TObject {
public:
    static void force_bgm(int index);
    static void defer_bgm(int index);
    TQuestBgmCtrl(TObject* parent);
    virtual ~TQuestBgmCtrl();
    virtual void run_task();
};

// Set while a quest has issued its own BGM; the music zones leave the music alone then.
extern s32 quest_bgm_ctrl_bgm_issued_flag;

LAYOUT_ASSERT(TQuestBgmCtrlSize, sizeof(TQuestBgmCtrl) == 0x1C);

#endif
