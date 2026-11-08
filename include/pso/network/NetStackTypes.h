/* Records shared by the network stack's session, buffer and socket files. */
#ifndef PSO_NETWORK_NETSTACKTYPES_H
#define PSO_NETWORK_NETSTACKTYPES_H
#include "types.h"

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
typedef struct p803FB184_Unk805BC238Entry {
    u8 pad0[8];
    u32 unk8;
    u32 unkC;
} p803FB184_Unk805BC238Entry;
typedef struct p803FB184_UnkHdr {
    u32 a;
    u16 b;
    u8 c;
} p803FB184_UnkHdr;

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
typedef struct p803FE518_Unk805BDDE0 {
    s16 unk0;
    struct {
        s16 unk0;
        s16 unk2;
    } unk2[2];
    s16 unkA;
    s16 unkC;
    s16* unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
} p803FE518_Unk805BDDE0;
typedef struct p803FE518_U7Obj p803FE518_U7Obj;
typedef struct p803FE518_U7Slot {
    p803FE518_U7Obj* obj;
    s16 used;
    s16 size;
    s16 cap;
    s16 pad;
    s32 data;
} p803FE518_U7Slot;
struct p803FE518_U7Obj {
    s16 pad0;
    s16 key;
    s32 pad4;
    p803FE518_U7Slot* slot;
};
typedef struct p803FE518_Unk805BDCD8Entry {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0xA];
} p803FE518_Unk805BDCD8Entry;
typedef struct p803FE518_Unk805BDCD8 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[4];
    p803FE518_Unk805BDCD8Entry* unkC;
} p803FE518_Unk805BDCD8;
typedef struct p803FE518_UnkNode8040A3C0 {
    s16 unk0;
    u32 unk4;
    u8 unk8[0x10];
    s16 unk18;
    u8 unk1a[2];
    s32 unk1c;
    struct p803FE518_UnkNode8040A3C0* next;
    void* unk24;
} p803FE518_UnkNode8040A3C0;
typedef struct p803FE518_Unk8040A3C0 {
    s16 unk0;
    u8 unk2[0x202];
    s16 unk204;
    p803FE518_UnkNode8040A3C0* unk208;
} p803FE518_Unk8040A3C0;
typedef struct p803FE518_Unk805BDCF0 {
    u8 unk0[0xc];
    s16* unkC;
    s16 unk10;
    u8 unk12[0x2];
    u8* unk14;
    s16 unk18;
    s16 unk1a;
    s16 unk1c;
    u8 unk1e[0x2];
    s32 unk20;
    s16 unk24;
    u8 unk26[0x2];
    u8* unk28;
    s16 unk2c;
    s16 unk2e;
    s16 unk30;
    u8 unk32[0x2];
    u8* unk34;
    p803FE518_Unk8040A3C0* unk38;
    u8* unk3c;
    s16 unk40;
    u8 unk42[0x2];
    u8* unk44;
} p803FE518_Unk805BDCF0;
typedef struct p803FE518_UnkArg8040B34C {
    s32 pad0;
    u32 type;
    u8 data[0x10];
} p803FE518_UnkArg8040B34C;
typedef struct p803FE518_Unk805D3D38 {
    s16 unk0;
    u8 pad2[2];
    u8* unk4;
} p803FE518_Unk805D3D38;
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
typedef struct {
    s16 countA;
    s16 countB;
    s16 countC;
    u16 pad6;
    Unk805BDD60Entry* entriesA;
    void* entriesB;
  } p8040B8B4_Unk805BDD60;
typedef struct p8040B8B4_Unk8040BEEnt {
    s16 a;
    u8 pad2[2];
    void* p;
    u32 pad8;
} p8040B8B4_Unk8040BEEnt;
typedef struct p8040B8B4_Unk8040BEBuf {
    u8 pad0[4];
    s32 count;
    s32 total;
    p8040B8B4_Unk8040BEEnt ents[8];
} p8040B8B4_Unk8040BEBuf;

typedef struct p8040EE4C_Unk805BDDB8 {
    s16 cnt0;
    s16 cnt2;
    s16 cnt4;
    u8 pad6[0xE];
    s16 cnt14;
    u8 pad16[2];
    void* p18;
    void* p1c;
    void* p20;
    void* p24;
} p8040EE4C_Unk805BDDB8;
typedef struct p8040EE4C_Unk805BDDE0 {
    s16 unk0;
    struct {
        s16 unk0;
        s16 unk2;
    } unk2[2];
    s16 unkA;
    s16 unkC;
    s16* unk10;
    u32 unk14;
} p8040EE4C_Unk805BDDE0;
typedef struct p8040EE4C_Unk805BDDF8 {
    s16 count;
    s16 step;
    u8* out;
    u32 cursor;
} p8040EE4C_Unk805BDDF8;
typedef void (*p8040EE4C_Unk8041900Cb)(void*, s32, s32, s32);
typedef struct p8040EE4C_Unk805BDE38Entry {
    u8 pad0[4];
    s16 flags;
    u8 pad6[2];
    u8 unk8[0x14];
    u32 unk1C;
    s16 unk20;
    u8 unk22;
    u8 unk23;
    u32 pad24;
    struct p8040EE4C_Unk805BDE38Entry* next;
    u32 unk2C;
    u32 unk30;
} p8040EE4C_Unk805BDE38Entry;
typedef struct {
    s16 count;
    u8 pad2[6];
    p8040EE4C_Unk805BDE38Entry* entries;
    u32 padC;
    p8040EE4C_Unk805BDE38Entry* head;
    p8040EE4C_Unk805BDE38Entry* tail;
} p8040EE4C_Unk805BDE38;

typedef struct p804210AC_Unk80427DD4 {
    u8 pad0[0x8];
    u8* p8;
    u8 pad1[0x2];
    s16 se;
    u8** p10;
    u8 pad3[0x4];
    s16* p18;
} p804210AC_Unk80427DD4;

#endif
