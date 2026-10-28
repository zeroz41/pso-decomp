#include "types.h"
#include "pso/item/TItem.h"
#include "pso/TObject.h"
#include "pso/TItemShootModel.h"
#include "pso/player/TObjPlayer.h"

extern "C" {


s32 TItemShootModel::is_owner_alive() {
    if (find_equipped_item(*(s32 *)&this->m_54) == 0U) {
        return 0;
    }
    return all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

}
