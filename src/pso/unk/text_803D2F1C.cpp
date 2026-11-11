#include "types.h"
#include "pso/unk/text_803D2F1C.h"

struct ByteBlock_8 { u8 bytes[0x8]; };

typedef struct Buf_803D2F1C { u8 *data; s32 size; } Buf_803D2F1C;

extern "C" {
int strncmp(const char *, const char *, u32);
u32 lbl_804F9E60[112] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
    0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
u8 *find_archive_entry__6TLobbyFPvPvPvPv(Buf_803D2F1C *arc, const char *name, const char *stop, Buf_803D2F1C *out);

#define HEX_803D2F1C(p, i) lbl_804F9E60[(s8)(p)[i]]
#define SIZE_803D2F1C(p) ((((((((((((HEX_803D2F1C(p, 8) << 4) + HEX_803D2F1C(p, 9)) << 4) + HEX_803D2F1C(p, 10)) << 4) + HEX_803D2F1C(p, 11)) << 4) + HEX_803D2F1C(p, 12)) << 4) + HEX_803D2F1C(p, 13)) << 4) + HEX_803D2F1C(p, 14))
inline s32 size_803D2F1C(u8 *p) {
    s32 v = HEX_803D2F1C(p, 8);
    v = (v << 4) + HEX_803D2F1C(p, 9);
    v = (v << 4) + HEX_803D2F1C(p, 10);
    v = (v << 4) + HEX_803D2F1C(p, 11);
    v = (v << 4) + HEX_803D2F1C(p, 12);
    v = (v << 4) + HEX_803D2F1C(p, 13);
    v = (v << 4) + HEX_803D2F1C(p, 14);
    return v;
}
u8 *find_archive_entry__6TLobbyFPvPvPvPv(Buf_803D2F1C *arc, const char *name, const char *stop, Buf_803D2F1C *out) {
    u8 *p;
    u8 *end;
    out->data = NULL;
    out->size = 0;
    p = arc->data;
    end = arc->data + arc->size;
    while (p < end) {
        if (strncmp((char *)p, name, 7) == 0) {
            out->data = p + 0x10;
            out->size = size_803D2F1C(p);
            break;
        }
        if (stop != NULL && strncmp((char *)p, stop, 7) == 0) {
            return NULL;
        }
        p += size_803D2F1C(p) + 0x10;
    }
    if (p < end) {
        return p;
    }
    return NULL;
}

#pragma push
#pragma scheduling off
void TLobby__sub_803D3130(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    *(ByteBlock_8 *)(arg2) = *(const ByteBlock_8 *)(arg0);
    *(s32 *)((s8 *)arg3 + 4) = (s32) *(s32 *)((s8 *)arg2 + 4);
    if ((s32) *(s32 *)((s8 *)arg2 + 4) > arg1) {
        *(s32 *)((s8 *)arg2 + 4) = arg1;
    }
    *(s32 *)((s8 *)arg3 + 4) = (s32) (*(s32 *)((s8 *)arg3 + 4) - *(s32 *)((s8 *)arg2 + 4));
    if ((s32) *(s32 *)((s8 *)arg3 + 4) == 0) {
        *(s32 *)((s8 *)arg3 + 0) = 0;
        return;
    }
    *(s32 *)((s8 *)arg3 + 0) = (s32) (*(s32 *)((s8 *)arg2 + 0) + *(s32 *)((s8 *)arg2 + 4));
}
#pragma pop

}
