#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLBASE_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLBASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TQuestThread;

// A quest collision trigger (TObjQuestCol.cpp holds the whole family and TQuestColCtrl).
// run_task asks the subclass whether it triggered and, if so, has it start its quest thread.
struct TObjQuestColBase : public TObjCollidable {
    TObjQuestColBase(TObject *parent, void *set_data);
    virtual ~TObjQuestColBase();
    virtual void update_room_id_check();
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
    s32 update_trigger_state(f32);
    virtual void render();
    f32 radius;  // scale.x; is_within_range tests radius squared (inferred name)
    u32 label;
    u32 m_b4;
    TQuestThread *m_b8;  // the quest thread run_task started, until it is queued for destruction
    s32 is_within_range(f32 range_sq);
    virtual void run_task();
};

LAYOUT_ASSERT(TObjQuestColBase_size, sizeof(TObjQuestColBase) == 0xBC);

#endif
