#ifndef PSO_SYSTEM_ADXF_H
#define PSO_SYSTEM_ADXF_H

#include "types.h"

// Opaque CRI file handle; its pool storage belongs to the ADXF implementation.
struct AdxfHandle;

extern "C" {
AdxfHandle *ADXF_Open(const void *name, s32 mode);
AdxfHandle *ADXF_OpenAfs(s32 partition, s32 file);
void ADXF_Close(AdxfHandle *file);
// Closes every open handle in the pool.
void ADXF_CloseAll(void);
s32 ADXF_GetFsizeByte(AdxfHandle *file);
s32 ADXF_GetFsizeSct(AdxfHandle *file);
s32 ADXF_GetStat(AdxfHandle *file);
s32 ADXF_Stop(AdxfHandle *file);
s32 ADXF_Seek(AdxfHandle *file, s32 offset, s32 origin);
s32 ADXF_ReadNw(AdxfHandle *file, s32 sectors, void *destination);
s32 ADXF_ReadNw32(AdxfHandle *file, s32 sectors, void *destination);
// File name, directory, sector offset and sector count of file flid of AFS partition ptid.
s32 ADXF_GetFnameRangeEx(s32 ptid, s32 flid, char *fname, s32 *dir, s32 *ofst, s32 *fnsct);
// Partition ptid's load state; advances a non-blocking partition load.
s32 ADXF_GetPtStat(s32 ptid);
// Starts a non-blocking load of AFS file name as partition id; ptinfo receives its table.
s32 ADXF_LoadPartitionNw(s32 id, const char *name, s32 mode, void *ptinfo);
void adxf_init(void);
void adxf_finish(void);
void adxf_exec_server(void);
void adxf_end_partition_load(void);
}

struct GetAfsFileInfoChunk { u16 id; u16 len; s32 off; };

// A loaded AFS partition: the archive's name and the sector count of each of its files.
struct AdxfPartitionInfo {
    AdxfPartitionInfo *next;
    s32 info_size; // bytes of this record with its sector counts
    s32 file_count;
    u16 entry_count;
    s8 fe;
    u8 pad_f;
    char name[0x100];
    s32 dir;
    u16 first_sector; // the first file's sector in the archive
    u16 sector_counts[1];
};

#endif
