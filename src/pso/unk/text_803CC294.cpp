#include <string.h>

#include "types.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/SjRingBuffer.h"

struct Obj_803CC4C0 { u8 a; s8 b; };

struct Chunk_803CC294 { u16 id; u16 len; s32 off; };

struct Ent_803CC294 {
    struct Ent_803CC294 *next; s32 f4; s32 f8; u16 fc; s8 fe; u8 pad_f; char name[0x100];
    s32 f110; u16 f114; u16 arr[1];
};

struct Ent_803CD5C4 {
    u8 pad_0[4]; s32 f4; s32 f8; u16 fc; u8 pad_e[0x114 - 0xE]; s16 f114; s16 arr[1];
};

struct LogEnt_803CD16C { s8 type; s8 phase; u16 seq; s32 a; s32 b; s32 c; };

struct Buf_803CD16C { u8 data[0x10C]; };

struct LogHdr_803CD16C { u8 pad[0x4]; u16 seq; u8 pad2[0x1A]; };

struct Slot_803CD16C {
    s8 used; s8 f1; s8 f2; u8 f3; u32 f4; s32 f8; s32 fc; s32 f10; u8 pad_14[4];
    s32 f18; s32 f1c; s32 f20; u8 pad_24[8]; s32 f2c; s32 f30; u8 pad_34[0x138 - 0x34];
};

struct LogHdr_803CD3A8 { u8 pad[0x2]; u16 seq; };

struct LogHdr_803CC980 { u8 pad[0xA]; u16 seq; };

struct Snd_803CC980 {
    u8 f0; s8 state; s8 f2; u8 f3; u32 f4; SjRingBuffer *f8; int fc; u8 pad_10[0x14 - 0x10];
    int f14; int f18; int f1c; int f20; s32 f24; s32 f28; int f2c; int f30;
};

struct Ent_803CC884 {
    s8 used; s8 state; s8 f2; u8 f3; u32 f4; SjRingBuffer *f8; u8 pad_c[0x14 - 0xC];
    s32 f14; u8 pad_18[0x20 - 0x18]; s32 f20; s32 f24; s32 f28; u8 pad_2c[0x138 - 0x2C];
};

struct Hdr_803CCE9C { u8 used; u8 f1; };

struct LogHdr_803CCE9C { u8 pad[0x6]; u16 seq; };

extern "C" {
s32 TLobby__sub_803CC4C0(Obj_803CC4C0 *p);
extern Ent_803CC294 *afs_archive_toc_table[];
extern s32 lobby_adxf_current_file_id;
extern Slot_803CD16C *lobby_adxf_open_file_handle;
extern s32 lobby_afs_toc_entry_index;
extern u8 *lbl_805D75EC;
u32 adxstm_open_fname_range__6TLobbyFPviiii(Buf_803CD16C *, s32, s32, s32, s32);
extern u16 lbl_8057B7B0[16];
extern LogEnt_803CD16C lbl_8057B7D0[];
extern Slot_803CD16C adxf_file_handle_pool[];
extern s32 adxf_log_write_index;
Slot_803CD16C *adxf_open_afs__6TLobbyFii(s32 arg0, s32 arg1);
u32 TLobby__sub_803C8CDC(u32, s32, s32);
Slot_803CD16C *adxf_open__6TLobbyFUii(u32 arg0, s32 arg1);
s32 invalidate_cache__6TLobbyFv(s32, s32);
extern s32 lbl_805D75E4;
extern s32 lbl_805D75E8;

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
// Command history: one entry per call (phase 0) and per return (phase 1) of an ADXF command.
inline void hist_803CC294(s32 cmd, s32 phase, s32 a, s32 b, s32 c) {
    LogEnt_803CD16C *e;
    adxf_log_write_index %= 256;
    e = &lbl_8057B7D0[adxf_log_write_index];
    if (phase == 0) {
        lbl_8057B7B0[cmd]++;
    }
    e->type = cmd;
    e->phase = phase;
    e->seq = lbl_8057B7B0[cmd];
    e->a = a;
    e->b = b;
    e->c = c;
    adxf_log_write_index++;
}

// ADXF_SetReqRdSct (named by its message). The linker removed it; its message opens the TU's string pool.
void adxf_set_req_rd_sct(Snd_803CC980 *adxf, s32 nsct) {
    if (adxf->state == 2) {
        TLobby::notify_error("E0041201:state is reading(ADXF_SetReqRdSct)");
        return;
    }
    adxf->f2c = nsct;
}

inline s32 check_803CC294(s32 arg0, s32 arg1) {
    if (arg0 < 0 || arg0 >= 0x100) {
        TLobby::notify_error("E9040828:'ptid' is range outside.");
        return -3;
    }
    if (afs_archive_toc_table[arg0] == NULL) {
        TLobby::notify_error("E9040828:'ptid' is range outside.");
        return -3;
    }
    if (arg1 < 0 || arg1 >= afs_archive_toc_table[arg0]->f8) {
        TLobby::notify_error("E9040828:'flid' is range outside.");
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
        TLobby::notify_error("E9040832:'adxf' is NULL.(ADXF_GetStat)");
        return -3;
    }
    return p->b;
}

// ADXF_GetNumReadSct and ADXF_GetNumReqSct (named by their messages): removed by the linker, their
// messages stay in the string pool between ADXF_GetStat's and ADXF_GetFsizeByte's.
s32 adxf_get_num_read_sct(Snd_803CC980 *adxf) {
    if (adxf == NULL) {
        TLobby::notify_error("E9040831:'adxf' is NULL.(ADXF_GetNumReadSct)");
        return -3;
    }
    return adxf->f20;
}

s32 adxf_get_num_req_sct(Snd_803CC980 *adxf) {
    if (adxf == NULL) {
        TLobby::notify_error("E9040830:'adxf' is NULL.(ADXF_GetNumReqSct)");
        return -3;
    }
    return adxf->f1c;
}

s32 TLobby::adxf_get_fsize_byte() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        TLobby::notify_error("E9040829:'adxf' is NULL.(ADXF_GetFsizeByte)");
        return -3;
    }
    return *(s32 *)&this->m_up;
}
s32 TLobby__sub_803CC53C(u8 *arg0) {
    if (arg0 == NULL) {
        TLobby::notify_error("E9040828:'adxf' is NULL.(ADXF_GetFsizeSct)");
        return -3;
    }
    return *(s32 *)((s8 *)arg0 + 0xC);
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

// ADXF_Tell (named by its message): removed by the linker, its message stays in the string pool.
s32 adxf_tell(Snd_803CC980 *adxf) {
    if (adxf == NULL) {
        TLobby::notify_error("E9040827:'adxf' is NULL.(ADXF_Tell)");
        return -3;
    }
    return adxf->f14;
}

inline s32 stop_803CC980(Snd_803CC980 *adxf) {
    s32 sp8;
    hist_803CC294(5, 0, (s32)adxf, -1, -1);
    if (adxf == NULL) {
        TLobby::notify_error("E9040822:'adxf' is NULL.(ADXF_Stop)");
        return -3;
    }
    if (adxf->state == 1) {
        return adxf->f14;
    }
    if (adxf->state == 3) {
        adxf->state = 1;
        return adxf->f14;
    }
    if (adxf->f4 == 0) {
        TLobby::notify_error("E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
        return -1;
    }
    TLobby::init_once();
    TLobby__sub_803C89C4((u8 *)adxf->f4);
    TLobby__sub_803C85AC((u8 *)adxf->f4, &sp8);
    adxf->f20 = sp8;
    if (adxf->f8 != NULL && adxf->f2 == 0) {
        if (lbl_805D75E4 == 1) {
            invalidate_cache__6TLobbyFv(adxf->f24, adxf->f28);
        }
        adxf->f8->interface->destroy(adxf->f8);
        adxf->f8 = NULL;
    }
    adxf->state = 1;
    TLobby::release_ref();
    hist_803CC294(5, 1, (s32)adxf, -1, -1);
    return adxf->f14;
}

// ADXF_Seek (named by its messages)
s32 TLobby::adxf_seek(void *handle, int pos, int type) {
    Snd_803CC980 *adxf = (Snd_803CC980 *)handle;
    hist_803CC294(6, 0, (s32)adxf, pos, type);
    if (adxf == NULL) {
        TLobby::notify_error("E9040825:'adxf' is NULL.(ADXF_Seek)");
        return -3;
    }
    if (adxf->state == 2) {
        stop_803CC980(adxf);
    }
    if (type == 0) {
        adxf->f14 = pos;
    } else if (type == 1) {
        adxf->f14 += pos;
    } else if (type == 2) {
        adxf->f14 = adxf->fc + pos;
    } else {
        TLobby::notify_error("E9040826:'type' is illigal.(ADXF_Seek)");
        return -3;
    }
    if (adxf->f14 < 0) {
        adxf->f14 = 0;
    } else if (adxf->f14 > adxf->fc) {
        adxf->f14 = adxf->fc;
    }
    hist_803CC294(6, 1, (s32)adxf, pos, type);
    return adxf->f14;
}

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
                    p->f8->interface->destroy(p->f8);
                    p->f8 = NULL;
                }
            }
        }
    }
    TLobby::release_ref();
}

s32 TLobby::adxf_stop() {
    return stop_803CC980((Snd_803CC980 *)this);
}
#pragma pop

s32 TLobby::read_checked_align(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 & 0x1F) {
        TLobby::notify_error("E0120401:'buf' isn't 32byte alignment.(ADXF_ReadNw)");
        return -3;
    }
    return TLobby::adxf_read_nw32((void *)arg0, arg1, (void *)arg2);
}
#define LE32_803CD5C4(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
// ADXF_ReadNw32 (named by its messages)
s32 TLobby::adxf_read_nw32(void *handle, int nsct, void *buf) {
    Snd_803CC980 *adxf = (Snd_803CC980 *)handle;
    SjRingBuffer *sj;
    s32 rqsct;
    hist_803CC294(4, 0, (s32)adxf, nsct, (s32)buf);
    if (adxf == NULL) {
        TLobby::notify_error("E9040816:'adxf' is NULL.(ADXF_ReadNw32)");
        return -3;
    }
    if (nsct < 0) {
        TLobby::notify_error("E9040817:'nsct' is negative.(ADXF_ReadNw32)");
        return -3;
    }
    if (buf == NULL) {
        TLobby::notify_error("E9040818:'buf' is NULL.(ADXF_ReadNw32)");
        return -3;
    }
    if (adxf->state == 2) {
        return 0;
    }
    if (adxf->f8 != NULL) {
        TLobby::notify_error("E9040821:'sj' is NULL.(ADXF_ReadNw32)");
        return -1;
    }
    sj = sj_ring_buffer_create(buf, nsct << 11, 0);
    if (sj == NULL) {
        return -2;
    }
    adxf->f24 = (s32)buf;
    adxf->f28 = nsct << 11;
    TLobby::init_once();
    if (lbl_805D75E4 == 1) {
        invalidate_cache__6TLobbyFv(adxf->f24, adxf->f28);
    }
    if (TLobby__sub_803C8B2C((u8 *)adxf->f4) != 1) {
        TLobby__sub_803C89C4((u8 *)adxf->f4);
    }
    TLobby::init_once();
    adxf->f18 = adxf->f30 + adxf->f14;
    adxf->f1c = nsct < adxf->fc - adxf->f14 ? nsct : adxf->fc - adxf->f14;
    adxf->f20 = rqsct = 0;
    if (adxf->f1c == 0) {
        adxf->state = 3;
    } else {
        TLobby__sub_803C8514((u8 *)adxf->f4, adxf->f1c);
        ((TLobby *)adxf->f4)->set_scroll_position(-1);
        ((TLobby *)adxf->f4)->set_buffer((void **)sj);
        ((TLobby *)adxf->f4)->set_field_10_and_notify(adxf->f30 + adxf->f14);
        TLobby__sub_803C8578((u8 *)adxf->f4, adxf->f2c);
        adxf->state = 2;
        ((TLobby *)adxf->f4)->init_stream_position();
        rqsct = adxf->f1c;
    }
    TLobby::release_ref();
    if (rqsct <= 0) {
        sj->interface->destroy(sj);
    } else {
        adxf->f8 = sj;
    }
    adxf->f2 = 0;
    TLobby::release_ref();
    hist_803CC294(4, 1, (s32)adxf, nsct, (s32)buf);
    return rqsct;
}

// ADXF_ReadSj32 (named by its messages): removed by the linker, its three messages stay in the string pool.
s32 adxf_read_sj32(Snd_803CC980 *adxf, s32 nsct, SjRingBuffer *sj) {
    s32 rqsct;
    if (adxf == NULL) {
        TLobby::notify_error("E9040811:'adxf' is NULL.(ADXF_ReadSj32)");
        return -3;
    }
    if (nsct < 0) {
        TLobby::notify_error("E9040812:'nsct'is negative.(ADXF_ReadSj32)");
        return -3;
    }
    if (sj == NULL) {
        TLobby::notify_error("E9040813:'sj'is NULL.(ADXF_ReadSj32)");
        return -3;
    }
    TLobby::init_once();
    adxf->f18 = adxf->f30 + adxf->f14;
    adxf->f1c = nsct < adxf->fc - adxf->f14 ? nsct : adxf->fc - adxf->f14;
    adxf->f20 = rqsct = 0;
    if (adxf->f1c == 0) {
        adxf->state = 3;
    } else {
        TLobby__sub_803C8514((u8 *)adxf->f4, adxf->f1c);
        ((TLobby *)adxf->f4)->set_scroll_position(-1);
        ((TLobby *)adxf->f4)->set_buffer((void **)sj);
        ((TLobby *)adxf->f4)->set_field_10_and_notify(adxf->f30 + adxf->f14);
        TLobby__sub_803C8578((u8 *)adxf->f4, adxf->f2c);
        adxf->state = 2;
        ((TLobby *)adxf->f4)->init_stream_position();
        rqsct = adxf->f1c;
    }
    TLobby::release_ref();
    return rqsct;
}

inline s32 rd32_803CD5C4(u8 *p) {
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}
inline s32 state_803CD5C4(void) {
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error("E9040832:'adxf' is NULL.(ADXF_GetStat)");
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
        TLobby::notify_error("E0110902:can't open file.(ADXF_OpenAfs)");
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
            stop_803CC980((Snd_803CC980 *)this);
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
        seq = lbl_8057B7B0[2] + 1;
        e->type = 2;
        e->phase = 0;
        e->seq = seq;
        e->a = arg0;
        e->b = arg1;
        lbl_8057B7B0[2] = seq;
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
        e->seq = lbl_8057B7B0[2];
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
        TLobby::notify_error("E9081901:illigal parameter fname=null.(ADXF_Open)");
        return -1;
    }
    h = TLobby__sub_803C8CDC(name, mode, 0);
    if (h == 0) {
        TLobby::notify_error("E0110901:can't open file.(ADXF_Open)");
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

// adxf_ChkPrmPt (named by its messages): inlined into ADXF_LoadPartitionNw below.
s32 adxf_chk_prm_pt(s32 ptid, void *ptinfo) {
    if (ptid < 0 || ptid >= 0x100) {
        TLobby::notify_error("E9040801:partition ID is range outside.(adxf_ChkPrmPt)");
        return -3;
    }
    if (ptinfo == NULL) {
        TLobby::notify_error("E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
        return -3;
    }
    return 0;
}

// ADXF_AddPartition and ADXF_LoadPartition (named by their messages): removed by the linker.
// Only their messages are left, between adxf_ChkPrmPt's and ADXF_GetPtStat's in the string pool.
s32 adxf_add_partition(void) {
    TLobby::notify_error("E9040808:can't open.(ADXF_AddPartition)");
    return -1;
}

s32 adxf_load_partition(s32 broken) {
    if (broken) {
        TLobby::notify_error("E9040810:file is broken.(ADXF_LoadPartition)");
        return -1;
    }
    TLobby::notify_error("E9040809:read error.(ADXF_LoadPartition)");
    return -1;
}
#pragma pop

s32 TLobby::read_afs_toc(s32 arg0) {
    s16 *arr;
    Ent_803CD5C4 *e;
    s32 st;
    s32 i;
    if (arg0 != lobby_adxf_current_file_id) {
        TLobby::notify_error("E0041303:illigal parameter 'ptid'.(ADXF_GetPtStat)");
        return -3;
    }
    st = state_803CD5C4();
    if (st != 3) {
        return st;
    }
    e = ((Ent_803CD5C4 * *)&afs_archive_toc_table)[arg0];
    arr = e->arr;
    if (e->f8 == 0) {
        s32 n;
        if (memcmp(lbl_805D75EC, "AFS", 3) != 0) {
            TLobby::notify_error("E0040701:Illigal format(not AFS).(ADXF_GetPtStat)");
            TLobby__sub_803CD804();
            return 4;
        }
        n = rd32_803CD5C4(lbl_805D75EC + 4);
        if (n > 0x10000) {
            TLobby::notify_error("E0040702:Illigal number of file.(ADXF_GetPtStat)");
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
        if (TLobby::adxf_read_nw32(lobby_adxf_open_file_handle, 1, lbl_805D75EC) < 0) {
            st = 4;
            TLobby__sub_803CD804();
        } else {
            st = lobby_adxf_open_file_handle->f1;
        }
    }
    return st;
}
#pragma pop

void TLobby__sub_803CD804(void) {
    ((TLobby *)lobby_adxf_open_file_handle)->close_adxf_handle();
    lobby_adxf_open_file_handle = 0;
    lobby_adxf_current_file_id = -1;
    lobby_afs_toc_entry_index = 0;
    lbl_805D75E8 = 0;
}

u8 adxf_open_file_buffer[0x2080];
u8 *lbl_805D75F0;

// ADXF_LoadPartitionNw (named by its messages)
s32 adxf_open_file__6TLobbyFiPviPv(s32 id, const char *name, s32 arg2, Ent_803CC294 *e) {
    s32 r;
    u8 *buf;
    r = adxf_chk_prm_pt(id, e);
    if (r < 0) {
        return r;
    }
    if (lobby_adxf_current_file_id >= 0) {
        TLobby::notify_error("E0042401:multi-load partition.(ADXF_LoadPartitionNw)");
        return -1;
    }
    lobby_adxf_open_file_handle = adxf_open__6TLobbyFUii((u32)name, arg2);
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error("E9040804:can't open file.(ADXF_LoaddPartitionNw)");
        return -1;
    }
    lobby_adxf_current_file_id = id;
    lobby_afs_toc_entry_index = 0;
    memset(e, 0, 0x118);
    afs_archive_toc_table[id] = e;
    e->next = NULL;
    strncpy(e->name, name, 0x100);
    e->f110 = arg2;
    e->fe = 0;
    buf = (u8 *)((s32)(adxf_open_file_buffer + 0x20) & ~0x1F);
    lbl_805D75F0 = buf;
    lbl_805D75EC = buf;
    r = TLobby::adxf_read_nw32(lobby_adxf_open_file_handle, 1, buf);
    if (r < 0) {
        ((TLobby *)lobby_adxf_open_file_handle)->close_adxf_handle();
        return r;
    }
    e->f8 = 0;
    return 0;
}

// ADXF_LoadPtNwEx (named by its messages) and a second loader whose messages also say ADXF_LoadPartition
// (real name unknown): removed by the linker. Only their messages are left after ADXF_LoadPartitionNw's, at
// the end of the string pool; the bodies follow ADXF_LoadPartitionNw.
s32 adxf_load_pt_nw_ex(s32 ptid, const char *fname, s32 dir, Ent_803CC294 *ptinfo, void *tmpbuf, s32 tbsize) {
    if (tmpbuf == NULL) {
        TLobby::notify_error("E1110701:'tmpbuf' is null.(ADXF_LoadPtNwEx)");
        return -3;
    }
    if (tbsize <= 0) {
        TLobby::notify_error("E1110702:'tbsize' <= 0.(ADXF_LoadPtNwEx)");
        return -3;
    }
    if (adxf_chk_prm_pt(ptid, ptinfo) < 0) {
        return -3;
    }
    if (lobby_adxf_current_file_id >= 0) {
        TLobby::notify_error("E0042401:multi-load partition.(ADXF_LoadPtNwEx)");
        return -1;
    }
    lobby_adxf_open_file_handle = adxf_open__6TLobbyFUii((u32)fname, dir);
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error("E9040804:can't open file.(ADXF_LoadPtNwEx)");
        return -1;
    }
    return 0;
}

s32 adxf_load_partition2(s32 ptid, const char *fname, s32 dir, Ent_803CC294 *ptinfo) {
    if (adxf_chk_prm_pt(ptid, ptinfo) < 0) {
        return -3;
    }
    if (adxf_open__6TLobbyFUii((u32)fname, dir) == NULL) {
        TLobby::notify_error("E9040804:can't open file.(ADXF_LoadPartition)");
        return -1;
    }
    if (ptinfo->f8 == 0) {
        TLobby::notify_error("E9040806:file is broken.(ADXF_LoadPartition)");
        return -1;
    }
    TLobby::notify_error("E9040805:read error.(ADXF_LoadPartition)");
    return -1;
}

}
