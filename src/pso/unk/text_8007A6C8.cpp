#include "types.h"
#include "pso/unk/text_8007A6C8.h"
#include "pso/map/TObjMapCsn.h"
extern "C" {
void __construct_array(void *, void *, s32, s32, s32);
extern u8 TObjPlayer__sub_8007A7B8[];
u8 lbl_804FF9C0[0x380];
u8 lbl_804FFD40[0x400];
__declspec(section ".data") u8 lbl_80500140[8];
u8 csn_query_map_object[0x10];
void __sinit_text_8007A6C8_cpp(void) {
    __construct_array(lbl_804FF9C0, TObjPlayer__sub_8007A7B8, 0, 0x1C, 0x20);
    TObjMapCsn::init_and_return((s32)lbl_80500140);
    ((TObjMapCsn *)csn_query_map_object)->init();
}

}

__declspec(section ".ctors") static void *const __sinit_text_8007A6C8_cpp_ref = (void *)__sinit_text_8007A6C8_cpp;
