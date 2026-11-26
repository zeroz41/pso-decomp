#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOL2_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOL2_H

#include "types.h"
class TQuestManager;
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestCol2 : public TObjQuestColBase {
    TObjQuestCol2(TObject *parent, void *set_data);
    virtual int is_triggered();
    virtual TQuestThread *start_quest_thread();
    virtual ~TObjQuestCol2();
    TQuestManager *thread_root;  // quest_mission_manager or quest_area_manager, per manager_kind (inferred name)
    s32 manager_kind;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjQuestCol2_size, sizeof(TObjQuestCol2) == 0xC4);

#endif
