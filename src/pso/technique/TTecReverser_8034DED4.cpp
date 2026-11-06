#include "types.h"
#include "pso/technique/TTecReverser.h"

extern "C" {

s32 all_parents_unqueued_for_destruction__7TObjectFv();

u8 TTecReverser::is_active() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0) && !(*(s32 *)((s8 *)this + 0x30) & 0x02040800)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

}
