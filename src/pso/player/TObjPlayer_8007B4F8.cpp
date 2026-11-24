#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"


s32 com_card_keyboard_mode;

void TObjPlayer::set_com_card_window(s32 client) {
    saddr temp_r31;
    u32 character_save_record;

    com_card_keyboard_mode = 0;
    character_save_record = ((u32)get_character_save_record((u32)client));
    if (character_save_record != 0U) {
        temp_r31 = character_save_record + 0x1510;
        if (temp_r31 != 0) {
            ((TLobby *)temp_r31)->fill_guild_card_from_char(client);
            com_card_keyboard_mode = temp_r31;
        }
    }
}
