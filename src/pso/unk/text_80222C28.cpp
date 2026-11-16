#include "types.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_80222C28.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/Language.h"

extern s32 quest_and_shop_error_text;
s32 ** lbl_805D6258;
struct GuildTextPlayModeTable { s32 value; u8 remaining[0xC]; };
extern GuildTextPlayModeTable guild_text_play_mode_table;
struct AppraisalTextGroupTable { s32 value; u8 remaining[0x24]; };
extern AppraisalTextGroupTable appraisal_text_group_table;
extern s32 lbl_805D6238;

s32 get_quest_list_text(s32 arg0, s32 arg1) {
    if ((s32 *) (*(s32 * *)&lbl_805D6258) != NULL) {
        return *(s32 *)((s8 *)(*(s32 *)((s8 *)(*(s32 *)((s8 *)(*(s32 * *)&lbl_805D6258) + 0) + (arg0 * 4)) + 0) + (arg1 * 4)) + 0);
    }
    return quest_and_shop_error_text;
}

s32 get_guild_text(s32 arg0) {
  s32 new_var;
  if (((s32 *) (*(s32 * *)&lbl_805D6258)) != 0)
  {
    new_var = *((s32 *) (((s8 *) (((u8 *)&guild_text_play_mode_table.value) + (get_game_play_mode() * 4))) + 0));
    return *((s32 *) (((s8 *) ((*((s32 *) (((s8 *) ((*((s32 *) (((s8 *) (*(s32 * *)&lbl_805D6258)) + 0))) + (new_var * 4))) + 0))) + (arg0 * 4))) + 0));
  }
  return quest_and_shop_error_text;
}

s32 get_appraisal_text(s32 arg0) {
  if (((s32 *) (*(s32 * *)&lbl_805D6258)) != 0)
  {
    return *((s32 *) (((s8 *) ((*((s32 *) (((s8 *) ((*((s32 *) (((s8 *) (*(s32 * *)&lbl_805D6258)) + 0))) + ((*((s32 *) (((s8 *) (((u8 *)&appraisal_text_group_table.value) + (lbl_805D6238 * 4))) + 0))) * 4))) + 0))) + (2 * (2 * arg0)))) + 0));
  }
  return quest_and_shop_error_text;
}

s32 get_shop_text(s32 arg0) {
    if ((s32 **) lbl_805D6258 != NULL) {
        return *(s32 *)((s8 *)(**lbl_805D6258) + (arg0 * 4));
    }
    return quest_and_shop_error_text;
}

#pragma readonly_strings on

extern "C" {
const char *text_shop_rel_name_table[6] = { "TextShopJapanese.rel", "TextShopEnglish.rel", "TextShopGerman.rel", "TextShopFrench.rel", "TextShopSpanish.rel", NULL };
#pragma fp_contract on
#pragma fp_contract on
extern const char *text_shop_rel_name_table[6];
s32 is_split_screen();
void TLobby::free_singleton() {
    if ((u32) lbl_805D6258 != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)lbl_805D6258));
        lbl_805D6258 = 0U;
    }
}
void TLobby::create_named_lobby_object() {
    if (((s32) lbl_805D6238 < 0) || ((s32) lbl_805D6238 > 9)) {
        lbl_805D6238 = 0;
    }
    (*(s32 *)&lbl_805D6258) = create_named_object(((s32 *)text_shop_rel_name_table)[current_language]);
}
#pragma push
#pragma scheduling off
s32 TShopGenerator__sub_80222DAC(s32 arg0) {
    return ((is_split_screen() - 1) == 0) ? arg0 : 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma pop

}
