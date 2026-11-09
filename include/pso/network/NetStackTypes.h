/* Records shared by the network stack's session, buffer and socket files. */
#ifndef PSO_NETWORK_NETSTACKTYPES_H
#define PSO_NETWORK_NETSTACKTYPES_H
#include "types.h"
#include <stddef.h>

typedef struct p803FB184_Unk805BC510 {
    s16 unk0;
    struct {
        s16 unk0;
        s16 unk2;
    } unk2[2];
    u8 unkA[2];
    s16* unkC;
    u32 unk10;
    s16 unk14;
    s16 unk16;
} p803FB184_Unk805BC510;

typedef struct p803FE518_UnkBuf803FF344 {
    u8* data;
    u16 len;
} p803FE518_UnkBuf803FF344;
typedef struct p803FE518_UnkSrc803FE518 {
    u8 pad0[2];
    u16 w2;
    u32 w4;
    u16 h8;
    u8 pad_a[2];
    u32 wc;
    u8 pad10[4];
    u8 b14;
} p803FE518_UnkSrc803FE518;
#pragma push
#pragma cplusplus off
static inline s16 fn_8040B758_len(char* s)
{
    s16 len = 0;
    s32 n;

    while (len < 255) {
        s8 c = *s;

        s++;
        if (c == 0) {
            len--;
            break;
        }
        n = c;
        if (len + n + 1 <= 255) {
            s += c;
        } else {
            len = 255;
            break;
        }
        len = n + len;
        len++;
    }
    return len;
}
#pragma pop

typedef struct {
    u16 flags;
    u8 pad2[2];
    u32 f4;
    u32 f8;
    u32 fC;
    u16 f10;
    s16 f12;
} Unk805BDD60Entry;



/* A PPP connection record (TLobby_803FC178.c / TLobby_803FCF44.c). */
typedef struct Conn_804004DC {
    u8 state;
    u8 id;
    u8 pad2;
    u8 retries;
    u8 pad4[2];
    u8 f6;
    u8 pad7;
    s16 abort;
    u8 padA[2];
    u8 *sub;
    u8 timer[0x1C]; /* a lobby timer (TLobby__sub_80405298) */
    void *proto;
    void *opts;
} Conn_804004DC;
typedef char Conn_804004DC_size_check[sizeof(Conn_804004DC) == 0x34 ? 1 : -1];
typedef char Conn_804004DC_opts_check[(offsetof(Conn_804004DC, opts) == 0x30) ? 1 : -1];
/* CHAP state, in Conn_804004DC.opts of the CHAP connection. */
typedef struct PppChap {
    const char *name;
    const char *secret;
    const char *msg;
    s16 active;
    u8 id;
    u8 padF;
    u16 len;
} PppChap;
typedef char PppChap_size_check[sizeof(PppChap) == 0x14 ? 1 : -1];
typedef char PppChap_len_check[(offsetof(PppChap, len) == 0x10) ? 1 : -1];

/* lbl_805C02D0: the PPP authentication (CHAP/PAP) buffers and settings (TLobby_803FC178.c). */
typedef struct PppAuthState {
    s32 f0;
    u8 *p4;
    u8 *p8;
    u32 fC;
    u8 *p10;
    u32 f14;
    u8 *p18;
    u8 *p1C;
    char *p20;
    u8 pad24[4];
    s16 f28;
    u8 pad2A[0xC];
    u8 f36;
    u8 f37;
    u16 f38;
    u8 pad3A[6];
} PppAuthState;
typedef char PppAuthState_size_check[sizeof(PppAuthState) == 0x40 ? 1 : -1];
#ifdef __cplusplus
extern "C" {
#endif
extern PppAuthState lbl_805C02D0;
#ifdef __cplusplus
}
#endif

#endif
