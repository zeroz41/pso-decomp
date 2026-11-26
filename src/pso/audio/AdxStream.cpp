#include <string.h>
#include "pso/audio/AdxError.h"
#include "pso/audio/AdxLock.h"
#include <dolphin/os/OSThread.h>
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/AdxStream.h"
#include "pso/system/CvFsStreamHandle.h"
#include "pso/network/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/audio/CriSvm.h"
#include "pso/system/CvFs.h"

extern "C" {
s32 lbl_805D7550;
s32 tlobby_stream_read_retry_limit;
s32 lbl_805D7558;
}

extern "C" {
s32 adx_stream_request_count_ex = 0x10;
s32 adx_stream_request_base_index = 0x10;
s32 adx_stream_fname_slot_count = 0x18;
static const char lbl_8047C600[] = "E00041205 ADXSTM_OpenFnameRangeExRt: can't open ";
static const char lbl_8047C634[] = "E00041205 ADXSTM_OpenFnameEx: can't open ";
static const char lbl_8047C660[] = "E0041206 ADXSTM_OpenFnameRang: can't open ";

void set_adx_stream_base_offset(AdxStreamFile *file, s32 offset) {
    file->base_offset = offset;
    cvFsSeek(file->handle, file->base_offset, 0);
    cvFsTell(file->handle);
}

void set_adx_stream_size_sectors(AdxStreamFile *file, s32 sectors) {
    file->size = sectors << 11;
}

void set_adx_stream_buffer(AdxStreamFile *file, SjRingBuffer *buffer) {
    file->buffer = buffer;
    s32 available = buffer->interface->get_available(buffer, 0);
    file->read_chunk_size = available;
    file->read_threshold = available;
}

s32 get_adx_stream_size(AdxStreamFile *file) {
    return file->size;
}

s32 set_adx_max_read_sectors(AdxStreamFile *file, s32 sectors) {
    file->max_read_sectors = sectors;
    return 1;
}

s32 adxstm_set_read_range(AdxStreamFile *file, s32 threshold, s32 chunk_size) {
    file->read_threshold = threshold;
    file->read_chunk_size = chunk_size;
    return 1;
}

s32 get_adx_threshold_and_chunk(AdxStreamFile *file, s32 *threshold, s32 *chunk_size) {
    *threshold = file->read_threshold;
    *chunk_size = file->read_chunk_size;
    return 1;
}

s32 get_adx_stream_position(const AdxStreamFile *file, s32 *position) {
    s32 offset;
    CvFsHandle *handle = file->handle;
    if (handle != NULL) {
        offset = cvFsTell(handle) - file->base_offset;
    } else {
        offset = 0;
    }
    *position = offset - file->start_position;
    return 1;
}

static inline s32 get_stream_position(AdxStreamFile *file) {
    if (file->handle != NULL) {
        return cvFsTell(file->handle) - file->base_offset;
    }
    return 0;
}
}

void update_active_stream_reads(void) {
    AdxStreamFile *requests = adx_stream_read_requests;
    s32 index = 0;
    do {
        if ((s32)(u8)requests[index].used == 1 && (s32)(u8)requests[index].stat == 2) {
            update_adx_stream_read(&requests[index]);
        }
        index++;
    } while (index < 40);
}
extern "C" {

void update_adx_stream_read(AdxStreamFile *file) {
    SjChunk a;
    SjChunk b;
    SjRingBuffer *stream = file->buffer;
    s32 n;
    s32 m;
    s32 r;

    if (file->read_pending == 1) {
        r = cvFsGetStat(file->handle);
        if (r == 1) {
            n = file->sectors_read << 11;
            sj_chunk_split(&file->pending_read, n, &a, &b);
            stream->interface->put_chunk(stream, 1, &a);
            stream->interface->unget_chunk(stream, 0, &b);
            if (file->sectors == get_stream_position(file) && file->on_completion != NULL) {
                file->on_completion(file->completion_context);
            }
            file->field34 += n;
            file->read_pending = 0;
            if (get_stream_position(file) >= (file->size + 0x7FF) / 2048) {
                file->stat = 3;
            }
            file->retry = 0;
        } else if (r == 3) {
            stream->interface->unget_chunk(stream, 0, &file->pending_read);
            if (tlobby_stream_read_retry_limit >= 0) {
                if (file->retry >= tlobby_stream_read_retry_limit) {
                    file->stat = 4;
                } else {
                    file->retry++;
                }
            }
            file->read_pending = 0;
        }
    }
    if (file->read_pending == 0) {
        if (stream == NULL || stream->interface == NULL) {
            lbl_805D7558++;
            return;
        }
        if (stream->interface->get_available(stream, 1) < file->read_threshold) {
            s32 e;
            s32 c;
            stream->interface->get_chunk(stream, 0, file->read_chunk_size, &file->pending_read);
            e = file->sectors;
            n = file->pending_read.size / 2048;
            m = e - get_stream_position(file);
            if (n < m) {
                m = n;
            }
            c = file->max_read_sectors;
            if (m < c) {
                c = m;
            }
            if (c == 0) {
                stream->interface->unget_chunk(stream, 0, &file->pending_read);
                return;
            }
            file->sectors_read = cvFsReqRd(file->handle, c, file->pending_read.data);
            if (file->sectors_read <= 0) {
                stream->interface->unget_chunk(stream, 0, &file->pending_read);
                if (cvFsGetStat(file->handle) == 3 && tlobby_stream_read_retry_limit >= 0) {
                    if (file->retry >= tlobby_stream_read_retry_limit) {
                        file->stat = 4;
                    } else {
                        file->retry++;
                    }
                }
            } else {
                file->read_pending = 1;
            }
        }
    }
}

void set_adx_stream_end_sector(AdxStreamFile *file, s32 sector) {
    if (sector >= 0) {
        file->sectors = sector;
        return;
    }
    file->sectors = (file->size + 0x7FF) / 2048;
}

void set_adx_stream_completion(AdxStreamFile *file, AdxStreamCompletion callback, void *context) {
    file->on_completion = callback;
    file->completion_context = context;
}

void stop_adx_stream(AdxStreamFile *file) {
    file->stat = 1;
    adx_lock();
    CvFsHandle *handle = file->handle;
    if (handle != NULL) {
        cvFsStopTr(handle);
        file->read_pending = 0;
    }
    adx_unlock();
}

static inline s32 get_pos_803C8A14(AdxStreamFile *s) {
    if (s->handle != 0) {
        return cvFsTell(s->handle) - s->base_offset;
    }
    return 0;
}
s32 init_adx_stream_position(AdxStreamFile *file) {
    if (file->size == 0) {
        file->field34 = 0;
        file->start_position = 0;
        file->stat = 3;
    } else {
        file->stat = 2;
        file->field34 = 0;
        file->start_position = get_pos_803C8A14(file);
        file->retry = 0;
    }
    return 1;
}

s32 get_adx_stream_file_offset(AdxStreamFile *file) {
    CvFsHandle *handle = file->handle;
    if (handle != NULL) {
        return cvFsTell(handle) - file->base_offset;
    }
    return 0;
}

s32 seek_adx_stream_sector(AdxStreamFile *file, s32 offset) {
    cvFsSeek(file->handle, file->base_offset + offset, 0);
    return cvFsTell(file->handle) - file->base_offset;
}

s32 get_adx_stream_status(const AdxStreamFile *file) {
    return file->stat;
}

void adxstm_close(AdxStreamFile *file) {
    if (file != NULL) {
        file->stat = 1;
        adx_lock();
        CvFsHandle *handle = file->handle;
        if (handle != NULL) {
            cvFsStopTr(handle);
            file->read_pending = 0;
        }
        adx_unlock();
        handle = file->handle;
        if (handle != NULL) {
            cvFsClose(handle);
        }
        memset(file, 0, sizeof(*file));
    }
}

inline AdxStreamFile *alloc_803C8BAC(s32 arg, CvFsHandle *h, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_request_count_ex; i++) {
        p = &adx_stream_read_requests[lbl_805D7550 + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_request_count_ex) {
        return NULL;
    }
    p->stat = 1;
    p->read_pending = 0;
    p->arg = arg;
    p->handle = h;
    p->start_position = 0;
    p->base_offset = 0;
    p->size = size;
    p->max_read_sectors = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *ADXSTM_OpenFnameEx(const char *name, s32 arg) {
    s32 size;
    CvFsHandle *h;
    AdxStreamFile *p;
    size = cvFsGetFileSize(name);
    h = cvFsOpen(name, 0, 0);
    if (h == 0) {
        adxerr_report_pair(lbl_8047C634, name);
        return NULL;
    }
    p = alloc_803C8BAC(arg, h, size);
    if (p != NULL) {
        cvFsSeek(p->handle, p->base_offset, 0);
        cvFsTell(p->handle);
    }
    return p;
}

inline AdxStreamFile *alloc_803C8CDC(s32 arg, CvFsHandle *h, s32 base_offset, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_fname_slot_count; i++) {
        p = &adx_stream_read_requests[adx_stream_request_base_index + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_fname_slot_count) {
        return NULL;
    }
    p->stat = 1;
    p->read_pending = 0;
    p->arg = arg;
    p->handle = h;
    p->start_position = 0;
    p->base_offset = base_offset;
    p->size = size;
    p->max_read_sectors = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *adxstm_open_fname_attr(const char *name, s32 mode, s32 arg) {
    s32 size;
    CvFsHandle *h;
    AdxStreamFile *p;
    if (mode == 0) {
        size = cvFsGetFileSize(name);
    } else {
        size = cvFsGetFileSizeEx(name, mode);
    }
    h = cvFsOpen(name, mode, 0);
    if (h == 0) {
        adxerr_report_pair(lbl_8047C634, name);
        return NULL;
    }
    p = alloc_803C8CDC(arg, h, 0, size);
    if (p != NULL) {
        cvFsSeek(p->handle, p->base_offset, 0);
        cvFsTell(p->handle);
    }
    return p;
}

inline AdxStreamFile *alloc_803C8E28(saddr arg, CvFsHandle *h, s32 base_offset, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_request_count_ex; i++) {
        p = &adx_stream_read_requests[lbl_805D7550 + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_request_count_ex) {
        return NULL;
    }
    p->stat = 1;
    p->read_pending = 0;
    p->arg = arg;
    p->handle = h;
    p->start_position = 0;
    p->base_offset = base_offset;
    p->size = size;
    p->max_read_sectors = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *ADXSTM_OpenFnameRangeExRt(const char *name, s32 mode, s32 off, s32 nsect, saddr arg) {
    CvFsHandle *h;
    AdxStreamFile *p;
    h = cvFsOpen(name, mode, 0);
    if (h == 0) {
        adxerr_report_pair(lbl_8047C600, name);
        return NULL;
    }
    p = alloc_803C8E28(arg, h, off, nsect << 11);
    if (p != NULL) {
        cvFsSeek(p->handle, p->base_offset, 0);
        cvFsTell(p->handle);
    }
    return p;
}

inline AdxStreamFile *alloc_803C8F5C(s32 arg, CvFsHandle *h, s32 base_offset, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_fname_slot_count; i++) {
        p = &adx_stream_read_requests[adx_stream_request_base_index + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_fname_slot_count) {
        return NULL;
    }
    p->stat = 1;
    p->read_pending = 0;
    p->arg = arg;
    p->handle = h;
    p->start_position = 0;
    p->base_offset = base_offset;
    p->size = size;
    p->max_read_sectors = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *ADXSTM_OpenFnameRange(const char *name, s32 mode, s32 off, s32 nsect, s32 arg) {
    CvFsHandle *h;
    AdxStreamFile *p;
    h = cvFsOpen(name, mode, 0);
    if (h == 0) {
        adxerr_report_pair(lbl_8047C660, name);
        return NULL;
    }
    p = alloc_803C8F5C(arg, h, off, nsect << 11);
    if (p != NULL) {
        cvFsSeek(p->handle, p->base_offset, 0);
        cvFsTell(p->handle);
    }
    return p;
}

void adxstm_finish_fs() {
    cvFsFinish();
}

s32 adxstm_clear_requests() {
    memset(adx_stream_read_requests, 0, sizeof(adx_stream_read_requests));
    return 1;
}

}

AdxStreamFile adx_stream_read_requests[40];
