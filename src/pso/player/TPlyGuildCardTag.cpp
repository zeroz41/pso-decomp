#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

void __ct__16TPlyGuildCardTagFUsUl(void *tag, s16 tag2, s32 guildcard_number) {
    *(s8 *)((s8 *)tag + 0) = 0;
    *(s8 *)((s8 *)tag + 1) = 0;
    *(s16 *)((s8 *)tag + 2) = tag2;
    *(s32 *)((s8 *)tag + 4) = guildcard_number;
}
