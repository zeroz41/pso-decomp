#ifndef PSO_QUEST_QUESTFLAGCOMMAND_H
#define PSO_QUEST_QUESTFLAGCOMMAND_H

#include "types.h"

struct G_UpdateQuestFlag_V3_BB_6x75;

// The offline quest's file names (prepare_offline_quest_filenames).
extern char offline_quest_filename_buffer_a[0x20];
extern char offline_quest_filename_buffer_b[0x20];

void TLobby__sub_801F3774(void);
void build_6x75_update_quest_flag_dc(G_UpdateQuestFlag_V3_BB_6x75 *packet);
void handle_6x75_update_quest_flag_dc(G_UpdateQuestFlag_V3_BB_6x75 *packet);
void prepare_offline_quest_filenames(const char *identity);
void send_and_handle_6x75(G_UpdateQuestFlag_V3_BB_6x75 *packet);

#endif
