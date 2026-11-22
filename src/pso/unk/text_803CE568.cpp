#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/system/CvFsStreamHandle.h"
#include "pso/unk/text_803CE568.h"
#include "pso/unk/TLobby.h"


struct Ent_803CF958 { CvFsDeviceInterface *device; char name[12]; };

struct CvFsHandle {
    CvFsDeviceInterface *vtbl;
    void *fd;
};

extern "C" {
extern s8 fs_default_device_name[];
extern Ent_803CF958 cvfs_entry_table[];
s32 lbl_805D7600;
u32 lbl_80581A30[75];
// CVFS version banner: the first string of this file's pool (0x8047CF30).
char *const volatile lbl_805E0DA0 = "\nCVFS/GC Ver.2.24 Build:Jun 13 2002 19:00:27\n";
s8 fs_default_device_name[12];
Ent_803CF958 cvfs_entry_table[32];
CvFsHandle si_type_info_table[40];
extern const char lbl_805E0DA4[6] = "%s:%s";

inline void cvfs_split_path(char *dev, char *file, char *path) {
    s32 i;
    s32 j;
    if (path == NULL) {
        return;
    }
    for (i = 0; i < 297; i++) {
        if (path[i] == ':' || path[i] == '\0') {
            break;
        }
        dev[i] = path[i];
    }
    if (path[i] == '\0') {
        dev[i] = '\0';
        memcpy(file, dev, strlen(dev) + 1);
        dev[0] = '\0';
    } else {
        u32 k;
        u32 n;
        dev[i] = '\0';
        i++;
        if (i == 2) {
            i = 0;
            dev[0] = '\0';
        }
        for (j = i; j < 297; j++) {
            if (path[j] == '\0') {
                break;
            }
            file[j - i] = path[j];
        }
        file[j - i] = '\0';
        n = strlen(dev) + 1;
        for (k = 0; k < n; k++) {
            if (dev[k] >= 'a' && dev[k] <= 'z') {
                dev[k] -= 0x20;
            }
        }
    }
}

// Copies the default device name into dev and returns dev (like strcpy).
inline char *cvfs_get_default_device(char *dev) {
    s32 len = strlen((const char *)fs_default_device_name);
    if (fs_default_device_name[0] == '\0') {
        dev[0] = '\0';
    } else {
        memcpy(dev, fs_default_device_name, len + 1);
    }
    return dev;
}

inline CvFsDeviceInterface *cvfs_lookup_device(char *name) {
    u32 i;
    s32 len = strlen(name);
    for (i = 0; i < 32; i++) {
        if (strncmp(name, cvfs_entry_table[i].name, len) == 0) {
            return cvfs_entry_table[i].device;
        }
    }
    return NULL;
}

inline void cvfs_add_device_prefix(char *dev, char *file) {
    CvFsDeviceInterface *vtbl;
    s32 need;
    if (dev == NULL) {
        dev = (char *)fs_default_device_name;
    }
    vtbl = cvfs_lookup_device(dev);
    if (vtbl == NULL) {
        need = 0;
    } else if (vtbl->query != NULL) {
        need = vtbl->query(0, 100, 0, 0);
    } else {
        need = 0;
    }
    if (need == 1) {
        strcpy((char *)lbl_80581A30, file);
        sprintf(file, lbl_805E0DA4, dev, (char *)lbl_80581A30);
    }
}

inline CvFsDeviceInterface *cvfs_get_device(char *dev, char *file, char *path) {
    CvFsDeviceInterface *vtbl;
    if (dev[0] == '\0') {
        dev = cvfs_get_default_device(dev);
        if (dev[0] == '\0') {
            return NULL;
        }
    }
    cvfs_add_device_prefix(dev, file);
    vtbl = cvfs_lookup_device(dev);
    if (vtbl == NULL) {
        cvfs_get_default_device(dev);
        vtbl = cvfs_lookup_device(dev);
        if (vtbl == NULL) {
            return NULL;
        }
        strcpy(file, path);
    }
    return vtbl;
}

inline void *cvfs_alloc_handle(void) {
    s32 i;
    CvFsHandle *h;
    for (i = 0; i < 40; i++) {
        if (si_type_info_table[i].fd == NULL) {
            break;
        }
    }
    h = &si_type_info_table[i];
    if (i == 40) {
        h = NULL;
    }
    return h;
}

inline void cvfs_free_handle(CvFsHandle *h) {
    h->fd = NULL;
    h->vtbl = NULL;
}

// cvFsInit: dead-stripped. cvFsFinish below undoes it (it decrements the init count, which no
// surviving code increments); this mirror of it is a reconstruction.
void cvFsInit(void) {
    CvFsHandle *h;
    s32 i;

    if (lbl_805D7600++ == 0) {
        for (h = si_type_info_table, i = 0; i < 40; i++, h++) {
            h->vtbl = NULL;
            h->fd = NULL;
        }
        for (i = 0; i < 32; i++) {
            cvfs_entry_table[i].name[0] = 0;
        }
        memset(fs_default_device_name, 0, 9);
    }
}

// The functions below were dead-stripped by the linker; only their error strings survive, in this
// order, at the head of the file's string pool (0x8047CF60-0x8047D67C). Minimal bodies that report
// those strings keep the pool offsets of the functions that remain.
inline void cvfs_error(const char *msg) {
    if (cvfs_completion_callback != NULL) {
        cvfs_completion_callback(lbl_805D75FC, msg, 0);
    }
}

void cvFsSetDefVol(char *dev, char *vol) {
    if (dev == NULL) {
        cvfs_error("cvFsSetDefVol #1:illegal device name");
    } else if (vol == NULL) {
        cvfs_error("cvFsSetDefVol #2:illegal volume name");
    } else {
        cvfs_error("cvFsSetDefVol #3:device not found");
    }
}

s32 cvFsGetVolumeInfo(char *dev, char *vol, void *info) {
    if (dev == NULL) {
        cvfs_error("cvFsGetVolumeInfo #1:illegal device name");
    } else if (vol == NULL) {
        cvfs_error("cvFsGetVolumeInfo #2:illegal volume name");
    } else {
        cvfs_error("cvFsGetVolumeInfo #3:device not found");
    }
    return 0;
}

s32 cvFsDelVolume(char *dev, char *vol) {
    if (dev == NULL) {
        cvfs_error("cvFsDelVolume #1:illegal device name");
    } else if (vol == NULL) {
        cvfs_error("cvFsDelVolume #2:illegal volume name");
    } else {
        cvfs_error("cvFsDelVolume #3:device not found");
    }
    return 0;
}

s32 cvFsAddVolume(char *dev, char *vol, void *img) {
    if (dev == NULL) {
        cvfs_error("cvFsAddVolume #1:illegal device name");
    } else if (vol == NULL) {
        cvfs_error("cvFsAddVolume #2:illegal volume name");
    } else if (img == NULL) {
        cvfs_error("cvFsAddVolume #3:illegal image handle");
    } else {
        cvfs_error("cvFsAddVolume #3:device not found");
    }
    return 0;
}

s32 cvFsSetCurVolume(char *dev, void *img) {
    if (dev == NULL) {
        cvfs_error("cvFsSetCurVolume #1:illegal device name");
    } else if (img == NULL) {
        cvfs_error("cvFsSetCurVolume #2:illegal image handle");
    } else {
        cvfs_error("cvFsSetCurVolume #3:device not found");
    }
    return 0;
}

s32 cvFsOptFn2(CvFsHandle *fd) {
    if (fd == NULL) {
        cvfs_error("cvFsOptFn2 #1:handle error");
    } else {
        cvfs_error("cvFsOptFn2 #2:vtbl error");
    }
    return 0;
}

s32 cvFsOptFn1(CvFsHandle *fd) {
    if (fd == NULL) {
        cvfs_error("cvFsOptFn1 #1:handle error");
    } else {
        cvfs_error("cvFsOptFn1 #2:vtbl error");
    }
    return 0;
}

char *cvFsGetDevName(CvFsHandle *fd) {
    cvfs_error("cvFsGetDevName #1:vtbl error");
    return NULL;
}

s32 cvFsDeleteFile(char *path) {
    if (path == NULL) {
        cvfs_error("cvFsDeleteFile #1:illegal file name");
    } else if (path[0] == '\0') {
        cvfs_error("cvFsDeleteFile #2:illegal device name");
    } else if (cvfs_lookup_device(path) == NULL) {
        cvfs_error("cvFsDeleteFile #3:device not found");
    } else {
        cvfs_error("cvFsDeleteFile #4:vtbl error");
    }
    return 0;
}

s32 cvFsRemoveDir(char *path) {
    if (path == NULL) {
        cvfs_error("cvFsRemoveDir #1:illegal directory name");
    } else if (path[0] == '\0') {
        cvfs_error("cvFsRemoveDir #2:illegal device name");
    } else if (cvfs_lookup_device(path) == NULL) {
        cvfs_error("cvFsRemoveDir #3:device not found");
    } else {
        cvfs_error("cvFsRemoveDir #4:vtbl error");
    }
    return 0;
}

s32 cvFsMakeDir(char *path) {
    if (path == NULL) {
        cvfs_error("cvFsMakeDir #1:illegal directory name");
    } else if (path[0] == '\0') {
        cvfs_error("cvFsMakeDir #2:illegal device name");
    } else if (cvfs_lookup_device(path) == NULL) {
        cvfs_error("cvFsMakeDir #3:device not found");
    } else {
        cvfs_error("cvFsMakeDir #4:vtbl error");
    }
    return 0;
}

s32 cvFsGetMaxByteRate(CvFsHandle *fd) {
    if (fd == NULL) {
        cvfs_error("cvFsGetMaxByteRate #1:handle error");
    } else {
        cvfs_error("cvFsGetMaxByteRate #2:vtbl error");
    }
    return 0;
}

s32 cvFsIsExistFile(char *path) {
    if (path == NULL) {
        cvfs_error("cvFsIsExistFile #2:illegal device name");
    } else if (path[0] == '\0') {
        cvfs_error("cvFsIsExistFile #1:illegal file name");
    } else if (cvfs_lookup_device(path) == NULL) {
        cvfs_error("cvFsIsExistFile #3:device not found");
    } else {
        cvfs_error("cvFsIsExistFile #4:vtbl error");
    }
    return 0;
}

s32 cvFsChangeDir(char *path) {
    if (path == NULL) {
        cvfs_error("cvFsChangeDir #1:illegal directory name");
    } else if (path[0] == '\0') {
        cvfs_error("cvFsChangeDir #2:illegal device name");
    } else if (cvfs_lookup_device(path) == NULL) {
        cvfs_error("cvFsChangeDir #3:device not found");
    } else {
        cvfs_error("cvFsChangeDir #4:vtbl error");
    }
    return 0;
}

s32 cvFsGetNumTr(CvFsHandle *fd) {
    if (fd == NULL) {
        cvfs_error("cvFsGetNumTr #1:handle error");
    } else {
        cvfs_error("cvFsGetNumTr #2:vtbl error");
    }
    return 0;
}

void cvFsSetSctLen(CvFsHandle *fd, s32 len) {
    if (fd == NULL) {
        cvfs_error("cvFsSetSctLen #3:handle error");
    } else {
        cvfs_error("cvFsSetSctLen #4:vtbl error");
    }
}

s32 cvFsGetSctLen(CvFsHandle *fd) {
    if (fd == NULL) {
        cvfs_error("cvFsGetSctLen #1:handle error");
    } else {
        cvfs_error("cvFsGetSctLen #2:vtbl error");
    }
    return 0;
}

s32 cvFsGetFreeSize(char *dev) {
    if (cvfs_lookup_device(dev) == NULL) {
        cvfs_error("cvFsGetFreeSize #5:device not found");
    } else {
        cvfs_error("cvFsGetFreeSize #6:vtbl error");
    }
    return 0;
}

s32 cvFsGetFileSizeEx(const char *name, s32 arg) {
    char *path = const_cast<char *>(name);
    char dev[300];
    char file[300];
    CvFsDeviceInterface *vtbl;

    if (path == NULL) {
        cvfs_error("cvFsGetFileSizeEx #1:illegal file name");
        return 0;
    }
    cvfs_split_path(dev, file, path);
    if (file[0] == '\0') {
        cvfs_error("cvFsGetFileSizeEx #1:illegal file name");
        return 0;
    }
    vtbl = cvfs_get_device(dev, file, path);
    if (dev == NULL) {
        cvfs_error("cvFsGetFileSizeEx #2:illegal device name");
    }
    if (vtbl == NULL) {
        cvfs_error("cvFsGetFileSizeEx #3:device not found");
    }
    if (vtbl->get_file_size_ex != NULL) {
        return vtbl->get_file_size_ex(file, arg);
    }
    cvfs_error("cvFsGetFileSizeEx #4:vtbl error");
    return 0;
}
s32 cvFsGetFileSize(const char *name) {
    char *path = const_cast<char *>(name);
    char dev[300];
    char file[300];
    CvFsDeviceInterface *vtbl;

    if (path == NULL) {
        cvfs_error("cvFsGetFileSize #1:illegal file name");
        return 0;
    }
    cvfs_split_path(dev, file, path);
    if (file[0] == '\0') {
        cvfs_error("cvFsGetFileSize #1:illegal file name");
        return 0;
    }
    vtbl = cvfs_get_device(dev, file, path);
    if (dev == NULL) {
        cvfs_error("cvFsGetFileSize #2:illegal device name");
    }
    if (vtbl == NULL) {
        cvfs_error("cvFsGetFileSize #3:device not found");
    }
    if (vtbl->get_file_size != NULL) {
        return vtbl->get_file_size(file);
    }
    cvfs_error("cvFsGetFileSize #4:vtbl error");
    return 0;
}

s32 cvFsGetStat(CvFsHandle *handle) {
    s32 (*operation)(void *);
    s32 var_r31;
    var_r31 = 3;
    if (handle == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsGetStat #1:handle error", 0);
        }
        return 3;
    }
    operation = handle->vtbl->get_status;
    if (operation != NULL) {
        var_r31 = operation(handle->fd);
    } else if (cvfs_completion_callback != NULL) {
        cvfs_completion_callback(lbl_805D75FC, "cvFsGetStat #2:vtbl error", 0);
    }
    return var_r31;
}

void TLobby__sub_803CEF60(void) {
    s32 i;
    Ent_803CF958 *p;
    for (i = 0; i < 0x20; i++) {
        p = &cvfs_entry_table[i];
        if (p->device != NULL && p->device->exec_server != 0) {
            p->device->exec_server();
        }
    }
}

void cvFsStopTr(CvFsHandle *handle) {
    void (*operation)(void *);
    if (handle == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsStopTr #1:handle error", 0);
        }
    } else {
        operation = handle->vtbl->stop_transfer;
        if (operation != NULL) {
            operation(handle->fd);
            return;
        }
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsStopTr #2:vtbl error", 0);
        }
    }
}

// Dead-stripped (see above); keeps "cvFsReqWr" strings between cvFsStopTr's and cvFsReqRd's.
s32 cvFsReqWr(CvFsHandle *fd, s32 nsct, void *buf) {
    if (fd == NULL) {
        cvfs_error("cvFsReqWr #1:handle error");
    } else {
        cvfs_error("cvFsReqWr #2:vtbl error");
    }
    return 0;
}

s32 cvFsReqRd(CvFsHandle *handle, s32 sector_count, void *buffer) {
    s32 (*operation)(void *, s32, void *);
    s32 var_r31;
    if (handle == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsReqRd #1:handle error", 0);
        }
        return 0;
    }
    operation = handle->vtbl->request_read;
    if (operation != NULL) {
        var_r31 = operation(handle->fd, sector_count, buffer);
    } else {
        var_r31 = 0;
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsReqRd #2:vtbl error", 0);
        }
    }
    return var_r31;
}

s32 cvFsSeek(CvFsHandle *handle, s32 sector, s32 origin) {
    s32 (*operation)(void *, s32, s32);
    s32 var_r31;
    if (handle == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsSeek #1:handle error", 0);
        }
        return 0;
    }
    operation = handle->vtbl->seek;
    if (operation != NULL) {
        var_r31 = operation(handle->fd, sector, origin);
    } else {
        var_r31 = 0;
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsSeek #2:vtbl error", 0);
        }
    }
    return var_r31;
}

s32 cvFsTell(CvFsHandle *handle) {
    s32 (*operation)(void *);
    s32 var_r31;
    if (handle == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsTell #1:handle error", 0);
        }
        return 0;
    }
    operation = handle->vtbl->tell;
    if (operation != NULL) {
        var_r31 = operation(handle->fd);
    } else {
        var_r31 = 0;
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsTell #2:vtbl error", 0);
        }
    }
    return var_r31;
}
void cvFsClose(CvFsHandle *handle) {
    void (*operation)(void *);
    if (handle == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsClose #1:handle error", 0);
        }
    } else {
        operation = handle->vtbl->close;
        if (operation != NULL) {
            operation(handle->fd);
            handle->fd = NULL;
            handle->vtbl = NULL;
            return;
        }
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsClose #2:vtbl error", 0);
        }
    }
}
CvFsHandle *cvFsOpen(const char *name, s32 mode, s32 arg) {
    char *path = const_cast<char *>(name);
    char dev[300];
    char file[300];
    CvFsDeviceInterface *vtbl;
    CvFsHandle *h;

    if (path == NULL) {
        cvfs_error("cvFsOpen #1:illegal file name");
        return NULL;
    }
    cvfs_split_path(dev, file, path);
    if (file[0] == '\0') {
        cvfs_error("cvFsOpen #1:illegal file name");
        return NULL;
    }
    h = (CvFsHandle *)cvfs_alloc_handle();
    if (h == NULL) {
        cvfs_error("cvFsOpen #3:failed handle alloced");
        return NULL;
    }
    vtbl = cvfs_get_device(dev, file, path);
    h->vtbl = vtbl;
    if (dev == NULL) {
        cvfs_free_handle(h);
        cvfs_error("cvFsOpen #2:illegal device name");
        return NULL;
    }
    if (h->vtbl == NULL) {
        cvfs_free_handle(h);
        cvfs_error("cvFsOpen #4:device not found");
        return NULL;
    }
    if (h->vtbl->open != NULL) {
        h->fd = h->vtbl->open(file, mode, arg);
    } else {
        cvfs_free_handle(h);
        cvfs_error("cvFsOpen #5:vtbl error");
        return NULL;
    }
    if (h->fd == NULL) {
        cvfs_free_handle(h);
        cvfs_error("cvFsOpen #6:open failed");
        return NULL;
    }
    return h;
}
inline s32 find_803CF958(char *s, s32 len) {
    Ent_803CF958 *p;
    s32 i;
    for (p = cvfs_entry_table, i = 0; i < 32; i++, p++) {
        if (strncmp(s, p->name, len) == 0) {
            return 1;
        }
    }
    return 0;
}
void cvFsSetDefDev(char *src) {
    s32 len;
    u32 j;
    u32 n;
    if (src == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsSetDefDev #1:illegal device name", 0);
        }
        return;
    }
    len = strlen(src);
    if (len == 0) {
        fs_default_device_name[0] = 0;
        return;
    }
    n = strlen(src) + 1;
    for (j = 0; j < n; j++) {
        if (src[j] >= 'a' && src[j] <= 'z') {
            src[j] -= 0x20;
        }
    }
    if (find_803CF958(src, len) == 1) {
        memcpy(fs_default_device_name, src, len + 1);
        return;
    }
    if (cvfs_completion_callback != NULL) {
        cvfs_completion_callback(lbl_805D75FC, "cvFsSetDefDev #2:unknown device name", 0);
    }
}

// Dead-stripped (see above); keeps its string between cvFsSetDefDev's and cvFsAddDev's.
void cvFsDelDev(char *dev) {
    if (dev == NULL) {
        cvfs_error("cvFsDelDev #1:illegal device name");
    }
}

inline CvFsDeviceInterface *cvfs_find_device_if(char *s, s32 len) {
    Ent_803CF958 *p;
    u32 i;
    for (p = cvfs_entry_table, i = 0; i < 32; i++, p++) {
        if (strncmp(s, p->name, len) == 0) {
            return cvfs_entry_table[i].device;
        }
    }
    return 0;
}

inline CvFsDeviceInterface *cvfs_add_device(char *name, CvFsDeviceInterface *dev) {
    s32 k;
    if (cvfs_find_device_if(name, strlen(name)) != 0) {
        return dev;
    }
    for (k = 0; k < 32; k++) {
        if (cvfs_entry_table[k].name[0] == 0) {
            break;
        }
    }
    if (k == 32) {
        return NULL;
    }
    cvfs_entry_table[k].device = dev;
    memcpy(cvfs_entry_table[k].name, name, strlen(name) + 1);
    return dev;
}
void cvFsAddDev(char *name, CvFsDeviceFactory getif, s32 arg) {
    CvFsDeviceInterface *dev;
    u32 n;
    u32 i;
    lbl_805E0DA0;
    if (name == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsAddDev #1:illegal device name", 0);
        }
        return;
    }
    if (getif == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsAddDev #2:illegal I/F func name", 0);
        }
        return;
    }
    n = strlen(name) + 1;
    for (i = 0; i < n; i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= 0x20;
        }
    }
    dev = cvfs_add_device(name, getif());
    if (dev == NULL) {
        if (cvfs_completion_callback != NULL) {
            cvfs_completion_callback(lbl_805D75FC, "cvFsAddDev #3:failed added a device", 0);
        }
        return;
    }
    if (dev->set_error_callback != NULL) {
        dev->set_error_callback(cvfs_forward_error, 0);
    }
}


void cvFsFinish(void) {
    CvFsHandle *h;
    s32 i;

    if (--lbl_805D7600 == 0) {
        for (h = si_type_info_table, i = 0; i < 40; i++, h++) {
            if (h->vtbl != NULL) {
                h->vtbl->close(h->fd);
            }
            h->vtbl = NULL;
            h->fd = NULL;
        }
        for (i = 0; i < 32; i++) {
            cvfs_entry_table[i].name[0] = 0;
        }
        memset(fs_default_device_name, 0, 9);
        ((s8 *)fs_default_device_name)[0] = 0;
    }
}

}
