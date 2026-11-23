#define PSO_SDK_COMPACT_MATH
#include <stdio.h>
#include <string.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/card.h>
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/system/date.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

struct Names_801E13C4 { const char* p[6]; };

struct CardSaveHeader {
    char title[0x20];
    char comment[0x20];
    u8 banner[0x1800];
    u8 icon[0x800];
    s32 size;
    u32 crc;
};

struct Date_801E21A8 { u16 year; u8 mon; u8 mday; u8 hour; u8 min; u8 sec; u8 pad; u8 pad8[4]; };
LAYOUT_ASSERT(CardSaveHeader_size, sizeof(CardSaveHeader) == 0x2048);
LAYOUT_ASSERT(CardSaveHeader_crc_offset, offsetof(CardSaveHeader, crc) == 0x2044);

struct Info_801E21A8 { u32 length; s16 blocks; u8 f6; u8 f7; s16 f8; u16 year; u8 mon; u8 mday; u8 hour; u8 min; u8 sec; u8 pad; };

u32 card_slot_state_flags;
s32 lbl_805D5E34;
void *banner_file_buf;
s32 lbl_805D5E3C;
s32 card_result_code;
    int lbl_805D5E44;
extern "C" {
s32 mount_memcard(saddr);
s32 poll_memcard_result(saddr);
const Names_801E13C4 memory_card_banner_filenames = {{"vms_sys.tp", "vms_icon1.tp", "vms_icon2.tp", "vms_down.tp", "vms_capt.tp", "vms_net.tp"}};
u32 calc_crc32_bitwise(u8 *, u32);
}
void fill_date_from_seconds(u32 secs, DateStamp *out);
extern "C" {
int strcmp(const char *s1, const char *s2);
s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(saddr chan, const char *name, Info_801E21A8 *info);
extern u8 *lbl_80511F68[];
s32 open_or_create_memcard_file(s32 chan, const char *name, void *buf, u32 size);
extern CARDFileInfo lbl_80511EE8;
extern CARDStat lbl_80511EFC;

void TAdPlayerLoadGC::reset_load_state(s32 channel, u64 *serial_number) {
    *serial_number = 0;
    CARDGetSerialNo(channel, serial_number);
}

void TAdPlayerLoadGC::poll_card_load(s32 chan) {
    s32 spC;
    s32 sp8;
    s32 temp_r3;

    card_slot_state_flags &= ~(0x400 << chan);
    do {
        temp_r3 = CARDProbeEx(chan, &spC, &sp8);
    } while (temp_r3 == -1);
    if (sp8 == 0x2000) {
        if ((temp_r3 == -3) || (temp_r3 == -2)) {
            card_result_code = -0x7D;
            return;
        }
        mount_memcard(chan);
    }
}

s32 TAdPlayerLoadGC::check_card_result_code(s32 channel) {
    if (channel >= 2) {
        return 0;
    }
    switch (CARDGetResultCode(channel)) {
    case -0x80:
    case -0xE:
    case -4:
    case -1:
    case 0:
        card_result_code = 0;
        return 1;
    case -5:
    case -3:
    case -0xB:
    case -0xA:
        card_result_code = -0x7D;
        return 0;
    default:
        return 1;
    }
}

#pragma push
#pragma fp_contract on
s32 TAdPlayerLoadGC::probe_and_check_card(saddr channel) {
    s32 spC;
    s32 sp8;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 var_r0;
    if ((card_slot_state_flags & (0x400 << channel)) && ((temp_r3 = CARDGetResultCode(channel), ((temp_r3 == -5) != 0)) || (temp_r3 == -2))) {
        var_r0 = -0x7F;
        if (temp_r3 == -2) {
            var_r0 = -0x7D;
        }
        card_result_code = var_r0;
        return 0;
    }
    do {
        temp_r3_2 = CARDProbeEx(channel, &spC, &sp8);
    } while (temp_r3_2 == -1);
    if (temp_r3_2 == -2) {
        card_result_code = -0x7D;
        return 0;
    }
    if (sp8 == 0x2000) {
        if (!(card_slot_state_flags & (4 << channel))) {
            mount_memcard(channel);
            if ((u32) TAdPlayerLoadGC::get_load_result(channel) == -0x7FU) {
                card_result_code = -0x7F;
                return 0;
            }
        }
        temp_r3_3 = CARDCheckAsync(channel, 0);
        if (temp_r3_3 == 0) {
            for (;;) {
                temp_r3_4 = CARDGetResultCode(channel);
                if (temp_r3_4 == -1) {
                    continue;
                }
                switch (temp_r3_4) {
                case -3:
                    card_result_code = -0xFF;
                    return 0;
                case -5:
                case -128:
                    card_result_code = -0x7F;
                    return 0;
                case 0:
                    return 1;
                case -13:
                case -6:
                    card_result_code = -0xFD;
                    return 1;
                }
            }
        } else {
            switch (temp_r3_3) {
            case -5:
            case -128:
                card_result_code = -0x7D;
                return 0;
            case -3:
                card_result_code = -0xFF;
                return 0;
            case 0:
                return 1;
            case -13:
            case -6:
                card_result_code = -0xFD;
                return 1;
            }
        }
    }
    card_result_code = -0xDF;
    return 0;
}
#pragma pop

s32 get_memcard_free_files(s32 chan) {
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

s32 mount_memcard(saddr chan) {
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
        card_result_code = -0xFF;
        return -0xFF;
    }
    if (sectorSize != 0x2000) {
        card_result_code = -0xDF;
        return -0xFF;
    }
    mounting = 0x100 << chan;
    workArea = lbl_80511F68[chan];
    if (card_slot_state_flags & mounting) {
        card_slot_state_flags &= ~mounting;
        card_result_code = -0x7F;
        return -0xFF;
    }
    CARDMountAsync(chan, workArea, TAdPlayerLoadGC::unmount_card_and_clear_flags, NULL);
    do {
        result = CARDGetResultCode(chan);
    } while (result == -1);
    switch (result) {
    case -128:
    case -3:
    case -2:
    case -1:
        card_slot_state_flags &= ~(4 << chan);
        card_result_code = -0xFF;
        return -0xFF;
    case -5:
        card_slot_state_flags |= mounting;
        card_slot_state_flags &= ~(4 << chan);
        card_result_code = -0x7F;
        return -0xFF;
    case -6:
        card_slot_state_flags |= 4 << chan;
        card_slot_state_flags |= 1 << chan;
        if (CARDCheckAsync(chan, 0) == 0) {
            for (;;) {
                do {
                    result = CARDGetResultCode(chan);
                } while (result == -1);
                switch (result) {
                case -4:
                    break;
                case -128:
                case -5:
                case -3:
                    card_result_code = -0x7D;
                    card_slot_state_flags |= 0x400 << chan;
                    return -0x7D;
                case -6:
                case 0:
                    card_result_code = -0xFD;
                    return -0xFD;
                }
            }
        }
    case -13:
        card_slot_state_flags |= 4 << chan;
        card_slot_state_flags |= 1 << chan;
        card_result_code = -0xFD;
        return -0xFD;
    case 0:
        card_slot_state_flags |= 4 << chan;
        card_slot_state_flags |= 1 << chan;
        card_slot_state_flags |= 4 << chan;
    case -4:
    default:
        card_result_code = 0;
        return 0;
    }
}

void TAdPlayerLoadGC::unmount_card_and_clear_flags(s32 n, s32) {
    s32 r = CARDUnmount(n);
    if (r == 0 || r == -3) {
        card_slot_state_flags &= ~(4 << n);
        card_slot_state_flags &= ~(0x10 << n);
        card_slot_state_flags &= ~(0x40 << n);
        card_slot_state_flags &= ~(0x100 << n);
        card_slot_state_flags &= ~(0x400 << n);
        card_slot_state_flags &= ~(4 << n);
    }
}

void free_banner_buffers(void) {
    s32 i;
    if (banner_file_buf != NULL) {
        xfree(banner_file_buf);
        banner_file_buf = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (banner_buffers[i] != NULL) {
            xfree(banner_buffers[i]);
            banner_buffers[i] = NULL;
        }
    }
}

void TAdPlayerLoadGC::load_banner_files() {
    Names_801E13C4 names = memory_card_banner_filenames;
    const char* path = "pso_bana_f.tp";
    s32 i;
    for (i = 0; i < 6; i++) {
        banner_buffers[i] = NULL;
    }
    banner_file_buf = NULL;
    banner_file_buf = xmalloc(0x1800);
    if (banner_file_buf == NULL) {
        return;
    }
    for (i = 0; i < 6; i++) {
        banner_buffers[i] = xmalloc(0x800);
        if (banner_buffers[i] == NULL) {
            return;
        }
    }
    if (read_disc_file(path, banner_file_buf) <= 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        if (read_disc_file(names.p[i], banner_buffers[i]) <= 0) {
            return;
        }
    }
}
}

void fn_801E14E4(CardSaveDescriptor *) {}


void set_card_banner_and_icon(CardSaveDescriptor *file, s32 index) {
    if (index < 6) {
        file->banner = banner_file_buf;
        file->icon = banner_buffers[index];
    }
}

int fn_801E1510(void) {  return lbl_805D5E44; }
s32 card_blocks_for_size(void *arg0, s32 arg1, u32 size) {
    return (s32) (((size >> 0xDU) + 3) << 0xD) / 8192;
}
s32 TAdPlayerLoadGC::get_load_result(s32) {
    return card_result_code;
}

s32 verify_card_save_header(CardSaveDescriptor *file, void *image) {
    CardSaveHeader *h = (CardSaveHeader *)image;
    u32 crc = h->crc;
    u32 calc;
    h->crc = 0;
    calc = calc_crc32_bitwise((u8 *)h, sizeof(*h));
    h->crc = crc;
    if (calc != crc) {
        return -0xE0;
    }
    file->size = h->size;
    file->data = (u8 *)image + sizeof(*h);
    return 0;
}

extern "C" {
s32 start_memcard_write(s32 chan, const char *name, void *buf, s32 blocks, CardWriteDate *date, u32 flags) {
    u32 size;
    if (chan >= 2) {
        return 0;
    }
    CARDGetSectorSize(chan, &size);
    size *= blocks;
    switch (open_or_create_memcard_file(chan, name, buf, size)) {
    case -3:
        card_result_code = -0xFF;
        return -0xFF;
    case -1:
        card_result_code = -1;
        return -1;
    case -6:
    case -10:
    case -128:
    default:
        card_result_code = -0xFD;
        return -0xFD;
    case 0:
    case -7:
        break;
    }
    if (static_cast<u8>(flags) != 0) {
        CARDSetAttributes(chan, lbl_80511EE8.fileNo, 0x1C);
    }
    CARDGetStatus(chan, lbl_80511EE8.fileNo, &lbl_80511EFC);
    lbl_80511EFC.commentAddr = 0;
    lbl_80511EFC.iconAddr = 0x40;
    lbl_80511EFC.bannerFormat = (lbl_80511EFC.bannerFormat & ~3) | 2;
    lbl_80511EFC.bannerFormat &= ~4;
    lbl_80511EFC.iconFormat = (lbl_80511EFC.iconFormat & ~3) | 2;
    lbl_80511EFC.iconSpeed = (lbl_80511EFC.iconSpeed & ~3) | 3;
    lbl_80511EFC.iconSpeed &= ~0xC;
    switch (CARDWriteAsync(&lbl_80511EE8, buf, lbl_805D5E3C, 0, NULL)) {
    case -128:
    case -14:
    case -11:
    case -10:
    case -5:
    case -4:
    case -3:
        card_result_code = -0xFD;
        return -0xFD;
    case -1:
        card_result_code = -1;
        return -1;
    case 0:
        card_result_code = 0;
        card_slot_state_flags |= 0x10 << chan;
        return 0;
    }
    card_result_code = -0xFD;
    return -0xFD;
}

s32 TAdPlayerLoadGC::build_save_file_image(void *image, CardSaveDescriptor *file) {
    DateStamp ds;
    char buf[0x80];
    s32 size;
    CardSaveHeader *h;
    memset(buf, 0, 0x80);
    h = (CardSaveHeader *)::operator new(sizeof(*h));
    memset(h->title, 0, 0x20);
    memset(h->comment, 0, 0x20);
    strncpy(h->title, "PSO EPISODE I & II Plus", 0x20);
    getDateStamp(&ds);
    memset(buf, 0, 0x80);
    if (file->omit_title_space != 0) {
        sprintf(buf, "%s", file->title);
    } else {
        sprintf(buf, "%s ", file->title);
    }
    strncpy(h->comment, buf, 0x20);
    memcpy(h->banner, file->banner, 0x1800);
    memcpy(h->icon, file->icon, 0x800);
    {
        s32 t = file->size;
        h->size = t;
        size = file->size;
        h->crc = 0;
        h->crc = calc_crc32_bitwise((u8 *)h, sizeof(*h));
    }
    memcpy(image, h, sizeof(*h));
    memcpy((u8 *)image + sizeof(*h), file->data, file->size);
    ::operator delete(h);
    return size / 8192 + 3;
}

s32 start_memcard_read(s32 chan, const char *name, void *buf, u32 blocks) {
    u32 size;
    CARDStat st;
    if (chan >= 2) {
        return 0;
    }
    switch (CARDOpen(chan, name, &lbl_80511EE8)) {
    case -3:
        card_result_code = -0xFF;
        return -0xFF;
    case -4:
        card_result_code = -0xFF;
        return -0xFB;
    case -1:
        card_result_code = -1;
        return -1;
    case -6:
    case -10:
    case -128:
    default:
        card_result_code = -0xFD;
        return -0xFD;
    case 0:
        break;
    }
    CARDGetSectorSize(chan, &size);
    if (size != 0x2000) {
        card_result_code = -0xFD;
        return -0xFD;
    }
    if (blocks != 0) {
        size = blocks * size;
    } else {
        CARDGetStatus(chan, lbl_80511EE8.fileNo, &st);
        size = st.length;
    }
    switch (CARDReadAsync(&lbl_80511EE8, buf, (s32)size, 0, NULL)) {
    case -3:
        card_result_code = -0xFF;
        return -0xFF;
    case -1:
        card_result_code = -1;
        return -1;
    case -4:
        card_result_code = -0xFF;
        return -0xFB;
    case 0:
        card_slot_state_flags |= 0x40 << chan;
        card_result_code = 0;
        return 0;
    case -5:
    case -11:
    case -10:
    case -14:
    case -128:
        break;
    }
    card_result_code = -0xF9;
    return -0xF9;
}

s32 poll_memcard_result(saddr chan) {
    s32 result;
    if (chan >= 2) {
        return 0;
    }
    result = CARDGetResultCode(chan);
    if (card_slot_state_flags & (0x10 << chan)) {
        switch (result) {
        case -1:
        case -14:
            card_result_code = -1;
            return -1;
        case -5:
            card_slot_state_flags &= ~(4 << chan);
            card_result_code = -0x7F;
            return 0;
        case -10:
        case 0:
            card_slot_state_flags &= ~(0x10 << chan);
            CARDSetStatus(chan, lbl_80511EE8.fileNo, &lbl_80511EFC);
            CARDClose(&lbl_80511EE8);
            card_result_code = 0;
            return 0;
        case -128:
        case -11:
        case -4:
        case -3:
            card_result_code = 0;
            return 0;
        case -2:
            card_result_code = -0x7D;
            return 0;
        }
    } else if (card_slot_state_flags & (0x40 << chan)) {
        switch (result) {
        case -1:
        case -14:
            return -1;
        case -5:
            card_slot_state_flags &= ~(4 << chan);
            card_result_code = -0x7F;
            return -1;
        case -10:
        case 0:
            card_slot_state_flags &= ~(0x40 << chan);
            CARDClose(&lbl_80511EE8);
            card_result_code = 0;
            return 0;
        case -128:
        case -11:
        case -4:
        case -3:
            card_result_code = 0;
            return 0;
        case -2:
            card_result_code = -0x7D;
            return 0;
        }
    } else {
        switch (result) {
        case -1:
        case -14:
            card_result_code = -1;
            return -1;
        case -10:
        case 0:
            card_result_code = 0;
            return 0;
        case -128:
        case -11:
        case -4:
        case -3:
            card_result_code = 0;
            return 0;
        case -5:
            card_slot_state_flags &= ~(4 << chan);
            card_result_code = -0x7F;
            return 0;
        case -2:
            card_result_code = -0x7D;
            return 0;
        }
    }
    card_result_code = 0;
    return 0;
}

s32 TAdPlayerLoadGC::probe_card_slot(saddr chan) {
    s32 spC;
    s32 sp8;
    s32 temp_r3;
    if (chan >= 2) {
        return 0;
    }
    if ((card_slot_state_flags & (0x400 << chan)) && (CARDGetResultCode(chan) == -5)) {
        card_result_code = -0x7D;
        return 1;
    }
    do {
        temp_r3 = CARDProbeEx(chan, &spC, &sp8);
    } while (temp_r3 == -1);
    if (temp_r3 == -3) {
        card_result_code = -0xFF;
        return 0;
    }
    if (sp8 == 0x2000) {
        switch (temp_r3) {
        case 0:
            if (!(card_slot_state_flags & (4 << chan))) {
                if (((s32)mount_memcard(chan)) == 0) {
                    card_result_code = 0;
                    return 1;
                }
                return 1;
            }
            card_result_code = 0;
            return 1;
        }
        goto block_17;
    }
    card_result_code = -0xDF;
block_17:
    return 1;
}
s32 TAdPlayerLoadGC::check_memcard_status(s32 chan) {
    if (chan >= 2) {
        card_result_code = -0xFF;
        return -0xFF;
    }
    if ((TAdPlayerLoadGC::probe_card_slot(chan) == 0) || (poll_memcard_result(chan) != 0) || (TAdPlayerLoadGC::probe_and_check_card(chan) == 0)) {
        card_result_code = -0xFF;
        return -0xFF;
    }
    if (!(card_slot_state_flags & (4 << chan)) && (((s32)mount_memcard(chan)) != 0)) {
        card_result_code = -0xFF;
        return -0xFF;
    }
    switch (CARDCheck(chan)) {
    case -6:
    case -13:
        card_result_code = -0xFD;
        return -0xFD;
    case 0:
        card_result_code = 0;
        return 0;
    default:
        card_result_code = 0;
        return 0;
    }
}

s32 TAdPlayerLoadGC::find_card_file(saddr chan, const char *name) {
    CARDStat st;
    s32 i;
    if (chan >= 2) {
        card_result_code = -0xFB;
        return -0xFB;
    }
    if (TAdPlayerLoadGC::probe_card_slot(chan) == 0 || poll_memcard_result(chan) != 0 ||
        TAdPlayerLoadGC::probe_and_check_card(chan) == 0 || TAdPlayerLoadGC::check_memcard_status(chan) != 0) {
        card_result_code = -0xFB;
        return -0xFB;
    }
    if (!(card_slot_state_flags & (4 << chan))) {
        if (mount_memcard(chan) != 0) {
            card_result_code = -0xFB;
            return -0xFB;
        }
    }
    goto check;
busy:
    card_result_code = -1;
    return -1;
check:
    if (CARDGetResultCode(chan) == -1) {
        goto busy;
    }
    for (i = 0; i < 0x7F; i++) {
        if (CARDGetStatus(chan, i, &st) == 0 && strncmp(st.fileName, name, 0x20) == 0) {
            if (st.iconAddr == 0xFFFFFFFF) {
                card_result_code = -0xBF;
                return -0xBF;
            }
            card_result_code = 0;
            return 0;
        }
    }
    card_result_code = -0xFB;
    return -0xFB;
}

s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(saddr chan, const char *name, Info_801E21A8 *info) {
    s32 memSize;
    s32 sectorSize;
    Date_801E21A8 date;
    CARDStat st;
    s32 r;
    s32 found;
    s32 i;
    if (chan >= 2) {
        card_result_code = -0xFF;
        return -0xFF;
    }
    do {
        r = CARDProbeEx(chan, &memSize, &sectorSize);
    } while (r == -1);
    if (sectorSize != 0x2000) {
        card_result_code = -0xDF;
        return -0xFF;
    }
    switch (r) {
    case -3:
        card_result_code = -0xFF;
        return -0xFF;
    }
    switch (TAdPlayerLoadGC::check_memcard_status(chan)) {
    case -1:
        card_result_code = -1;
        return -1;
    case -128:
    default:
        card_result_code = -0xFD;
        return -0xFD;
    case 0:
        break;
    }
    switch (TAdPlayerLoadGC::find_card_file(chan, name)) {
    case -251:
        card_result_code = -0xFB;
        return -0xFB;
    case -1:
        card_result_code = -1;
        return -1;
    }
    if (!(card_slot_state_flags & (4 << chan))) {
        if (mount_memcard(chan) != 0) {
            card_result_code = -0xFB;
            return -0xFB;
        }
    }
    goto check;
busy:
    card_result_code = -1;
    return -1;
check:
    if (CARDGetResultCode(chan) == -1) {
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
            fill_date_from_seconds(st.time, (DateStamp *)&date);
            info->year = date.year;
            info->mon = date.mon;
            info->mday = date.mday;
            info->hour = date.hour;
            info->min = date.min;
            info->sec = date.sec;
            info->pad = date.pad;
        }
        card_result_code = 0;
        return 0;
    }
    card_result_code = -0xFB;
    return -0xFB;
}

s32 TAdPlayerLoadGC::query_memcard_capacity(s32 channel, s32) {
    s32 free_bytes;
    s32 free_files;
    if (channel >= 2) {
        return -0xFF;
    }
    if (check_memcard_status(channel) != 0) {
        card_result_code = -0xFD;
        return -0xFD;
    }
    switch (CARDFreeBlocks(channel, &free_bytes, &free_files)) {
    case -3:
        card_result_code = -0xFF;
        return -0xFF;
    case -1:
        card_result_code = -1;
        return -1;
    case 0:
        card_result_code = 0;
        return free_bytes / 8192;
    case -6:
    case -128:
        card_result_code = -0xFD;
        return -0xFD;
    default:
        card_result_code = -0xFD;
        return -0xFD;
    }
}
s32 start_memcard_format(s32 chan) {
    if (chan >= 2) {
        card_result_code = -1;
        return -1;
    }
    switch (CARDFormatAsync(chan, NULL)) {
    case 0:
        card_result_code = 0;
        return 0;
    case -1:
    case -3:
    case -5:
    case -128:
        break;
    }
    card_slot_state_flags |= 0x400 << chan;
    card_result_code = -1;
    return -1;
}

s32 TAdPlayerLoadGC::delete_memcard_file(s32 chan, const char *name) {
    if (chan >= 2) {
        card_result_code = -1;
        return -1;
    }
    switch (CARDDelete(chan, name)) {
    case -1:
        card_result_code = -1;
        return -1;
    case 0:
        card_result_code = 0;
        return 0;
    case -4:
        card_result_code = 0;
        return 0;
    default:
        card_result_code = -1;
        return -1;
    }
}

s32 init_memcard(s32 unused, s32 chan, u8 *workArea) {
    s32 i;
    card_slot_state_flags = 0;
    lbl_805D5E34 = 0;
    CARDInit();
    card_result_code = 0;
    if (chan >= 2) {
        card_result_code = -0x100;
        return -0x100;
    }
    for (i = 0; i < 2; i++) {
        lbl_80511F68[i] = workArea + i * 0xA000;
        mount_memcard(i);
    }
    card_result_code = 0;
    return 0;
}

// Opens the card file, creating it with `size` bytes when CARDOpen reports CARD_RESULT_NOFILE.
s32 open_or_create_memcard_file(s32 chan, const char *name, void *buf, u32 size) {
    char fileName[32];
    s32 result;
    memset(fileName, 0, sizeof(fileName));
    strncpy(fileName, name, sizeof(fileName));
    lbl_805D5E3C = size;
    result = CARDOpen(chan, name, &lbl_80511EE8);
    switch (result) {
    case -3:
        return -0xFF;
    case -1:
        return result;
    case 0:
        return result;
    case -128:
    case -10:
    case -6:
    case -2:
    default:
        return result;
    case -4:
        result = CARDCreate(chan, fileName, lbl_805D5E3C, &lbl_80511EE8);
        switch (result) {
        case -7:
            return result;
        case -3:
            return result;
        case -1:
            return result;
        case 0:
            return result;
        case -2:
        case -4:
        case -6:
        case -8:
        case -9:
        case -12:
        case -128:
        default:
            return result;
        }
    }
}
}

void *banner_buffers[6];
CARDFileInfo lbl_80511EE8;
CARDStat lbl_80511EFC;
u8 *lbl_80511F68[2];
