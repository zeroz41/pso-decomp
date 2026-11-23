#include "types.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/npc/TNpcPlayer_8028B810.h"

extern "C" {
s32 copy_player_visual_record(void *, void *);
s32 TCharaMaking__bind_appearance_texture_lists(void *, void *, void *, void *);

u8 *init_appearance_load_request__10TNpcPlayerFPvPvii(u8 *arg0, u8 *parent, saddr arg2, s32 arg3) {
    CharacterPreviewLoadArgs args;
    copy_player_visual_record(arg0 + 4, (void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x4A8) = 0xFF;
    TCharaMaking__bind_appearance_texture_lists(arg0 + 0x54, arg0 + 0x1C0, arg0 + 0x32C, arg0 + 4);
    args.appearance = (CharacterAppearanceFields *)(arg0 + 4);
    args.completion_flags = (u32 *)(arg0 + 0x4A8);
    args.load_slot = arg3;
    args.body_model = (s32 *)(arg0 + 0x4A4);
    args.part_models = (s32 *)(arg0 + 0x498);
    args.body_textures = (NJS_TEXLIST *)(arg0 + 0x490);
    args.other_textures = (NJS_TEXLIST *)(arg0 + 0x324);
    args.head_textures = (NJS_TEXLIST *)(arg0 + 0x1B8);
    *(TChCrLoadReq **)arg0 = create_ch_cr_load_req((TObject *)parent, &args);
    return arg0;
}
}
