#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK2_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK2_H

#include "types.h"
class TQuestManager;
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColALock2 : public TObjQuestColBase {
    TObjQuestColALock2(TObject *parent, void *set_data);
    virtual ~TObjQuestColALock2();
    virtual int is_triggered();
    virtual TQuestThread *start_quest_thread();
    virtual void draw_debug_bounds();
    TQuestManager *thread_root;  // quest_mission_manager or quest_area_manager, per manager_kind (inferred name)
    s32 manager_kind;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjQuestColALock2_size, sizeof(TObjQuestColALock2) == 0xC4);

#endif
