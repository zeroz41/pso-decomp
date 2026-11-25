#ifndef PSO_OBJECT_TITEMQUESTBGMTASK_H
#define PSO_OBJECT_TITEMQUESTBGMTASK_H

#include "types.h"
#include "pso/system/task/TObject.h"

/* Plays one of the event tracks; only one exists at a time, and it removes
   itself once the quest takes over the music. */
class TItemQuestBgmTask : public TObject {
public:
    TItemQuestBgmTask(TObject *parent, u32 track);
    virtual ~TItemQuestBgmTask();
    virtual void run_task();
};

void create_quest_bgm_object(TObject *parent, u32 track);

#endif
