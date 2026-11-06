#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80077788.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_28 { u8 bytes[0x28]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct S_80077840 { u32 key; s32 val; };

struct S_80077814 { u32 key; s32 val; };

struct S_80077798 { s32 a; s32 b; };

struct D_80077798 { s16 a; s16 b; };

struct DO_80077798 { u8 pad[4]; D_80077798 e[5]; };

struct S_80077980 { s32 key; s32 val; };

struct Ent_800777C4 { u16 a; u16 b; u8 pad[0x1C]; };

struct Tbl_800777C4 { u8 f0; u8 count; u8 pad[2]; Ent_800777C4 e[1]; };

struct Out_800778B4 { s32 a; s32 b; };

extern "C" {
extern s32 lbl_805D4E5C;
extern s32 lbl_805D4E58;
void set_value_by_key(S_80077814 *arr, u16 key, s32 val);
void TLobby__sub_80077798(S_80077798 *src, DO_80077798 *dst);
void TWindowSubComCard__sub_80077980(S_80077980 *arr);
u32 find_table_entry_id(Tbl_800777C4 *t, u16 a, u32 b);
void TWindowSubComCard__sub_800778B4(Out_800778B4 *arg0, Tbl_800777C4 *arg1);

int fn_80077788(void) { return 0; }
int fn_80077790(void) { return 0; }

void TLobby__sub_80077798(S_80077798 *src, DO_80077798 *dst) {
    s32 i;
    D_80077798 *d = dst->e;
    for (i = 0; i < 5; i++) {
        d->a = src->a;
        d->b = src->b;
        src++;
        d++;
    }
}

u32 find_table_entry_id(Tbl_800777C4 *t, u16 a, u32 b) {
    s32 i;
    Ent_800777C4 *e;
    if (b == 0) {
        return 0;
    }
    e = t->e;
    for (i = 0; i < t->count; i++) {
        if (e->a == a && e->b == b) {
            return e->b;
        }
        e++;
    }
    return 0;
}

void set_value_by_key(S_80077814 *arr, u16 key, s32 val) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (arr->key == key) {
            arr->val = val;
            return;
        }
        arr++;
    }
}

s32 TWindowSubComCard::find_value_by_key(u16 key) {
    S_80077840 *arr = (S_80077840 *)this;
    s32 i;
    for (i = 0; i < 5; i++) {
        if (arr->key == key) {
            return arr->val;
        }
        arr++;
    }
    return 0;
}

s32 TWindowSubComCard::get_com_count() {
    return lbl_805D4E5C;
}
void TWindowSubComCard::release() {
    if ((u32) (*(u32 *)&lbl_805D4E5C) != 0U) {
        ::operator delete((void *)(*(u32 *)&lbl_805D4E5C));
        (*(u32 *)&lbl_805D4E5C) = 0U;
    }
}
s32 TWindowSubComCard::get_chr_select() {
    return lbl_805D4E58;
}

void TWindowSubComCard__sub_800778B4(Out_800778B4 *arr, Tbl_800777C4 *arg1) {
    s32 i;
    s32 n;
    u16 id;
    u32 k;
    Out_800778B4 *dst;
    Ent_800777C4 *e;
    S_80077840 tmp[5];
    copy_struct28__17TWindowSubComCardFii((s32) tmp, (s32) arr);
    TWindowSubComCard__sub_80077980((S_80077980 *) arr);
    n = arg1->count;
    dst = arr;
    e = arg1->e;
    i = 0;
    while (i < n) {
        if (e->a == 0) {
            id = dst->a = e->b;
            k = ((TWindowSubComCard *)tmp)->find_value_by_key(id);
            dst->b = (u16) find_table_entry_id(arg1, id, k);
            dst++;
        }
        i++;
        e++;
    }
}

u8 * copy_struct28__17TWindowSubComCardFii(s32 arg0, s32 arg1) {
    *(ByteBlock_28 *)(arg0) = *(const ByteBlock_28 *)(arg1);
    return (u8 *)arg0;
}
void TWindowSubComCard__sub_80077980(S_80077980 *arr) {
    s32 i;
    for (i = 0; i < 5; i++) {
        arr->key = 0;
        arr->val = 0;
        arr++;
    }
}

}
