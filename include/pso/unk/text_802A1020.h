#ifndef PSO_UNK_TEXT_802A1020_H
#define PSO_UNK_TEXT_802A1020_H

#include "types.h"

// Set by verify_game_file_integrity when a disc file's size or CRC differs from file_integrity_table.
extern s32 game_files_modified_flag;

s32 verify_game_file_integrity(void);

// --- C functions defined in text_802A1020.cpp ---
s32 verify_game_file_integrity(void);
// --- end of C functions

// Also the TMovie end callback of the opening movie: takes the callback's argument.
void set_movie_finished_flag(s32);
void update_movie_phase(void);

extern "C" {
unsigned char get_opening_movie_purpose(void);
}
void set_opening_movie_purpose(int a0);

extern "C" {
void fn_802A1154(void);
}

#endif
