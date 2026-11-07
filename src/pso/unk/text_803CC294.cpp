#include "types.h"
#include "pso/unk/TLobby_803CD804.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_803CC500_lbl_8047C910 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_803CC53C_lbl_8047C93C {
    s32 value;
    u8 remaining[0x70];
};

struct RecoveredGlobal_803CCB5C_lbl_8047CA28 {
    s32 value;
    u8 remaining[0x150];
};

struct Obj_803CC4C0 { u8 a; s8 b; };

struct Chunk_803CC294 { u16 id; u16 len; s32 off; };

struct Ent_803CC294 {
    struct Ent_803CC294 *next; s32 f4; s32 f8; u16 fc; u8 pad_e[2]; char name[0x100];
    s32 f110; u16 f114; u16 arr[1];
};

struct Ent_803CD5C4 {
    u8 pad_0[4]; s32 f4; s32 f8; u16 fc; u8 pad_e[0x114 - 0xE]; s16 f114; s16 arr[1];
};

struct Strm_803CD5C4 { u8 f0; s8 f1; };

struct LogEnt_803CD16C { s8 type; s8 phase; u16 seq; s32 a; s32 b; s32 c; };

struct Buf_803CD16C { u8 data[0x10C]; };

struct LogHdr_803CD16C { u8 pad[0x4]; u16 seq; u8 pad2[0x1A]; };

struct Slot_803CD16C {
    s8 used; s8 f1; s8 f2; u8 f3; u32 f4; s32 f8; s32 fc; s32 f10; u8 pad_14[4];
    s32 f18; s32 f1c; s32 f20; u8 pad_24[8]; s32 f2c; s32 f30; u8 pad_34[0x138 - 0x34];
};

struct LogHdr_803CD3A8 { u8 pad[0x2]; u16 seq; };

struct VObj_803CC980;
struct LogHdr_803CC980 { u8 pad[0xA]; u16 seq; };

struct VT_803CC980 { void *a; void *b; void *c; void (*fn)(VObj_803CC980 *); };

struct VObj_803CC980 { VT_803CC980 *vt; };

struct Snd_803CC980 {
    u8 f0; s8 state; s8 f2; u8 f3; u32 f4; VObj_803CC980 *f8; u8 pad_c[0x14 - 0xC];
    s32 f14; u8 pad_18[0x20 - 0x18]; s32 f20; s32 f24; s32 f28;
};

struct Ent_803CC884 {
    s8 used; s8 state; s8 f2; u8 f3; u32 f4; VObj_803CC980 *f8; u8 pad_c[0x14 - 0xC];
    s32 f14; u8 pad_18[0x20 - 0x18]; s32 f20; s32 f24; s32 f28; u8 pad_2c[0x138 - 0x2C];
};

struct Hdr_803CCE9C { u8 used; u8 f1; };

struct LogHdr_803CCE9C { u8 pad[0x6]; u16 seq; };

extern "C" {
extern RecoveredGlobal_803CC500_lbl_8047C910 lbl_8047C910;
extern RecoveredGlobal_803CC53C_lbl_8047C93C lbl_8047C93C;
s32 adxf_read_nw32__6TLobbyFPvil();
extern RecoveredGlobal_803CCB5C_lbl_8047CA28 lbl_8047CA28;
extern char lbl_8047C88C[];
s32 TLobby__sub_803CC4C0(Obj_803CC4C0 *p);
s32 strncpy(void *, void *, int);
extern s32 adx_afs_partition_id_range_error[];
extern s32 afs_file_id_out_of_range_error[];
extern Ent_803CC294 *afs_archive_toc_table[];
s32 memcmp(void *, void *, int);
extern s32 lbl_8047C818[];
extern s32 lobby_adxf_current_file_id;
extern Strm_803CD5C4 *lobby_adxf_open_file_handle;
extern s32 lobby_afs_toc_entry_index;
extern u8 *lbl_805D75EC;
extern s32 lbl_805E0D88;
u32 adxstm_open_fname_range__6TLobbyFPviiii(Buf_803CD16C *, s32, s32, s32, s32);
extern s32 lbl_8047CB7C[];
extern LogHdr_803CD16C lbl_8057B7B0;
extern LogEnt_803CD16C lbl_8057B7D0[];
extern Slot_803CD16C adxf_file_handle_pool[];
extern s32 adxf_log_write_index;
Slot_803CD16C *adxf_open_afs__6TLobbyFii(s32 arg0, s32 arg1);
u32 TLobby__sub_803C8CDC(u32, s32, s32);
extern s32 lbl_8047CBA4[];
extern s32 lbl_8047CBD8[];
Slot_803CD16C *adxf_open__6TLobbyFUii(u32 arg0, s32 arg1);
s32 invalidate_cache__6TLobbyFv(s32, s32);
extern s32 lbl_8047C9B0[];
extern s32 lbl_8047C9D4[];
extern s32 lbl_805D75E4;
void *memset(void *, int, unsigned long);
typedef char RecoveredGlobal_803CC500_lbl_8047C910_size[sizeof(RecoveredGlobal_803CC500_lbl_8047C910) == 0x2C ? 1 : -1];

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline s32 check_803CC294(s32 arg0, s32 arg1) {
    if (arg0 < 0 || arg0 >= 0x100) {
        TLobby::notify_error((const char *)adx_afs_partition_id_range_error);
        return -3;
    }
    if (afs_archive_toc_table[arg0] == NULL) {
        TLobby::notify_error((const char *)adx_afs_partition_id_range_error);
        return -3;
    }
    if (arg1 < 0 || arg1 >= afs_archive_toc_table[arg0]->f8) {
        TLobby::notify_error((const char *)afs_file_id_out_of_range_error);
        return -3;
    }
    return 0;
}
s32 TLobby::get_afs_file_info(s32 arg0, s32 arg1, char *arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    s32 st;
    Ent_803CC294 *e;
    u16 *arr;
    s32 sum;
    s32 i;
    Ent_803CC294 *next;
    st = check_803CC294(arg0, arg1);
    if (st < 0) {
        *arg3 = 0;
        *arg4 = -1;
        *arg5 = -1;
        return st;
    }
    e = afs_archive_toc_table[arg0];
    while ((next = e->next) != NULL) {
        Chunk_803CC294 *c = (Chunk_803CC294 *)&e->f114;
        for (i = 0; i < e->fc; i++, c++) {
            if (c->id == arg1) {
                strncpy(arg2, e->name, 0x100);
                *arg3 = e->f110;
                *arg4 = c->off;
                *arg5 = c->len;
                return st;
            }
        }
        e = next;
    }
    sum = e->f114;
    arr = e->arr;
    for (i = 0; i < arg1; i++) {
        sum += arr[i];
    }
    strncpy(arg2, e->name, 0x100);
    *arg3 = e->f110;
    *arg4 = sum;
    *arg5 = arr[arg1];
    return st;
}
#pragma pop

s32 TLobby__sub_803CC4C0(Obj_803CC4C0 *p) {
    if (p == 0) {
        TLobby::notify_error((const char *)lbl_8047C88C);
        return -3;
    }
    return p->b;
}

s32 TLobby::adxf_get_fsize_byte() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        TLobby::notify_error((const char *)(&lbl_8047C910.value));
        return -3;
    }
    return *(s32 *)&this->m_up;
}
typedef char RecoveredGlobal_803CC53C_lbl_8047C93C_size[sizeof(RecoveredGlobal_803CC53C_lbl_8047C93C) == 0x74 ? 1 : -1];
s32 TLobby__sub_803CC53C(u8 *arg0) {
    if (arg0 == NULL) {
        TLobby::notify_error((const char *)(&lbl_8047C93C.value));
        return -3;
    }
    return *(s32 *)((s8 *)arg0 + 0xC);
}
typedef char RecoveredGlobal_803CCB5C_lbl_8047CA28_size[sizeof(RecoveredGlobal_803CCB5C_lbl_8047CA28) == 0x154 ? 1 : -1];

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

void TLobby__sub_803CC884(void) {
    Ent_803CC884 *p;
    s32 i;
    s32 sp8;
    TLobby::init_once();
    for (i = 0; i < 0x10; i++) {
        p = (Ent_803CC884 *)&adxf_file_handle_pool[i];
        if (p->used == 1 && p->state == 2) {
            p->state = TLobby__sub_803C8B2C((u8 *)p->f4);
            TLobby__sub_803C85AC((u8 *)p->f4, &sp8);
            p->f20 = sp8;
            if (p->state == 3 || p->state == 4) {
                p->f14 += p->f20;
                if (p->f8 != NULL && p->f2 == 0) {
                    if (lbl_805D75E4 == 1) {
                        invalidate_cache__6TLobbyFv(p->f24, p->f28);
                    }
                    p->f8->vt->fn(p->f8);
                    p->f8 = NULL;
                }
            }
        }
    }
    TLobby::release_ref();
}

s32 TLobby::adxf_stop() {
    Snd_803CC980 *arg0 = (Snd_803CC980 *)this;
    s32 sp8;
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = ++((LogHdr_803CC980 *)&lbl_8057B7B0)->seq;
        e->type = 5;
        e->phase = 0;
        e->seq = seq;
        e->a = (s32)arg0;
        e->b = -1;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    if (arg0 == NULL) {
        TLobby::notify_error((const char *)lbl_8047C9B0);
        return -3;
    }
    if (arg0->state == 1) {
        return arg0->f14;
    }
    if (arg0->state == 3) {
        arg0->state = 1;
        return arg0->f14;
    }
    if (arg0->f4 == 0) {
        TLobby::notify_error((const char *)lbl_8047C9D4);
        return -1;
    }
    TLobby::init_once();
    TLobby__sub_803C89C4((u8 *)arg0->f4);
    TLobby__sub_803C85AC((u8 *)arg0->f4, &sp8);
    arg0->f20 = sp8;
    if (arg0->f8 != NULL && arg0->f2 == 0) {
        if (lbl_805D75E4 == 1) {
            invalidate_cache__6TLobbyFv(arg0->f24, arg0->f28);
        }
        arg0->f8->vt->fn(arg0->f8);
        arg0->f8 = NULL;
    }
    arg0->state = 1;
    TLobby::release_ref();
    {
        s32 i = adxf_log_write_index % 256;
        LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
        e->type = 5;
        e->phase = 1;
        e->seq = ((LogHdr_803CC980 *)&lbl_8057B7B0)->seq;
        e->a = (s32)arg0;
        e->b = -1;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    return arg0->f14;
}
#pragma pop

s32 TLobby::read_checked_align(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 & 0x1F) {
        TLobby::notify_error((const char *)(&lbl_8047CA28.value));
        return -3;
    }
    return adxf_read_nw32__6TLobbyFPvil();
}
#define LE32_803CD5C4(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline s32 rd32_803CD5C4(u8 *p) {
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}
inline s32 state_803CD5C4(s32 base) {
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error((const char *)(base + 0x74));
        return -3;
    }
    return lobby_adxf_open_file_handle->f1;
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline Slot_803CD16C *find_803CD16C(void) {
    Slot_803CD16C *r = NULL;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (adxf_file_handle_pool[i].used == 0) {
            r = &adxf_file_handle_pool[i];
            break;
        }
    }
    return r;
}
inline Slot_803CD16C *alloc_803CD16C(void) {
    Slot_803CD16C *s = find_803CD16C();
    if (s == NULL) {
        return NULL;
    }
    s->f1 = 1;
    s->f4 = 0;
    s->f18 = 0;
    s->f1c = 0;
    s->f20 = 0;
    s->f2c = 0x200;
    s->f2 = 0;
    s->f8 = 0;
    s->used = 1;
    return s;
}
inline s32 open_803CD16C(Slot_803CD16C *s, s32 arg0, s32 arg1) {
    Buf_803CD16C buf;
    s32 c;
    s32 b;
    s32 a;
    u32 h;
    if (TLobby::get_afs_file_info(arg0, arg1, (char *)&buf, &a, &b, &c) < 0) {
        return -3;
    }
    s->f30 = b;
    h = adxstm_open_fname_range__6TLobbyFPviiii(&buf, a, b, c, 0);
    s->f4 = h;
    if (h == 0) {
        TLobby::notify_error((const char *)lbl_8047CB7C);
        return -1;
    }
    s->fc = c;
    s->f10 = c << 11;
    return 0;
}

void TLobby::release_used_slots() {
    s32 i;
    Slot_803CD16C *p;
    for (i = 0; i < 0x10; i++) {
        p = &adxf_file_handle_pool[i];
        if (p->used == 1) {
            ((TLobby *)p)->close_adxf_handle();
        }
    }
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline s32 close_803CCE9C(Snd_803CC980 *arg0) {
    s32 sp8;
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = ((LogHdr_803CC980 *)&lbl_8057B7B0)->seq + 1;
        e->type = 5;
        e->phase = 0;
        e->seq = seq;
        e->a = (s32)arg0;
        e->b = -1;
        ((LogHdr_803CC980 *)&lbl_8057B7B0)->seq = seq;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    if (arg0 == NULL) {
        TLobby::notify_error((const char *)lbl_8047C9B0);
        return -3;
    }
    if (arg0->state == 1) {
        return arg0->f14;
    }
    if (arg0->state == 3) {
        arg0->state = 1;
        return arg0->f14;
    }
    if (arg0->f4 == 0) {
        TLobby::notify_error((const char *)lbl_8047C9D4);
        return -1;
    }
    TLobby::init_once();
    TLobby__sub_803C89C4((u8 *)arg0->f4);
    TLobby__sub_803C85AC((u8 *)arg0->f4, &sp8);
    arg0->f20 = sp8;
    if (arg0->f8 != NULL && arg0->f2 == 0) {
        if (lbl_805D75E4 == 1) {
            invalidate_cache__6TLobbyFv(arg0->f24, arg0->f28);
        }
        arg0->f8->vt->fn(arg0->f8);
        arg0->f8 = NULL;
    }
    arg0->state = 1;
    TLobby::release_ref();
    {
        s32 i = adxf_log_write_index % 256;
        LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
        e->type = 5;
        e->phase = 1;
        e->seq = ((LogHdr_803CC980 *)&lbl_8057B7B0)->seq;
        e->a = (s32)arg0;
        e->b = -1;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    return arg0->f14;
}
void TLobby::close_adxf_handle() {
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = ++((LogHdr_803CCE9C *)&lbl_8057B7B0)->seq;
        e->type = 3;
        e->phase = 0;
        e->seq = seq;
        e->a = (s32)this;
        e->b = -1;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    if (this != NULL) {
        TLobby::init_once();
        if ((s32)((Hdr_803CCE9C *)this)->f1 == 2) {
            close_803CCE9C((Snd_803CC980 *)this);
        }
        if (((Slot_803CD16C *)this)->f4 != 0) {
            TLobby__sub_803C8B38((u8 *)(((Slot_803CD16C *)this)->f4));
        }
        memset(this, 0, 0x138);
        TLobby::release_ref();
        {
            s32 i = adxf_log_write_index % 256;
            LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
            e->type = 3;
            e->phase = 1;
            e->seq = ((LogHdr_803CCE9C *)&lbl_8057B7B0)->seq;
            e->a = (s32)this;
            e->b = -1;
            e->c = -1;
            adxf_log_write_index = i + 1;
        }
    }
}
#pragma pop

Slot_803CD16C *adxf_open_afs__6TLobbyFii(s32 arg0, s32 arg1) {
    Slot_803CD16C *s;
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = lbl_8057B7B0.seq + 1;
        e->type = 2;
        e->phase = 0;
        e->seq = seq;
        e->a = arg0;
        e->b = arg1;
        lbl_8057B7B0.seq = seq;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    TLobby::init_once();
    s = alloc_803CD16C();
    if (s != NULL) {
        if (open_803CD16C(s, arg0, arg1) < 0) {
            ((TLobby *)s)->close_adxf_handle();
            s = NULL;
        }
    }
    TLobby::release_ref();
    {
        s32 i = adxf_log_write_index % 256;
        LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
        e->type = 2;
        e->phase = 1;
        e->seq = lbl_8057B7B0.seq;
        e->a = arg0;
        e->b = arg1;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    return s;
}
#pragma pop

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline Slot_803CD16C *find_803CD3A8(void) {
    Slot_803CD16C *r = NULL;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (adxf_file_handle_pool[i].used == 0) {
            r = &adxf_file_handle_pool[i];
            break;
        }
    }
    return r;
}
inline Slot_803CD16C *alloc_803CD3A8(void) {
    Slot_803CD16C *s = find_803CD3A8();
    if (s == NULL) {
        return NULL;
    }
    s->f1 = 1;
    s->f4 = 0;
    s->f18 = 0;
    s->f1c = 0;
    s->f20 = 0;
    s->f2c = 0x200;
    s->f2 = 0;
    s->f8 = 0;
    s->used = 1;
    return s;
}
inline s32 open_803CD3A8(Slot_803CD16C *s, u32 name, s32 mode) {
    u32 h;
    s32 sz;
    if (name == 0) {
        TLobby::notify_error((const char *)lbl_8047CBA4);
        return -1;
    }
    h = TLobby__sub_803C8CDC(name, mode, 0);
    if (h == 0) {
        TLobby::notify_error((const char *)lbl_8047CBD8);
        return -1;
    }
    s->f4 = h;
    sz = ((TLobby *)h)->get_field_14();
    s->fc = (sz + 0x7FF) / 2048;
    s->f10 = sz;
    return 0;
}
Slot_803CD16C *adxf_open__6TLobbyFUii(u32 arg0, s32 arg1) {
    Slot_803CD16C *s;
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = ((LogHdr_803CD3A8 *)&lbl_8057B7B0)->seq + 1;
        e->type = 1;
        e->phase = 0;
        e->seq = seq;
        e->a = arg0;
        e->b = arg1;
        ((LogHdr_803CD3A8 *)&lbl_8057B7B0)->seq = seq;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    TLobby::init_once();
    s = alloc_803CD3A8();
    if (s != NULL) {
        if (open_803CD3A8(s, arg0, arg1) < 0) {
            ((TLobby *)s)->close_adxf_handle();
            s = NULL;
        }
    }
    TLobby::release_ref();
    {
        s32 i = adxf_log_write_index % 256;
        LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
        e->type = 1;
        e->phase = 1;
        e->seq = ((LogHdr_803CD3A8 *)&lbl_8057B7B0)->seq;
        e->a = arg0;
        e->b = arg1;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    return s;
}
#pragma pop

s32 TLobby::read_afs_toc(s32 arg0) {
    s16 *arr;
    Ent_803CD5C4 *e;
    s32 st;
    s32 i;
    s32 base = (s32)lbl_8047C818;
    if (arg0 != lobby_adxf_current_file_id) {
        TLobby::notify_error((const char *)(base + 0x4D0));
        return -3;
    }
    st = state_803CD5C4(base);
    if (st != 3) {
        return st;
    }
    e = ((Ent_803CD5C4 * *)&afs_archive_toc_table)[arg0];
    arr = e->arr;
    if (e->f8 == 0) {
        s32 n;
        if (memcmp(lbl_805D75EC, &lbl_805E0D88, 3) != 0) {
            TLobby::notify_error((const char *)(base + 0x504));
            TLobby__sub_803CD804();
            return 4;
        }
        n = rd32_803CD5C4(lbl_805D75EC + 4);
        if (n > 0x10000) {
            TLobby::notify_error((const char *)(base + 0x538));
            TLobby__sub_803CD804();
            return 4;
        }
        e->fc = n;
        i = 3;
        e->f8 = (u16)n;
        e->f4 = ((e->f8 + 1) * 2 + 0x116) & ~3;
        e->f114 = LE32_803CD5C4(lbl_805D75EC + 8) / 2048;
    } else {
        i = 1;
    }
    for (; i < 0x200; i += 2) {
        u8 *q = lbl_805D75EC + i * 4;
        arr[lobby_afs_toc_entry_index++] = (LE32_803CD5C4(q) + 0x7FF) / 2048;
        if (lobby_afs_toc_entry_index >= e->f8) {
            st = 3;
            TLobby__sub_803CD804();
            break;
        }
    }
    if (i >= 0x200) {
        if (((s32 (*)(void *, int, void *))adxf_read_nw32__6TLobbyFPvil)(lobby_adxf_open_file_handle, 1, lbl_805D75EC) < 0) {
            st = 4;
            TLobby__sub_803CD804();
        } else {
            st = lobby_adxf_open_file_handle->f1;
        }
    }
    return st;
}
#pragma pop

}
