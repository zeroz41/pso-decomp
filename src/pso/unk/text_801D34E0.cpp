#include "types.h"
#include "pso/unk/text_801D34E0.h"
extern "C" {
void *TObjMapWarp__sub_80141CA4(void *);
s32 delete_object_if_delete_flag(s32 arg0, s16 del);
void *__register_global_object(void *, void *, void *);
u8 lbl_805D5DD8[8];
extern u8 lbl_80511DD8[];
void __sinit_text_801D34E0_cpp(void) {
    __register_global_object(TObjMapWarp__sub_80141CA4(lbl_805D5DD8), (void *)delete_object_if_delete_flag, lbl_80511DD8);
}

u8 lbl_80511DD8[0xC];
}

__declspec(section ".ctors") static void *const __sinit_text_801D34E0_cpp_ref = (void *)__sinit_text_801D34E0_cpp;
