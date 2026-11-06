#include "types.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/object/ending/TObjOnlineEnding.h"

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
void TObjPlayer__sub_8015431C(u8 *arg0);
void reset_global_table(void);
s32 get_attack_entry__16TObjOnlineEndingFi(int);
void TItemAttackCol::check_object_hits() {
    s32 i;
    s32 e;
    reset_global_table();
    TObjPlayer__sub_8015431C(((u8 *)this) + 0x1C);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        e = get_attack_entry__16TObjOnlineEndingFi(i);
        if (try_add_hit_target((void *)e) != 0) {
            this->vfunc_6((s32 *)e);
            this->m_a4 -= 1;
            if (this->m_a4 == 0) {
                queue_destruction__7TObjectFv(this);
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}

}
