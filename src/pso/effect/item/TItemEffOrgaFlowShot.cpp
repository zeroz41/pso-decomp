#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804E355C.h"

s32 TUnk_804E355C::has_game_join_id() {
    return find_equipped_item(item_id) != 0;
}

void TUnk_804E355C::vfunc_6(s32 *hit) { resolve_attack_col_hit((u8 *)hit); }
