#pragma readonly_strings on

#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "types.h"
#include "pso/network/TGameProtocol.h"
#include "pso/unk/text_801F3774.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/system/byteswap.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/ui/TLevelSelect.h"


void TLobby__sub_801F3774(void) {  }

void TLobby::send_6x75_quest_flag(u16 flag, s16 action, s32 difficulty) {
    G_UpdateQuestFlag_V3_BB_6x75 packet;
    build_6x75_update_quest_flag_dc(&packet);
    packet.__base_G_UpdateQuestFlag_DC_PC_6x75.flag = flag;
    packet.__base_G_UpdateQuestFlag_DC_PC_6x75.action = action;
    packet.difficulty16 = difficulty;
    packet.unused = 0;
    send_and_handle_6x75(&packet);
}

void TLobby::send_6x75_quest_flag_cur_difficulty(u16 flag, s16 action) {
    G_UpdateQuestFlag_V3_BB_6x75 packet;
    build_6x75_update_quest_flag_dc(&packet);
    packet.__base_G_UpdateQuestFlag_DC_PC_6x75.flag = flag;
    packet.__base_G_UpdateQuestFlag_DC_PC_6x75.action = action;
    packet.difficulty16 = (s16) game_difficulty_selection;
    packet.unused = 0;
    send_and_handle_6x75(&packet);
}

void handle_6x75_update_quest_flag_dc(G_UpdateQuestFlag_V3_BB_6x75 *packet) {
    u16 action;
    packet->bswap();
    action = packet->__base_G_UpdateQuestFlag_DC_PC_6x75.action;
    if (action == 0) {
        set_story_flag_in_bank(packet->difficulty16, packet->__base_G_UpdateQuestFlag_DC_PC_6x75.flag);
        return;
    }
    if (action == 1) {
        clear_story_flag_in_bank(packet->difficulty16, packet->__base_G_UpdateQuestFlag_DC_PC_6x75.flag);
    }
}

void prepare_offline_quest_filenames(const char* identity) {
 switch(current_language) {
 case LANGUAGE_JAPANESE:TLobby::replace_file_extension(offline_quest_filename_buffer_a, (char *)identity, (char *)"_j.bin");break;
 case LANGUAGE_ENGLISH:TLobby::replace_file_extension(offline_quest_filename_buffer_a, (char *)identity, (char *)"_e.bin");break;
 case LANGUAGE_GERMAN:TLobby::replace_file_extension(offline_quest_filename_buffer_a, (char *)identity, (char *)"_g.bin");break;
 case LANGUAGE_FRENCH:TLobby::replace_file_extension(offline_quest_filename_buffer_a, (char *)identity, (char *)"_f.bin");break;
 case LANGUAGE_SPANISH:TLobby::replace_file_extension(offline_quest_filename_buffer_a, (char *)identity, (char *)"_s.bin");break;
 default:TLobby::replace_file_extension(offline_quest_filename_buffer_a, (char *)identity, (char *)"_e.bin");break;
 }
 TLobby::replace_file_extension(offline_quest_filename_buffer_b, (char *)identity, (char *)"_j.dat");
}

void send_and_handle_6x75(G_UpdateQuestFlag_V3_BB_6x75 *packet) {
    packet->bswap();
    send_subcommand(packet);
}

void G_UpdateQuestFlag_V3_BB_6x75::bswap() {
    ((G_ClientIDHeader *)&__base_G_UpdateQuestFlag_DC_PC_6x75.header)->bswap();
    bswap_16(&__base_G_UpdateQuestFlag_DC_PC_6x75.flag);
    bswap_16(&__base_G_UpdateQuestFlag_DC_PC_6x75.action);
    bswap_16((u16 *)&difficulty16);
    bswap_16(&unused);
}

void build_6x75_update_quest_flag_dc(G_UpdateQuestFlag_V3_BB_6x75 *packet) {
    packet->__base_G_UpdateQuestFlag_DC_PC_6x75.header.subcommand = 0x75;
    packet->__base_G_UpdateQuestFlag_DC_PC_6x75.header.size = 3;
}


char offline_quest_filename_buffer_a[0x20];
char offline_quest_filename_buffer_b[0x20];
