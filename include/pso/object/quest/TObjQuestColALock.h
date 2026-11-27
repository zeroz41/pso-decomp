#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColALock : public TObjQuestColBase {
    TObjQuestColALock(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjQuestColALock();
    virtual int is_triggered();
    virtual TQuestThread *start_quest_thread();
    virtual void draw_debug_bounds();
};

LAYOUT_ASSERT(TObjQuestColALock_size, sizeof(TObjQuestColALock) == 0xBC);

#endif
