#include "types.h"
struct Hdl_803C1668 {
    u8 pad0[2];
    s16 f2;
    u8 pad4[8];
    u8 fc;
    u8 fd;
    s8 fe;
    s8 ff;
    s32 f10;
    s32 f14;
    s32 f18;
    s16 f1c;
    u8 pad1e[2];
    s32 f20;
    s16 f24;
    s16 f26;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    u8 pad38[4];
    s32 f3c;
    s32 f40;
    s32 f44;
    s16 f48;
    s16 f4a;
    u8 f4c[0xC];
    s32 f58;
    s32 f5c;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6c;
    u8 pad70[0xC];
    s16 f7c;
    s16 f7e;
    u8 *f80;
    u8 pad84[0x14];
    s32 f98;
    s32 f9c;
    u8 padA0[8];
    s16 fa8;
    u8 faa[2];
};

extern "C" {
s32 TLobby__sub_803C1780(s32 buf, s32 len, s16 *data_offset, s8 *marker, s8 *bits, s8 *block_align, s8 *channels, s32 *sample_rate, s32 *sample_count, s32 *samples_per_block, s16 *encoding);
void *memset(void *, int, u32);
s16 DVDReadPrio(Hdl_803C1668 *h, s32 arg1, s32 arg2);
s16 DVDReadPrio(Hdl_803C1668 *h, s32 arg1, s32 arg2) {
    s16 n;
    h->f2 = 1;
    if (TLobby__sub_803C1780((s32)arg1, (s32)arg2, (s16 *)&n, (s8 *)&h->fc, (s8 *)&h->fd, (s8 *)&h->ff, (s8 *)&h->fe, (s32 *)&h->f14, (s32 *)&h->f18, (s32 *)&h->f10, (s16 *)h->faa) < 0) {
        return 0;
    }
    h->f1c = 0;
    h->f4a = 0;
    h->f48 = 0;
    h->f26 = 0;
    h->f24 = 0;
    h->f34 = 0;
    h->f30 = 0;
    h->f2c = 0;
    h->f28 = 0;
    h->f20 = 0;
    h->f58 = h->fe;
    h->f5c = h->ff;
    h->f60 = h->f10;
    h->f64 = h->f3c;
    h->f68 = h->f40;
    h->f6c = h->f44;
    h->f7c = h->f48;
    h->f7e = h->f4a;
    h->f80 = h->f4c;
    h->f9c = 0;
    h->f98 = 0;
    h->fa8 = 1;
    memset(h->f4c, 0, 4);
    return n;
}

}
