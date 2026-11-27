#ifndef PSO_NETWORK_GUILDCARDRECORD_H
#define PSO_NETWORK_GUILDCARDRECORD_H

#include "types.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/network/protocol/packet_classes.h"

// One com-card list record (0xBC bytes). TLobby keeps the selected card and an
// 8-entry list; serial comes from a running counter (init_player_entry).
struct GuildCardRecord {
    s32 id;
    s32 serial;
    char name[0x11];
    char ship_name[0x11];
    char block_name[0x11];
    char team_name[0x11];
    TRecvPort recv_port;
    TPlyMeetUserExtension ext;

    GuildCardRecord();
    s32 get_serial() const;
    s32 get_id();
    char *get_sub_obj();
    char *get_ship_name();
    char *get_team_name();
    char *get_sub_disp_ptr();
    GuildCardRecord *copy_com_card_entry(GuildCardRecord *src);
};

// GuildCardRecord's constructor by symbol, for the static initializer that builds the com-card records
// (C++ cannot take a constructor's address).
extern "C" {
void *__ct__15GuildCardRecordFv(void *object);
}

// The com-card record picked in the com-card or choice-search windows (load_selected_guild_card_record).
extern GuildCardRecord selected_guild_card_record;
struct ChoiceSearchResult;
// Fills selected_guild_card_record from a choice-search result.
void load_selected_guild_card_record(ChoiceSearchResult *src);

char *get_guild_card_block_name(GuildCardRecord *entry);
// Copies the record's ship name to lobby_ship_name and asks the server to move to the card owner.
void jump_to_guild_card_owner(GuildCardRecord *entry);

class TUserAns;

void handle_user_search_answer(TUserAns &response);
void add_found_user_com_card(TUserAns &response);
void find_and_load_com_card(u32 serial);
void init_player_entry(GuildCardRecord *entry, TUserAns *response);
s32 remove_com_card_by_id(u32 id);
void remove_com_card_entry(s32 index);
char *build_text_from_comma_list(char *list);
char *parse_csv_token(char *src, char *dst);
char *skip_to_comma_field(char *s, s32 a, s32 b);
void copy_guild_card_f4c(void *dst, void *src);

void set_short_mail_flag_bit2(void);

#endif
