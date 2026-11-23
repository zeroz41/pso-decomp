#ifndef PSO_UI_CHARCREATE_CHARACTERCREATIONTEXTURECACHE_H
#define PSO_UI_CHARCREATE_CHARACTERCREATIONTEXTURECACHE_H
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/charcreate/CharacterShape.h"
#include <stddef.h>

struct TChCrLoadAfsTextureReq;

struct CreationTextureLoadSlot {
    s32 complete;
    s32 present;
    char names[8][32];
    NJS_TEXNAME entries[8];
    NJS_TEXLIST list;
    TChCrLoadAfsTextureReq *request;
};

struct CreationTextureCacheEntry {
    s32 in_use;
    s16 costume, skin, face, head, hair;
    s8 section;
    u8 reserved0f;
    CreationTextureLoadSlot hair_textures;
    CreationTextureLoadSlot head_textures;
    CreationTextureLoadSlot body_textures;
};
enum { CREATION_TEXTURE_CACHE_CAPACITY = 128 };
LAYOUT_ASSERT(CreationTextureLoadSlot_size, sizeof(CreationTextureLoadSlot) == 0x174);
LAYOUT_ASSERT(CreationTextureLoadSlot_entries, offsetof(CreationTextureLoadSlot, entries) == 0x108);
LAYOUT_ASSERT(CreationTextureLoadSlot_list, offsetof(CreationTextureLoadSlot, list) == 0x168);
LAYOUT_ASSERT(CreationTextureLoadSlot_request, offsetof(CreationTextureLoadSlot, request) == 0x170);
LAYOUT_ASSERT(CreationTextureCacheEntry_size, sizeof(CreationTextureCacheEntry) == 0x46C);
LAYOUT_ASSERT(CreationTextureCacheEntry_hair, offsetof(CreationTextureCacheEntry, hair_textures) == 0x10);
LAYOUT_ASSERT(CreationTextureCacheEntry_head, offsetof(CreationTextureCacheEntry, head_textures) == 0x184);
LAYOUT_ASSERT(CreationTextureCacheEntry_body, offsetof(CreationTextureCacheEntry, body_textures) == 0x2F8);
extern "C" {
extern CreationHeadModelStates creation_head_shape_destination;
extern CreationHeadModelStates creation_head_shape_samples[7];
extern CreationBodyModelStates creation_body_shape_destination;
extern CreationBodyModelStates creation_body_shape_samples[7];
extern CreationShapeBlend creation_shape_blend;
extern CreationTextureCacheEntry creation_texture_cache[CREATION_TEXTURE_CACHE_CAPACITY];
}
#endif
