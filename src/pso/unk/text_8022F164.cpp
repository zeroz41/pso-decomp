#include "types.h"
#include "pso/unk/text_8022F164.h"

extern "C" {
s32 __construct_array(void *, void *, int, int, int);
extern s32 fn_8022F258[];
u8 lbl_80515F90[0x2C];
s32 lbl_80515FBC[0x30];
s32 lbl_8051607C[0x30];
void fn_8022F164(void) {
    __construct_array(lbl_80515FBC, fn_8022F258, 0, 0x30, 4);
    __construct_array(lbl_8051607C, fn_8022F258, 0, 0x30, 4);
}

}

__declspec(section ".ctors") static void *const __sinit_text_8022F164_cpp_ref = (void *)fn_8022F164;
