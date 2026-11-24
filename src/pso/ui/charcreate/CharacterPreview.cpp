#include "types.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/ui/charcreate/CharacterPreview.h"

extern "C" {
void copy_player_visual_record(void *, const void *);
}

CharacterPreview::CharacterPreview(TObject *parent, void *visual, s32 load_slot) {
    CharacterPreviewLoadArgs args;
    copy_player_visual_record(&appearance, visual);
    completion_flags = 0xFF;
    TCharaMaking__bind_appearance_texture_lists(&head_textures, &other_textures, &body_textures, &appearance);
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
