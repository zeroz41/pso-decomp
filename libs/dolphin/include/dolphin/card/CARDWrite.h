#ifndef _DOLPHIN_CARDWRITE_H_
#define _DOLPHIN_CARDWRITE_H_

s32 CARDWriteAsync(struct CARDFileInfo * fileInfo, const void * buf, s32 length, s32 offset, void (* callback)(s32, s32));
s32 CARDWrite(struct CARDFileInfo * fileInfo, const void * buf, s32 length, s32 offset);

#endif
