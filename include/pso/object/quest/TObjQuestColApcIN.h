#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPCIN_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPCIN_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApcIN : public TObjQuestColBase {
    TObjQuestColApcIN(TObject *parent, ObjectSetData *set_data);
    virtual int is_triggered();
    virtual TQuestThread *start_quest_thread();
    f32 party_radius;  // scale.y; every other player must stand this close (inferred name)
};

LAYOUT_ASSERT(TObjQuestColApcIN_size, sizeof(TObjQuestColApcIN) == 0xC0);

#endif
