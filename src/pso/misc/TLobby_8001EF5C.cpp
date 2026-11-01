#include "types.h"
#include "pso/misc/TLobby_8001EF5C.h"
#include "pso/system/memory.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TGStream.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Obj_8001F8D8 { u8 pad0[4]; s32 f4; s32 f8; s32 fc; u8 pad10[0x418 - 0x10]; s32 f418; u8 pad41c[0x434 - 0x41c]; s32 f434; s32 f438; s32 f43c; };

struct Ent_8001FB6C { s32 a; s32 data; };

struct Lobby_8001FB6C { u8 pad[0x430]; struct Ent_8001FB6C *entries; };

typedef struct Ent_8001F018 {
    s32 flags;
    s32 unk4;
    s32 unk8;
    s32 data;
} Ent_8001F018;

typedef struct Lobby_8001F018 {
    s32 flags;
    u8 pad4[0x42C - 0x4];
    Ent_8001F018 *entries;
} Lobby_8001F018;

typedef struct Ent_8001FD98 {
    s32 flags;
    s32 unk4;
    void *motion;
    void *texture;
} Ent_8001FD98;

typedef struct Lobby_8001FD98 {
    u8 pad0[0x42C];
    Ent_8001FD98 *entries;
} Lobby_8001FD98;

struct Ctx_8001FA1C { s32 f0; s32 f4; u8 pad8[0x43C - 8]; s32 f43C; };

struct Lobby_8001FA1C {
    s32 f0;
    s32 *f4;
    s32 *f8;
    Ctx_8001FA1C *fC;
    s32 f10;
    u32 f14;
};

struct Params_8001FA1C { Ctx_8001FA1C *a; s32 b; };

struct Ent16_8001FE7C { u32 flags; u8 pad4[4]; void *a; void *b; };

struct Ent8_8001FE7C { s32 x; void *data; };

struct Lobby_8001FE7C {
    u32 flags;
    u8 pad4[0x18 - 4];
    s32 handles[(0x418 - 0x18) / 4];
    s32 nHandles;
    u8 pad41c[0x42C - 0x41C];
    Ent16_8001FE7C *ents16;
    Ent8_8001FE7C *ents8;
    s32 nEnts16;
    s32 nEnts8;
};

struct Lobby_8001FB6C;
typedef struct Lobby_8001F018 Lobby_8001F018;
struct Ent16_80020004 { u32 flags; u8 pad4[4]; void *a; void *b; };

struct Ent8_80020004 { s32 x; void *data; };

struct Lobby_80020004 {
    u32 flags;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 pad18[0x41C - 0x18];
    s32 f41C;
    s32 f420;
    s32 f424;
    u8 pad428[4];
    Ent16_80020004 *ents16;
    Ent8_80020004 *ents8;
    s32 nEnts16;
    s32 nEnts8;
};

struct Desc_80020004 { s32 name; u8 pad4[8]; s16 n16; s16 n8; };

struct Rec_80020004 { char name[0x20]; s32 size; u8 pad24[8]; s32 texSize; u8 pad30[0x10]; };

struct Hdr_80020004 { u8 pad0[8]; u8 compressed; s8 small; u8 padA[0x36]; Rec_80020004 recs[1]; };

struct Stream_80020004 { u8 pad[0x30]; };

typedef struct Ent_8001FBEC {
    s32 flags;
    s32 unk4;
    s32 motion;
    s32 texture;
} Ent_8001FBEC;

typedef struct Lobby_8001FBEC {
    u8 pad0[0x42C];
    Ent_8001FBEC *entries;
} Lobby_8001FBEC;

struct Lobby_8001FBEC;
struct Ent_8001F128 {
    s32 flags;
    s32 unk4;
    s32 motion;
    u32 texture;
};

struct Rec_8001F128 { u8 pad0[0x20]; s32 size; u8 pad24[4]; s32 rawSize; u8 pad2C[0x14]; };

struct Ctx_8001F128 {
    u32 flags;
    s32 nmodel;
    s32 nmotion;
    s32 ntex;
    u32 state;
    u8 pad14[0x42C - 0x14];
    Ent_8001F128 *entries;
    u8 pad430[4];
    s32 f434;
    s32 f438;
};

void reset_gstream_globals(void);
extern "C" {
s32 xmalloc__FUl(s32);
extern s8 TLobby__tmp_buf_name[];
extern s32 lobby_download_buffer;
extern s32 tmp_buf_in_use_flag;
extern u32 bml_load_buffer;
s32 debug_print__6TLobbyFle(s32 *, ...);
extern s32 lbl_80434C48[];
extern s32 lbl_805D4AD0;
extern char lbl_80434C38[];
void check_bin_model_loaded__6TLobbyFPvPv(Obj_8001F8D8 *self, void * _w1);
extern s32 lbl_80434CC4[];
s32 bind_bml_motion(struct Lobby_8001FB6C *self, s32 idx, void *bytes);
s32 change_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2);
s32 load_gvm_texture_archive(s32, s32);
extern s32 lbl_80434B04[];
extern s32 lbl_80434B24[];
extern s32 lbl_805D7F10;
s32 set_stream_state__6TLobbyFi(s32, s32);
extern s32 lbl_80434D10[];
extern s32 lbl_80434D30[];
extern s32 lbl_80434D54[];
extern s32 lbl_80434D74[];
extern s32 lbl_80434D94[];
s32 TLobby__sub_8001EDD8(void *, s32);
s32 create_file_load_entry__6TLobbyFllUllPPv(void *, s32, void *, void *, void *);
extern s32 lbl_80434C70[];
extern s32 lbl_80434C98[];
s32 TLobby__sub_800F9FF4(s32);
void mem_free(void *p);
s32 release_texture_list(void *);
Lobby_8001FE7C *TLobby__sub_8001FE7C(Lobby_8001FE7C *self, s16 del);
void open__8TGStreamFPvPvi(void *, s32, s32);
s32 get_gstream_file_size(void *);
void destroy_gstream(void *, s32);
u32 prs_decompress_buffer(s32 arg0, s32 arg1);
void debug_printf_nop(void *, ...);
void *mem_alloc(u32 size);
char *strncpy(char *dest, const char *src, unsigned long num);
extern u8 *resource_decompress_buffer;
extern u8 bml_load_state;
extern s32 disc_read_filename;
extern s32 lbl_805D2B10;
extern s32 lbl_80434B70[];
extern s32 lbl_80434DB8[];
extern s32 lbl_80434DD4[];
extern s32 lbl_80434DF4[];
extern s32 lbl_80434E10[];
extern s32 lbl_80434E2C[];
Lobby_80020004 *load_resource_from_descriptor(Lobby_80020004 *self, s32 kind, Desc_80020004 *desc, s32 arg3, s32 arg4, s32 arg5);
extern s32 lbl_80434CE8[];
s32 bind_bml_model(Lobby_8001FBEC *arg0, u32 arg1, s32 arg2, s32 arg3);
u8 *tmp_buf_use_req__6TLobbyFPCc(const char *);
s32 TLobby__sub_803CC4C0(u32);
s32 TLobby__sub_803CC53C(void);
u32 adxf_open__6TLobbyFUii(void *, s32);
extern char lbl_80434B44[];
extern s32 lbl_80434B50[];
extern s32 lbl_80434B90[];
extern s32 lbl_80434BB0[];
extern s32 lbl_80434BD4[];
extern s32 lbl_80434BF8[];
extern s32 lbl_80434C18[];
extern u32 lobby_bml_file_handle;
extern u8 *lbl_805D4AE0;
extern Rec_8001F128 *bml_header_record_ptr;
extern s32 bml_load_entry_index;
extern u8 *lobby_bml_read_buffer;
void TItemDrop__sub_800FE2D8(void);
s32 TLobby__sub_801E38A0(s32, s32, s32, s32, u32 *);
s32 load_nj_chunk_model_resource(s32, s32, s32);
int xfree__FPv(void*);

void TLobby::free_if_not_owner(void* a1) { if (*(unsigned int*)((char*)this + 0x424) == 0) { xfree__FPv(a1); } }

s32 alloc_load_data__6TLobbyFPviii(void *arg0, s32 base, s32 arg2, s32 arg3) {
    u32 sp8;
    s32 buf;
    u32 temp_r4;
    u32 temp_r7;

    temp_r7 = *(u32 *)((s8 *)arg0 + 0x424);
    if (temp_r7 != 0U) {
        buf = temp_r7 + *(s32 *)((s8 *)arg0 + 0x428);
        TLobby__sub_801E38A0(base, arg2, arg3, buf, &sp8);
        temp_r4 = ((sp8 >> 5U) + 1) << 5;
        sp8 = temp_r4;
        *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) + temp_r4);
        return buf;
    }
    return load_nj_chunk_model_resource(base, arg2, arg3);
}

void TLobby::load_texture_sub(void *arg1, s32 arg2) {
    Lobby_8001F018 *arg0 = (Lobby_8001F018 *)this;
    char buf[0x20];
    s32 size;
    change_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)arg1, (char *)&lbl_805D7F10);
    size = TGStream::load_sct_file((s32)buf, (s32)lobby_download_buffer);
    if (size > 0x40000) {
        debug_print__6TLobbyFle(lbl_80434B04, buf);
    } else if (size > 0) {
        load_gvm_texture_archive(lobby_download_buffer, arg0->entries[arg2].data);
        arg0->entries[arg2].flags |= 1;
    } else {
        arg0->entries[arg2].flags |= 2;
        if (!(arg0->flags & 4)) {
            debug_print__6TLobbyFle(lbl_80434B24, buf);
        }
    }
}

void TLobby::set_flag_and_notify() {
    s32 (*temp_r12)(s32);

    *(s32 *)&this->m_name = (s32) (*(s32 *)&this->m_name | 0x400);
    temp_r12 = *(s32 (**)(s32))((s8 *)this + 0x41C);
    if (temp_r12 != NULL) {
        temp_r12(*(s32 *)((s8 *)this + 0x420));
    }
}

#define self ((Ctx_8001F128 *) arg0)
s32 TLobby::load_bml_exec(u8 *arg0, u8 *arg1) {
    s32 n;
    switch (self->state) {
    case 0:
        lbl_805D4AE0 = NULL;
        if (self->flags & 0x200) {
            self->state = 9;
            break;
        }
        bml_load_entry_index = 0;
        lobby_bml_read_buffer = tmp_buf_use_req__6TLobbyFPCc(lbl_80434B44);
        lobby_bml_file_handle = adxf_open__6TLobbyFUii(arg1, 0);
        if (lobby_bml_file_handle == 0) {
            debug_print__6TLobbyFle(lbl_80434B50, arg1);
            self->state = 0xB;
            return -1;
        }
        n = ((self->f434 + self->f438 + 1) * 64 + 0x7FF) / 2048;
        if (n > 0x4000) {
            debug_printf_nop(lbl_80434B70, n);
        }
        lbl_805D4AE0 = (u8 *) bml_load_buffer;
        bml_header_record_ptr = (Rec_8001F128 *) (bml_load_buffer + 0x40);
        TLobby::read_checked_align((s32)lobby_bml_file_handle, (s32)n, (s32)((void *) bml_load_buffer));
        TLobby::set_read_params((int)&lobby_bml_file_handle, (int)n, (int)lbl_805D4AE0);
        self->state = 1;
    case 1:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ((TLobby *)lobby_bml_file_handle)->close_adxf_handle();
            self->state = 9;
        } else if (TLobby__sub_803CC4C0(lobby_bml_file_handle) == 3) {
            TLobby::reset_read_state();
            switch (lbl_805D4AE0[8]) {
            case 0x50:
                bml_load_state = 1;
                break;
            default:
                bml_load_state = 0;
                break;
            }
            self->state = 2;
        }
        break;
    case 2:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ((TLobby *)lobby_bml_file_handle)->close_adxf_handle();
            self->state = 9;
        } else if (self->nmodel < self->f434) {
            n = (bml_header_record_ptr->size + 0x7FF) / 2048;
            switch ((s8) bml_load_state) {
            case 0:
            case 1:
                TLobby::read_checked_align((s32)lobby_bml_file_handle, (s32)n, (s32)lobby_bml_read_buffer);
                TLobby::set_read_params((int)&lobby_bml_file_handle, (int)n, (int)lobby_bml_read_buffer);
                break;
            default:
                debug_print__6TLobbyFle(lbl_80434B90);
                break;
            }
            self->state = 3;
        } else {
            self->state = 4;
        }
        break;
    case 3:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ((TLobby *)lobby_bml_file_handle)->close_adxf_handle();
            self->state = 9;
        } else if (TLobby__sub_803CC4C0(lobby_bml_file_handle) == 3) {
            TLobby::reset_read_state();
            switch ((s8) bml_load_state) {
            case 1: {
                s32 p = ((TQuestVmDownLoadServer *)(bml_header_record_ptr->rawSize))->alloc();
                if (p != 0) {
                    prs_decompress_buffer((s32)lobby_bml_read_buffer, p);
                    bind_bml_model((Lobby_8001FBEC *) self, bml_header_record_ptr->rawSize, self->nmodel++, p);
                    TAdSinglePlyChrSelectGC::safe_free(p);
                } else {
                    debug_print__6TLobbyFle(lbl_80434BB0);
                }
                break;
            }
            case 0:
                bind_bml_model((Lobby_8001FBEC *) self, bml_header_record_ptr->size, self->nmodel++, (s32) lobby_bml_read_buffer);
                break;
            }
            bml_header_record_ptr++;
            self->state = 2;
        }
        break;
    case 4:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ((TLobby *)lobby_bml_file_handle)->close_adxf_handle();
            self->state = 9;
        } else if (self->nmotion < self->f438) {
            n = (bml_header_record_ptr->size + 0x7FF) / 2048;
            switch ((s8) bml_load_state) {
            case 0:
            case 1:
                TLobby::read_checked_align((s32)lobby_bml_file_handle, (s32)n, (s32)lobby_bml_read_buffer);
                TLobby::set_read_params((int)&lobby_bml_file_handle, (int)n, (int)lobby_bml_read_buffer);
                break;
            default:
                debug_print__6TLobbyFle(lbl_80434B90);
                break;
            }
            self->state = 5;
        } else {
            TLobby::reset_read_state();
            ((TLobby *)lobby_bml_file_handle)->close_adxf_handle();
            bml_header_record_ptr = (Rec_8001F128 *) (lbl_805D4AE0 + 0x40);
            self->state = 6;
        }
        break;
    case 5:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ((TLobby *)lobby_bml_file_handle)->close_adxf_handle();
            self->state = 9;
        } else if (TLobby__sub_803CC4C0(lobby_bml_file_handle) == 3) {
            TLobby::reset_read_state();
            switch ((s8) bml_load_state) {
            case 1: {
                s32 p = ((TQuestVmDownLoadServer *)(bml_header_record_ptr->rawSize))->alloc();
                if (p != 0) {
                    prs_decompress_buffer((s32)lobby_bml_read_buffer, p);
                    bind_bml_motion((Lobby_8001FB6C *) self, self->nmodel++, (void *) p);
                    TAdSinglePlyChrSelectGC::safe_free(p);
                } else {
                    debug_print__6TLobbyFle(lbl_80434BD4);
                }
                break;
            }
            case 0:
                bind_bml_motion((Lobby_8001FB6C *) self, self->nmotion++, lobby_bml_read_buffer);
                break;
            }
            bml_header_record_ptr++;
            self->state = 4;
        }
        break;
    case 6:
        while (self->entries[bml_load_entry_index].texture == 0) {
            bml_load_entry_index++;
            bml_header_record_ptr++;
            if (bml_load_entry_index >= self->f434) {
                break;
            }
        }
        if (bml_load_entry_index < self->f434) {
            change_file_extension__6TLobbyFPvPvPv((char *)(0), (char *)bml_header_record_ptr, (char *)&lbl_805D7F10);
            lobby_bml_file_handle = adxf_open__6TLobbyFUii(bml_header_record_ptr, 0);
            if (lobby_bml_file_handle != 0) {
                n = TLobby__sub_803CC53C();
                if (n > 0x80) {
                    debug_print__6TLobbyFle(lbl_80434BF8, bml_header_record_ptr, n << 11);
                    bml_load_entry_index++;
                    bml_header_record_ptr++;
                } else {
                    TLobby::read_checked_align((s32)lobby_bml_file_handle, (s32)n, (s32)lobby_bml_read_buffer);
                    TLobby::set_read_params((int)&lobby_bml_file_handle, (int)n, (int)lobby_bml_read_buffer);
                }
            } else {
                self->entries[bml_load_entry_index].flags |= 2;
                if (!(self->flags & 4)) {
                    debug_print__6TLobbyFle(lbl_80434C18, bml_header_record_ptr);
                }
                bml_load_entry_index++;
                bml_header_record_ptr++;
                break;
            }
            self->state = 7;
        } else {
            ((TLobby *)self)->set_flag_and_notify();
            self->state = 0xA;
        }
        break;
    case 7:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ((TLobby *)lobby_bml_file_handle)->close_adxf_handle();
            self->state = 9;
        } else if (TLobby__sub_803CC4C0(lobby_bml_file_handle) == 3) {
            TLobby::reset_read_state();
            load_gvm_texture_archive((s32) lobby_bml_read_buffer, (s32) self->entries[bml_load_entry_index].texture);
            self->entries[bml_load_entry_index].flags |= 1;
            bml_load_entry_index++;
            bml_header_record_ptr++;
            self->ntex++;
            self->state = 6;
        }
        break;
    case 9:
        self->state = 0xA;
    case 10:
        TLobby::tmp_buf_release((const char *)lbl_80434B44);
        lbl_805D4AE0 = NULL;
        return 1;
    case 11:
        TLobby::tmp_buf_release((const char *)lbl_80434B44);
        lbl_805D4AE0 = NULL;
        return -1;
    }
    return 0;
}
#undef self

void TLobby::free_chr_select_data() {
    if ((u32) bml_load_buffer != 0U) {
        xfree__FPv((void*)((void*)bml_load_buffer));
        bml_load_buffer = 0U;
    }
    TItemDrop__sub_800FE2D8();
    TAdSinglePlyChrSelectGC::safe_free(lobby_download_buffer);
    lobby_download_buffer = 0;
}
void TLobby::init_download_buffers() {
    (*(s32 *)&bml_load_buffer) = xmalloc__FUl(0x4000);
    lobby_download_buffer = ((TQuestVmDownLoadServer *)0x40000)->alloc();
    reset_gstream_globals();
    tmp_buf_in_use_flag = 1;
    TLobby__tmp_buf_name[0] = 0;
}

void check_bin_model_loaded__6TLobbyFPvPv(Obj_8001F8D8 *self, void * _w1) {
    if (self->f434 <= self->f4 && self->f438 <= self->f8 && self->f43c <= self->fc) {
        ((TLobby *)self)->set_flag_and_notify();
        self->f418 = 0;
        TLobby::tmp_buf_release((const char *)lbl_80434C38);
    }
}

void increment_ref_and_set_flag__6TLobbyFPv(void *arg0) {
    void *temp_r4;
    temp_r4 = *(void **)((s8 *)arg0 + 0);
    *(s32 *)((s8 *)temp_r4 + 0xC) = (s32) (*(s32 *)((s8 *)temp_r4 + 0xC) + 1);
    check_bin_model_loaded__6TLobbyFPvPv((Obj_8001F8D8 *)(*(void **)((s8 *)arg0 + 0)), temp_r4);
    *(*(s32 **)((s8 *)arg0 + 4)) |= 1;
}
}
void align_gstream_read_offset(void *, s32);
void load_bin_motion_callback(void *arg0) {
    s32 spC;
    s32 sp8;
    s32 temp_r3;
    void *temp_r4;
    **(s32 **)((s8 *)arg0 + 0) = 0;
    spC = 0;
    temp_r3 = alloc_load_data__6TLobbyFPviii((void *)(*(void **)((s8 *)arg0 + 4)), lobby_download_buffer, (s32)&spC, (s32)&sp8);
    if (temp_r3 == 0) {
        debug_print__6TLobbyFle(lbl_80434C48);
    }
    **(s32 **)((s8 *)arg0 + 0) = temp_r3;
    temp_r4 = *(void **)((s8 *)arg0 + 4);
    *(s32 *)((s8 *)temp_r4 + 8) = (s32) (*(s32 *)((s8 *)temp_r4 + 8) + 1);
    check_bin_model_loaded__6TLobbyFPvPv((Obj_8001F8D8 *)(*(void **)((s8 *)arg0 + 4)), temp_r4);
}

struct Obj_8001F8D8;

void TLobby::load_bin_model_callback() {
    Lobby_8001FA1C *self = (Lobby_8001FA1C *)this;
    char name[0x20];
    Params_8001FA1C params;
    u32 i;
    s32 tag;
    s32 handle;
    s32 data;
    s32 r;
    s32 *slot;
    i = 0;
    while (i < self->f14) {
        data = ((s32 (*)(void *, s32, void *, void *))alloc_load_data__6TLobbyFPviii)(self->fC, lobby_download_buffer, &i, &tag);
        switch (tag) {
        case 0x4E4A544C:
            slot = self->f8;
            *slot = data;
            params.a = self->fC;
            params.b = self->f10;
            change_file_extension__6TLobbyFPvPvPv((char *)name, (char *)self->f0, (char *)&lbl_805D7F10);
            r = create_file_load_entry__6TLobbyFllUllPPv(name, *slot, (void *)increment_ref_and_set_flag__6TLobbyFPv, &params, &handle);
            if (r >= 0) {
                TLobby__sub_8001EDD8(self->fC, handle);
                self->fC->f43C++;
            } else if (!(self->fC->f0 & 4)) {
                debug_print__6TLobbyFle(lbl_80434C70, name, r);
            }
            break;
        case 0x4E4A434D:
            *self->f4 = data;
            self->fC->f4++;
            break;
        default:
            debug_print__6TLobbyFle(lbl_80434C98);
            break;
        }
    }
    ((void (*)(void *))check_bin_model_loaded__6TLobbyFPvPv)(self->fC);
}

s32 bind_bml_motion(struct Lobby_8001FB6C *self, s32 idx, void *bytes) {
    s32 spC;
    s32 sp8;
    u32 r;
    self->entries[idx].data = 0;
    spC = 0;
    r = alloc_load_data__6TLobbyFPviii(self, (s32) bytes, (s32) &spC, (s32) &sp8);
    if (r == 0) {
        debug_print__6TLobbyFle(lbl_80434CC4);
        return 0;
    }
    self->entries[idx].data = r;
    return 1;
}

s32 bind_bml_model(Lobby_8001FBEC *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 data;
    u32 offset;
    s32 tag;
    arg0->entries[arg2].motion = 0;
    arg0->entries[arg2].texture = 0;
    offset = 0;
    while (offset < arg1) {
        data = ((s32 (*)(void *, s32, u32 *, s32 *))alloc_load_data__6TLobbyFPviii)(arg0, arg3, &offset, &tag);
        switch (tag) {
        case 0x4E4A434D:
            arg0->entries[arg2].motion = data;
            break;
        case 0x4E4A544C:
            arg0->entries[arg2].texture = data;
            break;
        default:
            debug_print__6TLobbyFle(lbl_80434CE8, tag);
            break;
        }
    }
    return 1;
}

s32 TLobby::load_bin_motion(s32 arg1, s32 arg2) {
    Lobby_8001FB6C *arg0 = (Lobby_8001FB6C *)this;
    u32 offset;
    s32 tag;
    s32 size;
    s32 data;
    arg0->entries[arg2].data = 0;
    size = set_stream_state__6TLobbyFi(arg1, lobby_download_buffer);
    if (size == 0) {
        debug_print__6TLobbyFle(lbl_80434D10, arg1);
        return 0;
    }
    if (size > 0x40000) {
        debug_print__6TLobbyFle(lbl_80434D30, size - 0x40000);
    }
    offset = 0;
    data = alloc_load_data__6TLobbyFPviii(arg0, lobby_download_buffer, (s32)&offset, (s32)&tag);
    if (data == 0) {
        debug_print__6TLobbyFle(lbl_80434D54);
    }
    arg0->entries[arg2].data = data;
    return 1;
}

s32 TLobby::load_bin_model(s32 arg1, s32 arg2) {
    s32 size;
    ((Lobby_8001FD98 *)this)->entries[arg2].motion = NULL;
    ((Lobby_8001FD98 *)this)->entries[arg2].texture = NULL;
    size = ((TLobby *)arg1)->get_resource_file_size();
    if (size <= 0) {
        debug_print__6TLobbyFle(lbl_80434D74, arg1);
        return 0;
    }
    if (size > 0x40000) {
        debug_print__6TLobbyFle(lbl_80434D94, size - 0x40000);
    }
    set_stream_state__6TLobbyFi(arg1, lobby_download_buffer);
    bind_bml_model((Lobby_8001FBEC *)(this), size, arg2, lobby_download_buffer);
    if (((Lobby_8001FD98 *)this)->entries[arg2].texture != NULL) {
        this->load_texture_sub((void *)arg1, (s32)arg2);
    }
    return 1;
}

Lobby_8001FE7C *TLobby__sub_8001FE7C(Lobby_8001FE7C *self, s16 del) {
    s32 i;
    if (self != NULL) {
        if (self->flags & 2) {
            if (self->flags & 0x100) {
                self->flags |= 0x200;
            } else {
                for (i = 0; i < self->nHandles; i++) {
                    TLobby__sub_800F9FF4(self->handles[i]);
                }
                TLobby::tmp_buf_release_if_owner((const char *)lbl_80434C38);
            }
        }
        for (i = 0; i < self->nEnts16; i++) {
            if (self->ents16[i].a != NULL) {
                ((TLobby *)self)->free_if_not_owner(self->ents16[i].a);
            }
            if (self->ents16[i].b != NULL) {
                if (self->ents16[i].flags & 1) {
                    release_texture_list(self->ents16[i].b);
                }
                ((TLobby *)self)->free_if_not_owner(self->ents16[i].b);
            }
        }
        mem_free(self->ents16);
        for (i = 0; i < self->nEnts8; i++) {
            ((TLobby *)self)->free_if_not_owner(self->ents8[i].data);
        }
        mem_free(self->ents8);
        if (del > 0) {
            ::operator delete(self);
        }
    }
    return self;
}

void TLobby::reset_battle_state() {
    *(s32 *)((s8 *)this + 0x42C) = 0;
    *(s32 *)((s8 *)this + 0x430) = 0;
    *(s32 *)((s8 *)this + 0x434) = 0;
    *(s32 *)((s8 *)this + 0x438) = 0;
    *(s32 *)((s8 *)this + 0x43C) = 0;
    *(s32 *)&this->m_next = 0;
    *(s32 *)&this->m_prev = 0;
    *(s32 *)&this->m_flags = 0;
    *(s32 *)((s8 *)this + 0x418) = 0;
    *(s32 *)((s8 *)this + 0x428) = 0;
    lbl_805D4AD0 = 0;
}
Lobby_80020004 *load_resource_from_descriptor(Lobby_80020004 *self, s32 kind, Desc_80020004 *desc, s32 arg3, s32 arg4, s32 arg5) {
    Stream_80020004 st;
    char name[0x20];
    Hdr_80020004 *hdr;
    s32 blk;
    s32 i;
    s32 j;
    Rec_80020004 *rec;
    Rec_80020004 *first;
    s32 sectors;
    s32 size;
    s32 buf;
    u32 flags;
    ((TLobby *)self)->reset_battle_state();
    self->flags = kind | 0x100;
    self->f41C = arg3;
    self->f420 = arg4;
    self->f424 = arg5;
    self->nEnts16 = desc->n16;
    self->nEnts8 = desc->n8;
    if (self->nEnts16 > 0) {
        self->ents16 = (Ent16_80020004 *)mem_alloc(self->nEnts16 * 16);
        for (s32 i = 0; i < self->nEnts16; i++) {
            self->ents16[i].flags = 0;
            self->ents16[i].a = NULL;
            self->ents16[i].b = NULL;
        }
    }
    if (self->nEnts8 > 0) {
        self->ents8 = (Ent8_80020004 *)mem_alloc(self->nEnts8 * 8);
        for (s32 i = 0; i < self->nEnts8; i++) {
            self->ents8[i].data = NULL;
        }
    }
    flags = self->flags;
    if (flags & 1) {
        TLobby::pump_frames();
        lbl_805D4AD0 = 1;
        open__8TGStreamFPvPvi(&st, desc->name, 0);
        if (get_gstream_file_size(&st) <= 0) {
            debug_print__6TLobbyFle(lbl_80434DB8, desc->name);
            self->nEnts16 = self->nEnts8 = 0;
            destroy_gstream(&st, -1);
            return self;
        }
        sectors = (((self->nEnts16 + self->nEnts8 + 1) << 6) + 0x7FF) / 2048;
        if (sectors > 0x4000) {
            debug_printf_nop(lbl_80434B70, sectors);
        }
        hdr = (Hdr_80020004 *)bml_load_buffer;
        first = hdr->recs;
        ((TGStream *)(&st))->read_data((s32)hdr, (s32)(sectors << 11));
        switch (hdr->compressed) {
        case 0x50:
            bml_load_state = 1;
            break;
        default:
            bml_load_state = 0;
            break;
        }
        blk = 0x800;
        if (hdr->small != 0) {
            blk = 0x20;
            self->flags |= 0x800;
        }
        rec = first;
        for (i = 0; i < self->nEnts16; i++, rec++) {
            size = rec->size;
            if (size > 0x40000) {
                debug_print__6TLobbyFle(lbl_80434DD4, size - 0x40000);
            }
            switch (bml_load_state) {
            case 1:
                buf = ((TQuestVmDownLoadServer *)(size + 0x800))->alloc();
                if (buf != 0) {
                    disc_read_filename = desc->name;
                    ((TGStream *)(&st))->read_data((s32)((void *)buf), (s32)size);
                    align_gstream_read_offset(&st, blk);
                    disc_read_filename = lbl_805D2B10;
                    prs_decompress_buffer(buf, (s32)resource_decompress_buffer);
                    TAdSinglePlyChrSelectGC::safe_free(buf);
                    bind_bml_model((Lobby_8001FBEC *)(self), size, i, (s32)((s32)resource_decompress_buffer));
                } else {
                    debug_print__6TLobbyFle(lbl_80434DF4, desc->name);
                }
                break;
            default:
                ((TGStream *)(&st))->read_data((s32)resource_decompress_buffer, (s32)size);
                align_gstream_read_offset(&st, blk);
                disc_read_filename = lbl_805D2B10;
                bind_bml_model((Lobby_8001FBEC *)(self), size, i, (s32)((s32)resource_decompress_buffer));
                break;
            }
            if (self->flags & 0x800) {
                Ent16_80020004 *e = &self->ents16[i];
                if (e->b != NULL) {
                    s32 tsize = rec->texSize;
                    if (tsize != 0) {
                        s32 tbuf = ((TQuestVmDownLoadServer *)(tsize + 0x800))->alloc();
                        ((TGStream *)(&st))->read_data((s32)((void *)tbuf), (s32)tsize);
                        align_gstream_read_offset(&st, blk);
                        prs_decompress_buffer(tbuf, (s32)resource_decompress_buffer);
                        TAdSinglePlyChrSelectGC::safe_free(tbuf);
                        if (load_gvm_texture_archive((s32)resource_decompress_buffer, (s32)self->ents16[i].b) > 0) {
                            self->ents16[i].flags |= 1;
                        } else {
                            self->ents16[i].flags |= 2;
                            debug_print__6TLobbyFle(lbl_80434E10);
                        }
                    } else {
                        e->flags |= 2;
                        if (!(self->flags & 4)) {
                            debug_print__6TLobbyFle(lbl_80434E2C);
                        }
                    }
                }
            }
        }
        for (j = 0; j < self->nEnts8; j++, rec++) {
            s32 sz = rec->size;
            if (sz > 0x40000) {
                debug_print__6TLobbyFle(lbl_80434DD4, sz - 0x40000);
            }
            switch (bml_load_state) {
            case 1: {
                s32 mb = ((TQuestVmDownLoadServer *)(sz + 0x800))->alloc();
                ((TGStream *)(&st))->read_data((s32)((void *)mb), (s32)sz);
                align_gstream_read_offset(&st, blk);
                prs_decompress_buffer(mb, (s32)resource_decompress_buffer);
                TAdSinglePlyChrSelectGC::safe_free(mb);
                bind_bml_motion((struct Lobby_8001FB6C *)self, j, resource_decompress_buffer);
                break;
            }
            default:
                ((TGStream *)(&st))->read_data((s32)resource_decompress_buffer, (s32)sz);
                align_gstream_read_offset(&st, blk);
                bind_bml_motion((struct Lobby_8001FB6C *)self, j, resource_decompress_buffer);
                break;
            }
        }
        destroy_gstream(&st, -1);
        if (!(self->flags & 0x800)) {
            rec = hdr->recs;
            for (s32 i = 0; i < self->nEnts16; i++, rec++) {
                if (self->ents16[i].b != NULL) {
                    strncpy(name, rec->name, 0x20);
                    ((TLobby *)self)->load_texture_sub(name, i);
                }
            }
        }
        ((TLobby *)self)->set_flag_and_notify();
    } else if (flags & 2) {
        self->fC = 0;
        self->f8 = 0;
        self->f4 = 0;
        self->f10 = 0;
        self->f14 = 0;
        TLobby::add_named_entry((s32)self, desc->name);
    }
    return self;
}
