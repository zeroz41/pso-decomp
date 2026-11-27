#ifndef PSO_SYSTEM_BML_RESOURCE_H
#define PSO_SYSTEM_BML_RESOURCE_H

#include "pso/system/BmlAccessors.h"
#include <stddef.h>
#include "types.h"

struct BmlModelEntry {
    u32 flags; // 1 once its texture list is loaded, 2 when that load failed
    s32 m_4;
    NJS_OBJECT *model;
    // The model's texture list, set as the global texture list before it is drawn.
    NJS_TEXLIST *texlist;
};

LAYOUT_ASSERT(BmlModelEntry_size, sizeof(BmlModelEntry) == 0x10);
LAYOUT_ASSERT(BmlModelEntry_model_offset, offsetof(BmlModelEntry, model) == 0x8);
LAYOUT_ASSERT(BmlModelEntry_texlist_offset, offsetof(BmlModelEntry, texlist) == 0xC);

struct NJS_MOTION;
struct BmlMotionEntry {
    BmlMotionEntry &operator=(BmlMotionEntry &other);
    u32 unknown;
    NJS_MOTION *motion;
};

LAYOUT_ASSERT(BmlMotionEntry_size, sizeof(BmlMotionEntry) == 8);
LAYOUT_ASSERT(BmlMotionEntry_motion_offset, offsetof(BmlMotionEntry, motion) == 4);

struct BmlResourceDescriptor;

typedef void (*BmlLoadCallback)(void *);
struct BmlResource {
    BmlResource(s32 kind, BmlResourceDescriptor *descriptor, BmlLoadCallback callback, void *context, void *arena);
    ~BmlResource();
    void free_if_not_in_arena(void *ptr);
    // Takes the next chunk out of `file` at `*offset`: decoded into the arena when the
    // archive has one (rounded up to 32 bytes), else loaded on its own.
    void *allocate_bml_chunk(u8 *file, u32 *offset, u32 *tag);
    // Records a file handle the archive holds while it loads.
    void add_resource_handle(void *item);
    void reset();
    void LoadTextureSub(const char *filename, s32 index);
    void set_flag_and_notify();
    s32 LoadBinMotion(const char *name, s32 index);
    s32 LoadBinModel(const char *name, s32 index);
    s32 get_arena_offset();

    u32 flags;
    s32 loaded_models;
    s32 loaded_motions;
    s32 loaded_textures;
    s32 load_state;
    s32 unknown_14;
    void *handles[256];
    s32 handle_count;
    BmlLoadCallback callback;
    void *callback_context;
    void *arena;
    s32 arena_offset;
    BmlModelEntry *models;
    BmlMotionEntry *motions;
    s32 model_count;
    s32 motion_count;
    s32 expected_textures;
};

LAYOUT_ASSERT(BmlResource_size, sizeof(BmlResource) == 0x440);
LAYOUT_ASSERT(BmlResource_handles_offset, offsetof(BmlResource, handles) == 0x18);
LAYOUT_ASSERT(BmlResource_handle_count_offset, offsetof(BmlResource, handle_count) == 0x418);
LAYOUT_ASSERT(BmlResource_callback_offset, offsetof(BmlResource, callback) == 0x41C);
LAYOUT_ASSERT(BmlResource_arena_offset, offsetof(BmlResource, arena) == 0x424);
LAYOUT_ASSERT(BmlResource_models_offset, offsetof(BmlResource, models) == 0x42C);
LAYOUT_ASSERT(BmlResource_motions_offset, offsetof(BmlResource, motions) == 0x430);
LAYOUT_ASSERT(BmlResource_model_count_offset, offsetof(BmlResource, model_count) == 0x434);

BmlResource *init_bin_model_request(BmlResource *resource, s32 kind,
    const char **models, const char **motions,
    BmlLoadCallback on_loaded, void *context, void *arena);

void check_bin_model_loaded(BmlResource *resource);
void increment_ref_and_set_flag(void *context);
struct BmlModelLoadRequest;
struct BmlMotionLoadRequest;
struct NJS_MOTION;
void LoadBinModelCallBack(BmlModelLoadRequest *request);
void LoadBinMotionCallBack(BmlMotionLoadRequest *request);


s32 tmp_buf_is_free();
s32 tmp_buf_release(const char *name);
void tmp_buf_release_if_owner(const char *name);
u8 *tmp_buf_use_req(const char *name);

void free_chr_select_data();
void init_download_buffers();

struct BmlModelLoadRequest {
    const char *name;
    NJS_OBJECT **model;
    NJS_TEXLIST **texture;
    BmlResource *resource;
    BmlModelEntry *entry;
    u32 size;
};

struct BmlMotionLoadRequest {
    NJS_MOTION **motion;
    BmlResource *resource;
};

struct BmlTextureLoadRequest {
    BmlResource *resource;
    BmlModelEntry *entry;
};

struct BmlArchiveEntry {
    char name[0x20];
    s32 size;
    u8 pad24[4];
    s32 rawSize;
    s32 texSize;
    u8 pad30[0x10];
};

struct BmlArchiveHeader {
    u8 pad0[8];
    u8 compressed;
    s8 small;
    u8 padA[0x36];
    BmlArchiveEntry recs[1];
};

#endif
