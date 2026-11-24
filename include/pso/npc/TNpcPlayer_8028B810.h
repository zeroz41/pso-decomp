#ifndef PSO_NPC_TNPCPLAYER_8028B810_H
#define PSO_NPC_TNPCPLAYER_8028B810_H

#include "types.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/CharacterCreationTextureCache.h"

class TObject;
class TChCrLoadReq;

struct CharacterPreviewLoadData {
    TChCrLoadReq *request;
    CharacterAppearanceFields appearance;
    CharacterTextureLoadSet head_textures;
    CharacterTextureLoadSet other_textures;
    CharacterTextureLoadSet body_textures;
    s32 part_models[3];
    s32 body_model;
    u32 completion_flags;

    int is_unloaded();
    s32 get_hair_model();
    NJS_TEXLIST *get_chara_making_data();
    s32 get_head_model();
    s32 get_attachment_model();
    NJS_TEXLIST *get_status_data();
    saddr get_body_model();
    NJS_TEXLIST *get_status_sub();
};

LAYOUT_ASSERT(CharacterPreviewLoadData_head, offsetof(CharacterPreviewLoadData, head_textures) == 0x54);
LAYOUT_ASSERT(CharacterPreviewLoadData_other, offsetof(CharacterPreviewLoadData, other_textures) == 0x1C0);
LAYOUT_ASSERT(CharacterPreviewLoadData_body, offsetof(CharacterPreviewLoadData, body_textures) == 0x32C);
LAYOUT_ASSERT(CharacterPreviewLoadData_models, offsetof(CharacterPreviewLoadData, part_models) == 0x498);
LAYOUT_ASSERT(CharacterPreviewLoadData_flags, offsetof(CharacterPreviewLoadData, completion_flags) == 0x4A8);
LAYOUT_ASSERT(CharacterPreviewLoadData_size, sizeof(CharacterPreviewLoadData) == 0x4AC);

extern "C" {
extern CharacterPreviewLoadData *ply_status_chcr_load_afs;
CharacterPreviewLoadData *init_appearance_load_request__10TNpcPlayerFPvPvii(
    CharacterPreviewLoadData *data, TObject *parent, CharacterAppearanceFields *appearance, s32 slot);
}

#endif
