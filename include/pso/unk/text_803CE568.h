#ifndef PSO_UNK_TEXT_803CE568_H
#define PSO_UNK_TEXT_803CE568_H

#include "types.h"
#include "pso/system/CvFsStreamHandle.h"

struct CvFsHandle;

// --- C functions defined in text_803CE568.cpp ---
extern "C" {

void cvFsFinish(void);
void TLobby__sub_803CEF60(void);
s32 cvFsAddVolume(char *dev, char *vol, void *img);
s32 cvFsChangeDir(char *path);
void cvFsDelDev(char *dev);
s32 cvFsDelVolume(char *dev, char *vol);
s32 cvFsDeleteFile(char *path);
s32 cvFsGetFileSize(const char *path);
CvFsHandle *cvFsOpen(const char *path, s32 mode, s32 extra);
s32 cvFsGetFileSizeEx(const char *path, s32 arg);
s32 cvFsGetFreeSize(char *dev);
s32 cvFsGetVolumeInfo(char *dev, char *vol, void *info);
void cvFsInit(void);
s32 cvFsIsExistFile(char *path);
s32 cvFsMakeDir(char *path);
s32 cvFsRemoveDir(char *path);
s32 cvFsSetCurVolume(char *dev, void *img);
void cvFsSetDefVol(char *dev, char *vol);
void cvfs_add_device_prefix(char *dev, char *file);
void *cvfs_alloc_handle(void);
void cvfs_error(const char *msg);
char *cvfs_get_default_device(char *dev);
void cvfs_split_path(char *dev, char *file, char *path);
s32 find_803CF958(char *s, s32 len);
}
// --- end of C functions

#endif
