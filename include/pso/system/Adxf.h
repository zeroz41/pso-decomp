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
void adxf_init(void);
void adxf_finish(void);
void TLobby__sub_803CC884(void);
void TLobby__sub_803CD804(void);
s32 check_803CC294(s32 arg0, s32 arg1);
s32 rd32_803CD5C4(u8 *p);
s32 state_803CD5C4(void);
}

#endif
