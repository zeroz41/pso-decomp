/* MD5 (RFC 1321's MD5Transform and the PADDING table at 8047FE78), used by CHAP (a C library, built with
 * GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
/* This file's functions. */
void init_md5_state(void *self);
void MD5Transform(u32 *state, u8 *block);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

extern u8 lbl_8047FE78[];
#pragma push
#pragma opt_propagation off
extern void TLobby__sub_80401D2C(u8 *dst, u32 *self_m) {
  u8 buf[8];
  u32 x;
  u32 n;
  u32 *s = self_m;
  u32 *new_var;
  buf[0] = self_m[4];
  new_var = &self_m[5];
  buf[1] = self_m[4] >> 8;
  buf[2] = self_m[4] >> 16;
  buf[3] = self_m[4] >> 24;
  buf[4] = *new_var;
  buf[5] = (*new_var) >> 8;
  buf[6] = (*new_var) >> 16;
  buf[7] = (*new_var) >> 24;
  x = (self_m[4] >> 3) & 0x3f;
  n = (x < 0x38) ? (0x38 - x) : (0x78 - x);
  TLobby__sub_80401EB8((u8*)((u8 *) s), (u8*)((*(u8(*)[])&lbl_8047FE78)), (u32)(n));
  TLobby__sub_80401EB8((u8*)((u8 *) s), (u8*)(buf), (u32)(8));
  dst[0] = self_m[0];
  dst[1] = self_m[0] >> 8;
  dst[2] = self_m[0] >> 16;
  dst[3] = (0, self_m[0] >> 24);
  dst[4] = self_m[1];
  dst[5] = self_m[1] >> 8;
  dst[6] = self_m[1] >> 16;
  dst[7] = self_m[1] >> 24;
  dst[8] = self_m[2];
  dst[9] = self_m[2] >> 8;
  dst[10] = self_m[2] >> 16;
  dst[11] = self_m[2] >> 24;
  dst[12] = self_m[3];
  dst[13] = self_m[3] >> 8;
  dst[14] = self_m[3] >> 16;
  dst[15] = self_m[3] >> 24;
  NetMemset((void *)((u8 *) self_m), (int)(0), (int)(0x58));
}
#pragma pop

void TLobby__sub_80401EB8(u8* self_m, u8* src, u32 len)
{
    u32 sum;
    u32 lo;
    u32 bits;
    u32 avail;
    u32 idx;
    u32 i;

    lo = *(u32*)(self_m + 0x10);
    bits = len << 3;
    sum = lo + bits;
    idx = (lo >> 3) & 0x3f;
    *(u32*)(self_m + 0x10) = sum;
    if (sum < bits) {
        *(u32*)(self_m + 0x14) += 1;
    }
    avail = 0x40 - idx;
    *(u32*)(self_m + 0x14) += len >> 29;
    i = avail;
    if (len >= avail) {
        NetMemcpy((void *)(self_m + 0x18 + idx), (void *)(src), (int)(i));
        MD5Transform((u32*)(self_m), (u8*)(self_m + 0x18));
        for (; i + 0x3f < len; i += 0x40) {
            MD5Transform((u32*)(self_m), (u8*)(src + i));
        }
        idx = 0;
    } else {
        i = 0;
    }
    NetMemcpy((void *)(self_m + 0x18 + idx), (void *)(src + i), (int)(len - i));
}

void init_md5_state(void *self) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { s32 field_0; s32 field_4; s32 field_8; s32 field_C; s32 field_10; s32 field_14; } Fields_arg0;
    ((Fields_arg0*)arg0)->field_14 = 0;
    ((Fields_arg0*)arg0)->field_10 = 0;
    ((Fields_arg0*)arg0)->field_0 = 0x67452301;
    ((Fields_arg0*)arg0)->field_4 = 0xEFCDAB89;
    ((Fields_arg0*)arg0)->field_8 = 0x98BADCFE;
    ((Fields_arg0*)arg0)->field_C = 0x10325476;
}

#define S11_80401FE8 7
#define S12_80401FE8 12
#define S13_80401FE8 17
#define S14_80401FE8 22
#define S21_80401FE8 5
#define S22_80401FE8 9
#define S23_80401FE8 14
#define S24_80401FE8 20
#define S31_80401FE8 4
#define S32_80401FE8 11
#define S33_80401FE8 16
#define S34_80401FE8 23
#define S41_80401FE8 6
#define S42_80401FE8 10
#define S43_80401FE8 15
#define S44_80401FE8 21
#define F_80401FE8(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G_80401FE8(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H_80401FE8(x, y, z) ((x) ^ (y) ^ (z))
#define I_80401FE8(x, y, z) ((y) ^ ((x) | (~z)))
#define ROTATE_LEFT_80401FE8(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define FF_80401FE8(a, b, c, d, x, s, ac) { (a) += F_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define GG_80401FE8(a, b, c, d, x, s, ac) { (a) += G_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define HH_80401FE8(a, b, c, d, x, s, ac) { (a) += H_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define II_80401FE8(a, b, c, d, x, s, ac) { (a) += I_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
inline void Decode_80401FE8(u32 *output, u8 *input, u32 len) {
    u32 i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[i] = ((u32)input[j]) | (((u32)input[j + 1]) << 8) | (((u32)input[j + 2]) << 16) | (((u32)input[j + 3]) << 24);
    }
}
void MD5Transform(u32 *state, u8 *block) {
    u32 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
    Decode_80401FE8(x, block, 64);
    FF_80401FE8(a, b, c, d, x[0], S11_80401FE8, 0xd76aa478);
    FF_80401FE8(d, a, b, c, x[1], S12_80401FE8, 0xe8c7b756);
    FF_80401FE8(c, d, a, b, x[2], S13_80401FE8, 0x242070db);
    FF_80401FE8(b, c, d, a, x[3], S14_80401FE8, 0xc1bdceee);
    FF_80401FE8(a, b, c, d, x[4], S11_80401FE8, 0xf57c0faf);
    FF_80401FE8(d, a, b, c, x[5], S12_80401FE8, 0x4787c62a);
    FF_80401FE8(c, d, a, b, x[6], S13_80401FE8, 0xa8304613);
    FF_80401FE8(b, c, d, a, x[7], S14_80401FE8, 0xfd469501);
    FF_80401FE8(a, b, c, d, x[8], S11_80401FE8, 0x698098d8);
    FF_80401FE8(d, a, b, c, x[9], S12_80401FE8, 0x8b44f7af);
    FF_80401FE8(c, d, a, b, x[10], S13_80401FE8, 0xffff5bb1);
    FF_80401FE8(b, c, d, a, x[11], S14_80401FE8, 0x895cd7be);
    FF_80401FE8(a, b, c, d, x[12], S11_80401FE8, 0x6b901122);
    FF_80401FE8(d, a, b, c, x[13], S12_80401FE8, 0xfd987193);
    FF_80401FE8(c, d, a, b, x[14], S13_80401FE8, 0xa679438e);
    FF_80401FE8(b, c, d, a, x[15], S14_80401FE8, 0x49b40821);
    GG_80401FE8(a, b, c, d, x[1], S21_80401FE8, 0xf61e2562);
    GG_80401FE8(d, a, b, c, x[6], S22_80401FE8, 0xc040b340);
    GG_80401FE8(c, d, a, b, x[11], S23_80401FE8, 0x265e5a51);
    GG_80401FE8(b, c, d, a, x[0], S24_80401FE8, 0xe9b6c7aa);
    GG_80401FE8(a, b, c, d, x[5], S21_80401FE8, 0xd62f105d);
    GG_80401FE8(d, a, b, c, x[10], S22_80401FE8, 0x2441453);
    GG_80401FE8(c, d, a, b, x[15], S23_80401FE8, 0xd8a1e681);
    GG_80401FE8(b, c, d, a, x[4], S24_80401FE8, 0xe7d3fbc8);
    GG_80401FE8(a, b, c, d, x[9], S21_80401FE8, 0x21e1cde6);
    GG_80401FE8(d, a, b, c, x[14], S22_80401FE8, 0xc33707d6);
    GG_80401FE8(c, d, a, b, x[3], S23_80401FE8, 0xf4d50d87);
    GG_80401FE8(b, c, d, a, x[8], S24_80401FE8, 0x455a14ed);
    GG_80401FE8(a, b, c, d, x[13], S21_80401FE8, 0xa9e3e905);
    GG_80401FE8(d, a, b, c, x[2], S22_80401FE8, 0xfcefa3f8);
    GG_80401FE8(c, d, a, b, x[7], S23_80401FE8, 0x676f02d9);
    GG_80401FE8(b, c, d, a, x[12], S24_80401FE8, 0x8d2a4c8a);
    HH_80401FE8(a, b, c, d, x[5], S31_80401FE8, 0xfffa3942);
    HH_80401FE8(d, a, b, c, x[8], S32_80401FE8, 0x8771f681);
    HH_80401FE8(c, d, a, b, x[11], S33_80401FE8, 0x6d9d6122);
    HH_80401FE8(b, c, d, a, x[14], S34_80401FE8, 0xfde5380c);
    HH_80401FE8(a, b, c, d, x[1], S31_80401FE8, 0xa4beea44);
    HH_80401FE8(d, a, b, c, x[4], S32_80401FE8, 0x4bdecfa9);
    HH_80401FE8(c, d, a, b, x[7], S33_80401FE8, 0xf6bb4b60);
    HH_80401FE8(b, c, d, a, x[10], S34_80401FE8, 0xbebfbc70);
    HH_80401FE8(a, b, c, d, x[13], S31_80401FE8, 0x289b7ec6);
    HH_80401FE8(d, a, b, c, x[0], S32_80401FE8, 0xeaa127fa);
    HH_80401FE8(c, d, a, b, x[3], S33_80401FE8, 0xd4ef3085);
    HH_80401FE8(b, c, d, a, x[6], S34_80401FE8, 0x4881d05);
    HH_80401FE8(a, b, c, d, x[9], S31_80401FE8, 0xd9d4d039);
    HH_80401FE8(d, a, b, c, x[12], S32_80401FE8, 0xe6db99e5);
    HH_80401FE8(c, d, a, b, x[15], S33_80401FE8, 0x1fa27cf8);
    HH_80401FE8(b, c, d, a, x[2], S34_80401FE8, 0xc4ac5665);
    II_80401FE8(a, b, c, d, x[0], S41_80401FE8, 0xf4292244);
    II_80401FE8(d, a, b, c, x[7], S42_80401FE8, 0x432aff97);
    II_80401FE8(c, d, a, b, x[14], S43_80401FE8, 0xab9423a7);
    II_80401FE8(b, c, d, a, x[5], S44_80401FE8, 0xfc93a039);
    II_80401FE8(a, b, c, d, x[12], S41_80401FE8, 0x655b59c3);
    II_80401FE8(d, a, b, c, x[3], S42_80401FE8, 0x8f0ccc92);
    II_80401FE8(c, d, a, b, x[10], S43_80401FE8, 0xffeff47d);
    II_80401FE8(b, c, d, a, x[1], S44_80401FE8, 0x85845dd1);
    II_80401FE8(a, b, c, d, x[8], S41_80401FE8, 0x6fa87e4f);
    II_80401FE8(d, a, b, c, x[15], S42_80401FE8, 0xfe2ce6e0);
    II_80401FE8(c, d, a, b, x[6], S43_80401FE8, 0xa3014314);
    II_80401FE8(b, c, d, a, x[13], S44_80401FE8, 0x4e0811a1);
    II_80401FE8(a, b, c, d, x[4], S41_80401FE8, 0xf7537e82);
    II_80401FE8(d, a, b, c, x[11], S42_80401FE8, 0xbd3af235);
    II_80401FE8(c, d, a, b, x[2], S43_80401FE8, 0x2ad7d2bb);
    II_80401FE8(b, c, d, a, x[9], S44_80401FE8, 0xeb86d391);
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    NetMemset(x, 0, sizeof(x));
}
#pragma pop
