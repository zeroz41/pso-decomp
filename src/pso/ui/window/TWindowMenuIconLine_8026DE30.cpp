#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {

s32 init_list_entry__20TWindowSubStatusDispFUcll(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0);

void TWindowMenuIconLine::add_list_entry(s32 arg1, s32 arg2, s32 arg3) {
    if (this->entry_count < this->entry_capacity) {
        init_list_entry__20TWindowSubStatusDispFUcll(reinterpret_cast<saddr>(get_array_entry(entry_count)), arg1, arg2, arg3);
        this->entry_count = (this->entry_count + 1);
    }
}

}
