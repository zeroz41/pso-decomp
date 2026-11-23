#ifndef PSO_SYSTEM_BML_RESOURCE_H
#define PSO_SYSTEM_BML_RESOURCE_H

#include "pso/system/BmlAccessors.h"
#include <stddef.h>

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

struct AnimationMotion;
struct BmlMotionEntry {
    u32 unknown;
    AnimationMotion *motion;
};

LAYOUT_ASSERT(BmlMotionEntry_size, sizeof(BmlMotionEntry) == 8);
LAYOUT_ASSERT(BmlMotionEntry_motion_offset, offsetof(BmlMotionEntry, motion) == 4);

struct BmlResourceDescriptor;

typedef void (*BmlLoadCallback)(void *);
struct BmlResource {
    BmlResource(s32 kind, BmlResourceDescriptor *descriptor, BmlLoadCallback callback, void *context, void *arena);
    ~BmlResource();
    void free_if_not_in_arena(void *ptr);
    void reset();
    void load_texture_sub(const char *filename, s32 index);
    void set_flag_and_notify();
    s32 load_bin_motion(const char *name, s32 index);
    s32 load_bin_model(const char *name, s32 index);

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

extern "C" BmlResource *init_bin_model_request(BmlResource *resource, s32 kind,
    const char **models, const char **motions,
    BmlLoadCallback on_loaded, void *context, void *arena);

#endif
