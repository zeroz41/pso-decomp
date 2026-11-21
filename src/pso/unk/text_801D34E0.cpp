#include "types.h"
#include "pso/unk/text_801D34E0.h"
extern "C" {
void *zero_object_vptr(void *);
s32 delete_object_if_delete_flag(s32 arg0, s16 arg1);
void *__register_global_object(void *, void *, void *);
u8 lbl_805D5DD8[8];
extern u8 lbl_80511DD8[];
void __sinit_text_801D34E0_cpp(void) {
    __register_global_object(zero_object_vptr(lbl_805D5DD8), (void *)delete_object_if_delete_flag, lbl_80511DD8);
}

u8 lbl_80511DD8[0xC];
u8 meet_user_settings[0x64] ATTRIBUTE_ALIGN(8);
u8 game_variations[0x84];
}

__declspec(section ".ctors") static void *const __sinit_text_801D34E0_cpp_ref = (void *)__sinit_text_801D34E0_cpp;
