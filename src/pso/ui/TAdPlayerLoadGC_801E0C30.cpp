#include "types.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/system/date.h"
#include "pso/system/memory.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_801E14E8_TAdPlayerLoadGC__data_80511ED0 {
    s32 value;
    u8 remaining[0x14];
};

struct Names_801E13C4 { const char* p[6]; };

struct DateStamp_801E17F4 { u8 b[0xc]; };

struct Src_801E17F4 {
    u8 pad0[0x12];
    char name[0x32];
    u8 *a;
    u8 *b;
    u8 pad4c[0x8];
    u16 flag;
    u8 pad56[0x2];
    u8 *data;
    s32 size;
};

struct Hdr_801E17F4 {
    char title[0x20];
    char sub[0x20];
    u8 a[0x1800];
    u8 b[0x800];
    s32 size;
    s32 crc;
};

struct CARDStat_801E2048 {
    char fileName[0x20];
    u32 length;
    u32 time;
    u8 gameName[4];
    u8 company[2];
    u8 bannerFormat;
    u8 pad2f;
    u32 iconAddr;
    u16 iconFormat;
    u16 iconSpeed;
    u32 commentAddr;
    u8 rest[0x30];
};

struct CARDFileInfo_801E15A4 { s32 chan; s32 fileNo; s32 offset; s32 length; u16 iBlock; u16 pad; };

struct Date_801E21A8 { u16 year; u8 mon; u8 mday; u8 hour; u8 min; u8 sec; u8 pad; u8 pad8[4]; };

struct Info_801E21A8 { u32 length; s16 blocks; u8 f6; u8 f7; s16 f8; u16 year; u8 mon; u8 mday; u8 hour; u8 min; u8 sec; u8 pad; };

extern "C" {
extern s32 TAdPlayerLoadGC__card_result_code;
s32 TAdPlayerLoadGC__sub_801E101C(s32);
s32 CARDProbeEx(s32, s32 *, s32 *);
extern u32 TAdPlayerLoadGC__card_slot_state_flags;
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 CARDCheck(s32);
s32 CARDFreeBlocks(s32, s32 *, s32 *);
s32 CARDDelete();
s32 CARDCheckAsync(void *, int);
extern RecoveredGlobal_801E14E8_TAdPlayerLoadGC__data_80511ED0 TAdPlayerLoadGC__banner_buffers;
extern s32 TAdPlayerLoadGC__banner_file_buf;
s32 CARDGetResultCode(void *);
s32 CARDUnmount();
s32 read_disc_file(const char*, void*);
extern Names_801E13C4 memory_card_banner_filenames;
extern char lbl_804496A8[];
s32 TAdSinglePlyChrSelectGC__sub_80201204(void *, s32, s32);
int sprintf(char *, const char *, ...);
char *strncpy(char *, const char *, u32);
void *memcpy(void *, const void *, u32);
void *memset(void *, int, u32);
extern char lbl_804496B8[];
extern char lbl_805DC410[4];
extern char lbl_805DC414[4];
s32 build_save_file_image__15TAdPlayerLoadGCFPvPv(u8 *arg0, Src_801E17F4 *arg1);
s32 CARDGetStatus(s32, s32, CARDStat_801E2048 *);
int strncmp(const char *, const char *, u32);
void fn_801E283C(u32, Date_801E21A8 *);
int strcmp(const char *s1, const char *s2);
s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(s32 chan, const char *name, Info_801E21A8 *info);
s32 CARDGetSerialNo();
s32 CARDFormatAsync(s32 chan, void *callback);
void CARDInit(void);
extern s32 lbl_805D5E34;
extern u8 *lbl_80511F68[];
s32 CARDMountAsync(s32 chan, void *workArea, void (*detachCallback)(s32), void (*attachCallback)(s32));
s32 CARDGetSectorSize(s32 chan, u32 *size);
s32 CARDSetStatus(s32 chan, s32 fileNo, CARDStat_801E2048 *stat);
s32 CARDClose(CARDFileInfo_801E15A4 *fileInfo);
s32 CARDOpen(s32 chan, const char *fileName, CARDFileInfo_801E15A4 *fileInfo);
s32 CARDReadAsync(CARDFileInfo_801E15A4 *fileInfo, void *addr, s32 length, s32 offset, void (*callback)(s32, s32));
s32 CARDSetAttributes(s32 chan, s32 fileNo, u8 attr);
s32 CARDWriteAsync(CARDFileInfo_801E15A4 *fileInfo, const void *addr, s32 length, s32 offset, void (*callback)(s32, s32));
s32 TAdPlayerLoadGC__sub_801E26DC(s32 chan, const char *name, void *buf, u32 size);
extern CARDFileInfo_801E15A4 TAdPlayerLoadGC__data_80511EE8;
extern CARDStat_801E2048 lbl_80511EFC;
extern s32 lbl_805D5E3C;

void TAdPlayerLoadGC::reset_load_state(void *arg0, void *arg1) {
    *(s32 *)((s8 *)arg1 + 4) = 0;
    *(s32 *)((s8 *)arg1 + 0) = 0;
    CARDGetSerialNo();
}

void TAdPlayerLoadGC::poll_card_load(s32 arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r3;

    TAdPlayerLoadGC__card_slot_state_flags &= ~(0x400 << arg0);
    do {
        temp_r3 = CARDProbeEx(arg0, &spC, &sp8);
    } while (temp_r3 == -1);
    if (sp8 == 0x2000) {
        if ((temp_r3 == -3) || (temp_r3 == -2)) {
            TAdPlayerLoadGC__card_result_code = -0x7D;
            return;
        }
        TAdPlayerLoadGC__sub_801E101C(arg0);
    }
}

s32 TAdPlayerLoadGC::check_card_result_code() {
    s32 arg0 = (s32)this;
    if (arg0 >= 2) {
        return 0;
    }
    switch (CARDGetResultCode((void *)arg0)) {
    case -0x80:
    case -0xE:
    case -4:
    case -1:
    case 0:
        TAdPlayerLoadGC__card_result_code = 0;
        return 1;
    case -5:
    case -3:
    case -0xB:
    case -0xA:
        TAdPlayerLoadGC__card_result_code = -0x7D;
        return 0;
    default:
        return 1;
    }
}

#pragma push
#pragma fp_contract on
s32 TAdPlayerLoadGC::probe_and_check_card() {
    s32 arg0 = (s32)this;
    s32 spC;
    s32 sp8;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 var_r0;
    if ((TAdPlayerLoadGC__card_slot_state_flags & (0x400 << arg0)) && ((temp_r3 = CARDGetResultCode((void *)arg0), ((temp_r3 == -5) != 0)) || (temp_r3 == -2))) {
        var_r0 = -0x7F;
        if (temp_r3 == -2) {
            var_r0 = -0x7D;
        }
        TAdPlayerLoadGC__card_result_code = var_r0;
        return 0;
    }
    do {
        temp_r3_2 = CARDProbeEx(arg0, &spC, &sp8);
    } while (temp_r3_2 == -1);
    if (temp_r3_2 == -2) {
        TAdPlayerLoadGC__card_result_code = -0x7D;
        return 0;
    }
    if (sp8 == 0x2000) {
        if (!(TAdPlayerLoadGC__card_slot_state_flags & (4 << arg0))) {
            TAdPlayerLoadGC__sub_801E101C(arg0);
            if ((u32) TAdPlayerLoadGC::get_load_result((void *)arg0) == -0x7FU) {
                TAdPlayerLoadGC__card_result_code = -0x7F;
                return 0;
            }
        }
        temp_r3_3 = CARDCheckAsync((void *)arg0, 0);
        if (temp_r3_3 == 0) {
            for (;;) {
                temp_r3_4 = CARDGetResultCode((void *)arg0);
                if (temp_r3_4 == -1) {
                    continue;
                }
                switch (temp_r3_4) {
                case -3:
                    TAdPlayerLoadGC__card_result_code = -0xFF;
                    return 0;
                case -5:
                case -128:
                    TAdPlayerLoadGC__card_result_code = -0x7F;
                    return 0;
                case 0:
                    return 1;
                case -13:
                case -6:
                    TAdPlayerLoadGC__card_result_code = -0xFD;
                    return 1;
                }
            }
        } else {
            switch (temp_r3_3) {
            case -5:
            case -128:
                TAdPlayerLoadGC__card_result_code = -0x7D;
                return 0;
            case -3:
                TAdPlayerLoadGC__card_result_code = -0xFF;
                return 0;
            case 0:
                return 1;
            case -13:
            case -6:
                TAdPlayerLoadGC__card_result_code = -0xFD;
                return 1;
            }
        }
    }
    TAdPlayerLoadGC__card_result_code = -0xDF;
    return 0;
}
#pragma pop

s32 TAdPlayerLoadGC__sub_801E0FA4(s32 chan) {
    s32 freeBytes;
    s32 freeFiles;
    if (chan >= 2) {
        return -0xFB;
    }
    switch (CARDFreeBlocks(chan, &freeBytes, &freeFiles)) {
    case -3:
    case -1:
    case -6:
    case -128:
        break;
    case 0:
        return freeFiles;
    }
    return 0;
}

s32 TAdPlayerLoadGC__sub_801E101C(s32 chan) {
    s32 memSize;
    s32 sectorSize;
    s32 result;
    s32 mounting;
    u8 *workArea;
    sectorSize = 0;
    memSize = 0;
    do {
        result = CARDProbeEx(chan, &memSize, &sectorSize);
    } while (result == -1);
    if (result != 0) {
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    }
    if (sectorSize != 0x2000) {
        TAdPlayerLoadGC__card_result_code = -0xDF;
        return -0xFF;
    }
    mounting = 0x100 << chan;
    workArea = lbl_80511F68[chan];
    if (TAdPlayerLoadGC__card_slot_state_flags & mounting) {
        TAdPlayerLoadGC__card_slot_state_flags &= ~mounting;
        TAdPlayerLoadGC__card_result_code = -0x7F;
        return -0xFF;
    }
    CARDMountAsync(chan, workArea, TAdPlayerLoadGC::unmount_card_and_clear_flags, NULL);
    do {
        result = CARDGetResultCode((void *)chan);
    } while (result == -1);
    switch (result) {
    case -128:
    case -3:
    case -2:
    case -1:
        TAdPlayerLoadGC__card_slot_state_flags &= ~(4 << chan);
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    case -5:
        TAdPlayerLoadGC__card_slot_state_flags |= mounting;
        TAdPlayerLoadGC__card_slot_state_flags &= ~(4 << chan);
        TAdPlayerLoadGC__card_result_code = -0x7F;
        return -0xFF;
    case -6:
        TAdPlayerLoadGC__card_slot_state_flags |= 4 << chan;
        TAdPlayerLoadGC__card_slot_state_flags |= 1 << chan;
        if (CARDCheckAsync((void *)chan, 0) == 0) {
            for (;;) {
                do {
                    result = CARDGetResultCode((void *)chan);
                } while (result == -1);
                switch (result) {
                case -4:
                    break;
                case -128:
                case -5:
                case -3:
                    TAdPlayerLoadGC__card_result_code = -0x7D;
                    TAdPlayerLoadGC__card_slot_state_flags |= 0x400 << chan;
                    return -0x7D;
                case -6:
                case 0:
                    TAdPlayerLoadGC__card_result_code = -0xFD;
                    return -0xFD;
                }
            }
        }
    case -13:
        TAdPlayerLoadGC__card_slot_state_flags |= 4 << chan;
        TAdPlayerLoadGC__card_slot_state_flags |= 1 << chan;
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    case 0:
        TAdPlayerLoadGC__card_slot_state_flags |= 4 << chan;
        TAdPlayerLoadGC__card_slot_state_flags |= 1 << chan;
        TAdPlayerLoadGC__card_slot_state_flags |= 4 << chan;
    case -4:
    default:
        TAdPlayerLoadGC__card_result_code = 0;
        return 0;
    }
}

void TAdPlayerLoadGC::unmount_card_and_clear_flags(s32 n) {
    s32 r = CARDUnmount();
    if (r == 0 || r == -3) {
        TAdPlayerLoadGC__card_slot_state_flags &= ~(4 << n);
        TAdPlayerLoadGC__card_slot_state_flags &= ~(0x10 << n);
        TAdPlayerLoadGC__card_slot_state_flags &= ~(0x40 << n);
        TAdPlayerLoadGC__card_slot_state_flags &= ~(0x100 << n);
        TAdPlayerLoadGC__card_slot_state_flags &= ~(0x400 << n);
        TAdPlayerLoadGC__card_slot_state_flags &= ~(4 << n);
    }
}

void TAdPlayerLoadGC__sub_801E1350(void) {
    s32 i;
    if ((*(void * *)&TAdPlayerLoadGC__banner_file_buf) != NULL) {
        xfree((*(void * *)&TAdPlayerLoadGC__banner_file_buf));
        (*(void * *)&TAdPlayerLoadGC__banner_file_buf) = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (((void * *)&TAdPlayerLoadGC__banner_buffers)[i] != NULL) {
            xfree(((void * *)&TAdPlayerLoadGC__banner_buffers)[i]);
            ((void * *)&TAdPlayerLoadGC__banner_buffers)[i] = NULL;
        }
    }
}

void TAdPlayerLoadGC::load_banner_files() {
    Names_801E13C4 names = memory_card_banner_filenames;
    const char* path = lbl_804496A8;
    s32 i;
    for (i = 0; i < 6; i++) {
        ((void**)&TAdPlayerLoadGC__banner_buffers)[i] = NULL;
    }
    *(void**)&TAdPlayerLoadGC__banner_file_buf = NULL;
    *(void**)&TAdPlayerLoadGC__banner_file_buf = xmalloc(0x1800);
    if (*(void**)&TAdPlayerLoadGC__banner_file_buf == NULL) {
        return;
    }
    for (i = 0; i < 6; i++) {
        ((void**)&TAdPlayerLoadGC__banner_buffers)[i] = xmalloc(0x800);
        if (((void**)&TAdPlayerLoadGC__banner_buffers)[i] == NULL) {
            return;
        }
    }
    if (read_disc_file(path, *(void**)&TAdPlayerLoadGC__banner_file_buf) <= 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        if (read_disc_file(names.p[i], ((void**)&TAdPlayerLoadGC__banner_buffers)[i]) <= 0) {
            return;
        }
    }
}

void TAdPlayerLoadGC__sub_801E14E4(void) {  }

    extern int lbl_805D5E44;

typedef char RecoveredGlobal_801E14E8_TAdPlayerLoadGC__data_80511ED0_size[sizeof(RecoveredGlobal_801E14E8_TAdPlayerLoadGC__data_80511ED0) == 0x18 ? 1 : -1];
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1) {
    if (arg1 < 6) {
        *(s32 *)((s8 *)arg0 + 0x44) = (s32) TAdPlayerLoadGC__banner_file_buf;
        *(s32 *)((s8 *)arg0 + 0x48) = (s32) *(s32 *)((s8 *)((u8 *)&TAdPlayerLoadGC__banner_buffers.value + (arg1 * 4)) + 0);
    }
}

int TAdPlayerLoadGC__sub_801E1510(void) {  return lbl_805D5E44; }
s32 TAdPlayerLoadGC__sub_801E1518(void *arg0, s32 arg1, u32 arg2) {
    return (s32) (((arg2 >> 0xDU) + 3) << 0xD) / 8192;
}
s32 TAdPlayerLoadGC::get_load_result(void * _w0) {
    return TAdPlayerLoadGC__card_result_code;
}

s32 TAdPlayerLoadGC__sub_801E1538(Src_801E17F4 *dst, u8 *buf) {
    Hdr_801E17F4 *h = (Hdr_801E17F4 *)buf;
    u32 crc = h->crc;
    u32 calc;
    h->crc = 0;
    calc = ((u32 (*)(void *, u32))TAdSinglePlyChrSelectGC__sub_80201204)(h, 0x2048);
    h->crc = crc;
    if (calc != crc) {
        return -0xE0;
    }
    dst->size = h->size;
    dst->data = buf + 0x2048;
    return 0;
}

s32 TAdPlayerLoadGC__sub_801E15A4(s32 chan, const char *name, void *buf, s32 blocks, s32 *date, u8 setAttr) {
    u32 size;
    if (chan >= 2) {
        return 0;
    }
    CARDGetSectorSize(chan, &size);
    size *= blocks;
    switch (TAdPlayerLoadGC__sub_801E26DC(chan, name, buf, size)) {
    case -3:
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    case -1:
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    case -6:
    case -10:
    case -128:
    default:
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    case 0:
    case -7:
        break;
    }
    if (setAttr) {
        CARDSetAttributes(chan, TAdPlayerLoadGC__data_80511EE8.fileNo, 0x1C);
    }
    CARDGetStatus(chan, TAdPlayerLoadGC__data_80511EE8.fileNo, &lbl_80511EFC);
    lbl_80511EFC.commentAddr = 0;
    lbl_80511EFC.iconAddr = 0x40;
    lbl_80511EFC.bannerFormat = (lbl_80511EFC.bannerFormat & ~3) | 2;
    lbl_80511EFC.bannerFormat &= ~4;
    lbl_80511EFC.iconFormat = (lbl_80511EFC.iconFormat & ~3) | 2;
    lbl_80511EFC.iconSpeed = (lbl_80511EFC.iconSpeed & ~3) | 3;
    lbl_80511EFC.iconSpeed &= ~0xC;
    switch (CARDWriteAsync(&TAdPlayerLoadGC__data_80511EE8, buf, lbl_805D5E3C, 0, NULL)) {
    case -128:
    case -14:
    case -11:
    case -10:
    case -5:
    case -4:
    case -3:
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    case -1:
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    case 0:
        TAdPlayerLoadGC__card_result_code = 0;
        TAdPlayerLoadGC__card_slot_state_flags |= 0x10 << chan;
        return 0;
    }
    TAdPlayerLoadGC__card_result_code = -0xFD;
    return -0xFD;
}

s32 build_save_file_image__15TAdPlayerLoadGCFPvPv(u8 *arg0, Src_801E17F4 *arg1) {
    DateStamp_801E17F4 ds;
    char buf[0x80];
    s32 size;
    Hdr_801E17F4 *h;
    memset(buf, 0, 0x80);
    h = (Hdr_801E17F4 *)::operator new(0x2048);
    memset(h->title, 0, 0x20);
    memset(h->sub, 0, 0x20);
    strncpy(h->title, lbl_804496B8, 0x20);
    getDateStamp((DateStamp *)&ds);
    memset(buf, 0, 0x80);
    if (arg1->flag != 0) {
        sprintf(buf, lbl_805DC410, arg1->name);
    } else {
        sprintf(buf, lbl_805DC414, arg1->name);
    }
    strncpy(h->sub, buf, 0x20);
    memcpy(h->a, arg1->a, 0x1800);
    memcpy(h->b, arg1->b, 0x800);
    {
        s32 t = arg1->size;
        h->size = t;
        size = arg1->size;
        h->crc = 0;
        h->crc = TAdSinglePlyChrSelectGC__sub_80201204(h, 0x2048, t);
    }
    memcpy(arg0, h, 0x2048);
    memcpy(arg0 + 0x2048, arg1->data, arg1->size);
    ::operator delete(h);
    return size / 8192 + 3;
}

s32 TAdPlayerLoadGC__sub_801E1B50(s32 chan) {
    s32 result;
    if (chan >= 2) {
        return 0;
    }
    result = CARDGetResultCode((void *)chan);
    if (TAdPlayerLoadGC__card_slot_state_flags & (0x10 << chan)) {
        switch (result) {
        case -1:
        case -14:
            TAdPlayerLoadGC__card_result_code = -1;
            return -1;
        case -5:
            TAdPlayerLoadGC__card_slot_state_flags &= ~(4 << chan);
            TAdPlayerLoadGC__card_result_code = -0x7F;
            return 0;
        case -10:
        case 0:
            TAdPlayerLoadGC__card_slot_state_flags &= ~(0x10 << chan);
            CARDSetStatus(chan, TAdPlayerLoadGC__data_80511EE8.fileNo, &lbl_80511EFC);
            CARDClose(&TAdPlayerLoadGC__data_80511EE8);
            TAdPlayerLoadGC__card_result_code = 0;
            return 0;
        case -128:
        case -11:
        case -4:
        case -3:
            TAdPlayerLoadGC__card_result_code = 0;
            return 0;
        case -2:
            TAdPlayerLoadGC__card_result_code = -0x7D;
            return 0;
        }
    } else if (TAdPlayerLoadGC__card_slot_state_flags & (0x40 << chan)) {
        switch (result) {
        case -1:
        case -14:
            return -1;
        case -5:
            TAdPlayerLoadGC__card_slot_state_flags &= ~(4 << chan);
            TAdPlayerLoadGC__card_result_code = -0x7F;
            return -1;
        case -10:
        case 0:
            TAdPlayerLoadGC__card_slot_state_flags &= ~(0x40 << chan);
            CARDClose(&TAdPlayerLoadGC__data_80511EE8);
            TAdPlayerLoadGC__card_result_code = 0;
            return 0;
        case -128:
        case -11:
        case -4:
        case -3:
            TAdPlayerLoadGC__card_result_code = 0;
            return 0;
        case -2:
            TAdPlayerLoadGC__card_result_code = -0x7D;
            return 0;
        }
    } else {
        switch (result) {
        case -1:
        case -14:
            TAdPlayerLoadGC__card_result_code = -1;
            return -1;
        case -10:
        case 0:
            TAdPlayerLoadGC__card_result_code = 0;
            return 0;
        case -128:
        case -11:
        case -4:
        case -3:
            TAdPlayerLoadGC__card_result_code = 0;
            return 0;
        case -5:
            TAdPlayerLoadGC__card_slot_state_flags &= ~(4 << chan);
            TAdPlayerLoadGC__card_result_code = -0x7F;
            return 0;
        case -2:
            TAdPlayerLoadGC__card_result_code = -0x7D;
            return 0;
        }
    }
    TAdPlayerLoadGC__card_result_code = 0;
    return 0;
}

s32 TAdPlayerLoadGC::probe_card_slot() {
    s32 arg0 = (s32)this;
    s32 spC;
    s32 sp8;
    s32 temp_r3;
    if (arg0 >= 2) {
        return 0;
    }
    if ((TAdPlayerLoadGC__card_slot_state_flags & (0x400 << arg0)) && (CARDGetResultCode((void *)arg0) == -5)) {
        TAdPlayerLoadGC__card_result_code = -0x7D;
        return 1;
    }
    do {
        temp_r3 = CARDProbeEx(arg0, &spC, &sp8);
    } while (temp_r3 == -1);
    if (temp_r3 == -3) {
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return 0;
    }
    if (sp8 == 0x2000) {
        switch (temp_r3) {
        case 0:
            if (!(TAdPlayerLoadGC__card_slot_state_flags & (4 << arg0))) {
                if (((s32)TAdPlayerLoadGC__sub_801E101C(arg0)) == 0) {
                    TAdPlayerLoadGC__card_result_code = 0;
                    return 1;
                }
                return 1;
            }
            TAdPlayerLoadGC__card_result_code = 0;
            return 1;
        }
        goto block_17;
    }
    TAdPlayerLoadGC__card_result_code = -0xDF;
block_17:
    return 1;
}
s32 TAdPlayerLoadGC::check_memcard_status(s32 arg0) {
    if (arg0 >= 2) {
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    }
    if ((((TAdPlayerLoadGC *)arg0)->probe_card_slot() == 0) || (TAdPlayerLoadGC__sub_801E1B50(arg0) != 0) || (((TAdPlayerLoadGC *)arg0)->probe_and_check_card() == 0)) {
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    }
    if (!(TAdPlayerLoadGC__card_slot_state_flags & (4 << arg0)) && (((s32)TAdPlayerLoadGC__sub_801E101C(arg0)) != 0)) {
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    }
    switch (CARDCheck(arg0)) {
    case -6:
    case -13:
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    case 0:
        TAdPlayerLoadGC__card_result_code = 0;
        return 0;
    default:
        TAdPlayerLoadGC__card_result_code = 0;
        return 0;
    }
}

s32 find_card_file__15TAdPlayerLoadGCFiPv(s32 chan, const char *name) {
    CARDStat_801E2048 st;
    s32 i;
    if (chan >= 2) {
        TAdPlayerLoadGC__card_result_code = -0xFB;
        return -0xFB;
    }
    if (((TAdPlayerLoadGC *)chan)->probe_card_slot() == 0 || TAdPlayerLoadGC__sub_801E1B50(chan) != 0 ||
        ((TAdPlayerLoadGC *)chan)->probe_and_check_card() == 0 || TAdPlayerLoadGC::check_memcard_status(chan) != 0) {
        TAdPlayerLoadGC__card_result_code = -0xFB;
        return -0xFB;
    }
    if (!(TAdPlayerLoadGC__card_slot_state_flags & (4 << chan))) {
        if (TAdPlayerLoadGC__sub_801E101C(chan) != 0) {
            TAdPlayerLoadGC__card_result_code = -0xFB;
            return -0xFB;
        }
    }
    goto check;
busy:
    TAdPlayerLoadGC__card_result_code = -1;
    return -1;
check:
    if (CARDGetResultCode((void *)chan) == -1) {
        goto busy;
    }
    for (i = 0; i < 0x7F; i++) {
        if (CARDGetStatus(chan, i, &st) == 0 && strncmp(st.fileName, name, 0x20) == 0) {
            if (st.iconAddr == 0xFFFFFFFF) {
                TAdPlayerLoadGC__card_result_code = -0xBF;
                return -0xBF;
            }
            TAdPlayerLoadGC__card_result_code = 0;
            return 0;
        }
    }
    TAdPlayerLoadGC__card_result_code = -0xFB;
    return -0xFB;
}

s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(s32 chan, const char *name, Info_801E21A8 *info) {
    s32 memSize;
    s32 sectorSize;
    Date_801E21A8 date;
    CARDStat_801E2048 st;
    s32 r;
    s32 found;
    s32 i;
    if (chan >= 2) {
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    }
    do {
        r = CARDProbeEx(chan, &memSize, &sectorSize);
    } while (r == -1);
    if (sectorSize != 0x2000) {
        TAdPlayerLoadGC__card_result_code = -0xDF;
        return -0xFF;
    }
    switch (r) {
    case -3:
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    }
    switch (TAdPlayerLoadGC::check_memcard_status(chan)) {
    case -1:
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    case -128:
    default:
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    case 0:
        break;
    }
    switch (find_card_file__15TAdPlayerLoadGCFiPv(chan, name)) {
    case -251:
        TAdPlayerLoadGC__card_result_code = -0xFB;
        return -0xFB;
    case -1:
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    }
    if (!(TAdPlayerLoadGC__card_slot_state_flags & (4 << chan))) {
        if (TAdPlayerLoadGC__sub_801E101C(chan) != 0) {
            TAdPlayerLoadGC__card_result_code = -0xFB;
            return -0xFB;
        }
    }
    goto check;
busy:
    TAdPlayerLoadGC__card_result_code = -1;
    return -1;
check:
    if (CARDGetResultCode((void *)chan) == -1) {
        goto busy;
    }
    found = 0;
    for (i = 0; i < 0x7F; i++) {
        if (CARDGetStatus(chan, i, &st) == 0 && strcmp(st.fileName, name) == 0) {
            found = 1;
            break;
        }
    }
    if (found != 0) {
        if (info != NULL) {
            info->length = st.length;
            info->blocks = (st.length >> 13) + 1;
            info->f6 = 0;
            info->f7 = 0;
            info->f8 = 0;
            fn_801E283C(st.time, &date);
            info->year = date.year;
            info->mon = date.mon;
            info->mday = date.mday;
            info->hour = date.hour;
            info->min = date.min;
            info->sec = date.sec;
            info->pad = date.pad;
        }
        TAdPlayerLoadGC__card_result_code = 0;
        return 0;
    }
    TAdPlayerLoadGC__card_result_code = -0xFB;
    return -0xFB;
}

s32 TAdPlayerLoadGC::query_memcard_capacity(s32 arg0) {
    s32 spC;
    s32 sp8;
    if (arg0 >= 2) {
        return -0xFF;
    }
    if (check_memcard_status(arg0) != 0) {
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    }
    switch (CARDFreeBlocks(arg0, &spC, &sp8)) {
    case -3:
        TAdPlayerLoadGC__card_result_code = -0xFF;
        return -0xFF;
    case -1:
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    case 0:
        TAdPlayerLoadGC__card_result_code = 0;
        return spC / 8192;
    case -6:
    case -128:
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    default:
        TAdPlayerLoadGC__card_result_code = -0xFD;
        return -0xFD;
    }
}
s32 TAdPlayerLoadGC__sub_801E24F8(s32 chan) {
    if (chan >= 2) {
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    }
    switch (CARDFormatAsync(chan, NULL)) {
    case 0:
        TAdPlayerLoadGC__card_result_code = 0;
        return 0;
    case -1:
    case -3:
    case -5:
    case -128:
        break;
    }
    TAdPlayerLoadGC__card_slot_state_flags |= 0x400 << chan;
    TAdPlayerLoadGC__card_result_code = -1;
    return -1;
}

s32 TAdPlayerLoadGC::poll_load_status(s32 arg0) {
    if (arg0 >= 2) {
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    }
    switch (CARDDelete()) {
    case -1:
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    case 0:
        TAdPlayerLoadGC__card_result_code = 0;
        return 0;
    case -4:
        TAdPlayerLoadGC__card_result_code = 0;
        return 0;
    default:
        TAdPlayerLoadGC__card_result_code = -1;
        return -1;
    }
}

s32 TAdPlayerLoadGC__sub_801E263C(s32 unused, s32 chan, u8 *workArea) {
    s32 i;
    TAdPlayerLoadGC__card_slot_state_flags = 0;
    lbl_805D5E34 = 0;
    CARDInit();
    TAdPlayerLoadGC__card_result_code = 0;
    if (chan >= 2) {
        TAdPlayerLoadGC__card_result_code = -0x100;
        return -0x100;
    }
    for (i = 0; i < 2; i++) {
        lbl_80511F68[i] = workArea + i * 0xA000;
        TAdPlayerLoadGC__sub_801E101C(i);
    }
    TAdPlayerLoadGC__card_result_code = 0;
    return 0;
}

}
