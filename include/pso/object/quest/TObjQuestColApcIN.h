#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPCIN_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPCIN_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApcIN : public TObjQuestColBase {
    TObjQuestColApcIN(TObject *parent, void *set_data);
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
    f32 party_radius;  // scale.y; every other player must stand this close (inferred name)
};

LAYOUT_ASSERT(TObjQuestColApcIN_size, sizeof(TObjQuestColApcIN) == 0xC0);

#endif
