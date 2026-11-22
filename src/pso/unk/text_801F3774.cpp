#pragma readonly_strings on

#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/unk/text_801F3774.h"
#include "pso/unk/text_801F4560.h"
#include "pso/unk/text_801F469C.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"

struct Stack_801F37CC {
    s32 sp8;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
};

struct Stack_801F3778 {
    s32 sp8;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
};


extern s32 game_difficulty_selection;

void TLobby__sub_801F3774(void) {  }

void TLobby::send_6x75_quest_flag(s16 arg0, s16 arg1, s16 arg2) {
    Stack_801F3778 stack;
    build_6x75_update_quest_flag_dc(&stack.sp8);
    stack.spC = arg0;
    stack.spE = arg1;
    stack.sp10 = arg2;
    stack.sp12 = 0;
    send_and_handle_6x75((TLobby *)&stack.sp8);
}

void TLobby::send_6x75_quest_flag_cur_difficulty(s16 arg0, s16 arg1) {
    Stack_801F37CC stack;
    build_6x75_update_quest_flag_dc(&stack.sp8);
    stack.spC = arg0;
    stack.spE = arg1;
    stack.sp10 = (s16) game_difficulty_selection;
    stack.sp12 = 0;
    send_and_handle_6x75((TLobby *)&stack.sp8);
}

void handle_6x75_update_quest_flag_dc(TLobby *lobby) {
    u16 id;
    lobby->byteswap_6x75_packet();
    id = lobby->m_id;
    if (id == 0) {
        set_story_flag_in_bank(((s32) *(s16 *)((s8 *)lobby + 8)), ((s32) lobby->m_flags));
        return;
    }
    if (id == 1) {
        clear_story_flag_in_bank(((s32) *(s16 *)((s8 *)lobby + 8)), ((s32) lobby->m_flags));
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

void send_and_handle_6x75(TLobby *lobby) {
    lobby->byteswap_6x75_packet();
    send_subcommand((u8 *)lobby);
}

void TLobby::byteswap_6x75_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)((void *)((char *)this + 4)));
    bswap_16((u16 *)((void *)((char *)this + 6)));
    bswap_16((u16 *)((void *)((char *)this + 8)));
    bswap_16((u16 *)((void *)((char *)this + 10)));
}

void build_6x75_update_quest_flag_dc(void* p) { *(u8*)((char*)p + 0x0) = 117; *(u8*)((char*)p + 0x1) = 3; }


char offline_quest_filename_buffer_a[0x20];
char offline_quest_filename_buffer_b[0x20];
