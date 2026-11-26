#ifndef PSO_ITEM_TITEMREVERSETECHCTRLTYPES_H
#define PSO_ITEM_TITEMREVERSETECHCTRLTYPES_H

#include "types.h"

struct ReverseTechCode {
    s8 *keys;
    s32 length;
    void (*activate)(void);
};

#endif
