#ifndef PSO_UI_FRONTEND_TADPLAYERLOADGC_801E0C30_H
#define PSO_UI_FRONTEND_TADPLAYERLOADGC_801E0C30_H

#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/system/save/CardSaveFile.h"

struct CardWriteDate;

// The banner and icon block build_save_file_image writes in front of a save file's data.
struct CardSaveHeader {
    char title[0x20];
    char comment[0x20];
    u8 banner[0x1800];
    u8 icon[0x800];
    s32 size;
    u32 crc;
};

LAYOUT_ASSERT(CardSaveHeader_size, sizeof(CardSaveHeader) == 0x2048);
LAYOUT_ASSERT(CardSaveHeader_crc_offset, offsetof(CardSaveHeader, crc) == 0x2044);

void free_banner_buffers(void);
s32 get_memcard_free_files(s32 chan);
s32 mount_memcard(saddr chan);
s32 start_memcard_read(s32 chan, const char *name, void *buf, u32 blocks);
s32 open_or_create_memcard_file(s32 chan, const char *name, void *buf, u32 size);
s32 start_memcard_write(s32 chan, const char *name, void *buffer, s32 blocks, CardWriteDate *date, u32 flags);
s32 init_memcard(s32, s32 chan, u8 *workArea, s32);
s32 start_memcard_format(s32 chan, s32, s32, s32, s32);

// Nothing sets the state; TChallenge and TChallenge4P skip their run_task while it is 1.
int get_card_wait_state(void);
s32 card_blocks_for_size(s32, s32, u32 size);

extern void *banner_buffers[6];

// The banner and icon image files of the save, copied whole by load_banner_files.
struct CardBannerFileNames { const char* p[6]; };

#endif
