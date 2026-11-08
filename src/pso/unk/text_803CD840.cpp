#include "pso/system/MiddlewareInterruptLock.h"

#include "types.h"
#include "pso/unk/TLobby.h"

#pragma readonly_strings on

struct Ent_803CE198 { s32 a; s32 b; u8 pad[8]; };

struct Sub_803CE198 { u8 pad[0x214]; Ent_803CE198 e[1]; };

struct Obj_803CE198 { u8 pad[0xa0]; Sub_803CE198 sub; };

struct Ent_803CD840 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[2];
    s8 fE;
    u8 padF;
    char name[0x100];
    s32 f110;
    u8 pad114[4];
};

#define BE32_803CDEC8(p) (((p)[0] << 24) | ((p)[1] << 16) | ((p)[2] << 8) | (p)[3])
#define BE16_803CDEC8(p) (((p)[0] << 8) | (p)[1])
struct Ent3_803CDEC8 { u8 b; u8 pad[3]; s32 a; u8 pad8[8]; };

struct Ent1_803CDEC8 { s32 w[4]; };

struct Ent2_803CDEC8 { s16 h[4]; };

struct Out_803CDEC8 {
    u8 f0;
    u8 f1;
    u8 pad2[2];
    s32 f4;
    f32 f8;
    s8 n3;
    u8 padd[3];
    Ent3_803CDEC8 e3[32];
    s32 n1;
    Ent1_803CDEC8 e1[32];
    s32 n2;
    Ent2_803CDEC8 e2[1];
};

#define BE32_803CDB0C(p) (((p)[0] << 24) | ((p)[1] << 16) | ((p)[2] << 8) | (p)[3])
#define BE16_803CDB0C(p) (((p)[0] << 8) | (p)[1])
struct Stream_803CDB0C;
struct Chunk_803CDB0C {
    u8 *data;
    s32 len;
};

struct Hdr_803CDB0C {
    u32 magic;
    s32 size;
    u8 b[2];
    s16 len;
    s32 w;
};

struct StreamVt_803CDB0C {
    u8 pad[0x18];
    void (*get)(Stream_803CDB0C *, s32, s32, Chunk_803CDB0C *);
    void (*release)(Stream_803CDB0C *, s32, Chunk_803CDB0C *);
    void (*commit)(Stream_803CDB0C *, s32, Chunk_803CDB0C *);
    s32 (*avail)(Stream_803CDB0C *, s32);
};

struct Stream_803CDB0C {
    StreamVt_803CDB0C *vt;
};

struct Obj_803CDB0C {
    u8 f0;
    s8 f1;
    s8 nch;
    u8 pad3;
    s8 f4;
    u8 pad5[3];
    s32 f8;
    u8 padC[0x10];
    Stream_803CDB0C *src;
    Stream_803CDB0C *ch[0x23];
    s8 n;
};

extern "C" {
char *strncpy(char *, const char *, u32);
void *memset(void *, s32, u32);
s32 adxf_read_nw32__6TLobbyFPviPv(void *, int, int);
void *adxf_open__6TLobbyFUii(const char *, s32);
extern char lbl_8047C818[];
extern Ent_803CD840 *afs_archive_toc_table[256];
u8 adxf_open_file_buffer[0x2080];
extern s32 lobby_adxf_current_file_id;
extern void *lobby_adxf_open_file_handle;
extern s32 lobby_afs_toc_entry_index;
extern s32 lbl_805D75EC;
s32 lbl_805D75F0;
s32 adxf_open_file__6TLobbyFiPviPv(s32 id, const char *name, s32 arg2, Ent_803CD840 *e);
int memcmp(const void *, const void *, unsigned long);
unsigned long strlen(const char *);
char *cri_copyright_string = "(c)CRI";
s32 parse_aix_header__6TLobbyFPviPv(u8 *arg0, s32 arg1, Out_803CDEC8 *arg2);
void TLobby__sub_803D3130(Chunk_803CDB0C *, s32, Chunk_803CDB0C *, Chunk_803CDB0C *);
void *memcpy(void *, const void *, u32);

#pragma dont_inline off
#pragma inline_depth(4)
inline s32 check_803CD840(char *msg, s32 id, Ent_803CD840 *e) {
    if (id < 0 || id >= 0x100) {
        TLobby::notify_error(msg + 0x3E8);
        return -3;
    }
    if (e == NULL) {
        TLobby::notify_error(msg + 0x420);
        return -3;
    }
    return 0;
}
s32 adxf_open_file__6TLobbyFiPviPv(s32 id, const char *name, s32 arg2, Ent_803CD840 *e) {
    char *msg = lbl_8047C818;
    s32 r;
    s32 aligned;
    r = check_803CD840(msg, id, e);
    if (r < 0) {
        return r;
    }
    if (lobby_adxf_current_file_id >= 0) {
        TLobby::notify_error(msg + 0x56C);
        return -1;
    }
    lobby_adxf_open_file_handle = adxf_open__6TLobbyFUii(name, arg2);
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error(msg + 0x5A4);
        return -1;
    }
    lobby_adxf_current_file_id = id;
    lobby_afs_toc_entry_index = 0;
    memset(e, 0, 0x118);
    afs_archive_toc_table[id] = e;
    e->f0 = 0;
    strncpy(e->name, name, 0x100);
    e->f110 = arg2;
    e->fE = 0;
    aligned = (s32)(adxf_open_file_buffer + 0x20) & ~0x1F;
    lbl_805D75F0 = aligned;
    lbl_805D75EC = aligned;
    r = adxf_read_nw32__6TLobbyFPviPv(lobby_adxf_open_file_handle, 1, aligned);
    if (r < 0) {
        ((TLobby *)lobby_adxf_open_file_handle)->close_adxf_handle();
        return r;
    }
    e->f8 = 0;
    return 0;
}

struct StreamSlot_803CD99C {
    s8 active;
    s8 phase;
    s8 nch;
    s8 paused;
    u8 pad4[4];
    s32 consumed;
    u8 padC[0x10];
    Stream_803CDB0C *src;
    u8 pad20[0x80];
    Out_803CDEC8 aix;
    u8 pad4C0[0x18];
};

StreamSlot_803CD99C lbl_8057FFD0[4];
void TLobby__sub_803CD99C(void);

void TLobby__sub_803CD99C(void) {
    StreamSlot_803CD99C *slot;
    s32 i;
    s32 size;
    Stream_803CDB0C *src;
    Chunk_803CDB0C rest;
    s32 active;
    Chunk_803CDB0C chunk;

    for (i = 0; i < 4; i++) {
        slot = &lbl_8057FFD0[i];
        active = slot->active;
        if (active == 1) {
            if (slot->phase == 1) {
                src = slot->src;
                src->vt->get(src, 1, 0x1800, &chunk);
                size = parse_aix_header__6TLobbyFPviPv(chunk.data, chunk.len, &slot->aix);
                if (size == 0) {
                    src->vt->release(src, 1, &chunk);
                } else {
                    if (size != chunk.len) {
                        while (1) {
                        }
                    }
                    TLobby__sub_803D3130(&chunk, size, &chunk, &rest);
                    src->vt->commit(src, 0, &chunk);
                    src->vt->release(src, 1, &rest);
                    slot->consumed += size;
                    slot->phase = 2;
                }
            } else if (slot->phase == 2 && slot->paused == 0) {
                if (((TLobby *)slot)->demux_stream_chunks() == -1) {
                    ((TLobby *)slot)->demux_stream_chunks();
                }
            }
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 parse_803CDB0C(u8 *data, u32 len, Hdr_803CDB0C *h) {
    u8 *p;
    if (len < 0x10) {
        return 0;
    }
    p = data;
    *(u32 *)((u8 *)h + 0) = BE32_803CDB0C(p);
    p += 4;
    *(s32 *)((u8 *)h + 4) = BE32_803CDB0C(p);
    p += 4;
    ((u8 *)h)[8] = *p++;
    ((u8 *)h)[9] = *p++;
    *(s16 *)((u8 *)h + 10) = BE16_803CDB0C(p);
    p += 2;
    *(s32 *)((u8 *)h + 12) = BE32_803CDB0C(p);
    p += 4;
    if (p - data != sizeof(Hdr_803CDB0C)) {
        while (1) {
        }
    }
    return 0x10;
}
s32 TLobby::demux_stream_chunks() {
    Obj_803CDB0C *o = (Obj_803CDB0C *)this;
    Stream_803CDB0C *s;
    Stream_803CDB0C **ch;
    s32 n;
    s32 i;
    s32 ret;
    s32 c;
    s32 len;
    s32 j;
    Hdr_803CDB0C hdr;
    Chunk_803CDB0C c1;
    Chunk_803CDB0C c2;
    Chunk_803CDB0C tmp;
    ret = -3;
    ch = o->ch;
    n = o->n;
    s = o->src;
    for (i = 0; i < n; i++) {
        s->vt->get(s, 1, 0x7FFFFFFF, &c1);
        if (parse_803CDB0C(c1.data, c1.len, &hdr) == 0) {
            s->vt->release(s, 1, &c1);
            return ret;
        }
        if (c1.len < hdr.size + 8) {
            s->vt->release(s, 1, &c1);
            return ret;
        }
        if (hdr.magic == 0x41495845) {
            TLobby__sub_803D3130(&c1, hdr.size + 8, &c1, &c2);
            s->vt->commit(s, 0, &c1);
            s->vt->release(s, 1, &c2);
            if (s->vt->avail(s, 1) <= 0) {
                o->f4 = 0;
            }
            if (o->f4 == 0) {
                o->f1 = 3;
            }
            return ret;
        }
        c = hdr.b[0];
        if (c >= o->nch) {
            while (1) {
            }
        }
        if (ch[c]->vt->avail(ch[c], 0) < hdr.len) {
            s->vt->release(s, 1, &c1);
            return ret;
        }
        middleware_interrupt_lock_enter();
        ret = hdr.w;
        TLobby__sub_803D3130(&c1, hdr.size + 8, &c1, &c2);
        s->vt->release(s, 1, &c2);
        TLobby__sub_803D3130(&c1, 0x10, &c1, &c2);
        if (c2.len < hdr.len) {
            while (1) {
            }
        }
        len = hdr.len;
        for (j = 0; j < len; j += tmp.len) {
            ch[c]->vt->get(ch[c], 0, c2.len - j, &tmp);
            memcpy(tmp.data, c2.data + j, tmp.len);
            ch[c]->vt->commit(ch[c], 1, &tmp);
        }
        s->vt->commit(s, 0, &c1);
        s->vt->commit(s, 0, &c2);
        o->f8 = c2.len + (c1.len + o->f8);
        middleware_interrupt_lock_leave();
    }
    return ret;
}
#pragma pop

s32 parse_aix_header__6TLobbyFPviPv(u8 *arg0, s32 arg1, Out_803CDEC8 *arg2) {
    s32 len;
    s32 hdr;
    u8 *p;
    s32 i;
    len = strlen(cri_copyright_string);
    if (arg1 < 0x1800) {
        return 0;
    }
    if (BE32_803CDEC8(arg0) != 0x41495846) {
        return 0;
    }
    hdr = BE32_803CDEC8(arg0 + 4);
    if (memcmp(arg0 + (hdr + 8 - len), cri_copyright_string, len) != 0) {
        return 0;
    }
    arg2->f0 = arg0[8];
    arg2->f1 = arg0[9];
    arg2->f8 = (s32)BE16_803CDEC8(arg0 + 0xA);
    arg2->f4 = BE32_803CDEC8(arg0 + 0xC);
    arg2->n1 = BE16_803CDEC8(arg0 + 0x18);
    p = arg0 + 0x20;
    for (i = 0; i < arg2->n1; i++) {
        arg2->e1[i].w[0] = BE32_803CDEC8(p);
        arg2->e1[i].w[1] = BE32_803CDEC8(p + 4);
        arg2->e1[i].w[2] = BE32_803CDEC8(p + 8);
        arg2->e1[i].w[3] = BE32_803CDEC8(p + 12);
        p += 0x10;
    }
    arg2->n2 = (s8)p[0];
    p += 8;
    for (i = 0; i < arg2->n2; i++) {
        arg2->e2[i].h[0] = BE16_803CDEC8(p);
        arg2->e2[i].h[1] = BE16_803CDEC8(p + 2);
        arg2->e2[i].h[2] = BE16_803CDEC8(p + 4);
        arg2->e2[i].h[3] = BE16_803CDEC8(p + 6);
        p += 8;
    }
    arg2->n3 = p[0];
    p += 8;
    for (i = 0; i < arg2->n3; i++) {
        arg2->e3[i].a = BE32_803CDEC8(p);
        arg2->e3[i].b = p[4];
        p += 8;
    }
    return hdr + 8;
}

void TLobby::get_entry_pair(s32 i, s32 *a, s32 *b) {
    Obj_803CE198 *self = (Obj_803CE198 *)this;
    Sub_803CE198 *s = &self->sub;
    if (a != 0) {
        *a = s->e[i].a;
    }
    if (b != 0) {
        *b = s->e[i].b;
    }
}

}
