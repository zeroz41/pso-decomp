#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOL2_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOL2_H

#include "types.h"
class TUnk_804C8678;
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestCol2 : public TObjQuestColBase {
    TObjQuestCol2(TObject *parent, void *set_data);
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
    virtual ~TObjQuestCol2();
    TUnk_804C8678 *thread_root;  // quest_mission_manager or quest_area_manager, per m_c0 (inferred name)
    s32 m_c0;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjQuestCol2_size, sizeof(TObjQuestCol2) == 0xC4);

#endif
