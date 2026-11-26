#ifndef PSO_UNK_GUILDCARDRECORD_H
#define PSO_UNK_GUILDCARDRECORD_H

#include "types.h"
#include "pso/network/TPlyMeetUserExtension.h"

// One com-card list record (0xBC bytes). TLobby keeps the selected card and an
// 8-entry list; serial comes from a running counter (init_player_entry).
struct GuildCardRecord {
    s32 id;
    s32 serial;
    char name[0x11];
    char s19[0x11];
    char s2A[0x11];
    char s3B[0x11];
    u8 f4C[0xC];
    TPlyMeetUserExtension ext;

    GuildCardRecord();
    s32 get_serial() const;
    s32 get_id();
    char *get_sub_obj();
    char *get_name();
    char *get_card_data_ptr();
    char *get_sub_disp_ptr();
};

// The com-card record picked in the com-card or choice-search windows (load_selected_guild_card_record).
extern GuildCardRecord selected_guild_card_record;

extern "C" char *TWindowSubComCard__sub_8027523C(GuildCardRecord *entry);
// Copies the record's ship name to lobby_ship_name and asks the server to move to the card owner.
extern "C" void jump_to_guild_card_owner(GuildCardRecord *entry);

class TUserAns;

void handle_user_search_answer(TUserAns &response);
void add_found_user_com_card(TUserAns &response);
void find_and_load_com_card(u32 serial);
void init_player_entry(GuildCardRecord *entry, u8 *response);
s32 remove_com_card_by_id(u32 id);
void remove_com_card_entry(s32 index);
char *build_text_from_comma_list(char *list);
char *parse_csv_token(char *src, char *dst);
char *skip_to_comma_field(char *s, s32 a, s32 b);

#endif
