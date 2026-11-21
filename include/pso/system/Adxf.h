#ifndef PSO_SYSTEM_ADXF_H
#define PSO_SYSTEM_ADXF_H

#include "types.h"

// Opaque CRI file handle; its pool storage belongs to the ADXF implementation.
struct AdxfHandle;

extern "C" {
AdxfHandle *ADXF_Open(const void *name, s32 mode);
AdxfHandle *ADXF_OpenAfs(s32 partition, s32 file);
void ADXF_Close(AdxfHandle *file);
s32 ADXF_GetFsizeByte(AdxfHandle *file);
s32 ADXF_GetFsizeSct(AdxfHandle *file);
s32 ADXF_GetStat(AdxfHandle *file);
s32 ADXF_Stop(AdxfHandle *file);
s32 ADXF_Seek(AdxfHandle *file, s32 offset, s32 origin);
s32 ADXF_ReadNw(AdxfHandle *file, s32 sectors, void *destination);
s32 ADXF_ReadNw32(AdxfHandle *file, s32 sectors, void *destination);
}

#endif
