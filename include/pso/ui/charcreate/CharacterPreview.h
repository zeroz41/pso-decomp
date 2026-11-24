#ifndef PSO_UI_CHARCREATE_CHARACTERPREVIEW_H
#define PSO_UI_CHARCREATE_CHARACTERPREVIEW_H

#include "types.h"
#include <stddef.h>
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

class TObject;
class TChCrLoadReq;

// A texture list the preview's load request fills.
struct CharacterPreviewTextures {
    s32 present;
    char names[8][32];
    NJS_TEXNAME entries[8];
    NJS_TEXLIST list;
};

// The models and textures of one character appearance, loaded through a
// TChCrLoadReq for the character select screens.
class CharacterPreview {
public:
    CharacterPreview(TObject *parent, void *visual, s32 load_slot);
    ~CharacterPreview();
    // Nonzero once every part has loaded (completion_flags all clear).
    int is_loaded();

    s32 get_hair_model();
    NJS_TEXLIST *get_head_texlist();
    s32 get_cap_model();
    s32 get_head_model();
    NJS_TEXLIST *get_other_texlist();
    s32 get_body_model();
    NJS_TEXLIST *get_body_texlist();

    TChCrLoadReq *request;
    CharacterAppearanceFields appearance;
    CharacterPreviewTextures head_textures;
    CharacterPreviewTextures other_textures;
    CharacterPreviewTextures body_textures;
    s32 part_models[3];  // hair, cap, head (TChCrLoadReq fills them)
    s32 body_model;
    u32 completion_flags;
};

LAYOUT_ASSERT(CharacterPreviewTextures_size, sizeof(CharacterPreviewTextures) == 0x16C);
LAYOUT_ASSERT(CharacterPreview_head_textures, offsetof(CharacterPreview, head_textures) == 0x54);
LAYOUT_ASSERT(CharacterPreview_body_model, offsetof(CharacterPreview, body_model) == 0x4A4);
LAYOUT_ASSERT(CharacterPreview_size, sizeof(CharacterPreview) == 0x4AC);

#endif
