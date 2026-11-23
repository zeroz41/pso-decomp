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

    TItemReverseTechPicture picture_0;
    TItemReverseTechPicture picture_1;
    TItemReverseTechPicture picture_2;
    TItemReverseTechPicture picture_3;
    TItemReverseTechPicture picture_4;
    TItemReverseTechPicture picture_5;
    TItemReverseTechPicture picture_6;
    s32 frame;
    s32 shown_count;
};
LAYOUT_ASSERT(TItemReverseTechPart2Size, sizeof(TItemReverseTechPart2) == 0x158);

#endif
