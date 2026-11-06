#include "types.h"
#include "pso/unk/TLobby_801F487C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_801F45FC.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"

extern "C" {
__declspec(section ".rodata") s32 lobby_story_flag_clear_list[6] = { 151, 152, 153, 154, -1, 0 };
}


extern "C" {
extern s32 lobby_story_flag_clear_list[6];
void *memcpy(void *, void *, u32);
extern u8 quest_story_flags_by_difficulty[0x200];
int is_not_split_screen__13TRaderMapCoreFv(void*);

void reset_camera_if_fullscreen__6TLobbyFPv(void* p) { if (is_not_split_screen__13TRaderMapCoreFv(p) == 1) { TCameraCtrl::get_nth_view_player_id((s32)((void*)0)); ((int (*)(void))TLobby__sub_801F494C)(); } }

void TLobby::clear_story_flag_list() {
    s32 i;
    for (i = 0; lobby_story_flag_clear_list[i] != -1; i++) {
        clear_story_flag(lobby_story_flag_clear_list[i]);
    }
}

void TLobby::clear_story_flags_and_reset_camera() {
    s32 i;
    for (i = 0; lobby_story_flag_clear_list[i] != -1; i++) {
        clear_story_flag(lobby_story_flag_clear_list[i]);
    }
    ((void (*)(void))reset_camera_if_fullscreen__6TLobbyFPv)();
}

void TLobby__sub_801F494C(u16 arg0) {
    u32 character_save_record;
    character_save_record = get_character_save_record(arg0);
    if (character_save_record != 0U) {
        memcpy(quest_story_flags_by_difficulty, (void *)(character_save_record + 0x44), 0x200);
    }
}

}
