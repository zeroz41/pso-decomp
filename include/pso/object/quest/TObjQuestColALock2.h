#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK2_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK2_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColALock2 : public TObjQuestColBase {
    TObjQuestColALock2(TObject *parent, void *set_data);
    virtual ~TObjQuestColALock2();
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
    virtual void update_room_id_check();
    TObject *thread_root;  // quest_mission_manager or quest_area_manager, per m_c0 (inferred name)
    s32 m_c0;
};

typedef char TObjQuestColALock2_size[sizeof(TObjQuestColALock2) == 0xC4 ? 1 : -1];

#endif
