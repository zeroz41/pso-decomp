#include "types.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

struct S_803DDD78 { s8 a, b; };

struct S_803DDD94 { s8 a, b, c, d; };

struct S_803DA7E0 { s32 a, b, c, d, e; };

struct Ent_803DD6DC { s32 f0; s32 f4; s32 f8; };

struct Obj_803DD6DC { struct Ent_803DD6DC *ents; u32 count; };

typedef struct Info_803DDA68 { u32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } Info_803DDA68;

typedef struct Ent_803DDA68 { Info_803DDA68 *info; s32 f4; s32 f8; } Ent_803DDA68;

typedef struct Obj_803DDA68 { Ent_803DDA68 *ents; } Obj_803DDA68;

typedef struct Desc_803DDA68 { s32 f0; u16 w; u16 h; } Desc_803DDA68;

typedef struct Rec_803DDB34 { s32 f0; } Rec_803DDB34;

typedef struct Slot_803DDB34 { s32 f0; s32 f4; s32 f8; Rec_803DDB34 *rec; } Slot_803DDB34;

struct GvmTextureEntry_803DDDC8 {
    char* name;
    u32 attributes;
    u32 globalIndex;
};

struct GvmTextureList_803DDDC8 {
    GvmTextureEntry_803DDDC8* textures;
    u32 count;
};

struct GvmTextureHeader_803DDDC8 {
    u8 prefix[8];
    u16 flags;
    s16 directoryCount;
};

struct FileInfo_803DD784 { u8 pad[0x34]; u32 length; u32 f38; };

struct Tex_803DD784 { u8 pad[0x20]; void *buf; };

struct Slot_803DD784 { s32 f0; s32 f4; s32 f8; Tex_803DD784 *tex; s32 f10; s32 f14; };

s32 lbl_805D77A0;
extern "C" {
void TLobby__sub_803DDD78(S_803DDD78 *d, S_803DDD78 *s);
void copy_4word_struct__6TLobbyFPvPv(S_803DDD94 *d, S_803DDD94 *s);
void TObjPlayer__sub_803DD6DC(struct Obj_803DD6DC *arg0, s32 arg1);
extern S_803DA7E0 lbl_8058D470;
s32 load_texture_list(struct Obj_803DD6DC *arg0);
typedef void (*Fn_803DD6DC)(struct Obj_803DD6DC *, s32);
extern Fn_803DD6DC lbl_804FC688[];
s32 TObjPlayer__sub_803D9E38(s32 *arg0, u32 arg1, s32 *arg2, u32 *arg3);
s32 TObjPlayer__sub_803DAC48(Obj_803DDA68 *, s32, s32, s32, Desc_803DDA68 *, s32 *);
s32 TObjPlayer__sub_803DD91C(Obj_803DDA68 *obj, s32 idx);
s32 TObjPlayer__sub_803DDA68(Obj_803DDA68 *obj, s32 idx);
s32 find_free_slot__10TObjPlayerFPvPv(Slot_803DDB34 **, Rec_803DDB34 **);
s32 TObjPlayer__sub_803DAB7C(Obj_803DDA68 *, s32, s32);
extern s32 player_ref_entry_active_count;
s32 TObjPlayer__sub_803DDB34(Obj_803DDA68 *obj, s32 idx);
s32 strlen(const char*);
void replace_gvm_texture_directory(GvmTextureList_803DDDC8* list, s32 stride, const GvmTextureHeader_803DDDC8* header);
s32 load_gvm_texture_archive(u32 *arg0, GvmTextureList_803DDDC8 *list);
void DCFlushRange(void *, u32);
s32 DVDOpen(const char *, FileInfo_803DD784 *);
s32 DVDClose(FileInfo_803DD784 *);
s32 Dolphin_DVDReadPrio(FileInfo_803DD784 *, void *, s32, s32, s32);
extern u8 gvrt_header_read_buffer[];
extern Slot_803DD784 *record_array_ptr;
s32 read_gvrt_file_header(Obj_803DDA68 *obj, s32 idx);
void TObjPlayer__sub_803DD5E8(GvmTextureList_803DDDC8 *list, GvmTextureEntry_803DDDC8 *entries, u32 names, s32 count);
}
u32 *find_gvrt_texture_chunk(TLobby *arg0, u32 *arg1, u32 *arg2);
extern s32 ginja_draw_flags;

void set_ginja_draw_flags(s32 arg0) {
    ginja_draw_flags = arg0;
}

void TObjPlayer__sub_803DD5E8(GvmTextureList_803DDDC8 *list, GvmTextureEntry_803DDDC8 *entries, u32 names, s32 count) {
    int i;

    for (i = 0; i < count; ++i) {
        entries[i].name = (char *)(names + i * 0x1C);
    }
    list->textures = entries;
}

void TObjPlayer__sub_803DD6DC(struct Obj_803DD6DC *arg0, s32 arg1) {
    s32 idx;

    switch (arg0->ents[arg1].f4 & 0x5C000000) {
    case 0x0:
        idx = 0;
        break;
    case 0x40000000:
        idx = 1;
        break;
    case 0x8000000:
        idx = 2;
        break;
    case 0x4000000:
        idx = 3;
        break;
    default:
        idx = 2;
        break;
    }
    lbl_804FC688[idx](arg0, arg1);
}

s32 lbl_805D77A4;

#pragma push
#pragma optimize_for_size off
#pragma use_lmw_stmw off
s32 read_gvrt_file_header(Obj_803DDA68 *obj, s32 idx) {
    s32 sz;
    s32 id;
    s32 arg;
    s32 handle;
    Desc_803DDA68 desc;
    char name[32];
    FileInfo_803DD784 fi;
    u32 n;
    s32 r;
    u32 base = (u32)gvrt_header_read_buffer;
    FileInfo_803DD784 *pfi;
    u32 size;
    TObjPlayer__sub_803DA7E0();
    r = TObjPlayer__sub_803D9E38((s32 *)obj, (u32)idx, (s32 *)&id, (u32 *)&arg);
    if (r != 0) {
        return r;
    }
    ((TAdSinglePlyChrSelectGC *)name)->append_extension_if_missing((char *)(obj->ents[idx].info), ".GVR");
    pfi = &fi;
    if (DVDOpen(name, pfi) == 0) {
        lbl_8058D470.c = 2;
        return -1;
    }
    size = (fi.length + 0x1F) & ~0x1F;
    if (Dolphin_DVDReadPrio(pfi, (void *)base, 0x20, 0, 2) == -1) {
        DVDClose(pfi);
        return -1;
    }
    n = (u32)find_gvrt_texture_chunk((TLobby *)((void *)&desc), (u32 *)((u32 *)&sz), (u32 *)((u32 *)base));
    if (n == 0) {
        DVDClose(pfi);
        return -1;
    }
    if ((u32)id != 0xFFFFFFFF) {
        sz = id;
    }
    r = TObjPlayer__sub_803DAC48(obj, idx, sz, arg, &desc, &handle);
    if (r != 0) {
        DVDClose(pfi);
        return r;
    }
    n -= base;
    Dolphin_DVDReadPrio(pfi, record_array_ptr[handle].tex->buf, size - n, n, 2);
    DVDClose(pfi);
    return 1;
}
#pragma pop

s32 TObjPlayer__sub_803DD91C(Obj_803DDA68 *obj, s32 idx) {
    s32 sz;
    s32 id;
    s32 arg;
    s32 handle;
    Desc_803DDA68 desc;
    s32 r;
    u32 n;
    Info_803DDA68 *info;
    TObjPlayer__sub_803DA7E0();
    r = TObjPlayer__sub_803D9E38((s32 *)obj, (u32)idx, (s32 *)&id, (u32 *)&arg);
    if (r != 0) {
        return r;
    }
    n = (u32)find_gvrt_texture_chunk((TLobby *)((void *)&desc), (u32 *)((u32 *)&sz), (u32 *)((u32 *)obj->ents[idx].info));
    if (n == 0) {
        n = (u32)find_gvrt_texture_chunk((TLobby *)((void *)&desc), (u32 *)((u32 *)&sz), (u32 *)((u32 *)obj->ents[idx].info->f0));
        if (n == 0) {
            info = obj->ents[idx].info;
            desc.w = info->f10;
            desc.h = info->f14;
            desc.f0 = info->f4;
            n = info->f0;
        }
    }
    if ((u32)id != 0xFFFFFFFF) {
        sz = id;
    }
    r = TObjPlayer__sub_803DAC48(obj, idx, sz, arg, &desc, &handle);
    if (r != 0) {
        return r;
    }
    if (TObjPlayer__sub_803DAB9C(handle, n) < 0) {
        TObjPlayer__sub_803DAC1C(handle);
        return -1;
    }
    while (TObjPlayer::is_gvm_load_ok() != 1) {
    }
    return 1;
}

s32 TObjPlayer__sub_803DDA68(Obj_803DDA68 *obj, s32 idx) {
    s32 id;
    Desc_803DDA68 desc;
    s32 arg;
    s32 handle;
    s32 r;
    s32 v;
    Info_803DDA68 *info;
    TObjPlayer__sub_803DA7E0();
    r = TObjPlayer__sub_803D9E38((s32 *)obj, (u32)idx, (s32 *)&id, (u32 *)&arg);
    if (r != 0) {
        return r;
    }
    info = obj->ents[idx].info;
    desc.w = info->f10;
    desc.h = info->f14;
    desc.f0 = info->f4;
    v = obj->ents[idx].f8;
    if ((u32)id != 0xFFFFFFFF) {
        v = id;
    }
    if (TObjPlayer__sub_803DAC48(obj, idx, v, arg, &desc, &handle) >= 0) {
        return 1;
    }
    return -1;
}

s32 TObjPlayer__sub_803DDB34(Obj_803DDA68 *obj, s32 idx) {
    s32 id;
    s32 arg;
    s32 h;
    Slot_803DDB34 *slot;
    Rec_803DDB34 *rec;
    s32 r;
    s32 v;
    TObjPlayer__sub_803DA7E0();
    r = TObjPlayer__sub_803D9E38((s32 *)obj, (u32)idx, (s32 *)&id, (u32 *)&arg);
    if (r != 0) {
        return r;
    }
    v = obj->ents[idx].f8;
    if ((u32)id != 0xFFFFFFFF) {
        v = id;
    }
    switch (TObjPlayer__sub_803DA8E4(v, arg, 0, &h)) {
    case -1:
        return -1;
    case 0:
        h = find_free_slot__10TObjPlayerFPvPv(&slot, &rec);
        if (h < 0) {
            return -1;
        }
        slot->rec = rec;
        if ((u32)v != 0xFFFFFFFF) {
            slot->rec->f0 = v;
        }
        player_ref_entry_active_count++;
        TObjPlayer__sub_803DAB7C(obj, idx, h);
        break;
    }
    return 1;
}

s32 load_texture_list(struct Obj_803DD6DC *arg0) {
    u32 i;
    if (arg0->count == 0) {
        lbl_8058D470.c = 1;
        return -1;
    }
    for (i = 0; i < arg0->count; i++) {
        if (((s32 (*)(struct Obj_803DD6DC *, s32))TObjPlayer__sub_803DD6DC)(arg0, i) < 0) {
            lbl_8058D470.a = i;
            return -1;
        }
    }
    return 1;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void TLobby::bswap32_in_place(u32 *p) {
    u32 v = *p;
    *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}
#pragma pop

void TLobby__sub_803DDD20(s32 arg0) {
    lbl_805D77A4 = arg0;
    lbl_805D77A0 = arg0;
}

s32 TLobby__sub_803DDD2C(s32 arg0) {
    s32 temp_r4;
    temp_r4 = lbl_805D77A0;
    lbl_805D77A0 = temp_r4 + arg0;
    return temp_r4;
}

void TLobby__sub_803DDD40(s32 arg0, s32 arg1) {
    switch (arg1) {
    case 1:
        lbl_805D77A0 += arg0;
        return;
    case 0:
        lbl_805D77A0 = lbl_805D77A4 + arg0;
        return;
    }
}
#pragma push
#pragma scheduling off
#pragma peephole off
void TLobby__sub_803DDD78(S_803DDD78 *d, S_803DDD78 *s) {
    s32 a = s->a;
    d->a = a;
    s32 b = s->b;
    d->b = b;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void copy_4word_struct__6TLobbyFPvPv(S_803DDD94 *d, S_803DDD94 *s) {
    s32 t;
    t = s->a;
    d->a = t;
    t = s->b;
    d->b = t;
    t = s->c;
    d->c = t;
    t = s->d;
    d->d = t;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
void replace_gvm_texture_directory(GvmTextureList_803DDDC8* list, s32 stride, const GvmTextureHeader_803DDDC8* header) {
    u16 image;
    s32 off;
    u16 flags;
    s32 names;
    s32 formats;
    s32 dimensions;
    s32 alternateGlobal;
    s32 globals;
    s32 count;
    u8* record;
    GvmTextureEntry_803DDDC8* texture;
    s32 index;
    index = 0;
    off = 0;
    flags = header->flags;
    names = flags & 1;
    formats = flags & 2;
    dimensions = flags & 4;
    alternateGlobal = flags & 0x400;
    globals = flags & 8;
    count = header->directoryCount;
    while (index < count) {
        record = (u8*)TLobby__sub_803DDD2C(stride);
        texture = (GvmTextureEntry_803DDDC8*)((u8*)list->textures + off);
        TLobby__sub_803DDD78((S_803DDD78*)&image, (S_803DDD78*)record);
        texture->attributes = (texture->attributes & 0xFFFF0000) | image;
        record += 2;
        if (names) {
            s32 length = strlen((char*)record);
            if (length > 0) {
                ((TLobby *)(texture->name))->move_data(record, length);
            }
            record += 0x1C;
        }
        if (formats) record += 2;
        if (dimensions) record += 2;
        if (alternateGlobal) {
            if (globals) {
                copy_4word_struct__6TLobbyFPvPv((S_803DDD94*)&texture->globalIndex, (S_803DDD94*)record);
                texture->attributes |= 0x01000000;
            }
        } else if (globals) {
            copy_4word_struct__6TLobbyFPvPv((S_803DDD94*)&texture->globalIndex, (S_803DDD94*)record);
            texture->attributes |= 0x00800000;
        }
        off += 0xC;
        index++;
    }
}
#pragma pop

s32 calc_gvm_entry_stride(u16 arg0) {
    s32 r = 2;
    if (arg0 & 1) r = 0x1E;
    if (arg0 & 2) r += 2;
    if (arg0 & 4) r += 2;
    if (arg0 & 8) r += 4;
    return r;
}

void TLobby::seek_gvrt_chunk() {
    s32 spC;
    s32 sp8;
    do {
        spC = *(s32 *)((s8 *)((s32 *)TLobby__sub_803DDD2C(4)) + 0);
        TLobby::bswap32_in_place((u32 *)&spC);
        switch (spC) {
        case 0x4D4D4F43:
        case 0x564E4F43:
        case 0x4E4C444D:
        case 0x494D5650:
        case 0x4C505647:
        case 0x43474D49:
            sp8 = *(s32 *)((s8 *)((s32 *)TLobby__sub_803DDD2C(4)) + 0);
            TLobby::bswap32_in_place((u32 *)&sp8);
            TLobby__sub_803DDD40(sp8, 1);
            break;
        case 0x54525647:
            TLobby__sub_803DDD40(-4, 1);
            break;
        default:
            sp8 = *(s32 *)((s8 *)((s32 *)TLobby__sub_803DDD2C(4)) + 0);
            TLobby::bswap32_in_place((u32 *)&sp8);
            TLobby__sub_803DDD40(sp8, 1);
            break;
        }
    } while ((spC + 0xABAE0000) != 0x5647U);
}

#pragma push
#pragma use_lmw_stmw off
s32 load_gvm_texture_archive(u32 *arg0, GvmTextureList_803DDDC8 *list) {
    s32 id;
    s32 arg;
    s32 handle;
    u32 *tex;
    s32 r;
    s32 i;
    s32 k;
    s32 data;
    u32 *hdr;
    s32 n;
    arg = -1;
    TObjPlayer__sub_803DA7E0();
    if (arg0 == NULL) {
        lbl_8058D470.c = 1;
        return -1;
    }
    TLobby__sub_803DDD20((s32)arg0);
    hdr = (u32 *)TLobby__sub_803DDD2C(0xC);
    TLobby::bswap32_in_place(hdr);
    TLobby::bswap32_in_place(hdr + 1);
    if (hdr[0] != 0x484D5647) {
        lbl_8058D470.c = 4;
        return -1;
    }
    list->count = ((GvmTextureHeader_803DDDC8 *)hdr)->directoryCount;
    replace_gvm_texture_directory(list, calc_gvm_entry_stride(((GvmTextureHeader_803DDDC8 *)hdr)->flags), (GvmTextureHeader_803DDDC8 *)hdr);
    TLobby__sub_803DDD40(hdr[1] + 8, 0);
    TLobby::seek_gvrt_chunk();
    n = list->count;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            if (i == (list->textures[k].attributes & 0xFFFF)) {
                break;
            }
        }
        r = TObjPlayer__sub_803D9E38((s32 *)((Obj_803DDA68 *)list), (u32)k, (s32 *)&id, (u32 *)&arg);
        if (r == -1) {
            lbl_8058D470.c = 7;
            return -1;
        }
        tex = (u32 *)TLobby__sub_803DDD2C(0x10);
        TLobby::bswap32_in_place(tex);
        TLobby::bswap32_in_place(tex + 1);
        if (tex[0] != 0x54525647) {
            lbl_8058D470.c = 4;
            return -1;
        }
        data = TLobby__sub_803DDD2C(tex[1] - 8);
        if (r == 0) {
            switch (TObjPlayer__sub_803DAC48((Obj_803DDA68 *)list, k, id, arg, (Desc_803DDA68 *)(tex + 2), &handle)) {
            case -1:
                lbl_8058D470.c = 6;
                return -1;
            case 0:
                if (TObjPlayer__sub_803DAB9C(handle, data) == -1) {
                    TObjPlayer__sub_803DAC1C(handle);
                    return -1;
                }
                do {
                } while (TObjPlayer::is_gvm_load_ok() != 1);
                break;
            }
        }
    }
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void TLobby::bswap_u32(u32 *p) {
    u32 v = *p;
    *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
u32 TLobby::bswap32_value(u32 v) {
    return ((v & 0xFF) << 24) | ((v & 0xFF00) << 8) | ((v & 0xFF0000) >> 8) | ((v & 0xFF000000) >> 24);
}
#pragma pop

void *load_nj_chunk_model_resource(u8 *base, u32 *off, u32 *out) {
    u32 magic;
    u32 size;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 *src;
    u8 *buf;
    u32 pos;
    u32 v;
    pos = 0;
    src = base + *off;
    ((TLobby *)(&magic))->move_data(src, 4);
    TLobby::bswap_u32(&magic);
    ((TLobby *)(&size))->move_data(src + 4, 4);
    TLobby::bswap_u32(&size);
    src += 8;
    *off += 8;
    magic = TLobby::bswap32_value(magic);
    switch ((s32) magic) {
    case 0x4E4A494E:
        *out = 0x4E4A494E;
        break;
    case 0x4E4A434D:
    case 0x474A434D:
        *out = 0x4E4A434D;
        break;
    case 0x474A424D:
        *out = 0x4E4A424D;
        break;
    case 0x4E4A544C:
    case 0x474A544C:
        *out = 0x4E4A544C;
        break;
    case 0x4E4A4C49:
        *out = 0x4E4A4C49;
        break;
    case 0x4E4A4341:
        *out = 0x4E4A4341;
        break;
    case 0x4E4D444D:
    case 0x474D444D:
        *out = 0x4E4D444D;
        break;
    case 0x474C494D:
        *out = 0x4E4C494D;
        break;
    case 0x4743414D:
        *out = 0x4E43414D;
        break;
    case 0x4E53534D:
    case 0x4753534D:
        *out = 0x4E53534D;
        break;
    default:
        goto unknown;
    }
    buf = (u8 *) xmalloc(size);
    if (buf == NULL) {
        return NULL;
    }
    ((TLobby *)buf)->move_data(src, size);
    DCFlushRange(buf, size);
    src += size;
    *off += size;
    goto relocate;
unknown:
    *out = 0x2A2A2A2A;
    return NULL;
relocate:
    ((TLobby *)(&magic))->move_data(src, 4);
    TLobby::bswap_u32(&magic);
    *off += 4;
    magic = TLobby::bswap32_value(magic);
    if (magic == 0x504F4630) {
        ((TLobby *)(&size))->move_data(src + 4, 4);
        TLobby::bswap_u32(&size);
        src += 8;
        *off += 4;
        while (size != 0) {
            ((TLobby *)(&b0))->move_data(src, 1);
            src++;
            (*off)++;
            size--;
            switch (b0 & 0xC0) {
            case 0x40:
                v = b0 & 0x3F;
                break;
            case 0x80:
                ((TLobby *)(&b1))->move_data(src, 1);
                src++;
                size--;
                (*off)++;
                v = ((b0 & 0x3F) << 8) | b1;
                break;
            case 0xC0:
                ((TLobby *)(&b1))->move_data(src, 1);
                size--;
                ((TLobby *)(&b2))->move_data(src + 1, 1);
                size--;
                ((TLobby *)(&b3))->move_data(src + 2, 1);
                src += 3;
                size--;
                *off += 3;
                v = ((b0 & 0x3F) << 24) | (b1 << 16) | (b2 << 8) | b3;
                break;
            case 0:
            default:
                continue;
            }
            pos += v * 4;
            if (*(u32 *)(buf + pos) != 0) {
                *(u32 *)(buf + pos) += (u32) buf;
            }
        }
    }
    return buf;
}

s32 TObjLight__gx_light_objects[0x50];
s16 *chunk_polygon_list_cache[0x7E];
u8 gvrt_header_read_buffer[0x20];
