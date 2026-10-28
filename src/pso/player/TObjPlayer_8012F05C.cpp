#include "types.h"
#include "pso/item/TItemProArmor.h"
#include "pso/player/TObjPlayer_8012F05C.h"

extern "C" {

int scale_current_matrix(void*);
s32 get_owner_client__5TItemFv(void *);
s32 init_item_timer_event__13TUnk_804A0648Fv(s32, u32, s32, s32);
int get_player_list__10TObjPlayerFv(void*);
s32 __nw__15TItemHeapObjectFUl(s32);
}

void madam_parasol_scale_canopy(void* p) { if (get_player_list__10TObjPlayerFv(p) == 2) { scale_current_matrix((char*)p + 0x1f8); } }

void madam_parasol_start_regen(void *item_pro_armor) {
    s32 temp_r3;

    if ((u32) ((TItemProArmor *)item_pro_armor)->effect_objects != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            init_item_timer_event__13TUnk_804A0648Fv(temp_r3, (u32)((TItemProArmor *)item_pro_armor)->effect_objects, get_owner_client__5TItemFv(item_pro_armor), 0x5A);
        }
    }
}
