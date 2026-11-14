#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/system/task/TObject.h"

extern "C" {
void TObjPlayer__sub_8015431C(u8 *arg0);
void reset_global_table(void);
s32 get_attack_entry__16TObjOnlineEndingFi(int);
void TItemAttackCol::check_object_hits() {
    s32 i;
    s32 e;
    reset_global_table();
    TObjPlayer__sub_8015431C((u8 *)&this->bodies);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        e = get_attack_entry__16TObjOnlineEndingFi(i);
        if (try_add_hit_target((void *)e) != 0) {
            this->vfunc_6((s32 *)e);
            this->hits_left -= 1;
            if (this->hits_left == 0) {
                queue_destruction();
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}

}
