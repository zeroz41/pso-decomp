#ifndef PSO_BOSS_BARBARAY_BOSS7DUSTDATA_H
#define PSO_BOSS_BARBARAY_BOSS7DUSTDATA_H

#include "types.h"

// TObjBoss7DustCtrl's and TObjBoss7Dust's class names. They live in their own unit ahead of
// TObjBoss7Dust.cpp: DustCtrl's name precedes Dust's in .sdata and .rodata although Dust's code comes
// first, so neither class unit defines them.
extern const char *TObjBoss7DustCtrl__name;
extern const char *TObjBoss7Dust__name;

#endif
