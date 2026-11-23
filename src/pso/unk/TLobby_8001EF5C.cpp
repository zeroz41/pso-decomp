#include <string.h>
#include "pso/render/GvmTextureArchive.h"
#include "pso/system/NinjaChunk.h"
#include "pso/system/Adxf.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/memory.h"
#include "pso/render/NinjaUtil.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TGStream.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_800FA2A0.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"


struct Ent_8001FB6C { s32 a; s32 data; };

struct Lobby_8001FB6C { u8 pad[0x430]; struct Ent_8001FB6C *entries; };

struct BmlModelLoadRequest {
    void *name;
    NJS_OBJECT **model;
    GinjaTextureList **texture;
    BmlResource *resource;
    BmlModelEntry *entry;
    u32 size;
};

LAYOUT_ASSERT(BmlModelLoadRequestSize, sizeof(BmlModelLoadRequest) == 0x18);
LAYOUT_ASSERT(BmlModelLoadRequestArchiveOffset, offsetof(BmlModelLoadRequest, resource) == 0xC);
LAYOUT_ASSERT(BmlModelLoadRequestSizeOffset, offsetof(BmlModelLoadRequest, size) == 0x14);

struct BmlMotionLoadRequest {
    AnimationMotion **motion;
    BmlResource *resource;
};

LAYOUT_ASSERT(BmlMotionLoadRequestSize, sizeof(BmlMotionLoadRequest) == 8);

// One model of a TBinModel (inferred name; counted from the constructor's model list).
struct BinModelSlot { u32 flags; u8 pad4[4]; void *a; void *b; };

// One motion of a TBinModel (inferred name; counted from the constructor's motion list).
struct BinMotionSlot { s32 x; void *data; };

// Named after the "TBinModel: ..." / "TBinModel_NORMAL" debug strings its constructor (0x8002058C) and
// the descriptor-based BmlResource constructor print. Field names below are inferred.
struct TBinModel {
    u32 flags;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 handles[0x100];
    s32 nHandles;
    s32 on_loaded;      // called with on_loaded_arg by BmlResource::set_flag_and_notify (0x41C)
    s32 on_loaded_arg;
    s32 load_buffer;    // when set, allocate_bml_chunk carves loads out of it (0x424)
    u8 pad428[4];
    BinModelSlot *ents16;
    BinMotionSlot *ents8;
    s32 nEnts16;
    s32 nEnts8;

    void load_models(char **list);
    void load_motions(char **list);
    void request_motions(char **list);
};

struct BmlTextureLoadRequest {
    BmlResource *resource;
    BmlModelEntry *entry;
};

LAYOUT_ASSERT(BmlTextureLoadRequestSize, sizeof(BmlTextureLoadRequest) == 8);

struct Rec_80020004 { char name[0x20]; s32 size; u8 pad24[8]; s32 texSize; u8 pad30[0x10]; };

struct Hdr_80020004 { u8 pad0[8]; u8 compressed; s8 small; u8 padA[0x36]; Rec_80020004 recs[1]; };


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
    GinjaTextureList *texture;
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
char tmp_buf_name[0x20];
u8 bml_load_state;
u8 *lobby_download_buffer;
s32 lbl_805D4AD0;
s32 tmp_buf_in_use_flag;
uaddr bml_load_buffer;
AdxfHandle *lobby_bml_file_handle;
u8 * lbl_805D4AE0;
Rec_8001F128 * bml_header_record_ptr;
s32 bml_load_entry_index;
u8 * lobby_bml_read_buffer;
void check_bin_model_loaded__6TLobbyFPvPv(BmlResource *resource, void *);
s32 bind_bml_motion(struct Lobby_8001FB6C *self, s32 idx, void *bytes);
s32 create_file_load_entry__6TLobbyFllUllPPv(void *, saddr, void *, void *, void *);
s32 TLobby__sub_800F9FF4(saddr);
s32 release_texture_list(void *);
u32 prs_decompress_buffer(s32 arg0, s32 arg1);
extern u8 *resource_decompress_buffer;

extern const char *lbl_805D2B10;
s32 bind_bml_model(Lobby_8001FBEC *resource, u32 size, s32 index, saddr file);
void TItemDrop__sub_800FE2D8(void);
void *load_nj_chunk_model_resource(u8 *, u32 *, u32 *);


// ---- 0x8001ED90-0x8001EF5C (was TObjFish_8001ED90) ----
extern "C" {
int fn_8001ED90(void* p) { return (*(u32*)((char*)p + 0x0) >> 10) & 0x1; }

AnimationMotion *get_bml_motion(BmlResource *resource, s32 index) {
    return resource->motions[index].motion;
}

GinjaTextureList *get_bml_texlist(BmlResource *resource, s32 index) {
    return resource->models[index].texlist;
}

NJS_OBJECT *get_bml_model(BmlResource *resource, s32 index) {
    return resource->models[index].model;
}

void TLobby__sub_8001EDD8(BmlResource *self, void *item) {
    self->handles[self->handle_count++] = item;
}
}

void TLobby::tmp_buf_release_if_owner(const char *name) {
    if (((s32) tmp_buf_in_use_flag == 0) && (strcmp(tmp_buf_name, name) == 0)) {
        tmp_buf_in_use_flag = 1;
        tmp_buf_name[0] = 0;
    }
}

s32 TLobby::tmp_buf_release(const char *name) {
    if (name != 0) {
        if (tmp_buf_in_use_flag == 1) {
            TLobby::debug_print("TmpBufRelease(%s) Bad Release", name);
            return 0;
        }
        if (strcmp(tmp_buf_name, name) != 0) {
            TLobby::debug_print("TmpBufRelease(%s) keycode no-match(%s)", name, tmp_buf_name);
            return 0;
        }
    }
    tmp_buf_in_use_flag = 1;
    tmp_buf_name[0] = 0;
    return 1;
}

s32 TLobby::tmp_buf_is_free() {
    return tmp_buf_in_use_flag;
}
u8 *TLobby::tmp_buf_use_req(const char *name) {
    if (tmp_buf_in_use_flag != 0) {
        tmp_buf_in_use_flag = 0;
        strncpy(tmp_buf_name, name, 0x20);
        return lobby_download_buffer;
    }
    TLobby::debug_print("TmpBufUseReq(%s) can't use");
    return 0;
}

// ---- 0x8001EF5C-0x80020898 ----
void BmlResource::free_if_not_in_arena(void *ptr) {
    if (arena == NULL) {
        xfree(ptr);
    }
}

extern "C" void *allocate_bml_chunk(BmlResource *resource, u8 *file, u32 *offset, u32 *tag) {
    u32 size;
    if (resource->arena != NULL) {
        u8 *destination = static_cast<u8 *>(resource->arena) + resource->arena_offset;
        TLobby__sub_801E38A0(file, offset, tag, destination, &size);
        size = ((size >> 5U) + 1) << 5;
        resource->arena_offset += size;
        return destination;
    }
    return load_nj_chunk_model_resource(file, offset, tag);
}

void BmlResource::load_texture_sub(void *name, s32 index) {
    char buf[0x20];
    s32 size;
    TLobby::change_file_extension((char *)buf, (char *)name, (char *)"gvm");
    size = TGStream::load_sct_file(buf, lobby_download_buffer);
    if (size > 0x40000) {
        TLobby::debug_print("LoadTextureSub: %s too large.", buf);
    } else if (size > 0) {
        load_gvm_texture_archive(lobby_download_buffer, models[index].texlist);
        models[index].m_0 |= 1;
    } else {
        models[index].m_0 |= 2;
        if (!(flags & 4)) {
            TLobby::debug_print("LoadTextureSub: %s load failed.", buf);
        }
    }
}

void BmlResource::set_flag_and_notify() {
    s32 (*temp_r12)(saddr);

    flags |= 0x400;
    temp_r12 = (s32 (*)(saddr))callback;
    if (temp_r12 != NULL) {
        temp_r12(callback_context);
    }
}

#define self ((Ctx_8001F128 *) arg0)
s32 TLobby::load_bml_exec(u8 *arg0, u8 *name) {
    s32 n;
    switch (self->state) {
    case 0:
        lbl_805D4AE0 = NULL;
        if (self->flags & 0x200) {
            self->state = 9;
            break;
        }
        bml_load_entry_index = 0;
        lobby_bml_read_buffer = TLobby::tmp_buf_use_req("LoadBmlExec");
        lobby_bml_file_handle = ADXF_Open(name, 0);
        if (lobby_bml_file_handle == 0) {
            TLobby::debug_print("LoadBmlExec: %s cannot open.", name);
            self->state = 0xB;
            return -1;
        }
        n = ((self->f434 + self->f438 + 1) * 64 + 0x7FF) / 2048;
        if (n > 0x4000) {
            debug_printf_nop("TOO LARGE BMLHEAD SIZE(%08x)", n);
        }
        lbl_805D4AE0 = (u8 *) bml_load_buffer;
        bml_header_record_ptr = (Rec_8001F128 *) (bml_load_buffer + 0x40);
        ADXF_ReadNw(lobby_bml_file_handle, (s32)n, (void *)bml_load_buffer);
        TLobby::set_read_params(&lobby_bml_file_handle, (int)n, (saddr)lbl_805D4AE0);
        self->state = 1;
    case 1:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ADXF_Close(lobby_bml_file_handle);
            self->state = 9;
        } else if (ADXF_GetStat(lobby_bml_file_handle) == 3) {
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
            ADXF_Close(lobby_bml_file_handle);
            self->state = 9;
        } else if (self->nmodel < self->f434) {
            n = (bml_header_record_ptr->size + 0x7FF) / 2048;
            switch ((s8) bml_load_state) {
            case 0:
            case 1:
                ADXF_ReadNw(lobby_bml_file_handle, (s32)n, lobby_bml_read_buffer);
                TLobby::set_read_params(&lobby_bml_file_handle, (int)n, (saddr)lobby_bml_read_buffer);
                break;
            default:
                TLobby::debug_print("TBinModel: Illegal File Format");
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
            ADXF_Close(lobby_bml_file_handle);
            self->state = 9;
        } else if (ADXF_GetStat(lobby_bml_file_handle) == 3) {
            TLobby::reset_read_state();
            switch ((s8) bml_load_state) {
            case 1: {
                s32 p = (saddr)TQuestVmDownLoadServer::alloc(bml_header_record_ptr->rawSize);
                if (p != 0) {
                    prs_decompress_buffer((saddr)lobby_bml_read_buffer, p);
                    bind_bml_model((Lobby_8001FBEC *) self, bml_header_record_ptr->rawSize, self->nmodel++, p);
                    TAdSinglePlyChrSelectGC::safe_free(p);
                } else {
                    TLobby::debug_print("TBinModel: Can't malloc(LOADMODEL)");
                }
                break;
            }
            case 0:
                bind_bml_model((Lobby_8001FBEC *) self, bml_header_record_ptr->size, self->nmodel++, (saddr) lobby_bml_read_buffer);
                break;
            }
            bml_header_record_ptr++;
            self->state = 2;
        }
        break;
    case 4:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ADXF_Close(lobby_bml_file_handle);
            self->state = 9;
        } else if (self->nmotion < self->f438) {
            n = (bml_header_record_ptr->size + 0x7FF) / 2048;
            switch ((s8) bml_load_state) {
            case 0:
            case 1:
                ADXF_ReadNw(lobby_bml_file_handle, (s32)n, lobby_bml_read_buffer);
                TLobby::set_read_params(&lobby_bml_file_handle, (int)n, (saddr)lobby_bml_read_buffer);
                break;
            default:
                TLobby::debug_print("TBinModel: Illegal File Format");
                break;
            }
            self->state = 5;
        } else {
            TLobby::reset_read_state();
            ADXF_Close(lobby_bml_file_handle);
            bml_header_record_ptr = (Rec_8001F128 *) (lbl_805D4AE0 + 0x40);
            self->state = 6;
        }
        break;
    case 5:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ADXF_Close(lobby_bml_file_handle);
            self->state = 9;
        } else if (ADXF_GetStat(lobby_bml_file_handle) == 3) {
            TLobby::reset_read_state();
            switch ((s8) bml_load_state) {
            case 1: {
                saddr p = (saddr)TQuestVmDownLoadServer::alloc(bml_header_record_ptr->rawSize);
                if (p != 0) {
                    prs_decompress_buffer((saddr)lobby_bml_read_buffer, p);
                    bind_bml_motion((Lobby_8001FB6C *) self, self->nmodel++, (void *) p);
                    TAdSinglePlyChrSelectGC::safe_free(p);
                } else {
                    TLobby::debug_print("TBinModel: Can't malloc(LOADMOTION)");
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
            TLobby::change_file_extension(NULL, (char *)bml_header_record_ptr, (char *)"gvm");
            lobby_bml_file_handle = ADXF_Open(bml_header_record_ptr, 0);
            if (lobby_bml_file_handle != 0) {
                n = ADXF_GetFsizeSct(lobby_bml_file_handle);
                if (n > 0x80) {
                    TLobby::debug_print("LoadBmlExec: %s Too Large(%08x)", bml_header_record_ptr, n << 11);
                    bml_load_entry_index++;
                    bml_header_record_ptr++;
                } else {
                    ADXF_ReadNw(lobby_bml_file_handle, (s32)n, lobby_bml_read_buffer);
                    TLobby::set_read_params(&lobby_bml_file_handle, (int)n, (saddr)lobby_bml_read_buffer);
                }
            } else {
                self->entries[bml_load_entry_index].flags |= 2;
                if (!(self->flags & 4)) {
                    TLobby::debug_print("LoadBmlExec: %s load failed.", bml_header_record_ptr);
                }
                bml_load_entry_index++;
                bml_header_record_ptr++;
                break;
            }
            self->state = 7;
        } else {
            ((BmlResource *)self)->set_flag_and_notify();
            self->state = 0xA;
        }
        break;
    case 7:
        if (self->flags & 0x200) {
            TLobby::reset_read_state();
            ADXF_Close(lobby_bml_file_handle);
            self->state = 9;
        } else if (ADXF_GetStat(lobby_bml_file_handle) == 3) {
            TLobby::reset_read_state();
            load_gvm_texture_archive(lobby_bml_read_buffer, self->entries[bml_load_entry_index].texture);
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
        TLobby::tmp_buf_release("LoadBmlExec");
        lbl_805D4AE0 = NULL;
        return 1;
    case 11:
        TLobby::tmp_buf_release("LoadBmlExec");
        lbl_805D4AE0 = NULL;
        return -1;
    }
    return 0;
}
#undef self

void TLobby::free_chr_select_data() {
    if ((u32) bml_load_buffer != 0U) {
        xfree((void*)((void*)bml_load_buffer));
        bml_load_buffer = 0U;
    }
    TItemDrop__sub_800FE2D8();
    TAdSinglePlyChrSelectGC::safe_free((uaddr)lobby_download_buffer);
    lobby_download_buffer = 0;
}
void TLobby::init_download_buffers() {
    (*(s32 *)&bml_load_buffer) = (saddr)xmalloc(0x4000);
    lobby_download_buffer = (u8 *)TQuestVmDownLoadServer::alloc(0x40000);
    reset_gstream_globals();
    tmp_buf_in_use_flag = 1;
    tmp_buf_name[0] = 0;
}

void check_bin_model_loaded__6TLobbyFPvPv(BmlResource *resource, void *) {
    if (resource->model_count <= resource->loaded_models &&
        resource->motion_count <= resource->loaded_motions &&
        resource->expected_textures <= resource->loaded_textures) {
        resource->set_flag_and_notify();
        resource->handle_count = 0;
        TLobby::tmp_buf_release("TBinModel_REQ");
    }
}

void increment_ref_and_set_flag__6TLobbyFPv(void *context) {
    BmlTextureLoadRequest *request = (BmlTextureLoadRequest *)context;
    BmlResource *resource = request->resource;
    resource->loaded_textures++;
    TLobby::check_bin_model_loaded(request->resource, resource);
    request->entry->m_0 |= 1;
}
}
void load_bin_motion_callback(BmlMotionLoadRequest *request) {
    u32 position;
    u32 kind;
    *request->motion = NULL;
    position = 0;
    void *data = allocate_bml_chunk(request->resource, (u8 *)lobby_download_buffer, &position, &kind);
    if (data == 0) {
        TLobby::debug_print("LoadBinMotionCallBack: Illegal format.");
    }
    *request->motion = (AnimationMotion *)data;
    BmlResource *resource = request->resource;
    resource->loaded_motions++;
    TLobby::check_bin_model_loaded(request->resource, resource);
}


void load_bin_model_callback(BmlModelLoadRequest *self) {
    char name[0x20];
    BmlTextureLoadRequest params;
    u32 i;
    u32 tag;
    void *handle;
    void *data;
    s32 r;
    GinjaTextureList **slot;
    i = 0;
    while (i < self->size) {
        data = allocate_bml_chunk(self->resource, (u8 *)lobby_download_buffer, &i, &tag);
        switch (tag) {
        case 0x4E4A544C:
            slot = self->texture;
            *slot = (GinjaTextureList *)data;
            params.resource = self->resource;
            params.entry = self->entry;
            TLobby::change_file_extension((char *)name, (char *)self->name, (char *)"gvm");
            r = create_file_load_entry__6TLobbyFllUllPPv(name, (saddr)*slot, (void *)increment_ref_and_set_flag__6TLobbyFPv, &params, &handle);
            if (r >= 0) {
                TLobby__sub_8001EDD8(self->resource, handle);
                self->resource->expected_textures++;
            } else if (!(self->resource->flags & 4)) {
                TLobby::debug_print("LoadBinModelCallBack: %s ERROR(%+2d)", name, r);
            }
            break;
        case 0x4E4A434D:
            *self->model = (NJS_OBJECT *)data;
            self->resource->loaded_models++;
            break;
        default:
            TLobby::debug_print("LoadBinModelCallBack: Illegal model format.");
            break;
        }
    }
    ((void (*)(void *))check_bin_model_loaded__6TLobbyFPvPv)(self->resource);
}

s32 bind_bml_motion(struct Lobby_8001FB6C *self, s32 idx, void *bytes) {
    s32 offset;
    s32 tag;
    u32 r;
    self->entries[idx].data = 0;
    offset = 0;
    r = (uaddr)allocate_bml_chunk((BmlResource *)self, (u8 *)bytes, (u32 *)&offset, (u32 *)&tag);
    if (r == 0) {
        TLobby::debug_print("LoadBinMotionSub: Illegal format.");
        return 0;
    }
    self->entries[idx].data = r;
    return 1;
}

s32 bind_bml_model(Lobby_8001FBEC *resource, u32 size, s32 index, saddr file) {
    s32 data;
    u32 offset;
    s32 tag;
    resource->entries[index].motion = 0;
    resource->entries[index].texture = 0;
    offset = 0;
    while (offset < size) {
        data = (saddr)allocate_bml_chunk((BmlResource *)resource, (u8 *)file, &offset, (u32 *)&tag);
        switch (tag) {
        case 0x4E4A434D:
            resource->entries[index].motion = data;
            break;
        case 0x4E4A544C:
            resource->entries[index].texture = data;
            break;
        default:
            TLobby::debug_print("LoadBinModelSub: Illegal format %08x", tag);
            break;
        }
    }
    return 1;
}

s32 BmlResource::load_bin_motion(void *name, s32 index) {
    u32 offset;
    s32 tag;
    s32 size;
    saddr data;
    motions[index].motion = NULL;
    size = read_disc_file_sectors((const char *)name, (void *)lobby_download_buffer);
    if (size == 0) {
        TLobby::debug_print("LoadBinMotion: %s load failed.", name);
        return 0;
    }
    if (size > 0x40000) {
        TLobby::debug_print("LoadBinMotion: tmpbuf overflow(%x)", size - 0x40000);
    }
    offset = 0;
    data = (saddr)allocate_bml_chunk(this, (u8 *)lobby_download_buffer, &offset, (u32 *)&tag);
    if (data == 0) {
        TLobby::debug_print("LoadBinMotion: Illegal format.");
    }
    motions[index].motion = (AnimationMotion *)data;
    return 1;
}

s32 BmlResource::load_bin_model(void *name, s32 index) {
    s32 size;
    models[index].model = NULL;
    models[index].texlist = NULL;
    size = TGStream::get_resource_file_size((const char *)name);
    if (size <= 0) {
        TLobby::debug_print("LoadBinModel: %s load failed.", name);
        return 0;
    }
    if (size > 0x40000) {
        TLobby::debug_print("LoadBinModel: tmpbuf overflow(%x)", size - 0x40000);
    }
    read_disc_file_sectors((const char *)name, (void *)lobby_download_buffer);
    bind_bml_model((Lobby_8001FBEC *)(this), size, index, (saddr)lobby_download_buffer);
    if (models[index].texlist != NULL) {
        load_texture_sub(name, index);
    }
    return 1;
}

BmlResource::~BmlResource() {
    s32 i;
    if (flags & 2) {
        if (flags & 0x100) {
            flags |= 0x200;
        } else {
            for (i = 0; i < handle_count; i++) {
                TLobby__sub_800F9FF4((saddr)handles[i]);
            }
            TLobby::tmp_buf_release_if_owner("TBinModel_REQ");
        }
    }
    for (i = 0; i < model_count; i++) {
        if (models[i].model != NULL) {
            free_if_not_in_arena(models[i].model);
        }
        if (models[i].texlist != NULL) {
            if (models[i].m_0 & 1) {
                release_texture_list(models[i].texlist);
            }
            free_if_not_in_arena(models[i].texlist);
        }
    }
    mem_free(models);
    for (i = 0; i < motion_count; i++) {
        free_if_not_in_arena(motions[i].motion);
    }
    mem_free(motions);
}

void BmlResource::reset() {
    models = NULL;
    motions = NULL;
    model_count = 0;
    motion_count = 0;
    expected_textures = 0;
    loaded_textures = 0;
    loaded_motions = 0;
    loaded_models = 0;
    handle_count = 0;
    arena_offset = 0;
    lbl_805D4AD0 = 0;
}
BmlResource::BmlResource(s32 kind, BmlResourceDescriptor *descriptor, saddr on_loaded, saddr on_loaded_arg, void *load_buffer) {
    char name[0x20];
    Hdr_80020004 *hdr;
    s32 blk;
    s32 i;
    s32 j;
    Rec_80020004 *rec;
    Rec_80020004 *first;
    s32 sectors;
    s32 size;
    saddr buf;
    u32 flags;
    reset();
    this->flags = kind | 0x100;
    callback = on_loaded;
    callback_context = on_loaded_arg;
    arena = load_buffer;
    model_count = descriptor->model_count;
    motion_count = descriptor->motion_count;
    if (model_count > 0) {
        models = (BmlModelEntry *)mem_alloc(model_count * sizeof(BmlModelEntry));
        for (s32 i = 0; i < model_count; i++) {
            models[i].m_0 = 0;
            models[i].model = NULL;
            models[i].texlist = NULL;
        }
    }
    if (motion_count > 0) {
        motions = (BmlMotionEntry *)mem_alloc(motion_count * sizeof(BmlMotionEntry));
        for (s32 i = 0; i < motion_count; i++) {
            motions[i].motion = NULL;
        }
    }
    flags = this->flags;
    if (flags & 1) {
        TLobby::pump_frames();
        lbl_805D4AD0 = 1;
        {
            TGStream st((void *)descriptor->archive_filename, 0);
            if (st.get_file_size() <= 0) {
                TLobby::debug_print("TBinModel: %s not found.", descriptor->archive_filename);
                model_count = motion_count = 0;
                return;
            }
            sectors = (((model_count + motion_count + 1) << 6) + 0x7FF) / 2048;
            if (sectors > 0x4000) {
                debug_printf_nop("TOO LARGE BMLHEAD SIZE(%08x)", sectors);
            }
            hdr = (Hdr_80020004 *)bml_load_buffer;
            first = hdr->recs;
            st.read_data((saddr)hdr, (s32)(sectors << 11));
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
                this->flags |= 0x800;
            }
            rec = first;
            for (i = 0; i < model_count; i++, rec++) {
                size = rec->size;
                if (size > 0x40000) {
                    TLobby::debug_print("TBinModel: tmpbuf overflow(%x)", size - 0x40000);
                }
                switch (bml_load_state) {
                case 1:
                    buf = (saddr)TQuestVmDownLoadServer::alloc(size + 0x800);
                    if (buf != 0) {
                        disc_read_filename = (const char *)descriptor->archive_filename;
                        st.read_data((saddr)((void *)buf), (s32)size);
                        st.align_read_offset(blk);
                        disc_read_filename = lbl_805D2B10;
                        prs_decompress_buffer(buf, (saddr)resource_decompress_buffer);
                        TAdSinglePlyChrSelectGC::safe_free(buf);
                        bind_bml_model((Lobby_8001FBEC *)(this), size, i, (saddr)resource_decompress_buffer);
                    } else {
                        TLobby::debug_print("TBinModel:%s Malloc failed.", descriptor->archive_filename);
                    }
                    break;
                default:
                    st.read_data((saddr)resource_decompress_buffer, (s32)size);
                    st.align_read_offset(blk);
                    disc_read_filename = lbl_805D2B10;
                    bind_bml_model((Lobby_8001FBEC *)(this), size, i, (saddr)resource_decompress_buffer);
                    break;
                }
                if (this->flags & 0x800) {
                    BmlModelEntry *e = &models[i];
                    if (e->texlist != NULL) {
                        s32 tsize = rec->texSize;
                        if (tsize != 0) {
                            saddr tbuf = (saddr)TQuestVmDownLoadServer::alloc(tsize + 0x800);
                            st.read_data((saddr)((void *)tbuf), (s32)tsize);
                            st.align_read_offset(blk);
                            prs_decompress_buffer(tbuf, (saddr)resource_decompress_buffer);
                            TAdSinglePlyChrSelectGC::safe_free(tbuf);
                            if (load_gvm_texture_archive(resource_decompress_buffer, models[i].texlist) > 0) {
                                models[i].m_0 |= 1;
                            } else {
                                models[i].m_0 |= 2;
                                TLobby::debug_print("TBinModel: Illegal Texture.");
                            }
                        } else {
                            e->m_0 |= 2;
                            if (!(this->flags & 4)) {
                                TLobby::debug_print("TBinModel: Texture not exist.");
                            }
                        }
                    }
                }
            }
            for (j = 0; j < motion_count; j++, rec++) {
                s32 sz = rec->size;
                if (sz > 0x40000) {
                    TLobby::debug_print("TBinModel: tmpbuf overflow(%x)", sz - 0x40000);
                }
                switch (bml_load_state) {
                case 1: {
                    saddr mb = (saddr)TQuestVmDownLoadServer::alloc(sz + 0x800);
                    st.read_data((saddr)((void *)mb), (s32)sz);
                    st.align_read_offset(blk);
                    prs_decompress_buffer(mb, (saddr)resource_decompress_buffer);
                    TAdSinglePlyChrSelectGC::safe_free(mb);
                    bind_bml_motion((struct Lobby_8001FB6C *)this, j, resource_decompress_buffer);
                    break;
                }
                default:
                    st.read_data((saddr)resource_decompress_buffer, (s32)sz);
                    st.align_read_offset(blk);
                    bind_bml_motion((struct Lobby_8001FB6C *)this, j, resource_decompress_buffer);
                    break;
                }
            }
        }
        if (!(this->flags & 0x800)) {
            rec = hdr->recs;
            for (s32 i = 0; i < model_count; i++, rec++) {
                if (models[i].texlist != NULL) {
                    strncpy(name, rec->name, 0x20);
                    load_texture_sub(name, i);
                }
            }
        }
        set_flag_and_notify();
    } else if (flags & 2) {
        loaded_textures = 0;
        loaded_motions = 0;
        loaded_models = 0;
        load_state = 0;
        unknown_14 = 0;
        TLobby::add_named_entry((saddr)this, (saddr)descriptor->archive_filename);
    }
}

// TBinModel helpers (inferred names): the original inlines one loop per list here; the inline copies of the
// list parameter are what give the constructor its register assignment.
inline void TBinModel::load_models(char **list) {
    s32 i;
    for (i = 0; *list != 0; list++, i++) {
        ((BmlResource *)this)->load_bin_model(*list, i);
    }
}

inline void TBinModel::load_motions(char **list) {
    s32 i;
    char **p;
    for (p = list, i = 0; *p != 0; p++, i++) {
        ((BmlResource *)this)->load_bin_motion(*p, i);
    }
}

inline void TBinModel::request_motions(char **list) {
    BmlMotionLoadRequest req;
    void *handle;
    s32 i;
    for (i = 0; *list != 0; list++, i++) {
        req.motion = &((BmlResource *)this)->motions[i].motion;
        req.resource = (BmlResource *)this;
        create_named_entry__6TLobbyFiiUiiPv((saddr)*list, (saddr)lobby_download_buffer, (uaddr)load_bin_motion_callback, &req, &handle);
        TLobby__sub_8001EDD8((BmlResource *)this, handle);
    }
}

// TBinModel constructor (inferred: strings "TBinModel_NORMAL" / "TBinModel_REQ", operator new(0x440) at each caller).
extern "C" {
TBinModel *init_bin_model_request(TBinModel *self, s32 kind, char **models, char **motions, saddr on_loaded, saddr on_loaded_arg, s32 load_buffer) {
    BmlModelLoadRequest req;
    void *handle;
    char **p;
    s32 i;
    ((BmlResource *)self)->reset();
    self->flags = kind;
    for (i = 0; i < 0x100; i++) {
        self->handles[i] = 0;
    }
    self->on_loaded = on_loaded;
    self->on_loaded_arg = on_loaded_arg;
    self->load_buffer = load_buffer;
    for (p = models; *p != 0; p++) {
        self->nEnts16++;
    }
    if (self->nEnts16 > 0) {
        self->ents16 = (BinModelSlot *)mem_alloc(self->nEnts16 * 16);
        for (s32 i = 0; i < self->nEnts16; i++) {
            self->ents16[i].flags = 0;
            self->ents16[i].a = NULL;
            self->ents16[i].b = NULL;
        }
    }
    for (p = motions; *p != 0; p++) {
        self->nEnts8++;
    }
    if (self->nEnts8 > 0) {
        self->ents8 = (BinMotionSlot *)mem_alloc(self->nEnts8 * 8);
        for (s32 i = 0; i < self->nEnts8; i++) {
            self->ents8[i].data = NULL;
        }
    }
    if (self->flags & 1) {
        TLobby::tmp_buf_use_req("TBinModel_NORMAL");
        self->load_models(models);
        self->load_motions(motions);
        TLobby::tmp_buf_release("TBinModel_NORMAL");
        ((BmlResource *)self)->set_flag_and_notify();
    } else if (self->flags & 2) {
        TLobby::tmp_buf_use_req("TBinModel_REQ");
        if (self->nEnts16 * 2 + self->nEnts8 >= 0x100) {
            TLobby::debug_print("TBinModel:Too Many Files.");
        }
        for (p = models, i = 0; *p != 0; p++, i++) {
            req.name = *p;
            req.model = (NJS_OBJECT **)&((BmlResource *)self)->models[i].model;
            req.texture = (GinjaTextureList **)&((BmlResource *)self)->models[i].texlist;
            req.resource = (BmlResource *)self;
            req.entry = &((BmlResource *)self)->models[i];
            req.size = TGStream::get_resource_file_size(*p);
            create_named_entry__6TLobbyFiiUiiPv((saddr)*p, (saddr)lobby_download_buffer, (uaddr)load_bin_model_callback, &req, &handle);
            TLobby__sub_8001EDD8((BmlResource *)self, handle);
        }
        self->request_motions(motions);
    }
    return self;
}
}
