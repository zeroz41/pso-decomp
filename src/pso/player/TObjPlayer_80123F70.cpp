#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A1F20.h"
#include "pso/item/TUnk_804A1E28.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 refresh_owner_stats__14TItemEquipBaseFv();
}

// Sorcerer's Cane (inferred): both reset the cached owner TP.
void TUnk_804A1E28::vfunc_57() { m_1fc = -1; }
void TUnk_804A1E28::vfunc_58() { m_1fc = -1; }
void TUnk_804A1F20::update_weapon() {
    void *temp_r3;

    refresh_owner_stats__14TItemEquipBaseFv();
    temp_r3 = (*(void * *)((u8 *)this + 0xF4));
    if (temp_r3 != NULL) {
        scroll_item_model_uvs(*(NJS_OBJECT **)((s8 *)temp_r3 + 0x2C), 2, 0, 1);
    }
}
