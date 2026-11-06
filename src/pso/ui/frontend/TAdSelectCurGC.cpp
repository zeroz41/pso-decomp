#include "types.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"

extern "C" {

s32 TRaderMapCore__sub_801A6D00();

u8 TAdSelectCurGC::check_flag_0x48() {
    return (u8) ((*(s32 *)((s8 *)this + 0x48) & TRaderMapCore__sub_801A6D00()) != 0);
}

}
