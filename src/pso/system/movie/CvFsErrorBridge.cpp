#include "types.h"
#include "pso/system/movie/CvFsErrorBridge.h"
#include "pso/system/CvFs.h"

#include "pso/system/CvFsStreamHandle.h"

void cvfs_forward_error(s32, const char *message, void *handle) {
    if (cvfs_completion_callback != NULL) {
        cvfs_completion_callback(cvfs_completion_context, message, handle);
    }
}

void gcci_dvd_async_callback(s32, DVDFileInfo *) {
}
