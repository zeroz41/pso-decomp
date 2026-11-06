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

typedef char TQuestBgmCtrlSize[(sizeof(TQuestBgmCtrl) == 0x1C) ? 1 : -1];

#endif
