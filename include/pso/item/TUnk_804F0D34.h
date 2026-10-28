#ifndef PSO_ITEM_TUNK_804F0D34_H
#define PSO_ITEM_TUNK_804F0D34_H

#include "types.h"
#include "pso/TObject.h"
#include "pso/item/TItemObject.h"

// The tool that starts a quest's event music (create_quest_bgm_object).
class TUnk_804F0D34 : public TItemObject {
public:
    TUnk_804F0D34(TObject *parent, u8 *item);
    virtual ~TUnk_804F0D34();
    virtual void apply_use_effect();
    static TUnk_804F0D34 *create(u8 *item);
};

#endif
