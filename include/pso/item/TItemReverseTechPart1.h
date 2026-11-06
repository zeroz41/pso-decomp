#ifndef PSO_ITEM_TITEMREVERSETECHPART1_H
#define PSO_ITEM_TITEMREVERSETECHPART1_H

#include "pso/TObject.h"
#include "types.h"

class TItemReverseTechPart1 : public TObject {
public:
    virtual ~TItemReverseTechPart1();
    virtual void run_task();
};

extern "C" {
void *TItemReverseTechPart1__ct(void *item_reverse_tech_part1, void *parent, void *texture_archive);
}

#endif
