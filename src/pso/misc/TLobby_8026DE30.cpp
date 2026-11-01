#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"

extern "C" {

s32 init_list_entry__20TWindowSubStatusDispFUcll(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0);
s32 get_array_entry__11TWindowBaseFi(void * a0 = 0);

void TWindowMenuIconLine::add_list_entry(s32 arg1, s32 arg2, s32 arg3) {
    if (this->entry_count < this->entry_capacity) {
        init_list_entry__20TWindowSubStatusDispFUcll(get_array_entry__11TWindowBaseFi(this), arg1, arg2, arg3);
        this->entry_count = (s16) (this->entry_count + 1);
    }
}

}
