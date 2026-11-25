#ifndef PSO_ITEM_TITEMTOOLQUESTBGM_H
#define PSO_ITEM_TITEMTOOLQUESTBGM_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemObject.h"

// The tool that starts a quest's event music (create_quest_bgm_object).
class TItemToolQuestBgm : public TItemObject {
public:
    TItemToolQuestBgm(TObject *parent, u8 *item);
    virtual ~TItemToolQuestBgm();
    virtual void apply_use_effect();
    static TItem *create(u8 *item);
};

#endif
