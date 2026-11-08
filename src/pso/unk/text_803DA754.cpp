#include "types.h"
#include "pso/unk/text_803DA754.h"
extern "C" {
void init_record_array__10TObjPlayerFl();
void TObjPlayer__sub_803DA388(void *, void *);
void init_record_and_slot_arrays(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    init_record_array__10TObjPlayerFl();
    TObjPlayer__sub_803DA388(arg2, arg3);
}

}
