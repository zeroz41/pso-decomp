#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804E355C.h"

extern "C" {

int resolve_attack_col_hit__13TUnk_804E355CFPUc(void*);

u8 TUnk_804E355C::has_game_join_id() {
    return (u8) (find_equipped_item(this->m_ac) != 0);
}
void TUnk_804E355C::vfunc_6(s32 *) { resolve_attack_col_hit__13TUnk_804E355CFPUc(this); }

}
