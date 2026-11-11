#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803CBCA0.h"
#include "pso/unk/text_803D31A4.h"

struct Strm_803C8678;
struct StrmVt_803C8678 {
    void *pad[6];
    void (*read)(Strm_803C8678 *, s32, s32, void *);
    void (*release)(Strm_803C8678 *, s32, void *);
    void (*submit)(Strm_803C8678 *, s32, void *);
    s32 (*avail)(Strm_803C8678 *, s32);
};
struct Strm_803C8678 { StrmVt_803C8678 *vt; };
struct Pair_803C8678 { u32 a, b; };
struct S_803C8678 {
    u8 f0;
    s8 state;
    s8 busy;
    s8 retry;
    Strm_803C8678 *strm;
    u32 h;
    s32 fC;
    s32 base;
    s32 size;
    s32 f18;
    s32 f1C;
    s32 nread;
    s32 buf;
    s32 f28;
    s32 f2C;
    s32 end;
    s32 total;
    void (*cb)(s32);
    s32 cbarg;
};

struct S_803C8A14 {
    u8 f0;
    s8 state;
    u8 f2;
    s8 f3;
    u8 pad4[4];
    void *fp;
    s32 pos;
    s32 base;
    s32 f14;
    u8 pad18[0x34 - 0x18];
    s32 f34;
};

struct PointerRecords_803C8610_var_r31 { u8 bytes[0x40]; };

extern "C" {
s32 TLobby__sub_803D3130(void *, s32, Pair_803C8678 *, Pair_803C8678 *);
extern s32 tlobby_stream_read_retry_limit;
extern s32 lbl_805D7558;
s32 memset(void *, int, int);
}
void update_active_stream_reads(void);

struct RecoveredGlobal_803C90B0_lbl_80575140 {
    s32 value;
    u8 remaining[0x9FC];
};

struct AdxStreamFile {
    s8 used;
    s8 b1;
    s8 b2;
    u8 pad3;
    s32 arg;
    u32 handle;
    s32 fC;
    s32 f10;
    s32 size;
    u8 pad18[0x14];
    s32 f2C;
    s32 sectors;
    u8 pad34[0xC];
};

extern "C" {
void TLobby__sub_803C89C4(u8 *arg0);
void TLobby__sub_803C8B38(u8 *arg0);
s32 TLobby__sub_803C8B2C(u8 *arg0);
extern RecoveredGlobal_803C90B0_lbl_80575140 adx_stream_read_requests;
s32 TLobby__sub_803C85AC(u8 *arg0, s32 *arg1);
s32 cvFsGetFileSize(void);
u32 cvFsOpen(const char *, int, int);
extern char lbl_8047C634[];
extern s32 adx_stream_request_count_ex;
extern s32 lbl_805D7550;
AdxStreamFile *TLobby__sub_803C8BAC(const char *name, s32 arg);
s32 cvFsGetFileSizeEx(void);
extern s32 adx_stream_fname_slot_count;
extern s32 adx_stream_request_base_index;
AdxStreamFile *TLobby__sub_803C8CDC(const char *name, s32 mode, s32 arg);
extern char lbl_8047C600[];
AdxStreamFile *adxstm_open_fname_range_ex_rt__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, s32 arg);
extern char lbl_8047C660[];
AdxStreamFile *adxstm_open_fname_range__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, s32 arg);
void TLobby__sub_803C8514(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8578(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8594(u8 *arg0, s32 *arg1, s32 *arg2);
s32 set_range__6TLobbyFPvii(u8 *arg0, s32 arg1, s32 arg2);
void SIGetTypeAsync(void);

void TLobby::set_field_10_and_notify(s32 up) {
    *(s32 *)&this->m_up = up;
    ((TLobby *)(this->m_prev))->cv_fs_seek((int)this->m_up, 0);
    ((TLobby *)(this->m_prev))->cv_fs_tell();
}

void TLobby__sub_803C8514(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) (arg1 << 0xB);
}

void TLobby::set_buffer(void **flags) {
    s32 temp_r3;
    u8 *temp_r5;

    *(void ** *)&this->m_flags = flags;
    temp_r5 = (unsigned char *) (*flags);
    temp_r3 = (*(s32 (**)(void **, s32, void *))((s8 *)temp_r5 + 0x24))(flags, 0, temp_r5);
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = temp_r3;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = temp_r3;
}

s32 TLobby::get_field_14() {
    return *(s32 *)&this->m_down;
}

s32 TLobby__sub_803C8578(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x2C) = arg1;
    return 1;
}

s32 set_range__6TLobbyFPvii(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x18) = arg2;
    return 1;
}

s32 TLobby__sub_803C8594(u8 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = *(s32 *)((s8 *)arg0 + 0x1C);
    *arg2 = *(s32 *)((s8 *)arg0 + 0x18);
    return 1;
}

s32 TLobby__sub_803C85AC(u8 *arg0, s32 *arg1) {
    struct Fields_arg0 { u8 pad_0[8]; u8 * field_8; s32 field_C; s32 field_10; };
    s32 var_r4;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((Fields_arg0*)arg0)->field_8);
    if (temp_r3 != NULL) {
        var_r4 = ((TLobby *)temp_r3)->cv_fs_tell() - ((Fields_arg0*)arg0)->field_10;
    } else {
        var_r4 = 0;
    }
    *arg1 = var_r4 - ((Fields_arg0*)arg0)->field_C;
    return 1;
}

inline s32 pos_803C8678(S_803C8678 *s) {
    if (s->h != 0) {
        return ((TLobby *)(s->h))->cv_fs_tell() - s->base;
    }
    return 0;
}
}

void update_active_stream_reads(void) {
    s32 *var_r31;
    s32 var_r30;
    var_r31 = (s32 *)(((s32 *)&adx_stream_read_requests));
    var_r30 = 0;
    do {
        if (((s32) *(u8 *)((s8 *)((s32 *)&((PointerRecords_803C8610_var_r31 *)var_r31)[var_r30]) + 0) == 1) && ((s32) *(u8 *)((s8 *)((s32 *)&((PointerRecords_803C8610_var_r31 *)var_r31)[var_r30]) + 1) == 2)) {
            ((TLobby *)((s32 *)&((PointerRecords_803C8610_var_r31 *)var_r31)[var_r30]))->update_stream_read();
        }
        var_r30 += 1;
    } while (var_r30 < 0x28);
}
extern "C" {

void TLobby::update_stream_read() {
    S_803C8678 *s = (S_803C8678 *)this;
    Pair_803C8678 a;
    Pair_803C8678 b;
    Strm_803C8678 *st = s->strm;
    s32 n;
    s32 m;
    s32 r;

    if (s->busy == 1) {
        r = ((TLobby *)(s->h))->cv_fs_get_stat();
        if (r == 1) {
            n = s->nread << 11;
            TLobby__sub_803D3130(&s->buf, n, &a, &b);
            st->vt->submit(st, 1, &a);
            st->vt->release(st, 0, &b);
            if (s->end == pos_803C8678(s) && s->cb != NULL) {
                s->cb(s->cbarg);
            }
            s->total += n;
            s->busy = 0;
            if (pos_803C8678(s) >= (s->size + 0x7FF) / 2048) {
                s->state = 3;
            }
            s->retry = 0;
        } else if (r == 3) {
            st->vt->release(st, 0, &s->buf);
            if (tlobby_stream_read_retry_limit >= 0) {
                if (s->retry >= tlobby_stream_read_retry_limit) {
                    s->state = 4;
                } else {
                    s->retry++;
                }
            }
            s->busy = 0;
        }
    }
    if (s->busy == 0) {
        if (st == NULL || st->vt == NULL) {
            lbl_805D7558++;
            return;
        }
        if (st->vt->avail(st, 1) < s->f1C) {
            s32 e;
            s32 c;
            st->vt->read(st, 0, s->f18, &s->buf);
            e = s->end;
            n = s->f28 / 2048;
            m = e - pos_803C8678(s);
            if (n < m) {
                m = n;
            }
            c = s->f2C;
            if (m < c) {
                c = m;
            }
            if (c == 0) {
                st->vt->release(st, 0, &s->buf);
                return;
            }
            s->nread = ((TLobby *)(s->h))->cv_fs_req_rd(c, s->buf);
            if (s->nread <= 0) {
                st->vt->release(st, 0, &s->buf);
                if (((TLobby *)(s->h))->cv_fs_get_stat() == 3 && tlobby_stream_read_retry_limit >= 0) {
                    if (s->retry >= tlobby_stream_read_retry_limit) {
                        s->state = 4;
                    } else {
                        s->retry++;
                    }
                }
            } else {
                s->busy = 1;
            }
        }
    }
}

void TLobby::set_scroll_position(s32 arg1) {
    if (arg1 >= 0) {
        *(s32 *)((s8 *)((u8 *)this) + 0x30) = arg1;
        return;
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = (s32) ((s32) (*(s32 *)&this->m_down + 0x7FF) / 2048);
}

void TLobby::set_coords(s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)((u8 *)this) + 0x38) = arg1;
    *(s32 *)((s8 *)((u8 *)this) + 0x3C) = arg2;
}

void TLobby__sub_803C89C4(u8 *arg0) {
    u8 *lobby;
    *(s8 *)((s8 *)arg0 + 1) = 1;
    TLobby::init_once();
    lobby = (u8 *)(*(u8 **)((s8 *)arg0 + 8));
    if (lobby != NULL) {
        ((TLobby *)lobby)->cvfs_stop_tr();
        *(s8 *)((s8 *)arg0 + 2) = 0;
    }
    TLobby::release_ref();
}

static inline s32 get_pos_803C8A14(S_803C8A14 *s) {
    if (s->fp != NULL) {
        return ((TLobby *)((int)s->fp))->cv_fs_tell() - s->base;
    }
    return 0;
}
s32 TLobby::init_stream_position() {
    if (((S_803C8A14 *)this)->f14 == 0) {
        ((S_803C8A14 *)this)->f34 = 0;
        ((S_803C8A14 *)this)->pos = 0;
        ((S_803C8A14 *)this)->state = 3;
    } else {
        ((S_803C8A14 *)this)->state = 2;
        ((S_803C8A14 *)this)->f34 = 0;
        ((S_803C8A14 *)this)->pos = get_pos_803C8A14(((S_803C8A14 *)this));
        ((S_803C8A14 *)this)->f3 = 0;
    }
    return 1;
}

s32 TLobby::get_file_offset_relative() {
    u8 *prev;
    prev = (u8 *)this->m_prev;
    if (prev != NULL) {
        return ((TLobby *)prev)->cv_fs_tell() - *(s32 *)&this->m_up;
    }
    return 0;
}

s32 TLobby::set_scroll_offset(s32 arg1) {
    ((TLobby *)(*(s32 *)&this->m_prev))->cv_fs_seek((int) (*(s32 *)&this->m_up + arg1), 0);
    return ((TLobby *)(*(s32 *)&this->m_prev))->cv_fs_tell() - *(s32 *)&this->m_up;
}

s32 TLobby__sub_803C8B2C(u8 *arg0) {
  return ((s8 *)arg0)[1];
}

void TLobby__sub_803C8B38(u8 *arg0) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    if (arg0 != NULL) {
        *(s8 *)((s8 *)arg0 + 1) = 1;
        TLobby::init_once();
        temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 8));
        if (temp_r3 != NULL) {
            ((TLobby *)temp_r3)->cvfs_stop_tr();
            *(s8 *)((s8 *)arg0 + 2) = 0;
        }
        TLobby::release_ref();
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 8));
        if (temp_r3_2 != NULL) {
            ((TLobby *)temp_r3_2)->cv_fs_close();
        }
        memset(arg0, 0, 0x40);
    }
}

inline AdxStreamFile *alloc_803C8BAC(s32 arg, u32 h, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_request_count_ex; i++) {
        p = &((AdxStreamFile *)&adx_stream_read_requests)[lbl_805D7550 + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_request_count_ex) {
        return NULL;
    }
    p->b1 = 1;
    p->b2 = 0;
    p->arg = arg;
    p->handle = h;
    p->fC = 0;
    p->f10 = 0;
    p->size = size;
    p->f2C = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *TLobby__sub_803C8BAC(const char *name, s32 arg) {
    s32 size;
    u32 h;
    AdxStreamFile *p;
    size = cvFsGetFileSize();
    h = cvFsOpen(name, 0, 0);
    if (h == 0) {
        TLobby::report_adx_error((const char *)lbl_8047C634, (s32)name);
        return NULL;
    }
    p = alloc_803C8BAC(arg, h, size);
    if (p != NULL) {
        ((TLobby *)(p->handle))->cv_fs_seek(p->f10, 0);
        ((TLobby *)(p->handle))->cv_fs_tell();
    }
    return p;
}

inline AdxStreamFile *alloc_803C8CDC(s32 arg, u32 h, s32 f10, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_fname_slot_count; i++) {
        p = &((AdxStreamFile *)&adx_stream_read_requests)[adx_stream_request_base_index + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_fname_slot_count) {
        return NULL;
    }
    p->b1 = 1;
    p->b2 = 0;
    p->arg = arg;
    p->handle = h;
    p->fC = 0;
    p->f10 = f10;
    p->size = size;
    p->f2C = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *TLobby__sub_803C8CDC(const char *name, s32 mode, s32 arg) {
    s32 size;
    u32 h;
    AdxStreamFile *p;
    if (mode == 0) {
        size = cvFsGetFileSize();
    } else {
        size = cvFsGetFileSizeEx();
    }
    h = cvFsOpen((const char *)(name), mode, 0);
    if (h == 0) {
        TLobby::report_adx_error((const char *)lbl_8047C634, (s32)name);
        return NULL;
    }
    p = alloc_803C8CDC(arg, h, 0, size);
    if (p != NULL) {
        ((TLobby *)(p->handle))->cv_fs_seek(p->f10, 0);
        ((TLobby *)(p->handle))->cv_fs_tell();
    }
    return p;
}

inline AdxStreamFile *alloc_803C8E28(s32 arg, u32 h, s32 f10, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_request_count_ex; i++) {
        p = &((AdxStreamFile *)&adx_stream_read_requests)[lbl_805D7550 + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_request_count_ex) {
        return NULL;
    }
    p->b1 = 1;
    p->b2 = 0;
    p->arg = arg;
    p->handle = h;
    p->fC = 0;
    p->f10 = f10;
    p->size = size;
    p->f2C = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *adxstm_open_fname_range_ex_rt__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, s32 arg) {
    u32 h;
    AdxStreamFile *p;
    h = cvFsOpen((const char *)(name), mode, 0);
    if (h == 0) {
        TLobby::report_adx_error((const char *)lbl_8047C600, (s32)name);
        return NULL;
    }
    p = alloc_803C8E28(arg, h, off, nsect << 11);
    if (p != NULL) {
        ((TLobby *)(p->handle))->cv_fs_seek(p->f10, 0);
        ((TLobby *)(p->handle))->cv_fs_tell();
    }
    return p;
}

inline AdxStreamFile *alloc_803C8F5C(s32 arg, u32 h, s32 f10, s32 size) {
    AdxStreamFile *p = NULL;
    s32 i;
    for (i = 0; i < adx_stream_fname_slot_count; i++) {
        p = &((AdxStreamFile *)&adx_stream_read_requests)[adx_stream_request_base_index + i];
        if (p->used == 0) {
            break;
        }
    }
    if (i == adx_stream_fname_slot_count) {
        return NULL;
    }
    p->b1 = 1;
    p->b2 = 0;
    p->arg = arg;
    p->handle = h;
    p->fC = 0;
    p->f10 = f10;
    p->size = size;
    p->f2C = 0x200;
    p->sectors = (p->size + 0x7FF) / 2048;
    p->used = 1;
    return p;
}
AdxStreamFile *adxstm_open_fname_range__6TLobbyFPviiii(const char *name, s32 mode, s32 off, s32 nsect, s32 arg) {
    u32 h;
    AdxStreamFile *p;
    h = cvFsOpen((const char *)(name), mode, 0);
    if (h == 0) {
        TLobby::report_adx_error((const char *)lbl_8047C660, (s32)name);
        return NULL;
    }
    p = alloc_803C8F5C(arg, h, off, nsect << 11);
    if (p != NULL) {
        ((TLobby *)(p->handle))->cv_fs_seek(p->f10, 0);
        ((TLobby *)(p->handle))->cv_fs_tell();
    }
    return p;
}

void TLobby::si_get_type_async() {
    SIGetTypeAsync();
}

typedef char RecoveredGlobal_803C90B0_lbl_80575140_size[sizeof(RecoveredGlobal_803C90B0_lbl_80575140) == 0xA00 ? 1 : -1];
s32 TLobby::clear_buffer_a00() {
    memset(&adx_stream_read_requests.value, 0, 0xA00);
    return 1;
}

}

RecoveredGlobal_803C90B0_lbl_80575140 adx_stream_read_requests;
