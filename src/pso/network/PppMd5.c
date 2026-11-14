/* MD5 (RFC 1321's MD5Init, MD5Update, MD5Final and MD5Transform), used by CHAP (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include "pso/network/NetStackTypes.h"
#include "pso/network/PppMd5.h"

const u8 lbl_8047FE78[64] = {128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void TLobby__sub_80401D2C(u8 *dst, u32 *self_m) {
    u8 buf[8];
    u32 x;
    u32 n;
    MD5Context *ctx = (MD5Context *)self_m;
    u32 *high;
    buf[0] = ctx->count[0];
    high = &ctx->count[1];
    buf[1] = ctx->count[0] >> 8;
    buf[2] = ctx->count[0] >> 16;
    buf[3] = ctx->count[0] >> 24;
    buf[4] = *high;
    buf[5] = *high >> 8;
    buf[6] = *high >> 16;
    buf[7] = *high >> 24;
    x = (ctx->count[0] >> 3) & 0x3f;
    n = (x < 0x38) ? (0x38 - x) : (0x78 - x);
    TLobby__sub_80401EB8((u8 *)ctx, lbl_8047FE78, n);
    TLobby__sub_80401EB8((u8 *)ctx, buf, 8);
    dst[0] = ctx->state[0];
    dst[1] = ctx->state[0] >> 8;
    dst[2] = ctx->state[0] >> 16;
    dst[3] = ctx->state[0] >> 24;
    dst[4] = ctx->state[1];
    dst[5] = ctx->state[1] >> 8;
    dst[6] = ctx->state[1] >> 16;
    dst[7] = ctx->state[1] >> 24;
    dst[8] = ctx->state[2];
    dst[9] = ctx->state[2] >> 8;
    dst[10] = ctx->state[2] >> 16;
    dst[11] = ctx->state[2] >> 24;
    dst[12] = ctx->state[3];
    dst[13] = ctx->state[3] >> 8;
    dst[14] = ctx->state[3] >> 16;
    dst[15] = ctx->state[3] >> 24;
    NetMemset(ctx, 0, sizeof(MD5Context));
}

void TLobby__sub_80401EB8(u8 *self_m, u8 *src, u32 len)
{
    u32 sum;
    u32 lo;
    u32 bits;
    u32 avail;
    u32 idx;
    u32 i;

    lo = ((MD5Context *)self_m)->count[0];
    bits = len << 3;
    sum = lo + bits;
    idx = (lo >> 3) & 0x3f;
    ((MD5Context *)self_m)->count[0] = sum;
    if (sum < bits) {
        ((MD5Context *)self_m)->count[1] += 1;
    }
    avail = 0x40 - idx;
    ((MD5Context *)self_m)->count[1] += len >> 29;
    i = avail;
    if (len >= avail) {
        NetMemcpy(&((MD5Context *)self_m)->buffer[idx], src, i);
        MD5Transform(((MD5Context *)self_m)->state, ((MD5Context *)self_m)->buffer);
        for (; i + 0x3f < len; i += 0x40) {
            MD5Transform(((MD5Context *)self_m)->state, &src[i]);
        }
        idx = 0;
    } else {
        i = 0;
    }
    NetMemcpy(&((MD5Context *)self_m)->buffer[idx], &src[i], len - i);
}

void init_md5_state(void *self) {
    MD5Context *ctx = (MD5Context *)self;
    ctx->count[1] = 0;
    ctx->count[0] = 0;
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
}

#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define FF(a, b, c, d, x, s, ac) { (a) += F((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT((a), (s)); (a) += (b); }
#define GG(a, b, c, d, x, s, ac) { (a) += G((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT((a), (s)); (a) += (b); }
#define HH(a, b, c, d, x, s, ac) { (a) += H((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT((a), (s)); (a) += (b); }
#define II(a, b, c, d, x, s, ac) { (a) += I((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT((a), (s)); (a) += (b); }
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
inline void Decode(u32 *output, u8 *input, u32 len) {
    u32 i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[i] = ((u32)input[j]) | (((u32)input[j + 1]) << 8) | (((u32)input[j + 2]) << 16) | (((u32)input[j + 3]) << 24);
    }
}
void MD5Transform(u32 *state, u8 *block) {
    u32 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
    Decode(x, block, 64);
    FF(a, b, c, d, x[0], S11, 0xd76aa478);
    FF(d, a, b, c, x[1], S12, 0xe8c7b756);
    FF(c, d, a, b, x[2], S13, 0x242070db);
    FF(b, c, d, a, x[3], S14, 0xc1bdceee);
    FF(a, b, c, d, x[4], S11, 0xf57c0faf);
    FF(d, a, b, c, x[5], S12, 0x4787c62a);
    FF(c, d, a, b, x[6], S13, 0xa8304613);
    FF(b, c, d, a, x[7], S14, 0xfd469501);
    FF(a, b, c, d, x[8], S11, 0x698098d8);
    FF(d, a, b, c, x[9], S12, 0x8b44f7af);
    FF(c, d, a, b, x[10], S13, 0xffff5bb1);
    FF(b, c, d, a, x[11], S14, 0x895cd7be);
    FF(a, b, c, d, x[12], S11, 0x6b901122);
    FF(d, a, b, c, x[13], S12, 0xfd987193);
    FF(c, d, a, b, x[14], S13, 0xa679438e);
    FF(b, c, d, a, x[15], S14, 0x49b40821);
    GG(a, b, c, d, x[1], S21, 0xf61e2562);
    GG(d, a, b, c, x[6], S22, 0xc040b340);
    GG(c, d, a, b, x[11], S23, 0x265e5a51);
    GG(b, c, d, a, x[0], S24, 0xe9b6c7aa);
    GG(a, b, c, d, x[5], S21, 0xd62f105d);
    GG(d, a, b, c, x[10], S22, 0x2441453);
    GG(c, d, a, b, x[15], S23, 0xd8a1e681);
    GG(b, c, d, a, x[4], S24, 0xe7d3fbc8);
    GG(a, b, c, d, x[9], S21, 0x21e1cde6);
    GG(d, a, b, c, x[14], S22, 0xc33707d6);
    GG(c, d, a, b, x[3], S23, 0xf4d50d87);
    GG(b, c, d, a, x[8], S24, 0x455a14ed);
    GG(a, b, c, d, x[13], S21, 0xa9e3e905);
    GG(d, a, b, c, x[2], S22, 0xfcefa3f8);
    GG(c, d, a, b, x[7], S23, 0x676f02d9);
    GG(b, c, d, a, x[12], S24, 0x8d2a4c8a);
    HH(a, b, c, d, x[5], S31, 0xfffa3942);
    HH(d, a, b, c, x[8], S32, 0x8771f681);
    HH(c, d, a, b, x[11], S33, 0x6d9d6122);
    HH(b, c, d, a, x[14], S34, 0xfde5380c);
    HH(a, b, c, d, x[1], S31, 0xa4beea44);
    HH(d, a, b, c, x[4], S32, 0x4bdecfa9);
    HH(c, d, a, b, x[7], S33, 0xf6bb4b60);
    HH(b, c, d, a, x[10], S34, 0xbebfbc70);
    HH(a, b, c, d, x[13], S31, 0x289b7ec6);
    HH(d, a, b, c, x[0], S32, 0xeaa127fa);
    HH(c, d, a, b, x[3], S33, 0xd4ef3085);
    HH(b, c, d, a, x[6], S34, 0x4881d05);
    HH(a, b, c, d, x[9], S31, 0xd9d4d039);
    HH(d, a, b, c, x[12], S32, 0xe6db99e5);
    HH(c, d, a, b, x[15], S33, 0x1fa27cf8);
    HH(b, c, d, a, x[2], S34, 0xc4ac5665);
    II(a, b, c, d, x[0], S41, 0xf4292244);
    II(d, a, b, c, x[7], S42, 0x432aff97);
    II(c, d, a, b, x[14], S43, 0xab9423a7);
    II(b, c, d, a, x[5], S44, 0xfc93a039);
    II(a, b, c, d, x[12], S41, 0x655b59c3);
    II(d, a, b, c, x[3], S42, 0x8f0ccc92);
    II(c, d, a, b, x[10], S43, 0xffeff47d);
    II(b, c, d, a, x[1], S44, 0x85845dd1);
    II(a, b, c, d, x[8], S41, 0x6fa87e4f);
    II(d, a, b, c, x[15], S42, 0xfe2ce6e0);
    II(c, d, a, b, x[6], S43, 0xa3014314);
    II(b, c, d, a, x[13], S44, 0x4e0811a1);
    II(a, b, c, d, x[4], S41, 0xf7537e82);
    II(d, a, b, c, x[11], S42, 0xbd3af235);
    II(c, d, a, b, x[2], S43, 0x2ad7d2bb);
    II(b, c, d, a, x[9], S44, 0xeb86d391);
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    NetMemset(x, 0, sizeof(x));
}
#pragma pop
