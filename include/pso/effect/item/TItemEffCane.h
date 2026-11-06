#ifndef PSO_EFFECT_ITEM_TITEMEFFCANE_H
#define PSO_EFFECT_ITEM_TITEMEFFCANE_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

struct TItem;

class TItemEffCane : public TObject {
public:
    TItemEffCane(TObject* parent, TItem* item, s32 attachment_index, s32 effect_id);
    virtual ~TItemEffCane();
    virtual void run_task();

    s32 attachment_index;
    void* effect;
    s32 item_id;
};

typedef char CaneAttachmentOffset[(offsetof(TItemEffCane, attachment_index) == 0x1C) ? 1 : -1];
typedef char CaneEffectOffset[(offsetof(TItemEffCane, effect) == 0x20) ? 1 : -1];
typedef char CaneItemIdOffset[(offsetof(TItemEffCane, item_id) == 0x24) ? 1 : -1];
typedef char CaneEffectSize[(sizeof(TItemEffCane) == 0x28) ? 1 : -1];

#endif
