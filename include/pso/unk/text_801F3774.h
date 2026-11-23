#ifndef PSO_UNK_TEXT_801F3774_H
#define PSO_UNK_TEXT_801F3774_H

#include "types.h"

struct TLobby;

// The offline quest's file names (prepare_offline_quest_filenames).
extern char offline_quest_filename_buffer_a[0x20];
extern char offline_quest_filename_buffer_b[0x20];

extern "C" {
void TLobby__sub_801F3774(void);
}
void build_6x75_update_quest_flag_dc(void *p);
void handle_6x75_update_quest_flag_dc(TLobby *lobby);
extern "C" {
void prepare_offline_quest_filenames(const char *identity);
}
void send_and_handle_6x75(TLobby *lobby);

// --- C functions defined in text_801F3774.cpp ---
extern "C" {
void TLobby__sub_801F3774(void);
void prepare_offline_quest_filenames(const char *identity);
}
// --- end of C functions

#endif
