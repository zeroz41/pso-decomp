#ifndef PSO_QUEST_TQUESTCOLCTRL_H
#define PSO_QUEST_TQUESTCOLCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

extern s32 quest_collision_warp_pending;  // set by TObjQuestColApcINW's trigger check

struct TQuestColCtrl : public TObject {
    TQuestColCtrl(TObject *parent);
    virtual ~TQuestColCtrl();
    virtual void render();
    virtual void run_task();
    static void delete_by_param(s32 arg0);
    static void init();
    static void sub_80196EC0();  // clears quest_collision_warp_pending
};

LAYOUT_ASSERT(TQuestColCtrl_size, sizeof(TQuestColCtrl) == 0x1C);
#endif
