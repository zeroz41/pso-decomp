#include "types.h"
#include "versions.h"

#if VERSION == VERSION_GPOP8P

// The European build carries its own PRS decompressors, built with the older compiler.
#define PRS_NEXT_BIT(flag)                  \
    if (--count == 0) {                     \
        bits = *src++;                      \
        count = 8;                          \
    }                                       \
    flag = bits & 1;                        \
    bits >>= 1;

#pragma push
#pragma opt_lifetimes off

extern "C" {

u32 prs_decompress_alloc(u8 *in, void *out, u32 max) {
    u8 *dst;
    u32 len;
    s32 i;
    u8 *base;
    u32 bit;
    u8 *start;
    u32 bits;
    u8 *ref;
    u8 *src;
    u32 literal;
    s32 count;
    u32 long_copy;

    dst = (u8 *)out;
    count = 9;
    src = in;
    bits = *src++;
    start = dst;
    base = dst;
    for (;;) {
        do {
            PRS_NEXT_BIT(literal);
            if (literal == 1) {
                if ((u32)(dst - base) < max) {
                    *dst++ = *src++;
                } else {
                    return 0;
                }
            }
        } while (literal == 1);
        PRS_NEXT_BIT(long_copy);
        if (long_copy == 1) {
            u32 lo = *src++;
            u32 off = lo | (*src++ << 8);
            if (off == 0) {
                return dst - start;
            }
            len = lo & 7;
            ref = (u8 *)((off >> 3) | 0xFFFFE000);
            if (len == 0) {
                len = *src++ + 1;
            } else {
                len += 2;
            }
            ref = (u8 *)((u32)ref + (u32)dst);
        } else {
            len = 0;
            for (i = 0; i < 2; i++) {
                PRS_NEXT_BIT(bit);
                len = (len << 1) | bit;
            }
            len += 2;
            ref = (u8 *)((*src++ | 0xFFFFFF00) + (u32)dst);
        }
        while (len != 0) {
            if ((u32)(dst - base) < max) {
                *dst++ = *ref;
            } else {
                return 0;
            }
            ref++;
            len--;
        }
    }
}

u32 prs_decompress_buffer(u8 *in, void *out) {
    u8 *dst;
    u32 len;
    u32 literal;
    u32 long_copy;
    u32 bit;
    u8 *start;
    u8 *src;
    u32 bits;
    s32 i;
    u8 *ref;
    s32 count;

    dst = (u8 *)out;
    count = 9;
    src = in;
    bits = *src++;
    start = dst;
    for (;;) {
        do {
            PRS_NEXT_BIT(literal);
            if (literal == 1) {
                *dst++ = *src++;
            }
        } while (literal == 1);
        PRS_NEXT_BIT(long_copy);
        if (long_copy == 1) {
            u32 lo = *src++;
            u32 off = lo | (*src++ << 8);
            if (off == 0) {
                return dst - start;
            }
            len = lo & 7;
            ref = (u8 *)((off >> 3) | 0xFFFFE000);
            if (len == 0) {
                len = *src++ + 1;
            } else {
                len += 2;
            }
            ref = (u8 *)((u32)ref + (u32)dst);
        } else {
            len = 0;
            for (i = 0; i < 2; i++) {
                PRS_NEXT_BIT(bit);
                len = (len << 1) | bit;
            }
            len += 2;
            ref = (u8 *)((*src++ | 0xFFFFFF00) + (u32)dst);
        }
        while (len != 0) {
            *dst++ = *ref;
            ref++;
            len--;
        }
    }
}

}

#pragma pop

#else

#include "pso/unk/text_800F7D30.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
u32 prs_decompress(int, int, int, int);
u32 reset_counters__6TLobbyFv();
#pragma scheduling off
u32 prs_decompress_alloc(s32 arg0, s32 arg1) {
  s32 var_r28;
  s32 var_r29;
  s32 src;
  s32 var_r5;
  s32 var_r6;
  u32 var_r30;
  u32 var_r31;
  u32 var_r3;
  u32 phi_r30;
  s32 saved_reg_r30;
  var_r30 = saved_reg_r30;
  var_r28 = arg0;
  var_r29 = arg1;
  var_r3 = 0x30U;
  var_r31 = (int)::operator new(0x30);
  phi_r30 = saved_reg_r30;
  if (var_r31 != 0U)
  {
    var_r31 = reset_counters__6TLobbyFv();
  }
  if (var_r31 != 0U)
  {
    var_r3 = var_r31;
    src = var_r29;
    var_r5 = var_r28;
    var_r6 = 0;
    phi_r30 = (prs_decompress((int) var_r3, (int) src, (int) var_r5, 0));
  }
  if (var_r31 != 0U)
  {
    var_r3 = var_r31;
    src = 1;
    TLobby::destroy_ep3_exist((int) var_r3, 1);
  }
  var_r3 = phi_r30;
  return var_r3;
}

}

#endif
