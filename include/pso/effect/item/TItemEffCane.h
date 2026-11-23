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

    static const char *class_name;
};

LAYOUT_ASSERT(CaneAttachmentOffset, offsetof(TItemEffCane, attachment_index) == 0x1C);
LAYOUT_ASSERT(CaneEffectOffset, offsetof(TItemEffCane, effect) == 0x20);
LAYOUT_ASSERT(CaneItemIdOffset, offsetof(TItemEffCane, item_id) == 0x24);
LAYOUT_ASSERT(CaneEffectSize, sizeof(TItemEffCane) == 0x28);

#endif
