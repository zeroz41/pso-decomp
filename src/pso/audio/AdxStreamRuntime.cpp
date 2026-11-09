#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#undef PSO_SDK_COMPACT_MATH
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

struct Strm_803C9104;
struct Buf_803C9104 {
    void *ptr;
    s32 size;
};

struct Vt_803C9104 {
    u8 pad[0x18];
    void (*lock)(Strm_803C9104 *, s32, s32, Buf_803C9104 *);
    void (*unlock)(Strm_803C9104 *, s32, Buf_803C9104 *);
    void (*write)(Strm_803C9104 *, s32, Buf_803C9104 *);
};

struct Strm_803C9104 {
    Vt_803C9104 *vt;
};

struct Obj_803C9104 {
    u8 pad[0x14];
    Strm_803C9104 *strm;
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
s32 TLobby__sub_803C9104(Obj_803C9104 *arg0, s32 arg1, s32 arg2);
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
short TLobby__sub_803C8B2C(u8 *arg0);
extern RecoveredGlobal_803C90B0_lbl_80575140 adx_stream_read_requests;
void TLobby__sub_803C9DB4(u8 *arg0);
void TLobby__sub_803C5D24(u8 *arg0);
s32 TLobby__sub_803C85AC(u8 *arg0, s32 *arg1);
s32 ARStartDMA(u8 *arg0, s32 arg1, s16 *arg2, u8 *arg3, s8 *arg4, s8 *arg5, u8 *arg6, s32 *arg7, s32 *arg8, s32 *arg9);
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2);
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
void *memcpy(void *, const void *, u32);
void ARAlloc(void);
void TLobby__sub_803C8514(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8578(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C8594(u8 *arg0, s32 *arg1, s32 *arg2);
s32 set_range__6TLobbyFPvii(u8 *arg0, s32 arg1, s32 arg2);
void SIGetTypeAsync(void);
void TLobby__sub_803C9608(void);
s32 TLobby__sub_803CB844();
void TLobby__sub_803CBA38(void);
s32 set_global_805D7520__6TLobbyFl();

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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 pos_803C8678(S_803C8678 *s) {
    if (s->h != 0) {
        return ((TLobby *)(s->h))->cv_fs_tell() - s->base;
    }
    return 0;
}
}

typedef char PointerRecords_803C8610_var_r31_size[sizeof(PointerRecords_803C8610_var_r31)==0x40?1:-1];
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
#pragma pop

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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
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
#pragma pop

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

short TLobby__sub_803C8B2C(u8 *arg0) {
  u8 *new_var;
  s8 *new_var2;
  new_var = arg0;
  new_var2 = ((s8 *) new_var) + 1;
  return *new_var2;
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

#pragma dont_inline off
#pragma inline_depth(4)
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

#pragma dont_inline off
#pragma inline_depth(4)
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

#pragma dont_inline off
#pragma inline_depth(4)
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

#pragma dont_inline off
#pragma inline_depth(4)
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

void TLobby::on_set_mode() {
    set_global_805D7520__6TLobbyFl();
}

s32 TLobby__sub_803C9104(Obj_803C9104 *arg0, s32 arg1, s32 arg2) {
    s32 blk;
    s32 total;
    Strm_803C9104 *s;
    s32 n1;
    s32 n2;
    Buf_803C9104 a;
    Buf_803C9104 b;
    void *p = arg0->strm;
    s = (Strm_803C9104 *)p;
    if (p == NULL) {
        return 0;
    }
    blk = arg1 * 0x12;
    total = (arg2 / 32) * blk;
    s->vt->lock(s, 0, total, &a);
    n1 = blk * (a.size / blk);
    memset(a.ptr, 0, n1);
    TLobby__sub_803D3130(&a, n1, (Pair_803C8678 *)&a, (Pair_803C8678 *)&b);
    s->vt->write(s, 1, &a);
    s->vt->unlock(s, 0, &b);
    total = total - n1;
    s->vt->lock(s, 0, total, &a);
    n2 = blk * (a.size / blk);
    memset(a.ptr, 0, n2);
    TLobby__sub_803D3130(&a, n2, (Pair_803C8678 *)&a, (Pair_803C8678 *)&b);
    s->vt->write(s, 1, &a);
    s->vt->unlock(s, 0, &b);
    return ((n1 + n2) / blk) * 32;
}

s32 TLobby::check_packet_header_8001(u16 *p, s32 size, s32 *out) {
    if (size < 2) {
        return 0;
    }
    if (*p != 0x8001) {
        return 0;
    }
    *out = size;
    return 1;
}
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2) {
    s32 a7;
    s32 a8;
    s32 a9;
    s16 len;
    u8 b3;
    s8 b4;
    s8 b5;
    u8 b6;
    if (arg1 < 2) {
        return 0;
    }
    if (*arg0 != 0x8000) {
        return 0;
    }
    if (ARStartDMA((u8 *)arg0, arg1, &len, &b3, &b4, &b5, &b6, &a7, &a8, &a9) < 0) {
        return 0;
    }
    *arg2 = len;
    return 1;
}
}

struct Ch_803CB5C4 {
    s32 used;
    s32 id;
    s32 f8;
    s32 fC;
    u8 pad10[0x18];
    u8 f28[8];
    s16 c0;
    s16 c1;
};
struct RecoveredGlobal_800F8A78_lbl_80501178 {
    s32 value;
    u8 remaining[0xC];
};

struct VT_803C9FCC { u8 pad[0x14]; void (*update)(void *self); };

struct Part_803C9FCC { VT_803C9FCC *vt; };

struct Stream_803C9FCC {
    u8 f0;
    u8 active;
    u8 f2;
    s8 count;
    void *f4;
    void *f8;
    u8 padc[0x10 - 0xC];
    s32 f10;
    s32 f14;
    Part_803C9FCC *parts[9];
    s16 f3c;
    s16 f3e;
    u8 pad40[0x4C - 0x40];
    s32 f4c;
    u8 pad50[0x71 - 0x50];
    u8 f71;
    u8 pad72[0x8C - 0x72];
    s32 f8c;
    s32 f90;
    u8 pad94[0x9C - 0x94];
    s32 f9c;
    s32 fa0;
    s32 fa4;
};

struct Stream_803CA824 {
    u8 f0;
    u8 state;
    u8 pad2[0x8 - 0x2];
    void *handle;
    u8 padc[0x10 - 0xC];
    s32 f10;
    u8 pad14[0x60 - 0x14];
    s16 f60;
    u8 pad62[0x98 - 0x62];
    u8 f98;
};

struct Obj_803C96E0 { u8 pad[0x42]; s16 vals[1]; };

struct S_803C96F0 { u8 pad0[3]; s8 count; u8 pad4[8]; void *p; u8 pad10[0x32]; s16 vals[1]; };

typedef struct Ent_803CA774 {
    s32 off;
    s32 len;
} Ent_803CA774;

typedef struct Cb_803CBA58 {
    void (*fn)(s32);
    s32 arg;
} Cb_803CBA58;

// Thread priorities of the ADX manager threads (set up by TLobby__sub_803CB858).
typedef struct Cfg_803CBA58 {
    s32 prio0;
    s32 busy_wait_prio;
    s32 vblank_prio;
    s32 pad_0c;
    s32 prio;
} Cfg_803CBA58;

struct VT_803CA0C8 { u8 pad[0x14]; void (*update)(void *self); };

struct Part_803CA0C8 { VT_803CA0C8 *vt; };

struct Stream_803CA0C8 {
    u8 f0;
    u8 active;
    u8 f2;
    s8 count;
    void *f4;
    void *f8;
    u8 padc[0x10 - 0xC];
    s32 f10;
    s32 f14;
    Part_803CA0C8 *parts[9];
    s16 f3c;
    s16 f3e;
    u8 pad40[0x4C - 0x40];
    s32 f4c;
    u8 pad50[0x71 - 0x50];
    u8 f71;
    u8 pad72[0x8C - 0x72];
    s32 f8c;
    s32 f90;
    u8 pad94[0x9C - 0x94];
    s32 f9c;
    s32 fa0;
    s32 fa4;
};

struct VObj_803C9E38;
struct VT_803C9E38 {
    void *pad[3];
    void (*fc)(VObj_803C9E38 *);
    void *pad10;
    void (*f14)(VObj_803C9E38 *);
};

struct VObj_803C9E38 { VT_803C9E38 *vt; };

struct Obj_803C9E38 {
    u8 f0; s8 f1; u8 f2; s8 f3; void *f4; void *f8; s32 fc; u8 pad_10[4];
    VObj_803C9E38 *f14; VObj_803C9E38 *objs[13]; s32 f4c; u8 pad_50[0x94 - 0x50];
    s32 f94; s8 f98; u8 pad_99[3]; s32 f9c; s32 fa0;
};

struct VObj_803CA194;
typedef void (*RecoveredCallback_2be3cacebb2e)(void);
struct VT_803CA194 {
    void *pad[3];
    void (*fc)(VObj_803CA194 *);
    void *pad10;
    void (*f14)(VObj_803CA194 *);
};

struct VObj_803CA194 { VT_803CA194 *vt; };

struct Obj_803CA194 {
    u8 f0; s8 f1; u8 f2; s8 f3; void *f4; void *f8; void *fc; VObj_803CA194 *f10;
    VObj_803CA194 *f14; VObj_803CA194 *objs[23]; void *f74; VObj_803CA194 *objs2[2]; VObj_803CA194 *objs3[4]; u8 pad_90[4];
    void *f94; s8 f98; u8 pad_99[3]; s32 f9c; s32 fa0;
};

struct Obj_803CA194;
struct Ch_803CA3C4 {
    s8 state;
    u8 f1, f2;
    s8 n;
    void *f4;
    void *f8;
    void *fc;
    void *f10;
    s32 f14;
    void *f18[2];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s16 f3c;
    s16 f3e;
    s16 f40;
    s16 f42[8];
    u8 pad52[2];
    s32 f54;
    s32 f58;
    s32 f5c;
    s16 f60;
    u8 pad62[2];
    s32 f64;
    s16 f68;
    s16 f6a;
    s8 f6c;
    s8 f6d;
    u8 pad6e[4];
    s8 f72;
    u8 pad73[0x88 - 0x73];
    s32 f88;
    u8 pad8c[0x94 - 0x8C];
    void *f94;
    s8 f98;
    u8 pad99[0xA8 - 0x99];
};

struct Strm_803CB20C;
struct Buf_803CB20C { void *data; s32 size; };

struct VT_803CB20C {
    void *pad[5];
    void (*m14)(Strm_803CB20C *);
    void (*lock)(Strm_803CB20C *, s32, s32, Buf_803CB20C *);
    void *pad1C;
    void (*commit)(Strm_803CB20C *, s32, Buf_803CB20C *);
};

struct Strm_803CB20C { VT_803CB20C *vt; };

struct Obj_803CB20C {
    u8 pad0[2]; u8 f2; u8 pad3; s32 f4; u32 f8; u8 padC[8]; Strm_803CB20C *f14;
    u8 pad18[0x4C - 0x18]; s32 f4C; s32 f50; u8 pad54[0x6C - 0x54]; s8 f6C;
    u8 pad6D[0x90 - 0x6D]; s32 f90;
};

extern "C" {
extern const u32 lbl_805E0D58[1];
s32 dispatch_field4_event__6TLobbyFv(int);
s32 send_with_offset4_alt__6TLobbyFv(int);
s32 notify_client__6TLobbyFv(int);
s32 set_field_44__6TLobbyFl(int, int);
s32 set_field_40__6TLobbyFl(int, int);
s32 set_field_3c__6TLobbyFl(int, int);
s32 set_count__6TLobbyFl(int, int);
extern char adxt_trap_entry_data_shortage_error[];
void adxt_trap_entry_update__6TLobbyFPv(Obj_803CB20C *arg0);
s32 VIWaitForRetrace();

extern Cb_803CBA58 adx_worker_thread_pending_callback;
extern s32 lbl_805D7540;
extern s32 lbl_805D75A0;
void TLobby__sub_803CBB14(void);
}
extern const u32 lbl_805E0D5C[1];
extern const u32 lbl_805E0D60[1];
extern const u32 lbl_805E0D64[1];
#define lbl_805E0D58 (*(const f32 *)lbl_805E0D58)
#define lbl_805E0D5C (*(const f32 *)lbl_805E0D5C)
#define lbl_805E0D60 (*(const f32 *)lbl_805E0D60)
#define lbl_805E0D64 (*(const f32 *)lbl_805E0D64)

extern "C" {
s32 TLobby__sub_803CC030(int, int);
s32 dispatch_packet__6TLobbyFv(int, int);
s32 calc_adx_predictor_coeffs(void *, void *, void *, void *);
s8 TLobby__sub_803C9CB0(u8 *arg0);
void TLobby__sub_803CB7F8(s32 arg0, s32 arg1);
extern Ch_803CB5C4 adx_decoder_channel_pool[16];
void TLobby__sub_803CB194(u8 *arg0);
extern s32 lbl_805D7590;
s32 TLobby__sub_803CB844(void);
void TLobby__sub_803C0758(u8 *arg0);
void configure_audio_stream_output(Stream_803C9FCC *self);
extern char adxt_start_filename_open_error[];
void start_audio_stream_file(Stream_803CA824 *self, const char *name);
s16 TLobby__sub_803C96E0(Obj_803C96E0 *self, s32 i);
extern const char *const volatile lbl_805E0D78;
void TLobby__sub_803CB81C(void);
s32 TLobby__sub_803CBF50(void *);
extern u8 adx_out_pan_parameter_error[];
void GXFlush(void);
s32 TLobby__sub_803CA8B4(Ent_803C9608 *);
extern Ent_803C9608 adx_stream_player_pool[16];
extern s32 lbl_805D7564;
struct SjMemoryBuffer;
SjMemoryBuffer *sj_memory_buffer_create(void *arg0, s32 arg1);
extern char adxt_start_mem_idx_stream_create_error[];
void TLobby__sub_803CE544(void *, int);
void TLobby__sub_803CFAA8(const char *, void *, int);
char *TLobby__sub_803D43B8(void);
extern const char lbl_805E0D70[4];
extern const char lbl_805E0D74[4];
void TLobby__sub_803CB74C(s32 *arg0);
s32 run_worker_callbacks_slot5__6TLobbyFv(int);
extern Cfg_803CBA58 lbl_804F9D80;
extern OSThread *lbl_805D75A8;

extern s32 lbl_805D7598;
extern s32 lbl_805D75A4;
extern char adxm_idle_border_internal_error[];

void TLobby__sub_803C97F4(u8 *arg0, s32 *pos, s32 *rate);
s32 TLobby__sub_803CBF10(int);
extern s32 lbl_805D7560;
extern s32 lbl_805D7570;
s32 TLobby__sub_803C9358(u8 *arg0);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
void TLobby__sub_803C9E38(Obj_803C9E38 *arg0, VObj_803C9E38 *arg1);
extern RecoveredCallback_2be3cacebb2e lbl_805D7574;
void TLobby__sub_803CA194(Obj_803CA194 *arg0);
void *TLobby__sub_803C0848(void *, s32, void *);
void *run_step_5210__6TLobbyFv(void *, s32);
Ch_803CA3C4 *adx_create_stream_player(s32 n, s32 base, s32 size);
void TLobby__sub_803C9350(u8 *arg0, s32 arg1);
void TLobby__sub_803C94B8(void);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C96A8(u8 *arg0, s32 arg1);
s16 TLobby__sub_803C96B0(u8 *arg0);
s32 TLobby__sub_803C9740(u8 *arg0);
s32 TLobby__sub_803C97B8(u8 *arg0);
void TLobby__sub_803CB4A4(u8 *arg0);
void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2);
void TLobby__sub_803CBA18(void);
u32 decode_adx_mono_blocks(int, int, int, void *, int, int);
s32 set_callback_params__6TLobbyFll();
u32 dispatch_receive_update__6TLobbyFv(int, int, int, void *, int, void *, int, int);
s32 notify_field_4__6TLobbyFv(int);
s32 send_packet_by_id__6TLobbyFv(int);
s32 send_with_offset4__6TLobbyFv(int);
s32 set_params__6TLobbyFll();
s32 trigger_sub_task__6TLobbyFv(int);

void TLobby::set_field98(s8 arg1) {
    *(s8 *)((s8 *)((u8 *)this) + 0x98) = arg1;
}

void TLobby__sub_803C9350(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x88) = arg1;
}

#pragma dont_inline off
#pragma inline_depth(4)
inline void inl_803C9608(void) {
    s32 i;
    if (lbl_805D7564 == 0) {
        TLobby::init_once();
        lbl_805D7564 = 1;
        GXFlush();
        lbl_805D7564 = 2;
        for (i = 0; i < 16; i++) {
            if (adx_stream_player_pool[i].state == 1) {
                TLobby__sub_803CA8B4(&adx_stream_player_pool[i]);
            }
        }
        lbl_805D7564 = 3;
        TLobby::run_sequence();
        lbl_805D7564 = 0;
        TLobby::release_ref();
    }
}
s32 TLobby__sub_803C9358(u8 *arg0) {
    s32 ret;
    s32 save;
    s32 spC;
    s32 sp8;
    if (*(s8 *)((s8 *)arg0 + 0x72) == 0) {
        return 0;
    }
    ret = TLobby__sub_803CBF10(*(s32 *)((s8 *)arg0 + 0xC));
    inl_803C9608();
    save = lbl_805D7560;
    lbl_805D7560 = 0;
    TLobby__sub_803C97F4(arg0, &spC, &sp8);
    lbl_805D7560 = save;
    *(s32 *)((s8 *)arg0 + 0x9C) = (s32)((f32)lbl_805D7570 * ((f32)spC / (f32)sp8));
    *(s32 *)((s8 *)arg0 + 0xA0) = lbl_805D7540;
    return ret;
}

void TLobby__sub_803C94B8(void) {
    set_params__6TLobbyFll();
}

void TLobby__sub_803C94D8(void) {

}

void TLobby__sub_803C94DC(u8 *arg0, s32 arg1) {
    s32 spC;
    s32 sp8;
    s32 st;
    s32 save;
    st = *(s8 *)((s8 *)arg0 + 1);
    if (arg1 != *(s8 *)((s8 *)arg0 + 0x72)) {
        TLobby::init_once();
        *(s8 *)((s8 *)arg0 + 0x72) = arg1;
        if (st == 3 || st == 4) {
            if (arg1 == 1) {
                TLobby__sub_803CC030(*(s32 *)((s8 *)arg0 + 0xC), 0);
            } else {
                TLobby__sub_803CC030(*(s32 *)((s8 *)arg0 + 0xC), 1);
                *(s32 *)((s8 *)arg0 + 0xA0) = lbl_805D7540;
            }
            save = lbl_805D7560;
            lbl_805D7560 = 0;
            TLobby__sub_803C97F4(arg0, &spC, &sp8);
            lbl_805D7560 = save;
            *(s32 *)((s8 *)arg0 + 0x9C) = (s32)((f32)lbl_805D7570 * ((f32)spC / (f32)sp8));
        }
        TLobby::release_ref();
    }
}

s16 TLobby::get_field_60() {
    return *(s16 *)((s8 *)((u8 *)this) + 0x60);
}

void TLobby__sub_803C9608(void) {
    s32 i;
    if (lbl_805D7564 == 0) {
        TLobby::init_once();
        lbl_805D7564 = 1;
        GXFlush();
        lbl_805D7564 = 2;
        for (i = 0; i < 16; i++) {
            if (adx_stream_player_pool[i].state == 1) {
                TLobby__sub_803CA8B4(&adx_stream_player_pool[i]);
            }
        }
        lbl_805D7564 = 3;
        TLobby::run_sequence();
        lbl_805D7564 = 0;
        TLobby::release_ref();
    }
}

void TLobby::set_field_6d(s8 arg1) {
    *(s8 *)((s8 *)((u8 *)this) + 0x6D) = arg1;
}

void TLobby__sub_803C96A8(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x38) = arg1;
}

s16 TLobby__sub_803C96B0(u8 *arg0) {
    return *(s16 *)((s8 *)arg0 + 0x40);
}

void TLobby::set_field_40_and_notify(s16 arg1) {
    *(s16 *)((s8 *)((u8 *)this) + 0x40) = arg1;
    trigger_sub_task__6TLobbyFv((int)this->m_next);
}

s16 TLobby__sub_803C96E0(Obj_803C96E0 *self, s32 i) {
    return self->vals[i];
}

void TLobby::adxt_set_out_pan(s32 arg1, s16 arg2) {
    S_803C96F0 *arg0 = (S_803C96F0 *)this;
    arg0->vals[arg1] = arg2;
    if (arg1 < arg0->count) {
        TLobby__sub_803CBF50(this->m_next);
        return;
    }
    TLobby::notify_error((const char *)adx_out_pan_parameter_error);
}

s32 TLobby__sub_803C9740(u8 *arg0) {
    if ((s8) *(u8 *)((s8 *)arg0 + 1) >= 2) {
        return send_with_offset4__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 4)));
    }
    return 0;
}

s32 TLobby::apply_if_v2() {
    if ((s8) *(u8 *)((s8 *)((u8 *)this) + 1) >= 2) {
        return notify_field_4__6TLobbyFv((int) (*(s32 *)&this->m_flags));
    }
    return 0;
}

s32 TLobby__sub_803C97B8(u8 *arg0) {
    if ((s8) *(u8 *)((s8 *)arg0 + 1) >= 2) {
        return send_packet_by_id__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 4)));
    }
    return 0;
}

struct Strm_803C97F4;

struct VT_803C97F4 {
    void *pad[9];
    s32 (*f24)(Strm_803C97F4 *, s32);
};

struct Strm_803C97F4 { VT_803C97F4 *vt; };

struct Adxt_803C97F4 {
    u8 pad_0[1];
    s8 f1;
    u8 pad_2[2];
    s32 f4;
    u8 pad_8[4];
    s32 fC;
    u8 pad_10[8];
    Strm_803C97F4 *f18;
    u8 pad_1c[0x72 - 0x1C];
    s8 f72;
    u8 pad_73[0x88 - 0x73];
    s32 f88;
    u8 pad_8c[0x9C - 0x8C];
    s32 f9C;
    s32 fA0;
    s32 fA4;
};

extern "C" {
s32 TLobby__sub_803C0010(u8 *arg0);
s32 send_packet_by_id_2__6TLobbyFv(int);
s32 query_available_size__6TLobbyFv(int);
extern f32 lbl_805D756C;
extern s32 lbl_805D7568;
extern u32 lbl_805D4678;
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline void get_play_position_803C97F4(Adxt_803C97F4 *p, s32 *pos, s32 *rate) {
    s32 st = p->f1;
    if (st == 3 || st == 4) {
        s32 total;
        *rate = notify_field_4__6TLobbyFv(p->f4);
        total = TLobby__sub_803C0010((u8 *)p->f4);
        *pos = p->fA4 + (total - (query_available_size__6TLobbyFv(p->fC) + (p->f18 != NULL ? p->f18->vt->f24(p->f18, 1) / 2 : 0)));
    } else if (st == 5) {
        *pos = send_packet_by_id__6TLobbyFv(p->f4);
        *rate = notify_field_4__6TLobbyFv(p->f4);
        *pos *= 16 / send_packet_by_id_2__6TLobbyFv(p->f4);
        *pos += p->fA4;
    } else {
        *pos = 0;
        *rate = 1;
    }
    *pos += p->f88;
}

void TLobby__sub_803C97F4(u8 *arg0, s32 *pos, s32 *rate) {
    Adxt_803C97F4 *p = (Adxt_803C97F4 *)arg0;
    s32 cur_pos;
    s32 cur_rate;
    s32 st;

    if (lbl_805D7560 == 0) {
        get_play_position_803C97F4(p, pos, rate);
        return;
    }
    lbl_805D756C = lbl_805E0D58;
    st = p->f1;
    if (st == 3 || st == 4) {
        if (p->f72 == 0) {
            *pos = p->f9C + (lbl_805D7540 - p->fA0) * 100;
        } else {
            *pos = p->f9C;
        }
        get_play_position_803C97F4(p, &cur_pos, &cur_rate);
        lbl_805D756C = lbl_805E0D5C * ((f32)cur_pos / (f32)cur_rate - (f32)*pos / (f32)lbl_805D7570);
        if (lbl_805D756C > lbl_805E0D60 || lbl_805D756C < lbl_805E0D64) {
            if (lbl_805D4678 == 1) {
                s32 save = lbl_805D7560;
                lbl_805D7560 = 0;
                TLobby__sub_803C97F4(arg0, &cur_pos, &cur_rate);
                lbl_805D7560 = save;
                lbl_805D7568++;
            }
            p->f9C = (u32)((f32)lbl_805D7570 * ((f32)cur_pos / (f32)cur_rate));
            p->fA0 = lbl_805D7540;
        }
    } else if (st == 5) {
        cur_pos = send_packet_by_id__6TLobbyFv(p->f4);
        cur_rate = notify_field_4__6TLobbyFv(p->f4);
        cur_pos *= 16 / send_packet_by_id_2__6TLobbyFv(p->f4);
        *pos = (s32)((f32)lbl_805D7570 * ((f32)cur_pos / (f32)cur_rate));
        *pos += p->f9C + 1;
    } else {
        *pos = 0;
    }
    *pos += p->f88;
    *rate = lbl_805D7570;
}
#pragma pop

void TLobby::set_rate_mode(s32 arg0) {
    if (arg0 == 1) {
        lbl_805D7570 = 0x176A;
    } else if (arg0 == 2) {
        lbl_805D7570 = 0x1388;
    }
    lbl_805D7560 = arg0;
}

extern s32 lbl_805D7588;

s8 TLobby__sub_803C9CB0(u8 *arg0) {
  u8 new_var2;
  u8 new_var;
  new_var = (((((((*((u8 *) (((s8 *) arg0) + 1))) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  new_var2 = new_var;
  return (s8) new_var2;
}
}
void * *initialize_dvd_file_driver(void);
void stop_audio_stream(u8 *arg0);
void set_dvd_synchronous_read_mode(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
#pragma push
#pragma fp_contract on
#pragma push
#pragma dont_inline on
void stop_audio_stream(u8 *arg0) {
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    if (*(void **)((s8 *)arg0 + 8) != NULL) {
        TLobby__sub_803C89C4((u8 *)(*(void **)((s8 *)arg0 + 8)));
        TLobby__sub_803C8B38((u8 *)((int) (*(u32 *)((s8 *)arg0 + 8))));
        temp_r3 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3 != NULL) {
            temp_r4 = (u8 *)(*temp_r3);
            (*(s32 (**)(void *, void *))((s8 *)temp_r4 + 0x14))(temp_r3, temp_r4);
        }
        *(u32 *)((s8 *)arg0 + 8) = 0U;
    }
    TLobby::init_once();
    if ((s32) *(u8 *)((s8 *)arg0 + 2) == 4) {
        lsc_stop((LscStream*) (*(s32 *)((s8 *)arg0 + 0x94)));
        temp_r3_2 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3_2 != NULL) {
            temp_r4_2 = (u8 *)(*temp_r3_2);
            (*(s32 (**)(void *, void *))((s8 *)temp_r4_2 + 0x14))(temp_r3_2, temp_r4_2);
        }
    }
    TLobby::init_once();
    dispatch_packet__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    TLobby__sub_803CC030((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->reset_flag();
    if ((s32) *(u8 *)((s8 *)arg0 + 2) == 2) {
        temp_r3_3 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3_3 != NULL) {
            temp_r4_3 = (u8 *)(*temp_r3_3);
            (*(s32 (**)(void *, void *))((s8 *)temp_r4_3 + 0xC))(temp_r3_3, temp_r4_3);
        }
    }
    *(void ***)((s8 *)arg0 + 0x14) = NULL;
    *(s8 *)((s8 *)arg0 + 1) = 0;
    TLobby::release_ref();
    TLobby::release_ref();
}
#pragma pop
#pragma pop
extern "C" {

void TLobby__sub_803C9DB4(u8 *arg0) {
    void **temp_r3;
    TLobby::init_once();
    dispatch_packet__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    TLobby__sub_803CC030((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->reset_flag();
    if ((s32) *(u8 *)((s8 *)arg0 + 2) == 2) {
        temp_r3 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3 != NULL) {
            (*(s32 (**)(void *))((s8 *)((unsigned char *) (*temp_r3)) + 0xC))(temp_r3);
        }
    }
    *(void ***)((s8 *)arg0 + 0x14) = NULL;
    *(s8 *)((s8 *)arg0 + 1) = 0;
    TLobby::release_ref();
}

#pragma push
#pragma dont_inline on
void TLobby__sub_803C9E38(Obj_803C9E38 *arg0, VObj_803C9E38 *arg1) {
    s32 i;
    if (arg0->f8 != NULL) {
        TLobby__sub_803C89C4((u8 *)arg0->f8);
        TLobby__sub_803C8B38((u8 *)((int)arg0->f8));
        if (arg0->f14 != NULL) {
            arg0->f14->vt->f14(arg0->f14);
        }
        arg0->f8 = NULL;
    }
    TLobby::init_once();
    if ((s32)arg0->f2 == 4) {
        lsc_stop((LscStream*)arg0->f94);
        if (arg0->f14 != NULL) {
            arg0->f14->vt->f14(arg0->f14);
        }
    }
    TLobby::init_once();
    dispatch_packet__6TLobbyFv(arg0->fc, 0);
    TLobby__sub_803CC030(arg0->fc, 0);
    ((TLobby *)((int)arg0->f4))->reset_flag();
    if ((s32)arg0->f2 == 2) {
        if (arg0->f14 != NULL) {
            arg0->f14->vt->fc(arg0->f14);
        }
    }
    arg0->f14 = NULL;
    arg0->f1 = 0;
    TLobby::release_ref();
    TLobby::release_ref();
    TLobby::init_once();
    for (i = 0; i < arg0->f3; i++) {
        arg0->objs[i]->vt->f14(arg0->objs[i]);
    }
    ((TLobby *)(arg0->f4))->set_param_and_notify((int)arg1);
    arg0->f14 = arg1;
    TLobby__sub_803C0758((u8 *)arg0->f4);
    arg0->f1 = 1;
    arg0->f2 = 3;
    arg0->f4c = 0;
    arg0->f98 = 1;
    arg0->f9c = 0;
    arg0->fa0 = lbl_805D7540;
    TLobby::release_ref();
}
#pragma pop

#pragma push
#pragma dont_inline on
void configure_audio_stream_output(Stream_803C9FCC *self) {
    s32 i;
    s32 v;
    Stream_803C9FCC *pp;
    set_range__6TLobbyFPvii((u8 *)self->f8, self->f3e << 11, self->f3c << 11);
    ((TLobby *)(self->f8))->set_scroll_position(0x19);
    ((TLobby *)(self->f8))->init_stream_position();
    v = self->f10;
    pp = self;
    for (i = 0; i < self->count; i++) {
        pp->parts[0]->vt->update(pp->parts[0]);
        pp = (Stream_803C9FCC *)((u8 *)pp + 4);
    }
    ((TLobby *)(self->f4))->set_param_and_notify(v);
    self->f14 = v;
    TLobby__sub_803C0758((u8 *)self->f4);
    self->active = 1;
    self->f4c = 0;
    self->f71 = 0;
    self->f8c = 0x7FFFFFFF;
    self->f90 = -1;
    self->f9c = 0;
    self->fa4 = 0;
    self->fa0 = lbl_805D7540;
    self->f2 = 0;
}
#pragma pop

struct Stream_803C9FCC;

void TLobby::start_stream_playback(s32 arg1) {
    s32 i;
    for (i = 0; i < ((Stream_803CA0C8 *)this)->count; i++) {
        ((Stream_803CA0C8 *)this)->parts[i]->vt->update(((Stream_803CA0C8 *)this)->parts[i]);
    }
    ((TLobby *)(((Stream_803CA0C8 *)this)->f4))->set_param_and_notify(arg1);
    ((Stream_803CA0C8 *)this)->f14 = arg1;
    TLobby__sub_803C0758((u8 *)(((Stream_803CA0C8 *)this)->f4));
    ((Stream_803CA0C8 *)this)->active = 1;
    ((Stream_803CA0C8 *)this)->f4c = 0;
    ((Stream_803CA0C8 *)this)->f71 = 0;
    ((Stream_803CA0C8 *)this)->f8c = 0x7FFFFFFF;
    ((Stream_803CA0C8 *)this)->f90 = -1;
    ((Stream_803CA0C8 *)this)->f9c = 0;
    ((Stream_803CA0C8 *)this)->fa4 = 0;
    ((Stream_803CA0C8 *)this)->fa0 = lbl_805D7540;
}

#pragma push
#pragma dont_inline on
void TLobby__sub_803CA194(Obj_803CA194 *arg0) {
    s32 i;
    if (arg0 == NULL) {
        return;
    }
    if (lbl_805D7574 != NULL) {
        lbl_805D7574();
    }
    if ((s32)arg0->f0 == 1) {
        if (arg0->f8 != NULL) {
            TLobby__sub_803C89C4((u8 *)arg0->f8);
            TLobby__sub_803C8B38((u8 *)((int)arg0->f8));
            if (arg0->f14 != NULL) {
                arg0->f14->vt->f14(arg0->f14);
            }
            arg0->f8 = NULL;
        }
        TLobby::init_once();
        if ((s32)arg0->f2 == 4) {
            lsc_stop((LscStream*)arg0->f94);
            if (arg0->f14 != NULL) {
                arg0->f14->vt->f14(arg0->f14);
            }
        }
        TLobby::init_once();
        dispatch_packet__6TLobbyFv((int)arg0->fc, 0);
        TLobby__sub_803CC030((int)arg0->fc, 0);
        ((TLobby *)((int)arg0->f4))->reset_flag();
        if ((s32)arg0->f2 == 2) {
            if (arg0->f14 != NULL) {
                arg0->f14->vt->fc(arg0->f14);
            }
        }
        arg0->f14 = NULL;
        arg0->f1 = 0;
        TLobby::release_ref();
        TLobby::release_ref();
    }
    if (arg0->fc != NULL) {
        ((TLobby *)(arg0->fc))->unregister_si_polling();
    }
    if (arg0->f4 != NULL) {
        ((TLobby *)(arg0->f4))->reset_entry();
    }
    if (arg0->f8 != NULL) {
        TLobby__sub_803C8B38((u8 *)((int)arg0->f8));
    }
    if (arg0->f94 != NULL) {
        lsc_destroy((LscStream*)arg0->f94);
    }
    TLobby::init_once();
    if (arg0->f10 != NULL) {
        arg0->f10->vt->fc(arg0->f10);
    }
    for (i = 0; i < arg0->f3; i++) {
        if (arg0->objs[i] != NULL) {
            arg0->objs[i]->vt->fc(arg0->objs[i]);
        }
        if (arg0->objs2[i] != NULL) {
            arg0->objs2[i]->vt->fc(arg0->objs2[i]);
        }
        if (arg0->objs3[i] != NULL) {
            arg0->objs3[i]->vt->fc(arg0->objs3[i]);
        }
    }
    if (arg0->f74 != NULL) {
        ((TLobby *)(arg0->f74))->clear_entry();
    }
    memset(arg0, 0, 0xA8);
    arg0->f0 = 0;
    TLobby::release_ref();
}
#pragma pop

#undef lbl_805E0D58
#undef lbl_805E0D5C
#undef lbl_805E0D60
#undef lbl_805E0D64
__declspec(section ".sdata2") extern const u32 lbl_805E0D58[1] = { 0x00000000 };
__declspec(section ".sdata2") extern const u32 lbl_805E0D5C[1] = { 0x447a0000 };
__declspec(section ".sdata2") extern const u32 lbl_805E0D60[1] = { 0x42700000 };
__declspec(section ".sdata2") extern const u32 lbl_805E0D64[1] = { 0xc2700000 };
#define lbl_805E0D58 (*(const f32 *)lbl_805E0D58)
#define lbl_805E0D5C (*(const f32 *)lbl_805E0D5C)
#define lbl_805E0D60 (*(const f32 *)lbl_805E0D60)
#define lbl_805E0D64 (*(const f32 *)lbl_805E0D64)

Ch_803CA3C4 *adx_create_stream_player(s32 n, s32 base, s32 size) {
    Ch_803CA3C4 *c;
    s32 aligned = (base + 0x3F) & ~0x3F;
    s32 rem = size - (aligned - base);
    s32 i;
    s32 t;
    for (i = 0; i < 16; i++) {
        if (adx_stream_player_pool[i].state == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    c = (Ch_803CA3C4 *)&adx_stream_player_pool[i];
    memset(c, 0, 0xA8);
    c->n = n;
    t = (n * 0x2060) << 1;
    c->f20 = aligned + t;
    c->f24 = (rem - t - 0x24) / 2048 * 2048;
    c->f28 = 0x24;
    c->f2c = aligned;
    c->f30 = 0x2000;
    c->f34 = 0x2060;
    c->f14 = 0;
    c->f10 = sj_ring_buffer_create((void *)c->f20, c->f24, c->f28);
    if (c->f10 == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    for (i = 0; i < n; i++) {
        c->f18[i] = sj_ring_buffer_create((void *)(c->f2c + c->f34 * i * 2), c->f30 * 2, (c->f34 - c->f30) * 2);
        if (c->f18[i] == NULL) {
            TLobby__sub_803CA194((Obj_803CA194 *)c);
            return NULL;
        }
    }
    if ((c->f4 = TLobby__sub_803C0848(c->f10, n, c->f18)) == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    if ((c->fc = run_step_5210__6TLobbyFv(c->f18, n)) == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    if ((c->f94 = lsc_create(c->f10)) == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    c->f38 = 0x3C;
    c->f3c = c->f24 / 2048;
    c->f3e = 0.85 * c->f3c;
    c->f40 = 0;
    for (i = 0; i < n; i++) {
        c->f42[i] = -0x80;
    }
    c->f6c = 1;
    c->f54 = 0;
    c->f58 = 0;
    c->f5c = 0;
    c->f60 = 0;
    c->f64 = 0;
    c->f68 = 0;
    c->f6a = 0;
    c->f6d = 1;
    c->f72 = 0;
    c->f88 = 0;
    c->f98 = 1;
    c->state = 1;
    return c;
}

void TLobby::adxt_start_mem_idx(u8 *arg1, s32 arg2) {
    s32 r;
    stop_audio_stream(((u8 *)this));
    if (arg2 >= ((Ent_803CA774 *)arg1)[0].len || arg2 < 0) {
        return;
    }
    TLobby::init_once();
    r = (s32)sj_memory_buffer_create(arg1 + *(s32 *)(arg1 + (arg2 + 1) * 8), 0x40000000);
    if (r == 0) {
        TLobby::release_ref();
        TLobby::notify_error((const char *)adxt_start_mem_idx_stream_create_error);
        return;
    }
    start_stream_playback(r);
    ((u8 *)this)[2] = 2;
    ((u8 *)this)[0x98] = 0;
    TLobby::release_ref();
}

#pragma push
#pragma dont_inline on
void start_audio_stream_file(Stream_803CA824 *self, const char *name) {
    stop_audio_stream((u8 *)self);
    TLobby::init_once();
    if ((self->handle = TLobby__sub_803C8BAC(name, self->f10)) == 0) {
        TLobby::release_ref();
        TLobby::report_adx_error((const char *)adxt_start_filename_open_error, (s32)name);
        self->f60 = -1;
        self->state = 6;
    } else {
        configure_audio_stream_output((Stream_803C9FCC *)self);
        self->f98 = 0;
        TLobby::release_ref();
    }
}
#pragma pop

struct Strm_803CAB38 {
    u8 f0;
    s8 f1;
    u8 f2;
    s8 f3;
    s32 f4;
    void *f8;
    s32 fc;
    u8 pad10[0x28];
    s32 f38;
    s16 f3c_pad;
    s16 f3e_pad;
    s16 f40;
    s16 f42;
    s16 f44;
    s16 pad46;
    s32 f48;
    s32 pad4c;
    s32 f50;
    u8 pad54[0x20];
    void *f74;
    u8 pad78[0x14];
    s32 f8c;
    s32 f90;
};

s32 TLobby__sub_803BFE58(int);
s32 TLobby__sub_803BFEE8(int);
s32 notify_field_4_alt__6TLobbyFv(int);
s32 send_packet_by_id_2__6TLobbyFv(int);
s32 TLobby__sub_803BFFC0(int);
void TLobby__sub_803BFFFC(u8 *arg0, s32 arg1, s32 arg2);
s32 TLobby__sub_803C07E8(int);
s32 run_step_4430__6TLobbyFv(int, int);
s32 TLobby__sub_803CBF0C(int, int);
s32 TLobby__sub_803CBF30(int, int);
s32 TLobby__sub_803CBF90(int, int);
s32 TLobby__sub_803CBFB0(int, int);
struct Conn_803CAEB4;
void TLobby__sub_803CAEB4(Conn_803CAEB4 *arg0);
extern char adx_decoder_channel_count_error[];

#define SBF50 TLobby__sub_803CBF50

#pragma push
#pragma dont_inline on
void TLobby__sub_803CAB38(Strm_803CAB38 *self) {
#define arg0 ((u8 *)self)
    s32 TLobby__sub_803CBF50(s32, s32, s32);
    s32 trigger_sub_task__6TLobbyFv(int, int);
    s32 t = self->f4;
    s32 k;
    s32 n1;
    char buf[32];

    if (TLobby__sub_803C07E8(t) == 2) {
        s32 v = send_with_offset4__6TLobbyFv(t);
        if (v > self->f3) {
            TLobby::format_number_pair(v, self->f3, buf, 0x10);
            TLobby::report_adx_error((const char *)adx_decoder_channel_count_error, (s32)buf);
            stop_audio_stream(arg0);
            return;
        }
        n1 = notify_field_4__6TLobbyFv(t);
        k = TLobby__sub_803BFEE8(t);
        if (k > 0) {
            self->f48 = (n1 / self->f38) * 3;
        } else {
            self->f48 = ((n1 / self->f38) * 3) / 2;
        }
        {
            s32 a = notify_field_4_alt__6TLobbyFv(t) * 2;
            self->f48 = a * ((self->f48 + a) / a);
        }
        ((TLobby *)t)->set_network_result(self->f48);
        if (k > 0) {
            if ((s32) self->f2 == 2) {
                self->f50 = 0;
            } else {
                s32 x = TLobby__sub_803BFE58(t);
                s32 pages;
                self->f50 = 0x800 - x % 0x800;
                pages = (x + 0x7FF) / 0x800;
                self->f50 = self->f50 % 0x800;
                self->f8c = pages;
                ((TLobby *)(self->f8))->set_scroll_position(pages);
                ((TLobby *)(self->f8))->set_coords((s32)((void *)TLobby__sub_803CB194), (s32)arg0);
            }
            s32 e = dispatch_field4_event__6TLobbyFv(t);
            self->f90 = e;
            set_field_3c__6TLobbyFl(t, e);
            set_field_44__6TLobbyFl(t, 0);
            set_field_40__6TLobbyFl(t, 0);
            TLobby__sub_803BFFFC((u8 *)t, (s32)adxt_trap_entry_update__6TLobbyFPv, (s32)arg0);
        } else {
            if (self->f8 != NULL) {
                ((TLobby *)(self->f8))->set_scroll_position(0x7FFFFFFF);
            }
            set_field_3c__6TLobbyFl(t, send_packet_by_id__6TLobbyFv(t));
            set_field_44__6TLobbyFl(t, 0);
            set_field_40__6TLobbyFl(t, 0);
            TLobby__sub_803BFFFC((u8 *)t, (s32)TLobby__sub_803CAEB4, (s32)arg0);
        }
        k = notify_field_4__6TLobbyFv(t);
        n1 = send_with_offset4__6TLobbyFv(t);
        s32 pid = send_packet_by_id__6TLobbyFv(t);
        s32 p2 = send_packet_by_id_2__6TLobbyFv(t);
        TLobby__sub_803CBF30(self->fc, p2);
        TLobby__sub_803CBF90(self->fc, k);
        TLobby__sub_803CBFB0(self->fc, n1);
        TLobby__sub_803CBF0C(self->fc, pid);
        trigger_sub_task__6TLobbyFv(self->fc, self->f40);
        if (send_with_offset4__6TLobbyFv(self->f4) == 1) {
            if (self->f42 == -0x80) {
                SBF50(self->fc, 0, 0);
            } else {
                SBF50(self->fc, 0, self->f42);
            }
        } else {
            if (self->f42 == -0x80) {
                SBF50(self->fc, 0, -0xF);
            } else {
                SBF50(self->fc, 0, self->f42);
            }
            if (self->f44 == -0x80) {
                SBF50(self->fc, 1, 0xF);
            } else {
                SBF50(self->fc, 1, self->f44);
            }
        }
        if (self->f74 != NULL) {
            ((TLobby *)(self->f74))->set_packet_flags(k);
        }
        if (TLobby__sub_803BFFC0(t) == 2) {
            s32 o = ((TLobby *)t)->get_offset_58();
            run_step_4430__6TLobbyFv(self->fc, o);
        }
        dispatch_packet__6TLobbyFv(self->fc, 1);
        self->f1 = 2;
    }
}
#pragma pop
#undef arg0
#undef SBF50

#pragma push
#pragma dont_inline on
#pragma push

extern "C" {

typedef struct Buf_803CAEB4 Buf_803CAEB4;
typedef struct Conn_803CAEB4 Conn_803CAEB4;
typedef struct RingVt_803CAEB4 RingVt_803CAEB4;
typedef struct Ring_803CAEB4 Ring_803CAEB4;
struct Buf_803CAEB4
{
  u8 *p;
  s32 len;
};
struct Ring_803CAEB4;
struct RingVt_803CAEB4
{
  u8 pad0[0x18];
  void (*m4)(Ring_803CAEB4 *, s32, s32, Buf_803CAEB4 *);
  void (*m5)(Ring_803CAEB4 *, s32, Buf_803CAEB4 *);
  void (*m6)(Ring_803CAEB4 *, s32, Buf_803CAEB4 *);
};
struct Ring_803CAEB4
{
  RingVt_803CAEB4 *vt;
};
struct Conn_803CAEB4
{
  u8 pad0[4];
  s32 lobby;
  u8 pad8[0x14 - 0x8];
  Ring_803CAEB4 *ring;
  u8 pad18[0x48 - 0x18];
  s32 f48;
  u8 pad4C[0x98 - 0x4C];
  s8 active;
  u8 pad99[0xA4 - 0x99];
  s32 fA4;
};
s32 TLobby__sub_803C0010(u8 *arg0);
s32 process_audio_stream_input(int);

void TLobby__sub_803CAEB4(Conn_803CAEB4 *o) {
  s32 lobby = o->lobby;
  Ring_803CAEB4 *ring = o->ring;
  Buf_803CAEB4 a;
  Buf_803CAEB4 c;
  Buf_803CAEB4 b;
  Buf_803CAEB4 d;
  s16 hlen;
  s16 tlen;
  s32 r1;
  s32 r2;
  s32 n;
  s32 m;
  if (o->active != 0)
  {
    tlen = 0;
    ring->vt->m4(ring, 1, 0x7FFFFFFF, &a);
    ring->vt->m4(ring, 1, 0x7FFFFFFF, &b);
    if (((TLobby *)(a.p))->parse_packet_header_len(a.len, &hlen) != 0)
    {
      o->active = 0;
      ring->vt->m5(ring, 1, &b);
      ring->vt->m5(ring, 1, &a);
      return;
    }
    n = hlen;
    r1 = TLobby::find_terminator_index((s16 *)(a.p + n), (s32)(a.len - n), &hlen);
    if (r1 == 0)
    {
      r2 = -1;
    }
    else
    {
      r2 = TLobby::find_terminator_index((s16 *)b.p, (s32)b.len, &tlen);
    }
    n += hlen;
    m = tlen & 0xFFFFFFFFFFFFFFFFu;
    if ((r1 != 0) && (r2 != 0))
    {
      ring->vt->m5(ring, 1, &b);
      ring->vt->m5(ring, 1, &a);
      o->active = 0;
      return;
    }
    if (r1 == 0)
    {
      ring->vt->m5(ring, 1, &b);
      TLobby__sub_803D3130(&a, n, (Pair_803C8678 *)&a, (Pair_803C8678 *)&c);
      ring->vt->m6(ring, 0, &a);
      ring->vt->m5(ring, 1, &c);
    }
    else
    {
      ring->vt->m6(ring, 0, &a);
      TLobby__sub_803D3130(&b, m, (Pair_803C8678 *)&b, (Pair_803C8678 *)&d);
      ring->vt->m6(ring, 0, &b);
      ring->vt->m5(ring, 1, &d);
    }
    o->fA4 += TLobby__sub_803C0010((u8 *)lobby);
    ((TLobby *)lobby)->reset_flag();
    TLobby__sub_803C0758((u8 *)lobby);
    process_audio_stream_input(lobby);
    if (TLobby__sub_803C07E8(lobby) != 2)
    {
      o->active = 0;
      return;
    }
    ((TLobby *)lobby)->set_network_result(o->f48);
    set_field_3c__6TLobbyFl(lobby, send_packet_by_id__6TLobbyFv(lobby));
    set_field_44__6TLobbyFl(lobby, 0);
    set_field_40__6TLobbyFl(lobby, 0);
  }
}

}

#pragma pop

void TLobby__sub_803CB194(u8 *arg0) {
    s32 temp_r3;
    u8 *lobby;
    lobby = (u8 *)(*(u8 **)((s8 *)arg0 + 8));
    temp_r3 = send_with_offset4_alt__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 4)));
    if ((s8) *(u8 *)((s8 *)arg0 + 0x6C) == 0) {
        set_field_3c__6TLobbyFl((int) (*(s32 *)((s8 *)arg0 + 4)), -1);
        ((TLobby *)(*(u8 **)((s8 *)arg0 + 8)))->set_scroll_position(0x7FFFFFFF);
        return;
    }
    ((TLobby *)lobby)->set_scroll_offset(temp_r3 / 2048);
}
#pragma pop

void adxt_trap_entry_update__6TLobbyFPv(Obj_803CB20C *arg0) {
    Buf_803CB20C b;
    Strm_803CB20C *s;
    s32 off;
    s32 total;
    s32 id;
    s32 c;
    id = arg0->f4;
    s = arg0->f14;
    c = notify_client__6TLobbyFv(id);
    off = send_with_offset4_alt__6TLobbyFv(id);
    total = dispatch_field4_event__6TLobbyFv(id);
    if (arg0->f8 == 0U && arg0->f6C == 0) {
        set_field_3c__6TLobbyFl(arg0->f4, -1);
        return;
    }
    s->vt->lock(s, 1, arg0->f50, &b);
    if (b.size < arg0->f50) {
        TLobby::notify_error((const char *)adxt_trap_entry_data_shortage_error);
    }
    s->vt->commit(s, 0, &b);
    set_field_40__6TLobbyFl(id, 0);
    set_field_3c__6TLobbyFl(id, arg0->f90 = total - c);
    set_field_44__6TLobbyFl(id, off);
    set_count__6TLobbyFl(id, c);
    if ((s32)arg0->f2 == 2) {
        s->vt->m14(s);
        s->vt->lock(s, 1, off, &b);
        s->vt->commit(s, 0, &b);
    }
    arg0->f4C += 1;
}

void TLobby::update_receive_check() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r0;
    u32 temp_r3;

    if ((s32) this->m_next == 1) {
        *(s32 *)&this->m_next = 2;
    }
    if ((s32) this->m_next == 2) {
        if ((s32) this->m_down == 1) {
            *(u32 *)&this->m_up = decode_adx_mono_blocks((int) (*(s32 *)((s8 *)arg0 + 0x18)), (int) (*(s32 *)((s8 *)arg0 + 0x1C)), (int) (*(s32 *)((s8 *)arg0 + 0x20)), arg0 + 0x28, (int) (*(s16 *)((s8 *)arg0 + 0x30)), (int) (*(s16 *)((s8 *)arg0 + 0x32)));
        } else {
            *(u32 *)&this->m_up = dispatch_receive_update__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 0x18)), (int) (*(s32 *)((s8 *)arg0 + 0x1C)), (int) (*(s32 *)((s8 *)arg0 + 0x20)), arg0 + 0x28, (int) (*(s32 *)((s8 *)arg0 + 0x24)), arg0 + 0x2C, (int) (*(s16 *)((s8 *)arg0 + 0x30)), (int) (*(s16 *)((s8 *)arg0 + 0x32)));
            temp_r0 = *(u32 *)&this->m_up;
            temp_r3 = temp_r0 >> 0x1FU;
            if ((s32) (((temp_r0 & 1) ^ temp_r3) - temp_r3) == 1) {
                lbl_805D7588 = 1;
            }
        }
        *(s32 *)&this->m_next = 3;
    }
}

s32 TLobby::get_size() {
    return *(s32 *)&this->m_up;
}

void TLobby::reset_field_0C() {
    if ((s32) this->m_next == 3) {
        this->m_next = 0;
    }
}

void TLobby::reset_client_state() {
    u8 *arg0 = (u8 *)this;
    this->m_next = 0;
    memset(arg0 + 0x28, 0, 8);
}

void TLobby__sub_803CB4A4(u8 *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0xC) == 0) {
        *(s32 *)((s8 *)arg0 + 0x10) = 0;
        *(s32 *)((s8 *)arg0 + 0xC) = 1;
    }
}

s32 TLobby::post_request(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_next == 0) {
        *(s32 *)&this->m_down = 2;
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
        *(s32 *)((s8 *)arg0 + 0x20) = arg3;
        *(s32 *)((s8 *)arg0 + 0x24) = arg4;
        return 1;
    }
    return 0;
}

s32 TLobby::try_post_command(s32 arg1, s32 arg2, s32 arg3) {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_next == 0) {
        *(s32 *)&this->m_down = 1;
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
        *(s32 *)((s8 *)arg0 + 0x20) = arg3;
        *(s32 *)((s8 *)arg0 + 0x24) = 0;
        return 1;
    }
    return 0;
}

s32 TLobby::get_client_count() {
    return *(s32 *)&this->m_next;
}

void TLobby::clear_record_data() {
    s32 *arg0 = (s32 *)this;
    if (arg0 != NULL) {
        *arg0 = 0;
        memset(arg0, 0, 0x34);
    }
}

void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2) {
    *(s16 *)((s8 *)arg0 + 0x28) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 0x2A) = (s16) *arg2;
    *(s16 *)((s8 *)arg0 + 0x2C) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s16 *)((s8 *)arg0 + 0x2C) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

#pragma push
#pragma fp_contract on
void TLobby::calc_adx_coeffs_at_offset(void *arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    calc_adx_predictor_coeffs((void *)arg2, arg1, (void *)(arg0 + 0x30), (void *)(arg0 + 0x32));
}
#pragma pop

Ch_803CB5C4 *adx_allocate_decoder_channel(void) {
    s32 i;
    Ch_803CB5C4 *c;

    for (i = 0; i < 16; i++) {
        if (adx_decoder_channel_pool[i].used == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    c = &adx_decoder_channel_pool[i];
    memset(c, 0, sizeof(Ch_803CB5C4));
    c->used = 1;
    c->id = i;
    c->f8 = 0;
    c->fC = 0;
    calc_adx_predictor_coeffs((void *)500, (void *)44100, &c->c0, &c->c1);
    memset(c->f28, 0, 8);
    return c;
}

typedef char RecoveredGlobal_800F8A78_lbl_80501178_size[sizeof(RecoveredGlobal_800F8A78_lbl_80501178) == 0x10 ? 1 : -1];
void TLobby::clear_buffer_340() {
    memset(adx_decoder_channel_pool, 0, 0x340);
}

void TLobby__sub_803CB74C(s32 *arg0) {
    TLobby__sub_803CE544((void *)TLobby__sub_803CB7F8, 0);
    TLobby__sub_803CFAA8(lbl_805E0D70, (void *)TLobby__sub_803D43B8, 0);
    TLobby__sub_803CE544((void *)TLobby__sub_803CB7F8, 0);
    TLobby__sub_803CFAA8(lbl_805E0D74, (void *)initialize_dvd_file_driver, 0);
    ((TLobby *)lbl_805E0D74)->cvFsSetDefDev();
    if (arg0 != NULL) {
        set_dvd_synchronous_read_mode(0, 0, 0, *arg0);
    } else {
        set_dvd_synchronous_read_mode(0, 0, 0, 0);
    }
}

void TLobby__sub_803CB7F8(s32 arg0, s32 arg1) {
    TLobby::notify_error((const char *)arg1);
}

void TLobby__sub_803CB81C(void) {
    lbl_805E0D78;
    TLobby__sub_803C9608();
    ARAlloc();
}

s32 TLobby__sub_803CB844(void) {
    return lbl_805D7590 != 0;
}

OSThread adxm_worker_thread;
OSThread adxm_vblank_thread;
OSThread adxm_busy_wait_thread;
u8 adxm_worker_stack[ADXM_WORKER_STACK_BYTES];
u8 adxm_vblank_stack[ADXM_VBLANK_STACK_BYTES];
u8 adxm_busy_wait_stack[ADXM_BUSY_WAIT_STACK_BYTES];

void TLobby__sub_803CB858(Cfg_803CBA58 *cfg) {
    lbl_805E0D78;
    if (lbl_805D7590 == 0) {
        TLobby::init_callback_tables();
        TLobby__sub_803D33E4((s32)__OSCallResetFunctions, 0);
        TLobby__sub_803D33D4((s32)fn_803CBCA0, 0);
        if (cfg == NULL) {
            lbl_804F9D80.pad_0c = 16;
            lbl_804F9D80.prio0 = 1;
            lbl_804F9D80.busy_wait_prio = 8;
            lbl_804F9D80.vblank_prio = 12;
            lbl_804F9D80.prio = 24;
        } else {
            __memcpy(&lbl_804F9D80, cfg, sizeof(Cfg_803CBA58));
        }
        OSCreateThread(&adxm_busy_wait_thread, (void *(*)(void *))TLobby::wait_for_lock_release, NULL,
                       adxm_busy_wait_stack + sizeof(adxm_busy_wait_stack), sizeof(adxm_busy_wait_stack),
                       lbl_804F9D80.busy_wait_prio, 1);
        OSCreateThread(&adxm_vblank_thread, (void *(*)(void *))TLobby__sub_803CBB14, NULL,
                       adxm_vblank_stack + sizeof(adxm_vblank_stack), sizeof(adxm_vblank_stack),
                       lbl_804F9D80.vblank_prio, 1);
        OSCreateThread(&adxm_worker_thread, (void *(*)(void *))TLobby::worker_thread_loop, NULL,
                       adxm_worker_stack + sizeof(adxm_worker_stack), sizeof(adxm_worker_stack),
                       lbl_804F9D80.prio, 1);
        lbl_805D75A8 = OSGetCurrentThread();
        lobby_worker_thread_run_flag = 1;
        lbl_805D75B8 = 1;
        lbl_805D75C8 = 1;
        lbl_805D75BC = 0;
        lbl_805D75B4 = 0;
        lbl_805D75C4 = 0;
        lbl_805D75B0 = 0;
        OSResumeThread(&adxm_vblank_thread);
        OSResumeThread(&adxm_worker_thread);
        TLobby__sub_803D34B0(5, (void (*)(s32))TLobby::adxm_goto_mwidle_border, 0);
    }
    lbl_805D7590++;
}

void TLobby__sub_803CBA18(void) {
    set_callback_params__6TLobbyFll();
}

void TLobby__sub_803CBA38(void) {
    TLobby::run_callbacks_group2();
}

void TLobby::worker_thread_loop() {
    while (lobby_worker_thread_run_flag == 1) {
        if (run_worker_callbacks_slot5__6TLobbyFv(lbl_805D75A4++) == 0 || lbl_805D7598 == 1) {
            if (lbl_805D7598 == 1) {
                lbl_805D7598 = 0;
                OSSetThreadPriority(&adxm_worker_thread, lbl_804F9D80.prio);
            }
            if (adx_worker_thread_pending_callback.fn != NULL) {
                adx_worker_thread_pending_callback.fn(adx_worker_thread_pending_callback.arg);
            }
            OSSuspendThread(&adxm_worker_thread);
        }
    }
    lbl_805D75BC = 1;
}

void TLobby__sub_803CBB14(void) {
    while (lbl_805D75B8 == 1) {
        VIWaitForRetrace();
        lbl_805D75A0++;
        lbl_805D7540++;
        TLobby::run_callbacks_group2();
        if (lbl_805D75BC == 0) {
            OSResumeThread(&adxm_worker_thread);
            if (adx_worker_thread_pending_callback.fn != NULL) {
                adx_worker_thread_pending_callback.fn(adx_worker_thread_pending_callback.arg);
            }
        }
    }
    lbl_805D75B4 = 1;
}

void TLobby::wait_for_lock_release() {
    while (lbl_805D75C8 == 1) {
        lbl_805D759C++;
    }
    lbl_805D75C4 = 1;
}
void TLobby::adxm_goto_mwidle_border() {
    s32 i;
    if (lbl_805D75BC == 1) {
        return;
    }
    lbl_805D7598 = 1;
    OSSetThreadPriority(&adxm_worker_thread, lbl_804F9D80.prio0);
    for (i = 0; i < 200000000; i++) {
        OSResumeThread(&adxm_worker_thread);
        if (lbl_805D7598 == 0) {
            break;
        }
    }
    if (i == 200000000) {
        TLobby::set_message_and_notify(adxm_idle_border_internal_error);
    }
    OSSetThreadPriority(&adxm_worker_thread, lbl_804F9D80.prio);
}
}

RecoveredGlobal_803C90B0_lbl_80575140 adx_stream_read_requests;
Ch_803CB5C4 adx_decoder_channel_pool[16];

typedef char AdxmOriginalThreadSize[sizeof(OSThread)==0x310 ? 1 : -1];
