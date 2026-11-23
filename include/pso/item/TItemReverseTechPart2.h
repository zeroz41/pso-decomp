#ifndef PSO_ITEM_TITEMREVERSETECHPART2_H
#define PSO_ITEM_TITEMREVERSETECHPART2_H

#include "pso/system/task/TObject.h"
#include "pso/item/TItemReverseTechBG.h"
#include "types.h"

class TItemReverseTechPart2 : public TObject {
public:
    TItemReverseTechPart2(TObject *parent, NJS_TEXLIST *texlist);
    virtual ~TItemReverseTechPart2();
    virtual void run_task();
    virtual void render();
public:
    static void destroy_and_flag(TObject *fade);

    TItemReverseTech_8011A54C picture_0;
    TItemReverseTech_8011A54C picture_1;
    TItemReverseTech_8011A54C picture_2;
    TItemReverseTech_8011A54C picture_3;
    TItemReverseTech_8011A54C picture_4;
    TItemReverseTech_8011A54C picture_5;
    TItemReverseTech_8011A54C picture_6;
    s32 frame;
    s32 shown_count;
};
LAYOUT_ASSERT(TItemReverseTechPart2Size, sizeof(TItemReverseTechPart2) == 0x158);

#endif
