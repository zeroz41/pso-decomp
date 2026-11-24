#include "pso/npc/TNpcPlayer_8028B810.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"

extern "C" {

void copy_player_visual_record(void *, const void *);

CharacterPreviewLoadData *init_appearance_load_request__10TNpcPlayerFPvPvii(
    CharacterPreviewLoadData *data, TObject *parent, CharacterAppearanceFields *appearance, s32 slot) {
    CharacterPreviewLoadArgs args;
    copy_player_visual_record(&data->appearance, appearance);
    data->completion_flags = 0xFF;
    TCharaMaking__bind_appearance_texture_lists(
        &data->head_textures, &data->other_textures, &data->body_textures, &data->appearance);
    args.appearance = &data->appearance;
    args.completion_flags = &data->completion_flags;
    args.load_slot = slot;
    args.body_model = &data->body_model;
    args.part_models = data->part_models;
    args.body_textures = &data->body_textures.list;
    args.other_textures = &data->other_textures.list;
    args.head_textures = &data->head_textures.list;
    data->request = create_ch_cr_load_req(parent, &args);
    return data;
}
}
