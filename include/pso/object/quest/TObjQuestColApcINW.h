#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPCINW_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPCINW_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApcINW : public TObjQuestColBase {
    TObjQuestColApcINW(TObject *parent, ObjectSetData *set_data);
    virtual int is_triggered();
    virtual TQuestThread *start_quest_thread();
    f32 party_radius;  // scale.y; a player farther than this is warped (inferred name)
    Vec warp_pos;      // copied to quest_col_apc_warp_target_pos (inferred name)
};

LAYOUT_ASSERT(TObjQuestColApcINW_size, sizeof(TObjQuestColApcINW) == 0xCC);

#endif
