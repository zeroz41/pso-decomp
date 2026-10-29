#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/misc/TOVS2Wall01.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_4C { u8 bytes[0x4c]; };

struct RecoveredGlobal_8017BC10_lbl_8044311C {
    s32 value;
    u8 remaining[0x48];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(int, void *);
s32 get_bml_model(int, void *);
u32 __nw__7TObjectFUl(int);
extern s32 TOVS2Wall01__bml_resource;
extern RecoveredGlobal_8017BC10_lbl_8044311C vs2_wall_debris_desc;
extern s32 tl_05;
s32 init__11TOVS2Wall01Fi();

void TOVS2Wall01::vfunc_6(s16 *arg1, s32 arg2) {
    s32 temp_r0;

    if (arg1 != NULL) {
        this->mode = (s16) *arg1;
    }
    temp_r0 = this->mode;
    if (temp_r0 != 1) {
        if ((temp_r0 >= 1) || (temp_r0 < 0)) {
            this->mode = 0;
        }
    } else {
        this->m_33c = 0;
        if (arg2 != 0) {
            init__11TOVS2Wall01Fi();
        }
    }
}
typedef char RecoveredGlobal_8017BC10_lbl_8044311C_size[sizeof(RecoveredGlobal_8017BC10_lbl_8044311C) == 0x4C ? 1 : -1];
void TOVS2Wall01::spawn_debris(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    struct CopyStack_8017BC10 { u8 bytes[0x4C]; };
    CopyStack_8017BC10 copy_storage_8017BC10;
    u8 *chip;
    *(ByteBlock_4C *)(copy_storage_8017BC10.bytes) = *(const ByteBlock_4C *)((s32) ((u8 *)((void *)((u8 *)&vs2_wall_debris_desc.value + -4))) + 4);
    (*(f32 *)(copy_storage_8017BC10.bytes + 0xC)) = this->m_2fc;
    (*(f32 *)(copy_storage_8017BC10.bytes + 0x10)) = this->m_300;
    (*(f32 *)(copy_storage_8017BC10.bytes + 0x14)) = this->m_304;
    (*(f32 *)(copy_storage_8017BC10.bytes + 0x38)) = *(f32 *)((s8 *)arg0 + 0x3C);
    (*(s32 *)(copy_storage_8017BC10.bytes + 0x40)) = get_bml_model((int)TOVS2Wall01__bml_resource, (void *)arg1);
    (*(s32 *)(copy_storage_8017BC10.bytes + 0x44)) = TObjFish__sub_8001EDB0((int)TOVS2Wall01__bml_resource, (void *)arg1);
    chip = (u8 *) __nw__7TObjectFUl(0x234);
    if (chip != NULL) {
        __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)chip, (u8 *)tl_05, (u8 *)((copy_storage_8017BC10.bytes)));
    }
}

}
