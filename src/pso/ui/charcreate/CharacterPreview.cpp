#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/ui/charcreate/CharacterPreview.h"
#include "pso/player/PrsTextureLoad.h"
#include "pso/player/TPlyCharData.h"


CharacterPreview::~CharacterPreview() {
    if (request != NULL && is_unloaded() == 0) {
        delete request;
        request = NULL;
    }
    if (head_textures.present != 0) {
        if (!(completion_flags & 1)) {
            free_texture_if_valid(&head_textures.list);
        }
        head_textures.present = 0;
    }
    if (other_textures.present != 0) {
        if (!(completion_flags & 2)) {
            free_texture_if_valid(&other_textures.list);
        }
        other_textures.present = 0;
    }
    if (body_textures.present != 0) {
        if (!(completion_flags & 4)) {
            free_texture_if_valid(&body_textures.list);
        }
        body_textures.present = 0;
    }
}

CharacterPreview::CharacterPreview(TObject *parent, void *visual, s32 load_slot) {
    CharacterPreviewLoadArgs args;
    copy_player_visual_record((PlayerVisualRecord *)&appearance, (PlayerVisualRecord *)visual);
    completion_flags = 0xFF;
    bind_appearance_texture_lists(&head_textures, &other_textures, &body_textures, &appearance);
    args.appearance = &appearance;
    args.completion_flags = &completion_flags;
    args.load_slot = load_slot;
    args.body_model = &body_model;
    args.part_models = part_models;
    args.body_textures = &body_textures.list;
    args.other_textures = &other_textures.list;
    args.head_textures = &head_textures.list;
    request = create_ch_cr_load_req(parent, &args);
}

int CharacterPreview::is_unloaded() { return completion_flags == 0; }
