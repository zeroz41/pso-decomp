#include "types.h"
#include "pso/object/TObjTombstone_800762F0.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/object/TObjTombstone.h"
struct Stack_8007643C {
    u8 sp8;
    u8 sp9;
    u8 spA;
    u8 pad_B[0xD];
    s32 sp18;
    u8 trailing_storage[0x3C];
};

struct RecoveredGlobal_8007643C___vt__13TObjTombstone { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_8007643C___vt__13TObjTombstone_size[sizeof(RecoveredGlobal_8007643C___vt__13TObjTombstone) == 0x38 ? 1 : -1];

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct C_80076390 { u32 w[2]; };

struct In_80076390 { u32 w[5]; };

struct B_80076390 { u32 a; In_80076390 b; };

struct E_80076390 { u32 w[8]; };

struct T_80076390 {
    u8 b0, b1, b2, b3;
    s16 h4, h6;
    s32 i8, iC;
    C_80076390 c10;
    B_80076390 s18;
    E_80076390 s30;
};

extern "C" {
s32 __ct__13TUnk_804AF8A0FP7TObject();
extern RecoveredGlobal_8007643C___vt__13TObjTombstone __vt__13TObjTombstone;
extern const char* TObjTombstone__class_name;
extern s32 TObjTombstone__shared_resource_object;
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 fn_80074E04(s32, void *);

extern const f32 TObjTombstone__data_805D9174;

void TObjTombstone::setup(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    this->texlist = TObjFish__sub_8001EDB0(TObjTombstone__shared_resource_object, 0);
    *(s32 *)&this->model = get_bml_model(TObjTombstone__shared_resource_object, 0);
    *(s32 *)&this->unk_AC = arg1;
    TObjTombstone::copy_record(arg0 + 0xC0, arg2);
    VecCopy((Vec *)&this->position, (const Vec *)(arg0 + 0xD0));
    this->rotation_y = (s32) (*(s32 *)&this->unk_AC << 0xD);
    this->m_b0 = (f32) TObjTombstone__data_805D9174;
    *(f32 *)&this->unk_B4 = (f32) TObjTombstone__data_805D9174;
    this->m_b8 = (f32) TObjTombstone__data_805D9174;
    *(f32 *)((s8 *)arg0 + 0xBC) = (f32) TObjTombstone__data_805D9174;
    this->m_230 = 0;
    fn_80074E04(*(s32 *)&this->unk_AC, (u8 *)&this->position);
}

#define dst ((T_80076390 *)arg0)
#define src ((T_80076390 *)arg1)
s32 TObjTombstone::copy_record(void *arg0, s32 arg1) {
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    dst->b3 = src->b3;
    dst->h4 = src->h4;
    dst->h6 = src->h6;
    dst->i8 = src->i8;
    dst->iC = src->iC;
    dst->c10 = src->c10;
    dst->s18 = src->s18;
    dst->s30 = src->s30;
    return (s32)dst;
}
#undef dst
#undef src

u8 *TObjTombstone__ct(TObjTombstone *tombstone, s32 arg1, s32 arg2, u8 *arg3) {
    typedef char sp8_offset[(offsetof(Stack_8007643C, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_8007643C, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_8007643C, spA) == 0x2) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8007643C, sp18) == 0x10) ? 1 : -1];
    Stack_8007643C stack;
    __ct__13TUnk_804AF8A0FP7TObject();
    *(s32 **)((s8 *)tombstone + 0x18) = &__vt__13TObjTombstone.value;
    *(s32 *)((s8 *)tombstone + 0) = (s32) TObjTombstone__class_name;
    if ((u32) (*(u32 *)&TObjTombstone__shared_resource_object) == 0U) {
        return (u8 *)tombstone;
    }
    stack.sp8 = *(u8 *)((s8 *)arg3 + 0);
    stack.sp9 = *(u8 *)((s8 *)arg3 + 1);
    stack.spA = *(u8 *)((s8 *)arg3 + 2);
    VecCopy((Vec *)(&stack.sp18), (const Vec *)(arg3 + 4));
    tombstone->setup(arg2, (s32)&stack.sp8);
    tombstone->reset_entries_and_format_name();
    tombstone->m_234 = 0;
    return (u8 *)tombstone;
}

}
