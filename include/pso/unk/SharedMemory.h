#ifndef PSO_UNK_SHAREDMEMORY_H
#define PSO_UNK_SHAREDMEMORY_H

#include "types.h"

#define SHARED_MEMORY_MAGIC 0x53454741 // 'SEGA'

// SharedMemory::flags
#define SHARED_MEMORY_DATA_SET 0x1
#define SHARED_MEMORY_UPLOAD_DATA_SET 0x4
#define SHARED_MEMORY_DOWNLOAD_DATA_SET 0x20
#define SHARED_MEMORY_CONNECT_PARAM_SET 0x800
#define SHARED_MEMORY_DISC_MESSAGES_SET 0x1000

// Block named "Shared Memory Connect Parameter" by the string at its start.
struct SharedMemoryConnectParam {
    u8 unk_000[4];
    char name[0xF0];
    s32 check_param;
    u8 unk_0F8[0x44];
    s8 unk_13C;
    s8 unk_13D;
    u8 unk_13E[0x82];
    s16 trial_param;
    s16 unk_1C2;
    u8 unk_1C4[0x78];
    s8 modem_flag;
    s8 check_char;
    s16 modem_param;
    u8 unk_240[0x120];
    s8 check_param_360;
    u8 unk_361[0x49F];
};

// Disc error messages.
struct SharedMemoryDiscMessages {
    s8 unk_000;
    u8 unk_001[0x8B];
    char message[5][0x100];
};

// The 0x8000 bytes kept across the reset into the next DOL while the magic is set.
struct SharedMemory {
    u32 magic;
    s32 flags;
    u32 unk_008;
    u32 upload_data_size;
    u32 download_data_size;
    u32 data_size;
    u8 unk_018[4];
    s32 connect_param_size;
    u8 unk_020[0x2000];
    u8 upload_data[0x2000];
    u8 download_data[0x2000];
    u8 data[0x800];
    u8 unk_6820[0x800];
    SharedMemoryConnectParam connect_param;
    SharedMemoryDiscMessages disc_messages;
    u8 unk_7DAC[0x254];
};

typedef char SharedMemory_size[sizeof(SharedMemory) == 0x8000 ? 1 : -1];

// Header of a DOL executable.
struct DolHeader {
    u32 text_offset[7];
    u32 data_offset[11];
    u32 text_address[7];
    u32 data_address[11];
    u32 text_size[7];
    u32 data_size[11];
    u32 bss_address;
    u32 bss_size;
    u32 entry_point;
    u8 unk_0E4[0x1C];
};

typedef char DolHeader_size[sizeof(DolHeader) == 0x100 ? 1 : -1];

// Argument of LaunchDol: the DOL to start, its loaded image, and the bytes after
// this header to keep across the reset.
struct LaunchDolContext {
    char dol_name[0x100];
    s32 unk_100;
    DolHeader *dol_image;
    s32 keep_size;
    u8 unk_10C[4];
    SharedMemory shared_memory;
};

extern LaunchDolContext *lbl_805D7CB0;
extern SharedMemoryDiscMessages *lbl_805D7CB8;
extern SharedMemory *lbl_805D7CC0;
extern SharedMemoryConnectParam *lbl_805D7CC4;

extern "C" {
extern s32 lbl_805D7CA8;
void LaunchDol(LaunchDolContext *context);
}

#endif
