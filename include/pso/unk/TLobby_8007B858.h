#ifndef PSO_UNK_TLOBBY_8007B858_H
#define PSO_UNK_TLOBBY_8007B858_H

#include "types.h"

extern "C" {
void TLobby__sub_8007BBEC(void);
void TLobby__sub_8007BBF8(void);
}

struct CollectActiveCardIdsL { u8 pad0; u8 count; u8 pad2[2]; s32 ids[30]; };

#endif
