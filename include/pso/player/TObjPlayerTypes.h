#ifndef PSO_PLAYER_TOBJPLAYERTYPES_H
#define PSO_PLAYER_TOBJPLAYERTYPES_H

#include "types.h"

struct ItemDataWords { u32 w[5]; };

struct InventoryEntryLayout { u8 a; u8 b; u8 c; u8 d; s32 e; ItemDataWords f; };

#endif
