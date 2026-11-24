#ifndef PSO_UI_CHARCREATE_CHARACTERPREVIEW_H
#define PSO_UI_CHARCREATE_CHARACTERPREVIEW_H

#include "types.h"
#include <stddef.h>
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/CharacterCreationTextureCache.h"

class TObject;
class TChCrLoadReq;

// The models and textures of one character appearance, loaded through a
// TChCrLoadReq for the character select screens.
class CharacterPreview {
public:
    CharacterPreview(TObject *parent, void *visual, s32 load_slot);

    int is_unloaded();
    s32 get_hair_model();
    NJS_TEXLIST *get_chara_making_data();
    s32 get_head_model();
    s32 get_attachment_model();
    NJS_TEXLIST *get_status_data();
    saddr get_body_model();
    NJS_TEXLIST *get_status_sub();

    TChCrLoadReq *request;
    CharacterAppearanceFields appearance;
    CharacterTextureLoadSet head_textures;
    CharacterTextureLoadSet other_textures;
    CharacterTextureLoadSet body_textures;
    s32 part_models[3];
    s32 body_model;
    u32 completion_flags;
};

LAYOUT_ASSERT(CharacterPreview_head_textures, offsetof(CharacterPreview, head_textures) == 0x54);
LAYOUT_ASSERT(CharacterPreview_body_model, offsetof(CharacterPreview, body_model) == 0x4A4);
LAYOUT_ASSERT(CharacterPreview_size, sizeof(CharacterPreview) == 0x4AC);

extern "C" CharacterPreview *ply_status_chcr_load_afs;

#endif
