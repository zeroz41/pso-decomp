#ifndef PSO_UI_CHARCREATE_CHARACTERCREATIONTEXTURECACHE_H
#define PSO_UI_CHARCREATE_CHARACTERCREATIONTEXTURECACHE_H
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/charcreate/CharacterShape.h"
#include <stddef.h>

struct CharacterAppearanceFields;
struct CharacterClassAppearance;
struct CharacterTextureList;
struct TChCrLoadAfsTextureReq;

struct CharacterTextureLoadSet {
    s32 present;
    char names[8][32];
    NJS_TEXNAME entries[8];
    NJS_TEXLIST list;

    void build_appearance_texture_names(CharacterAppearanceFields *appearance,
        CharacterClassAppearance *definition, CharacterTextureList *source);
};

struct CreationTextureLoadSlot {
    s32 complete;
    CharacterTextureLoadSet textures;
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
LAYOUT_ASSERT(CharacterTextureLoadSet_size, sizeof(CharacterTextureLoadSet) == 0x16C);
LAYOUT_ASSERT(CharacterTextureLoadSet_entries, offsetof(CharacterTextureLoadSet, entries) == 0x104);
LAYOUT_ASSERT(CharacterTextureLoadSet_list, offsetof(CharacterTextureLoadSet, list) == 0x164);
LAYOUT_ASSERT(CreationTextureLoadSlot_textures, offsetof(CreationTextureLoadSlot, textures) == 0x4);
LAYOUT_ASSERT(CreationTextureLoadSlot_request, offsetof(CreationTextureLoadSlot, request) == 0x170);
LAYOUT_ASSERT(CreationTextureCacheEntry_size, sizeof(CreationTextureCacheEntry) == 0x46C);
LAYOUT_ASSERT(CreationTextureCacheEntry_hair, offsetof(CreationTextureCacheEntry, hair_textures) == 0x10);
LAYOUT_ASSERT(CreationTextureCacheEntry_head, offsetof(CreationTextureCacheEntry, head_textures) == 0x184);
LAYOUT_ASSERT(CreationTextureCacheEntry_body, offsetof(CreationTextureCacheEntry, body_textures) == 0x2F8);
extern "C" {
void TCharaMaking__bind_appearance_texture_lists(CharacterTextureLoadSet *hair,
    CharacterTextureLoadSet *head, CharacterTextureLoadSet *body, CharacterAppearanceFields *appearance);
extern CreationHeadModelStates creation_head_shape_destination;
extern CreationHeadModelStates creation_head_shape_samples[7];
extern CreationBodyModelStates creation_body_shape_destination;
extern CreationBodyModelStates creation_body_shape_samples[7];
extern CreationShapeBlend creation_shape_blend;
extern CreationTextureCacheEntry creation_texture_cache[CREATION_TEXTURE_CACHE_CAPACITY];
}
#endif
